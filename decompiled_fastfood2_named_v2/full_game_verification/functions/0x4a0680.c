// rea decompile_all
// name: GammaOptions_Init
// address: 0x4a0680
// body: available
// range: 0x4a0680-0x4a083f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x004a07e3) */

void __cdecl GammaOptions_Init(void *param_1)

{
  int *piVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 uVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587f6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar1 = Resource_Open(DAT_0057c5d8,s_gamma_bin_00568c7c,0);
  if (piVar1 != (int *)0x0) {
    pvVar2 = operator_new(0x50);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      DAT_0057cda4 = (undefined4 *)0x0;
    }
    else {
      DAT_0057cda4 = Sprite_CreateRaw(pvVar2,0x1fe,0xaa,0,8,0);
    }
    local_4 = 0xffffffff;
    pvVar2 = operator_new(0x50);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      DAT_0057cda8 = (undefined4 *)0x0;
    }
    else {
      DAT_0057cda8 = Sprite_CreateRaw(pvVar2,0x1fe,0xaa,0,8,0);
    }
    local_4 = 0xffffffff;
    pcVar3 = (char *)Sprite_GetPixelBuffer(DAT_0057cda8);
    Resource_Read(DAT_0057c5d8,pcVar3,0x152ac,(int)piVar1);
    Resource_Close(DAT_0057c5d8,(int)piVar1);
    if (*(char *)(DAT_0057c5c8 + 0x18) == '\0') {
      iVar4 = 0;
      do {
        iVar5 = iVar4 + 3;
        *(ushort *)(pcVar3 + iVar4) =
             *(ushort *)(pcVar3 + iVar4) >> 1 & 0x7fe0 | *(ushort *)(pcVar3 + iVar4) & 0x1f;
        iVar4 = iVar5;
      } while (iVar5 < 0x152ac);
    }
  }
  Window_GadgetNotify_Slider_SetRange(param_1,0x1f53,0,0x32,0);
  Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x1f53,1);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x1f53,(int)lVar7,uVar8);
  uVar6 = (uint)*(byte *)(DAT_0057c5cc + 0x2bf48);
  if (3 < *(byte *)(DAT_0057c5cc + 0x2bf48)) {
    uVar6 = 3;
  }
  Window_GadgetNotify_Slider_SetRange(param_1,0x1f5e,0,3,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x1f5e,uVar6,0);
  Window_GadgetNotify_Text_SetText(param_1,0x1f60,(&DAT_00583878)[uVar6]);
  GammaOptions_DrawPreview(param_1);
  ExceptionList = local_c;
  return;
}

