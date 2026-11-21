/* Building_MapSubtypeToState (0x508fb0, 48 bytes).  Build: /O2 /TP.
   Maps a building subtype to its construction state. */
extern "C" int __stdcall Building_MapSubtypeToState(int subtype)
{
    int result = -1;

    switch (subtype) {
    case 3:
        result = 4;
        break;
    case 2:
        result = 2;
        break;
    case 0:
        result = 6;
        break;
    case 1:
        result = 0;
        break;
    }
    return result;
}
