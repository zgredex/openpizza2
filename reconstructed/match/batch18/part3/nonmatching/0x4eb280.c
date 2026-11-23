extern char *DAT_0057c5c8;

/* IsoMap_ConstructFromStream: constructs an isometric map from a save stream
   (0x4eb280). */
struct List {
    int pad[5];
};

struct IsoMap {
    void DeserializeGrid(void *stream);
    void SetWindowOffsets();
    void UpdateObjectScreenBounds();
    void SetScrollPosition(int x, int y);
    void CompactVisibleDrawRecords();
    void RenderViewport(void *renderer, int *flags);
};

extern "C" void __cdecl List_Construct(void *list, int zero);

extern "C" void *__cdecl IsoMap_ConstructFromStream(IsoMap *map, void *stream)
{
    List_Construct((char *)map + 0x11c, 0);
    List_Construct((char *)map + 0x140, 0);
    *(int *)((char *)map + 4) = (int)stream;
    *(void **)map = (void *)0x55c5d4;
    *(int *)((char *)map + 8) = 0;
    *(int *)((char *)map + 0x70) = 0;
    *(int *)((char *)map + 0x74) = 0;
    *(int *)((char *)map + 0x78) = 0;
    *(int *)((char *)map + 0x1015c) = 1;
    map->DeserializeGrid(stream);
    map->SetWindowOffsets();
    map->UpdateObjectScreenBounds();
    map->SetScrollPosition(*(int *)((char *)map + 0x24), *(int *)((char *)map + 0x28));
    *(int *)((char *)map + 0x24) = *(int *)((char *)map + 0xe8);
    *(int *)((char *)map + 0x28) = *(int *)((char *)map + 0xec);
    map->CompactVisibleDrawRecords();
    if (*(int *)((char *)map + 0xc) != 0x10) {
        map->RenderViewport(DAT_0057c5c8, 0);
    }
    return map;
}
