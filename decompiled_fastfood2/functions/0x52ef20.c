// rea decompile_all
// name: FUN_0052ef20
// address: 0x52ef20
// body: available
// range: 0x52ef20-0x52f07e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0052ef20(void *this,int param_1,int param_2,uint param_3,int param_4)

{
  LPRECT lprc;
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  byte bStack_e;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa3b;
  local_c = ExceptionList;
  iVar3 = 4;
  puVar4 = (uint *)((int)this + 0xfc);
  ExceptionList = &local_c;
  do {
    if (*puVar4 != 0xff000000) {
      *(int *)((int)this + 0x10c) = *(int *)((int)this + 0x10c) + 1;
      uVar1 = *puVar4;
      bStack_e = (byte)(uVar1 >> 0x10);
      if ((((uVar1 & 0xff) < 8) && (bStack_e < 8)) && (0xf7 < (uVar1 >> 8 & 0xff))) {
        *puVar4 = 0xf700;
      }
    }
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar5 = (undefined4 *)0x0;
  if (*(int *)((int)this + 0x114) != 0) {
    pvVar2 = operator_new(0x50);
    local_4 = 0;
    if (pvVar2 != (void *)0x0) {
      puVar5 = FUN_0053c710(pvVar2,param_3,param_4,0,0x10,0);
    }
    pvVar2 = *(void **)((int)this + 0xdc);
    *(undefined4 **)((int)this + 0x50) = puVar5;
    local_4 = 0xffffffff;
    if (*(char *)((int)puVar5 + 0x39) == '\0') {
      FUN_0053cea0(puVar5);
    }
    FUN_00539280(pvVar2,puVar5[0xb],(ushort)((int)*(short *)((int)puVar5 + 6) >> 1),
                 *(ushort *)(puVar5 + 2),(int)*(short *)((int)puVar5 + 6));
  }
  lprc = (LPRECT)((int)this + 8);
  SetRect(lprc,param_1,param_2,param_1 + 0x140,param_2 + 200);
  FUN_005301f0((int)this);
  if (*(int *)((int)this + 0x168) == 0) {
    SetRect(lprc,param_1,param_2,param_3 + param_1,param_2 + param_4);
  }
  *(LONG *)((int)this + 0x18) = lprc->left;
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0xc);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0x14);
  ExceptionList = local_c;
  return;
}

