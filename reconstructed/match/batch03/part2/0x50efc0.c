/* Player_ResetAiState - 0x50efc0, 21 bytes */
void __fastcall Player_ResetAiState(void *this_)
{
    *(int *)((char *)this_ + 0x84) = 1;
    *(int *)((char *)this_ + 0x88) = 0;
}
