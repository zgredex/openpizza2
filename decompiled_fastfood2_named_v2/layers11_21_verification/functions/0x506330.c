// rea decompile_all
// name: Object_InitCompanyBuildingGraphics
// address: 0x506330
// body: available
// range: 0x506330-0x506b95 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_InitCompanyBuildingGraphics(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Initializes the eight per-company building graphics for an object. */
  if (param_1 == -1) {
    param_1 = *(int *)((int)this + 0x30);
  }
  switch(param_1) {
  case 0:
    Object_SetCompanyStylePalette(0,1,6,2,5,7,4,0x12);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x14,10,0x19,10,0x14,10,0,5);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,5,0,0x1e,10,0x14,10,0x14,5);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x3c,0,10,0,0,0x14,10,0);
    uVar3 = 0;
    *(int *)((int)this + 0xec) = iVar1;
    uVar2 = 100;
    break;
  case 1:
    Object_SetCompanyStylePalette(0,1,2,4,8,6,7,0xd);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,10,0x28,0x14,0,0,0x14,5,5);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0x1e,10,5,0x28,5,0);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0,0,0x1e,0x2d,0x14,5,0);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x14,0,0,0x1e,0x1e,10,10,0);
    *(int *)((int)this + 0xf0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x5a,0,0,5,5,0,0,0);
    *(int *)((int)this + 0xd4) = iVar1;
    return;
  case 2:
    Object_SetCompanyStylePalette(0,9,2,8,4,10,0xb,6);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x32,0x28,0,0,0,10,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x50,10,0,0,10,0,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x28,0x14,10,0,5,5,0x14);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x1e,10,5,0x14,5,10,0x14);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0,0x1e,0x1e,0,10,0x14);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,5,0,0x32,0x1e,0,0,0xf);
    uVar3 = 10;
    *(int *)((int)this + 0xf0) = iVar1;
    uVar2 = 0x28;
    goto LAB_0050691d;
  case 3:
  case 0x15:
    Object_SetCompanyStylePalette(0,0xc,2,4,8,6,7,0x12);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x1e,0,0x1e,0,0x14,10,0,10);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x14,0,0,0x14,0x1e,0x14,10,0);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x28,0,0,0x14,0x1e,0,10,0);
    *(int *)((int)this + 0xf0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x5a,0,0,0,5,0,5,0);
    *(int *)((int)this + 0xd4) = iVar1;
    return;
  case 4:
    Object_SetCompanyStylePalette(0,10,2,4,8,6,0xd,0x21);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,100,0,0,0,0,0,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x28,0x14,0,10,0x14,10,0);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x46,0x14,0,0,0,10,0);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0,0x14,0x14,0x14,0,0x1e);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x14,0,0,10,0x28,0,0,0x1e);
    *(int *)((int)this + 0xf0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x3c,0,0,10,0x1e,0,0,0);
    *(int *)((int)this + 0xd4) = iVar1;
    return;
  case 5:
    Object_SetCompanyStylePalette(0,10,2,4,8,0xd,0xc,0x21);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x3c,0x14,0,0,0,0,0x14,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0x28,0,0,0x28,10,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0x28,0,0x14,0x14,10,0);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0x32,0,0x1e,0,10,0);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0,0,10,0x14,0,0,0x46);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0,0,10,0x28,0,0,0x32);
    uVar3 = 0x32;
    *(int *)((int)this + 0xf0) = iVar1;
    uVar2 = 0;
LAB_0050691d:
    iVar1 = Object_PickWeightedBuildingRecord(this,0x32,0,0,uVar2,uVar3,0,0,0);
    *(int *)((int)this + 0xd4) = iVar1;
    return;
  case 6:
    Object_SetCompanyStylePalette(0,0xd,0x12,2,4,0xb,6,8);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x14,0x28,0x14,0,0,0x14,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,10,0,0x1e,0x14,0,0x14,0x14,0);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,10,0x14,0x14,0x14,10,0x14,0);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x14,0,0x14,0,0x14,10,10,0x14);
    uVar3 = 0x14;
    *(int *)((int)this + 0xec) = iVar1;
    uVar2 = 0x50;
    break;
  case 7:
    Object_SetCompanyStylePalette(0xe,0xb,2,0x12,0x21,0xd,6,8);
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xd8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
    *(int *)((int)this + 0xdc) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x14,0x1e,0x14,0,10,0x14,0);
    *(int *)((int)this + 0xe0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x19,0x14,0xf,0,10,0x14,10);
    *(int *)((int)this + 0xe4) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0x19,0x14,0xf,0,0,0x14,0x14);
    *(int *)((int)this + 0xe8) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0xf,0,0x14,0x14,0,0x19,0x14);
    *(int *)((int)this + 0xec) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0,0,0,0,0x19,0,0x14,0x37);
    *(int *)((int)this + 0xf0) = iVar1;
    iVar1 = Object_PickWeightedBuildingRecord(this,0x28,0,0,0,0,0,0,0x3c);
    *(int *)((int)this + 0xd4) = iVar1;
    return;
  default:
    Object_SetBuildingRecordForAllCompanies(this,0,0);
    return;
  case 10:
  case 0x10:
  case 0x18:
  case 0x19:
  case 0x20:
    Object_SetBuildingRecordForAllCompanies(this,0x19,0);
    return;
  case 0xb:
    Object_SetBuildingRecordForAllCompanies(this,0xe,0);
    return;
  case 0xc:
    Object_SetBuildingRecordForAllCompanies(this,0x13,0);
    return;
  case 0xd:
    Object_SetBuildingRecordForAllCompanies(this,0x11,0);
    return;
  case 0x16:
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    Object_SetBuildingRecordForAllCompanies(this,0x17,0);
    return;
  }
  iVar1 = Object_PickWeightedBuildingRecord(this,uVar2,0,0,0,0,0,0,uVar3);
  *(int *)((int)this + 0xf0) = iVar1;
  iVar1 = Object_PickWeightedBuildingRecord(this,100,0,0,0,0,0,0,0);
  *(int *)((int)this + 0xd4) = iVar1;
  return;
}

