// rea decompile_all
// name: Game_AcquireStateLock
// address: 0x486be0
// body: available
// range: 0x486be0-0x486dfe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_AcquireStateLock(void *this,int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 == *(DWORD *)(*(int *)((int)this + 0x90) + 0x10)) {
    iVar2 = 0;
  }
  else {
    iVar2 = (DVar1 != *(DWORD *)(DAT_0057c5e0 + 0x830c)) + 1;
  }
  DebugConsole_Printf(DAT_0057c1e0,0x8000c0,(byte *)s_Want_Lock__s___08x_00568174,
                      (&PTR_DAT_00567e88)[iVar2]);
  if (DVar1 != *(DWORD *)(*(int *)((int)this + 0x90) + 0x10)) {
    if (DVar1 != *(DWORD *)(DAT_0057c5e0 + 0x830c)) {
      *(undefined4 *)((int)this + 0x2d18) = 1;
      CS_Enter(*(int *)((int)this + 0x23c));
LAB_00486d75:
      iVar2 = *(int *)((int)this + 0x250);
      if (param_1 == 0) {
joined_r0x00486d94:
        if ((iVar2 == 0) && (*(int *)((int)this + 0x24c) == 0)) goto LAB_00486dd0;
      }
      else if (iVar2 == 0) {
        iVar2 = *(int *)(*(int *)((int)this + 0x90) + 0x38);
        goto joined_r0x00486d94;
      }
      if ((*(int *)((int)this + 0x2d10) != 0) || (*(int *)((int)this + 0x2d14) != 0)) {
        CS_Leave(*(int *)((int)this + 0x23c));
        Sleep(10);
        CS_Enter(*(int *)((int)this + 0x23c));
      }
      goto LAB_00486d75;
    }
    *(undefined4 *)((int)this + 0x2d14) = 1;
    CS_Enter(*(int *)((int)this + 0x23c));
    iVar2 = *(int *)((int)this + 0x254);
    while ((iVar2 != 0 && (Sleep(10), *(int *)((int)this + 0x2d18) == 0))) {
      iVar2 = *(int *)((int)this + 0x254);
    }
LAB_00486d00:
    iVar2 = *(int *)((int)this + 0x250);
    if (param_1 == 0) {
joined_r0x00486d1f:
      if (iVar2 == 0) goto LAB_00486d47;
    }
    else if (iVar2 == 0) {
      iVar2 = *(int *)(*(int *)((int)this + 0x90) + 0x38);
      goto joined_r0x00486d1f;
    }
    if (*(int *)((int)this + 0x2d10) != 0) {
      CS_Leave(*(int *)((int)this + 0x23c));
      Sleep(10);
      CS_Enter(*(int *)((int)this + 0x23c));
    }
    goto LAB_00486d00;
  }
  *(undefined4 *)((int)this + 0x2d10) = 1;
  CS_Enter(*(int *)((int)this + 0x23c));
  iVar2 = *(int *)((int)this + 0x24c);
  while ((iVar2 != 0 && (Sleep(10), *(int *)((int)this + 0x2d14) == 0))) {
    iVar2 = *(int *)((int)this + 0x24c);
  }
  iVar2 = *(int *)((int)this + 0x254);
  while ((iVar2 != 0 && (Sleep(10), *(int *)((int)this + 0x2d18) == 0))) {
    iVar2 = *(int *)((int)this + 0x254);
  }
  *(undefined4 *)((int)this + 0x2d10) = 0;
LAB_00486dde:
  DebugConsole_Printf(DAT_0057c1e0,0x8000c0,(byte *)s_OK_Lock___08x_00568164,DVar1);
  return;
LAB_00486dd0:
  *(undefined4 *)((int)this + 0x2d18) = 0;
  goto LAB_00486dde;
LAB_00486d47:
  *(undefined4 *)((int)this + 0x2d14) = 0;
  goto LAB_00486dde;
}

