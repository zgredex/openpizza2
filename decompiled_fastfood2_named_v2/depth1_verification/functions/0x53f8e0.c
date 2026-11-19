// rea decompile_all
// name: FUN_0053f8e0
// address: 0x53f8e0
// body: available
// range: 0x53f8e0-0x53fbec inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0053f8e0(void *this,undefined4 *param_1,uint param_2)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_810;
  undefined4 *local_80c;
  uint local_808;
  short local_800;
  undefined1 local_7fe;
  undefined2 local_7fc;
  undefined1 local_7fa;
  char local_7f8 [2040];
  
  uVar2 = (uint)*(ushort *)((int)this + 0x20);
  local_80c = param_1;
  uVar5 = uVar2 * 4 + (uint)*(ushort *)((int)this + 0x16) * -0xe;
  local_808 = param_2;
  if (*(uint *)((int)this + 0x30) % uVar5 != 0) {
    if (*(char *)((int)this + 0x48) != '\0') {
      uVar6 = uVar2 + (uint)*(ushort *)((int)this + 0x16) * -4;
      uVar2 = FUN_005401b0(*(void **)((int)this + 8),(char *)&local_800,uVar2,
                           *(int *)((int)this + 0xc));
      if (uVar2 < *(ushort *)((int)this + 0x20)) {
        FUN_0048e0a0();
        return -0x7fffbffb;
      }
      psVar1 = (short *)((int)this + 0x40);
      *(undefined1 *)((int)this + 0x42) = local_7fe;
      *psVar1 = local_800;
      **(short **)((int)this + 0x3c) = local_800;
      if (*(short *)((int)this + 0x16) == 2) {
        *(undefined2 *)((int)this + 0x44) = local_7fc;
        *(undefined1 *)((int)this + 0x46) = local_7fa;
        *(undefined2 *)(*(int *)((int)this + 0x3c) + 2) = local_7fc;
        FUN_0053ea00(local_7f8,(undefined2 *)(*(int *)((int)this + 0x3c) + 4),uVar6,psVar1);
      }
      else {
        FUN_0053ec60((char *)&local_7fc,(short *)(*(int *)((int)this + 0x3c) + 2),uVar6,psVar1);
      }
    }
    uVar6 = *(uint *)((int)this + 0x30) % uVar5;
    uVar2 = uVar5 - uVar6;
    if (param_2 < uVar2) {
      uVar2 = param_2;
    }
    local_808 = param_2 - uVar2;
    puVar4 = (undefined4 *)(*(int *)((int)this + 0x3c) + uVar6);
    puVar7 = param_1;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar6 = uVar2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    local_80c = (undefined4 *)(uVar2 + (int)param_1);
    *(uint *)((int)this + 0x30) = *(int *)((int)this + 0x30) + uVar2;
  }
  local_810 = 0;
  *(undefined1 *)((int)this + 0x48) = 0;
  uVar2 = local_808;
  do {
    while( true ) {
      if (local_808 == 0) {
        return local_810;
      }
      if (*(uint *)((int)this + 0x28) <= *(uint *)((int)this + 0x30)) break;
      uVar3 = (uint)*(ushort *)((int)this + 0x20) + (uint)*(ushort *)((int)this + 0x16) * -4;
      uVar6 = FUN_005401b0(*(void **)((int)this + 8),(char *)&local_800,
                           (uint)*(ushort *)((int)this + 0x20),*(int *)((int)this + 0xc));
      if (uVar6 < *(ushort *)((int)this + 0x20)) {
        FUN_0048e0a0();
        return -0x7fffbffb;
      }
      psVar1 = (short *)((int)this + 0x40);
      *(undefined1 *)((int)this + 0x42) = local_7fe;
      *psVar1 = local_800;
      **(short **)((int)this + 0x3c) = local_800;
      if (*(short *)((int)this + 0x16) == 2) {
        *(undefined2 *)((int)this + 0x44) = local_7fc;
        *(undefined1 *)((int)this + 0x46) = local_7fa;
        *(undefined2 *)(*(int *)((int)this + 0x3c) + 2) = local_7fc;
        FUN_0053ea00(local_7f8,(undefined2 *)(*(int *)((int)this + 0x3c) + 4),uVar3,psVar1);
      }
      else {
        FUN_0053ec60((char *)&local_7fc,(short *)(*(int *)((int)this + 0x3c) + 2),uVar3,psVar1);
        uVar2 = local_808;
      }
      local_810 = 0;
      uVar6 = uVar5;
      if (uVar2 <= uVar5) {
        uVar6 = uVar2;
      }
      uVar3 = *(int *)((int)this + 0x28) - *(int *)((int)this + 0x30);
      if (uVar3 < uVar6) {
        uVar6 = uVar3;
      }
      local_808 = uVar2 - uVar6;
      puVar4 = *(undefined4 **)((int)this + 0x3c);
      puVar7 = local_80c;
      for (uVar2 = uVar6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar2 = uVar6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      local_80c = (undefined4 *)((int)local_80c + uVar6);
      *(uint *)((int)this + 0x30) = *(int *)((int)this + 0x30) + uVar6;
      uVar2 = local_808;
    }
    if (*(char *)((int)this + 0x34) == '\0') {
      for (uVar2 = local_808 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *local_80c = 0;
        local_80c = local_80c + 1;
      }
      for (local_808 = local_808 & 3; local_808 != 0; local_808 = local_808 - 1) {
        *(undefined1 *)local_80c = 0;
        local_80c = (undefined4 *)((int)local_80c + 1);
      }
      return 1;
    }
    local_810 = SoundBuffer_SeekSample(this,0);
  } while (-1 < local_810);
  return local_810;
}

