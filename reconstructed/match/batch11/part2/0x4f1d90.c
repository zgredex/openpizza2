/* Enum_MapDirection: maps the raw direction bits to the enumeration value
   (0x4f1d90). */
struct DirectionOwner {
    char pad[0xc];
    unsigned int direction;
};

extern "C" int __stdcall Enum_MapDirection(DirectionOwner *owner)
{
    switch (owner->direction & 7) {
    default: return 0;
    case 0: return 0;
    case 1: return 4;
    case 2: return 1;
    case 3: return 5;
    case 4: return 2;
    case 5: return 6;
    case 6: return 3;
    case 7: return 7;
    }
}
