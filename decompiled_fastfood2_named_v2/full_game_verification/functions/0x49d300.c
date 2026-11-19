// rea decompile_all
// name: ContestRecipePage_FillIngredientDetails
// address: 0x49d300
// body: available
// range: 0x49d300-0x49d484 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ContestRecipePage_FillIngredientDetails(void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 local_40 [64];
  
                    /* Fills the contest recipe ingredient detail pane. */
  iVar3 = 0;
  iVar4 = 1;
  iVar1 = DAT_00568af4;
  if (((DAT_00568af4 < 0) && (iVar1 = param_2, param_2 < 0)) ||
     (iVar3 = IDMap_Lookup(DAT_0057cac8,iVar1,(int *)0x0), iVar3 == 0)) {
    iVar4 = 0;
  }
  UI_SetChildVisibleByID(param_1,0x4fa,iVar4);
  UI_SetChildVisibleByID(param_1,0x4f9,iVar4);
  UI_SetChildVisibleByID(param_1,0x4e9,iVar4);
  UI_SetChildVisibleByID(param_1,0x4ea,iVar4);
  UI_SetChildVisibleByID(param_1,0x449,iVar4);
  UI_SetChildVisibleByID(param_1,0x44c,iVar4);
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar3 + 0xac + _DAT_0057cacc * 4);
  Window_GadgetNotify_Text_SetText(param_1,0x4fa,iVar3 + 0x88);
  String_Format(local_40,(byte *)s__0_2f___005688b0,
                SUB84(*(double *)(iVar3 + 0xc0) * (double)iVar1 * 0.001,0));
  Window_GadgetNotify_Text_SetText(param_1,0x4e9,local_40);
  lVar5 = __ftol();
  String_Format(local_40,&DAT_00568930,(int)lVar5);
  Window_GadgetNotify_Text_SetText(param_1,0x4ea,local_40);
  switch(_DAT_0057cacc) {
  case 0:
    uVar2 = DAT_00582094;
    goto LAB_0049d45a;
  case 1:
    uVar2 = DAT_0058175c;
    break;
  case 2:
    uVar2 = DAT_00582004;
    break;
  case 3:
    uVar2 = DAT_00582568;
LAB_0049d45a:
    break;
  default:
    goto switchD_0049d421_default;
  }
  String_Format(local_40,&DAT_005630d0,uVar2);
switchD_0049d421_default:
  Window_GadgetNotify_Text_SetText(param_1,0x4f9,local_40);
  return;
}

