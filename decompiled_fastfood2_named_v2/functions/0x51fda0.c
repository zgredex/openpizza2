// rea decompile_all
// name: FUN_0051fda0
// address: 0x51fda0
// body: available
// range: 0x51fda0-0x5205fd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0051fda0(void *this,uint param_1)

{
  double dVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  uint uVar7;
  uint *puVar8;
  undefined2 *puVar9;
  int iVar10;
  longlong lVar11;
  int iVar12;
  int iVar13;
  int local_2c;
  int local_28;
  int local_24;
  undefined2 *local_20;
  int local_1c;
  int local_10;
  int local_c;
  double local_8;
  
  if (*(int *)((int)this + 8) == 0) {
    return;
  }
  DVar2 = timeGetTime();
  local_8 = (double)(ulonglong)(DVar2 - *(int *)((int)this + 0xc));
  dVar1 = (double)(longlong)local_8;
  local_8 = (double)(ulonglong)*(uint *)((int)this + 0x10);
  local_8 = dVar1 / (double)(longlong)local_8;
  if (1.0 < local_8) {
    local_8 = 1.0;
  }
  iVar13 = *(int *)(*(int *)((int)this + 8) + 0x18);
  iVar12 = *(int *)(param_1 + 0x28);
  *(int *)((int)this + 0x1c) = *(int *)(param_1 + 0x20) << 1;
  if (*(int *)((int)this + 0x14) != 0) {
    DAT_00584164 = (uint *)(*(int *)((int)this + 0x20) / *(int *)((int)this + 0x28));
    DAT_0058416c = *(int *)((int)this + 0x24) / *(int *)((int)this + 0x28);
    DAT_00584170 = operator_new(DAT_0058416c * (int)DAT_00584164);
    DAT_00584174 = operator_new(DAT_0058416c * (int)DAT_00584164 * 4);
    iVar10 = 0;
    if (0 < (int)(DAT_0058416c * (int)DAT_00584164)) {
      do {
        iVar3 = iVar10 + 1;
        *(undefined1 *)((int)DAT_00584170 + iVar10) = 0;
        iVar10 = iVar3;
      } while (iVar3 < (int)(DAT_0058416c * (int)DAT_00584164));
    }
    FUN_0051fb50((int)this,DAT_00584174,DAT_00584164,DAT_0058416c);
    switch(*(undefined4 *)((int)this + 0x18)) {
    case 0:
    case 1:
      DAT_00584168 = *(int *)((int)this + 0x24) / *(int *)((int)this + 0x28) +
                     *(int *)((int)this + 0x28);
      break;
    case 2:
    case 3:
      DAT_00584168 = *(int *)((int)this + 0x20) / *(int *)((int)this + 0x28) +
                     *(int *)((int)this + 0x28);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      DAT_00584168 = (*(int *)((int)this + 0x24) + *(int *)((int)this + 0x20)) /
                     *(int *)((int)this + 0x28) + *(int *)((int)this + 0x28);
      break;
    case 8:
    case 9:
      DAT_00584168 = (int)DAT_0058416c / 2 + (int)DAT_00584164 / 2 + *(int *)((int)this + 0x28);
      break;
    default:
      DAT_00584168 = DAT_00584168 + *(int *)((int)this + 0x28);
    }
  }
  uVar4 = DAT_0058416c;
  puVar8 = DAT_00584164;
  local_20 = *(undefined2 **)((int)this + 0x18);
  switch(local_20) {
  case (undefined2 *)0x0:
  case (undefined2 *)0x1:
    lVar11 = __ftol();
    local_2c = (int)lVar11;
    if (local_20 == (undefined2 *)0x1) {
      local_2c = uVar4 - local_2c;
    }
    param_1 = 1;
    do {
      iVar10 = (int)puVar8 * local_2c;
      if (((local_20 == (undefined2 *)0x0) && (local_2c < 0)) ||
         ((local_20 == (undefined2 *)0x1 && ((int)DAT_0058416c < local_2c)))) goto LAB_0052041b;
      if ((local_2c < (int)DAT_0058416c) && (-1 < local_2c)) {
        uVar4 = *(uint *)((int)this + 0x28);
        if (*(byte *)((int)DAT_00584170 + iVar10) == uVar4) goto LAB_0052041b;
        local_20 = (undefined2 *)(uVar4 * *(int *)((int)this + 0x1c) * local_2c + iVar12);
        local_24 = iVar13 + *(int *)((int)this + 0x20) * uVar4 * local_2c * 2;
        iVar3 = 0;
        if (0 < (int)puVar8) {
          local_1c = iVar10 * 4;
          do {
            FUN_00520640(this,local_24,local_20,(uint)*(byte *)((int)DAT_00584170 + iVar3 + iVar10),
                         param_1,(int *)(local_1c + (int)DAT_00584174));
            *(undefined1 *)((int)DAT_00584170 + iVar3 + iVar10) = (undefined1)param_1;
            local_24 = local_24 + *(int *)((int)this + 0x28) * 2;
            local_20 = local_20 + *(int *)((int)this + 0x28);
            iVar3 = iVar3 + 1;
            local_1c = local_1c + 4;
            puVar8 = DAT_00584164;
          } while (iVar3 < (int)DAT_00584164);
        }
      }
      local_20 = *(undefined2 **)((int)this + 0x18);
      param_1 = param_1 + 1;
      if (local_20 == (undefined2 *)0x0) {
        local_2c = local_2c + -1;
      }
      else {
        local_2c = local_2c + 1;
      }
      if ((int)*(uint *)((int)this + 0x28) < (int)param_1) {
        param_1 = *(uint *)((int)this + 0x28);
      }
    } while( true );
  case (undefined2 *)0x2:
  case (undefined2 *)0x3:
    lVar11 = __ftol();
    local_28 = (int)lVar11;
    if (local_20 == (undefined2 *)0x3) {
      local_28 = (int)puVar8 - local_28;
    }
    param_1 = 1;
    do {
      if (((local_20 == (undefined2 *)0x2) && (local_28 < 0)) ||
         ((local_20 == (undefined2 *)0x3 && ((int)puVar8 < local_28)))) goto LAB_0052022f;
      if ((local_28 < (int)puVar8) && (-1 < local_28)) {
        if ((uint)*(byte *)((int)DAT_00584170 + local_28) == *(uint *)((int)this + 0x28))
        goto LAB_0052022f;
        iVar3 = *(uint *)((int)this + 0x28) * local_28 * 2;
        local_2c = 0;
        iVar10 = iVar3 + iVar13;
        local_20 = (undefined2 *)(iVar3 + iVar12);
        iVar3 = local_28;
        if (0 < (int)DAT_0058416c) {
          do {
            FUN_00520640(this,iVar10,local_20,(uint)*(byte *)((int)DAT_00584170 + iVar3),param_1,
                         (int *)(DAT_00584174 + iVar3));
            *(undefined1 *)((int)DAT_00584170 + iVar3) = (undefined1)param_1;
            local_20 = (undefined2 *)
                       ((int)local_20 + *(int *)((int)this + 0x28) * *(int *)((int)this + 0x1c));
            iVar10 = iVar10 + *(int *)((int)this + 0x28) * *(int *)((int)this + 0x20) * 2;
            iVar3 = iVar3 + (int)DAT_00584164;
            local_2c = local_2c + 1;
            puVar8 = DAT_00584164;
          } while (local_2c < (int)DAT_0058416c);
        }
      }
      local_20 = *(undefined2 **)((int)this + 0x18);
      param_1 = param_1 + 1;
      if (local_20 == (undefined2 *)0x2) {
        local_28 = local_28 + -1;
      }
      else {
        local_28 = local_28 + 1;
      }
      if ((int)*(uint *)((int)this + 0x28) < (int)param_1) {
        param_1 = *(uint *)((int)this + 0x28);
      }
    } while( true );
  case (undefined2 *)0x4:
  case (undefined2 *)0x5:
  case (undefined2 *)0x6:
  case (undefined2 *)0x7:
    lVar11 = __ftol();
    local_28 = (int)lVar11;
    param_1 = 1;
    if ((local_20 == (undefined2 *)0x4) || (local_20 == (undefined2 *)0x6)) {
      local_1c = -1;
    }
    else if ((local_20 == (undefined2 *)0x5) || (local_20 == (undefined2 *)0x7)) {
      local_1c = 1;
      local_28 = (int)puVar8 - local_28;
    }
    while (((-1 < local_28 || ((local_20 != (undefined2 *)0x4 && (local_20 != (undefined2 *)0x6))))
           && ((local_28 <= (int)puVar8 ||
               ((local_20 != (undefined2 *)0x5 && (local_20 != (undefined2 *)0x7))))))) {
      if ((int)local_20 < 6) {
        uVar4 = *(uint *)((int)this + 0x28);
        iVar10 = uVar4 * local_28 * 2;
        local_24 = iVar10;
      }
      else {
        uVar4 = *(uint *)((int)this + 0x28);
        iVar10 = ((DAT_0058416c - 1) * *(int *)((int)this + 0x1c) + local_28 * 2) * uVar4;
        local_24 = (*(int *)((int)this + 0x20) * (DAT_0058416c - 1) + local_28) * uVar4 * 2;
      }
      local_24 = iVar13 + local_24;
      puVar9 = (undefined2 *)(iVar10 + iVar12);
      local_2c = 0;
      local_10 = local_28;
      local_c = local_28;
      if (0 < (int)DAT_0058416c) {
        do {
          if ((-1 < local_c) && (local_c < (int)puVar8)) {
            if (*(byte *)((int)DAT_00584170 + local_10) == uVar4) break;
            FUN_00520640(this,local_24,puVar9,(uint)*(byte *)((int)DAT_00584170 + local_10),param_1,
                         (int *)(DAT_00584174 + local_10));
            *(undefined1 *)((int)DAT_00584170 + local_10) = (undefined1)param_1;
            puVar8 = DAT_00584164;
          }
          uVar4 = *(uint *)((int)this + 0x28);
          iVar10 = *(int *)((int)this + 0x20) * uVar4;
          local_20 = *(undefined2 **)((int)this + 0x18);
          iVar3 = iVar10 * 2;
          if (5 < (int)local_20) {
            iVar3 = iVar10 * -2;
          }
          iVar10 = uVar4 * local_1c * 2;
          local_24 = local_24 + iVar3 + iVar10;
          iVar3 = uVar4 * *(int *)((int)this + 0x1c);
          if (5 < (int)local_20) {
            iVar3 = -iVar3;
          }
          puVar9 = (undefined2 *)((int)puVar9 + iVar10 + iVar3);
          local_10 = (int)puVar8 + local_10 + local_1c;
          local_c = local_c + local_1c;
          local_2c = local_2c + 1;
        } while (local_2c < (int)DAT_0058416c);
      }
      local_28 = local_28 + local_1c;
      param_1 = param_1 + 1;
      if ((int)*(uint *)((int)this + 0x28) < (int)param_1) {
        param_1 = *(uint *)((int)this + 0x28);
      }
    }
LAB_0052041b:
    iVar13 = *(int *)((int)this + 0x24);
    iVar12 = *(int *)((int)this + 0x20);
    break;
  case (undefined2 *)0x8:
  case (undefined2 *)0x9:
    lVar11 = __ftol();
    local_2c = 0;
    if (0 < (int)uVar4) {
      do {
        local_28 = 0;
        local_24 = iVar13 + *(int *)((int)this + 0x28) * local_2c * *(int *)((int)this + 0x20) * 2;
        iVar10 = (int)puVar8 * local_2c;
        local_20 = (undefined2 *)
                   (*(int *)((int)this + 0x28) * *(int *)((int)this + 0x1c) * local_2c + iVar12);
        if (0 < (int)puVar8) {
          do {
            if ((int)DAT_00584174[iVar10] < *(int *)((int)this + 0x2c)) {
              uVar7 = local_28 - ((int)puVar8 >> 1);
              uVar4 = local_2c - ((int)DAT_0058416c >> 1);
              uVar5 = (int)uVar4 >> 0x1f;
              uVar6 = (int)uVar7 >> 0x1f;
              if (*(int *)((int)this + 0x18) == 8) {
                uVar4 = ((int)lVar11 - ((uVar7 ^ uVar6) - uVar6)) - ((uVar4 ^ uVar5) - uVar5);
              }
              else {
                uVar4 = (-((int)DAT_0058416c / 2) - (int)puVar8 / 2) +
                        ((uVar7 ^ uVar6) - uVar6) + (int)lVar11 + ((uVar4 ^ uVar5) - uVar5);
                puVar8 = DAT_00584164;
              }
              if ((int)*(uint *)((int)this + 0x2c) < (int)uVar4) {
                uVar4 = *(uint *)((int)this + 0x2c);
              }
              if (0 < (int)uVar4) {
                FUN_00520640(this,local_24,local_20,(uint)*(byte *)((int)DAT_00584170 + iVar10),
                             uVar4,(int *)(DAT_00584174 + iVar10));
                *(char *)((int)DAT_00584170 + iVar10) = (char)uVar4;
                puVar8 = DAT_00584164;
              }
            }
            local_24 = local_24 + *(int *)((int)this + 0x28) * 2;
            local_20 = local_20 + *(int *)((int)this + 0x28);
            iVar10 = iVar10 + 1;
            local_28 = local_28 + 1;
          } while (local_28 < (int)puVar8);
        }
        local_2c = local_2c + 1;
      } while (local_2c < (int)DAT_0058416c);
    }
    iVar13 = *(int *)((int)this + 0x24);
    iVar12 = *(int *)((int)this + 0x20);
    break;
  default:
    goto switchD_0051ff8e_default;
  }
LAB_005205a9:
  FUN_00526d30(*(void **)((int)this + 0x30),0,0,iVar12,iVar13);
switchD_0051ff8e_default:
  *(undefined4 *)((int)this + 0x14) = 0;
  if (local_8 == 1.0) {
    Mem_Free(DAT_00584170);
    DAT_00584170 = (LPVOID)0x0;
    Mem_Free(DAT_00584174);
    DAT_00584174 = (uint *)0x0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  return;
LAB_0052022f:
  iVar13 = *(int *)((int)this + 0x24);
  iVar12 = *(int *)((int)this + 0x20);
  goto LAB_005205a9;
}

