// rea decompile_all
// name: FUN_00537f20
// address: 0x537f20
// body: available
// range: 0x537f20-0x53877e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00537f20(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  HWND pHVar4;
  HDC hdc;
  undefined4 *puVar5;
  undefined4 *puStack_b0;
  undefined4 uStack_ac;
  int *piStack_a8;
  undefined4 *puStack_a4;
  undefined4 *puStack_a0;
  undefined1 auStack_8a [2];
  undefined4 auStack_88 [2];
  int *piStack_40;
  int *piStack_34;
  int *piStack_24;
  int *piStack_14;
  undefined4 *puStack_8;
  
  auStack_88[1] = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x40);
  iVar3 = DirectDrawCreate();
  if (iVar3 != 0) {
    *puStack_8 = 200;
    return;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    pHVar4 = GetDesktopWindow();
    hdc = GetDC(pHVar4);
    puStack_a0 = (undefined4 *)0x53844b;
    GetDeviceCaps(hdc,8);
    puStack_a0 = (undefined4 *)0x538454;
    GetDeviceCaps(hdc,10);
    puStack_a0 = (undefined4 *)0x53845d;
    iVar3 = GetDeviceCaps(hdc,0xc);
    pHVar4 = GetDesktopWindow();
    puStack_a0 = (undefined4 *)0x538469;
    ReleaseDC(pHVar4,hdc);
    if (iVar3 != 0x10) {
      (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x40) + 0x50))();
      piStack_a8 = (int *)**(undefined4 **)(param_1 + 0x40);
      puStack_a0 = (undefined4 *)0x0;
      uStack_ac = 0x538498;
      puStack_a4 = (undefined4 *)uVar1;
      (**(code **)(*piStack_a8 + 0x54))();
    }
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x40) + 0x50))();
    puVar5 = auStack_88;
    for (iVar3 = 0x1b; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
    }
    auStack_88[1] = 0x6c;
    piStack_a8 = (int *)**(undefined4 **)(param_1 + 0x40);
    puStack_a0 = *(undefined4 **)(param_1 + 0x40) + 1;
    puStack_a4 = auStack_88 + 1;
    uStack_ac = 0x5384e8;
    iVar3 = (**(code **)(*piStack_a8 + 0x18))();
    if (iVar3 == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x10) =
           *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
      *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xc) =
           *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
      return;
    }
    if (iVar3 < -0x7789ff1e) {
      if (iVar3 == -0x7789ff1f) {
        *piStack_24 = 0x104;
        return;
      }
      if (iVar3 < -0x7789ff7d) {
        if (iVar3 == -0x7789ff7e) {
          *piStack_24 = 0xfd;
          return;
        }
        if (iVar3 < -0x7789ffa0) {
          if (iVar3 == -0x7789ffa1) {
            *piStack_24 = 0xfb;
            return;
          }
          if (iVar3 == -0x7ff8fff2) {
            *piStack_24 = 0x108;
            return;
          }
          if (iVar3 == -0x7ff8ffa9) {
            *piStack_24 = 0xfe;
            return;
          }
        }
        else if (iVar3 == -0x7789ff9c) {
          *piStack_24 = 0xfc;
          return;
        }
      }
      else {
        if (iVar3 == -0x7789ff6f) {
          *piStack_24 = 0xff;
          return;
        }
        if (iVar3 == -0x7789ff4c) {
          *piStack_24 = 0x100;
          return;
        }
        if (iVar3 == -0x7789ff2c) {
          *piStack_24 = 0x101;
          return;
        }
      }
    }
    else if (iVar3 < -0x7789fdcb) {
      if (iVar3 == -0x7789fdcc) {
        *piStack_24 = 0x10a;
        return;
      }
      if (iVar3 < -0x7789fe83) {
        if (iVar3 == -0x7789fe84) {
          *piStack_24 = 0x109;
          return;
        }
        if (iVar3 == -0x7789ff1a) {
          *piStack_24 = 0x105;
          return;
        }
        if (iVar3 == -0x7789feac) {
          *piStack_24 = 0x107;
          return;
        }
      }
      else if (iVar3 == -0x7789fdcd) {
        *piStack_24 = 0x102;
        return;
      }
    }
    else if (iVar3 == -0x7789fdcb) {
      iVar3 = 9;
    }
    else {
      if (iVar3 == -0x7789fdb2) {
        *piStack_24 = 0x10b;
        return;
      }
      if (iVar3 == -0x7789fdb1) {
        *piStack_24 = 0x106;
        return;
      }
    }
    *piStack_24 = iVar3 + 0xfa;
    return;
  }
  iVar3 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x40) + 0x50))();
  if (iVar3 == 0) {
    piStack_a8 = (int *)**(undefined4 **)(param_1 + 0x40);
    puStack_a0 = (undefined4 *)DAT_00574738;
    puStack_a4 = (undefined4 *)DAT_00574734;
    uStack_ac = 0x538062;
    iVar3 = (**(code **)(*piStack_a8 + 0x54))();
    if (iVar3 != 0) {
      *piStack_24 = *piStack_24 + 0xd2;
      return;
    }
    uStack_ac = 0;
    puVar5 = (undefined4 *)(auStack_8a + -10);
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    piVar2 = (int *)**(undefined4 **)(param_1 + 0x40);
    puStack_b0 = *(undefined4 **)(param_1 + 0x40) + 1;
    iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,auStack_8a + -10);
    if (iVar3 == 0) {
      puStack_b0 = (undefined4 *)0x4;
      piVar2 = *(int **)(*(int *)(param_1 + 0x40) + 4);
      iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2,&puStack_b0,*(int *)(param_1 + 0x40) + 8);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x98) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x10) =
             *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
        *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xc) =
             *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
        return;
      }
      if (iVar3 < -0x7789ff7d) {
        if (iVar3 == -0x7789ff7e) {
          *piStack_40 = 0xdd;
          return;
        }
        if (iVar3 == -0x7ff8ffa9) {
          *piStack_40 = 0xde;
          return;
        }
        if (iVar3 == -0x7789ff9c) {
          *piStack_40 = 0xe1;
          return;
        }
      }
      else if (iVar3 == -0x7789ff01) {
        iVar3 = 3;
      }
      else if (iVar3 == -0x7789fe3e) {
        *piStack_40 = 0xe0;
        return;
      }
      *piStack_40 = iVar3 + 0xdc;
      return;
    }
    if (iVar3 < -0x7789ff1e) {
      if (iVar3 == -0x7789ff1f) {
        *piStack_34 = 0xdc;
        return;
      }
      if (iVar3 < -0x7789ff7d) {
        if (iVar3 == -0x7789ff7e) {
          *piStack_34 = 0xd5;
          return;
        }
        if (iVar3 < -0x7789ffa0) {
          if (iVar3 == -0x7789ffa1) {
            *piStack_34 = 0xd3;
            return;
          }
          if (iVar3 == -0x7ff8fff2) {
            *piStack_34 = 0xe0;
            return;
          }
          if (iVar3 == -0x7ff8ffa9) {
            *piStack_34 = 0xd6;
            return;
          }
        }
        else if (iVar3 == -0x7789ff9c) {
          *piStack_34 = 0xd4;
          return;
        }
      }
      else {
        if (iVar3 == -0x7789ff6f) {
          *piStack_34 = 0xd7;
          return;
        }
        if (iVar3 == -0x7789ff4c) {
          *piStack_34 = 0xd8;
          return;
        }
        if (iVar3 == -0x7789ff2c) {
          *piStack_34 = 0xd9;
          return;
        }
      }
    }
    else if (iVar3 < -0x7789fdcb) {
      if (iVar3 == -0x7789fdcc) {
        *piStack_34 = 0xe2;
        return;
      }
      if (iVar3 < -0x7789fe83) {
        if (iVar3 == -0x7789fe84) {
          *piStack_34 = 0xe1;
          return;
        }
        if (iVar3 == -0x7789ff1a) {
          *piStack_34 = 0xdd;
          return;
        }
        if (iVar3 == -0x7789feac) {
          *piStack_34 = 0xdf;
          return;
        }
      }
      else if (iVar3 == -0x7789fdcd) {
        *piStack_34 = 0xda;
        return;
      }
    }
    else if (iVar3 == -0x7789fdcb) {
      iVar3 = 9;
    }
    else {
      if (iVar3 == -0x7789fdb2) {
        *piStack_34 = 0xe3;
        return;
      }
      if (iVar3 == -0x7789fdb1) {
        *piStack_34 = 0xde;
        return;
      }
    }
    *piStack_34 = iVar3 + 0xd2;
    return;
  }
  if (iVar3 < -0x7789fdc5) {
    if (iVar3 == -0x7789fdc6) {
      *piStack_14 = 0xcb;
      return;
    }
    if (iVar3 == -0x7ff8fff2) {
      *piStack_14 = 0xce;
      return;
    }
    if (iVar3 == -0x7ff8ffa9) {
      *piStack_14 = 0xcd;
      return;
    }
    if (iVar3 == -0x7789ff7e) {
      *piStack_14 = 0xcc;
      return;
    }
  }
  else if (iVar3 == -0x7789fdc5) {
    iVar3 = 2;
  }
  else if (iVar3 == -0x7789fdbb) {
    *piStack_14 = 0xc9;
    return;
  }
  *piStack_14 = iVar3 + 200;
  return;
}

