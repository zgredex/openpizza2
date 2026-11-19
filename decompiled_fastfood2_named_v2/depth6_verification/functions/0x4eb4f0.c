// rea decompile_all
// name: FUN_004eb4f0
// address: 0x4eb4f0
// body: available
// range: 0x4eb4f0-0x4eb8d6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004eb4f0(void *this,int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  int *this_00;
  int *this_01;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int local_440;
  uint local_43c;
  int *local_438;
  int iStack_434;
  char *local_430 [4];
  undefined *local_420;
  undefined *local_41c;
  undefined *local_418;
  undefined *local_414;
  undefined1 local_410 [260];
  char acStack_30c [256];
  undefined1 local_20c [256];
  undefined1 local_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559fba;
  pvStack_c = ExceptionList;
  local_430[0] = s_KLEIN_00567cd4;
  local_430[1] = s_MITTEL_00567ccc;
  local_430[2] = s_GROSS_00567cc4;
  local_430[3] = &DAT_00567cbc;
  local_420 = &DAT_00567cb4;
  local_41c = &DAT_00567cac;
  local_418 = &DAT_00567ca4;
  local_414 = &DAT_00567ca0;
  bVar2 = false;
  ExceptionList = &pvStack_c;
  FUN_0054dd83(local_20c,(byte *)s_Iso_Filiale_ROH__s_sty_00571adc,local_430[param_1]);
  FUN_0054dd83(local_10c,(byte *)s_Iso_Filiale__s__s_sty_00571ac4,local_430[param_2 + 3]);
  FUN_00401320(*(int *)(DAT_0057c670 + 0x240));
  if ((param_2 == 0) && (param_1 == 1)) {
    FUN_0054dd83(local_410,(byte *)s__sIsokarten__s_00571a60,&DAT_0057c278);
    local_438 = operator_new(0x5c);
    local_4 = param_2;
    if (local_438 == (int *)0x0) {
      this_00 = (int *)0x0;
    }
    else {
      this_00 = FUN_0054cc99();
    }
    local_4 = 0xffffffff;
    if ((*(byte *)(*(int *)(*this_00 + 4) + 8 + (int)this_00) & 6) != 0) {
      FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
      FUN_0048e0a0();
    }
    bVar2 = true;
  }
  else {
    this_00 = local_438;
  }
  FUN_0054dd83(local_410,(byte *)s__sIsokarten__s_00571a60,&DAT_0057c278);
  local_438 = operator_new(0x5c);
  local_4 = 1;
  if (local_438 == (void *)0x0) {
    this_01 = (int *)0x0;
  }
  else {
    this_01 = FUN_0054cc99();
  }
  local_4 = 0xffffffff;
  if ((*(byte *)(*(int *)(*this_01 + 4) + 8 + (int)this_01) & 6) != 0) {
    FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
    FUN_0048e0a0();
  }
  if (bVar2) {
    FUN_0054cbc1(this_00,(int)this + 0x7c,0x1e);
  }
  FUN_0054cbc1(this_01,(int)this + 0x7c,0x1e);
  do {
    FUN_0054cbc1(this_01,&local_440,4);
    if (bVar2) {
      FUN_0054cbc1(this_00,&local_440,4);
    }
    if (local_440 == -1) break;
    if (bVar2) {
      FUN_0054cbc1(this_00,&local_43c,4);
    }
    FUN_0054cbc1(this_01,&local_43c,4);
    if (*(int *)(*(int *)((int)this + 0x4c) + 8 + local_440 * 0xc) != 0) {
      local_43c = FUN_004eaa10(*(void **)((int)this + 4),local_43c);
      *(uint *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_440 * 0xc) + 0x10) = local_43c;
    }
  } while (local_440 != -1);
  if (this_01 != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*this_01 + 4) + (int)this_01))(1);
  }
  if ((bVar2) && (this_00 != (int *)0x0)) {
    (*(code *)**(undefined4 **)(*(int *)(*this_00 + 4) + (int)this_00))(1);
  }
  uVar5 = 0xffffffff;
  pcVar3 = (char *)((int)this + 0x7c);
  do {
    pcVar9 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar3 = pcVar9 + -uVar5;
  pcVar9 = acStack_30c;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  pcVar3 = _strrchr(acStack_30c,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
  }
  uVar5 = 0xffffffff;
  pcVar3 = &DAT_005719f8;
  do {
    pcVar9 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar3 = acStack_30c;
  do {
    pcVar8 = pcVar3;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  pcVar3 = pcVar9 + -uVar5;
  pcVar9 = pcVar8 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  if (*(undefined4 **)((int)this + 0x74) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x74))(1);
  }
  local_438 = operator_new(0x50);
  local_4 = 2;
  if (local_438 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = FUN_0053c7f0(local_438,DAT_0057c5c8,*(void **)(*(int *)((int)this + 4) + 0x2bf44),
                          acStack_30c,&iStack_434,0,(void *)0x0,0);
  }
  *(undefined4 **)((int)this + 0x74) = puVar4;
  local_4 = 0xffffffff;
  if (iStack_434 != 0) {
    FUN_0048e0a0();
  }
  *(undefined4 *)((int)this + 0xf4) = 1;
  FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
  ExceptionList = pvStack_c;
  return;
}

