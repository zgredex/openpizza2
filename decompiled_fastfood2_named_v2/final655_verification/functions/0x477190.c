// rea decompile_all
// name: Branch_SpawnWalkInCustomer
// address: 0x477190
// body: available
// range: 0x477190-0x477357 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Branch_SpawnWalkInCustomer(void *param_1)

{
  short sVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  void *this;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined1 unaff_BP;
  undefined4 unaff_ESI;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Spawns a random walk-in customer during branch opening hours. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f0b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_0047e470(param_1,0);
  if (CONCAT31(extraout_var,uVar2) != 0) {
    iVar3 = FUN_00489750(DAT_0057c670,0xb,4,3,&local_24);
    iVar4 = FUN_004f50d0(1,0,0,unaff_ESI,unaff_BP);
    if (iVar4 != 0) {
      this = operator_new(0x24);
      local_4 = 0;
      local_20 = this;
      if (this == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        uVar5 = FUN_004034d0(0,7);
        iVar6 = ConstructionOrder_Construct(this,local_24,uVar5);
      }
      local_4 = 0xffffffff;
      FUN_004f4e90(*(void **)((int)param_1 + 0x14e0),*(int *)(iVar4 + 0xc),*(int *)(iVar4 + 0x10),
                   &local_30,&local_34,(int *)0x1);
      *(undefined4 *)((int)param_1 + 0x1718) = 0;
      FUN_004014b0((void *)((int)param_1 + 0x19e0),iVar6);
      *(int *)(iVar6 + 0x18) = local_30;
      *(int *)(iVar6 + 0x1c) = local_34;
      *(int *)(iVar6 + 0x20) =
           *(int *)(*(int *)((int)param_1 + 0x14e0) + 0x1c) * local_34 + local_30;
      piVar7 = (int *)FUN_004ef4b0(*(void **)((int)param_1 + 0x14e0),local_30,local_34);
      sVar1 = *(short *)(iVar3 + (*(int *)(iVar6 + 8) + 10) * 0xc);
      FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
      FUN_004ed330(*(void **)((int)param_1 + 0x14e0),(int)piVar7,(int)sVar1,1);
      FUN_004f34c0(*(void **)((int)param_1 + 0x14e0),piVar7,&local_2c,&local_28);
      local_2c = local_2c - *(int *)(*(int *)((int)param_1 + 0x14e0) + 0x24);
      local_28 = local_28 - *(int *)(*(int *)((int)param_1 + 0x14e0) + 0x28);
      local_1c = local_2c - 0x10;
      local_18 = local_28 + -8;
      local_10 = local_28 + 8;
      local_14 = local_2c + 0x10;
      FUN_00534e20(DAT_0058072c,&local_1c);
      FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
    }
  }
  ExceptionList = local_c;
  return;
}

