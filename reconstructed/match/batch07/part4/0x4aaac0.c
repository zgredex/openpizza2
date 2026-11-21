/* Calendar_IsSelectedDate: reports whether the calendar cursor matches the
   selected date (0x4aaac0). */
extern char *DAT_0057c670;
extern int DAT_00569354;
extern int DAT_0057d5c8;

unsigned char __cdecl Calendar_IsSelectedDate(void)
{
    char *calendar = *(char **)(DAT_0057c670 + 0x94);

    if (DAT_00569354 == *(unsigned short *)(calendar + 4) &&
        (DAT_0057d5c8 == *(unsigned char *)(calendar + 8) + 1 ||
         DAT_0057d5c8 == 0))
        return 1;
    return 0;
}
