// rea decompile_all
// name: FUN_00477850
// address: 0x477850
// body: available
// range: 0x477850-0x477a9e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00477850(void *this,int param_1)

{
  ushort uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_EDI;
  int *piVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x35c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_004010f0(pvVar2,(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10),
                          (uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 4));
  }
  local_4 = 0xffffffff;
  FUN_004014b0((void *)((int)this + 0x14e4),puVar3);
  if (param_1 != 0) {
    iVar5 = *(int *)((int)this + 0x30);
    iVar4 = FUN_00482820((int)DAT_0057c670);
    if (iVar5 == iVar4) {
      pvVar2 = (void *)FUN_00488be0(DAT_0057c670,iVar5);
      iVar5 = FUN_004e2280((int)pvVar2);
      if (1 < iVar5) {
        iVar5 = FUN_004e2750(pvVar2,(int)this,0x17);
        if (iVar5 == 0) {
          iVar5 = FUN_0048c000(DAT_0057c670,5);
          if (iVar5 == 0) {
            iVar5 = FUN_0048bf90((int)DAT_0057c670,-1,5,4,10,*(int *)((int)this + 0x16f0),
                                 DAT_005811a8,DAT_00581280,unaff_EDI);
            FUN_0048c040(DAT_0057c670,iVar5,5);
          }
        }
      }
    }
  }
  uVar1 = *(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10);
  FUN_0047f180(this);
  puVar3 = (undefined4 *)((int)this + 0x430);
  iVar5 = 8;
  do {
    *puVar3 = puVar3[-1];
    puVar3[-0xa2] = puVar3[-0xa3];
    puVar3 = puVar3 + 9;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar7 = (int *)((int)this + (uVar1 - 1) * 4 + 0x554);
  piVar8 = (int *)((int)this + 0x44);
  iVar5 = 8;
  do {
    iVar4 = 8;
    piVar6 = piVar8;
    do {
      *piVar7 = *piVar7 + *piVar6;
      piVar6[0x51] = *piVar6;
      piVar6[0xf3] = piVar6[0xa2];
      iVar4 = iVar4 + -1;
      piVar6 = piVar6 + 1;
    } while (iVar4 != 0);
    piVar7 = piVar7 + 100;
    piVar8 = piVar8 + 9;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)((int)this + 0x13cc) = *(undefined4 *)((int)this + 0x13c8);
  *(undefined4 *)((int)this + 0x1414) = *(undefined4 *)((int)this + 0x1410);
  *(undefined4 *)((int)this + 0x145c) = *(undefined4 *)((int)this + 0x1458);
  *(undefined4 *)((int)this + 0x14a4) = *(undefined4 *)((int)this + 0x14a0);
  puVar3 = (undefined4 *)((int)this + 5000);
  iVar5 = 8;
  do {
    puVar3[9] = *puVar3;
    *puVar3 = 0;
    puVar3[0x1b] = puVar3[0x12];
    puVar3[0x12] = 0;
    puVar3[0x2d] = puVar3[0x24];
    puVar3[0x24] = 0;
    puVar3[0x3f] = puVar3[0x36];
    puVar3[0x36] = 0;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_00477e40(this,1,(float)*(int *)((int)this + 0x14b0),'\0',-1);
  puVar3 = (undefined4 *)((int)this + 0x44);
  for (iVar5 = 0x51; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0x1364);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0x2cc);
  for (iVar5 = 0x51; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  ExceptionList = local_c;
  return;
}

