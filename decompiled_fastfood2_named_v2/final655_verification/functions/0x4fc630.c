// rea decompile_all
// name: City_TickBranches
// address: 0x4fc630
// body: available
// range: 0x4fc630-0x4fc71c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall City_TickBranches(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int unaff_EDI;
  void *local_4;
  
                    /* Runs the city's branch action tick. */
  iVar1 = *(int *)(*(int *)((int)this + param_1 * 0x168 + 0x70) + 0x15c);
  local_4 = this;
  City_EnsurePedestrianCoverage(this,param_1);
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      pvVar3 = (void *)FUN_00500e80(this,param_1,iVar5,1);
      if (((pvVar3 != (void *)0x0) && (*(void **)((int)pvVar3 + 0x16f0) != (void *)0x0)) &&
         (iVar4 = FUN_004d2ae0(*(void **)((int)pvVar3 + 0x16f0),0x1e), iVar4 == 0)) {
        FUN_0047f2e0(pvVar3,1,0x22,(float *)&local_4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      pvVar3 = (void *)FUN_00500e80(this,param_1,iVar5,1);
      if ((pvVar3 != (void *)0x0) && (*(int *)((int)pvVar3 + 0x2c) == 0)) {
        uVar2 = *(uint *)((int)pvVar3 + 0x28);
        if ((uVar2 & 2) != 0) {
          Branch_ValidateMenuAndRecalculate(this,pvVar3);
          break;
        }
        if ((uVar2 & 0x10) != 0) {
          FUN_004fc0f0(this,param_1,pvVar3);
          break;
        }
        if ((uVar2 & 0x20) != 0) {
          FUN_004ff6e0(pvVar3);
          break;
        }
        if ((uVar2 & 4) != 0) {
          Customer_VisitBranch
                    (param_1,(int)pvVar3,(void *)0xffffffff,-1,-1,(undefined4 *)0xffffffff,unaff_EDI
                     ,unaff_ESI);
          break;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  FUN_004fc5f0(this,param_1);
  return 1;
}

