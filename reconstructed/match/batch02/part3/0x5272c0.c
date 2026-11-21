extern void __fastcall Renderer_GetTextObject(void *object);

void __fastcall UI_GetTextObject(char *this_)
{
    Renderer_GetTextObject(*(void **)(this_ + 0x244));
}
