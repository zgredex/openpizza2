// rea decompile_all
// name: CompanyData_Save
// address: 0x4e1540
// body: available
// range: 0x4e1540-0x4e198d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall CompanyData_Save(void *this,void *param_1)

{
  void *this_00;
  void *pvVar1;
  void *this_01;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_5;
  int local_4;
  
  this_00 = param_1;
  local_5 = 0;
  CRT_Ostream_Write(param_1,(int)this + 8,0x40);
  CRT_Ostream_Write(this_00,(int)this + 0x48,4);
  CRT_Ostream_Write(this_00,(int)this + 0x4c,4);
  CRT_Ostream_Write(this_00,&local_5,1);
  CRT_Ostream_Write(this_00,(int)this + 0x5c,2);
  CRT_Ostream_Write(this_00,(int)this + 0x50,4);
  CRT_Ostream_Write(this_00,(int)this + 0x54,4);
  CRT_Ostream_Write(this_00,(int)this + 0x1dc,4);
  CRT_Ostream_Write(this_00,(int)this + 0x108,8);
  CRT_Ostream_Write(this_00,(int)this + 0x1e4,4);
  CRT_Ostream_Write(this_00,(int)this + 0x1e0,4);
  CRT_Ostream_Write(this_00,(int)this + 100,4);
  CRT_Ostream_Write(this_00,(int)this + 0x68,4);
  CRT_Ostream_Write(this_00,(int)this + 0x6c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x70,0x24);
  CRT_Ostream_Write(this_00,(int)this + 0x94,0x18);
  CRT_Ostream_Write(this_00,(int)this + 0xac,6);
  CRT_Ostream_Write(this_00,(int)this + 0xcc,0x18);
  CRT_Ostream_Write(this_00,(int)this + 0xb4,0x18);
  CRT_Ostream_Write(this_00,(int)this + 0xf0,4);
  CRT_Ostream_Write(this_00,(int)this + 0xf4,4);
  CRT_Ostream_Write(this_00,(int)this + 0xf8,4);
  CRT_Ostream_Write(this_00,(int)this + 0xe4,10);
  CRT_Ostream_Write(this_00,(int)this + 0x60,4);
  CRT_Ostream_Write(this_00,(int)this + 0x58,4);
  CRT_Ostream_Write(this_00,(int)this + 0x1e8,4);
  CRT_Ostream_Write(this_00,(int)this + 0xfc,4);
  CRT_Ostream_Write(this_00,(int)this + 0x100,4);
  pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  local_4 = Array_FindIndexByPtr(pvVar1,*(int *)((int)this + 0x1d8));
  CRT_Ostream_Write(this_00,&local_4,4);
  param_1 = *(void **)((int)this + 0x140);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = this_00;
      this_01 = (void *)IDMap_Lookup((void *)((int)this + 300),iVar3,(int *)0x0);
      GamePlan_SaveRecord(this_01,pvVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  param_1 = *(void **)((int)this + 0x124);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x110),iVar3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Recipe_SaveToStream(pvVar1,this_00,'\x01');
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  iVar3 = 0;
  if (*(int *)((int)this + 0x1d4) == 0) {
    local_4 = 0;
    CRT_Ostream_Write(this_00,&local_4,4);
  }
  else {
    local_4 = 1;
    CRT_Ostream_Write(this_00,&local_4,4);
    Recipe_SaveToStream(*(void **)((int)this + 0x1d4),this_00,'\x01');
  }
  param_1 = *(void **)((int)this + 0x15c);
  CRT_Ostream_Write(this_00,&param_1,4);
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x148),iVar3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Branch_Save(pvVar1,this_00);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  param_1 = *(void **)((int)this + 0x178);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x164),iVar3,(int *)0x0);
      StatsPeriodReport_Save(pvVar1,this_00);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  param_1 = *(void **)((int)this + 0x194);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((int)this + 0x180),iVar3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Storage_SaveRecord(pvVar1,this_00);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  param_1 = *(void **)((int)this + 0x1cc);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      uVar2 = IDMap_Lookup((void *)((int)this + 0x1b8),iVar3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      CRT_Ostream_Write(this_00,uVar2,8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  param_1 = *(void **)((int)this + 0x1b0);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar3 = 0;
  if (0 < (int)param_1) {
    do {
      uVar2 = IDMap_Lookup((void *)((int)this + 0x19c),iVar3,(int *)0x0);
      CRT_Ostream_Write(this_00,uVar2,0x1a0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1);
  }
  return;
}

