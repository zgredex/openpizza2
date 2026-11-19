// rea decompile_all
// name: Record_DrawSprite48
// address: 0x5344e0
// body: available
// range: 0x5344e0-0x53469a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Record_DrawSprite48(void *this,uint *param_1,void *param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  longlong lVar3;
  int in_stack_00000020;
  uint in_stack_00000024;
  undefined4 uVar4;
  undefined1 uVar5;
  uint uVar6;
  
  if ((-1 < param_3) && (param_3 < *(int *)((int)this + 0x48))) {
    CS_Enter(0x5842a0);
    if (*(int *)(*(int *)((int)this + 0x4c) + param_3 * 0x48) == -1) {
      CS_Leave(0x5842a0);
      return;
    }
    if (*(char *)((int)this + 0x35) == '\0') {
      RecordList_EnsureLoaded((int)this);
    }
    uVar4 = DAT_00585518;
    iVar2 = *(int *)((int)this + 0x4c) + param_3 * 0x48;
    *(undefined2 *)((int)this + 6) =
         *(undefined2 *)(*(int *)((int)this + 0x20) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 8) =
         *(undefined2 *)(*(int *)((int)this + 0x24) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 10) =
         *(undefined2 *)(*(int *)((int)this + 0x28) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 0xc) =
         *(undefined2 *)(*(int *)((int)this + 0x2c) + *(short *)(iVar2 + 0x32) * 2);
    puVar1 = *(ushort **)(*(int *)((int)this + 0x80) + *(short *)(iVar2 + 0x32) * 4);
    if (puVar1 != (ushort *)0x0) {
      if ((((*(byte *)((int)this + 4) & 0x10) == 0) && (in_stack_00000020 != -2)) &&
         (*(char *)((int)this + 5) == '\b')) {
        if (in_stack_00000020 < 0) {
          uVar6 = 0;
          uVar4 = 0xffffffff;
          lVar3 = __ftol();
          iVar2 = (int)lVar3;
          lVar3 = __ftol();
          Sprite_BlitRLEOpaque
                    (this,param_1,(byte *)puVar1,*(int *)((int)this + 0x7c),(int)lVar3,iVar2,uVar4,
                     uVar6);
          CS_Leave(0x5842a0);
          return;
        }
        lVar3 = __ftol();
        iVar2 = (int)lVar3;
        lVar3 = __ftol();
        Sprite_BlitRLEOpaque
                  (this,param_1,(byte *)puVar1,*(int *)((int)this + 0x7c),(int)lVar3,iVar2,
                   in_stack_00000020,in_stack_00000024);
        CS_Leave(0x5842a0);
        return;
      }
      lVar3 = __ftol();
      uVar5 = (undefined1)uVar4;
      iVar2 = (int)lVar3;
      lVar3 = __ftol();
      Sprite_BlitAlphaRLE(this,param_1,param_2,puVar1,*(int *)((int)this + 0x7c),(uint *)lVar3,iVar2
                          ,uVar5);
    }
    CS_Leave(0x5842a0);
  }
  return;
}

