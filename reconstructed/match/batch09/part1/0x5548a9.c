/* Heap_InitSmallBlock: allocates the small block pool used by the custom
   heap (0x5548a9). */
extern void *(__stdcall *DAT_0055c114)(void *heap, unsigned int flags,
                                       unsigned int size);
extern int DAT_00585be0;
extern void *DAT_00585bdc;
extern int DAT_00585bd4;
extern int DAT_00585bd8;
extern void *DAT_00585bd0;
extern int DAT_00585bc8;

int __cdecl Heap_InitSmallBlock(void)
{
    DAT_00585bdc = DAT_0055c114((void *)DAT_00585be0, 0, 0x140);
    if (DAT_00585bdc == 0)
        return 0;
    DAT_00585bd4 = 0;
    DAT_00585bd8 = 0;
    DAT_00585bd0 = DAT_00585bdc;
    DAT_00585bc8 = 0x10;
    return 1;
}
