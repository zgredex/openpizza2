// rea decompile_all
// name: FUN_004c07c0
// address: 0x4c07c0
// body: available
// range: 0x4c07c0-0x4c0b22 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c07c0(void *param_1)

{
  void *this;
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  longlong lVar7;
  int local_8;
  int *local_4;
  
  pvVar1 = param_1;
  iVar5 = 0;
  this = *(void **)((int)DAT_0057c670 + 0x9c);
  local_4 = (int *)0x0;
  iVar2 = *(int *)((int)this + 0x38);
  if (iVar2 == 0) {
    pvVar3 = (void *)0x21;
    pvVar6 = (void *)0x1e;
  }
  else if (iVar2 == 1) {
    pvVar3 = (void *)0x42;
    pvVar6 = (void *)0x3c;
  }
  else if (iVar2 == 2) {
    pvVar3 = (void *)0x64;
    pvVar6 = (void *)0x5f;
  }
  else {
    pvVar3 = param_1;
    pvVar6 = param_1;
  }
  FUN_0052fd70(param_1,0x511,pvVar3,0);
  FUN_0052fd70(param_1,0x443,pvVar6,0);
  iVar2 = FUN_0047ee60((int)this);
  FUN_0052fd70(param_1,0x444,iVar2,0);
  pvVar3 = FUN_004e23b0(*(void **)((int)DAT_0057c670 +
                                  *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),(int)this);
  if (pvVar3 == (void *)0x0) {
    FUN_00531740(param_1,0x512);
    FUN_00531740(param_1,0x1f62);
    FUN_00531740(param_1,0x1f69);
    FUN_00531740(param_1,0x1f42);
    FUN_00531740(param_1,0x1f6b);
    FUN_0052f9b0(param_1,0x519,DAT_00582e4c);
    FUN_0052f9b0(param_1,0x1f6c,DAT_00582e4c);
    FUN_0052f9b0(param_1,0x1f6a,DAT_00582e4c);
    FUN_0052f9b0(param_1,0x1f61,DAT_00582e4c);
  }
  else {
    iVar2 = Get_Subobject4((int)pvVar3);
    FUN_0052f9b0(param_1,0x519,iVar2);
    FUN_005316b0(param_1,0x1f42);
    FUN_005316b0(param_1,0x512);
    FUN_005316b0(param_1,0x1f6b);
    iVar2 = FUN_005144f0((int)pvVar3);
    FUN_0052f080(param_1,0x1f6c,(byte *)s__d____00568834,iVar2);
    iVar2 = *(int *)((int)pvVar3 + 0x30);
    if (iVar2 == -1) {
      FUN_00531740(param_1,0x1f62);
      FUN_0052f9b0(param_1,0x1f6a,DAT_00582e4c);
      FUN_0052f9b0(param_1,0x1f61,DAT_00582e4c);
      FUN_00531740(param_1,0x1f69);
    }
    else {
      pvVar3 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                    *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      local_4 = (int *)Array_GetStride60(pvVar3,iVar2);
      FUN_0052f9b0(param_1,0x1f61,local_4 + 0x11);
      FUN_005316b0(param_1,0x1f62);
      FUN_005316b0(param_1,0x1f69);
      FUN_0052f080(param_1,0x1f6a,(byte *)s__d____00568834,*local_4 / 10);
    }
  }
  param_1 = (void *)0x0;
  local_8 = 0;
  iVar2 = FUN_0047aac0(this,0xffffffff);
  if (0 < iVar2) {
    do {
      piVar4 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),iVar5,(int *)0x0);
      if (*(char *)(*piVar4 + 0x824) == '\x03') {
        iVar2 = FUN_004d3910(*piVar4);
        if ((*(char *)(iVar2 + 0x80) == '\0') &&
           (param_1 = (void *)((int)param_1 + 1), *(char *)(*piVar4 + 0x825) == '\x02')) {
          local_8 = local_8 + 1;
        }
      }
      iVar5 = iVar5 + 1;
      iVar2 = FUN_0047aac0(this,0xffffffff);
    } while (iVar5 < iVar2);
  }
  FUN_0052f080(pvVar1,0x521,&DAT_005686f4,param_1);
  FUN_0052f080(pvVar1,0x522,&DAT_005686f4,local_8);
  lVar7 = FUN_004782a0(this,3);
  FUN_0052f080(pvVar1,0x523,(byte *)s__d____00568834,(int)lVar7);
  iVar2 = FUN_004781e0((int)this);
  FUN_0052f080(pvVar1,0x524,(byte *)s__d____00568834,iVar2);
  iVar2 = 0;
  do {
    if (local_4 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0048c7b0(DAT_0057c670,iVar2,*local_4 / 10);
    }
    FUN_004a80e0(pvVar1,0x207c,iVar2,iVar5,DAT_00581048);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

