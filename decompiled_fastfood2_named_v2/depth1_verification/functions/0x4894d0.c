// rea decompile_all
// name: FUN_004894d0
// address: 0x4894d0
// body: available
// range: 0x4894d0-0x48974a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004894d0(void *this,undefined4 param_1,int param_2,int param_3,int *param_4)

{
  ushort uVar1;
  HCURSOR lParam;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 == 0x2a) {
    if (param_3 == 8) {
      if (*(int *)((int)this + 0x2d98) != 0) {
        if (*(int *)((int)this + 0x2fc) != 0) {
          if (DAT_0057c658 == 0) {
            DAT_0057c660 = DAT_0057c660 + param_4[2];
            uVar5 = param_4[3] >> 0x1f;
            uVar4 = param_4[2];
            iVar3 = (param_4[3] ^ uVar5) - uVar5;
            DAT_0057c664 = DAT_0057c664 + param_4[3];
          }
          else {
            DAT_0057c660 = *param_4 - DAT_0057c628;
            uVar4 = param_4[1] - DAT_0057c62c;
            iVar3 = (DAT_0057c660 ^ (int)DAT_0057c660 >> 0x1f) - ((int)DAT_0057c660 >> 0x1f);
            DAT_0057c664 = uVar4;
          }
          DAT_0057c650 = ((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) + DAT_0057c650 +
                         iVar3;
          Input_CompleteEvent((void *)((int)this + 0x2d1c),*(int *)((int)this + 0x2da4));
        }
        if (DAT_0057c658 == 0) {
          FUN_00527e20(DAT_0057c5e0,DAT_0057c628,DAT_0057c62c,0,0);
        }
      }
    }
    else {
      if (param_3 == 9) {
        *(undefined4 *)((int)this + 0x2da8) = 0;
        iVar3 = FUN_004893a0(this,9);
        DAT_0057c620 = *param_4;
        DAT_0057c624 = param_4[1];
        if (iVar3 == 0) {
          DAT_0057c628 = (DAT_00571950 >> 1) >> ((byte)DAT_00580a50 & 0x1f);
          DAT_0057c62c = (DAT_00571954 >> 1) >> ((byte)DAT_00580a50 & 0x1f);
        }
        else {
          DAT_0057c628 = DAT_0057c620;
          DAT_0057c62c = DAT_0057c624;
        }
        PostMessageA(DAT_0057c5d0,0x400,0,0);
        FUN_00527e20(DAT_0057c5e0,DAT_0057c628,DAT_0057c62c,1,0);
        uVar1 = GetAsyncKeyState(0x11);
        if ((uVar1 & 0x8000) == 0) {
          *(undefined4 *)((int)this + 0x2d98) = 1;
        }
        else {
          *(undefined4 *)((int)this + 0x2d98) = 2;
        }
        DAT_0057c630 = timeGetTime();
        DAT_0057c664 = 0;
        DAT_0057c660 = 0;
        DAT_0057c650 = 0;
        _DAT_0057c690 = DAT_0057c630;
        _DAT_0057c648 = 0;
        _DAT_0057c64c = 0;
        return;
      }
      if (param_3 == 10) {
        FUN_004893a0(this,10);
        if (*(int *)((int)this + 0x2d98) != 0) {
          *(undefined4 *)((int)this + 0x2d98) = 0;
          FUN_00527e20(DAT_0057c5e0,DAT_0057c620,DAT_0057c624,0,0);
          lParam = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
          PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)lParam);
        }
        if (DAT_0057c650 < 3) {
          DVar2 = timeGetTime();
          if (DVar2 - _DAT_0057c690 < 200) {
            FUN_0048a4c0(this);
          }
        }
        DAT_0057c664 = 0;
        DAT_0057c660 = 0;
        return;
      }
    }
  }
  return;
}

