extern int DAT_00585578;
extern char STR_00574f98[];
extern char STR_00574fa8[];

/* SoundBuffer_LockSample: locks the sample buffer, restoring it on loss
   (0x540a80). */
struct CSound {
    int Lock(int a, int b, int *p1, int *p2, int c, int d, int e);
    int Restore();
};

struct SoundBuffer {
    char pad[0x2c];
    int locked;
    int data;
    char rest[0x48 - 0x34];
    CSound *sound;
    int LockSample(int offset, int length);
};

extern "C" void __cdecl Sound_SetLastError(int *error, char *message, int code, void *object);

int SoundBuffer::LockSample(int offset, int length)
{
    CSound *object;
    int result;

    if (locked != 0) {
        return 0;
    }
    if (*(unsigned int *)((char *)this + 0x10) < (unsigned int)(length + offset)) {
        return 0;
    }
    object = sound;
    result = object->Lock(offset, length, &locked, &data, 0, 0, 0);
    for (;;) {
        if (result >= 0) {
            return locked;
        }
        if (result != -0x7787ff6a) {
            if (result < 0) {
                locked = 0;
                data = 0;
                Sound_SetLastError(&DAT_00585578, STR_00574f98, result, object);
                return 0;
            }
            return locked;
        }
        object = sound;
        if (object->Restore() < 0) {
            Sound_SetLastError(&DAT_00585578, STR_00574fa8, result, object);
            return 0;
        }
        object = sound;
        result = object->Lock(offset, length, &locked, &data, 0, 0, 0);
    }
}
