struct Renderer { void ClipRect(int *rect, int flag); };
struct UI { char pad[8]; Renderer *renderer; };

void __fastcall UI_ClipChildRect(UI *ui)
{
    ui->renderer->ClipRect((int *)((char *)ui + 0x28), 1);
}
