#!/usr/bin/env python3
"""Propose independently evidenced symbol mappings for blocked audit recipes.

The input is one or more audit directories produced by ``tools/audit_matches.py``
(or an assessment report from ``tools/verify_linked_image.py --assess``).
Unresolved COFF symbols are joined against:

* strict audit records (a symbol already verified in a passing recipe),
* the shared symbol registry,
* the shipped function/data symbol maps,
* the PE import table,
* the stock CRT archive report,
* recovered vtable and vtable-slot inventories.

The output separates independently established facts from weak name matches,
and ranks groups of facts by how many blocked functions they would finish
together. Observed relocation targets are recorded for investigation only;
they are never treated as independent evidence.
"""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from functools import lru_cache
import json
from pathlib import Path
import re
import subprocess
from typing import Iterable

from coff_cache import CACHE_FLAGS
from match_decomp import (DATA_SYMBOLS, GAME, ROOT, SYMBOL_INDEX,
                          current_registry, file_sha256, function_lengths,
                          pe_imports, resolve_auto_symbol)

VERSION = "pc2.symbol_proposals.v1"
VTABLE_FILE = ROOT / "decompiled_fastfood2_named_v2" / "vtables_full.csv"
VTABLE_SLOT_FILE = ROOT / "decompiled_fastfood2_named_v2" / "vtable_slot_targets.csv"
LOCAL_PREFIXES = ("$", "__real@", "__xmm@")
LOCAL_CATEGORIES = {"local_label", "constant"}
STRONG_ORIGINS = {"symbol_registry", "exact_symbol", "decorated_alias", "pe_iat",
                  "address_label", "vc6_eh_intrinsic"}
CRT_CATEGORIES = {"crt", "vtable", "import"}


def is_pilot(symbol: str, fact_category: str) -> bool:
    return (fact_category in CRT_CATEGORIES
            or symbol.startswith(("??2", "??_", "??0", "??1")))


def normalize(text: str) -> str:
    return re.sub(r"[^a-z0-9]+", "_", text.lower()).strip("_")


_WORD_RE = re.compile(r"[A-Z]+(?=[A-Z][a-z]|$)|[A-Z]?[a-z]+|[0-9]+")


def words(text: str) -> set[str]:
    result = set()
    for part in re.split(r"[^A-Za-z0-9]+", text):
        result.update(word.lower() for word in _WORD_RE.findall(part))
    return result


def category(symbol: str) -> str:
    if symbol.startswith("$"):
        return "local_label"
    if symbol.startswith(("__real@", "__xmm@")):
        return "constant"
    if symbol.startswith(("__imp__", "_imp__")):
        return "import"
    if symbol.startswith(("??_7", "??_8")):
        return "vtable"
    if symbol.startswith(("?g_", "?_g_")):
        return "global"
    if symbol.startswith("?"):
        return "decorated"
    if symbol.startswith(("_DAT_", "DAT_", "_STR_", "STR_")):
        return "address_label"
    if symbol.startswith(("_", "@")):
        return "crt"
    if symbol.startswith(("g_", "_g_")):
        return "global"
    return "other"


def is_local(symbol: str) -> bool:
    return symbol.startswith(LOCAL_PREFIXES) or category(symbol) in LOCAL_CATEGORIES


@lru_cache(maxsize=None)
def demangled(symbol: str) -> str:
    if not symbol.startswith("?"):
        return symbol
    try:
        result = subprocess.run(["llvm-undname", symbol], text=True,
                                capture_output=True, timeout=10)
    except (OSError, subprocess.SubprocessError):
        return symbol
    lines = [line.strip() for line in result.stdout.splitlines() if line.strip()]
    return lines[-1] if lines else symbol


@lru_cache(maxsize=None)
def parsed_name(symbol: str):
    """Return (class, method, method_words, class_words, declaration)."""
    text = demangled(symbol)
    declaration = text
    data_global = re.match(r"\?(g_[^@]+)@@", symbol)
    if data_global:
        name = data_global.group(1)
        return None, name, words(name), set(), declaration
    if symbol.startswith("?") and text:
        operator = re.search(r"\boperator\s+(new|delete)\b", text)
        function = re.search(r"([~A-Za-z_]\w*(?:::[~A-Za-z_]\w*)*)\s*\(", text)
        if operator:
            method = f"operator {operator.group(1)}"
            return None, method, words(method), set(), declaration
        if function:
            qualified = function.group(1)
            if "::" in qualified:
                cls, method = qualified.rsplit("::", 1)
                cls = cls.split("::")[-1]
            else:
                cls, method = None, qualified
            method_words = words(method)
            class_words = words(cls) if cls else set()
            if cls and method == cls:
                method_words = words(cls) | {"construct"}
            elif method.startswith("~"):
                method_words = words(cls) | {"destruct"}
            return cls, method, method_words, class_words, declaration
    # C symbols and data globals.
    name = symbol.lstrip("_@").split("@", 1)[0]
    return None, name, words(name), set(), declaration


def load_json(path: Path):
    return json.loads(path.read_text())


def source_path(row):
    source = row.get("source")
    if isinstance(source, dict):
        return source.get("path")
    return source


def source_sha(row):
    source = row.get("source")
    if isinstance(source, dict):
        return source.get("sha256")
    return row.get("source_sha256")


def merge_key(row):
    return (row.get("address"), source_sha(row) or source_path(row),
            tuple(row.get("flags", [])),
            tuple(sorted(row.get("symbol_overrides", {}).items())))


def recipe_key(row):
    return (*merge_key(row), row.get("entry"), row.get("length"),
            json.dumps(row.get("compiler"), sort_keys=True))


def load_rows(paths: Iterable[Path], executable_sha256: str):
    rows = []
    inputs = []
    for path in paths:
        path = path.resolve()
        inputs.append(str(path))
        if path.is_dir():
            directory = path / "functions" if (path / "functions").is_dir() else path
            files = sorted(directory.glob("*.json"))
            if not files:
                raise ValueError(f"no audit records under {path}")
            for file in files:
                payload = load_json(file)
                payload.setdefault("_audit_path", str(file.parent.parent if file.parent.name == "functions" else file.parent))
                rows.append(payload)
        elif path.is_file() and path.suffix == ".json":
            payload = load_json(path)
            if "candidates" in payload:
                for candidate in payload["candidates"]:
                    source = candidate.get("source")
                    if isinstance(source, dict):
                        candidate.setdefault("source_sha256", source.get("sha256"))
                    candidate.setdefault("_audit_path", str(path))
                    candidate["_assessment"] = True
                    rows.append(candidate)
            else:
                payload.setdefault("_audit_path", str(path))
                rows.append(payload)
        else:
            raise ValueError(f"unsupported audit input: {path}")
    for row in rows:
        sha = row.get("executable_sha256")
        if sha is not None and sha != executable_sha256:
            raise ValueError(f"audit record {row.get('address')} targets a different executable")
    return rows, inputs


def merge_rows(rows, registry_sha256: str):
    fresh = {merge_key(row) for row in rows
             if row.get("symbol_registry_sha256") == registry_sha256}
    rows = [row for row in rows
            if row.get("symbol_registry_sha256") == registry_sha256
            or merge_key(row) not in fresh]
    by_recipe = {}
    for row in rows:
        by_recipe.setdefault(merge_key(row), []).append(row)
    merged = []
    for group in by_recipe.values():
        group.sort(key=lambda row: (row.get("strict_match") is True,
                                    row.get("symbol_registry_sha256") == registry_sha256,
                                    row.get("_assessment") is True),
                   reverse=True)
        merged.append(group[0])
    verified = {int(row["address"], 16) for row in merged
                if row.get("strict_match") is True}
    return merged, verified


def missing_fixups(row):
    return [fixup for fixup in row.get("relocations", [])
            if fixup.get("verified") is not True and fixup.get("target") is None
            and fixup.get("symbol") not in row.get("symbol_overrides", {})]


def observed_target(fixup):
    try:
        original = int(str(fixup["original"]), 0)
        site = int(str(fixup["site"]), 0)
        addend = int(fixup.get("addend", 0))
    except (KeyError, TypeError, ValueError):
        return None
    if str(fixup.get("kind", "")).upper().startswith("DIR"):
        return (original - addend) & 0xFFFFFFFF
    return (original + site + 4 - addend) & 0xFFFFFFFF


@dataclass
class Evidence:
    source: str
    path: str
    locator: str
    detail: str = ""


@dataclass
class Candidate:
    address: int
    score: int
    confidence: str
    strong: bool
    exact_alias: bool = False
    sources: set[str] = field(default_factory=set)
    evidence: list[Evidence] = field(default_factory=list)

    def merge(self, other: "Candidate"):
        self.score = max(self.score, other.score)
        if other.score > self.score:
            self.confidence = other.confidence
        self.strong = self.strong or other.strong
        self.exact_alias = self.exact_alias or other.exact_alias
        self.sources.update(other.sources)
        known = {(item.source, item.path, item.locator) for item in self.evidence}
        for item in other.evidence:
            if (item.source, item.path, item.locator) not in known:
                self.evidence.append(item)
                known.add((item.source, item.path, item.locator))


def add_candidate(store, address, source, score, confidence, strong, evidence,
                  exact_alias=False):
    if address is None:
        return
    address = int(address)
    current = store.get(address)
    candidate = Candidate(address, score, confidence, strong, exact_alias,
                          {source}, [evidence])
    if current is None:
        store[address] = candidate
    else:
        current.merge(candidate)


def evidence_item(source, path, locator, detail=""):
    return Evidence(source, str(path), locator, detail)


def load_symbol_inventory():
    raw = load_json(SYMBOL_INDEX)
    return [(words(name), name, int(address, 16), "symbol_map")
            for address, name in raw.items()]


def load_data_inventory():
    import csv
    with DATA_SYMBOLS.open() as table:
        rows = list(csv.DictReader(table))
    inventory = []
    for row in rows:
        try:
            address = int(row["address"], 16)
        except (KeyError, TypeError, ValueError):
            continue
        name = row.get("name")
        if not name:
            continue
        inventory.append((words(name), name, address, "data_symbols"))
        suffix = re.search(r"_([0-9a-fA-F]{8})$", name)
        if suffix:
            inventory.append((words(name), name, int(suffix.group(1), 16),
                              "data_symbols_address_alias"))
    return inventory


def load_vtables():
    import csv
    by_class = {}
    if VTABLE_FILE.is_file():
        with VTABLE_FILE.open() as table:
            for row in csv.DictReader(table):
                cls = row.get("class")
                try:
                    address = int(row["vtable"], 16)
                except (KeyError, TypeError, ValueError):
                    continue
                if cls:
                    by_class[normalize(cls)] = (cls, address, row)
    slots = defaultdict(list)
    if VTABLE_SLOT_FILE.is_file():
        with VTABLE_SLOT_FILE.open() as table:
            for row in csv.DictReader(table):
                cls = row.get("class")
                if not cls:
                    continue
                try:
                    target = int(row["target"], 16)
                except (KeyError, TypeError, ValueError):
                    continue
                slots[normalize(cls)].append((row.get("name", ""),
                                              row.get("raw_name", ""), target, row))
    return by_class, slots


def load_crt_report(path: Path | None):
    if path is None or not path.is_file():
        return {}
    payload = load_json(path)
    mapping = defaultdict(list)
    for kind in ("matches", "unresolved_candidates"):
        for entry in payload.get(kind, []):
            try:
                address = int(entry["address"], 16)
            except (KeyError, TypeError, ValueError):
                continue
            for variant in entry.get("variants", []):
                symbol = variant.get("symbol")
                if symbol:
                    mapping[symbol].append({
                        "address": address,
                        "kind": kind,
                        "symbol": symbol,
                        "archive": variant.get("archive", ""),
                        "member": variant.get("member", ""),
                        "method": variant.get("method", ""),
                        "ambiguity": entry.get("ambiguity", []),
                    })
    return mapping


class EvidenceIndex:
    def __init__(self, registry, rows, verified_addresses, crt_report):
        self.registry = registry
        self.crt_path = str(crt_report) if crt_report else "stock CRT archive scan"
        self.crt = load_crt_report(crt_report)
        self.symbols = load_symbol_inventory()
        self.data = load_data_inventory()
        self.vtables, self.vtable_slots = load_vtables()
        self.imports = pe_imports()
        self.verified = defaultdict(lambda: defaultdict(list))
        self.verified_functions = defaultdict(set)
        for row in rows:
            if row.get("strict_match") is not True:
                continue
            address = row.get("address")
            for fixup in row.get("relocations", []):
                if fixup.get("verified") is True and fixup.get("target"):
                    try:
                        target = int(fixup["target"], 16)
                    except (KeyError, TypeError, ValueError):
                        continue
                    self.verified[fixup["symbol"]][target].append({
                        "address": address,
                        "origin": fixup.get("origin"),
                        "source": source_path(row),
                        "flags": row.get("flags", []),
                    })
                    self.verified_functions[fixup["symbol"]].add(address)

    def candidates(self, symbol: str):
        store = {}
        self._registry(symbol, store)
        self._verified(symbol, store)
        self._exact(symbol, store)
        self._crt(symbol, store)
        self._imports(symbol, store)
        self._vtables(symbol, store)
        self._resolver(symbol, store)
        self._address_label(symbol, store)
        self._name_match(symbol, store)
        return sorted(store.values(), key=lambda item: (-item.score, item.address))

    def _registry(self, symbol, store):
        entry = self.registry.get(symbol)
        if entry:
            add_candidate(store, int(entry["address"], 16), "symbol_registry", 100,
                          "registry", True,
                          evidence_item("symbol_registry",
                                        "reconstructed/match/symbol_registry.json",
                                        entry["address"], entry.get("name", "")))

    def _verified(self, symbol, store):
        for address, records in self.verified.get(symbol, {}).items():
            for record in records:
                add_candidate(store, address, "verified_audit", 95,
                              "verified_audit", True,
                              evidence_item("verified_audit", record["source"],
                                            record["address"],
                                            f"verified {symbol} in a strict recipe"))
                break

    def _exact(self, symbol, store):
        normalized = normalize(symbol)
        global_match = re.match(r"\?(g_[^@]+)@@", symbol)
        global_name = normalize(global_match.group(1)) if global_match else None
        for inventory, source, score in ((self.symbols, "symbol_map", 85),
                                         (self.data, "data_symbols", 85)):
            for name_words, name, address, kind in inventory:
                exact = name == symbol
                if global_name and normalize(name) == global_name:
                    exact = True
                if exact:
                    add_candidate(store, address, source, score, "exact_symbol", True,
                                  evidence_item(source, SYMBOL_INDEX if source == "symbol_map"
                                                else DATA_SYMBOLS, hex(address), name))

    def _crt(self, symbol, store):
        variants = self.crt.get(symbol, [])
        addresses = {variant["address"] for variant in variants}
        if len(addresses) == 1:
            address = next(iter(addresses))
            exact = any(variant["kind"] == "matches" for variant in variants)
            same_symbol = all(variant.get("symbol") == symbol for variant in variants)
            strong = exact or same_symbol
            add_candidate(store, address, "crt_archive", 80 if strong else 55,
                          "crt_archive" if strong else "crt_archive_candidate",
                          strong,
                          evidence_item("crt_archive", self.crt_path,
                                        hex(address),
                                        f"{len(variants)} archive variant(s) for {symbol}"))
        elif addresses:
            for address in addresses:
                add_candidate(store, address, "crt_archive", 40,
                              "crt_archive_ambiguous", False,
                              evidence_item("crt_archive", self.crt_path,
                                            hex(address), symbol))

    def _imports(self, symbol, store):
        name = symbol
        for prefix in ("__imp__", "_imp__"):
            if name.startswith(prefix):
                name = name[len(prefix):].lstrip("_").split("@", 1)[0]
                break
        else:
            return
        address = self.imports.get(name)
        if address:
            add_candidate(store, address, "pe_import", 90, "pe_iat", True,
                          evidence_item("pe_import", GAME, hex(address), name))

    def _vtables(self, symbol, store):
        if symbol.startswith(("??_7", "??_8")):
            cls = symbol.split("@@", 1)[0][4:]
            key = normalize(cls)
            if key in self.vtables:
                original, address, row = self.vtables[key]
                add_candidate(store, address, "vtable", 85, "vtable", True,
                              evidence_item("vtable", VTABLE_FILE, hex(address), original))
        if "vtable" in words(symbol):
            symbol_words = words(symbol)
            matches = []
            for key, (original, address, row) in self.vtables.items():
                class_words = words(original)
                if class_words and class_words <= symbol_words:
                    matches.append((len(class_words), original, address))
            matches.sort(reverse=True)
            best = matches[0][0] if matches else 0
            top = [match for match in matches if match[0] == best]
            for overlap, original, address in matches:
                strong = (best >= 2 and len(top) == 1
                          and (overlap, original, address) == top[0])
                add_candidate(store, address, "vtable_global",
                              80 if strong else 55,
                              "vtable" if strong else "vtable_global_candidate",
                              strong,
                              evidence_item("vtable_global", VTABLE_FILE,
                                            hex(address), original))
        cls, method, method_words, class_words, _ = parsed_name(symbol)
        if not cls:
            return
        rows = self.vtable_slots.get(normalize(cls), [])
        if not rows:
            return
        normalized_method = normalize(method)
        for name, raw_name, target, row in rows:
            if normalized_method and (normalize(name) == normalized_method
                                      or normalize(raw_name) == normalized_method):
                add_candidate(store, target, "vtable_slot", 75, "vtable_slot", True,
                              evidence_item("vtable_slot", VTABLE_SLOT_FILE,
                                            hex(target), f"{cls} slot {row.get('slot')}"))

    def _resolver(self, symbol, store):
        target, origin = resolve_auto_symbol(symbol)
        if target is None:
            return
        strong = origin in STRONG_ORIGINS
        add_candidate(store, target, "resolver", 70 if strong else 40,
                      f"resolver_{origin}", strong,
                      evidence_item("resolver", "tools/match_decomp.py",
                                    hex(target), origin or ""))

    def _address_label(self, symbol, store):
        match = re.match(r"\??_?(?:DAT|STR)_([0-9a-fA-F]{8})(?:@@.*)?$", symbol)
        if match:
            address = int(match.group(1), 16)
            add_candidate(store, address, "address_label", 100, "address_label", True,
                          evidence_item("address_label", "symbol name", hex(address), symbol))

    def _name_match(self, symbol, store):
        kind = category(symbol)
        if kind in {"address_label", "import", "vtable", "local_label", "constant"}:
            return
        cls, method, method_words, class_words, _ = parsed_name(symbol)
        if not method_words:
            return
        aliases = set()
        if cls:
            aliases.add(normalize(f"{cls}_{method}"))
            if method == cls:
                aliases.update((normalize(f"{cls}_Construct"),
                                normalize(f"{cls}_Constructor")))
            elif method.startswith("~"):
                aliases.update((normalize(f"{cls}_Destructor"),
                                normalize(f"{cls}_Destroy"),
                                normalize(f"{cls}_Delete"),
                                normalize(f"{cls}_ScalarDeletingDestructor")))
        candidates = defaultdict(lambda: (0, ""))
        inventory = self.data if kind == "global" else self.symbols
        for name_words, name, address, kind in inventory:
            if method_words <= name_words:
                overlap = len(class_words & name_words)
                exact = normalize(name) in aliases
                score = overlap * 10 + (25 if exact else 0) + 5
                if score > candidates[address][0]:
                    candidates[address] = (score, name)
        if not candidates:
            return
        ranked = sorted(candidates.items(), key=lambda item: (-item[1][0], item[0]))
        best_score = ranked[0][1][0]
        if len(ranked) > 1 and best_score >= ranked[1][1][0] + 15:
            symbol_note = f"best name match {ranked[0][1][1]}"
        else:
            symbol_note = ""
        for address, (score, name) in ranked[:8]:
            confidence = "name_match" if len(ranked) == 1 else "name_match_candidate"
            add_candidate(store, address, "name_match", 45 + min(score, 20),
                          confidence, False,
                          evidence_item("name_match", "shipped function/data names",
                                        hex(address), name + (f" ({symbol_note})" if symbol_note else "")),
                          exact_alias=(normalize(name) in aliases))


@dataclass
class Fact:
    symbol: str
    category: str
    affected: set[str] = field(default_factory=set)
    observed: Counter = field(default_factory=Counter)
    candidates: list[Candidate] = field(default_factory=list)
    notes: list[str] = field(default_factory=list)
    sole: int = 0
    section_only: bool = False

    @property
    def authoritative(self):
        return [candidate for candidate in self.candidates if candidate.strong]

    @property
    def decision_candidates(self):
        return self.authoritative or self.candidates

    @property
    def status(self):
        if self.category in LOCAL_CATEGORIES:
            return "local"
        if not self.candidates:
            return "missing"
        choices = self.decision_candidates
        if len({candidate.address for candidate in choices}) > 1:
            return "ambiguous"
        if self.authoritative:
            return "ready"
        candidate = choices[0]
        if candidate.exact_alias or hex(candidate.address) in set(self.observed):
            return "candidate"
        return "needs_evidence"

    @property
    def chosen(self):
        choices = self.decision_candidates
        addresses = {candidate.address for candidate in choices}
        return next(iter(addresses)) if len(addresses) == 1 else None


def build_facts(rows, verified, index: EvidenceIndex):
    blockers = {}
    blocker_rows = {}
    section_names = set()
    for row in rows:
        address = int(row["address"], 16)
        if address in verified or row.get("match") is not True:
            continue
        if row.get("relocation_issues") or row.get("link_plan_issues"):
            continue
        fixups = missing_fixups(row)
        names = {fixup["symbol"] for fixup in fixups}
        if names:
            blockers[address] = names
            blocker_rows[address] = row
        for section in row.get("blocked_sections", []):
            section_names.update(section.get("symbols", []))
    body_names = set().union(*blockers.values()) if blockers else set()
    all_names = set(body_names) | section_names
    facts = {}
    for symbol in sorted(all_names):
        fact = Fact(symbol, category(symbol),
                    section_only=symbol in section_names and symbol not in body_names)
        if fact.category in LOCAL_CATEGORIES:
            fact.notes.append("local compiler label or constant; not a shared address")
        for candidate in index.candidates(symbol):
            fact.candidates.append(candidate)
        facts[symbol] = fact
    for address, names in blockers.items():
        for symbol in names:
            facts[symbol].affected.add(hex(address))
        row = blocker_rows[address]
        for symbol in names:
            for fixup in missing_fixups(row):
                if fixup["symbol"] != symbol:
                    continue
                target = observed_target(fixup)
                if target is not None:
                    facts[symbol].observed[hex(target)] += 1
    # Corroborate candidates against observed targets without promoting them.
    for fact in facts.values():
        observed = set(fact.observed)
        for candidate in fact.candidates:
            if hex(candidate.address) in observed:
                candidate.score += 5
                candidate.evidence.append(
                    evidence_item("observed_relocation", "audit record",
                                  hex(candidate.address),
                                  "matches the original relocation target (investigation only)"))
    for address, names in shared_blockers(blockers).items():
        if len(names) == 1:
            facts[next(iter(names))].sole += 1
    for fact in facts.values():
        fact.candidates.sort(key=lambda item: (-item.score, item.address))
        if len(fact.candidates) == 1 and fact.candidates[0].strong:
            pass
        elif len(fact.candidates) > 1:
            corroborated = [candidate for candidate in fact.candidates
                            if hex(candidate.address) in set(fact.observed)]
            if len(corroborated) == 1:
                fact.notes.append("one candidate matches the observed relocation target; still ambiguous")
            elif not corroborated:
                fact.notes.append("no candidate matches the observed relocation target")
    return facts, blockers, body_names, section_names


def shared_blockers(blockers):
    return {address: {symbol for symbol in names if not is_local(symbol)}
            for address, names in blockers.items()}


def make_group(group, covered_ready, covered_candidate, covered_possible,
               facts, affected, seeds=()):
    group = frozenset(symbol for symbol in group if not is_local(symbol))
    missing = sorted(symbol for symbol in group
                     if not facts[symbol].candidates)
    ambiguous = sorted(symbol for symbol in group
                       if facts[symbol].status == "ambiguous")
    observed_only = sorted(symbol for symbol in group
                           if not facts[symbol].candidates and facts[symbol].observed)
    return {
        "facts": sorted(group),
        "seeds": sorted(seeds),
        "fact_count": len(group),
        "missing": missing,
        "ambiguous": ambiguous,
        "observed_only": observed_only,
        "covered_ready": sorted(covered_ready, key=lambda value: int(value, 16)),
        "covered_candidate": sorted(covered_candidate, key=lambda value: int(value, 16)),
        "covered_possible": sorted(covered_possible, key=lambda value: int(value, 16)),
        "covered_ready_count": len(covered_ready),
        "covered_candidate_count": len(covered_candidate),
        "covered_possible_count": len(covered_possible),
        "affected": sorted(affected, key=lambda value: int(value, 16)),
        "affected_count": len(affected),
    }


def rank_groups(facts, blockers, top=25):
    shared = shared_blockers(blockers)
    ready = {symbol for symbol, fact in facts.items()
             if symbol in shared_symbols(shared) and fact.status == "ready"}
    candidate = {symbol for symbol, fact in facts.items()
                 if symbol in shared_symbols(shared)
                 and fact.status in {"ready", "candidate"}}
    possible = {symbol for symbol, fact in facts.items()
                if symbol in shared_symbols(shared)
                and (fact.candidates or fact.observed)}
    focus_symbols = [symbol for symbol in facts
                     if symbol in shared_symbols(shared)
                     and (facts[symbol].candidates or facts[symbol].observed)]
    groups = {}
    seed_map = defaultdict(set)
    focus_groups = []
    for focus in focus_symbols:
        group = {focus}
        affected = set()
        for address, names in shared.items():
            if focus in names:
                group |= names
                affected.add(hex(address))
        group = {symbol for symbol in group if not is_local(symbol)}
        if not group:
            continue
        covered_ready = {hex(address) for address, names in shared.items()
                         if names and names <= group
                         and names <= ready}
        covered_candidate = {hex(address) for address, names in shared.items()
                             if names and names <= group
                             and names <= candidate}
        covered_possible = {hex(address) for address, names in shared.items()
                            if names and names <= group
                            and names <= possible}
        key = frozenset(group)
        groups[key] = make_group(group, covered_ready, covered_candidate,
                                  covered_possible, facts, affected, {focus})
        seed_map[key].add(focus)
        focus_groups.append({"focus": focus, **groups[key]})
    for address, names in shared.items():
        if not names:
            continue
        group = frozenset(names)
        covered_ready = {hex(address)} if names <= ready else set()
        covered_candidate = {hex(address)} if names <= candidate else set()
        covered_possible = {hex(address)} if names <= possible else set()
        groups.setdefault(group, make_group(group, covered_ready,
                                            covered_candidate, covered_possible,
                                            facts, {hex(address)}, seed_map.get(group, ())))
    # Merge pairs of high-value focus groups when the union covers more functions.
    seed_groups = sorted(groups.values(),
                         key=lambda item: (-item["covered_possible_count"],
                                           -item["covered_candidate_count"],
                                           item["fact_count"]))[:10]
    for left in seed_groups:
        for right in seed_groups:
            if left is right:
                continue
            group = frozenset(set(left["facts"]) | set(right["facts"]))
            if group in groups:
                continue
            covered_ready = {hex(address) for address, names in shared.items()
                             if names and names <= group and names <= ready}
            covered_candidate = {hex(address) for address, names in shared.items()
                                 if names and names <= group and names <= candidate}
            covered_possible = {hex(address) for address, names in shared.items()
                                if names and names <= group and names <= possible}
            affected = set(left["affected"]) | set(right["affected"])
            groups[group] = make_group(group, covered_ready, covered_candidate,
                                       covered_possible, facts, affected,
                                       seed_map.get(frozenset(left["facts"]), set())
                                       | seed_map.get(frozenset(right["facts"]), set()))
    ranked = sorted(groups.values(),
                    key=lambda item: (-item["covered_possible_count"],
                                      -item["covered_candidate_count"],
                                      -item["covered_ready_count"],
                                      len(item["missing"]) + len(item["ambiguous"]),
                                      item["fact_count"],
                                      item["facts"]))
    focus_ranked = sorted(focus_groups,
                          key=lambda item: (-item["covered_possible_count"],
                                            -item["covered_candidate_count"],
                                            -len(facts[item["focus"]].affected),
                                            item["fact_count"]))
    return ranked[:top], focus_ranked[:top]


def shared_symbols(shared):
    result = set()
    for names in shared.values():
        result |= names
    return result


def registry_entry(fact: Fact):
    candidate = next(candidate for candidate in fact.decision_candidates
                     if candidate.address == fact.chosen)
    sources = candidate.sources
    if fact.category == "vtable" or "vtable" in sources:
        kind = "vtable"
    elif fact.category in {"global", "address_label"} or "data_symbols" in sources:
        kind = "global"
    elif fact.category == "import" or "pe_import" in sources:
        kind = "import"
    else:
        kind = "function"
    name = fact.symbol
    _, method, _, _, declaration = parsed_name(fact.symbol)
    if method:
        name = method
    evidence = [{"path": item.path, "locator": item.locator}
                for item in candidate.evidence
                if item.source != "observed_relocation"]
    entry = {
        "symbol": fact.symbol,
        "address": hex(candidate.address),
        "name": name,
        "kind": kind,
        "evidence": evidence,
        "proposal": {"status": fact.status, "confidence": candidate.confidence,
                     "affected": sorted(fact.affected,
                                        key=lambda value: int(value, 16)),
                     "observed_targets": dict(fact.observed)},
    }
    if declaration and declaration != fact.symbol:
        entry["candidate_declaration"] = declaration
    return entry


def fact_payload(fact: Fact):
    return {
        "symbol": fact.symbol,
        "category": fact.category,
        "status": fact.status,
        "affected": sorted(fact.affected, key=lambda value: int(value, 16)),
        "affected_count": len(fact.affected),
        "sole_blocker_count": fact.sole,
        "section_only": fact.section_only,
        "chosen_address": hex(fact.chosen) if fact.chosen is not None else None,
        "candidates": [
            {
                "address": hex(candidate.address),
                "confidence": candidate.confidence,
                "score": candidate.score,
                "strong": candidate.strong,
                "sources": sorted(candidate.sources),
                "evidence": [item.__dict__ for item in candidate.evidence],
                "observed_match": hex(candidate.address) in set(fact.observed),
                "authoritative": candidate.strong,
                "exact_alias": candidate.exact_alias,
            }
            for candidate in fact.candidates
        ],
        "observed_targets": [{"address": address, "count": count}
                             for address, count in fact.observed.most_common()],
        "notes": fact.notes,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("audit", nargs="+", type=Path,
                        help="audit directory or assessment JSON")
    parser.add_argument("--crt-report", type=Path,
                        help="JSON report from tools/match_crt_archive.py")
    parser.add_argument("--json-out", type=Path, required=True)
    parser.add_argument("--report-out", type=Path)
    parser.add_argument("--registry-fragment-out", type=Path)
    parser.add_argument("--pilot-fragment-out", type=Path)
    parser.add_argument("--top-groups", type=int, default=25)
    parser.add_argument("--only-symbol", action="append", default=[])
    parser.add_argument("--pilot", action="store_true",
                        help="highlight CRT, vtable, and C++ runtime helpers")
    args = parser.parse_args()

    executable_sha256 = file_sha256(GAME)
    registry_sha256 = file_sha256(ROOT / "reconstructed/match/symbol_registry.json")
    rows, inputs = load_rows(args.audit, executable_sha256)
    rows, verified = merge_rows(rows, registry_sha256)
    registry = current_registry()
    index = EvidenceIndex(registry, rows, verified, args.crt_report)
    facts, blockers, body_names, section_names = build_facts(rows, verified, index)
    row_by_address = {row.get("address"): row for row in rows}
    lengths = function_lengths()
    if args.only_symbol:
        wanted = set(args.only_symbol)
        facts = {symbol: fact for symbol, fact in facts.items() if symbol in wanted}
        blockers = {address: {symbol for symbol in names if symbol in wanted}
                    for address, names in blockers.items()}
        blockers = {address: names for address, names in blockers.items() if names}
    all_groups, focus_groups = rank_groups(facts, blockers,
                                           max(args.top_groups, 500))
    groups = all_groups[:args.top_groups]
    ready_facts = [fact for fact in facts.values() if fact.status == "ready"]
    ready_groups = sorted(
        (group for group in all_groups if group["covered_ready_count"]),
        key=lambda item: (-item["covered_ready_count"],
                          -item["covered_candidate_count"],
                          item["fact_count"]))[:args.top_groups]
    candidate_facts = [fact for fact in facts.values() if fact.status == "candidate"]
    ambiguous_facts = [fact for fact in facts.values() if fact.status == "ambiguous"]
    needs_evidence_facts = [fact for fact in facts.values() if fact.status == "needs_evidence"]
    missing_facts = [fact for fact in facts.values() if fact.status == "missing"]
    local_addresses = sorted(
        {hex(address) for address, names in blockers.items()
         if names and not shared_blockers({address: names})[address]},
        key=lambda value: int(value, 16))
    all_addresses = sorted({address for fact in facts.values()
                            for address in fact.affected},
                           key=lambda value: int(value, 16))
    cache_eligible = []
    for address in all_addresses:
        row = row_by_address.get(address)
        if not row or not row.get("entry"):
            continue
        if not set(row.get("flags", [])) <= CACHE_FLAGS:
            continue
        if lengths.get(int(address, 16)) != row.get("length"):
            continue
        source = source_path(row)
        if source and (ROOT / source).is_file():
            cache_eligible.append(address)
    payload = {
        "schema": VERSION,
        "executable_sha256": executable_sha256,
        "symbol_registry_sha256": registry_sha256,
        "audits": inputs,
        "summary": {
            "body_only_addresses": len(blockers),
            "unresolved_names": len(body_names),
            "all_names": len(facts),
            "ready_facts": len(ready_facts),
            "candidate_facts": len(candidate_facts),
            "ambiguous_facts": len(ambiguous_facts),
            "needs_evidence_facts": len(needs_evidence_facts),
            "missing_facts": len(missing_facts),
            "local_only_addresses": len(local_addresses),
            "groups": len(groups),
            "section_blocked_symbols": len(section_names),
            "pilot_mode": args.pilot,
        },
        "facts": [fact_payload(fact) for fact in sorted(
            facts.values(), key=lambda item: (-len(item.affected), item.symbol))],
        "section_facts": [fact_payload(fact) for fact in sorted(
            (fact for fact in facts.values() if fact.section_only),
            key=lambda item: item.symbol)],
        "groups": groups,
        "focus_groups": focus_groups,
        "ready_groups": ready_groups,
        "local_only_addresses": local_addresses,
        "ambiguous": [fact_payload(fact) for fact in sorted(
            ambiguous_facts, key=lambda item: (-len(item.affected), item.symbol))],
        "needs_evidence": [fact_payload(fact) for fact in sorted(
            needs_evidence_facts, key=lambda item: (-len(item.affected), item.symbol))],
        "missing": [fact_payload(fact) for fact in sorted(
            missing_facts, key=lambda item: (-len(item.affected), item.symbol))],
        "pilot": {
            "ready": [fact_payload(fact) for fact in sorted(
                (fact for fact in facts.values()
                 if fact.status == "ready" and is_pilot(fact.symbol, fact.category)),
                key=lambda item: (-len(item.affected), item.symbol))],
            "candidates": [fact_payload(fact) for fact in sorted(
                (fact for fact in facts.values()
                 if fact.status == "candidate" and is_pilot(fact.symbol, fact.category)),
                key=lambda item: (-len(item.affected), item.symbol))],
        },
        "luna_tasks": {
            "ambiguous": [fact_payload(fact) for fact in sorted(
                ambiguous_facts, key=lambda item: (-len(item.affected), item.symbol))[:60]],
            "missing": [fact_payload(fact) for fact in sorted(
                missing_facts + needs_evidence_facts,
                key=lambda item: (-len(item.affected), item.symbol))[:60]],
            "candidate_name_matches": [fact_payload(fact) for fact in sorted(
                (fact for fact in candidate_facts if len(fact.affected) >= 2),
                key=lambda item: (-item.sole, -len(item.affected), item.symbol))[:60]],
            "section_layout": [fact_payload(fact) for fact in sorted(
                (fact for fact in facts.values() if fact.section_only),
                key=lambda item: item.symbol)[:60]],
        },
        "recheck": {
            "ready_addresses": sorted({address for fact in ready_facts
                                       for address in fact.affected},
                                      key=lambda value: int(value, 16)),
            "candidate_addresses": sorted({address for fact in candidate_facts
                                           for address in fact.affected},
                                          key=lambda value: int(value, 16)),
            "all_addresses": all_addresses,
            "cache_eligible_addresses": cache_eligible,
        },
    }
    pilot_facts = [fact for fact in facts.values()
                   if fact.status == "ready" and is_pilot(fact.symbol, fact.category)]
    fragment_facts = pilot_facts if args.pilot else ready_facts
    fragment = {
        "schema": "pc2.symbol_registry.v1",
        "executable_sha256": executable_sha256,
        "base_registry_sha256": registry_sha256,
        "entries": [registry_entry(fact) for fact in sorted(
            fragment_facts, key=lambda item: (-len(item.affected), item.symbol))],
    }
    pilot_fragment = {
        "schema": "pc2.symbol_registry.v1",
        "executable_sha256": executable_sha256,
        "base_registry_sha256": registry_sha256,
        "entries": [registry_entry(fact) for fact in sorted(
            pilot_facts, key=lambda item: (-len(item.affected), item.symbol))],
    }
    payload["registry_fragment"] = fragment
    payload["registry_fragment"]["entry_count"] = len(fragment["entries"])
    payload["pilot"]["registry_fragment"] = pilot_fragment
    payload["pilot"]["registry_fragment"]["entry_count"] = len(pilot_fragment["entries"])
    args.json_out.parent.mkdir(parents=True, exist_ok=True)
    args.json_out.write_text(json.dumps(payload, indent=2) + "\n")
    if args.registry_fragment_out:
        args.registry_fragment_out.write_text(json.dumps(fragment, indent=2) + "\n")
    if args.pilot_fragment_out:
        args.pilot_fragment_out.write_text(json.dumps(pilot_fragment, indent=2) + "\n")
    if args.report_out:
        lines = [
            "# Blocked symbol reuse proposals",
            "",
            f"- body-only addresses: {len(blockers)}",
            f"- unresolved names: {len(body_names)}",
            f"- ready facts: {len(ready_facts)}",
            f"- candidate facts: {len(candidate_facts)}",
            f"- ambiguous facts: {len(ambiguous_facts)}",
            f"- missing facts: {len(missing_facts)}",
            "",
            "## Top groups by potential functions finished",
            "",
            "| potential | candidate | ready | facts | missing/ambiguous | addresses |",
            "|---:|---:|---:|---:|---:|---|",
        ]
        for group in groups[:15]:
            lines.append(
                f"| {group['covered_possible_count']} | {group['covered_candidate_count']} | "
                f"{group['covered_ready_count']} | {group['fact_count']} | "
                f"{len(group['missing']) + len(group['ambiguous'])} | "
                f"{', '.join(group['covered_possible'][:8])} |")
        lines += ["", "## Highest-impact facts", "",
                  "| affected | status | symbol | evidence | observed targets |",
                  "|---:|---|---|---|---|"]
        for fact in sorted(facts.values(),
                           key=lambda item: (-len(item.affected), item.symbol))[:30]:
            evidence = ", ".join(sorted({candidate.confidence
                                         for candidate in fact.candidates})) or "none"
            observed = ", ".join(address for address, _ in fact.observed.most_common(3)) or "-"
            lines.append(f"| {len(fact.affected)} | {fact.status} | `{fact.symbol}` | "
                         f"{evidence} | {observed} |")
        lines += ["", "## Focus groups", "",
                  "| seed | potential | candidate | ready | facts | missing | ambiguous | addresses |",
                  "|---|---:|---:|---:|---:|---:|---:|---|"]
        for group in focus_groups[:15]:
            lines.append(
                f"| `{group['focus']}` | {group['covered_possible_count']} | "
                f"{group['covered_candidate_count']} | {group['covered_ready_count']} | "
                f"{group['fact_count']} | {len(group['missing'])} | "
                f"{len(group['ambiguous'])} | {', '.join(group['covered_possible'][:8])} |")
        lines += ["", "## Ambiguous mappings for Luna", "",
                  "| affected | symbol | candidates | observed target |",
                  "|---:|---|---|---|"]
        for fact in sorted(ambiguous_facts,
                           key=lambda item: (-len(item.affected), item.symbol))[:40]:
            candidates = ", ".join(hex(candidate.address)
                                    for candidate in fact.candidates[:4])
            observed = ", ".join(address for address, _ in fact.observed.most_common(3)) or "-"
            lines.append(f"| {len(fact.affected)} | `{fact.symbol}` | {candidates} | {observed} |")
        lines += ["", "## Missing evidence for Luna", "",
                  "| affected | symbol | category | observed target | note |",
                  "|---:|---|---|---|---|"]
        for fact in sorted(missing_facts + needs_evidence_facts,
                           key=lambda item: (-len(item.affected), item.symbol))[:40]:
            observed = ", ".join(address for address, _ in fact.observed.most_common(3)) or "-"
            note = "; ".join(fact.notes) or "no independent candidate"
            lines.append(f"| {len(fact.affected)} | `{fact.symbol}` | {fact.category} | {observed} | {note} |")
        if ready_groups:
            lines += ["", "## Ready groups", "",
                      "| ready | candidate | facts | addresses |",
                      "|---:|---:|---:|---|"]
            for group in ready_groups[:10]:
                lines.append(f"| {group['covered_ready_count']} | "
                             f"{group['covered_candidate_count']} | {group['fact_count']} | "
                             f"{', '.join(group['covered_ready'][:8])} |")
        args.report_out.write_text("\n".join(lines) + "\n")
    print(f"proposed facts={len(facts)} ready={len(ready_facts)} "
          f"candidate={len(candidate_facts)} ambiguous={len(ambiguous_facts)} "
          f"needs_evidence={len(needs_evidence_facts)} missing={len(missing_facts)} "
          f"groups={len(groups)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
