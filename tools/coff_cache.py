"""Local cache for self-contained VC6 compiler inputs."""

import hashlib
import json
import os
from pathlib import Path
import shutil
import tempfile


CACHE_FLAGS = frozenset(("/O1", "/O2", "/TP", "/TC", "/Os", "/Ot", "/Oy", "/Oy-",
                         "/Oi", "/Oi-", "/G5", "/G6", "/GX", "/GX-"))
VOLATILE_SOURCE = (b"#", b"%:", b"??", b"__DATE__", b"__TIME__", b"__TIMESTAMP__",
                   b"__pragma", b"_Pragma", b"\\\n", b"\\\r")
ENVIRONMENT_KEYS = frozenset(("PATH", "HOME", "USER", "LOGNAME", "LANG", "LANGUAGE", "INCLUDE", "LIB",
                              "TMP", "TEMP", "TMPDIR", "DISPLAY", "XAUTHORITY", "WAYLAND_DISPLAY",
                              "DBUS_SESSION_BUS_ADDRESS"))
ENVIRONMENT_OVERRIDES = frozenset(("CL", "_CL_", "WINELOADER", "WINEDLLOVERRIDES", "WINEDLLPATH",
                                   "LD_PRELOAD", "LD_LIBRARY_PATH", "LD_AUDIT"))


def hash_bytes(data):
    return hashlib.sha256(data).hexdigest()


def cache_environment():
    if any(value and key.upper() in ENVIRONMENT_OVERRIDES for key, value in os.environ.items()):
        return None
    env = {key: value for key, value in os.environ.items()
           if key in ENVIRONMENT_KEYS or key.startswith(("LC_", "WINE", "XDG_"))}
    wine_prefix = Path(env.get("WINEPREFIX") or (Path.home() / ".wine"))
    if (wine_prefix / "dosdevices" / "z:").resolve() != Path("/"):
        return None
    env["WINEDEBUG"] = "-all"
    return env


def cache_identity(vc6, cwd, environment):
    if environment is None:
        return None
    path = environment.get("PATH", os.defpath)
    wine = shutil.which("wine", path=path)
    if not wine:
        return None
    paths = [*sorted((vc6 / "BIN").glob("*")), Path(wine)]
    if server := shutil.which("wineserver", path=path):
        paths.append(Path(server))
    files = {str(path.absolute()): hash_bytes(path.read_bytes()) for path in paths
             if path.suffix.lower() in {".exe", ".dll"} or path.name in {"wine", "wineserver"}}
    return hash_bytes(json.dumps({"schema": 2, "environment": environment, "inputs": files,
                                  "cwd": str(cwd)}, sort_keys=True).encode())


def cache_path(directory, identity, source, source_bytes, flags):
    if (not identity or not source_bytes.isascii() or not set(flags) <= CACHE_FLAGS
            or any(marker in source_bytes for marker in VOLATILE_SOURCE)):
        return None
    key = hash_bytes(json.dumps([identity, str(source), hash_bytes(source_bytes), flags]).encode())
    return directory / f"{key}.obj"


def store_object(path, data):
    with tempfile.NamedTemporaryFile(dir=path.parent) as file:
        file.write(data)
        file.flush()
        try:
            os.link(file.name, path)
        except FileExistsError:
            pass
