/* SoundFormat_Init: initializes a PCM wave format header (0x53f840). */
struct SoundFormat {
    unsigned short format;
    unsigned short channels;
    unsigned int sampleRate;
    unsigned int blockAlign;
    unsigned short bits;
    unsigned short fieldE;
    unsigned short extra;
};

void __stdcall SoundFormat_Init(struct SoundFormat *fmt)
{
    fmt->extra = 0;
    fmt->blockAlign =
        fmt->sampleRate * (unsigned short)fmt->channels * 2;
    fmt->format = 1;
    fmt->fieldE = 0x10;
    fmt->bits = fmt->channels * 2;
}
