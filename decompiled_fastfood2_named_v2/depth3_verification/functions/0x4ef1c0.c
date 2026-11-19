// rea decompile_all
// name: FUN_004ef1c0
// address: 0x4ef1c0
// body: available
// range: 0x4ef1c0-0x4ef4a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ef1c0(void *this,int param_1)

{
  int *piVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x13c)) {
    iVar4 = 0;
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar4 + 0x20 + *(int *)((int)this + 0x138)) = 0;
      iVar4 = iVar4 + 0x3c;
    } while (iVar2 < *(int *)((int)this + 0x13c));
  }
  for (piVar1 = *(int **)((int)this + 0xbc); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x1c]) {
    FUN_00534370((void *)piVar1[0x16],*piVar1,&local_34,&local_40);
    if (param_1 == 0) {
      FUN_00534060((void *)piVar1[0x16],*piVar1,&local_3c,&local_38,&local_48,&local_44);
      FUN_005340d0((void *)piVar1[0x16],*piVar1,(int *)&local_48,(int *)&local_44);
      local_20 = local_48 + local_34;
      local_18 = local_3c + local_20;
      local_1c = local_44 + local_40;
      local_14 = local_1c + local_38;
      if ((piVar1[0x1d] == 0) &&
         (this_00 = *(void **)(*(int *)((int)this + 4) + 0x2c180 + *(int *)(piVar1[0x1e] + 0xc) * 4)
         , this_00 != (void *)0x0)) {
        iVar2 = FUN_00534960((void *)piVar1[0x16],*piVar1);
        FUN_00534990(this_00,*(int *)(piVar1[0x1e] + 0x10),iVar2);
        FUN_00534060(this_00,*(int *)(piVar1[0x1e] + 0x10),&local_3c,&local_38,&local_48,&local_44);
        FUN_005340d0(this_00,*(int *)(piVar1[0x1e] + 0x10),(int *)&local_48,(int *)&local_44);
        iVar2 = local_48 + local_34;
        iVar4 = local_44 + local_40;
        local_8 = local_3c + iVar2;
        local_4 = local_38 + iVar4;
        if (iVar2 < local_20) {
          local_20 = iVar2;
        }
        if (local_18 < local_8) {
          local_18 = local_8;
        }
        if (iVar4 < local_1c) {
          local_1c = iVar4;
        }
        if (local_14 < local_4) {
          local_14 = local_4;
        }
      }
      iVar2 = local_20;
      if (((short)piVar1[2] != -1) && ((*(byte *)(piVar1 + 4) & 1) == 0)) {
        local_30 = local_34 - *(int *)((int)this + 0x24);
        local_2c = local_40 - *(int *)((int)this + 0x28);
        FUN_00534790((void *)piVar1[0x16],*piVar1,&local_30,&local_2c);
        FUN_00533540(*(void **)(*(int *)((int)this + 4) + 0x2c3b4),&local_24,&local_28);
        iVar3 = (local_30 - ((int)local_24 >> 2)) + *(int *)((int)this + 0x24);
        iVar4 = (local_2c - local_28) + -3 + *(int *)((int)this + 0x28);
        if (iVar3 < iVar2) {
          iVar2 = iVar3;
        }
        if (local_18 < (int)(local_24 + iVar3)) {
          local_18 = local_24 + iVar3;
        }
        if (iVar4 < local_1c) {
          local_1c = iVar4;
        }
        if (local_14 < (int)(local_28 + iVar4)) {
          local_14 = local_28 + iVar4;
        }
      }
      piVar1[0x17] = iVar2;
      piVar1[0x18] = local_1c;
      piVar1[0x19] = local_18;
      piVar1[0x1a] = local_14;
    }
    if (local_34 != -1) {
      if (piVar1[0x16] == *(int *)(*(int *)((int)this + 4) + 0x2c3bc)) {
        local_40 = *(int *)(piVar1[0x1d] + 0x98);
      }
      if (piVar1[1] == -1) {
        iVar2 = local_40 + 0xd0;
        iVar4 = local_34 + 0xa0;
      }
      else {
        iVar2 = *(int *)((int)this + 0xfc) + local_40;
        iVar4 = *(int *)((int)this + 0xf8) + local_34;
      }
      iVar2 = FUN_004ed5a0(this,iVar4,iVar2,(int *)0x1,0);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {
        Object_InsertSortedByScreenY(this,iVar2,piVar1);
      }
    }
  }
  return;
}

