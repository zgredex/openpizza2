// rea decompile_all
// name: FinanceScreen_UpdateStatement
// address: 0x48fad0
// body: available
// range: 0x48fad0-0x48ffcc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FinanceScreen_UpdateStatement(void *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 uVar7;
  float local_38;
  int local_34;
  undefined1 local_28 [36];
  
                    /* Fills the finance statement figures from the statistics ledger. */
  DAT_0057c69c = *(int *)(DAT_0057c670 + 0x9c);
  uVar4 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uVar3 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  fVar5 = FUN_00478090(DAT_0057c69c,-1,uVar3,uVar4);
  fVar1 = (float)fVar5;
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x471,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,0xc,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x47e,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,0xe,uVar3,uVar4);
  fVar6 = FUN_00478090(DAT_0057c69c,0,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)(fVar6 + (float10)(float)fVar5),0));
  Window_GadgetNotify_Text_SetText(param_1,0x473,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,1,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x472,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,2,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x47b,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,4,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x47a,local_28);
  fVar5 = FUN_0047a670(DAT_0057c69c,1,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x47f,local_28);
  fVar5 = FUN_0047a670(DAT_0057c69c,3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x487,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,0xb,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x1f42,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,5,uVar3,uVar4);
  fVar6 = FUN_00478090(DAT_0057c69c,9,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)(fVar6 + (float10)(float)fVar5),0));
  Window_GadgetNotify_Text_SetText(param_1,0x483,local_28);
  fVar5 = FUN_00478090(DAT_0057c69c,0x13,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x482,local_28);
  FUN_00531740(param_1,0x485);
  FUN_00531740(param_1,0x486);
  fVar5 = FUN_00477fe0(DAT_0057c69c,-1,uVar3,uVar4);
  fVar2 = (float)fVar5;
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x474,local_28);
  local_38 = 0.0;
  local_34 = 0;
  do {
    fVar5 = FUN_00477fe0(DAT_0057c69c,local_34,uVar3,uVar4);
    local_34 = local_34 + 1;
    local_38 = (float)(fVar5 + (float10)local_38);
  } while (local_34 < 8);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)local_38,0));
  Window_GadgetNotify_Text_SetText(param_1,0x475,local_28);
  fVar5 = FUN_00477fe0(DAT_0057c69c,0x16,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x476,local_28);
  fVar5 = FUN_00477fe0(DAT_0057c69c,0x17,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x489,local_28);
  fVar5 = FUN_00477fe0(DAT_0057c69c,0x15,uVar3,uVar4);
  FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(param_1,0x477,local_28);
  if (fVar2 < fVar1) {
    Window_GadgetNotify_Text_SetTextColor(param_1,0x43c,0xff);
    Window_GadgetNotify_Text_SetText(param_1,0x43c,DAT_00582554);
    FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)(fVar1 - fVar2),0));
    uVar7 = 0xff;
  }
  else {
    Window_GadgetNotify_Text_SetTextColor(param_1,0x43c,0xa000);
    Window_GadgetNotify_Text_SetText(param_1,0x43c,DAT_00582d8c);
    FUN_0054dd83(local_28,(byte *)s___2f___005683d4,SUB84((double)(fVar2 - fVar1),0));
    uVar7 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(param_1,0x466,uVar7);
  Window_GadgetNotify_Text_SetText(param_1,0x466,local_28);
  return;
}

