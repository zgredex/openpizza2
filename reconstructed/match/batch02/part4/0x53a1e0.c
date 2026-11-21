/* PC2 byte-match candidate: SpriteBase_Construct (0x53a1e0, 9 bytes).
   Build: /O2 /TP; entry ??0SpriteBase@@QAE@XZ. */
extern void *g_SpriteBaseVtable;

struct SpriteBase {
    void *vtable;

    SpriteBase(void);
};

SpriteBase::SpriteBase(void)
{
    vtable = &g_SpriteBaseVtable;
}
