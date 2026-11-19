// rea decompile_all
// name: IsoMap_RenderViewport
// address: 0x4f4400
// body: available
// range: 0x4f4400-0x4f4955 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall IsoMap_RenderViewport(void *this,void *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  char *pcVar21;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  byte *local_16c;
  int local_168;
  byte *local_15c;
  int local_158;
  undefined1 *local_154;
  int local_150;
  uint local_148;
  int local_144;
  int local_140;
  byte *local_13c;
  undefined1 *local_134;
  uint local_120;
  short local_11b;
  uint local_119;
  short local_114;
  short local_112;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar5 = DAT_00571954;
  uVar4 = DAT_00571950;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a06e;
  local_c = ExceptionList;
  iVar9 = *(int *)((int)this + 0x70);
  if (iVar9 != 0) {
    iVar15 = *(int *)(iVar9 + 8);
    iVar9 = *(int *)(iVar9 + 4);
    if (param_2 == (int *)0x0) {
      local_174 = *(int *)((int)this + 0x1016c) + *(int *)((int)this + 0x2c);
      local_170 = (*(int *)((int)this + 0x2c) - *(int *)((int)this + 0x10168)) + iVar9;
      local_184 = *(int *)((int)this + 0x30) - *(int *)((int)this + 0x10174);
      local_180 = *(int *)((int)this + 0x30) + *(int *)((int)this + 0x10170) + iVar15;
    }
    else {
      local_174 = *param_2;
      local_170 = param_2[2];
      local_184 = param_2[1];
      local_180 = param_2[3];
      iVar6 = *(int *)((int)this + 0xc) * DAT_00571960;
      iVar16 = (iVar6 - *(int *)((int)this + 0x2c)) + -0x100 + local_174;
      if (iVar16 < 0) {
        local_174 = (*(int *)((int)this + 0x2c) - iVar6) + 0x100;
        iVar16 = 0;
      }
      iVar13 = *(int *)((int)this + 0x10) * DAT_00571964;
      iVar6 = (iVar13 - *(int *)((int)this + 0x30)) + -0x80 + local_184;
      if (iVar6 < 0) {
        local_184 = (*(int *)((int)this + 0x30) - iVar13) + 0x80;
        iVar6 = 0;
      }
      if (iVar9 < (iVar16 - local_174) + local_170) {
        local_170 = (iVar9 - iVar16) + local_174;
      }
      if (iVar15 < (iVar6 - local_184) + local_180) {
        local_180 = (iVar15 - iVar6) + local_184;
      }
    }
    uVar14 = local_170 - local_174;
    local_148 = DAT_00571950;
    if ((int)uVar14 <= (int)DAT_00571950) {
      local_148 = uVar14;
    }
    local_168 = local_180 - local_184;
    local_144 = DAT_00571954;
    if (local_168 <= DAT_00571954) {
      local_144 = local_168;
    }
    ExceptionList = &local_c;
    pvVar7 = operator_new(0x11c);
    local_4 = 0;
    if (pvVar7 == (void *)0x0) {
      local_16c = (byte *)0x0;
    }
    else {
      local_16c = (byte *)Window_Construct(pvVar7,local_148,local_144,8);
    }
    local_4 = 0xffffffff;
    puVar8 = Renderer_CreateChild(param_1);
    *(undefined4 **)((int)this + 8) = puVar8;
    Surface_ConfigureFromOwner(local_16c,puVar8);
    iVar9 = Object_GetChildField14(*(int *)((int)this + 0x70));
    if (*(int *)((int)this + 0x1015c) == 0) {
      iVar9 = (*(int *)((int)this + 0xc) * DAT_00571960 - *(int *)((int)this + 0x2c)) + -0x100 +
              local_174;
      pvVar7 = *(void **)(*(int *)((int)this + 4) + 0x2bf44);
      local_17c = (*(int *)((int)this + 0x10) * DAT_00571964 - *(int *)((int)this + 0x30)) + -0x80 +
                  local_184;
      String_Format(local_10c,(byte *)s__s_tga_00571b10,&DAT_0057bb44);
      piVar12 = Resource_Open(pvVar7,local_10c,0);
      if (piVar12 != (int *)0x0) {
        Resource_Read(pvVar7,(char *)&local_120,0x12,(int)piVar12);
        pcVar21 = (char *)(*(int *)(*(int *)((int)this + 0x70) + 4) * local_17c +
                           *(int *)(*(int *)((int)this + 0x70) + 0x18) + iVar9);
        if (local_184 < local_180) {
          do {
            Stream_Seek(((local_112 - local_17c) + -1) * (int)local_114 +
                        ((int)((int)local_11b * (local_119 & 0xff)) >> 3) + 0x12 +
                        (local_120 & 0xff) + iVar9,(int)piVar12,0);
            Resource_Read(pvVar7,pcVar21,uVar14,(int)piVar12);
            pcVar21 = pcVar21 + *(int *)(*(int *)((int)this + 0x70) + 4);
            local_17c = local_17c + 1;
            local_168 = local_168 + -1;
          } while (local_168 != 0);
        }
        Resource_Close(pvVar7,(int)piVar12);
      }
    }
    else {
      local_154 = (undefined1 *)((int)this + 0x15c);
      local_15c = (byte *)(iVar9 + 2);
      local_178 = 0x100;
      do {
        bVar1 = local_15c[-2];
        bVar2 = local_15c[-1];
        bVar3 = *local_15c;
        local_150 = 0;
        local_158 = 0;
        local_17c = 0;
        local_134 = local_154;
        local_168 = 0x100;
        do {
          local_13c = (byte *)0x0;
          local_140 = 1000;
          pbVar20 = (byte *)(iVar9 + 1);
          do {
            uVar14 = (uint)pbVar20[1] - (local_150 >> 8);
            uVar17 = (int)uVar14 >> 0x1f;
            uVar10 = (uint)pbVar20[-1] - (local_17c >> 8);
            uVar18 = (int)uVar10 >> 0x1f;
            uVar11 = (uint)*pbVar20 - (local_158 >> 8);
            uVar19 = (int)uVar11 >> 0x1f;
            iVar15 = ((uVar14 ^ uVar17) - uVar17) + ((uVar10 ^ uVar18) - uVar18) +
                     ((uVar11 ^ uVar19) - uVar19);
            if (iVar15 < local_140) {
              local_13c = pbVar20 + (-1 - iVar9);
              local_140 = iVar15;
            }
            pbVar20 = pbVar20 + 3;
          } while ((int)(pbVar20 + (-1 - iVar9)) < 0x300);
          *local_134 = (char)((int)local_13c / 3);
          local_134 = local_134 + 0x100;
          local_17c = local_17c + (uint)bVar1;
          local_158 = local_158 + (uint)bVar2;
          local_150 = local_150 + (uint)bVar3;
          local_168 = local_168 + -1;
        } while (local_168 != 0);
        local_15c = local_15c + 3;
        local_154 = local_154 + 1;
        local_178 = local_178 + -1;
      } while (local_178 != 0);
    }
    *(undefined4 *)((int)this + 0x1015c) = 0;
    for (; local_184 < local_180; local_184 = local_184 + iVar5) {
      if (local_174 < local_170) {
        iVar9 = local_174;
        do {
          puVar8 = *(undefined4 **)(local_16c + 0x18);
          for (uVar14 = local_144 * local_148 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar8 = 0xffffffff;
            puVar8 = puVar8 + 1;
          }
          for (uVar14 = local_144 * local_148 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar8 = 0xff;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          *(int *)((int)this + 0x24) = iVar9;
          *(int *)((int)this + 0x28) = local_184;
          Map_UpdateObjectVisibility(this);
          Sprite_ApplyPaletteRemap(this,iVar9,local_184,local_16c,(int)this + 0x15c);
          iVar9 = iVar9 + uVar4;
        } while (iVar9 < local_170);
      }
    }
    if (*(undefined4 **)((int)this + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)this + 8))(1);
    }
    if (local_16c != (byte *)0x0) {
      (*(code *)**(undefined4 **)local_16c)(1);
    }
    *(undefined4 *)((int)this + 8) = 0;
  }
  ExceptionList = local_c;
  return;
}

