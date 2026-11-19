// rea decompile_all
// name: FUN_0053ed70
// address: 0x53ed70
// body: available
// range: 0x53ed70-0x53ef54 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0053ed70(void *this,undefined4 param_1,HWND param_2,int param_3,int *param_4)

{
  LPVOID *ppv;
  void *pvVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_0055ade8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = 1;
  ppv = (LPVOID *)((int)this + 8);
  local_4 = 0;
  *ppv = (LPVOID)0x0;
  *(undefined1 *)((int)this + 0xc) = 0;
  *(undefined ***)this = &PTR_LAB_0055c830;
  if (param_4 != (int *)0x0) {
    if (*param_4 < 0) {
      ExceptionList = pvVar1;
      return this;
    }
    *param_4 = 0;
  }
  HVar2 = CoInitialize((LPVOID)0x0);
  if (HVar2 < 0) {
    *(undefined1 *)((int)this + 0xc) = 0;
    if (HVar2 != -0x7ffefefa) {
      FUN_0048e0a0();
      if (param_4 == (int *)0x0) {
        ExceptionList = local_c;
        return this;
      }
      *param_4 = HVar2;
      ExceptionList = local_c;
      return this;
    }
  }
  else {
    *(undefined1 *)((int)this + 0xc) = 1;
  }
  HVar2 = CoCreateInstance((IID *)&DAT_0055cba8,(LPUNKNOWN)0x0,1,(IID *)&DAT_0055cb98,ppv);
  if (HVar2 < 0) {
    FUN_0048e0a0();
    *ppv = (LPVOID)0x0;
    if (param_4 == (int *)0x0) {
      ExceptionList = local_c;
      return this;
    }
    *param_4 = HVar2;
    ExceptionList = local_c;
    return this;
  }
  iVar3 = (**(code **)(*(int *)*ppv + 0x28))(*ppv,param_1);
  if (iVar3 < 0) {
    Sound_SetLastError(&DAT_00585578,s_initializing_DirectSound__00574b30,iVar3,unaff_EDI);
  }
  else {
    if ((param_2 == (HWND)0x0) && (param_2 = GetForegroundWindow(), param_2 == (HWND)0x0)) {
      param_2 = GetDesktopWindow();
    }
    iVar3 = (**(code **)(*(int *)*ppv + 0x18))(*ppv,param_2,param_3);
    if (-1 < iVar3) {
      if (param_3 == 3) {
        (**(code **)(*(int *)*ppv + 0x1c))(*ppv);
        ExceptionList = local_c;
        return this;
      }
      ExceptionList = local_c;
      return this;
    }
    Sound_SetLastError(&DAT_00585578,s_setting_cooperative_level__00574b4c,iVar3,unaff_EDI);
  }
  (**(code **)(*(int *)*ppv + 8))(*ppv);
  *ppv = (LPVOID)0x0;
  if (iVar3 < -0x7ffbfeef) {
    if (iVar3 == -0x7ffbfef0) {
      iVar3 = -0x7ffbfef0;
      goto LAB_0053ef42;
    }
    if (iVar3 == -0x7fffbfff) {
      iVar3 = -0x7fffbfff;
      goto LAB_0053ef42;
    }
    if (iVar3 == -0x7fffbffe) {
      iVar3 = -0x7fffbffe;
      goto LAB_0053ef42;
    }
    if (iVar3 == -0x7fffbffb) {
      iVar3 = -0x7fffbffb;
      goto LAB_0053ef42;
    }
  }
  else {
    if (iVar3 == -0x7ff8fff2) {
      iVar3 = -0x7ff8fff2;
      goto LAB_0053ef42;
    }
    if (iVar3 == -0x7ff8ffa9) {
      iVar3 = -0x7ff8ffa9;
      goto LAB_0053ef42;
    }
  }
  iVar3 = -0x7fff0001;
LAB_0053ef42:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
  ExceptionList = local_c;
  return this;
}

