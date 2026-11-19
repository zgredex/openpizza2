// rea decompile_all
// name: FUN_004b1f40
// address: 0x4b1f40
// body: available
// range: 0x4b1f40-0x4b2228 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b1f40(void *param_1,int param_2,int param_3,int param_4,int param_5)

{
  void *this;
  void *this_00;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  int local_c;
  
  this = param_1;
  this_00 = (void *)IDMap_Lookup((void *)(param_3 + 0x148),param_4,(int *)0x0);
  if (this_00 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_0047aac0(this_00,0xffffffff);
  }
  iVar4 = 6000;
  do {
    FUN_00531740(param_1,iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x178c);
  iVar4 = 51000;
  do {
    iVar1 = FUN_0052ff20(param_1,iVar4 + -1000);
    if (iVar1 != 0) {
      FUN_005311a0(param_1,iVar4 + -1000);
    }
    iVar1 = FUN_0052ff20(param_1,iVar4);
    if (iVar1 != 0) {
      FUN_005311a0(param_1,iVar4);
    }
    iVar1 = iVar4 + -50999;
    iVar4 = iVar4 + 1;
  } while (iVar1 < 7);
  if (local_14 < 8) {
    param_2 = 0;
  }
  else {
    local_14 = 7;
  }
  if (0 < local_14) {
    local_c = 0;
    param_1 = (void *)0x1770;
    iVar4 = 50000;
    do {
      iVar1 = param_2 + -50000 + iVar4;
      if (iVar1 == param_5) {
        FUN_005316b0(this,iVar1 + (0x1794 - param_2));
      }
      else {
        FUN_00531740(this,(0x1794 - param_2) + iVar1);
      }
      piVar2 = (int *)IDMap_Lookup((void *)((int)this_00 + 0x1500),iVar1,(int *)0x0);
      uVar5 = piVar2[1] + 1U & 7;
      FUN_005314a0(this,0x45a,&param_3,&param_4);
      param_4 = param_4 + 1 + local_c;
      param_3 = param_3 + 1 + uVar5 * 0x14;
      switch(*(undefined1 *)(*piVar2 + 0x824)) {
      case 0:
        local_10 = (void *)((int)param_1 + 2);
        local_1c = FUN_00531980(this,0x1792);
        iVar1 = 0x1793;
        break;
      case 1:
        local_10 = param_1;
        local_1c = FUN_00531980(this,0x178c);
        iVar1 = 0x178d;
        break;
      case 2:
        local_10 = (void *)((int)param_1 + 1);
        local_1c = FUN_00531980(this,0x1790);
        iVar1 = 0x1791;
        break;
      case 3:
        local_10 = (void *)((int)param_1 + 3);
        local_1c = FUN_00531980(this,0x178e);
        iVar1 = 0x178f;
        break;
      default:
        goto switchD_004b20b3_default;
      }
      local_18 = FUN_00531980(this,iVar1);
switchD_004b20b3_default:
      FUN_005316b0(this,(int)local_10);
      FUN_0052fd00(this,(int)local_10,0,7,0);
      FUN_0052fd70(this,(int)local_10,uVar5,0);
      if (uVar5 == 0) {
        iVar1 = param_3 + 0x8c;
      }
      else {
        iVar1 = param_3 + -0x14;
      }
      FUN_005317b0(this,iVar4,iVar1,param_4,local_1c,0);
      iVar1 = iVar4 + 1000;
      if (uVar5 < 7) {
        iVar3 = param_3 + 0x14;
      }
      else {
        iVar3 = param_3 + -0x8c;
      }
      FUN_005317b0(this,iVar1,iVar3,param_4,local_18,0);
      iVar3 = Get_FieldF0((int)this);
      FUN_00531d10(this,iVar4,iVar3 + -1);
      iVar3 = Get_FieldF0((int)this);
      FUN_00531d10(this,iVar1,iVar3 + -1);
      FUN_00531470(this,iVar4,0);
      FUN_00531470(this,iVar1,0);
      local_c = local_c + 10;
      param_1 = (void *)((int)param_1 + 4);
      iVar1 = iVar4 + -49999;
      iVar4 = iVar4 + 1;
    } while (iVar1 < local_14);
  }
  return;
}

