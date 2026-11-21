/* IsoMap_Delete: destroying destructor, frees the map when flag bit 0 is set (0x4eade0). */
extern void Mem_Free(void *block);

struct IsoMap {
    void Destroy();
    IsoMap *Delete(unsigned char flags);
};

IsoMap *IsoMap::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1) {
        Mem_Free(this);
    }
    return this;
}
