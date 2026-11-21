/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct OverlayTable {
    char pad00[0x48];
    int count;              /* +0x48 */
    unsigned char *rows;    /* +0x4c */
};

struct Overlay {
    int index;              /* +0x00 */
    char pad04[0x3c];
    int field40;            /* +0x40 */
    char pad44[0x14];
    OverlayTable *table;    /* +0x58 */
};

struct MapActor {
    int UpdateLinkedOverlays(void *overlay);
};

struct MapObject {
    char pad00[0xc4];
    MapActor *actor;        /* +0xc4 */
    Overlay *overlay;       /* +0xc8 */
    int IsVisibleThisFrame(void);
};

int MapObject::IsVisibleThisFrame(void)
{
    int index;
    OverlayTable *table;

    if (overlay != 0) {
        if (overlay->field40 != -1) {
            if (actor->UpdateLinkedOverlays(overlay))
                return 1;
        }
        index = overlay->index;
        table = overlay->table;
        if (index >= 0 && index < table->count)
            return table->rows[0x3e + index * 0x48];
    }
    return 0;
}
