/* FreePlaySetup_FillGameLengthText (0x4cb7e0). */
struct Window_GadgetNotify_Text {
    void SetText(int id, char *text);
};
extern "C" int DAT_0057bb2c;
extern "C" int DAT_00581274;
extern "C" int DAT_00581a24;
extern "C" int DAT_00582768;
extern "C" char STR_00568324[];
extern "C" char DAT_005630d0[];
extern "C" int __cdecl String_Format(char *buffer, const char *format, ...);

extern "C" void __cdecl FreePlaySetup_FillGameLengthText(void *window)
{
    char local[32];

    if (DAT_0057bb2c < 2) {
        String_Format(local, STR_00568324, DAT_0057bb2c, DAT_00581274);
    } else if (DAT_0057bb2c == 0xb) {
        String_Format(local, DAT_005630d0, DAT_00582768);
    } else {
        String_Format(local, STR_00568324, DAT_0057bb2c, DAT_00581a24);
    }
    ((struct Window_GadgetNotify_Text *)window)->SetText(0x435, local);
}
