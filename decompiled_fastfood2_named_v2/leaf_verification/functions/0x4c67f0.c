// rea decompile_all
// name: FUN_004c67f0
// address: 0x4c67f0
// body: available
// range: 0x4c67f0-0x4c6aaf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c67f0(void *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  void *this;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_3 < 0x19) {
    if (param_3 != 0x18) {
      if (param_3 == -0x18657) {
        if (param_2 < 0x131) {
          if (param_2 == 0x130) {
LAB_004c69a5:
            iVar2 = FUN_00531780(param_1,0x42d);
            if (iVar2 != 0) {
              iVar2 = FUN_0052fd90(param_1,0x42d,0);
              if (param_2 == 0x136) {
                iVar2 = iVar2 + 0x514;
              }
              else {
                iVar2 = iVar2 + -0x514;
              }
              FUN_0052fd70(param_1,0x42d,iVar2,0);
              puVar3 = (undefined4 *)FUN_0052fd90(param_1,0x42d,0);
              FUN_004c67f0(param_1,0x42d,0x19,puVar3);
            }
            *param_4 = 1;
            return;
          }
          if (param_2 == 0xd) {
            FUN_004c67f0(param_1,DAT_0056b154 + 0x444,1,(undefined4 *)0x0);
            *param_4 = 1;
            return;
          }
          if (param_2 == 0x12f) {
            if (DAT_0056b154 < 0) {
              DAT_0056b154 = 0xc;
            }
            else {
              DAT_0056b154 = DAT_0056b154 + -1;
              if (-1 < DAT_0056b154) goto joined_r0x004c692c;
              DAT_0056b154 = 0xc;
            }
            do {
              iVar2 = FUN_00531780(param_1,DAT_0056b154 + 0x451);
              if (iVar2 != 0) break;
              DAT_0056b154 = DAT_0056b154 + -1;
joined_r0x004c692c:
            } while (0 < DAT_0056b154);
            goto LAB_004c6954;
          }
        }
        else {
          if (param_2 == 0x135) {
            if ((DAT_0056b154 < 0) || (DAT_0056b154 = DAT_0056b154 + 1, DAT_0056b154 == 0xd)) {
              DAT_0056b154 = 0;
            }
            iVar2 = FUN_00531780(param_1,DAT_0056b154 + 0x451);
            if (iVar2 == 0) {
              DAT_0056b154 = 0;
            }
LAB_004c6954:
            FUN_004c6780(param_1,DAT_0056b154 + 0x451);
            *param_4 = 1;
            return;
          }
          if (param_2 == 0x136) goto LAB_004c69a5;
        }
      }
      else if (param_3 == 1) {
        if (param_2 == 0x443) {
          FUN_00482890((int)DAT_0057c670);
          return;
        }
        if ((0x443 < param_2) && (param_2 < 0x451)) {
          iVar1 = *(int *)((int)DAT_0057c670 + 0x274);
          iVar2 = *(int *)((int)DAT_0057c670 + 0x280) + -0x444 + param_2;
          Object_SetField280(DAT_0057c670,iVar2);
          FUN_00483120((int)DAT_0057c670);
          if (*(int *)((int)DAT_0057c670 + 0x278) == 0) {
            FUN_00528190(DAT_0057c5e0,iVar1,1);
            FUN_00482890((int)DAT_0057c670);
            Object_SetField280(DAT_0057c670,iVar2);
            return;
          }
          this = (void *)Game_GetActiveScreenOrFallback((int)DAT_0057c670);
          FUN_005301c0(this,iVar1,0x23,1);
          FUN_00482890((int)DAT_0057c670);
          Object_SetField280(DAT_0057c670,iVar2);
          return;
        }
      }
    }
  }
  else if (param_3 == 0x19) {
    if (param_2 == 0x42d) {
      FUN_00483150(DAT_0057c670,(int)param_4 / 100);
      Object_SetField280(DAT_0057c670,(int)param_4 / 100);
    }
  }
  else if (param_3 == 0x1f) {
    DAT_0056b154 = 0xffffffff;
    return;
  }
  return;
}

