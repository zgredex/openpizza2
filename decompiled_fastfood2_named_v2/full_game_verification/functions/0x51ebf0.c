// rea decompile_all
// name: Renderer_ComposeSpriteScaled
// address: 0x51ebf0
// body: available
// range: 0x51ebf0-0x51ee7a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Renderer_ComposeSpriteScaled(void *this,int param_1,int param_2,int param_3,LPRECT param_4)

{
  int xLeft;
  void *this_00;
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a51b;
  local_c = ExceptionList;
  iVar5 = *(int *)((int)this + 0x18);
  if (*(int *)((int)this + 0x14) == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  Sprite_GetSize(*(void **)this,(int *)&local_24,&local_20);
  if (*(void **)((int)this + 4) == (void *)0x0) {
    local_18 = 0;
    local_1c = 0;
  }
  else {
    Sprite_GetSize(*(void **)((int)this + 4),(int *)&local_1c,&local_18);
  }
  Sprite_GetHotspot(*(void **)this,&local_14,&local_10);
  if (param_2 == -9999) {
    if ((local_1c == local_24) && (local_18 == local_20)) {
      iVar5 = 0;
    }
    else {
      *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(*(int *)((int)this + 8) + 0x248);
      *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(*(int *)((int)this + 8) + 0x24c);
      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + *(int *)((int)this + 0x1c);
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + *(int *)((int)this + 0x20);
    }
    puVar3 = (uint *)(*(int *)((int)this + 0xc) - local_14);
    iVar4 = *(int *)((int)this + 0x10) - local_10;
  }
  else {
    puVar3 = (uint *)(param_2 + *(int *)((int)this + 0x1c));
    iVar4 = param_3 + *(int *)((int)this + 0x20);
  }
  xLeft = *(int *)((int)this + 0xc);
  if ((xLeft == -9999) || (iVar5 == 0)) {
    SetRect(param_4,-9999,0,0,0);
  }
  else {
    if (param_4 != (LPRECT)0x0) {
      SetRect(param_4,xLeft,*(int *)((int)this + 0x10),local_1c + xLeft,
              local_18 + *(int *)((int)this + 0x10));
    }
    Sprite_Draw(*(void **)((int)this + 4),param_1,*(uint **)((int)this + 0xc),
                *(int *)((int)this + 0x10));
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  *(int *)((int)this + 0x10) = local_10 + iVar4;
  puVar1 = *(undefined4 **)((int)this + 4);
  *(int *)((int)this + 0xc) = local_14 + (int)puVar3;
  if ((puVar1 != (undefined4 *)0x0) && ((local_1c != local_24 || (local_18 != local_20)))) {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (*(int *)((int)this + 4) == 0) {
    this_00 = operator_new(0x50);
    uStack_4 = 0;
    if (this_00 == (void *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = Sprite_CreateRaw(this_00,local_24,local_20,0,0x10,0);
    }
    uStack_4 = 0xffffffff;
    *(undefined4 **)((int)this + 4) = puVar1;
  }
  uVar6 = *(uint *)((int)this + 0x10);
  iVar5 = *(int *)((int)this + 0xc);
  puVar1 = (undefined4 *)Sprite_GetPixelBuffer(*(void **)((int)this + 4));
  Gfx_BlitScaled16Rows(*(void **)((int)this + 4),param_1,puVar1,iVar5,uVar6);
  *(undefined4 *)((int)this + 0x18) = 1;
  Sprite_Draw(*(void **)this,param_1,puVar3,iVar4);
  if (param_4 != (LPRECT)0x0) {
    puVar2 = (uint *)param_4->left;
    if (puVar2 == (uint *)0xffffd8f1) {
      param_4->left = (LONG)puVar3;
      param_4->top = iVar4;
      param_4->right = local_24 + (int)puVar3;
      param_4->bottom = local_20 + iVar4;
    }
    else {
      if ((int)puVar3 < (int)puVar2) {
        puVar2 = puVar3;
      }
      param_4->left = (LONG)puVar2;
      iVar5 = param_4->top;
      if (iVar4 < param_4->top) {
        iVar5 = iVar4;
      }
      param_4->top = iVar5;
      iVar5 = local_24 + (int)puVar3;
      if ((int)(local_24 + (int)puVar3) <= param_4->right) {
        iVar5 = param_4->right;
      }
      param_4->right = iVar5;
      iVar5 = local_20 + iVar4;
      if (local_20 + iVar4 <= param_4->bottom) {
        iVar5 = param_4->bottom;
      }
      param_4->bottom = iVar5;
    }
  }
  ExceptionList = local_c;
  return 1;
}

