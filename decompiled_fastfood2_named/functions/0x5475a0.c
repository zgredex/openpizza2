// rea decompile_all
// name: SoundSystem_Init
// address: 0x5475a0
// body: available
// range: 0x5475a0-0x5476e3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall SoundSystem_Init(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
                    /* Initializes DirectSound and opens resources/sound.pak; logs success/failure.
                        */
  if (param_1 == 0) {
    piVar3 = *(int **)((int)this + 8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))();
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
      *(undefined4 *)((int)this + 0x10) = 0;
      *(undefined4 *)((int)this + 0x14) = 0;
      *(undefined4 *)((int)this + 0x20) = 0;
      *(undefined4 *)((int)this + 0xf4) = 0;
      *(undefined4 *)((int)this + 0xf8) = 0;
      puVar2 = (undefined4 *)((int)this + 0x244);
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      *(undefined1 *)((int)this + 0xfc) = 0;
      *(undefined1 *)((int)this + 0xfd) = 0;
      *(undefined4 *)this = 0;
      FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_Sound_disabled__005760b8,piVar3);
      return;
    }
  }
  else {
    puVar2 = (undefined4 *)((int)this + 8);
    if (*(int *)((int)this + 8) == 0) {
      FUN_00547230();
      iVar1 = Sound_CreatePrimaryBuffer(0,DAT_0057c5d0,puVar2);
      *(bool *)((int)this + 0xfd) = -1 < iVar1;
      if (-1 < iVar1) {
        *(undefined1 *)((int)this + 0xfc) = 1;
        (**(code **)(*(int *)*puVar2 + 0xc))((int *)*puVar2,1);
        (**(code **)(*(int *)*puVar2 + 0x14))((int *)*puVar2,s_Sound__005760b0);
        (**(code **)(*(int *)*puVar2 + 0x18))((int *)*puVar2,s_resources_sound_pak_0057609c);
        (**(code **)(*(int *)*puVar2 + 0x10))((int *)*puVar2,1);
        (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,0);
        (**(code **)(*(int *)*puVar2 + 0x38))((int *)*puVar2,(int)this + 0xf4);
        piVar3 = (int *)*puVar2;
        (**(code **)(*piVar3 + 0x38))(piVar3,(int)this + 0xf8);
        FUN_00547810((int)this);
        FUN_005477a0(this,&DAT_00575090);
        FUN_005478c0(this);
        FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_Sound_successfully_initialized__0057607c,piVar3
                    );
      }
    }
  }
  return;
}

