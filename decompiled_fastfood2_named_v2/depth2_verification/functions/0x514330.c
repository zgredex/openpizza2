// rea decompile_all
// name: FUN_00514330
// address: 0x514330
// body: available
// range: 0x514330-0x514440 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00514330(void *param_1)

{
  int iVar1;
  void *this;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  int local_c;
  
  iVar1 = FUN_00514320((int)param_1);
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x28),
                              (int *)0x0);
  puVar2 = (undefined4 *)FUN_004da630(this,*(int *)((int)param_1 + 0x30));
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x24));
    local_c = iVar1 - *(int *)((int)param_1 + 0x58);
    iVar1 = iVar1 / (*(int *)((int)param_1 + 0x2c) + 1);
    if (iVar1 < local_c) {
      local_c = iVar1;
    }
    puVar2[*(int *)((int)param_1 + 0x24) + 5] = puVar2[*(int *)((int)param_1 + 0x24) + 5] + local_c;
    if (0 < local_c) {
      do {
        puVar4 = operator_new(0x20);
        puVar5 = puVar4;
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        *puVar4 = 200000;
        fVar6 = FUN_004e2410(iVar3,this,(int)puVar2);
        puVar4[4] = (float)fVar6;
        puVar4[1] = *puVar2;
        puVar4[3] = puVar2[1];
        FUN_004014b0((void *)((int)param_1 + 0x44),puVar4);
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    FUN_00514100(param_1,*(float *)((int)this + 0x94) * 100.0,'\0');
    if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x264),-0x1861c,0x23,0);
    }
  }
  return;
}

