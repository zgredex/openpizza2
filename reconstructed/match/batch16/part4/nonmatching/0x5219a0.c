/* Sprite_FillRectColor: fills a rectangle of the sprite with one color
   (0x5219a0). */
extern "C" void Mem_FillWord(void *dest, unsigned short value, int count);

struct Sprite {
    void GetSize(int *width, int *height);
    int GetPixelBuffer();
};

struct Color {
    unsigned short RGBTo16FromDword(unsigned int color);
};

class Sprite2 {
public:
    void FillRectColor(int left, int top, int right, int bottom,
                       unsigned int color);
};

void Sprite2::FillRectColor(int param_1, int param_2, int param_3, int param_4,
                            unsigned int param_5)
{
    unsigned short uVar1;
    int iVar2;
    int *puVar3;
    int local_8;
    int local_4;

    ((Sprite *)*(void **)((char *)this + 0x60))->GetSize(&local_8, &local_4);
    uVar1 = ((Color *)*(void **)((char *)this + 0x68))
                ->RGBTo16FromDword(param_5);
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_2 < 0) {
        param_2 = 0;
    }
    if (local_8 <= param_3) {
        param_3 = local_8 + -1;
    }
    if (local_4 <= param_4) {
        param_4 = local_4 + -1;
    }
    iVar2 = ((Sprite *)*(void **)((char *)this + 0x60))->GetPixelBuffer();
    puVar3 = (int *)(iVar2 + (local_8 * param_2 + param_1) * 2);
    if (param_2 <= param_4) {
        iVar2 = (param_4 - param_2) + 1;
        do {
            Mem_FillWord(puVar3, uVar1, param_3 - param_1);
            iVar2 = iVar2 + -1;
            puVar3 = (int *)((int)puVar3 + local_8 * 2);
        } while (iVar2 != 0);
    }
}
