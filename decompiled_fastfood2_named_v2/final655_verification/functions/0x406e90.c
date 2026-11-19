// rea decompile_all
// name: Person_UpdateIndoorAction
// address: 0x406e90
// body: available
// range: 0x406e90-0x406f90 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Person_UpdateIndoorAction(void *this,void *param_1)

{
  int iVar1;
  char *pcVar2;
  
                    /* Dispatches an indoor person to its action handler. */
  iVar1 = *(int *)((int)param_1 + 0xf4);
  if ((iVar1 != 0) &&
     (pcVar2 = (char *)FUN_00489820(this,*(int *)(iVar1 + 8),*(int *)(iVar1 + 0x2c)),
     pcVar2 != (char *)0x0)) {
    switch(*(undefined4 *)((int)param_1 + 0x30)) {
    case 10:
    case 0x12:
    case 0x18:
      Object_UpdateCompanyBuilding(this,pcVar2,param_1);
      return;
    default:
      Object_UpdateFallback(this,pcVar2,param_1);
      break;
    case 0xd:
    case 0x17:
    case 0x1d:
    case 0x1e:
      Object_UpdateBranchOps(this,pcVar2,param_1);
      return;
    case 0xe:
      Customer_UpdateMovement(this,pcVar2,param_1);
      return;
    case 0x11:
      Object_UpdateProductionWorker(this,pcVar2,param_1);
      return;
    case 0x13:
      Object_UpdateCustomerQueue(this,pcVar2,param_1);
      return;
    case 0x14:
      Object_UpdateConstructionWorker(this,pcVar2,param_1);
      return;
    case 0x16:
      Object_UpdateSupplyBuilding(this,(int)pcVar2,param_1);
      return;
    case 0x1a:
    case 0x1b:
      Person_EnterBuildingAndWork((int)pcVar2,param_1);
      return;
    case 0x1c:
      Person_SitAndEatPizza(pcVar2,param_1);
      return;
    case 0x1f:
      Object_UpdateBranchOpenClose(this,pcVar2,param_1);
      return;
    case 0x20:
      Object_UpdateCitizen(pcVar2,param_1);
      return;
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2f:
      Game_UpdateVisitorObjectState(this,pcVar2,param_1);
      return;
    }
  }
  return;
}

