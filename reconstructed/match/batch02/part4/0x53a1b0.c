/* PC2 byte-match candidate: Gfx_InitBlendTable (0x53a1b0, 10 bytes).
   Build: /O2 /TP; entry _Gfx_InitBlendTable. */
extern "C" void __fastcall Gfx_BuildBlendTable(void *table);
extern unsigned char g_GfxBlendTable;

extern "C" void Gfx_InitBlendTable(void)
{
    Gfx_BuildBlendTable(&g_GfxBlendTable);
}
