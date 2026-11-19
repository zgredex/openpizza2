// rea decompile_all
// name: Dialog_ConstructWithSprite
// address: 0x52eb70
// body: available
// range: 0x52eb70-0x52ec9f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Dialog_ConstructWithSprite
          (void *this,void *param_1,void *param_2,char *param_3,undefined4 param_4,int param_5,
          int param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int local_18;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a9dc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = this;
  Array_Construct((void *)((int)this + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((int)this + 0x2a8),0);
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined ***)this = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((int)this + 0x28),param_5,param_6,0,0);
  Dialog_InitBase(this,param_2,param_1,param_7);
  iVar2 = Window_LoadSpriteCached
                    (param_1,param_3,(undefined4 *)0x1,(undefined4 *)((int)this + 0x54));
  if (iVar2 == 0) {
    local_14 = 0x140;
    local_18 = 200;
    *(undefined4 *)((int)this + 0x94) = 0;
    *(undefined1 *)((int)this + 0x54) = 0;
  }
  else {
    Sprite_GetSize(*(void **)((int)this + 0x94),(int *)&local_14,&local_18);
  }
  UI_SetWindowBounds(this,param_5,param_6,local_14,local_18);
  uVar4 = 0xffffffff;
  pcVar3 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = operator_new(~uVar4);
  uVar4 = 0xffffffff;
  *(char **)((int)this + 0xf8) = pcVar3;
  do {
    pcVar6 = param_3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar3 = pcVar3 + 1;
  }
  ExceptionList = local_c;
  return this;
}

