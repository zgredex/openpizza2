// rea decompile_all
// name: Recipe_Construct
// address: 0x50fc20
// body: available
// range: 0x50fc20-0x50fdc6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Recipe_Construct(void *this,int *param_1,char param_2)

{
  uint uVar1;
  void *this_00;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Constructs a recipe, optionally from a save stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a406;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0x48),0);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c698;
  if (param_1 != (int *)0x0) {
    Recipe_LoadFromStream(this,param_1);
    ExceptionList = local_c;
    return this;
  }
  *(undefined4 *)((int)this + 0x304) = 0;
  *(undefined1 *)((int)this + 0x1dc) = 0;
  *(undefined1 *)((int)this + 0x1dd) = 0;
  *(undefined4 *)((int)this + 0x308) = 5;
  *(undefined4 *)((int)this + 0x30c) = 0;
  FUN_0054dd83((undefined1 *)((int)this + 4),&DAT_005630d0,DAT_00582c6c);
  puVar2 = (undefined4 *)((int)this + 100);
  for (iVar4 = 0x56; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1e0);
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1bc);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_0050fdf0((int)this);
  uVar1 = FUN_004034d0(7,7);
  if (param_2 == '\0') {
    uVar1 = 0xffffffff;
  }
  if (0 < (int)uVar1) {
    do {
      this_00 = operator_new(0x1c);
      local_4._0_1_ = 1;
      if (this_00 == (void *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_004d1b30(this_00,(void *)0x0);
      }
      local_4 = (uint)local_4._1_3_ << 8;
      uVar3 = FUN_004034d0(0,0x55);
      *(char *)(puVar2 + 1) = (char)uVar3;
      *(undefined1 *)((int)puVar2 + 5) =
           *(undefined1 *)(*(int *)(DAT_0057c670 + 0xa8 + uVar3 * 4) + 0xa8);
      uVar3 = FUN_004034d0(0,3);
      *(char *)((int)puVar2 + 6) = (char)uVar3;
      uVar3 = FUN_004034d0(0x2d,400);
      puVar2[2] = uVar3 - 0x23;
      uVar3 = FUN_004034d0(0x35,400);
      puVar2[3] = uVar3 - 0x23;
      FUN_004014b0((void *)((int)this + 0x48),puVar2);
      FUN_0050fec0((int)this);
      fVar5 = FUN_0050fe70((int)this);
      *(float *)((int)this + 0x44) = (float)fVar5;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  FUN_0050fec0((int)this);
  fVar5 = FUN_0050fe70((int)this);
  *(float *)((int)this + 0x44) = (float)fVar5;
  ExceptionList = local_c;
  return this;
}

