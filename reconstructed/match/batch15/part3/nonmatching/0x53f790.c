/* Non-matching candidate.
   First difference: offset 0x3, 121 bytes differ.
   original delays push edi until after the stream-mode compare; candidate pushes it in the prologue.
   Kept for evidence; not part of the strict match set. */
void __stdcall Stream_Seek(int position, void *handle, int origin);

struct SoundBuffer {
    unsigned SeekSample(unsigned sample);
};

unsigned SoundBuffer::SeekSample(unsigned sample)
{
    int handle = *(int *)((char *)this + 0xc);
    if (handle == 0)
        return 0x80070006;
    if (*(short *)((char *)this + 0x14) == 1) {
        Stream_Seek(*(int *)((char *)this + 0x2c) + sample, (void *)handle, 0);
        *(unsigned *)((char *)this + 0x30) = sample;
        return 0;
    }
    Stream_Seek((sample /
                 ((unsigned)*(unsigned short *)((char *)this + 0x20) * 4 -
                  (unsigned)*(unsigned short *)((char *)this + 0x16) * 0xe)) *
                    *(unsigned short *)((char *)this + 0x20) +
                *(int *)((char *)this + 0x2c),
                (void *)handle, 0);
    *(unsigned *)((char *)this + 0x30) = sample;
    *(unsigned char *)((char *)this + 0x48) = 1;
    return 0;
}
