// rea decompile_all
// name: City_AssignPersonToBuilding
// address: 0x4f7dd0
// body: available
// range: 0x4f7dd0-0x4f7e7f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * City_AssignPersonToBuilding(void *param_1,uint param_2)

{
  void *this;
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_78;
  int local_74 [29];
  
                    /* Assigns an idle person to a building. */
  this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Game_BuildTopRatedObjectList((int)param_1,&local_78,param_2);
  iVar3 = 0;
  piVar4 = local_74;
  do {
    if (((piVar4[1] != 0) &&
        (piVar1 = (int *)Game_LookupObjectByIndex(this,*piVar4), piVar1 != (int *)0x0)) &&
       (iVar2 = City_RemovePersonEntry(this,piVar1), iVar2 != 0)) goto LAB_004f7e5b;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 3;
  } while (iVar3 < 10);
  piVar1 = City_SpawnPerson(this,param_2);
  City_RemovePersonEntry(this,piVar1);
LAB_004f7e5b:
  Company_AssignEmployee(param_1,piVar1,param_2,0);
  return piVar1;
}

