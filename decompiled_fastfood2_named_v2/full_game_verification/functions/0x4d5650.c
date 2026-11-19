// rea decompile_all
// name: City_InitBuildings
// address: 0x4d5650
// body: available
// range: 0x4d5650-0x4d5939 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall City_InitBuildings(int param_1)

{
  int *piVar1;
  void *this;
  void **ppvVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *this_00;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558fbb;
  local_c = ExceptionList;
  this = *(void **)(param_1 + 0xfa8);
  if (this != (void *)0x0) {
    iVar5 = *(int *)((int)this + 0x20);
    iVar6 = *(int *)((int)this + 0x1c);
    local_40 = 0;
    ExceptionList = &local_c;
    ppvVar2 = &local_c;
    local_3c = param_1;
    local_18 = iVar6;
    local_14 = iVar5;
    if (0 < iVar5) {
      do {
        local_38 = 0;
        if (0 < iVar6) {
          do {
            iVar5 = local_38;
            piVar3 = (int *)Grid_GetCell(this,local_38,local_40);
            if (((piVar3 != (int *)0x0) && (piVar3[2] != 0)) &&
               (local_2c = *(int *)(piVar3[2] + 0x10), -1 < local_2c)) {
              iVar6 = 0;
              local_4c = 0;
              if (DAT_0056cb48 != -1) {
                piVar4 = &DAT_0056cb50;
                do {
                  if ((piVar4[-1] <= local_2c) && (local_2c <= *piVar4)) break;
                  iVar6 = iVar6 + 3;
                  piVar1 = piVar4 + 1;
                  piVar4 = piVar4 + 3;
                } while (*piVar1 != -1);
                local_4c = iVar6;
              }
              if ((&DAT_0056cb48)[local_4c] != -1) {
                UI_AlignSpriteToObject(this,piVar3,&local_44,&local_48,&local_24,&local_28);
                local_44 = local_44 + *(int *)((int)this + 0x24);
                local_48 = local_48 + *(int *)((int)this + 0x28);
                local_10 = operator_new(0x9c);
                this_00 = (undefined4 *)0x0;
                local_4 = 0;
                if (local_10 != (void *)0x0) {
                  this_00 = MapObject_Construct(local_10,(void *)0x0);
                }
                local_4 = 0xffffffff;
                this_00[1] = (&DAT_0056cb48)[local_4c];
                Entity_ApplyTypeProperties(this_00,local_2c);
                iVar5 = this_00[0x12];
                if ((iVar5 < 0) || (3 < iVar5)) {
                  iVar6 = iVar5;
                }
                else {
                  iVar6 = *(int *)(&DAT_00568188 + iVar5 * 4);
                }
                if ((((iVar6 == -1) || (iVar6 = (&DAT_0056cb48)[local_4c], iVar6 == 0x20)) ||
                    (iVar6 == 5)) || (iVar6 == 6)) {
                  piVar4 = piVar3;
                }
                else {
                  piVar4 = (int *)Grid_GetNeighborCell(this,(int)piVar3,iVar5);
                }
                SetRect((LPRECT)(this_00 + 4),local_44,local_48,local_24 + local_44,
                        local_48 + local_28);
                Entity_SetTileId(this_00,(uint)*(ushort *)piVar3[2]);
                this_00[10] = *(undefined4 *)(local_3c + 0xc1c);
                Object_SetMarketValueByType((int)this_00);
                if ((&DAT_0056cb48)[local_4c] == 0xb) {
                  UI_ComputeCenteredRect(this,piVar3,&local_30,&local_34);
                }
                UI_ComputeCenteredRect(this,piVar4,&local_1c,&local_20);
                if (this_00[0x12] != -1) {
                  iVar5 = Map_ConnectCellToStreetGraph
                                    (this,local_1c - *(int *)((int)this + 0x24),
                                     local_20 - *(int *)((int)this + 0x28),this_00[0x12]);
                  Map_AssignObjectToCell(this_00,iVar5);
                  iVar5 = Array_GetRecord28(this,1,this_00[0x15]);
                  if (iVar5 == 0) {
                    Debug_WarningMessageBox();
                  }
                  iVar5 = Array_GetRecord28(this,1,this_00[0x15]);
                  Grid_CollectNearbyIds(this,this_00 + 0x16,iVar5,10,0xfa);
                }
                if ((&DAT_0056cb48)[local_4c] == 0x1b) {
                  BuildingValue_CreateDefault(this_00,3);
                }
                List_Add((void *)(local_3c + 0xfac),this_00);
                iVar5 = local_38;
              }
            }
            local_38 = iVar5 + 1;
          } while (local_38 < local_18);
          iVar6 = local_18;
          iVar5 = local_14;
        }
        local_40 = local_40 + 1;
        ppvVar2 = ExceptionList;
      } while (local_40 < iVar5);
    }
    ExceptionList = ppvVar2;
    Rect_Center(&local_30,&local_34);
    Map_SetScrollPosition(this,local_30,local_34);
  }
  ExceptionList = local_c;
  return;
}

