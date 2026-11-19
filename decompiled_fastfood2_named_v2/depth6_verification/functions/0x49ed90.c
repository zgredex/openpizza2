// rea decompile_all
// name: FUN_0049ed90
// address: 0x49ed90
// body: available
// range: 0x49ed90-0x49ef0c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0049ed90(void)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  uint3 uVar6;
  int iVar5;
  int iVar7;
  char cVar8;
  undefined1 local_200 [512];
  
  this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  cVar8 = *(char *)(DAT_0057cda0 + 0x1dc) == '\x01';
  uVar3 = FUN_004e0f40(this,DAT_0057cda0);
  if ((char)uVar3 == '\x01') {
    cVar8 = '\x02';
  }
  DAT_0057cc38 = 0;
  if (cVar8 != '\0') {
    FUN_0054dd83(local_200,DAT_00582890,DAT_0057cda0 + 4);
    FUN_00482c40(DAT_0057c670,0xfffe798c,DAT_00581e34,local_200,0xfffe798d,0,-1,'\x01');
    DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    while (((DVar4 != 0 && (DAT_0057cc38 == 0)) && (*(int *)((int)DAT_0057c670 + 0x280) == 1))) {
      FUN_00525a10(DAT_0057c5e0,0);
      Sleep(10);
      DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    }
  }
  uVar6 = (uint3)((uint)DAT_0057c670 >> 8);
  if (*(int *)((int)DAT_0057c670 + 0x280) == 0) {
    return (uint)uVar6 << 8;
  }
  if (DAT_0057cc38 == 2) {
    return (uint)uVar6 << 8;
  }
  puVar1 = *(undefined4 **)((int)DAT_0057c670 + 0x98);
  FUN_004dde70(this,(int)puVar1);
  iVar5 = FUN_004ddd60(this,puVar1);
  if (cVar8 == '\x02') {
    iVar2 = *(int *)((int)this + 0x15c);
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        iVar5 = FUN_004017f0((void *)((int)this + 0x148),iVar7,(int *)0x0);
        if (((iVar5 != 0) && (*(undefined4 **)(iVar5 + 0x14dc) != (undefined4 *)0x0)) &&
           (*(undefined4 **)(iVar5 + 0x14dc) == puVar1)) {
          iVar5 = FUN_00477b80(iVar5);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
    }
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

