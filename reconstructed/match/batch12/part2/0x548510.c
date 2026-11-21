/* Sound_UpdatePositionCountdown: maintains the periodic position refresh
   (0x548510). */
struct Sound {
    char pad[0x84];
    int position;
    char pad2[0xfc - 0x88];
    char enabled;
    char pad3[0x144 - 0xfd];
    int countdown;
    char pad4[0x169 - 0x148];
    char positioned;
    char pad5[0x170 - 0x16a];
    int field170;

    void SetPosition(int position, int flag, int value);

    void UpdatePositionCountdown();
};

void Sound::UpdatePositionCountdown()
{
    if (!enabled || positioned) {
        return;
    }
    SetPosition(position, 1, field170);
    if (countdown > 0) {
        positioned = 1;
        countdown = countdown - 1;
        return;
    }
    countdown = 3;
    positioned = 1;
}
