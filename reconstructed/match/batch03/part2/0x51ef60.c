/* Object_GetByte36Max7 - 0x51ef60, 22 bytes */
int __fastcall Object_GetByte36Max7(int *param_1)
{
    int *child = (int *)*param_1;

    if (child != 0 && *(unsigned char *)((char *)child + 0x36) <= 7)
        return *(unsigned char *)((char *)child + 0x36);
    return 0;
}
