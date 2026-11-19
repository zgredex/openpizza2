// rea decompile_all
// name: FUN_0052cfb0
// address: 0x52cfb0
// body: available
// range: 0x52cfb0-0x52d19d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_0052cfb0(void *this,void *param_1,void *param_2,int param_3,uint *param_4,uint *param_5,
            undefined4 *param_6)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined1 uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar8;
  undefined3 extraout_var_01;
  void *pvVar9;
  void *local_c;
  int local_8;
  undefined4 *local_4;
  
  pvVar4 = param_1;
  local_8 = -1;
  local_4 = (undefined4 *)0x0;
  local_c = (void *)0x0;
  puVar6 = (uint *)0x0;
  if (*(int *)((int)this + 0x80) != 0) {
    puVar6 = *(uint **)((int)this + 0x88);
    local_c = (void *)*puVar6;
  }
  puVar7 = (undefined4 *)CONCAT31((int3)((uint)puVar6 >> 8),*(char *)((int)param_1 + param_3));
  if (*(char *)((int)param_1 + param_3) != '\0') {
    do {
      if ((byte)puVar7 != 1) {
        if (0x1f < (byte)puVar7) {
          puVar3 = *(undefined4 **)((int)param_2 + 0x9b0);
          puVar7 = puVar3;
          if ((int)local_4 < (int)puVar3) {
            *param_6 = param_2;
            puVar7 = param_6;
            local_4 = puVar3;
          }
        }
        cVar2 = *(char *)((int)pvVar4 + param_3);
        pvVar9 = (void *)CONCAT31((int3)((uint)puVar7 >> 8),cVar2);
        if (cVar2 != '\n') {
          if (cVar2 == ' ') {
            param_1 = local_c;
            local_8 = param_3;
          }
          if (cVar2 == '\r') break;
          uVar5 = FUN_00535650(param_2,(uint)pvVar9);
          iVar8 = CONCAT31(extraout_var_00,uVar5);
          if (iVar8 == 0) {
            uVar5 = FUN_00535650(param_2,0x20);
            iVar8 = CONCAT31(extraout_var_01,uVar5);
          }
          pvVar9 = (void *)(iVar8 + (int)local_c);
          if ((int)*(short *)((int)this + 100) < (int)pvVar9) {
            if (local_8 != -1) {
              local_c = param_1;
              param_3 = local_8;
            }
            break;
          }
          local_c = pvVar9;
        }
        param_3 = param_3 + 1;
        goto LAB_0052d168;
      }
      pvVar9 = (void *)(uint)*(byte *)((int)pvVar4 + param_3 + 2);
      switch(pvVar9) {
      case (void *)0x0:
        bVar1 = *(byte *)((int)pvVar4 + param_3 + 3);
        if ((bVar1 == 9 || bVar1 < 9) &&
           (pvVar9 = *(void **)(*(int *)((int)this + 0x88) + 0xc + (uint)bVar1 * 4),
           pvVar9 != (void *)0x0)) {
          param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
          param_2 = pvVar9;
        }
        else {
          pvVar9 = *(void **)((int)this + 0x88);
          param_2 = *(void **)((int)pvVar9 + 0xc);
          param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
        }
        break;
      case (void *)0x2:
      case (void *)0x3:
        if (*(int *)((int)this + 0x80) != 0) goto switchD_0052d013_caseD_1;
        *(undefined4 *)((int)this + 0x80) = 1;
        if (*(char *)((int)pvVar4 + param_3 + 2) == '\x02') {
          *(undefined4 *)((int)this + 0x84) = 1;
          pvVar9 = (void *)((int)local_c + 0x14);
          param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
          local_c = pvVar9;
        }
        else {
          *(undefined4 *)((int)this + 0x84) = 0;
          pvVar9 = (void *)((int)local_c + 0x14);
          param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
          local_c = pvVar9;
        }
        break;
      case (void *)0x4:
        *param_5 = (uint)*(byte *)((int)pvVar4 + param_3 + 3);
        param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
        break;
      case (void *)0x5:
        uVar5 = FUN_00535650(param_2,0x2d);
        pvVar9 = (void *)(CONCAT31(extraout_var,uVar5) + (int)local_c);
        if ((int)pvVar9 <= (int)*(short *)((int)this + 100)) {
          local_8 = param_3 + 3;
          param_1 = pvVar9;
        }
      default:
switchD_0052d013_caseD_1:
        param_3 = param_3 + 2 + (uint)*(byte *)((int)pvVar4 + param_3 + 1);
      }
LAB_0052d168:
      puVar7 = (undefined4 *)CONCAT31((int3)((uint)pvVar9 >> 8),*(char *)((int)pvVar4 + param_3));
    } while (*(char *)((int)pvVar4 + param_3) != '\0');
  }
  *param_4 = (uint)local_c;
  return param_3;
}

