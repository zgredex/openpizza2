/* Resource_Close: closes a resource handle under the manager lock
   (0x402990). */
void __fastcall CS_Enter(void *section);
void __fastcall CS_Leave(void *section);
void __cdecl CRT_Fclose(void *file);

struct Resource {
    char pad[0x1688];
    void Close(int handle);
};

void Resource::Close(int handle)
{
    CS_Enter((char *)this + 0x1688);
    if (*(int *)(handle + 0x1c) == 1)
        CRT_Fclose(*(void **)(handle + 0x18));
    *(int *)(handle + 0x14) = 0;
    CS_Leave((char *)this + 0x1688);
}
