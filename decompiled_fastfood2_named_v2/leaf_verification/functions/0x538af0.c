// rea decompile_all
// name: Surface_CreateDesc
// address: 0x538af0
// body: available
// range: 0x538af0-0x538d9e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Surface_CreateDesc(void *this,undefined4 param_1,undefined4 param_2,int *param_3,int param_4,
                  uint param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [26];
  uint local_4;
  
  *param_3 = 0;
  puVar2 = local_6c;
                    /* Builds a surface description and creates it through vtable. */
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_6c[3] = param_1;
  local_6c[0] = 0x6c;
  local_6c[2] = param_2;
  local_6c[1] = 7;
  if (param_4 == 0) {
    local_4 = param_5 | 0x40;
  }
  else {
    local_4 = param_5 | 0x4000;
  }
  iVar1 = (**(code **)(*(int *)**(undefined4 **)((int)this + 0x40) + 0x18))
                    ((int *)**(undefined4 **)((int)this + 0x40),local_6c,&param_5,0);
  if (iVar1 == 0) {
    return param_1;
  }
  if (iVar1 < -0x7789ff1e) {
    if (iVar1 == -0x7789ff1f) {
      *param_3 = 0x136;
      return 0;
    }
    if (iVar1 < -0x7789ff7d) {
      if (iVar1 == -0x7789ff7e) {
        *param_3 = 0x12f;
        return 0;
      }
      if (iVar1 < -0x7789ffa0) {
        if (iVar1 == -0x7789ffa1) {
          *param_3 = 0x12d;
          return 0;
        }
        if (iVar1 == -0x7ff8fff2) {
          *param_3 = 0x13a;
          return 0;
        }
        if (iVar1 == -0x7ff8ffa9) {
          *param_3 = 0x130;
          return 0;
        }
      }
      else if (iVar1 == -0x7789ff9c) {
        *param_3 = 0x12e;
        return 0;
      }
    }
    else {
      if (iVar1 == -0x7789ff6f) {
        *param_3 = 0x131;
        return 0;
      }
      if (iVar1 == -0x7789ff4c) {
        *param_3 = 0x132;
        return 0;
      }
      if (iVar1 == -0x7789ff2c) {
        *param_3 = 0x133;
        return 0;
      }
    }
  }
  else if (iVar1 < -0x7789fdcb) {
    if (iVar1 == -0x7789fdcc) {
      *param_3 = 0x13c;
      return 0;
    }
    if (iVar1 < -0x7789fe83) {
      if (iVar1 == -0x7789fe84) {
        *param_3 = 0x13b;
        return 0;
      }
      if (iVar1 == -0x7789ff1a) {
        *param_3 = 0x137;
        return 0;
      }
      if (iVar1 == -0x7789feac) {
        *param_3 = 0x139;
        return 0;
      }
    }
    else if (iVar1 == -0x7789fdcd) {
      *param_3 = 0x134;
      return 0;
    }
  }
  else if (iVar1 == -0x7789fdcb) {
    iVar1 = 9;
  }
  else {
    if (iVar1 == -0x7789fdb2) {
      *param_3 = 0x13d;
      return 0;
    }
    if (iVar1 == -0x7789fdb1) {
      *param_3 = 0x138;
      return 0;
    }
  }
  *param_3 = iVar1 + 300;
  return 0;
}

