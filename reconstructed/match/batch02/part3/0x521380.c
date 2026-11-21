struct Sprite { void FillTransparentColor(int color); };
struct UI { char pad[0x60]; Sprite *sprite; };

void __fastcall UI_RealizeSprite(UI *ui)
{
    ui->sprite->FillTransparentColor(-1);
}
