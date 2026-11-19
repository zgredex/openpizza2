// rea decompile_all
// name: UI_Child_HandleControlCommand
// address: 0x521390
// body: available
// range: 0x521390-0x521519 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall
UI_Child_HandleControlCommand(void *this,uint param_1,undefined4 param_2,int param_3)

{
  void *local_4;
  
  local_4 = this;
  switch(param_1) {
  case 4:
    break;
  case 5:
    if (*(int *)((int)this + 0x50) == 0) {
      return *(uint *)((int)this + 0x58) | *(uint *)((int)this + 0x54);
    }
    *(undefined4 *)((int)this + 0x50) = 0;
    return *(uint *)((int)this + 0x58) | *(uint *)((int)this + 0x54);
  case 6:
    UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),6,param_3);
    *(undefined4 *)((int)this + 0x54) = 1;
    return *(uint *)((int)this + 0x58) | 1;
  case 7:
    if (*(int *)((int)this + 0x50) != 0) {
      UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),5,0);
    }
    UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),7,param_3);
    *(undefined4 *)((int)this + 0x54) = 0;
    return *(uint *)((int)this + 0x58);
  case 8:
    UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),9,param_3);
    *(undefined4 *)((int)this + 0x58) = 1;
    return *(uint *)((int)this + 0x54) | 1;
  case 9:
    UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),10,param_3);
    *(undefined4 *)((int)this + 0x58) = 0;
    return *(uint *)((int)this + 0x54);
  case 10:
    *(undefined4 *)((int)this + 0x50) = 0;
    *(undefined4 *)((int)this + 0x58) = 0;
    *(undefined4 *)((int)this + 0x54) = 0;
  default:
    return 0;
  case 0x36:
    return (uint)this;
  case 0xd4:
  case 0xde:
    return 1;
  case 0xd5:
    Sprite_GetSize(*(void **)((int)this + 0x60),(int *)&param_1,(int *)&local_4);
    return param_1;
  case 0xdf:
    Sprite_GetSize(*(void **)((int)this + 0x60),(int *)&param_1,(int *)&local_4);
    return (uint)local_4;
  }
  UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),8,param_3);
  if (*(int *)((int)this + 0x50) == 0) {
    *(undefined4 *)((int)this + 0x50) = 1;
    return *(uint *)((int)this + 0x58) | *(uint *)((int)this + 0x54);
  }
  return *(uint *)((int)this + 0x58) | *(uint *)((int)this + 0x54);
}

