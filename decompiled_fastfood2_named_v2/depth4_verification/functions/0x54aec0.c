// rea decompile_all
// name: UI_AddBriefingButton
// address: 0x54aec0
// body: available
// range: 0x54aec0-0x54afa0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_AddBriefingButton(void *this,int param_1,int param_2,int param_3)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_800 [2048];
  
                    /* Creates a briefing button and its label. */
  FUN_0052f5b0(*(void **)((int)this + 0x34),param_2,param_3,*(int *)((int)this + 0x24),
               (&PTR_s_BRIEFBUTTONS_ALLGEM_00_005763a4)
               [(uint)(*(int *)(param_1 + 0x10) == 0) + *(int *)(param_1 + 4) * 2],0,0);
  FUN_00531fb0(*(void **)((int)this + 0x34),param_2,1,(char *)0x0);
  uVar3 = 0xffffffff;
  pcVar5 = (char *)(param_1 + 0x38);
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = local_800;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pvVar2 = (void *)FUN_005272c0(DAT_0057c5e0);
  FUN_00535c10(pvVar2,local_800,300);
  FUN_00531f50(*(void **)((int)this + 0x34),param_2,local_800);
  *(int *)(param_1 + 8) = param_2;
  *(float *)(param_1 + 0x1c) = (float)param_3;
  pvVar2 = (void *)FUN_005313d0(*(void **)((int)this + 0x34),param_2);
  if (pvVar2 != (void *)0x0) {
    FUN_00520f30(pvVar2,&LAB_0054a960,param_1);
  }
  return;
}

