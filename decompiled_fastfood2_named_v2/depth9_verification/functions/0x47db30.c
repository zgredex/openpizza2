// rea decompile_all
// name: FUN_0047db30
// address: 0x47db30
// body: available
// range: 0x47db30-0x47dcc1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047db30(void *this,void *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  void *pvVar5;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  void *local_14;
  int local_10;
  void *local_c;
  int local_8;
  int local_4;
  
  local_c = this;
  FUN_00401320(*(int *)(DAT_0057c670 + 0x244));
  pvVar5 = *(void **)((int)this + 0x16f0);
  local_10 = 0;
  local_14 = pvVar5;
  if (0 < *(int *)((int)pvVar5 + 0x8c)) {
    do {
      iVar2 = FUN_004d2a60(pvVar5,local_10);
      iVar3 = FUN_0050dbd0(iVar2);
      if (iVar3 == 0) {
        switch(*(undefined4 *)(iVar2 + 0x30)) {
        case 0xd:
        case 0xe:
        case 0x20:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
          goto switchD_0047db9b_caseD_d;
        default:
          goto switchD_0047db9b_caseD_f;
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
          iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 0x20),*(int *)(iVar2 + 0x50),(int *)0x0);
          iVar3 = *(int *)(iVar3 + 0x81c);
          break;
        case 0x17:
        case 0x1d:
        case 0x1e:
        case 0x1f:
          iVar3 = *(int *)(iVar2 + 0x110);
        }
        if (iVar3 != -1) {
switchD_0047db9b_caseD_f:
          piVar1 = *(int **)(iVar2 + 200);
          if (piVar1 != (int *)0x0) {
            pvVar5 = (void *)piVar1[0x16];
            iVar3 = *piVar1;
            FUN_00534370(pvVar5,iVar3,&local_20,&local_18);
            FUN_00534060(pvVar5,iVar3,&local_8,&local_4,&local_24,&local_1c);
            FUN_005340d0(pvVar5,iVar3,(int *)&local_24,(int *)&local_1c);
            local_20 = local_20 + (local_24 - *(int *)(*(int *)((int)local_c + 0x14e0) + 0x24));
            local_18 = local_18 + (local_1c - *(int *)(*(int *)((int)local_c + 0x14e0) + 0x28));
            if ((((local_20 <= param_2) && (param_2 <= local_8 + local_20)) && (local_18 <= param_3)
                ) && (param_3 <= local_4 + local_18)) {
              puVar4 = operator_new(8);
              *puVar4 = 1;
              *(int *)(puVar4 + 4) = iVar2;
              FUN_004014b0(param_1,puVar4);
            }
            pvVar5 = local_14;
          }
        }
      }
switchD_0047db9b_caseD_d:
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((int)pvVar5 + 0x8c));
  }
  FUN_00401340(*(int *)(DAT_0057c670 + 0x244));
  return;
}

