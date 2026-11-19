// rea decompile_all
// name: FUN_0054b460
// address: 0x54b460
// body: available
// range: 0x54b460-0x54b614 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_0054b460(void *this,void *param_1,void *param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b931;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 4),0);
  local_4 = 0;
  FUN_004013a0((void *)((int)this + 0x20),0);
  local_4._0_1_ = 1;
  FUN_004013a0((void *)((int)this + 0x3c),0);
  local_4._0_1_ = 2;
  FUN_004013a0((void *)((int)this + 0x58),0);
  local_4._0_1_ = 3;
  FUN_004013a0((void *)((int)this + 0x74),0);
  local_4._0_1_ = 4;
  FUN_004013a0((void *)((int)this + 0x90),0);
  local_4._0_1_ = 5;
  FUN_004013a0((void *)((int)this + 0xac),0);
  local_4._0_1_ = 6;
  FUN_004013a0((void *)((int)this + 200),0);
  local_4 = CONCAT31(local_4._1_3_,7);
  *(undefined ***)this = &PTR_FUN_0055cb44;
  Sprite_LoadSequence((byte *)s_PizzaImages_HEAD_F__02d_spr_00576590,(void *)((int)this + 0x20),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_HEAD_M__02d_spr_00576574,(void *)((int)this + 4),param_1
                      ,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_AUGEN_F__02d_spr_00576554,(void *)((int)this + 0x58),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_AUGEN_M__02d_spr_00576534,(void *)((int)this + 0x3c),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_HAARE_F__02d_spr_00576514,(void *)((int)this + 0x90),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_HAARE_M__02d_spr_005764f4,(void *)((int)this + 0x74),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_MUND_F__02d_spr_005764d8,(void *)((int)this + 200),
                      param_1,param_2);
  Sprite_LoadSequence((byte *)s_PizzaImages_MUND_M__02d_spr_005764bc,(void *)((int)this + 0xac),
                      param_1,param_2);
  DAT_00585588 = *(int *)((int)this + 0x34);
  if (*(int *)((int)this + 0x18) <= *(int *)((int)this + 0x34)) {
    DAT_00585588 = *(int *)((int)this + 0x18);
  }
  DAT_00585580 = *(int *)((int)this + 0x6c);
  if (*(int *)((int)this + 0x50) <= *(int *)((int)this + 0x6c)) {
    DAT_00585580 = *(int *)((int)this + 0x50);
  }
  DAT_00585584 = *(int *)((int)this + 0xdc);
  if (*(int *)((int)this + 0xc0) <= *(int *)((int)this + 0xdc)) {
    DAT_00585584 = *(int *)((int)this + 0xc0);
  }
  DAT_0058557c = *(int *)((int)this + 0xa4);
  if (*(int *)((int)this + 0x88) <= *(int *)((int)this + 0xa4)) {
    DAT_0058557c = *(int *)((int)this + 0x88);
  }
  ExceptionList = local_c;
  return this;
}

