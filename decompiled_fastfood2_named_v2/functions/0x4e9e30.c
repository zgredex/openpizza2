// rea decompile_all
// name: FUN_004e9e30
// address: 0x4e9e30
// body: available
// range: 0x4e9e30-0x4ea221 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004e9e30(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00559e5e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c5d0;
  piVar2 = (int *)param_1[7];
  local_4 = 0;
  if (piVar2 != (int *)0x0) {
    FUN_00535cf0(piVar2);
    Mem_Free(piVar2);
  }
  piVar2 = param_1 + 0x1a;
  local_14 = 0x9c4;
  do {
    if ((undefined4 *)piVar2[-4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[-4])(1);
      piVar2[-4] = 0;
    }
    if (*piVar2 != 0) {
      iVar3 = 0;
      if (0 < *(int *)(*piVar2 + 0x14)) {
        do {
          iVar1 = IDMap_Lookup((void *)*piVar2,iVar3,(int *)0x0);
          if (*(undefined4 **)(iVar1 + 0x48) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(iVar1 + 0x48))(1);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(*piVar2 + 0x14));
      }
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
    }
    if ((undefined4 *)piVar2[-3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[-3])(1);
    }
    if ((undefined4 *)piVar2[-2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[-2])(1);
    }
    if ((undefined4 *)piVar2[-1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[-1])(1);
    }
    piVar2 = piVar2 + 0x12;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  FUN_00533a50((void *)param_1[0xb0ee],param_1[0xb105]);
  FUN_00533a50((void *)param_1[0xb0ed],param_1[0xb106]);
  piVar2 = param_1 + 0xb126;
  piVar4 = param_1 + 0xb107;
  iVar3 = 6;
  do {
    FUN_00533a50((void *)param_1[0xb0f5],*piVar4);
    FUN_00533a50((void *)param_1[0xb0fa],piVar2[-1]);
    FUN_00533a50((void *)param_1[0xb0fb],*piVar2);
    FUN_00533a50((void *)param_1[0xb0fc],piVar2[1]);
    FUN_00533a50((void *)param_1[0xb0fd],piVar2[2]);
    FUN_00533a50((void *)param_1[0xb0f6],piVar2[-0x19]);
    FUN_00533a50((void *)param_1[0xb0f7],piVar2[-0x18]);
    FUN_00533a50((void *)param_1[0xb0f8],piVar2[-0x17]);
    FUN_00533a50((void *)param_1[0xb0f9],piVar2[-0x16]);
    piVar4 = piVar4 + 1;
    piVar2 = piVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  piVar2 = param_1 + 0xb003;
  do {
    if (iVar3 != 0x10) {
      if ((undefined4 *)piVar2[-0x30] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[-0x30])(1);
      }
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      if ((undefined4 *)piVar2[0x8a] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[0x8a])(1);
      }
      if ((undefined4 *)piVar2[0xba] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[0xba])(1);
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 0x30);
  piVar2 = param_1 + 0xb033;
  iVar3 = 0x2d;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((undefined4 *)param_1[0xb060] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb060])(1);
  }
  if ((undefined4 *)param_1[0xb061] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb061])(1);
  }
  if ((undefined4 *)param_1[0xb067] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb067])(1);
  }
  if ((undefined4 *)param_1[0xb06d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb06d])(1);
  }
  if ((undefined4 *)param_1[0xb073] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb073])(1);
  }
  if ((undefined4 *)param_1[0xb079] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb079])(1);
  }
  if ((undefined4 *)param_1[0xb07a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb07a])(1);
  }
  if ((undefined4 *)param_1[0xb080] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb080])(1);
  }
  if ((undefined4 *)param_1[0xb086] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb086])(1);
  }
  if ((undefined4 *)param_1[0xb087] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb087])(1);
  }
  if ((undefined4 *)param_1[0xb0ed] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0ed])(1);
  }
  if ((undefined4 *)param_1[0xb0ee] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0ee])(1);
  }
  if ((undefined4 *)param_1[0xb0ef] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0ef])(1);
  }
  if ((undefined4 *)param_1[0xb0f0] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f0])(1);
  }
  if ((undefined4 *)param_1[0xb0f2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f2])(1);
  }
  if ((undefined4 *)param_1[0xb0f1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f1])(1);
  }
  if ((undefined4 *)param_1[0xb0f3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f3])(1);
  }
  if ((undefined4 *)param_1[0xb0f4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f4])(1);
  }
  if ((undefined4 *)param_1[0xb0f5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb0f5])(1);
  }
  piVar2 = param_1 + 0xb0f6;
  iVar3 = 4;
  do {
    if ((undefined4 *)piVar2[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[4])(1);
    }
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  do {
    if (*(undefined4 **)((int)&DAT_005806ec + iVar3) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)&DAT_005806ec + iVar3))(1);
    }
    if (*(undefined4 **)((int)&DAT_0058070c + iVar3) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)&DAT_0058070c + iVar3))(1);
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x20);
  if (DAT_00580730 != (undefined4 *)0x0) {
    (**(code **)*DAT_00580730)(1);
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(param_1 + 0xb0fe);
  ExceptionList = pvStack_c;
  return;
}

