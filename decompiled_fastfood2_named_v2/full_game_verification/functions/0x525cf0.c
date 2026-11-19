// rea decompile_all
// name: Window_HandleInputMessage
// address: 0x525cf0
// body: available
// range: 0x525cf0-0x525fc1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Window_HandleInputMessage(void *this,int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  tagRECT local_10;
  
  iVar1 = param_2;
  if (((param_2 != 0x200) || (*(int *)((int)this + 0x284) == 0)) || (DAT_00584504 == 0))
  goto LAB_00525e95;
  uVar5 = param_4 & 0xffff;
  uVar4 = param_4 >> 0x10;
  if (*(int *)(*(int *)((int)this + 0x8310) + 0x14) == 0) goto LAB_00525e95;
  CS_Enter(*(int *)((int)this + 0x1c8));
  if (*(int *)((int)this + 0x1b4) == 0) {
    if (*(void **)((int)this + 0x1bc) == (void *)0x0) {
      uVar3 = Surface_GetDescription
                        (*(void **)((int)this + 0xc),*(int **)((int)this + 0x1c0),&param_2);
      Surface_Configure(*(void **)((int)this + 0xc),uVar3,(ushort)*(undefined4 *)((int)this + 0x270)
                        ,(ushort)*(undefined4 *)((int)this + 0x274),param_2);
      Surface_IsReady(*(int **)((int)this + 0x1c0));
      iVar2 = Renderer_ComposeSpriteScaled
                        (*(void **)((int)this + 0x8310),*(int *)((int)this + 0xc),uVar5,uVar4,
                         &local_10);
      if (iVar2 != 0) {
        iVar2 = *(int *)((int)this + 0x1c0);
        goto LAB_00525e68;
      }
    }
    else {
      Surface_ConfigureFromOwner(*(void **)((int)this + 0x1bc),*(void **)((int)this + 0xc));
      iVar2 = Renderer_ComposeSpriteScaled
                        (*(void **)((int)this + 0x8310),*(int *)((int)this + 0xc),uVar5,uVar4,
                         &local_10);
      if (iVar2 != 0) {
        iVar2 = *(int *)((int)this + 0x1bc);
        Gfx_BlitClipped16(DAT_0057c5c8,*(HWND *)((int)this + 0x8320),*(int *)(iVar2 + 0x18),
                          local_10.left,(HDC)local_10.top,local_10.right - local_10.left,
                          local_10.bottom - local_10.top,*(int *)(iVar2 + 4),*(ushort **)(iVar2 + 8)
                          ,(HDC)0x0,-1,(ushort *)0xffffffff);
      }
    }
  }
  else {
    Surface_LockAndMark(*(void **)((int)this + 0xc));
    iVar2 = Renderer_ComposeSpriteScaled
                      (*(void **)((int)this + 0x8310),*(int *)((int)this + 0xc),uVar5,uVar4,
                       &local_10);
    Surface_ReleaseThunk(*(int *)((int)this + 0xc));
    if (iVar2 != 0) {
      iVar2 = 0;
LAB_00525e68:
      Surface_BlitRectRetry
                (*(void **)((int)this + 0xc),local_10.left,local_10.top,
                 local_10.right - local_10.left,local_10.bottom - local_10.top,0,iVar2);
    }
  }
  CS_Leave(*(int *)((int)this + 0x1c8));
LAB_00525e95:
  if (param_1 == 0) {
    uVar4 = *(uint *)((int)this + 0x32b4);
    if (uVar4 != *(uint *)((int)this + 0x32b8)) {
      while (uVar4 = uVar4 + 1 & 0x3ff, uVar4 != *(uint *)((int)this + 0x32b8)) {
        if (*(int *)((int)this + uVar4 * 0xc + 0x2b4) == iVar1) {
          *(int *)((int)this + uVar4 * 0xc + 0x2b4) = iVar1;
          *(undefined4 *)((int)this + (uVar4 * 3 + 0xae) * 4) = param_3;
          *(uint *)((int)this + uVar4 * 0xc + 700) = param_4;
          return;
        }
      }
    }
  }
  if ((*(int *)((int)this + 0x32b8) + 1U & 0x3ff) != *(uint *)((int)this + 0x32b4)) {
    if (iVar1 == 0x202) {
      if (*(int *)((int)this + 0x8350) == 0) {
        return;
      }
      *(undefined4 *)((int)this + 0x8350) = 0;
    }
    else if (iVar1 == 0x205) {
      if (*(int *)((int)this + 0x834c) == 0) {
        return;
      }
      *(undefined4 *)((int)this + 0x834c) = 0;
    }
    else if (iVar1 == 0x201) {
      *(undefined4 *)((int)this + 0x8350) = 1;
    }
    else if (iVar1 == 0x204) {
      *(undefined4 *)((int)this + 0x834c) = 1;
    }
    *(int *)((int)this + *(int *)((int)this + 0x32b8) * 0xc + 0x2b4) = iVar1;
    *(undefined4 *)((int)this + (*(int *)((int)this + 0x32b8) + 0x3a) * 0xc) = param_3;
    *(uint *)((int)this + *(int *)((int)this + 0x32b8) * 0xc + 700) = param_4;
    *(uint *)((int)this + 0x32b8) = *(int *)((int)this + 0x32b8) + 1U & 0x3ff;
  }
  return;
}

