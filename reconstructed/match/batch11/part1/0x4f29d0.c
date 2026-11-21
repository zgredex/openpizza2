/* IsMenuIdRange: reports whether an id belongs to the menu id block
   (0x4f29d0). */
extern "C" int __stdcall IsMenuIdRange(int id)
{
    if (id == 0x34e || id == 0x34d || id == 0x34f || id == 0x352 ||
        id == 0x353 || id == 0x354 || id == 0x350 || id == 0x355 ||
        id == 0x351)
        return 1;
    return 0;
}
