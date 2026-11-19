// rea decompile_all
// name: FUN_0047f780
// address: 0x47f780
// body: available
// range: 0x47f780-0x47fa3c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0047f780(void *param_1)

{
  int *piVar1;
  void *pvVar2;
  char *pcVar3;
  char *this;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580a6;
  local_c = ExceptionList;
  if (*(int *)((int)param_1 + 0x38) == 2) {
    return;
  }
  ExceptionList = &local_c;
  FUN_0047c5e0(param_1,0);
  FUN_0047fd20(param_1);
  this = *(char **)((int)param_1 + 0x1514);
  iVar4 = 0;
  if (0 < (int)this) {
    do {
      piVar1 = (int *)FUN_004017f0((void *)((int)param_1 + 0x1500),iVar4,(int *)0x0);
      pvVar2 = (void *)FUN_004d3910(*piVar1);
      if ((*(char *)(*piVar1 + 0x824) == '\x03') && (*(int *)((int)pvVar2 + 0xa4) == 4)) {
        FUN_0050e850(pvVar2,0xffffffff);
        FUN_00507e20(pvVar2,3,*(int *)((int)pvVar2 + 0xcc));
        FUN_0050e4c0(pvVar2,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)this);
  }
  *(undefined1 *)((int)param_1 + 0x16f5) = 1;
  if (*(int *)((int)DAT_0057c670 + 0x2fc) == *(int *)((int)param_1 + 0x14e0)) {
    FUN_004858a0(DAT_0057c670,0);
    if (*(int *)((int)param_1 + 0x38) == 0) {
      pcVar3 = s_BAUHINTERGRUND_MITTEL_tga_00567cdc;
    }
    else if (*(int *)((int)param_1 + 0x38) == 1) {
      pcVar3 = s_BAUHINTERGRUND_GROSS_tga_00567cf8;
    }
    else {
      pcVar3 = this;
    }
    FUN_004858d0(DAT_0057c670,pcVar3);
  }
  FUN_0047c590((int)param_1);
  if (*(int *)((int)param_1 + 0x38) == 0) {
    pvVar2 = operator_new(0x10178);
    local_4 = 0;
    if (pvVar2 != (void *)0x0) {
      this = (char *)FUN_004eb0f0(pvVar2,(int)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  else {
    if (*(int *)((int)param_1 + 0x38) != 1) goto LAB_0047f909;
    pvVar2 = operator_new(0x10178);
    local_4 = 1;
    if (pvVar2 != (void *)0x0) {
      this = (char *)FUN_004eb0f0(pvVar2,(int)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  local_4 = 0xffffffff;
  this = (char *)0x0;
LAB_0047f909:
  iVar4 = FUN_004f1250(this,(undefined4 *)0x1);
  if (iVar4 == 0) {
    FUN_004f3200(this,(int)param_1);
  }
  FUN_004eac80(DAT_0057c5cc,this,-1);
  FUN_00486be0(DAT_0057c670,0);
  *(int *)((int)param_1 + 0x38) = *(int *)((int)param_1 + 0x38) + 1;
  FUN_00401790((void *)((int)DAT_0057c5cc + 0x2c3f8),*(int *)((int)param_1 + 0x14e0));
  if (*(undefined4 **)((int)param_1 + 0x14e0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)param_1 + 0x14e0))(1);
  }
  *(char **)((int)param_1 + 0x14e0) = this;
  if (((*(int *)((int)DAT_0057c670 + 0x290) == 4) && (*(int *)((int)DAT_0057c670 + 0x2fc) == 0)) &&
     (*(void **)((int)DAT_0057c670 + 0x9c) == param_1)) {
    FUN_004858a0(DAT_0057c670,this);
  }
  FUN_0047e5e0(param_1,4);
  FUN_0047e6a0(param_1,4);
  FUN_004e43a0(*(void **)(*(int *)((int)param_1 + 0x16f0) + 0x74),
               *(undefined4 *)((int)param_1 + 0x38));
  FUN_00486e00((int)DAT_0057c670);
  FUN_0047e6e0((int)param_1);
  pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x34),
                                (int *)0x0);
  FUN_004d77b0(pvVar2,*(void **)((int)param_1 + 0x16f0),1,*(int *)((int)param_1 + 0x30),
               (void *)0xffffffff,-1);
  FUN_0047edc0((int)param_1);
  FUN_0047ec70(param_1);
  FUN_0047ed20((int)param_1);
  FUN_0047f100(param_1);
  FUN_004805d0(param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x14e0) + 0xf4) = 1;
  ExceptionList = local_c;
  return;
}

