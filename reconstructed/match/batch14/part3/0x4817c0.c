/* System_QueryMemoryInfo (0x4817c0): stores physical and video memory sizes
   in megabytes. */
struct MEMORYSTATUS {
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

extern "C" __declspec(dllimport)
void __stdcall GlobalMemoryStatus(MEMORYSTATUS *status);

extern "C" {
void *memset(void *dest, int value, unsigned int count);
}

struct DeviceInfo {
    unsigned long size;
    char pad[0x38];
    unsigned long availableMemory;
    char rest[0x16c - 0x40];
};

struct Device {
    void **vtable;
};

struct SystemGlobal {
    char pad[0x40];
    Device **deviceSlot;
};

extern SystemGlobal *DAT_0057c5c8;

typedef void (__stdcall *DeviceQueryFn)(void *self, DeviceInfo *info,
                                        int flags);

struct System {
    char pad[0x2e1c];
    unsigned long physicalMemory;
    unsigned long videoMemory;

    void QueryMemoryInfo();
};

void System::QueryMemoryInfo()
{
    MEMORYSTATUS status;
    DeviceInfo info;

    GlobalMemoryStatus(&status);
    physicalMemory = (status.dwTotalPhys + 0xfffff) >> 20;
    if (DAT_0057c5c8->deviceSlot != 0 && *DAT_0057c5c8->deviceSlot != 0) {
        Device *device = *DAT_0057c5c8->deviceSlot;

        memset(&info, 0, sizeof(info));
        info.size = 0x16c;
        (*(DeviceQueryFn *)(*(char **)device + 0x2c))(device, &info, 0);
        videoMemory = (info.availableMemory + 0xfffff) >> 20;
    }
}
