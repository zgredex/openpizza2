// rea decompile_all
// name: Game_Construct
// address: 0x4e64c0
// body: available
// range: 0x4e64c0-0x4e9d68 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall Game_Construct(void *this,undefined4 param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  int *piVar11;
  longlong lVar12;
  undefined2 *local_178;
  int local_174;
  double dStack_170;
  double dStack_168;
  undefined8 local_160;
  undefined4 auStack_158 [2];
  undefined4 auStack_150 [2];
  double dStack_148;
  int local_13c [8];
  void *local_11c;
  CHAR local_118 [260];
  void *pvStack_14;
  undefined1 *puStack_10;
  int local_c;
  
                    /* Constructs the game/engine object and loads its animation banks. */
  local_c = 0xffffffff;
  puStack_10 = &LAB_00559e3d;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  local_11c = this;
  FUN_004013a0((void *)((int)this + 0x2c3f8),0);
  *(undefined ***)this = &PTR_FUN_0055c5d0;
  local_13c[1] = 0xab;
  local_13c[3] = 0xab;
  local_13c[7] = 0xab;
  *(undefined4 *)((int)this + 0x2bf44) = param_1;
  *(undefined1 *)((int)this + 0x2bf48) = 0xff;
  *(undefined4 *)((int)this + 0x2f87c) = 0;
  *(undefined4 *)((int)this + 0x2f880) = 0;
  *(undefined4 *)((int)this + 0x2f884) = 0;
  *(undefined4 *)((int)this + 0x2f88c) = 0;
  *(undefined4 *)((int)this + 0x2f888) = 0;
  DAT_0058072c = 0;
  _DAT_00580a48 = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_c._1_3_ = 0;
  local_13c[0] = 0x6c;
  local_13c[2] = 0x56;
  local_13c[4] = 0x6b;
  local_13c[5] = 0xaa;
  local_13c[6] = 0x56;
  *(undefined4 *)((int)this + 0x20) = 0;
  iVar7 = 0;
  do {
    local_c._0_1_ = 0;
    FUN_0054dd83(local_118,(byte *)s_pink__02d_spr_005718b8,iVar7);
    pvVar2 = operator_new(0x50);
    local_c._0_1_ = 1;
    if (pvVar2 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_0053c7f0(pvVar2,DAT_0057c5c8,*(void **)((int)this + 0x2bf44),local_118,
                            (undefined4 *)0x0,0,(void *)0x0,0);
    }
    (&DAT_005806ec)[iVar7] = puVar3;
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0054dd83(local_118,(byte *)s_ping__02d_spr_005718a8,iVar7);
    pvVar2 = operator_new(0x50);
    local_c._0_1_ = 2;
    if (pvVar2 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_0053c7f0(pvVar2,DAT_0057c5c8,*(void **)((int)this + 0x2bf44),local_118,
                            (undefined4 *)0x0,0,(void *)0x0,0);
    }
    (&DAT_0058070c)[iVar7] = puVar3;
    iVar7 = iVar7 + 1;
    local_c._0_1_ = 0;
  } while (iVar7 < 8);
  pvVar2 = operator_new(0x50);
  local_c._0_1_ = 3;
  if (pvVar2 == (void *)0x0) {
    DAT_00580730 = (undefined4 *)0x0;
  }
  else {
    DAT_00580730 = FUN_0053c7f0(pvVar2,DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                                s_man_shadow_spr_00571898,&local_174,0,(void *)0x0,0);
  }
  local_c = (uint)local_c._1_3_ << 8;
  if (local_174 != 0) {
    if (DAT_00580730 != (undefined4 *)0x0) {
      (**(code **)*DAT_00580730)(1);
    }
    DAT_00580730 = (undefined4 *)0x0;
  }
  local_178 = (undefined2 *)((int)this + 0x2e4f4);
  local_160 = (double)((ulonglong)local_160._4_4_ << 0x20);
  pcVar6 = (char *)((int)this + 0x25);
  do {
    *local_178 = (undefined2)local_160;
    uVar4 = 0xffffffff;
    pcVar6[-1] = -1;
    pcVar8 = &DAT_00579aec;
    do {
      pcVar10 = pcVar8;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar10 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar8 = pcVar10 + -uVar4;
    pcVar10 = pcVar6;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar10 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar10 = pcVar10 + 1;
    }
    pcVar6[0x33] = '\0';
    pcVar6[0x34] = '\0';
    pcVar6[0x35] = '\0';
    pcVar6[0x36] = '\0';
    pcVar6[0x37] = '\0';
    pcVar6[0x38] = '\0';
    pcVar6[0x39] = '\0';
    pcVar6[0x3a] = '\0';
    pcVar6[0x3b] = '\0';
    pcVar6[0x3c] = '\0';
    pcVar6[0x3d] = '\0';
    pcVar6[0x3e] = '\0';
    pcVar6[0x3f] = '\0';
    pcVar6[0x40] = '\0';
    pcVar6[0x41] = '\0';
    pcVar6[0x42] = '\0';
    pcVar6[0x43] = '\0';
    pcVar6[0x44] = '\0';
    pcVar6[0x45] = '\0';
    pcVar6[0x46] = '\0';
    local_178 = local_178 + 1;
    iVar7 = (int)local_160 + 1;
    local_160 = (double)CONCAT44(local_160._4_4_,iVar7);
    pcVar6 = pcVar6 + 0x48;
    if (0x9c3 < iVar7) {
      *(undefined4 *)((int)this + 0xc) = 0;
      *(undefined4 *)((int)this + 0x14) = 0;
      *(undefined4 *)((int)this + 0x10) = 0;
      *(undefined4 *)((int)this + 0x18) = 0;
      iVar7 = 0x30;
      puVar3 = (undefined4 *)((int)this + 0x2c00c);
      do {
        puVar3[-0x30] = 0;
        *puVar3 = 0;
        puVar3[0x8a] = 0;
        puVar3[0xba] = 0;
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      puVar3 = (undefined4 *)((int)this + 0x2c180);
      iVar7 = 0x2d;
      do {
        puVar3[-0x2d] = 0;
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *(undefined4 *)((int)this + 0x2c3b4) = 0;
      *(undefined4 *)((int)this + 0x2c3b8) = 0;
      *(undefined4 *)((int)this + 0x2c3bc) = 0;
      *(undefined4 *)((int)this + 0x2c3c0) = 0;
      *(undefined4 *)((int)this + 0x2c3c8) = 0;
      *(undefined4 *)((int)this + 0x2c3c4) = 0;
      *(undefined4 *)((int)this + 0x2c3cc) = 0;
      *(undefined4 *)((int)this + 0x2c3d0) = 0;
      *(undefined4 *)((int)this + 0x2c3d4) = 0;
      puVar3 = (undefined4 *)((int)this + 0x2c3e8);
      iVar7 = 6;
      do {
        puVar3[-4] = 0;
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 4;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KID_M_SMA_ani_00571888,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf4c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 5;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TEEN_M_SMA_ani_00571878,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf50) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 6;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_STUDENT_M_SMA_ani_00571864,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf54) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 7;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROLL_M_SMA_ani_00571854,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf58) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 8;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERO_M_SMA_ani_00571844,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf5c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 9;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BONZE_M_SMA_ani_00571834,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf60) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 10;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_GRUFTIE_M_SMA_ani_00571820,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf64) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xb;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TOURISTEN_M_SMA_ani_0057180c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf68) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xc;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SERVICE_M_SMA_ani_005717f8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf98) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xd;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KOCH_M_SMA_ani_005717e8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf90) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xe;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERGERMEISTER_M_SMA_ani_005717cc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfac) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xf;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LAUFBURSCHE_M_SMA_ani_005717b4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf9c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x10;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PUNK_M_SMA_ani_005717a4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfa4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x11;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MANAGER_M_SMA_ani_00571790,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf94) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x12;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KURRIER_M_SMA_ani_0057177c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfc8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x13;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SCHLAEGER_M_SMA_ani_00571768,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfc4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x14;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_DARKMAN_SMA_ani_00571758,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfc0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x15;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_POLIZIST_SMA_ani_00571744,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf80) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x16;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BEAMTER_M_SMA_ani_00571730,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf74) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x17;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_FATMAN_M_SMA_ani_0057171c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf78) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x18;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KAMMERJAEGER_M_SMA_ani_00571704,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfcc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x19;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_REINIGUNG_M_SMA_ani_005716f0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf84) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WACHE_M_SMA_ani_005716e0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfa8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROMMI_M_SMA_ani_005716cc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf88) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WISSENSCHAFTLER_M_SMA_ani_005716b0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfd0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_KOCH_M_SMA_ani_00571694,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfe0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_SERVICE_M_SMA_ani_00571674,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfe8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x1f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_MANAGER_M_SMA_ani_00571654,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfe4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x20;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_LAUFBURSCHE_M_SMA_ani_00571630,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfec) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x21;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIEFERANT_M_SMA_ani_0057161c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bf7c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x22;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WERBEJUNGE_M_SMA_ani_00571604,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2bfd4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x23;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KID_W_SMA_ani_005715f4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c00c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x24;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TEEN_W_SMA_ani_005715e4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c010) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x25;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_STUDENT_W_SMA_ani_005715d0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c014) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x26;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROLL_W_SMA_ani_005715c0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c018) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x27;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERO_W_SMA_ani_005715b0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c01c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x28;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BONZE_W_SMA_ani_005715a0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c020) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x29;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_GRUFTIE_W_SMA_ani_0057158c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c024) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TOURISTEN_W_SMA_ani_00571578,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c028) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SERVICE_W_SMA_ani_00571564,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c058) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KOCH_W_SMA_ani_00571554,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c050) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MANAGER_W_SMA_ani_00571540,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c054) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROMMI_W_SMA_ani_0057152c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c048) = puVar3;
      *(undefined4 *)((int)this + 0x2c05c) = 0;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x2f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_KOCH_W_SMA_ani_00571510,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0a0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x30;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_SERVICE_W_SMA_ani_005714f0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0a8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x31;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ARBEITSLOS_MANAGER_W_SMA_ani_005714d0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0a4) = puVar3;
      *(undefined4 *)((int)this + 0x2c0ac) = 0;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x32;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KID_M_BIG_ani_005714c0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c234) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x33;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TEEN_M_BIG_ani_005714b0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c238) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x34;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_STUDENT_M_BIG_ani_0057149c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c23c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x35;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROLL_M_BIG_ani_0057148c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c240) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x36;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERO_M_BIG_ani_0057147c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c244) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x37;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BONZE_M_BIG_ani_0057146c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c248) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x38;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_GRUFTIE_M_BIG_ani_00571458,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c24c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x39;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TOURISTEN_M_BIG_ani_00571444,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c250) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SERVICE_M_BIG_ani_00571430,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c280) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KOCH_M_BIG_ani_00571420,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c278) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERGERMEISTER_M_BIG_ani_00571404,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c294) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LAUFBURSCHE_M_BIG_ani_005713ec,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c284) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PUNK_M_BIG_ani_005713dc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c28c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x3f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MANAGER_M_BIG_ani_005713c8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c27c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x40;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_RATTE_ani_005713bc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c29c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x41;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KAKERLAKE_ani_005713ac,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2a0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x42;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WURM_ani_005713a0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2a4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x43;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KURRIER_M_BIG_ani_0057138c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2b0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x44;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SCHLAEGER_M_BIG_ani_00571378,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2ac) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x45;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_DARKMAN_BIG_ani_00571368,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2a8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x46;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_POLIZIST_BIG_ani_00571354,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c268) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x47;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BEAMTER_M_BIG_ani_00571340,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c25c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x48;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_FATMAN_M_BIG_ani_0057132c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c260) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x49;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KAMMERJAEGER_M_BIG_ani_00571314,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2b4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_REINIGUNG_M_BIG_ani_00571300,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c26c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WACHE_M_BIG_ani_005712f0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c290) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROMMI_M_BIG_ani_005712dc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c270) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_WISSENSCHAFTLER_M_BIG_ani_005712c0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2b8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KID_W_BIG_ani_005712b0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2f4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x4f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TEEN_W_BIG_ani_005712a0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2f8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x50;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_STUDENT_W_BIG_ani_0057128c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c2fc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x51;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROLL_W_BIG_ani_0057127c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c300) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x52;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BUERO_W_BIG_ani_0057126c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c304) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x53;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BONZE_W_BIG_ani_0057125c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c308) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x54;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_GRUFTIE_W_BIG_ani_00571248,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c30c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x55;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TOURISTEN_W_BIG_ani_00571234,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c310) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x56;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_SERVICE_W_BIG_ani_00571220,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c340) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x57;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KOCH_W_BIG_ani_00571210,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c338) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x58;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MANAGER_W_BIG_ani_005711fc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c33c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x59;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_PROMMI_W_BIG_ani_005711e8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c330) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LAUFBURSCHE_M_BIG_ani_005713ec,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c344) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ALBERTO01_00_ani_005711d4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0cc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ALBERTO01_M_ani_005711c4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c180) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01A_00_ani_005711b0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0d0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01_M_ani_0057119c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c184) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x5f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01B_00_ani_00571188,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0d4) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c188) = *(undefined4 *)((int)this + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x60;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01C_00_ani_00571174,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0d8) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c18c) = *(undefined4 *)((int)this + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x61;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01D_00_ani_00571160,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0dc) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c190) = *(undefined4 *)((int)this + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x62;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01E_00_ani_0057114c,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0e0) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c194) = *(undefined4 *)((int)this + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 99;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG01F_00_ani_00571138,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0e4) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c198) = *(undefined4 *)((int)this + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 100;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02A_00_ani_00571124,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c0e8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x65;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02_M_ani_00571110,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c19c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x66;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02B_00_ani_005710fc,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0ec) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1a0) = *(undefined4 *)((int)this + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x67;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02C_00_ani_005710e8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0f0) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1a4) = *(undefined4 *)((int)this + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x68;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02D_00_ani_005710d4,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0f4) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1a8) = *(undefined4 *)((int)this + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x69;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02E_00_ani_005710c0,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0f8) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1ac) = *(undefined4 *)((int)this + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KLEINWAG02F_00_ani_005710ac,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c0fc) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1b0) = *(undefined4 *)((int)this + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01A_00_ani_00571098,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c100) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01_M_ani_00571084,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c1b4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01B_00_ani_00571070,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c104) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1b8) = *(undefined4 *)((int)this + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01C_00_ani_0057105c,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c108) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1bc) = *(undefined4 *)((int)this + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x6f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01D_00_ani_00571048,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c10c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1c0) = *(undefined4 *)((int)this + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x70;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01E_00_ani_00571034,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c110) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1c4) = *(undefined4 *)((int)this + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x71;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE01F_00_ani_00571020,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c114) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1c8) = *(undefined4 *)((int)this + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x72;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02A_00_ani_0057100c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c118) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x73;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02_M_ani_00570ff8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c1cc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x74;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02B_00_ani_00570fe4,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c11c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1d0) = *(undefined4 *)((int)this + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x75;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02C_00_ani_00570fd0,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c120) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1d4) = *(undefined4 *)((int)this + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x76;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02D_00_ani_00570fbc,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c124) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1d8) = *(undefined4 *)((int)this + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x77;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02E_00_ani_00570fa8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c128) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1dc) = *(undefined4 *)((int)this + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x78;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LIMUSINE02F_00_ani_00570f94,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c12c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1e0) = *(undefined4 *)((int)this + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x79;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LKW01A_00_ani_00570f84,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c130) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_LKW01_M_ani_00570f78,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c1e4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01A_00_ani_00570f60,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c134) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01_M_ani_00570f48,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c1e8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01B_00_ani_00570f30,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c138) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1ec) = *(undefined4 *)((int)this + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01C_00_ani_00570f18,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c13c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1f0) = *(undefined4 *)((int)this + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x7f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01D_00_ani_00570f00,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c140) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1f4) = *(undefined4 *)((int)this + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x80;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01E_00_ani_00570ee8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c144) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1f8) = *(undefined4 *)((int)this + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x81;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE01F_00_ani_00570ed0,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c148) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c1fc) = *(undefined4 *)((int)this + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x82;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02A_00_ani_00570eb8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c14c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x83;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02_M_ani_00570ea0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c200) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x84;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02B_00_ani_00570e88,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c150) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c204) = *(undefined4 *)((int)this + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x85;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02C_00_ani_00570e70,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c154) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c208) = *(undefined4 *)((int)this + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x86;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02D_00_ani_00570e58,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c158) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c20c) = *(undefined4 *)((int)this + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x87;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02E_00_ani_00570e40,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c15c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c210) = *(undefined4 *)((int)this + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x88;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_MITTELKLASSE02F_00_ani_00570e28,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c160) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c214) = *(undefined4 *)((int)this + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x89;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_POLIZEI01A_00_ani_00570e14,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c164) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_POLIZEI01_M_ani_00570e04,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c218) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01A_00_ani_00570df4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c168) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01_M_ani_00570de8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c21c) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01B_00_ani_00570dd8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c16c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c220) = *(undefined4 *)((int)this + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01C_00_ani_00570dc8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c170) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c224) = *(undefined4 *)((int)this + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x8f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01D_00_ani_00570db8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c174) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c228) = *(undefined4 *)((int)this + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x90;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01E_00_ani_00570da8,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c178) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c22c) = *(undefined4 *)((int)this + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x91;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_VAN01F_00_ani_00570d98,&local_174,1);
      }
      *(undefined4 **)((int)this + 0x2c17c) = puVar3;
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 *)((int)this + 0x2c230) = *(undefined4 *)((int)this + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x92;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TEUFEL_ani_00570d8c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3c0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x93;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ENGEL_ani_00570d80,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3bc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x94;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_GRAFFITI_ani_00570d70,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3c8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x95;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_STINKBOMBE_ani_00570d60,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3c4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x96;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_KOPFICON_ani_00565e68,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3b4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x97;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_TPIZZA_ani_00570d54,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3b8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x98;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_BOMBE_ani_00570d48,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3d0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x99;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_EXPLO_ani_00570d3c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3cc) = puVar3;
      FUN_00534ac0(puVar3,0,(undefined4 *)&dStack_170,(undefined4 *)&dStack_168,auStack_150,
                   auStack_158);
      dStack_170 = dStack_170 + 18.0;
      dStack_168 = dStack_168 - 14.0;
      FUN_00534b30(*(void **)((int)this + 0x2c3cc),0,(undefined4 *)&dStack_170,
                   (undefined4 *)&dStack_168,auStack_150,auStack_158);
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9a;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP01A_00_ani_00570d2c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3d4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9b;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WLOGO_01_ani_00570d18,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3d8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9c;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WLOGO_02_ani_00570d04,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3dc) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9d;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WLOGO_03_ani_00570cf0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3e0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9e;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WLOGO_04_ani_00570cdc,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3e4) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0x9f;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WSCHILD_01_ani_00570cc8,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3e8) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xa0;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WSCHILD_02_ani_00570cb4,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3ec) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xa1;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WSCHILD_03_ani_00570ca0,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3f0) = puVar3;
      pvVar2 = operator_new(0x98);
      local_c._0_1_ = 0xa2;
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = Anim_Load(pvVar2,(int)DAT_0057c5c8,*(void **)((int)this + 0x2bf44),
                           s_ZEP_WSCHILD_04_ani_00570c8c,&local_174,1);
      }
      local_c = (uint)local_c._1_3_ << 8;
      *(undefined4 **)((int)this + 0x2c3f4) = puVar3;
      piVar9 = local_13c + 1;
      puVar3 = (undefined4 *)((int)this + 0x2c3e8);
      local_178 = (undefined2 *)0x4;
      do {
        FUN_00534ac0((void *)puVar3[-4],0,(undefined4 *)&dStack_170,(undefined4 *)&dStack_168,
                     auStack_150,auStack_158);
        local_160 = (double)piVar9[-1];
        dStack_170 = dStack_170 - local_160;
        dStack_148 = (double)*piVar9;
        dStack_168 = dStack_168 - dStack_148;
        FUN_00534b30((void *)puVar3[-4],0,(undefined4 *)&dStack_170,(undefined4 *)&dStack_168,
                     auStack_150,auStack_158);
        FUN_00534ac0((void *)*puVar3,0,(undefined4 *)&dStack_170,(undefined4 *)&dStack_168,
                     auStack_150,auStack_158);
        dStack_170 = dStack_170 - local_160;
        dStack_168 = dStack_168 - dStack_148;
        FUN_00534b30((void *)*puVar3,0,(undefined4 *)&dStack_170,(undefined4 *)&dStack_168,
                     auStack_150,auStack_158);
        puVar3 = puVar3 + 1;
        piVar9 = piVar9 + 2;
        local_178 = (undefined2 *)((int)local_178 + -1);
      } while (local_178 != (undefined2 *)0x0);
      iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3b8),-1);
      *(int *)((int)this + 0x2c414) = iVar7;
      iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3b4),-1);
      *(int *)((int)this + 0x2c418) = iVar7;
      piVar9 = (int *)((int)this + 0x2c498);
      piVar11 = (int *)((int)this + 0x2c41c);
      local_178 = (undefined2 *)0x6;
      do {
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3d4),-1);
        *piVar11 = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3e8),-1);
        piVar9[-1] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3ec),-1);
        *piVar9 = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3f0),-1);
        piVar9[1] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3f4),-1);
        piVar9[2] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3d8),-1);
        piVar9[-0x19] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3dc),-1);
        piVar9[-0x18] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3e0),-1);
        piVar9[-0x17] = iVar7;
        iVar7 = FUN_005338c0(*(void **)((int)this + 0x2c3e4),-1);
        piVar9[-0x16] = iVar7;
        piVar11 = piVar11 + 1;
        piVar9 = piVar9 + 4;
        local_178 = (undefined2 *)((int)local_178 + -1);
      } while (local_178 != (undefined2 *)0x0);
      iVar7 = 0;
      puVar3 = (undefined4 *)((int)this + 0x2c4f4);
      do {
        lVar12 = __ftol();
        *puVar3 = (int)lVar12;
        iVar7 = iVar7 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar7 < 0x800);
      ExceptionList = pvStack_14;
      return this;
    }
  } while( true );
}

