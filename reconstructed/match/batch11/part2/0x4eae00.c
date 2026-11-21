/* UI_SetWindowOffsets: applies the window offset preset for the window type
   (0x4eae00). */
extern "C" void __fastcall UI_SetWindowOffsets(char *this_)
{
    if (*(int *)(this_ + 0xc) == 0x10) {
        *(int *)(this_ + 0x1016c) = 0x41;
        *(int *)(this_ + 0x10168) = 0;
        *(int *)(this_ + 0x10174) = -0xd2;
        *(int *)(this_ + 0x10170) = 0x28;
        return;
    }
    *(int *)(this_ + 0x1016c) = 0x41;
    *(int *)(this_ + 0x10168) = 0x41;
    *(int *)(this_ + 0x10174) = 0x1e;
    *(int *)(this_ + 0x10170) = 0x1e;
}
