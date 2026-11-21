extern void *PTR_Storage_Delete_0055c700[];
extern void __fastcall List_Node_Destroy(void *node);

void __fastcall Storage_Destroy(char *this_)
{
    *(void **)this_ = PTR_Storage_Delete_0055c700;
    List_Node_Destroy(this_ + 0x44);
}
