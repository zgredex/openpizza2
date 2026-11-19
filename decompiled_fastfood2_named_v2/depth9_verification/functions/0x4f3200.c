// rea decompile_all
// name: FUN_004f3200
// address: 0x4f3200
// body: available
// range: 0x4f3200-0x4f3484 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f3200(void *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_2c;
  int local_28;
  int local_24 [5];
  undefined4 local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  local_24[3] = *(int *)((int)this + 0x1c);
  local_24[1] = 1;
  local_24[2] = local_24[3] + 1;
  local_24[4] = local_24[3] + -1;
  local_c = -1 - local_24[3];
  local_8 = -local_24[3];
  local_4 = 1 - local_24[3];
  local_10 = 0xffffffff;
  IsoMap_MarkPlayerFootprints(this,param_1);
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x20)) {
    do {
      iVar6 = 0;
      if (0 < *(int *)((int)this + 0x1c)) {
        do {
          iVar1 = FUN_004ef4b0(this,iVar6,iVar4);
          if (((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) &&
             (iVar1 = FUN_004f29d0(*(int *)(*(int *)(iVar1 + 8) + 4)), iVar1 != 0)) {
            iVar5 = iVar5 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)((int)this + 0x1c));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x20));
  }
  if (*(LPVOID *)((int)this + 0x9c) != (LPVOID)0x0) {
    FUN_0054dd78(*(LPVOID *)((int)this + 0x9c));
    *(undefined4 *)((int)this + 0xa4) = 0;
  }
  pvVar2 = operator_new(iVar5 * 0x28);
  *(void **)((int)this + 0x9c) = pvVar2;
  param_1 = 0;
  if (0 < *(int *)((int)this + 0x20)) {
    do {
      iVar4 = 0;
      if (0 < *(int *)((int)this + 0x1c)) {
        do {
          piVar3 = (int *)FUN_004ef4b0(this,iVar4,param_1);
          if ((piVar3 != (int *)0x0) && (iVar5 = piVar3[2], iVar5 != 0)) {
            iVar6 = *(int *)(iVar5 + 0x10);
            iVar5 = FUN_004f29d0(*(int *)(iVar5 + 4));
            if (iVar5 == 0) {
              *(undefined2 *)(piVar3[2] + 0x24) = 0xffff;
            }
            else {
              FUN_004f34c0(this,piVar3,local_24,&local_28);
              FUN_004f1070(this,(int *)0x1,local_24[0] - *(int *)((int)this + 0x24),
                           local_28 - *(int *)((int)this + 0x28));
              *(short *)(piVar3[2] + 0x24) = *(short *)((int)this + 0xa4) + -1;
              iVar5 = FUN_004f2a20(iVar6);
              if (iVar5 == 0) {
                *(undefined4 *)(piVar3[2] + 0x28) = 0;
              }
              else {
                *(undefined4 *)(piVar3[2] + 0x28) = 1;
              }
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)((int)this + 0x1c));
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)((int)this + 0x20));
  }
  param_1 = 0;
  if (0 < *(int *)((int)this + 0xa4)) {
    do {
      iVar4 = FUN_004f0cc0(this,1,param_1);
      iVar4 = *(int *)(iVar4 + 8);
      iVar5 = *(int *)((int)this + 0x4c);
      if (*(int *)(*(int *)(iVar5 + 8 + iVar4 * 0xc) + 0x28) != 0) {
        piVar3 = local_24;
        local_2c = 8;
        do {
          piVar3 = piVar3 + 1;
          iVar6 = *(int *)((int)this + 0x4c) + (**(int **)(iVar5 + iVar4 * 0xc + 8) + *piVar3) * 0xc
          ;
          if (((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) &&
             ((iVar1 = FUN_004f0cc0(this,1,(int)*(short *)(*(int *)(iVar6 + 8) + 0x24)), iVar1 != 0
              && (*(int *)(*(int *)(iVar6 + 8) + 0x28) != 0)))) {
            FUN_004f0ab0(this,1,param_1,(int)*(short *)(*(int *)(iVar6 + 8) + 0x24));
          }
          local_2c = local_2c + -1;
        } while (local_2c != 0);
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)((int)this + 0xa4));
  }
  FUN_004edbc0();
  FUN_004f37d0(this,1,(uint)(*(int *)((int)this + 0x118) == 0),1);
  return;
}

