// rea decompile_all
// name: AI_CheckBranchGuards
// address: 0x4fe040
// body: available
// range: 0x4fe040-0x4fe2f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_CheckBranchGuards(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  int local_78;
  int local_6c;
  int *local_68;
  int local_60;
  int *local_5c;
  int local_50 [20];
  
                    /* Balances guards across a player's branches. */
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  iVar1 = FUN_004e2280((int)this_00);
  if (1 < iVar1) {
    iVar1 = *(int *)((int)this_00 + 100);
    if ((iVar1 < 3) && (iVar2 = FUN_004e2280((int)this_00), 0 < (iVar2 - iVar1) + -1)) {
      FUN_004e3660((int)this_00);
    }
    iVar1 = 0;
    local_6c = 0;
    iVar2 = FUN_00482720((int)DAT_0057c670);
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        pvVar3 = (void *)FUN_00488be0(DAT_0057c670,iVar7);
        if ((pvVar3 != this_00) && (iVar4 = FUN_004e2280((int)this_00), iVar1 <= iVar4)) {
          iVar1 = FUN_004e2280((int)this_00);
          local_6c = iVar1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
      if (1 < iVar1) {
        iVar2 = 0;
        local_68 = (int *)0x0;
        local_60 = (int)*(short *)((int)this + param_1 * 0x168 + 0x130) / 0x28 + 1;
        if ((iVar1 == 5) && (local_60 < 2)) {
          local_60 = 2;
        }
        iVar7 = *(int *)((int)this_00 + 0x15c);
        local_78 = 0;
        if (0 < iVar7) {
          local_5c = local_50;
          do {
            iVar1 = FUN_004017f0((void *)((int)this_00 + 0x148),local_78,(int *)0x0);
            iVar4 = 0;
            iVar2 = 0;
            uVar6 = (uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10);
            do {
              uVar6 = uVar6 - 1;
              if ((int)uVar6 < 0) break;
              FUN_00477fe0(iVar1,-1,-1,uVar6);
              iVar4 = iVar4 + 1;
              iVar2 = iVar2 + 1;
            } while (iVar2 < 4);
            if (iVar4 < 1) {
              iVar1 = 1;
            }
            else {
              lVar8 = __ftol();
              iVar1 = (int)lVar8 + 1;
              if (local_60 < iVar1) {
                iVar1 = local_60;
              }
            }
            iVar2 = (int)local_68 + iVar1;
            *local_5c = iVar1;
            local_5c = local_5c + 1;
            local_78 = local_78 + 1;
            local_68 = (int *)iVar2;
          } while (local_78 < iVar7);
          iVar1 = local_6c;
        }
        iVar7 = 0;
        if (iVar1 == 5) {
          iVar7 = 2;
        }
        else if (iVar1 == 6) {
          iVar7 = 4;
        }
        iVar1 = FUN_004e1d40(this_00,0x17);
        while ((iVar1 < iVar2 + iVar7 && (iVar4 = Company_HireFreeGuard(this_00), iVar4 != 0))) {
          iVar1 = iVar1 + 1;
        }
        iVar1 = *(int *)((int)this_00 + 0x15c);
        local_78 = 0;
        if (0 < iVar1) {
          local_68 = local_50;
          do {
            iVar4 = FUN_004017f0((void *)((int)this_00 + 0x148),local_78,(int *)0x0);
            iVar2 = *local_68;
            iVar5 = FUN_004e2750(this_00,iVar4,0x17);
            iVar7 = iVar5 - iVar2;
            if (iVar2 < iVar5) {
              do {
                iVar7 = Company_AssignStaffToBranch(this_00,iVar4);
                if (iVar7 == 0) break;
                iVar5 = iVar5 + -1;
              } while (iVar2 < iVar5);
              iVar7 = iVar5 - iVar2;
            }
            if (SBORROW4(iVar5,iVar2) != iVar7 < 0) {
              do {
                iVar7 = Company_DispatchWorkerToBranch((int)this_00,iVar4);
                if (iVar7 == 0) break;
                iVar5 = iVar5 + 1;
              } while (iVar5 < iVar2);
            }
            local_78 = local_78 + 1;
            local_68 = local_68 + 1;
          } while (local_78 < iVar1);
        }
        if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
          FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18610,0x23,0);
        }
      }
    }
  }
  return 1;
}

