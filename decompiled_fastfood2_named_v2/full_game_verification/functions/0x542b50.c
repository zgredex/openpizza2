// rea decompile_all
// name: Sound_CreatePrimaryBuffer
// address: 0x542b50
// body: available
// range: 0x542b50-0x542e25 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl Sound_CreatePrimaryBuffer(undefined4 param_1,HWND param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_EBP;
  undefined1 uStack00000000;
  int local_8c;
  undefined4 *local_88;
  undefined4 *puStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b0c1;
  local_c = ExceptionList;
  local_8c = 0;
  ExceptionList = &local_c;
  *param_3 = 0;
  puVar1 = operator_new(0xb8);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    ExceptionList = local_c;
    return -0x7ff8fff2;
  }
  *puVar1 = &PTR_LAB_0055ca08;
  local_88 = puVar1;
  SoundDevice_Construct(puVar1 + 1,param_1,param_2,3,&local_8c);
  local_4._0_1_ = 1;
  puVar1[6] = 0;
  puVar1[5] = &PTR_DirectSoundBuffer_Delete_0055c860;
  if (&uStack00000000 != (undefined1 *)0x8c) {
    if (local_8c < 0) goto LAB_00542cb2;
    local_8c = 0;
  }
  local_7c = 1;
  local_74 = 0;
  local_80 = 0x14;
  local_78 = 0;
  local_70 = 0;
  iVar2 = (**(code **)(*(int *)puVar1[3] + 0xc))((int *)puVar1[3],&local_80,puVar1 + 6,0);
  if (-1 < iVar2) goto LAB_00542cb2;
  Sound_SetLastError(&DAT_00585578,s_creating_primary_buffer__00574f34,iVar2,unaff_EBP);
  if (iVar2 < -0x7ffbfeef) {
    if (iVar2 == -0x7ffbfef0) {
      iVar2 = -0x7ffbfef0;
    }
    else if (iVar2 == -0x7fffbfff) {
      iVar2 = -0x7fffbfff;
    }
    else if (iVar2 == -0x7fffbffe) {
      iVar2 = -0x7fffbffe;
    }
    else {
      if (iVar2 != -0x7fffbffb) goto LAB_00542c93;
      iVar2 = -0x7fffbffb;
    }
  }
  else if (iVar2 == -0x7ff8fff2) {
    iVar2 = -0x7ff8fff2;
  }
  else if (iVar2 == -0x7ff8ffa9) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
LAB_00542c93:
    iVar2 = -0x7fff0001;
  }
  if (&uStack00000000 != (undefined1 *)0x8c) {
    local_8c = iVar2;
  }
LAB_00542cb2:
  local_4._0_1_ = 2;
  SoundVoiceThread_Construct(puVar1 + 7,&local_8c);
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x20] = 0;
  puVar1[0x23] = 100;
  puVar1[0x21] = 10000;
  puVar1[0x22] = 10000;
  puVar1[0x24] = 100000;
  puVar1[0x25] = 0;
  puVar1[0x26] = 0x80004002;
  puVar1[0x27] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x28));
  puVar1[1] = &PTR_LAB_0055c9f8;
  puVar1[7] = &PTR_LAB_0055c9f4;
  local_4._0_1_ = 7;
  *puVar1 = &PTR_LAB_0055c8f8;
  puVar1[5] = &PTR_LAB_0055c8f4;
  if ((&uStack00000000 != (undefined1 *)0x8c) && (-1 < local_8c)) {
    puVar1[0x26] = local_8c;
    puStack_84 = operator_new(0x62c);
    local_4._0_1_ = 8;
    if (puStack_84 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = SoundBuffer_ConstructBase(puStack_84);
    }
    local_4 = CONCAT31(local_4._1_3_,7);
    puVar1[0x27] = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      puVar1[0x26] = 0x8007000e;
    }
    else {
      uStack_6c = 0x60;
      iVar2 = (**(code **)(*(int *)puVar1[3] + 0x10))();
      if (-1 < iVar2) {
        puVar1[0x23] = uStack_64;
        puVar1[0x24] = uStack_60;
      }
    }
  }
  *param_3 = puVar1;
  ExceptionList = local_c;
  return local_8c;
}

