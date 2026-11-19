// rea decompile_all
// name: FUN_004919f0
// address: 0x4919f0
// body: available
// range: 0x4919f0-0x491c74 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004919f0(void *param_1,int param_2,void *param_3,void *param_4,float param_5)

{
  uint *puVar1;
  void *pvVar2;
  float fVar3;
  float fVar4;
  void *this;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  this = (void *)FUN_00531cf0(param_1,param_2);
  FUN_00521380((int)this);
  if (*(short *)(*(int *)(DAT_0057c670 + 0x94) + 10) == 0) {
    FUN_00521ae0(this,(int *)&param_1,&param_2);
    pvVar5 = (void *)FUN_00521b10((int)this);
    pvVar2 = param_3;
    FUN_00535520(param_3,(int)param_1 / 2,param_2 / 2,2);
    FUN_00535500(pvVar2,0);
    Font_DrawTextLine(pvVar2,pvVar5,DAT_00581444);
    FUN_00521b30((int)this);
    return;
  }
  iVar6 = FUN_004de670(pvVar2,(int)param_4);
  param_3 = (void *)(float)iVar6;
  FUN_00521ae0(this,(int *)&param_1,&param_2);
  param_1 = (void *)((int)param_1 + -3);
  param_2 = param_2 + -3;
  fVar3 = (float)(int)param_1;
  piVar7 = FUN_00521bc0(this,0,3);
  fVar4 = param_5;
  param_3 = (void *)0x0;
  do {
    pvVar5 = param_3;
    if (*(int *)((int)fVar4 + (int)param_3) != 0) {
      param_5 = 0.0;
      FUN_004de600(pvVar2,*(undefined4 *)((int)param_3 + 0x568638),8,param_4);
      iVar6 = 0;
      while( true ) {
        param_5 = param_5 + fVar3 * 0.125;
        FUN_004de600(pvVar2,*(undefined4 *)((int)pvVar5 + 0x568638),iVar6,param_4);
        lVar10 = __ftol();
        iVar9 = param_2 - (int)lVar10;
        lVar10 = __ftol();
        puVar1 = (uint *)((int)lVar10 + 1);
        lVar10 = __ftol();
        lVar11 = __ftol();
        puVar8 = (uint *)((int)lVar11 + 1);
        FUN_00521740(this,puVar8,(int)lVar10 + 2,puVar1,iVar9 + 2,0);
        FUN_00521740(this,puVar8,(int)lVar10 + 1,puVar1,iVar9 + 1,*(uint *)((int)param_3 + 0x568668)
                    );
        iVar6 = iVar6 + 1;
        if (7 < iVar6) break;
        pvVar5 = param_3;
      }
    }
    param_3 = (void *)((int)param_3 + 4);
  } while ((int)param_3 < 0x10);
  FUN_00521b30((int)this);
  FUN_00521da0(piVar7);
  return;
}

