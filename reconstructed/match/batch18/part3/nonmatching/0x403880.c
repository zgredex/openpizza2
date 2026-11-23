/* String_CompareLocalizedNoCase: compares two localized strings ignoring case
   and treating the German umlauts as their base letters (0x403880). */
extern "C" int __cdecl String_CompareLocalizedNoCase(unsigned int *param_1, int *param_2)
{
    int iVar2;
    int iVar3;
    char *pcVar4;
    int iVar5;
    int iVar6;
    char cVar1;

    char *s2 = (char *)*param_2;
    pcVar4 = (char *)*param_1;
    iVar6 = 0;
    cVar1 = *pcVar4;
    if (cVar1 != '\0') {
        iVar5 = (int)s2 - (int)pcVar4;
        do {
            iVar3 = (int)pcVar4[iVar5];
            iVar2 = (int)cVar1;
            if ((iVar2 == -0x3c) || (iVar2 == -0x1c)) {
                iVar2 = 0x61;
            } else if ((iVar2 == -0x2a) || (iVar2 == -10)) {
                iVar2 = 0x6f;
            } else if ((iVar2 == -0x24) || (iVar2 == -4)) {
                iVar2 = 0x75;
            }
            if ((iVar3 == -0x3c) || (iVar3 == -0x1c)) {
                iVar3 = 0x61;
            } else if ((iVar3 == -0x2a) || (iVar3 == -10)) {
                iVar3 = 0x6f;
            } else if ((iVar3 == -0x24) || (iVar3 == -4)) {
                iVar3 = 0x75;
            }
            if ((0x40 < iVar2) && (iVar2 < 0x5b)) {
                iVar2 = iVar2 + 0x20;
            }
            if ((0x40 < iVar3) && (iVar3 < 0x5b)) {
                iVar3 = iVar3 + 0x20;
            }
            if (iVar2 != iVar3) {
                return iVar2 >= iVar3 ? 1 : -1;
            }
            cVar1 = pcVar4[1];
            iVar6 = iVar6 + 1;
            pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
    }
    return -((*(char *)(s2 + iVar6)) != '\0');
}
