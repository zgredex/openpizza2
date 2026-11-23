// Host harness for the readable source port.
// This is not a recovered game function; it exercises a few ported functions
// so the 32-bit PE has a real entry point and linkable call edges.
#include "pc2_port.h"

void NoOp_2(void);
void Clamp_0_100(int *arg1);
int __fastcall Storage_GetCapacity(int self);
void __thiscall UI_OffsetPoint(void *self, int *arg1, int *arg2);

int main(void)
{
    unsigned char object[0x100] = {0};
    int value = 150;
    int x = 1;
    int y = 2;

    Clamp_0_100(&value);
    int capacity = Storage_GetCapacity((int)(intptr_t)object);
    UI_OffsetPoint(object, &x, &y);
    NoOp_2();

    return (value == 100 && capacity == 0x24 && x == 1 && y == 2) ? 0 : 1;
}
