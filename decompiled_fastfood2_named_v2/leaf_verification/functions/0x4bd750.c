// rea decompile_all
// name: FUN_004bd750
// address: 0x4bd750
// body: available
// range: 0x4bd750-0x4bde13 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bd750(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined4 uVar7;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  iVar1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*(int *)((int)DAT_0057c670 + 0x218) + 8));
  if (iVar1 != 0) {
    FUN_0052f9b0(param_1,0x51b,iVar1 + 8);
    FUN_004a66d0(param_1,0x2387,iVar1);
    iVar2 = Game_GetPlayerCity(iVar1);
    FUN_0054bb00(param_1,0x2386,*(int *)(iVar2 + 4));
    FUN_0052f9b0(param_1,0x515,iVar2 + 0xc);
    iVar4 = *(int *)(iVar2 + 0xa0);
    if (0 < iVar4) {
      do {
        iVar3 = IDMap_Lookup((void *)(iVar2 + 0x8c),iVar5,(int *)0x0);
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          local_c = local_c + 1;
        }
        else if (iVar3 == 1) {
          local_8 = local_8 + 1;
        }
        else if (iVar3 == 2) {
          local_4 = local_4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
    FUN_0052f080(param_1,0x236b,&DAT_005686f4,local_c);
    FUN_0052f080(param_1,0x236c,&DAT_005686f4,local_4);
    FUN_0052f080(param_1,0x236d,&DAT_005686f4,local_8);
    FUN_004a6680(param_1,0x2348,*(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x3c));
    FUN_004a6680(param_1,0x2349,*(int *)(iVar2 + 0x58) + *(int *)(iVar2 + 0x40));
    FUN_004a6680(param_1,0x234a,*(int *)(iVar2 + 0x5c) + *(int *)(iVar2 + 0x44));
    FUN_004a6680(param_1,0x234b,*(int *)(iVar2 + 0x60) + *(int *)(iVar2 + 0x48));
    FUN_004a6680(param_1,0x234c,*(int *)(iVar2 + 100) + *(int *)(iVar2 + 0x4c));
    FUN_004a6680(param_1,0x234d,*(int *)(iVar2 + 0x68) + *(int *)(iVar2 + 0x50));
    FUN_0052f080(param_1,0x2379,&DAT_005686f4,*(undefined4 *)(iVar1 + 0x15c));
    FUN_0052f080(param_1,0x2389,&DAT_005686f4,*(undefined4 *)(iVar1 + 0x194));
    FUN_004e09e0(iVar1,-1,-1,-1);
    lVar6 = __ftol();
    FUN_0052f080(param_1,0x237a,&DAT_005683a4,(int)lVar6);
    iVar1 = *(int *)(iVar1 + 0x48);
    iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    FUN_0052f080(param_1,0x2374,&DAT_005686f4,*(undefined4 *)(iVar5 + 0xc20 + iVar1 * 4));
    iVar5 = 0;
    this = *(void **)((int)DAT_0057c670 + 0x218);
    iVar1 = *(int *)((int)this + 0x8c);
    if (0 < iVar1) {
      do {
        iVar2 = FUN_004d2a60(this,iVar5);
        iVar4 = *(int *)(iVar2 + 0x110);
        iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
        if (iVar4 != iVar3) {
          iVar4 = *(int *)(iVar2 + 0x30);
          if (iVar4 == 0x17) {
            local_1c = local_1c + 1;
          }
          else if (iVar4 == 0x1d) {
            local_14 = local_14 + 1;
          }
          else if (iVar4 == 0x1e) {
            local_18 = local_18 + 1;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    FUN_0052f080(param_1,0x2380,&DAT_005686f4,local_1c);
    FUN_0052f080(param_1,0x2382,&DAT_005686f4,local_18);
    FUN_0052f080(param_1,0x2383,&DAT_005686f4,local_14);
    iVar1 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar5 = *(int *)(iVar1 + 0x48);
    iVar4 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar5 = *(int *)(iVar4 + 0xc20 + iVar5 * 4);
    if (*(void **)(iVar1 + 0x1d8) == (void *)0x0) {
      iVar4 = 0;
      uVar7 = 0xff;
    }
    else {
      iVar4 = FUN_004d2ae0(*(void **)(iVar1 + 0x1d8),0x1d);
      if (iVar4 == 0) {
        uVar7 = 0xff;
      }
      else {
        uVar7 = 0;
      }
    }
    FUN_0052f910(param_1,0x236f,uVar7);
    FUN_0052f080(param_1,0x236f,&DAT_005686f4,iVar4);
    uVar7 = 5000;
    iVar4 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar4 + 0x134) == 0) {
      if (*(int *)(iVar4 + 0x98) == 0) {
        if ((*(int *)(iVar4 + 0x218) != 0) || (*(int *)(iVar4 + 0x17c) != 0)) {
          uVar7 = 0x1d4c;
        }
      }
      else {
        uVar7 = 0x9c4;
      }
    }
    else {
      uVar7 = 0;
    }
    FUN_0052f080(param_1,0x235a,&DAT_0056a850,uVar7);
    iVar4 = *(int *)((int)DAT_0057c670 + 0x218);
    iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar4 = FUN_0048a130(DAT_0057c670,6,0x1d,iVar4,iVar2);
    FUN_0052f080(param_1,0x235c,&DAT_005686f4,iVar4);
    iVar4 = *(int *)((int)DAT_0057c670 + 0x218);
    iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar4 = FUN_0048a090(DAT_0057c670,6,0x1d,iVar4,iVar2);
    FUN_0052f080(param_1,0x2360,&DAT_005686f4,iVar4);
    if (*(void **)(iVar1 + 0x1d8) == (void *)0x0) {
      iVar1 = 0;
      uVar7 = 0xff;
    }
    else {
      iVar1 = FUN_004d2ae0(*(void **)(iVar1 + 0x1d8),0x1f);
      if (iVar1 == 0) {
        uVar7 = 0xff;
      }
      else {
        uVar7 = 0;
      }
    }
    FUN_0052f910(param_1,0x2372,uVar7);
    FUN_0052f080(param_1,0x2372,&DAT_005686f4,iVar1);
    uVar7 = 100000;
    iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0x158) == 0) {
      if (*(int *)(iVar1 + 0x23c) != 0) {
        uVar7 = 150000;
      }
    }
    else {
      uVar7 = 0;
    }
    FUN_0052f080(param_1,0x235e,&DAT_005683a4,uVar7);
    iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
    iVar4 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar1 = FUN_0048a130(DAT_0057c670,5,0x1f,iVar1,iVar4);
    FUN_0052f080(param_1,0x2362,&DAT_005686f4,iVar1);
    iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
    iVar4 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar1 = FUN_0048a090(DAT_0057c670,5,0x1f,iVar1,iVar4);
    FUN_0052f080(param_1,0x2364,&DAT_005686f4,iVar1);
    if (iVar5 < 5) {
      FUN_00531740(param_1,0x2357);
      FUN_00531740(param_1,0x236f);
      FUN_00531740(param_1,0x235a);
      FUN_00531740(param_1,0x235c);
      FUN_00531740(param_1,0x2360);
      FUN_00531740(param_1,0x236e);
      FUN_00531740(param_1,0x2359);
      FUN_00531740(param_1,0x235b);
      FUN_00531740(param_1,0x235f);
    }
    else {
      FUN_005316b0(param_1,0x2357);
      FUN_005316b0(param_1,0x236f);
      FUN_005316b0(param_1,0x235a);
      FUN_005316b0(param_1,0x235c);
      FUN_005316b0(param_1,0x2360);
      FUN_005316b0(param_1,0x236e);
      FUN_005316b0(param_1,0x2359);
      FUN_005316b0(param_1,0x235b);
      FUN_005316b0(param_1,0x235f);
    }
    if (5 < iVar5) {
      FUN_005316b0(param_1,0x2358);
      FUN_005316b0(param_1,0x2372);
      FUN_005316b0(param_1,0x235e);
      FUN_005316b0(param_1,0x2362);
      FUN_005316b0(param_1,0x2364);
      FUN_005316b0(param_1,0x2371);
      FUN_005316b0(param_1,0x235d);
      FUN_005316b0(param_1,0x2361);
      FUN_005316b0(param_1,0x2363);
      return;
    }
    FUN_00531740(param_1,0x2358);
    FUN_00531740(param_1,0x2372);
    FUN_00531740(param_1,0x235e);
    FUN_00531740(param_1,0x2362);
    FUN_00531740(param_1,0x2364);
    FUN_00531740(param_1,0x2371);
    FUN_00531740(param_1,0x235d);
    FUN_00531740(param_1,0x2361);
    FUN_00531740(param_1,0x2363);
  }
  return;
}

