// rea decompile_all
// name: FUN_00483740
// address: 0x483740
// body: available
// range: 0x483740-0x483bb5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00483740(void *this,undefined4 param_1)

{
  int *piVar1;
  void *pvVar2;
  void *local_4;
  
  local_4 = this;
  if (*(int *)((int)this + 0x268) != 0) {
    FUN_00482890((int)this);
  }
  switch(param_1) {
  case 1:
    FUN_00456450((int *)&local_4);
    FUN_0048e0a0();
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 2:
    pvVar2 = FUN_004501c0((int *)&local_4);
    FUN_004bb760(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 3:
    pvVar2 = FUN_0045aad0((int *)&local_4);
    FUN_004c0ff0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 4:
    pvVar2 = FUN_00454ee0((int *)&local_4);
    FUN_004be490(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 5:
    pvVar2 = FUN_00453ec0((int *)&local_4);
    FUN_004bd750(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 6:
    pvVar2 = FUN_0044e390((int *)&local_4);
    FUN_004bb120(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 7:
    pvVar2 = FUN_00458140((int *)&local_4);
    FUN_004bf980(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 8:
    pvVar2 = FUN_00465600((int *)&local_4);
    FUN_004c3a40(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 9:
    pvVar2 = FUN_00468bd0((int *)&local_4);
    FUN_004c51b0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 10:
    piVar1 = FUN_0045ebd0((int *)&local_4);
    FUN_004c2950(piVar1);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xb:
    pvVar2 = FUN_004602d0((int *)&local_4);
    FUN_004c3070(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xc:
    pvVar2 = FUN_00453760((int *)&local_4);
    FUN_004bd340(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xd:
    pvVar2 = FUN_004556f0((int *)&local_4);
    FUN_004be820(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xe:
    pvVar2 = FUN_00415620((int *)&local_4);
    FUN_004951f0(pvVar2,1);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0xf:
    pvVar2 = FUN_0046ac80((int *)&local_4);
    FUN_004c5a60(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x10:
    pvVar2 = FUN_0044d8c0((int *)&local_4);
    FUN_004bade0(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x11:
    pvVar2 = FUN_00455be0((int *)&local_4);
    FUN_004befd0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x12:
    pvVar2 = FUN_00456f70((int *)&local_4);
    FUN_004bf4d0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x13:
    pvVar2 = FUN_0046a390((int *)&local_4);
    FUN_004c54d0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x14:
    pvVar2 = FUN_00458f50((int *)&local_4);
    FUN_004c03c0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x15:
    pvVar2 = FUN_0044ee20((int *)&local_4);
    FUN_004bb650(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x16:
    pvVar2 = FUN_00459300((int *)&local_4);
    FUN_004c0b30(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x17:
    pvVar2 = FUN_00451dd0((int *)&local_4);
    FUN_004bc530(pvVar2,'\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x18:
    pvVar2 = FUN_00469e30((int *)&local_4);
    FUN_004c5280(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x19:
    pvVar2 = FUN_00466b10((int *)&local_4);
    FUN_004c47d0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1a:
    pvVar2 = FUN_004508a0((int *)&local_4);
    FUN_004bbfd0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1c:
    pvVar2 = FUN_00468090((int *)&local_4);
    FUN_004c4e30(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1d:
    pvVar2 = FUN_004632c0((int *)&local_4);
    FUN_00493110(pvVar2,'\x01','\x01');
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1e:
    pvVar2 = FUN_0045d3e0((int *)&local_4);
    FUN_004c2000(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x1f:
    pvVar2 = FUN_0045c150((int *)&local_4);
    FUN_004c16e0(pvVar2);
    *(undefined4 *)((int)this + 0x2d8) = param_1;
    return (int)local_4;
  case 0x20:
    pvVar2 = FUN_00461b20((int *)&local_4);
    FUN_004c3610(pvVar2);
  }
  *(undefined4 *)((int)this + 0x2d8) = param_1;
  return (int)local_4;
}

