/* Resource_GetSize: reads the size field of a resource header (0x4029d0). */
int __stdcall Resource_GetSize(int resource)
{
    return *(int *)(resource + 8);
}
