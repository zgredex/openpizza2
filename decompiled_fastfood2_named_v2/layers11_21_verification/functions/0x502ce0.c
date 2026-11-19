// rea decompile_all
// name: AI_InitActionPlan
// address: 0x502ce0
// body: available
// range: 0x502ce0-0x502eab inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
AI_InitActionPlan(void *this,uint param_1,uint param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
                    /* Initializes a player's AI action plan and selected action. */
  iVar4 = 0;
  iVar3 = 0xd;
  *(undefined4 *)((int)this + 0x84) = 0;
  piVar1 = (int *)((int)this + 0xc);
  do {
    if (*piVar1 == 1) {
      iVar4 = iVar4 + 1;
    }
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (iVar4 == 0xd) {
    piVar1 = (int *)((int)this + 0xc);
    for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar1 = 0;
      piVar1 = piVar1 + 1;
    }
  }
  if (param_1 == 0xffffffff) {
    param_1 = FUN_004034d0(0,0xc);
    do {
      param_1 = param_1 + 1;
      if (param_1 == 0xd) {
        param_1 = 0;
      }
    } while (*(int *)((int)this + param_1 * 4 + 0xc) != 0);
  }
  *(undefined4 *)((int)this + 8) = 0xffffffff;
  *(uint *)((int)this + 0x58) = param_1;
  *(undefined4 *)((int)this + param_1 * 4 + 0xc) = 1;
  if (param_2 == 0xffffffff) {
    param_2 = Game_GetStatBandByIndex(this,param_1);
  }
  *(uint *)((int)this + 0x44) = param_2;
  *(undefined4 *)((int)this + 0x40) = (&DAT_005726a8)[param_1];
  uVar2 = AI_SelectActionForType((int)this);
  *(undefined4 *)((int)this + 0x48) = uVar2;
  if (param_3 != -1) {
    *(int *)((int)this + 0x48) = param_3;
  }
  if ((param_4 != -1) && (param_3 != -1)) {
    if (param_3 < 0xc) {
      uVar2 = *(undefined4 *)(&DAT_0057270c + (param_3 / 3 + (param_3 % 3) * 4) * 4);
    }
    else if (param_3 < 0x18) {
      uVar2 = *(undefined4 *)
               (&DAT_0057276c + ((param_3 + -0xc) / 3 + ((param_3 + -0xc) % 3) * 4) * 4);
    }
    else {
      uVar2 = *(undefined4 *)
               (&DAT_005727cc + ((param_3 + -0x18) / 3 + ((param_3 + -0x18) % 3) * 4) * 4);
    }
    *(undefined4 *)((int)this + 0x4c) = uVar2;
  }
  if (param_5 != -1) {
    *(int *)((int)this + 0x84) = param_5;
  }
  if (param_4 == -1) {
    if (*(int *)((int)this + 0x40) == 6) goto LAB_00502e72;
    if (*(int *)((int)this + 0x40) < 3) {
      iVar3 = *(int *)((int)this + 0x4c) * 0xb;
    }
    else {
      iVar3 = *(int *)((int)this + 0x4c) * 9;
    }
  }
  else {
    iVar3 = *(int *)((int)this + 0x4c) * 6;
  }
  *(int *)((int)this + 0x4c) = iVar3 / 10;
LAB_00502e72:
  uVar2 = FUN_00502c50(this,*(int *)((int)this + 0x40));
  *(undefined4 *)((int)this + 0x50) = uVar2;
  uVar2 = FUN_00502cb0(this,*(int *)((int)this + 0x40));
  *(undefined4 *)((int)this + 0x54) = uVar2;
  if (param_6 != -1) {
    *(int *)((int)this + 0x50) = param_6;
  }
  if (param_7 != -1) {
    *(int *)((int)this + 0x54) = param_7;
  }
  return;
}

