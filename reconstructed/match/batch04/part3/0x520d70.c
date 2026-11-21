/* Buffer_ReleaseField0C: frees the buffer at 0xc and clears the field (0x520d70). */
extern void Mem_Free(void *block);

void __fastcall Buffer_ReleaseField0C(char *object)
{
    if (*(void **)(object + 0xc) != 0) {
        Mem_Free(*(void **)(object + 0xc));
    }
    *(void **)(object + 0xc) = 0;
}
