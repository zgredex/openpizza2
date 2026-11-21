/* PC2 byte-match candidate: Sprite_GetColorKey (0x53d430, 13 bytes).
   Build: /O2 /TP; entry @Sprite_GetColorKey@4. */
extern "C" int __fastcall Sprite_GetColorKey(char *self)
{
    if ((*(unsigned char *)(self + 4) & 0x10) != 0)
        return 0;
    return *(int *)(self + 0x1c);
}
