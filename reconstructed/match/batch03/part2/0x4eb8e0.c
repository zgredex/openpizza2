/* Map_MissingNameFallback - 0x4eb8e0, 22 bytes */
extern void Debug_WarningMessageBox(const char *format, int value);
extern char DAT_00571af4;

int Map_MissingNameFallback(int unused, int value)
{
    Debug_WarningMessageBox(&DAT_00571af4, value);
    return -1;
}
