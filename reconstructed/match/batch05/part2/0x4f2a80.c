/* IsMenuId351Or355: true for either of the two briefing menu ids
   (0x4f2a80). */
int __stdcall IsMenuId351Or355(int id)
{
    if (id == 0x355 || id == 0x351)
        return 1;
    return 0;
}
