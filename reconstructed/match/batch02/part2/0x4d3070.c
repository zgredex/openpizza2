/* Entity_SetTileId - 0x4d3070, 10 bytes */
void __fastcall Entity_SetTileId(void *this_, int unused, int tile_id)
{
    *(int *)((char *)this_ + 0x24) = tile_id;
}
