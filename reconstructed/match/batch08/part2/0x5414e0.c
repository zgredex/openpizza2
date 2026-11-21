/* Input_GetDeviceObjectInfo: queries a DirectInput device object and checks
   its supported flag (0x5414e0). */
struct DeviceVtbl {
    void *slot0;
    void *slot1;
    void *slot2;
    void *slot3;
    void *slot4;
    int (__stdcall *GetObjectInfo)(void *device, void *guid, int object,
                                   int *info);
};

struct Device {
    struct DeviceVtbl *vtbl;
};

extern int DAT_0055cbe8;

int __cdecl Input_GetDeviceObjectInfo(struct Device *device, int object)
{
    int local = 0;
    int result;

    result = device->vtbl->GetObjectInfo(device, &DAT_0055cbe8, object, &local);
    if (result < 0 || (local & 1) == 0)
        return 0;
    return 1;
}
