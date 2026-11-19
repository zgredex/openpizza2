// rea decompile_all
// name: FUN_00552d0f
// address: 0x552d0f
// body: available
// range: 0x552d0f-0x552ec1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x552ebd to 0x5534dc FUN_005534dc (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_00552d0f(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_0055353d();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_00552398();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_00552398();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_00552398();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_00555f86(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_0055353d();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_00552e97;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_0055353d();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)CRT_FindTryBlockRange(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_00553401((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_00552f6c(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_0055307d(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                goto LAB_00552e74;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
LAB_00552e74:
          iVar5 = local_14;
        }
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_00552e97:
  if (param_6 == '\0') {
    FUN_00552ec2(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_005534dc();
  return;
}

