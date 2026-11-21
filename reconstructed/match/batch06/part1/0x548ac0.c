/* Object_FlushPending: flushes the pending renderer command (0x548ac0). */
void __fastcall Object_FlushPending(char *object)
{
    if (*(char *)(object + 0x140) != 0) {
        char *renderer = *(char **)(object + 8);
        (*(void (__stdcall **)(void *, int))(*(char **)renderer + 0x68))(
            renderer, *(int *)(object + 0x80));
        *(char *)(object + 0x140) = 0;
    }
}
