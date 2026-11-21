/* PC2 byte-match candidate: Surface_Unlock (0x539260, 18 bytes).
   Build: /O2.  Unlocks the surface through the nested object's stdcall
   method pointer at vtable slot +0x80. */
void __fastcall Surface_Unlock(int surface)
{
    int *target = *(int **)(*(int *)(surface + 0x40) + 0x10);

    (*(void (__stdcall **)(int *, int))(*target + 0x80))(target, 0);
}
