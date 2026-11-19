// rea decompile_all
// name: SoundSample_Construct
// address: 0x53f460
// body: available
// range: 0x53f460-0x53f5a3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall SoundSample_Construct(void *this,void *param_1,char *param_2,int *param_3)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a sound sample, opens its stream, and parses its format. */
  puStack_8 = &LAB_0055ae28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = 1;
  *(void **)((int)this + 8) = param_1;
  local_4 = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined1 *)((int)this + 0x48) = 0;
  *(undefined ***)this = &PTR_LAB_0055c850;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  uVar5 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = operator_new(~uVar5);
  *(char **)((int)this + 0x10) = pcVar2;
  if (pcVar2 == (char *)0x0) {
    if (param_3 != (int *)0x0) {
      *param_3 = -0x7ff8fff2;
    }
  }
  else {
    uVar5 = 0xffffffff;
    pcVar7 = param_2;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar2 = pcVar2 + 1;
    }
    piVar3 = SoundPakManager_OpenStream(param_1,param_2);
    *(int **)((int)this + 0xc) = piVar3;
    if (piVar3 == (int *)0x0) {
      FUN_0048e0a0();
      if (param_3 != (int *)0x0) {
        *param_3 = -0x7fffbffb;
      }
    }
    else {
      iVar4 = SoundSample_ParseWavFormat((int)this);
      if (iVar4 < 0) {
        if (iVar4 == -0x7fffbffb) {
          FUN_0048e0a0();
        }
        if (param_3 != (int *)0x0) {
          *param_3 = iVar4;
        }
      }
      else {
        FUN_0053f790(this,0);
      }
    }
  }
  ExceptionList = local_c;
  return this;
}

