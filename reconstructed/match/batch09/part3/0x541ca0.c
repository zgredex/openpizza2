/* Sound_GetDeviceCaps: queries the audio device capabilities and reports
   whether 3D hardware voices are available (0x541ca0). */
struct ICapsVtbl {
    char pad[0x10];
    int (__stdcall *GetCaps)(void *self, void *caps);
};

struct ICaps {
    ICapsVtbl *vtbl;
};

int Sound_GetDeviceCaps(ICaps *device)
{
    unsigned int caps[24];
    int i;
    int result;
    int supported = 0;

    for (i = 0; i < 24; i++)
        caps[i] = 0;
    caps[0] = 0x60;
    result = device->vtbl->GetCaps(device, caps);
    if (result >= 0 && (((unsigned char *)caps)[4] & 0x20) != 0)
        supported = 0x10000;
    return supported;
}
