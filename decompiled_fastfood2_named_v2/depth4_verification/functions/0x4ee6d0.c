// rea decompile_all
// name: Map_UpdateObjectState
// address: 0x4ee6d0
// body: available
// range: 0x4ee6d0-0x4ee833 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Map_UpdateObjectState(void *this,int *param_1)

{
  byte bVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  
                    /* Updates map-object state. */
  this_00 = *(void **)(*(int *)((int)this + 4) + 0x2c3b8);
  local_24 = *(int *)(*(int *)((int)this + 4) + 0x2c414);
  local_20 = 0;
  do {
    bVar1 = *(byte *)(param_1[2] + 0x2c + local_20);
    if (bVar1 < 0x28) {
      if (0x1d < bVar1) {
        iVar3 = -0x10;
        iVar2 = bVar1 - 0x1e;
        goto LAB_004ee75e;
      }
      if (0x13 < bVar1) {
        iVar3 = -8;
        iVar2 = bVar1 - 0x14;
        goto LAB_004ee75e;
      }
      if (9 < bVar1) {
        iVar3 = 0;
        iVar2 = bVar1 - 10;
        goto LAB_004ee75e;
      }
    }
    else {
      iVar3 = -8;
      iVar2 = bVar1 - 0x28;
LAB_004ee75e:
      if (iVar2 != -1) {
        FUN_00534990(this_00,local_24,iVar2);
        FUN_005336f0(this_00,&local_1c,&local_18,local_c,&local_10);
        FUN_004f34c0(this,param_1,&local_2c,&local_28);
        local_2c = local_2c - ((local_1c >> 1) + *(int *)((int)this + 0x24));
        local_28 = local_28 - ((local_18 >> 1) + *(int *)((int)this + 0x28));
        local_14 = local_2c + iVar3 + 2;
        FUN_005344e0(this_00,*(uint **)((int)this + 8),DAT_0058072c,local_24);
      }
    }
    local_20 = local_20 + 1;
    if (3 < local_20) {
      return;
    }
  } while( true );
}

