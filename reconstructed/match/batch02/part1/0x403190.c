/* Clear_Ptr: clears the pointed-to pointer and returns the pointer (0x403190). */
void * __fastcall Clear_Ptr(void *ptr)
{
    *(int *)ptr = 0;
    return ptr;
}
