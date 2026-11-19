// rea decompile_all
// name: CompareScreen_UpdateRows
// address: 0x496680
// body: available
// range: 0x496680-0x4968eb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompareScreen_UpdateRows(void *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *this;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  char *pcVar6;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  undefined4 local_23c;
  float local_238;
  uint local_234;
  void *local_230;
  undefined4 local_22c;
  undefined1 local_228 [32];
  char local_208 [516];
  
                    /* Fills the company comparison rows for the selected metric. */
  local_24c = DAT_0057c704;
  local_234 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_230 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_240 = *(int *)(DAT_0057c670 + 0x9c);
  iVar1 = *(int *)(local_240 + 0x3c);
  if (param_3 == 1000) {
    local_250 = *(int *)(local_240 + 0x14a8);
  }
  else {
    local_250 = param_3;
  }
  if (DAT_0057c704 < 7) {
    param_2 = 0;
  }
  else {
    local_24c = 6;
  }
  local_254 = 0;
  iVar2 = DAT_0057c670;
  if (-1 < local_24c) {
    do {
      if (local_254 == 0) {
        this = *(void **)(*(int *)(iVar2 + 0x9c) + 0x14dc);
        if (this != (void *)0x0) {
          iVar2 = 0x4f7;
          local_248 = 0x51d;
          iVar3 = 0x4f7;
LAB_0049677b:
          Gadget_SetTextf(param_1,iVar2,&DAT_005630d0,(int)this + 4);
          switch(DAT_0057c708) {
          case 0:
            fVar4 = FUN_00513bf0((int)this,local_240,local_250);
            FUN_0054dd83(local_228,(byte *)s__0_2f_005685f4,SUB84((double)fVar4,0));
            local_244 = local_250;
            FUN_00513c40(this,local_240,&local_22c,&local_238,&local_244,&local_23c);
            FUN_0054dd83(local_208,(byte *)s___2f___s_x__03d____s_x__03d____s_005687fc,
                         SUB84((double)local_238,0));
            pcVar6 = local_208;
            goto LAB_004968b2;
          case 1:
            fVar4 = FUN_00510030((int)this,local_234,iVar1);
            uVar5 = SUB84((double)fVar4,0);
            break;
          case 2:
            fVar4 = FUN_004ddf10(DAT_0057c700,(int)this,iVar1);
            uVar5 = SUB84((double)fVar4,0);
            break;
          case 3:
            fVar4 = FUN_00510390((int)this,iVar1);
            uVar5 = SUB84((double)fVar4,0);
            break;
          default:
            goto switchD_0049679c_default;
          }
          FUN_0054dd83(local_228,(byte *)s__0_2f_005685f4,uVar5);
          pcVar6 = &DAT_00579aec;
LAB_004968b2:
          FUN_00531f50(param_1,iVar3,pcVar6);
switchD_0049679c_default:
          Window_GadgetNotify_Text_SetText(param_1,local_248,local_228);
          goto LAB_004968cb;
        }
      }
      else {
        iVar2 = local_254 + -1;
        this = (void *)FUN_004dde30(local_230,*(int *)(DAT_0057c714 + (iVar2 + param_2) * 4));
        if (this != (void *)0x0) {
          local_248 = (&DAT_005687dc)[iVar2];
          iVar2 = 0x512 - iVar2;
          iVar3 = local_254 + 0x501;
          goto LAB_0049677b;
        }
LAB_004968cb:
        iVar2 = DAT_0057c670;
      }
      local_254 = local_254 + 1;
    } while (local_254 <= local_24c);
  }
  return;
}

