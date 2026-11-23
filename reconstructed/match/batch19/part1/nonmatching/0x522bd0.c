// UI_MeasureTextExtent: caches the measured extent of a text object.

struct Font {
    int GetCharWidth(unsigned char character);
};

struct UI {
    int GetFirstEnabledIndex();
    void MeasureTextExtent(int x, int y);
};

void UI::MeasureTextExtent(int x, int y)
{
    int index;

    if (*(int *)((char *)this + 0x88) != -999)
        return;
    *(int *)((char *)this + 0x88) = x;
    index = 0;
    if (*(int *)((char *)this + 0x80) > 0) {
        do {
            *(int *)((char *)this + 0x88) +=
                ((Font *)*(void **)((char *)this + 0x54))
                    ->GetCharWidth(
                        *(unsigned char *)(*(int *)((char *)this + 0x6c) +
                                           index));
            index++;
        } while (index < *(int *)((char *)this + 0x80));
    }
    if (*(int *)((char *)this + 0x7c) != 0) {
        int value = *(int *)((char *)this + 0x88) - 1;
        *(int *)((char *)this + 0x88) = value;
        *(int *)((char *)this + 0x90) = value + 2;
        *(int *)((char *)this + 0x8c) = x;
        *(int *)((char *)this + 0x94) =
            *(int *)(*(int *)((char *)this + 0x54) + 0x9b4) + x;
    } else {
        Font *font = (Font *)*(void **)((char *)this + 0x54);
        int width = font->GetCharWidth(
            *(unsigned char *)(*(int *)((char *)this + 0x6c) + index));
        if (width == 0)
            width = ((UI *)font)->GetFirstEnabledIndex();
        *(int *)((char *)this + 0x90) =
            *(int *)((char *)this + 0x88) + width;
        *(int *)((char *)this + 0x8c) =
            *(int *)(*(int *)((char *)this + 0x54) + 0x9b4) + y;
        *(int *)((char *)this + 0x94) =
            *(int *)((char *)this + 0x8c) + 2;
    }
}
