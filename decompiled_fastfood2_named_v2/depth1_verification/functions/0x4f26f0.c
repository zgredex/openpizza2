// rea decompile_all
// name: FUN_004f26f0
// address: 0x4f26f0
// body: available
// range: 0x4f26f0-0x4f29b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING (jumptable): Unable to track spacebase fully for stack */

void __fastcall FUN_004f26f0(void *param_1)

{
  void *this;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *this_00;
  uint *puVar5;
  undefined4 unaff_EDI;
  longlong lVar6;
  uint local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  undefined4 local_18 [2];
  undefined4 local_10 [3];
  
  puVar5 = *(uint **)((int)param_1 + 0xbc);
  if (puVar5 != (uint *)0x0) {
    DAT_00580a5c = timeGetTime();
    do {
      FUN_004f21e0(param_1,puVar5,DAT_00580a5c);
      puVar5 = (uint *)puVar5[0x1c];
    } while (puVar5 != (uint *)0x0);
    this = *(void **)(*(int *)((int)param_1 + 4) + 0x2c3d4);
    if (*(int *)((int)param_1 + 0xc) == 0x40) {
      local_28 = 0x36c;
      local_1c = 0;
      do {
        iVar4 = *(int *)(local_28 + 0x2c0b0 + *(int *)((int)param_1 + 4));
        if (((iVar4 < 0) || (*(int *)((int)this + 0x48) <= iVar4)) ||
           (*(char *)(*(int *)((int)this + 0x4c) + 0x3e + iVar4 * 0x48) == '\0')) goto LAB_004f298a;
        FUN_005341c0(this,iVar4,local_18,local_10);
        lVar6 = __ftol();
        iVar2 = (int)lVar6;
        lVar6 = __ftol();
        iVar3 = (int)lVar6;
        FUN_00534060(this,iVar4,&local_20,&local_24,&local_2c,&local_30);
        Record_GetScreenRect48(this,iVar4,(int *)&local_2c,(int *)&local_30);
        switch(*(undefined4 *)(local_28 + (int)DAT_0057c670)) {
        case 1:
          if ((iVar2 <= *(int *)((int)param_1 + 0x34) + DAT_00571958) &&
             (iVar3 <= *(int *)((int)param_1 + 0x38) + DAT_0057195c)) {
LAB_004f2870:
            if ((int)((*(int *)((int)param_1 + 0x2c) - local_20) - local_2c) <= iVar2) break;
          }
          goto LAB_004f28fa;
        case 2:
          if ((*(int *)((int)param_1 + 0x34) + DAT_00571958 < iVar2) ||
             ((iVar3 < (int)((*(int *)((int)param_1 + 0x30) - local_24) - local_30) ||
              (iVar2 < (int)((*(int *)((int)param_1 + 0x2c) - local_20) - local_2c)))))
          goto LAB_004f28fa;
          break;
        case 3:
          if ((iVar3 <= *(int *)((int)param_1 + 0x38) + DAT_0057195c) &&
             ((int)((*(int *)((int)param_1 + 0x30) - local_24) - local_30) <= iVar3))
          goto LAB_004f2870;
LAB_004f28fa:
          FUN_00533a70(this,iVar4);
          uVar1 = local_1c;
          *(undefined4 *)(local_28 + (int)DAT_0057c670) = 0xffffffff;
          iVar4 = FUN_00488be0(DAT_0057c670,local_1c);
          iVar4 = Player_GetFirstRecordType1(iVar4);
          if ((iVar4 == 0) || (*(int *)(iVar4 + 4) == 0)) {
            FUN_0054a660(DAT_0057c1e0,0xa000,(byte *)s_Ende_Stadtwerbung_00571cd4,unaff_EDI);
          }
          else {
            FUN_0054a660(DAT_0057c1e0,0xa000,&DAT_00571ce8,unaff_EDI);
            this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                           *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
            FUN_004dc760(this_00,uVar1);
          }
          break;
        case 4:
          if (((*(int *)((int)param_1 + 0x34) + DAT_00571958 < iVar2) ||
              (*(int *)((int)param_1 + 0x38) + DAT_0057195c < iVar3)) ||
             (iVar3 < (int)((*(int *)((int)param_1 + 0x30) - local_24) - local_30)))
          goto LAB_004f28fa;
        }
LAB_004f298a:
        local_28 = local_28 + 4;
        local_1c = local_1c + 1;
      } while (local_28 < 900);
    }
  }
  return;
}

