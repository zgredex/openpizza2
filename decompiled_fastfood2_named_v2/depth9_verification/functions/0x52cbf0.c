// rea decompile_all
// name: FUN_0052cbf0
// address: 0x52cbf0
// body: available
// range: 0x52cbf0-0x52cfa6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0052cbf0(void *this,void *param_1,void *param_2)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar4;
  int iVar5;
  void *this_00;
  int iVar6;
  uint uVar7;
  int local_3c;
  void *local_38;
  int local_34;
  void *local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  int local_4;
  
  iVar6 = 0;
  this_00 = *(void **)((int)this + 0x54);
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(void **)(*(int *)((int)this + 0x88) + 0xc) = this_00;
  local_24 = 0;
  local_38 = this;
  if (param_1 == (void *)0x0) {
    local_3c = *(int *)((int)this + 0x38);
    local_34 = *(int *)((int)this + 0x3c);
    local_2c = *(uint *)((int)this + 0x6c);
  }
  else {
    FUN_005355b0(this_00,&local_3c,&local_34);
    local_2c = *(uint *)((int)this_00 + 0x9c4);
  }
  local_1c = FUN_00535510((int)this_00);
  local_28 = local_34 - *(int *)((int)this + 0x60);
  local_4 = local_3c;
  do {
    local_10 = 0;
    local_14 = 0;
    local_30 = (void *)0x0;
    local_3c = local_4;
    local_34 = local_28;
    local_18 = FUN_0052cfb0(this,param_2,this_00,iVar6,&local_20,&local_2c,&local_30);
    if (local_30 == (void *)0x0) {
      local_30 = this_00;
    }
    local_8 = *(int *)((int)local_30 + 0x9b0);
    iVar5 = (local_8 - *(int *)((int)local_30 + 0x9b4)) + local_34;
    if (local_2c == 2) {
      iVar4 = (int)((int)*(short *)((int)local_38 + 100) - local_20) >> 1;
LAB_0052ccfe:
      local_3c = local_3c + iVar4;
    }
    else if (local_2c == 1) {
      iVar4 = (int)*(short *)((int)local_38 + 100) - local_20;
      goto LAB_0052ccfe;
    }
    if (*(int *)((int)local_38 + 0x80) != 0) {
      if (*(int *)((int)local_38 + 0x84) == 0) {
        if (param_1 != (void *)0x0) {
          iVar4 = *(int *)(*(int *)((int)local_38 + 0x88) + 8);
          FUN_0052d1c0(param_1,iVar4 + local_3c,*(int *)((int)this_00 + 0x9b0) / 2 + local_34,iVar4,
                       *(uint *)(*(int *)((int)local_38 + 0x88) + 4));
        }
        *(undefined4 *)((int)local_38 + 0x84) = 1;
      }
      local_3c = local_3c + **(int **)((int)local_38 + 0x88);
    }
    iVar4 = (*(int *)((int)local_30 + 0x9b4) - *(int *)((int)this_00 + 0x9b4)) + iVar5;
    local_34 = iVar4;
    if (iVar6 < local_18) {
      do {
        cVar1 = *(char *)(iVar6 + (int)param_2);
        local_c = CONCAT31(local_c._1_3_,cVar1);
        uVar7 = local_c;
        if (cVar1 == '\x01') {
          cVar1 = *(char *)(iVar6 + 2 + (int)param_2);
          if (cVar1 == '\0') {
            bVar2 = *(byte *)(iVar6 + 3 + (int)param_2);
            if ((!(bVar2 == 9 || bVar2 < 9)) ||
               (this_00 = *(void **)(*(int *)((int)local_38 + 0x88) + 0xc + (uint)bVar2 * 4),
               this_00 == (void *)0x0)) {
              this_00 = *(void **)(*(int *)((int)local_38 + 0x88) + 0xc);
            }
            FUN_00535500(this_00,local_1c);
            iVar4 = (*(int *)((int)local_30 + 0x9b4) - *(int *)((int)this_00 + 0x9b4)) + iVar5;
            local_34 = iVar4;
          }
          else if (cVar1 == '\x01') {
            local_1c = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 5 + (int)param_2),
                                               *(undefined1 *)(iVar6 + 4 + (int)param_2)),
                                      *(undefined1 *)(iVar6 + 3 + (int)param_2));
            FUN_00535500(this_00,local_1c);
            iVar4 = local_34;
          }
          else if (cVar1 == '\x05') {
            if (local_18 <= (int)(*(byte *)(iVar6 + 1 + (int)param_2) + 2 + iVar6)) {
              if (param_1 != (void *)0x0) {
                FUN_005355d0(this_00,local_3c,iVar4);
                FUN_00535800(this_00,param_1,'-');
              }
              uVar3 = FUN_00535650(this_00,0x2d);
              local_3c = local_3c + CONCAT31(extraout_var,uVar3);
              iVar4 = local_34;
            }
          }
          local_14 = 1;
          iVar6 = iVar6 + 1 + (uint)*(byte *)(iVar6 + 1 + (int)param_2);
        }
        else {
          local_10 = 1;
          uVar3 = FUN_00535650(this_00,local_c);
          if (CONCAT31(extraout_var_00,uVar3) == 0) {
            uVar7 = 0x20;
          }
          else if (param_1 != (void *)0x0) {
            FUN_005355d0(this_00,local_3c,local_34);
            FUN_00535800(this_00,param_1,cVar1);
          }
          uVar3 = FUN_00535650(this_00,uVar7);
          local_3c = local_3c + CONCAT31(extraout_var_01,uVar3);
          iVar4 = local_34;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < local_18);
    }
    if (*(char *)(iVar6 + (int)param_2) == '\0') {
LAB_0052cf90:
      return local_24 + *(int *)((int)this_00 + 0x9b0) * 2;
    }
    if ((local_14 == 0) || (local_10 != 0)) {
      local_28 = local_28 + local_8;
      local_24 = local_24 + local_8;
    }
    if (*(byte *)(iVar6 + (int)param_2) < 0x21) {
      if (*(byte *)(iVar6 + (int)param_2) == 0xd) {
        *(undefined4 *)((int)local_38 + 0x80) = 0;
        *(undefined4 *)((int)local_38 + 0x84) = 0;
        local_2c = 0;
      }
      iVar6 = iVar6 + 1;
    }
    if (*(char *)(iVar6 + (int)param_2) == '\n') {
      iVar6 = iVar6 + 1;
    }
    if (*(char *)(iVar6 + (int)param_2) == '\0') goto LAB_0052cf90;
    this = local_38;
  } while( true );
}

