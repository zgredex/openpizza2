// rea decompile_all
// name: FUN_0048c400
// address: 0x48c400
// body: available
// range: 0x48c400-0x48c603 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048c400(void *this,undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  int *piVar6;
  
  DAT_0057c638 = param_2;
  DAT_0057c63c = FUN_0048c340((int)this);
  puVar1 = (undefined4 *)DAT_0057c63c[5];
  if ((int)puVar1 < (int)param_1) {
    param_1 = puVar1;
  }
  piVar2 = operator_new((int)puVar1 * 4);
  iVar3 = 0;
  if (0 < (int)puVar1) {
    piVar6 = piVar2;
    do {
      *piVar6 = iVar3;
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < (int)puVar1);
  }
  if (param_2 == -1) {
    FUN_0054ea8f(piVar2,puVar1,4,&LAB_0048c670);
    piVar6 = piVar2;
    if (0 < (int)param_1) {
      do {
        pvVar4 = (void *)FUN_004017f0(DAT_0057c63c,*piVar6,(int *)0x0);
        if (*(int *)((int)pvVar4 + 0x74) == 0) {
          pvVar5 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                        (int *)0x0);
          iVar3 = FUN_004d74c0(pvVar5,0x22,0,'\0');
          FUN_00507e20(pvVar4,7,iVar3);
          UI_SetChildState(pvVar4,0xffff);
        }
        else {
          *(undefined1 *)((int)pvVar4 + 0x81) = 1;
          Object_SetFieldA4Locked(pvVar4,0x13);
        }
        piVar6 = piVar6 + 1;
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
    }
  }
  else {
    FUN_0054ea8f(piVar2,puVar1,4,&LAB_0048c610);
    if (param_3 < 0) {
      piVar6 = piVar2;
      if (0 < (int)param_1) {
        do {
          pvVar4 = (void *)FUN_004017f0(DAT_0057c63c,*piVar6,(int *)0x0);
          if (*(int *)((int)pvVar4 + 0x74) == 0) {
            pvVar5 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                          (int *)0x0);
            iVar3 = FUN_004d74c0(pvVar5,0x22,0,'\0');
            FUN_00507e20(pvVar4,7,iVar3);
            UI_SetChildState(pvVar4,0xffff);
          }
          else {
            *(undefined1 *)((int)pvVar4 + 0x81) = 1;
            Object_SetFieldA4Locked(pvVar4,0x13);
          }
          piVar6 = piVar6 + 1;
          param_1 = (undefined4 *)((int)param_1 + -1);
        } while (param_1 != (undefined4 *)0x0);
      }
    }
    else {
      iVar3 = (int)puVar1 + -1;
      if ((int)puVar1 + -0xb < iVar3) {
        piVar6 = piVar2 + iVar3;
        param_2 = iVar3 - ((int)puVar1 + -0xb);
        do {
          pvVar4 = (void *)FUN_004017f0(DAT_0057c63c,*piVar6,(int *)0x0);
          if (*(int *)((int)pvVar4 + 0x74) == 0) {
            pvVar5 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                          (int *)0x0);
            iVar3 = FUN_004d74c0(pvVar5,0x22,0,'\0');
            FUN_00507e20(pvVar4,7,iVar3);
            UI_SetChildState(pvVar4,0xffff);
          }
          else {
            *(undefined1 *)((int)pvVar4 + 0x81) = 1;
            Object_SetFieldA4Locked(pvVar4,0x13);
          }
          piVar6 = piVar6 + -1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
  }
  FUN_0054dd78(piVar2);
  if (DAT_0057c63c != (undefined4 *)0x0) {
    (**(code **)*DAT_0057c63c)(1);
  }
  return;
}

