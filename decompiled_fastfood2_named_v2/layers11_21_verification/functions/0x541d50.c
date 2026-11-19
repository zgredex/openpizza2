// rea decompile_all
// name: SoundVoice_Construct
// address: 0x541d50
// body: available
// range: 0x541d50-0x541efd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
SoundVoice_Construct
          (void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
          char param_5,undefined4 param_6,int *param_7)

{
  char cVar1;
  char *pcVar2;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a streaming sound voice with its WAV list and defaults. */
  puStack_8 = &LAB_0055aff3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = 1;
  *(undefined ***)this = &PTR_LAB_0055c840;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  local_4 = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x34) = param_1;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = param_3;
  *(undefined4 *)((int)this + 0x38) = param_6;
  *(undefined1 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  if ((param_7 == (int *)0x0) || (-1 < *param_7)) {
    uVar4 = 0xffffffff;
    pcVar2 = param_4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = operator_new(~uVar4);
    *(char **)((int)this + 0x44) = pcVar2;
    if (pcVar2 == (char *)0x0) {
      if (param_7 != (int *)0x0) {
        *param_7 = -0x7ff8fff2;
      }
    }
    else {
      uVar4 = 0xffffffff;
      do {
        pcVar7 = param_4;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = param_4 + 1;
        cVar1 = *param_4;
        param_4 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar7 + -uVar4;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar2 = pcVar2 + 1;
      }
      pcVar2 = *(char **)((int)this + 0x44);
      *(undefined4 *)((int)this + 0x40) = 1;
      cVar1 = *pcVar2;
      while (cVar1 != '\0') {
        if (cVar1 == ',') {
          *(int *)((int)this + 0x40) = *(int *)((int)this + 0x40) + 1;
        }
        pcVar7 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar7;
      }
    }
  }
  puVar8 = (undefined4 *)((int)this + 0x50);
  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined1 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x74) = param_2;
  *(undefined4 *)((int)this + 0x78) = 10000;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0x3f800000;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined1 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x8c) = 0;
  DVar3 = timeGetTime();
  *(DWORD *)((int)this + 0x90) = DVar3;
  *(DWORD *)((int)this + 0x94) = DVar3;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined4 *)((int)this + 0x9c) = 10000;
  *(undefined ***)this = &PTR_LAB_0055c8e0;
  *(undefined1 *)((int)this + 0x55) = 1;
  if (param_5 == '\0') {
    *(undefined1 *)((int)this + 0x51) = 0;
  }
  else {
    *(undefined1 *)((int)this + 0x51) = 1;
  }
  if ((param_7 == (int *)0x0) || (-1 < *param_7)) {
    iVar6 = 0;
    if (param_5 == '\0') {
      iVar6 = SoundVoice_Open(this);
    }
    else {
      *(undefined1 *)((int)this + 0x53) = 0;
    }
    if (param_7 != (int *)0x0) {
      *param_7 = iVar6;
    }
  }
  ExceptionList = local_c;
  return this;
}

