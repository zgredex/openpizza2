// rea decompile_all
// name: FUN_00539980
// address: 0x539980
// body: available
// range: 0x539980-0x539dfd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00539980(void *this,HWND param_1,int param_2,uint param_3,HDC param_4,int param_5,int param_6,
            int param_7,ushort *param_8,HDC param_9,int param_10,ushort *param_11)

{
  HDC hdcSrc;
  int iVar1;
  HBITMAP h;
  HGDIOBJ h_00;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  uint cx;
  int iVar6;
  void *local_58;
  void *local_54;
  HDC local_50;
  uint local_4c;
  HDC local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  BITMAPINFO local_2c;
  
  if (param_10 == -1) {
    param_10 = param_3;
  }
  if (param_11 == (ushort *)0xffffffff) {
    param_11 = (ushort *)param_4;
  }
  local_44 = param_5 + param_10;
  local_40 = (int)&((HDC)param_11)->unused + param_6;
  iVar6 = *(int *)((int)this + 0x58);
  local_3c = (param_3 - *(int *)((int)this + 0x5c)) * iVar6;
  local_38 = ((int)param_4 - *(int *)((int)this + 0x60)) * iVar6;
  iVar5 = iVar6 * param_5 + local_3c;
  puVar4 = (ushort *)(iVar6 * param_6 + local_38);
  local_4c = param_10;
  if (param_10 < 0) {
    local_4c = 0;
    local_3c = local_3c - iVar6 * param_10;
  }
  iVar1 = local_3c;
  local_48 = (HDC)param_11;
  if ((int)param_11 < 0) {
    local_48 = (HDC)0x0;
    local_38 = local_38 - iVar6 * (int)param_11;
  }
  if (param_7 < local_44) {
    iVar5 = iVar5 - (local_44 - param_7) * iVar6;
  }
  if ((int)param_8 < local_40) {
    puVar4 = (ushort *)((int)puVar4 - (local_40 - (int)param_8) * iVar6);
  }
  if (local_3c < 0) {
    local_3c = 0;
    local_4c = local_4c - iVar1 / iVar6;
  }
  if (local_38 < 0) {
    iVar1 = local_38 / iVar6;
    local_38 = 0;
    local_48 = (HDC)((int)local_48 - iVar1);
  }
  iVar1 = iVar6 * (param_3 - param_10) + param_7;
  if (iVar1 < iVar5) {
    iVar5 = iVar1;
  }
  puVar2 = (ushort *)(iVar6 * ((int)param_4 - (int)param_11) + (int)param_8);
  if ((int)puVar2 < (int)puVar4) {
    puVar4 = puVar2;
  }
  cx = iVar5 - local_3c;
  iVar5 = (int)puVar4 - local_38;
  if ((0 < (int)cx) && (0 < iVar5)) {
    iVar1 = iVar6 * (int)local_48;
    iVar6 = iVar6 * local_4c;
    local_54 = this;
    if (param_9 == (HDC)0x0) {
      param_4 = GetDC(param_1);
      if (param_4 == (HDC)0x0) {
        NoOp_Stub();
      }
    }
    else {
      param_4 = param_9;
    }
    local_2c.bmiHeader.biCompression = 0;
    local_2c.bmiHeader.biSizeImage = 0;
    local_2c.bmiHeader.biXPelsPerMeter = 0;
    local_2c.bmiHeader.biYPelsPerMeter = 0;
    local_2c.bmiHeader.biSize = 0x28;
    local_2c.bmiHeader.biClrUsed = 0x7fff;
    local_2c.bmiHeader.biClrImportant = 0x7fff;
    local_2c.bmiHeader.biPlanes = 1;
    local_2c.bmiHeader.biBitCount = 0x10;
    local_2c.bmiHeader.biWidth = cx;
    local_2c.bmiHeader.biHeight = iVar5;
    local_50 = CreateCompatibleDC(param_4);
    h = CreateDIBSection(local_50,&local_2c,0,&local_58,(HANDLE)0x0,0);
    hdcSrc = local_50;
    param_3 = cx;
    if ((cx & 1) != 0) {
      param_3 = cx + 1;
    }
    param_10 = 0;
    param_8 = (ushort *)((int)local_58 + (iVar5 + -1) * param_3 * 2);
    puVar4 = (ushort *)
             (param_2 +
             ((iVar1 / *(int *)((int)local_54 + 0x58)) * param_7 +
             iVar6 / *(int *)((int)local_54 + 0x58)) * 2);
    param_11 = puVar4;
    if (*(char *)(DAT_0057c5c8 + 0x18) == '\0') {
      if (0 < iVar5) {
        param_5 = iVar5;
        do {
          iVar6 = 0;
          if (0 < (int)cx) {
            uVar3 = cx;
            puVar2 = param_8;
            do {
              iVar6 = iVar6 + 1;
              *puVar2 = *puVar4;
              if (*(int *)((int)local_54 + 0x58) <= iVar6) {
                iVar6 = 0;
                puVar4 = puVar4 + 1;
              }
              puVar2 = puVar2 + 1;
              uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
            puVar4 = param_11;
          }
          param_8 = param_8 + -param_3;
          param_10 = param_10 + 1;
          if (*(int *)((int)local_54 + 0x58) <= param_10) {
            param_10 = 0;
            puVar4 = puVar4 + param_7;
            param_11 = puVar4;
          }
          param_5 = param_5 + -1;
        } while (param_5 != 0);
      }
    }
    else if (0 < iVar5) {
      param_2 = iVar5;
      do {
        iVar6 = 0;
        if (0 < (int)cx) {
          uVar3 = cx;
          puVar2 = param_8;
          do {
            iVar6 = iVar6 + 1;
            *puVar2 = *puVar4 >> 1 & 0x7fe0 | *puVar4 & 0x1f;
            if (*(int *)((int)local_54 + 0x58) <= iVar6) {
              iVar6 = 0;
              puVar4 = puVar4 + 1;
            }
            puVar2 = puVar2 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
          puVar4 = param_11;
        }
        param_8 = param_8 + -param_3;
        param_10 = param_10 + 1;
        if (*(int *)((int)local_54 + 0x58) <= param_10) {
          param_10 = 0;
          puVar4 = puVar4 + param_7;
          param_11 = puVar4;
        }
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    h_00 = SelectObject(local_50,h);
    if (h_00 == (HGDIOBJ)0x0) {
      NoOp_Stub();
    }
    BitBlt(param_4,local_3c,local_38,cx,iVar5,hdcSrc,0,0,0xcc0020);
    SelectObject(hdcSrc,h_00);
    DeleteObject(h);
    DeleteDC(hdcSrc);
    if (param_9 == (HDC)0x0) {
      ReleaseDC(param_1,param_4);
    }
  }
  return;
}

