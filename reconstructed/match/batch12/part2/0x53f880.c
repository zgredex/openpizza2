/* Sound_AllocDecompressedBuffer: allocates the decompression buffer
   (0x53f880). */
extern char DAT_00574e78;
extern char DAT_00585578;
void *__cdecl operator_new(unsigned size);
void __cdecl NoOp_Stub(void *first, void *second, int value);

extern "C" int __fastcall Sound_AllocDecompressedBuffer(void *buffer)
{
    if (*(short *)((char *)buffer + 0x14) != 0x11 ||
        *(short *)((char *)buffer + 0x22) != 4) {
        return 0x80004001;
    }
    if (*(unsigned short *)((char *)buffer + 0x20) > 0x800) {
        NoOp_Stub(&DAT_00585578, &DAT_00574e78,
                  *(int *)((char *)buffer + 0x10));
        return 0x80004001;
    }
    {
        void *memory = operator_new(
            (unsigned)*(unsigned short *)((char *)buffer + 0x20) << 3);

        *(void **)((char *)buffer + 0x3c) = memory;
        return memory != 0 ? 0 : 0x8007000e;
    }
}
