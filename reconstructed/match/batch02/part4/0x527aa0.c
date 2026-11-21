/* PC2 byte-match candidate: UI_ResetInputHelper (0x527aa0, 11 bytes).
   Build: /O2 /TP; entry _UI_ResetInputHelper. */
extern "C" void __fastcall Object_GetByte36Max7(int *object);

extern "C" void __fastcall UI_ResetInputHelper(char *self)
{
    Object_GetByte36Max7(*(int **)(self + 0x8310));
}
