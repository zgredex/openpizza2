/* UI_GetButtonSprite: fetches the sprite attached to a button gadget (0x531980). */
void * __stdcall Window_GadgetNotify(void *handle, int a, int b, int c, int d);

int __stdcall UI_GetButtonSprite(void *param)
{
    int *result = (int *)Window_GadgetNotify(param, 6, 0x38, 0, 0);

    if (result == 0)
        return 0;
    return result[0x10];
}
