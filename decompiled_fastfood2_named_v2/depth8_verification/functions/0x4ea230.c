// rea decompile_all
// name: FUN_004ea230
// address: 0x4ea230
// body: available
// range: 0x4ea230-0x4ea3f4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_004ea230(void *this,void *param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uVar6 = param_3;
  uVar5 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00559e86;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(void **)((int)this + 0x2f884) != (void *)0x0) &&
     ((ExceptionList = &pvStack_c,
      FUN_0053d090(*(void **)((int)this + 0x2f884),(int *)&param_3,(int *)&param_2),
      param_3 != uVar5 || (param_2 != uVar6)))) {
    if (*(undefined4 **)((int)this + 0x2f884) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)this + 0x2f884))(1);
    }
    *(undefined4 *)((int)this + 0x2f884) = 0;
  }
  if ((DAT_0058072c != (undefined4 *)0x0) &&
     ((FUN_00535160(DAT_0058072c,&param_3,&param_2), param_3 != uVar5 || (param_2 != uVar6)))) {
    if (DAT_0058072c != (undefined4 *)0x0) {
      (**(code **)*DAT_0058072c)(1);
    }
    DAT_0058072c = (undefined4 *)0x0;
  }
  if ((uVar5 & 1) != 0) {
    uVar5 = uVar5 + 1;
  }
  if (DAT_0058072c == (undefined4 *)0x0) {
    pvVar1 = operator_new(0x18);
    uStack_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_0058072c = (undefined4 *)0x0;
    }
    else {
      DAT_0058072c = FUN_00534d60(pvVar1,uVar5,uVar6,0xf);
    }
    uStack_4 = 0xffffffff;
  }
  if (*(int *)((int)this + 0x2f884) == 0) {
    pvVar1 = operator_new(0x50);
    uStack_4 = 1;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_0053c710(pvVar1,uVar5 * 3,uVar6,0,8,0);
    }
    uStack_4 = 0xffffffff;
    *(undefined4 **)((int)this + 0x2f884) = puVar2;
  }
  if (*(int *)((int)this + 0x2f87c) == 0) {
    puVar2 = Renderer_CreateChild(param_1);
    *(undefined4 **)((int)this + 0x2f87c) = puVar2;
  }
  iVar4 = uVar5 * 6;
  uVar3 = FUN_0053d480(*(void **)((int)this + 0x2f884));
  FUN_00539280(*(void **)((int)this + 0x2f87c),uVar3,(ushort)uVar5,(ushort)uVar6,iVar4);
  if (param_4 == 0) {
    *(undefined4 *)((int)this + 0x2f888) = param_5;
    *(undefined4 *)((int)this + 0x2f88c) = param_6;
    ExceptionList = pvStack_c;
    return;
  }
  *(int *)((int)this + 0x2f880) = param_4;
  *(undefined4 *)((int)this + 0x2f88c) = param_6;
  *(undefined4 *)((int)this + 0x2f888) = param_5;
  ExceptionList = pvStack_c;
  return;
}

