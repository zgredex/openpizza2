/* Game_MapPlayerStatusToAnimation (0x483fa0, 48 bytes).  Build: /O2 /TP.
   Maps the player status byte to a walking animation index. */
struct Game {
    unsigned char GetPlayerByte8(void);
};

extern "C" unsigned __stdcall Game_MapPlayerStatusToAnimation(int player)
{
    unsigned char status = ((Game *)player)->GetPlayerByte8();

    switch (status) {
    case 5:
        return 0x20;
    case 7:
        return 0x16;
    }
    return 0xb;
}
