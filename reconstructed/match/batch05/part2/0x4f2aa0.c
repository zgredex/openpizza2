/* IsMenuId34EOr350: true for either of the two briefing menu ids
   (0x4f2aa0). */
int __stdcall IsMenuId34EOr350(int id)
{
    if (id == 0x34e || id == 0x350)
        return 1;
    return 0;
}
