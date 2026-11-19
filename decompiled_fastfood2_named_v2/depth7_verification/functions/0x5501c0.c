// rea decompile_all
// name: FUN_005501c0
// address: 0x5501c0
// body: available
// range: 0x5501c0-0x550398 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_005501c0(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_00586c20 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_00586c20)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = FUN_00553606();
          *pDVar7 = 9;
          pDVar7 = FUN_0055360f();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_00553593(DVar6);
        }
        return -1;
      }
      local_c = (char *)((int)local_c + local_10);
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) != 0) {
        if ((local_10 == 0) || (*param_2 != '\n')) {
          bVar4 = bVar4 & 0xfb;
        }
        else {
          bVar4 = bVar4 | 4;
        }
        *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
        param_3 = param_2;
        local_c = param_2 + (int)local_c;
        pcVar8 = param_2;
        if (param_2 < local_c) {
          do {
            cVar3 = *param_3;
            if (cVar3 == '\x1a') {
              pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
              bVar4 = *pbVar2;
              if ((bVar4 & 0x40) == 0) {
                *pbVar2 = bVar4 | 2;
              }
              break;
            }
            if (cVar3 == '\r') {
              if (param_3 < local_c + -1) {
                if (param_3[1] == '\n') {
                  param_3 = param_3 + 2;
                  goto LAB_0055034b;
                }
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                param_3 = param_3 + 1;
              }
              else {
                param_3 = param_3 + 1;
                BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0
                                );
                if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_00550365:
                  *pcVar8 = '\r';
LAB_00550368:
                  pcVar8 = pcVar8 + 1;
                }
                else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                  if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_0055034b:
                    *pcVar8 = '\n';
                    goto LAB_00550368;
                  }
                  FUN_005503fe(param_1,-1,1);
                  if (local_5 != '\n') goto LAB_00550365;
                }
                else {
                  if (local_5 == '\n') goto LAB_0055034b;
                  *pcVar8 = '\r';
                  pcVar8 = pcVar8 + 1;
                  *(char *)(*piVar1 + 5 + iVar9) = local_5;
                }
              }
            }
            else {
              *pcVar8 = cVar3;
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
          } while (param_3 < local_c);
        }
        local_c = (char *)((int)pcVar8 - (int)param_2);
      }
      return (int)local_c;
    }
  }
  return 0;
}

