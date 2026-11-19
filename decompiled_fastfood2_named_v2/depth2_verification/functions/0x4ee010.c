// rea decompile_all
// name: FUN_004ee010
// address: 0x4ee010
// body: available
// range: 0x4ee010-0x4ee365 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ee010(void *this,int param_1,uint *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  void *this_00;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  int local_2c;
  void *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  puVar4 = param_2;
  iVar9 = param_3 * 0xc;
  local_1c = 0;
  local_28 = this;
  this_00 = (void *)FUN_004eab50(*(void **)((int)this + 4),*(int *)(param_2[2] + 4 + iVar9));
  if (this_00 == (void *)0x0) {
    return;
  }
  local_10 = this_00;
  if (param_1 != 3) {
    FUN_004f34c0(this,(int *)puVar4,&local_c,&local_24);
    FUN_004ed780(this,(int *)puVar4,this_00,&local_2c,(int *)&param_2);
    param_2 = (uint *)((int)param_2 + *(int *)((int)this + 0x28));
    FUN_0053d100(this_00,&local_8,&local_18);
    FUN_0053d090(this_00,&local_4,&local_14);
    iVar5 = local_14 + local_18 + (int)param_2;
    if (param_1 == 1) {
      if (local_24 < iVar5) {
        return;
      }
    }
    else if ((param_1 == 2) && (iVar5 <= local_24)) {
      return;
    }
  }
  uVar8 = puVar4[2];
  local_20 = *(int *)(uVar8 + 8 + iVar9);
  if (local_20 == 0) {
    FUN_004ede90(this,puVar4,this_00);
    if (param_3 == 1) {
      FUN_004edf30(this,puVar4);
      return;
    }
  }
  else {
    iVar9 = 0;
    if (0 < local_20) {
      iVar5 = (param_3 * 3 + 3) * 4;
      piVar6 = (int *)(*(int *)(iVar5 + uVar8) + 8);
      do {
        if (piVar6[-1] != 0) {
          iVar2 = *piVar6;
          if (*(char *)(iVar2 + 2) == '\x02') {
            FUN_004ed810(this,(int *)puVar4,*(void **)(iVar2 + 0x48),&local_2c,(int *)&param_2);
            FUN_005344e0(*(void **)(iVar2 + 0x48),*(uint **)((int)this + 8),DAT_0058072c,
                         *(int *)(*(int *)(iVar5 + puVar4[2]) + iVar9 * 0xc));
            FUN_00534150(*(void **)(iVar2 + 0x48),
                         *(int *)(*(int *)(iVar5 + puVar4[2]) + iVar9 * 0xc));
            local_1c = 1;
            goto LAB_004ee193;
          }
          this_00 = local_10;
        }
        iVar9 = iVar9 + 1;
        piVar6 = piVar6 + 3;
      } while (iVar9 < local_20);
    }
    bVar1 = *(byte *)(uVar8 + 0x2d);
    if ((bVar1 != 0) && (puVar7 = (ushort *)FUN_0053d4a0((int)this_00), puVar7 != (ushort *)0x0)) {
      FUN_0048ce70(puVar7,(uint)*(byte *)(*(int *)((int)this + 8) + 0x18),bVar1 - 1);
    }
    FUN_004ede90(this,puVar4,this_00);
LAB_004ee193:
    if (0 < local_20) {
      param_1 = local_20;
      iVar5 = (param_3 * 3 + 3) * 4;
      iVar9 = 0;
      do {
        iVar2 = *(int *)(*(int *)(puVar4[2] + iVar5) + 8 + iVar9);
        if (*(int *)(*(int *)(puVar4[2] + iVar5) + 4 + iVar9) == 0) {
          if ((*(char *)(iVar2 + 1) == '\x02') && (uVar8 = FUN_004034d0(1,10000), (int)uVar8 < 0x3c)
             ) {
            *(undefined4 *)(*(int *)(puVar4[2] + iVar5) + 4 + iVar9) = 1;
            Record_ApplyVariantState
                      (*(void **)(iVar2 + 0x48),*(int *)(*(int *)(puVar4[2] + iVar5) + iVar9),0,1);
          }
        }
        else {
          if (*(char *)(iVar2 + 2) == '\x01') {
            FUN_004ed810(local_28,(int *)puVar4,*(void **)(iVar2 + 0x48),&local_2c,(int *)&param_2);
            FUN_005344e0(*(void **)(iVar2 + 0x48),*(uint **)((int)local_28 + 8),DAT_0058072c,
                         *(int *)(*(int *)(puVar4[2] + iVar5) + iVar9));
            FUN_00534150(*(void **)(iVar2 + 0x48),*(int *)(*(int *)(puVar4[2] + iVar5) + iVar9));
          }
          if (*(char *)(iVar2 + 1) == '\x02') {
            iVar3 = *(int *)(*(int *)(puVar4[2] + iVar5) + iVar9);
            if (((iVar3 < 0) || (*(int *)(*(int *)(iVar2 + 0x48) + 0x48) <= iVar3)) ||
               (*(char *)(*(int *)(*(int *)(iVar2 + 0x48) + 0x4c) + 0x3e + iVar3 * 0x48) == '\0')) {
              *(undefined4 *)(*(int *)(puVar4[2] + iVar5) + iVar9 + 4) = 0;
            }
          }
        }
        iVar9 = iVar9 + 0xc;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      this = local_28;
    }
    if ((local_1c == 0) && (param_3 == 1)) {
      FUN_004edf30(this,puVar4);
    }
  }
  return;
}

