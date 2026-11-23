extern "C" void NoOp_Stub(int message);
struct UI { char pad0[4]; int type; char pad1[0x34]; int value; char pad2[0x0c]; int flag4c; int flag50; int IsSpriteVisibleInView(); };
struct Object { char pad0[4]; int type; char pad1[0x34]; int value; char pad2[0x0c]; int flag4c; int flag50; void SetMarketValueByType(); };
void Object::SetMarketValueByType()
{
    if (((UI *)this)->IsSpriteVisibleInView() == 0) return;
    switch (type) {
    case 0: flag50=1; value=1000; return;
    case 1: flag50=1; value=45000; return;
    case 2: flag50=1; value=30000; return;
    case 3: break;
    case 4: flag50=1; value=35000; return;
    case 5: break;
    case 6: break;
    case 7: flag50=1; value=1000; return;
    case 8: flag50=1; value=7000; return;
    case 9: flag50=1; value=40000; return;
    case 10: flag50=1; value=10000; return;
    case 11: break;
    case 12: flag50=1; value=25000; return;
    case 13: flag50=1; value=50000; return;
    case 14: flag50=1; value=20000; return;
    case 15: break;
    case 16: break;
    case 17: break;
    case 18: break;
    case 19: break;
    case 20: flag4c=1; return;
    case 21: flag4c=1; return;
    case 22: flag4c=1; return;
    case 23: break;
    case 24: break;
    case 25: break;
    case 26: break;
    case 27: break;
    case 28: break;
    case 29: flag4c=1; return;
    case 30: flag4c=1; return;
    case 31: flag4c=1; return;
    case 32: break;
    case 33: flag50=1; value=60000; return;
    case 34: break;
    case 35: flag50=1; value=1000; return;
    default: NoOp_Stub(0x56c95c);
    }
}
