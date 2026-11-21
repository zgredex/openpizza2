/* Branch_InvalidateRatingCache: clears the cached rating and the object flag
   (0x47ee50). */
void __fastcall Game_ClearObjectFlag20(void *object);

void __fastcall Branch_InvalidateRatingCache(char *this_)
{
    *(int *)(this_ + 0x1714) = 0;
    Game_ClearObjectFlag20(this_);
}
