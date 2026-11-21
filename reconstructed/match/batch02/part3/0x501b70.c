extern void *PTR_Player_AIState_Delete_0055c664[];
extern void __fastcall List_Node_Destroy(void *node);

void __fastcall Player_AIState_Destroy(char *this_)
{
    *(void **)this_ = PTR_Player_AIState_Delete_0055c664;
    List_Node_Destroy(this_ + 0x68);
}
