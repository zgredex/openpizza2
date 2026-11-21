/* Object_GetId - 0x5260e0, 20 bytes */
int __stdcall Object_GetId(void *object)
{
    if (object == 0)
        return -1;
    return *(int *)((char *)object + 4);
}
