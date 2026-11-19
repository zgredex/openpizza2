// rea decompile_all
// name: FUN_004d9780
// address: 0x4d9780
// body: available
// range: 0x4d9780-0x4d9a0b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d9780(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 unaff_EDI;
  undefined4 *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005591f6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = FUN_004d8140(-1);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0x3c - *(int *)(param_1 + 0xcc8 + *(int *)((int)pvVar2 + 0x30) * 4);
    iVar4 = FUN_0047a3b0(pvVar2,-1,1);
    if (((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + 0x32 < iVar4) {
      iVar4 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar2 + 0x30));
      iVar3 = *(int *)((int)DAT_0057c670 + *(int *)(iVar4 + 0x4c) * 4 + 0x224);
      pvVar5 = operator_new(0xc);
      local_4 = 0;
      if (pvVar5 == (void *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6 = Player_Event_StreamConstruct(pvVar5,(void *)0x0);
      }
      local_4 = 0xffffffff;
      puVar6[1] = 1;
      FUN_004014b0((void *)(iVar3 + 0x8c),puVar6);
      iVar1 = *(int *)((int)pvVar2 + 0x30);
      iVar7 = FUN_00482820((int)DAT_0057c670);
      if (iVar1 == iVar7) {
        FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
      }
      *(int *)(param_1 + 0xcf8 + *(int *)(iVar4 + 0x48) * 4) =
           *(int *)(param_1 + 0xcf8 + *(int *)(iVar4 + 0x48) * 4) + 1;
      if (*(int *)(iVar3 + 0x88) != 0) {
        FUN_0054a980((void *)((int)DAT_0057c670 + 0x304),0x11,0,4,1,*(int *)((int)pvVar2 + 0x16f0),
                     DAT_00581128,DAT_005824e8,unaff_EDI);
      }
    }
  }
  pvVar2 = FUN_004d8220();
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0x3c - *(int *)(param_1 + 0xcc8 + *(int *)((int)pvVar2 + 0x30) * 4);
    uVar8 = iVar3 >> 0x1f & 7;
    iVar4 = FUN_00478be0(pvVar2,uVar8,-1);
    if (((int)(iVar3 + uVar8) >> 3) + 0x32 < iVar4) {
      iVar4 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar2 + 0x30));
      iVar3 = *(int *)((int)DAT_0057c670 + *(int *)(iVar4 + 0x4c) * 4 + 0x224);
      pvVar5 = operator_new(0xc);
      local_4 = 1;
      if (pvVar5 == (void *)0x0) {
        local_14 = (undefined4 *)0x0;
      }
      else {
        local_14 = Player_Event_StreamConstruct(pvVar5,(void *)0x0);
      }
      iVar1 = *(int *)((int)pvVar2 + 0x30);
      local_4 = 0xffffffff;
      iVar7 = FUN_00482820((int)DAT_0057c670);
      if (iVar1 == iVar7) {
        FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
      }
      local_14[1] = 2;
      FUN_004014b0((void *)(iVar3 + 0x8c),local_14);
      *(int *)(param_1 + 0xd10 + *(int *)(iVar4 + 0x48) * 4) =
           *(int *)(param_1 + 0xd10 + *(int *)(iVar4 + 0x48) * 4) + 1;
      if (*(int *)(iVar3 + 0x88) != 0) {
        FUN_0054a980((void *)((int)DAT_0057c670 + 0x304),0x12,0,4,1,*(int *)((int)pvVar2 + 0x16f0),
                     DAT_00581128,DAT_005824e8,unaff_EDI);
      }
    }
  }
  ExceptionList = local_c;
  return;
}

