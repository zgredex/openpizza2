// rea decompile_all
// name: MapActor_UpdateLinkedOverlays
// address: 0x4f1b60
// body: available
// range: 0x4f1b60-0x4f1d80 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall MapActor_UpdateLinkedOverlays(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  int local_4;
  
                    /* Maintains a map actor's linked overlay slots and idle release. */
  piVar1 = param_1;
  iVar2 = 0;
  iVar3 = 0;
  iVar4 = 0;
  local_8 = 0;
  local_4 = 0;
  if (param_1[1] == -1) {
    param_1[0x15] = param_1[0x15] + 1;
    if (-1 < param_1[0xe]) {
      iVar3 = *(int *)((int)this + 0x4c) + param_1[0xe] * 0xc;
    }
    if (-1 < param_1[0xf]) {
      iVar4 = *(int *)((int)this + 0x4c) + param_1[0xf] * 0xc;
    }
    if (-1 < param_1[0x13]) {
      local_8 = *(int *)((int)this + 0x4c) + param_1[0x13] * 0xc;
    }
    if (-1 < param_1[0x14]) {
      local_4 = *(int *)((int)this + 0x4c) + param_1[0x14] * 0xc;
    }
    if (iVar3 != 0) {
      if (*(int *)(*(int *)(iVar3 + 8) + 0x34) == 0) {
        param_1[0xe] = -1;
        Record_SelectVariant((void *)param_1[0x16],*param_1,param_1[3]);
        piVar1[0x10] = -1;
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
    }
    if (iVar4 != 0) {
      if (*(int *)(*(int *)(iVar4 + 8) + 0x34) == 0) {
        piVar1[0xf] = -1;
        Record_SelectVariant((void *)piVar1[0x16],*piVar1,piVar1[3]);
        piVar1[0x10] = -1;
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
    }
    if (local_8 != 0) {
      iVar3 = FUN_004f5b40(local_8,(int)piVar1,piVar1 + 0x13,&param_1);
      if (iVar3 == 0) {
        if (param_1 == (int *)0x0) {
          Record_SelectVariant((void *)piVar1[0x16],*piVar1,piVar1[3]);
        }
        piVar1[0x10] = -1;
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
    }
    if (local_4 == 0) {
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      iVar3 = FUN_004f5b40(local_4,(int)piVar1,piVar1 + 0x14,&param_1);
      if (iVar3 != 0) {
        return 1;
      }
      if (param_1 == (int *)0x0) {
        Record_SelectVariant((void *)piVar1[0x16],*piVar1,piVar1[3]);
      }
      piVar1[0x10] = -1;
    }
    iVar3 = piVar1[0x15];
    piVar1[0x15] = -1;
    if (200 < iVar3) {
      FUN_004f5ae0(this,(int)piVar1);
      FUN_004d3680((void *)piVar1[0x1e]);
      return 1;
    }
  }
  else {
    if (-1 < param_1[0xe]) {
      iVar3 = *(int *)((int)this + 0x4c) + param_1[0xe] * 0xc;
    }
    if (-1 < param_1[0xf]) {
      iVar4 = *(int *)((int)this + 0x4c) + param_1[0xf] * 0xc;
    }
    if ((iVar3 != 0) && (*(int *)(*(int *)(iVar3 + 8) + 0x30) == 0)) {
      param_1[0xe] = -1;
      Record_SelectVariant((void *)param_1[0x16],*param_1,param_1[3]);
      piVar1[0x10] = -1;
    }
    if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 8) + 0x30) == 0)) {
      piVar1[0xf] = -1;
      Record_SelectVariant((void *)piVar1[0x16],*piVar1,piVar1[3]);
      piVar1[0x10] = -1;
    }
  }
  return 0;
}

