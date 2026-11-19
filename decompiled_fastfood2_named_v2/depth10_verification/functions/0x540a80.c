// rea decompile_all
// name: SoundBuffer_LockSample
// address: 0x540a80
// body: available
// range: 0x540a80-0x540b4d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall SoundBuffer_LockSample(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
                    /* Locks a DirectSound buffer range and returns its mapped pointer. */
  puVar1 = (undefined4 *)((int)this + 0x2c);
  if (*(int *)((int)this + 0x2c) != 0) {
    return 0;
  }
  if (*(uint *)((int)this + 0x10) < (uint)(param_2 + param_1)) {
    return 0;
  }
  piVar5 = *(int **)((int)this + 0x48);
  puVar2 = (undefined4 *)((int)this + 0x30);
  uVar6 = 0;
  iVar3 = (**(code **)(*piVar5 + 0x2c))(piVar5,param_1,param_2,puVar1,puVar2,0,0,0);
  do {
    if (-1 < iVar3) {
LAB_00540afd:
      return *puVar1;
    }
    if (iVar3 != -0x7787ff6a) {
      if (iVar3 < 0) {
        *puVar1 = 0;
        *puVar2 = 0;
        FUN_0053f0a0(&DAT_00585578,s_locking_sample__00574f98,iVar3,piVar5);
        return 0;
      }
      goto LAB_00540afd;
    }
    piVar4 = *(int **)((int)this + 0x48);
    iVar3 = (**(code **)(*piVar4 + 0x50))();
    if (iVar3 < 0) {
      FUN_0053f0a0(&DAT_00585578,s_restoring_sample_buffer__00574fa8,iVar3,piVar4);
      return 0;
    }
    iVar3 = (**(code **)(**(int **)((int)this + 0x48) + 0x2c))
                      (*(int **)((int)this + 0x48),param_1,uVar6,puVar1,puVar2,0,0,0);
  } while( true );
}

