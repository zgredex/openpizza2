/* Surface_FillFF: fills a 16-bit surface with 0xffff (0x534df0). */
#pragma intrinsic(memset)
void *memset(void *dest, int value, unsigned int count);

void __fastcall Surface_FillFF(int surface)
{
    int count = *(int *)(surface + 0x10) * *(int *)(surface + 8);

    memset(*(void **)(surface + 0x14), 0xff, count * 2);
}
