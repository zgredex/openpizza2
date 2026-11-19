// rea decompile_all
// name: FUN_005524cd
// address: 0x5524cd
// body: available
// range: 0x5524cd-0x552753 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005524cd(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_8;
  
  FUN_0055395d(0xc);
  DAT_00576ad8 = 0xffffffff;
  DAT_00576ac8 = 0xffffffff;
  DAT_00585670 = 0;
  _Str1 = (uint *)FUN_00555d5c("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_005539be(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00585678);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_00576a30 = (void *)(DAT_00585678 * 0x3c);
    DAT_00585670 = 1;
    if (DAT_005856be != 0) {
      DAT_00576a30 = (void *)((int)DAT_00576a30 + DAT_005856cc * 0x3c);
    }
    if ((DAT_00585712 == 0) || (DAT_00585720 == 0)) {
      DAT_00576a34 = 0;
      _DAT_00576a38 = 0;
    }
    else {
      DAT_00576a34 = 1;
      _DAT_00576a38 = (DAT_00585720 - DAT_005856cc) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_005857dc,0x220,(LPCWSTR)&DAT_0058567c,-1,PTR_DAT_00576abc,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_00576abc = 0;
    }
    else {
      PTR_DAT_00576abc[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_005857dc,0x220,(LPCWSTR)&DAT_005856d0,-1,PTR_DAT_00576ac0,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_00576ac0[0x3f] = 0;
      return;
    }
LAB_0055273e:
    *PTR_DAT_00576ac0 = 0;
  }
  else {
    if (((char)*_Str1 != '\0') &&
       ((DAT_00585724 == (uint *)0x0 ||
        (iVar4 = _strcmp((char *)_Str1,(char *)DAT_00585724), iVar4 != 0)))) {
      FUN_00551005(DAT_00585724);
      sVar5 = _strlen((char *)_Str1);
      DAT_00585724 = _malloc(sVar5 + 1);
      if (DAT_00585724 != (uint *)0x0) {
        FUN_00553620(DAT_00585724,_Str1);
        FUN_005539be(0xc);
        _strncpy(PTR_DAT_00576abc,(char *)_Str1,3);
        _Source = (uint *)((int)_Str1 + 3);
        PTR_DAT_00576abc[3] = 0;
        cVar1 = *(char *)_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 1;
        }
        iVar4 = FUN_0054e0cc(this,(byte *)_Source);
        DAT_00576a30 = (void *)(iVar4 * 0xe10);
        for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = (uint *)((int)_Source + 1)) {
        }
        if ((char)*_Source == ':') {
          _Source = (uint *)((int)_Source + 1);
          iVar4 = FUN_0054e0cc(DAT_00576a30,(byte *)_Source);
          DAT_00576a30 = (void *)((int)DAT_00576a30 + iVar4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
              _Source = (uint *)((int)_Source + 1)) {
          }
          if ((char)*_Source == ':') {
            _Source = (uint *)((int)_Source + 1);
            iVar4 = FUN_0054e0cc(DAT_00576a30,(byte *)_Source);
            DAT_00576a30 = (void *)((int)DAT_00576a30 + iVar4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
                _Source = (uint *)((int)_Source + 1)) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_00576a30 = (void *)-(int)DAT_00576a30;
        }
        DAT_00576a34 = (int)(char)*_Source;
        if (DAT_00576a34 != 0) {
          _strncpy(PTR_DAT_00576ac0,(char *)_Source,3);
          PTR_DAT_00576ac0[3] = 0;
          return;
        }
        goto LAB_0055273e;
      }
    }
    FUN_005539be(0xc);
  }
  return;
}

