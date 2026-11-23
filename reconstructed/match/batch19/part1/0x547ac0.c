// Sound_SetVolumeSetting: clamps a 0..10000 scale value per channel.

extern "C" {
extern unsigned int g_Settings_LoadFromRegistry_RData_00575094;
extern unsigned int g_Settings_LoadFromRegistry_RData_00575098;
extern unsigned int g_Settings_LoadFromRegistry_RData_0057509c;
}

struct Sound {
    char SetVolumeSetting(int mode, int value);
    unsigned int ConvertVolumeSetting(int value);
};

char Sound::SetVolumeSetting(int mode, int value)
{
    unsigned int scaled = (unsigned int)(value * 10000) / 10000;
    bool changed = false;

    if (scaled > 10000)
        scaled = 10000;
    if (mode == 1) {
        changed = scaled != g_Settings_LoadFromRegistry_RData_00575094;
        g_Settings_LoadFromRegistry_RData_00575094 = scaled;
    }
    switch (mode) {
    case 1:
        *(unsigned int *)((char *)this + 0x1d0) =
            g_Settings_LoadFromRegistry_RData_00575094;
        *(unsigned int *)((char *)this + 0x1d4) =
            ConvertVolumeSetting(g_Settings_LoadFromRegistry_RData_00575098);
        *(unsigned int *)((char *)this + 0x1d8) =
            ConvertVolumeSetting(g_Settings_LoadFromRegistry_RData_0057509c);
        goto done;
    case 2:
        g_Settings_LoadFromRegistry_RData_00575098 = scaled;
        {
            unsigned int converted = ConvertVolumeSetting(scaled);
            unsigned int old = *(unsigned int *)((char *)this + 0x1d4);
            *(unsigned int *)((char *)this + 0x1d4) = converted;
            changed = converted != old;
        }
        goto done;
    case 3:
        g_Settings_LoadFromRegistry_RData_0057509c = scaled;
        {
            unsigned int converted = ConvertVolumeSetting(scaled);
            unsigned int old = *(unsigned int *)((char *)this + 0x1d8);
            *(unsigned int *)((char *)this + 0x1d8) = converted;
            changed = converted != old;
        }
        goto done;
    }
    return 0;
done:
    return changed;
}
