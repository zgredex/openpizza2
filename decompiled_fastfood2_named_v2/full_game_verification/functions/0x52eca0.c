// rea decompile_all
// name: Dialog_ConstructWithPicture
// address: 0x52eca0
// body: available
// range: 0x52eca0-0x52ee0d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Dialog_ConstructWithPicture
          (void *this,undefined4 param_1,void *param_2,char *param_3,void *param_4,
          undefined4 param_5)

{
  char cVar1;
  void *this_00;
  undefined4 *this_01;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa17;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_10 = this;
  Array_Construct((void *)((int)this + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((int)this + 0x2a8),0);
  local_4._0_1_ = 1;
  *(undefined ***)this = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((int)this + 0x28),0,0,0,0);
  Dialog_InitBase(this,param_2,param_1,param_5);
  this_00 = operator_new(0x11c);
  local_4._0_1_ = 2;
  if (this_00 == (void *)0x0) {
    this_01 = (undefined4 *)0x0;
  }
  else {
    this_01 = FullscreenImage_Load(this_00,param_3,param_2,param_4,&local_14,(undefined *)0x0);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 **)((int)this + 0x138) = this_01;
  if (local_14 == 0) {
    uVar6 = this_01[1];
    iVar4 = this_01[2];
    Sprite_ConvertTo16Bit(this_01,(int)param_2,1,1);
  }
  else {
    DebugConsole_Errorf(param_1,1,(byte *)s_Unable_to_load_requester_backgro_0057441c,param_3);
    uVar6 = 0x140;
    iVar4 = 200;
    if (*(undefined4 **)((int)this + 0x138) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)this + 0x138))(1);
    }
    *(undefined4 *)((int)this + 0x138) = 0;
  }
  UI_SetWindowBounds(this,0,0,uVar6,iVar4);
  uVar6 = 0xffffffff;
  pcVar2 = param_3;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = operator_new(~uVar6);
  uVar6 = 0xffffffff;
  *(char **)((int)this + 0xf8) = pcVar2;
  do {
    pcVar5 = param_3;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar5 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar5;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar5 = pcVar5 + -uVar6;
  for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  ExceptionList = pvStack_c;
  return this;
}

