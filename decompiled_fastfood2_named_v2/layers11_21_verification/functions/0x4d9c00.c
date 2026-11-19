// rea decompile_all
// name: City_SendPoliceUnits
// address: 0x4d9c00
// body: available
// range: 0x4d9c00-0x4d9dd1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
City_SendPoliceUnits
          (void *this,undefined4 param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *this_00;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int local_24;
  int local_20;
  int local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Spawns a district's police patrol with its weapon mix. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055920b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_18 = this;
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x244));
  local_14 = FUN_004db030(this,&local_24,&local_20,&local_1c);
  iVar5 = 0;
  if (local_14 < 1) {
LAB_004d9d9d:
    FUN_00401340(*(int *)((int)DAT_0057c670 + 0x244));
    FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
    ExceptionList = local_c;
    return;
  }
  do {
    local_10 = operator_new(0x16c);
    this_00 = (char *)0x0;
    local_4 = 0;
    if (local_10 != (void *)0x0) {
      this_00 = (char *)Object_Construct(local_10,0xd,*(int *)((int)this + 0xc1c),0,0,-1);
    }
    uVar3 = 0xffffffff;
    pcVar7 = s_Police_0056ce08;
    do {
      pcVar6 = pcVar7;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar6 + -uVar3;
    pcVar7 = this_00;
    for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
    }
    local_4 = 0xffffffff;
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    *(undefined4 *)(this_00 + 0x100) = param_3;
    *(undefined4 *)(this_00 + 0x58) = param_4;
    FUN_00482790(DAT_0057c670,this_00);
    FUN_0050e730(this_00,param_2,1);
    *(void **)(this_00 + 0xcc) = param_2;
    iVar5 = iVar5 + 1;
    *(int *)(this_00 + 0x98) = iVar5;
    FUN_0050e890(this_00,0x18);
    FUN_0050e850(this_00,param_1);
    if (local_24 < 1) {
      if (local_20 < 1) {
        if (local_1c < 1) {
          FUN_0048e0a0();
        }
        else {
          this_00[0x10c] = '\x03';
          this_00[0x10d] = '\0';
          this_00[0x10e] = '\0';
          this_00[0x10f] = '\0';
          local_1c = local_1c + -1;
        }
      }
      else {
        this_00[0x10c] = '\x02';
        this_00[0x10d] = '\0';
        this_00[0x10e] = '\0';
        this_00[0x10f] = '\0';
        local_20 = local_20 + -1;
      }
    }
    else {
      this_00[0x10c] = '\x01';
      this_00[0x10d] = '\0';
      this_00[0x10e] = '\0';
      this_00[0x10f] = '\0';
      local_24 = local_24 + -1;
    }
    iVar2 = FUN_0050e810((int)this_00);
    FUN_0050b6d0(this_00,iVar2);
    if (local_14 <= iVar5) goto LAB_004d9d9d;
    this = local_18;
  } while( true );
}

