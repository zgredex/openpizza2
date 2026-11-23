/* Sound_LoadEffectBuffers: formats and loads the sound-effect buffer names
   (0x547810). */
extern char *DAT_005750a0[];
extern char *DAT_0057510c[];
extern char *DAT_00575170[];
extern char DAT_005760c8[];

extern "C" int String_Format(char *buffer, char *format, ...);

extern "C" void __fastcall Sound_LoadEffectBuffers(int param_1)
{
    char local_104[260];
    char **ppuVar3;
    int iVar1;
    int iVar2;
    int *puVar4;
    int device;

    ppuVar3 = DAT_005750a0;
    iVar2 = param_1 + 0x24;
    do {
        String_Format(local_104, DAT_005760c8, *ppuVar3);
        device = *(int *)(param_1 + 8);
        iVar1 = (*(int (__cdecl **)(int, char *, int))(
            *(int *)device + 0x28))(device, local_104, iVar2);
        if (iVar1 < 0)
            break;
        ppuVar3 = ppuVar3 + 1;
        iVar2 = iVar2 + 4;
    } while ((int)ppuVar3 < (int)DAT_0057510c);

    ppuVar3 = DAT_0057510c;
    puVar4 = (int *)(param_1 + 0x90);
    do {
        String_Format(local_104, DAT_005760c8, *ppuVar3);
        device = *(int *)(param_1 + 8);
        iVar2 = (*(int (__cdecl **)(int, char *, int *))(
            *(int *)device + 0x28))(device, local_104, puVar4);
        if (-1 < iVar2) {
            (*(void (__cdecl **)(int, int, int))(
                *(int *)device + 0x9c))(device, *(int *)(param_1 + 0xf4),
                                        *puVar4);
        }
        ppuVar3 = ppuVar3 + 1;
        puVar4 = puVar4 + 1;
    } while ((int)ppuVar3 < (int)DAT_00575170);
}
