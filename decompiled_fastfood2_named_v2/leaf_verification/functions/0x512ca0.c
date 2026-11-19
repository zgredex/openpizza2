// rea decompile_all
// name: FUN_00512ca0
// address: 0x512ca0
// body: available
// range: 0x512ca0-0x512e4d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00512ca0(void *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  void *this;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int *piVar4;
  uint uVar5;
  longlong lVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    iVar3 = Game_GetPlayerBySlot(DAT_0057c670,local_8);
    if ((iVar3 != 0) && (local_c = 0, 0 < *(int *)(iVar3 + 0x124))) {
      do {
        this = (void *)IDMap_Lookup((void *)(iVar3 + 0x110),local_c,(int *)0x0);
        if ((this != (void *)0x0) && (this != param_1)) {
          local_14 = 0;
          local_10 = 0;
          local_18 = 0;
          local_1c = 0;
          uVar5 = 0;
          piVar4 = (int *)((int)this + 100);
          do {
            bVar2 = Product_HasStock(this,uVar5);
            if (CONCAT31(extraout_var,bVar2) != 0) {
              local_1c = local_1c + 1;
            }
            bVar2 = Product_HasStock(param_1,uVar5);
            if (CONCAT31(extraout_var_00,bVar2) == 0) {
              bVar2 = Product_HasStock(this,uVar5);
              if ((CONCAT31(extraout_var_02,bVar2) != 0) && (10 < *piVar4)) {
                local_14 = local_14 + 1;
              }
            }
            else {
              bVar2 = Product_HasStock(this,uVar5);
              if (CONCAT31(extraout_var_01,bVar2) == 0) {
                if (10 < *(int *)((int)piVar4 + ((int)param_1 - (int)this))) {
                  local_18 = local_18 + 1;
                }
              }
              else {
                fVar1 = (float)*(int *)((int)piVar4 + ((int)param_1 - (int)this));
                if ((fVar1 * 0.8 <= (float)*piVar4) && ((float)*piVar4 <= fVar1 * 1.2)) {
                  local_10 = local_10 + 1;
                }
              }
            }
            uVar5 = uVar5 + 1;
            piVar4 = piVar4 + 1;
          } while ((int)uVar5 < 0x56);
          if ((local_18 < 2) && (local_14 < 2)) {
            if (local_1c == local_10) {
              *(undefined4 *)((int)param_1 + 0x240) = 0;
              return;
            }
            if ((2 < local_1c) && (lVar6 = __ftol(), (int)lVar6 <= local_10)) {
              *(undefined4 *)((int)param_1 + 0x240) = 0;
              return;
            }
          }
        }
        local_c = local_c + 1;
      } while (local_c < *(int *)(iVar3 + 0x124));
    }
    local_8 = local_8 + 1;
    if (5 < local_8) {
      *(undefined4 *)((int)param_1 + 0x240) = 1;
      return;
    }
  } while( true );
}

