// rea decompile_all
// name: FUN_0048d530
// address: 0x48d530
// body: available
// range: 0x48d530-0x48dff2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048d530(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  
  iVar11 = 0;
  do {
    iVar1 = FUN_00488be0(this,iVar11);
    if (iVar1 != 0) {
      puVar2 = operator_new(0x1a0);
      param_1[iVar11] = (int)puVar2;
      for (iVar3 = 0x68; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      iVar3 = 0;
      if (0 < *(int *)(iVar1 + 0x1b0)) {
        do {
          puVar2 = (undefined4 *)FUN_004017f0((void *)(iVar1 + 0x19c),iVar3,(int *)0x0);
          if ((int)((undefined4 *)param_1[iVar11])[0x48] < (int)puVar2[0x48]) {
            *(undefined4 *)param_1[iVar11] = *puVar2;
            *(undefined4 *)(param_1[iVar11] + 4) = puVar2[1];
            *(undefined4 *)(param_1[iVar11] + 0x120) = puVar2[0x48];
          }
          if (*(int *)(param_1[iVar11] + 0x124) < (int)puVar2[0x49]) {
            *(undefined4 *)(param_1[iVar11] + 8) = puVar2[2];
            *(undefined4 *)(param_1[iVar11] + 0xc) = puVar2[3];
            *(undefined4 *)(param_1[iVar11] + 0x124) = puVar2[0x49];
          }
          if (*(int *)(param_1[iVar11] + 0x128) < (int)puVar2[0x4a]) {
            *(undefined4 *)(param_1[iVar11] + 0x10) = puVar2[4];
            *(undefined4 *)(param_1[iVar11] + 0x14) = puVar2[5];
            *(undefined4 *)(param_1[iVar11] + 0x128) = puVar2[0x4a];
          }
          if (*(int *)(param_1[iVar11] + 300) < (int)puVar2[0x4b]) {
            *(undefined4 *)(param_1[iVar11] + 0x18) = puVar2[6];
            *(undefined4 *)(param_1[iVar11] + 0x1c) = puVar2[7];
            *(undefined4 *)(param_1[iVar11] + 300) = puVar2[0x4b];
          }
          if (*(int *)(param_1[iVar11] + 0x130) < (int)puVar2[0x4c]) {
            *(undefined4 *)(param_1[iVar11] + 0x20) = puVar2[8];
            *(undefined4 *)(param_1[iVar11] + 0x24) = puVar2[9];
            *(undefined4 *)(param_1[iVar11] + 0x130) = puVar2[0x4c];
          }
          if (*(int *)(param_1[iVar11] + 0x134) < (int)puVar2[0x4d]) {
            *(undefined4 *)(param_1[iVar11] + 0x28) = puVar2[10];
            *(undefined4 *)(param_1[iVar11] + 0x2c) = puVar2[0xb];
            *(undefined4 *)(param_1[iVar11] + 0x134) = puVar2[0x4d];
          }
          if (*(int *)(param_1[iVar11] + 0x138) < (int)puVar2[0x4e]) {
            *(undefined4 *)(param_1[iVar11] + 0x30) = puVar2[0xc];
            *(undefined4 *)(param_1[iVar11] + 0x34) = puVar2[0xd];
            *(undefined4 *)(param_1[iVar11] + 0x138) = puVar2[0x4e];
          }
          if (*(int *)(param_1[iVar11] + 0x13c) < (int)puVar2[0x4f]) {
            *(undefined4 *)(param_1[iVar11] + 0x38) = puVar2[0xe];
            *(undefined4 *)(param_1[iVar11] + 0x3c) = puVar2[0xf];
            *(undefined4 *)(param_1[iVar11] + 0x13c) = puVar2[0x4f];
          }
          if (*(int *)(param_1[iVar11] + 0x150) < (int)puVar2[0x54]) {
            *(undefined4 *)(param_1[iVar11] + 0xdc) = puVar2[0x37];
            *(undefined4 *)(param_1[iVar11] + 0xe0) = puVar2[0x38];
            *(undefined4 *)(param_1[iVar11] + 0x150) = puVar2[0x54];
          }
          if (*(int *)(param_1[iVar11] + 0x154) < (int)puVar2[0x55]) {
            *(undefined4 *)(param_1[iVar11] + 0xe4) = puVar2[0x39];
            *(undefined4 *)(param_1[iVar11] + 0xe8) = puVar2[0x3a];
            *(undefined4 *)(param_1[iVar11] + 0x154) = puVar2[0x55];
          }
          if (*(int *)(param_1[iVar11] + 0x158) < (int)puVar2[0x56]) {
            *(undefined4 *)(param_1[iVar11] + 0xec) = puVar2[0x3b];
            *(undefined4 *)(param_1[iVar11] + 0xf0) = puVar2[0x3c];
            *(undefined4 *)(param_1[iVar11] + 0x158) = puVar2[0x56];
          }
          if (*(int *)(param_1[iVar11] + 0x15c) < (int)puVar2[0x57]) {
            *(undefined4 *)(param_1[iVar11] + 0xf4) = puVar2[0x3d];
            *(undefined4 *)(param_1[iVar11] + 0xf8) = puVar2[0x3e];
            *(undefined4 *)(param_1[iVar11] + 0x15c) = puVar2[0x57];
          }
          if (*(int *)(param_1[iVar11] + 0x40) < (int)puVar2[0x10]) {
            *(undefined4 *)(param_1[iVar11] + 0x40) = puVar2[0x10];
          }
          if (*(int *)(param_1[iVar11] + 0x44) < (int)puVar2[0x11]) {
            *(undefined4 *)(param_1[iVar11] + 0x44) = puVar2[0x11];
          }
          if (*(int *)(param_1[iVar11] + 0x48) < (int)puVar2[0x12]) {
            *(undefined4 *)(param_1[iVar11] + 0x48) = puVar2[0x12];
          }
          if (*(int *)(param_1[iVar11] + 0x4c) < (int)puVar2[0x13]) {
            *(undefined4 *)(param_1[iVar11] + 0x4c) = puVar2[0x13];
          }
          if (*(int *)(param_1[iVar11] + 0x58) < (int)puVar2[0x16]) {
            *(undefined4 *)(param_1[iVar11] + 0x58) = puVar2[0x16];
          }
          if (*(int *)(param_1[iVar11] + 0x5c) < (int)puVar2[0x17]) {
            *(undefined4 *)(param_1[iVar11] + 0x5c) = puVar2[0x17];
          }
          if (*(int *)(param_1[iVar11] + 0x50) < (int)puVar2[0x14]) {
            *(undefined4 *)(param_1[iVar11] + 0x50) = puVar2[0x14];
          }
          if (*(int *)(param_1[iVar11] + 0x54) < (int)puVar2[0x15]) {
            *(undefined4 *)(param_1[iVar11] + 0x54) = puVar2[0x15];
          }
          if (*(int *)(param_1[iVar11] + 0x60) < (int)puVar2[0x18]) {
            *(undefined4 *)(param_1[iVar11] + 0x60) = puVar2[0x18];
          }
          if (*(int *)(param_1[iVar11] + 100) < (int)puVar2[0x19]) {
            *(undefined4 *)(param_1[iVar11] + 100) = puVar2[0x19];
          }
          if (*(int *)(param_1[iVar11] + 0x68) < (int)puVar2[0x1a]) {
            *(undefined4 *)(param_1[iVar11] + 0x68) = puVar2[0x1a];
          }
          if (*(int *)(param_1[iVar11] + 0x6c) < (int)puVar2[0x1b]) {
            *(undefined4 *)(param_1[iVar11] + 0x6c) = puVar2[0x1b];
          }
          if (*(int *)(param_1[iVar11] + 0x70) < (int)puVar2[0x1c]) {
            *(undefined4 *)(param_1[iVar11] + 0x70) = puVar2[0x1c];
          }
          if (*(int *)(param_1[iVar11] + 0x74) < (int)puVar2[0x1d]) {
            *(undefined4 *)(param_1[iVar11] + 0x74) = puVar2[0x1d];
          }
          if (*(int *)(param_1[iVar11] + 0x19c) < (int)puVar2[0x67]) {
            *(undefined4 *)(param_1[iVar11] + 0x19c) = puVar2[0x67];
            *(undefined4 *)(param_1[iVar11] + 0x78) = puVar2[0x1e];
          }
          if (*(int *)(param_1[iVar11] + 0x7c) < (int)puVar2[0x1f]) {
            *(undefined4 *)(param_1[iVar11] + 0x7c) = puVar2[0x1f];
          }
          if (*(int *)(param_1[iVar11] + 0x80) < (int)puVar2[0x20]) {
            *(undefined4 *)(param_1[iVar11] + 0x80) = puVar2[0x20];
          }
          if (*(int *)(param_1[iVar11] + 0x84) < (int)puVar2[0x21]) {
            *(undefined4 *)(param_1[iVar11] + 0x84) = puVar2[0x21];
          }
          if (*(int *)(param_1[iVar11] + 0x88) < (int)puVar2[0x22]) {
            *(undefined4 *)(param_1[iVar11] + 0x88) = puVar2[0x22];
          }
          if (*(int *)(param_1[iVar11] + 0x8c) < (int)puVar2[0x23]) {
            *(undefined4 *)(param_1[iVar11] + 0x8c) = puVar2[0x23];
          }
          if (*(int *)(param_1[iVar11] + 0x90) < (int)puVar2[0x24]) {
            *(undefined4 *)(param_1[iVar11] + 0x90) = puVar2[0x24];
          }
          if (*(int *)(param_1[iVar11] + 0x94) < (int)puVar2[0x25]) {
            *(undefined4 *)(param_1[iVar11] + 0x94) = puVar2[0x25];
          }
          if (*(int *)(param_1[iVar11] + 0x98) < (int)puVar2[0x26]) {
            *(undefined4 *)(param_1[iVar11] + 0x98) = puVar2[0x26];
          }
          if (*(int *)(param_1[iVar11] + 0x9c) < (int)puVar2[0x27]) {
            *(undefined4 *)(param_1[iVar11] + 0x9c) = puVar2[0x27];
          }
          if (*(int *)(param_1[iVar11] + 0xa0) < (int)puVar2[0x28]) {
            *(undefined4 *)(param_1[iVar11] + 0xa0) = puVar2[0x28];
          }
          if (*(int *)(param_1[iVar11] + 0x174) < (int)puVar2[0x5d]) {
            *(undefined4 *)(param_1[iVar11] + 0x174) = puVar2[0x5d];
            *(undefined4 *)(param_1[iVar11] + 0xa4) = puVar2[0x29];
            *(undefined4 *)(param_1[iVar11] + 0xa8) = puVar2[0x2a];
          }
          if (*(int *)(param_1[iVar11] + 0x178) < (int)puVar2[0x5e]) {
            *(undefined4 *)(param_1[iVar11] + 0x178) = puVar2[0x5e];
            *(undefined4 *)(param_1[iVar11] + 0xac) = puVar2[0x2b];
            *(undefined4 *)(param_1[iVar11] + 0xb0) = puVar2[0x2c];
          }
          if (*(int *)(param_1[iVar11] + 0x17c) < (int)puVar2[0x5f]) {
            *(undefined4 *)(param_1[iVar11] + 0x17c) = puVar2[0x5f];
            *(undefined4 *)(param_1[iVar11] + 0xb4) = puVar2[0x2d];
            *(undefined4 *)(param_1[iVar11] + 0xb8) = puVar2[0x2e];
          }
          if (*(int *)(param_1[iVar11] + 0xbc) < (int)puVar2[0x2f]) {
            *(undefined4 *)(param_1[iVar11] + 0xbc) = puVar2[0x2f];
          }
          if (*(int *)(param_1[iVar11] + 0xc0) < (int)puVar2[0x30]) {
            *(undefined4 *)(param_1[iVar11] + 0xc0) = puVar2[0x30];
          }
          if (*(int *)(param_1[iVar11] + 0xc4) < (int)puVar2[0x31]) {
            *(undefined4 *)(param_1[iVar11] + 0xc4) = puVar2[0x31];
          }
          if (*(int *)(param_1[iVar11] + 200) < (int)puVar2[0x32]) {
            *(undefined4 *)(param_1[iVar11] + 200) = puVar2[0x32];
          }
          if (*(int *)(param_1[iVar11] + 0xcc) < (int)puVar2[0x33]) {
            *(undefined4 *)(param_1[iVar11] + 0xcc) = puVar2[0x33];
          }
          if (*(int *)(param_1[iVar11] + 0xd0) < (int)puVar2[0x34]) {
            *(undefined4 *)(param_1[iVar11] + 0xd0) = puVar2[0x34];
          }
          if (*(int *)(param_1[iVar11] + 0xd4) < (int)puVar2[0x35]) {
            *(undefined4 *)(param_1[iVar11] + 0xd4) = puVar2[0x35];
          }
          if (*(int *)(param_1[iVar11] + 0xd8) < (int)puVar2[0x36]) {
            *(undefined4 *)(param_1[iVar11] + 0xd8) = puVar2[0x36];
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(iVar1 + 0x1b0));
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 6);
  iVar11 = 0;
  piVar12 = param_1;
  do {
    iVar1 = FUN_00488be0(this,iVar11);
    if (iVar1 != 0) {
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x11,iVar11);
      *(int *)(iVar1 + 0x140) = *(int *)(iVar1 + 0x40) + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x13,iVar11);
      *(int *)(iVar1 + 0x144) = *(int *)(iVar1 + 0x48) + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x15,iVar11);
      *(int *)(iVar1 + 0x148) = *(int *)(iVar1 + 0x50) + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x17,iVar11);
      *(int *)(iVar1 + 0x14c) = *(int *)(iVar1 + 0x58) + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x19,iVar11);
      *(int *)(iVar1 + 400) = *(int *)(iVar1 + 0x60) / 100 + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x1b,iVar11);
      *(int *)(iVar1 + 0x194) = *(int *)(iVar1 + 0x68) / 10 + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x1d,iVar11);
      *(int *)(iVar1 + 0x198) = (*(int *)(iVar1 + 0x70) + iVar3 * 10) * 500;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x20,iVar11);
      *(int *)(iVar1 + 0x160) = (*(int *)(iVar1 + 0x7c) << 1) / 5 + iVar3 * 5000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x22,iVar11);
      *(int *)(iVar1 + 0x164) = (*(int *)(iVar1 + 0x84) + iVar3 * 500) * 10;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x24,iVar11);
      *(int *)(iVar1 + 0x168) = (*(int *)(iVar1 + 0x8c) + iVar3 * 500) * 10;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x26,iVar11);
      *(int *)(iVar1 + 0x16c) = (*(int *)(iVar1 + 0x94) + iVar3 * 0x32) * 100;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x30,iVar11);
      *(int *)(iVar1 + 0x180) = (*(int *)(iVar1 + 0xbc) + iVar3 * 0x32) * 100;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x32,iVar11);
      *(int *)(iVar1 + 0x184) = (*(int *)(iVar1 + 0xc4) + iVar3 * 0x32) * 100;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x34,iVar11);
      *(int *)(iVar1 + 0x188) = (*(int *)(iVar1 + 0xcc) + iVar3 * 0x32) * 100;
      *(int *)(*piVar12 + 0x18c) = *(int *)(*piVar12 + 0xd4) * 10000;
      iVar1 = *piVar12;
      iVar3 = FUN_0048e000(this,param_1,0x28,iVar11);
      *(int *)(iVar1 + 0x170) = iVar3 * *(int *)(iVar1 + 0x9c) * 500;
    }
    iVar11 = iVar11 + 1;
    piVar12 = piVar12 + 1;
  } while (iVar11 < 6);
  iVar11 = 0;
  do {
    iVar1 = FUN_00488be0(this,iVar11);
    if (iVar1 != 0) {
      iVar1 = *param_1;
      iVar3 = *(int *)(iVar1 + 300) + *(int *)(iVar1 + 0x128) + *(int *)(iVar1 + 0x124) +
              *(int *)(iVar1 + 0x120);
      *(int *)(iVar1 + 0xfc) = iVar3;
      iVar1 = *param_1;
      iVar4 = *(int *)(iVar1 + 0x14c) + *(int *)(iVar1 + 0x148) + *(int *)(iVar1 + 0x144) +
              *(int *)(iVar1 + 0x140);
      *(int *)(iVar1 + 0x100) = iVar4;
      iVar1 = *param_1;
      iVar5 = *(int *)(iVar1 + 0x17c) + *(int *)(iVar1 + 0x178) + *(int *)(iVar1 + 0x174) +
              *(int *)(iVar1 + 0x170);
      *(int *)(iVar1 + 0x104) = iVar5;
      iVar1 = *param_1;
      iVar6 = *(int *)(iVar1 + 0x19c) + *(int *)(iVar1 + 0x198) + *(int *)(iVar1 + 0x194) +
              *(int *)(iVar1 + 400);
      *(int *)(iVar1 + 0x108) = iVar6;
      iVar1 = *param_1;
      iVar7 = *(int *)(iVar1 + 0x16c) + *(int *)(iVar1 + 0x168) + *(int *)(iVar1 + 0x164) +
              *(int *)(iVar1 + 0x160);
      *(int *)(iVar1 + 0x10c) = iVar7;
      iVar1 = *param_1;
      iVar8 = *(int *)(iVar1 + 0x15c) + *(int *)(iVar1 + 0x158) + *(int *)(iVar1 + 0x154) +
              *(int *)(iVar1 + 0x150);
      *(int *)(iVar1 + 0x110) = iVar8;
      iVar1 = *param_1;
      iVar9 = *(int *)(iVar1 + 0x13c) + *(int *)(iVar1 + 0x138) + *(int *)(iVar1 + 0x134) +
              *(int *)(iVar1 + 0x130);
      *(int *)(iVar1 + 0x114) = iVar9;
      iVar1 = *param_1;
      iVar10 = *(int *)(iVar1 + 0x18c) + *(int *)(iVar1 + 0x188) + *(int *)(iVar1 + 0x184) +
               *(int *)(iVar1 + 0x180);
      *(int *)(iVar1 + 0x118) = iVar10;
      *(int *)(*param_1 + 0x11c) = iVar10 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9;
    }
    iVar11 = iVar11 + 1;
    param_1 = param_1 + 1;
  } while (iVar11 < 6);
  return;
}

