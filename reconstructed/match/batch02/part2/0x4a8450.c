/* Personnel_GetTrainingLevel - 0x4a8450, 18 bytes */
extern int DAT_0057d298[];

int Personnel_GetTrainingLevel(int index)
{
    if (index == 0)
        return 0;
    return DAT_0057d298[index] + 1;
}
