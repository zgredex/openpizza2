// rea decompile_all
// name: Recipe_ImportFile
// address: 0x49ba50
// body: available
// range: 0x49ba50-0x49bd4f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __cdecl Recipe_ImportFile(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  HANDLE pvVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  void *this;
  int *this_00;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  int local_23c;
  void *local_238;
  int *local_234;
  undefined4 *local_230;
  int local_22c;
  void *local_228;
  uint local_224 [5];
  undefined1 local_210 [260];
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055874c;
  local_c = ExceptionList;
  local_23c = 0;
  ExceptionList = &local_c;
  pvVar4 = CRT_FindFirst(s_save_menu___men_00568a34,local_224);
  if (pvVar4 != (HANDLE)0xffffffff) {
    do {
      if (local_23c == param_1) {
        String_Format(local_10c,(byte *)s_save_menu__s_00568a58,local_210);
        break;
      }
      local_23c = local_23c + 1;
      iVar5 = CRT_FindNext(pvVar4,local_224);
    } while (iVar5 != -1);
    CRT_FindClose(pvVar4);
    local_228 = operator_new(0x5c);
    local_4 = 0;
    if (local_228 == (void *)0x0) {
      local_234 = (int *)0x0;
    }
    else {
      local_234 = CRT_Ifstream_Construct();
    }
    this_00 = local_234;
    local_4 = 0xffffffff;
    if ((*(byte *)(*(int *)(*local_234 + 4) + 8 + (int)local_234) & 6) == 0) {
      this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
      iVar5 = *(int *)((int)this + 0x124);
      local_238 = this;
      local_22c = iVar5;
      Game_AcquireStateLock(DAT_0057c670,0);
      CRT_Istream_Read(this_00,&DAT_0057c668,4);
      if ((0x29 < DAT_0057c668) && (DAT_0057c668 < 0x2f)) {
        UI_RemoveAllObjects(*(void **)((int)DAT_0057c670 + 0x25c));
        iVar8 = 0;
        if (0 < iVar5) {
          do {
            iVar5 = IDMap_Lookup((void *)((int)this + 0x110),iVar8,(int *)0x0);
            Recipe_SetOnMenu(this,iVar5,0);
            iVar8 = iVar8 + 1;
          } while (iVar8 < local_22c);
        }
        CRT_Istream_Read(this_00,&local_23c,4);
        local_228 = (void *)0x0;
        if (0 < local_23c) {
          do {
            local_230 = operator_new(0x330);
            local_4 = 1;
            if (local_230 == (void *)0x0) {
              local_230 = (undefined4 *)0x0;
            }
            else {
              local_230 = Recipe_Construct(local_230,this_00,'\x01');
            }
            iVar5 = 0;
            local_4 = 0xffffffff;
            if (0 < local_22c) {
              pbVar1 = (byte *)(local_230 + 1);
              do {
                puVar6 = (undefined4 *)
                         IDMap_Lookup((void *)((int)local_238 + 0x110),iVar5,(int *)0x0);
                pbVar7 = (byte *)(puVar6 + 1);
                pbVar9 = pbVar1;
                do {
                  bVar2 = *pbVar7;
                  bVar10 = bVar2 < *pbVar9;
                  if (bVar2 != *pbVar9) {
LAB_0049bc8d:
                    iVar8 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                    goto LAB_0049bc92;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pbVar7[1];
                  bVar10 = bVar2 < pbVar9[1];
                  if (bVar2 != pbVar9[1]) goto LAB_0049bc8d;
                  pbVar7 = pbVar7 + 2;
                  pbVar9 = pbVar9 + 2;
                } while (bVar2 != 0);
                iVar8 = 0;
LAB_0049bc92:
                if (iVar8 == 0) {
                  Company_RemoveRecipe(local_238,puVar6);
                  break;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < local_22c);
              this = local_238;
            }
            puVar6 = local_230;
            List_Add((void *)((int)this + 0x110),local_230);
            Recipe_SetOnMenu(this,(int)puVar6,1);
            local_228 = (void *)((int)local_228 + 1);
            this_00 = local_234;
          } while ((int)local_228 < local_23c);
        }
        uVar3 = *(uint *)(*(int *)(*this_00 + 4) + 8 + (int)this_00);
        if (this_00 != (int *)0x0) {
          (*(code *)**(undefined4 **)(*(int *)(*this_00 + 4) + (int)this_00))(1);
        }
        Company_InvalidateAllBranchRatings((int)this);
        Window_UnlockState((int)DAT_0057c670);
        ExceptionList = local_c;
        return (uVar3 & 6) == 0;
      }
      if (this_00 != (int *)0x0) {
        (*(code *)**(undefined4 **)(*(int *)(*this_00 + 4) + (int)this_00))(1);
      }
      Window_UnlockState((int)DAT_0057c670);
    }
    else if (local_234 != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*local_234 + 4) + (int)local_234))(1);
    }
  }
  ExceptionList = local_c;
  return false;
}

