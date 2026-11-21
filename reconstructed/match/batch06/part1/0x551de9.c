/* String_MakeRoomAtFront: shifts a string to open room for a prefix (0x551de9).
   Built with /Oi- so the strlen call is emitted instead of the intrinsic. */
extern "C" unsigned int strlen(const char *text);
extern "C" void *memmove(void *dest, const void *source, unsigned int count);

void String_MakeRoomAtFront(char *text, int room)
{
    if (room != 0) {
        memmove(text + room, text, strlen(text) + 1);
    }
}
