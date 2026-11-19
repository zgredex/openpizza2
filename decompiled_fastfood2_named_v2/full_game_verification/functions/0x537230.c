// rea decompile_all
// name: Window_Construct
// address: 0x537230
// body: available
// range: 0x537230-0x53734a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Window_Construct(void *this,int param_1,int param_2,uint param_3)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30c [192];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ad1e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = &PTR_Window_Delete_0055c814;
  *(undefined4 *)((int)this + 0x14) = 0;
  if ((int)param_3 < 8) {
    if (param_3 != 1) goto LAB_005372e8;
  }
  else {
    if (0x20 < (int)param_3) {
      param_3 = 4;
      goto LAB_005372e8;
    }
    if (0x18 < (int)param_3) {
      param_3 = 3;
      goto LAB_005372e8;
    }
    if (0xf < (int)param_3) {
      param_3 = 2;
      goto LAB_005372e8;
    }
    param_3 = 1;
  }
  puVar4 = local_30c;
  for (iVar3 = 0xc0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  pvVar2 = operator_new(0x20c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = Palette_Init(pvVar2,0,local_30c,0);
  }
  *(int **)((int)this + 0x14) = piVar1;
LAB_005372e8:
  local_4 = 0xffffffff;
  *(char *)((int)this + 0x11) = (char)param_3;
  *(int *)((int)this + 4) = param_1;
  iVar3 = (param_3 & 0xff) * param_1 * param_2;
  *(int *)((int)this + 0xc) = iVar3;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(int *)((int)this + 8) = param_2;
  *(char *)((int)this + 0x10) = (char)param_3 << 3;
  pvVar2 = operator_new((iVar3 >> 1) * 2 + 2);
  *(void **)((int)this + 0x18) = pvVar2;
  ExceptionList = local_c;
  return this;
}

