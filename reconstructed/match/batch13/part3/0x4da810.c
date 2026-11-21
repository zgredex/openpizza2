/* Player_TrackRecentEntry (0x4da810). */
struct Player {
    void TrackRecentEntry(int slot, int value);
};

void Player::TrackRecentEntry(int slot, int value)
{
    int index = 0;
    bool found = false;
    char *base = (char *)this + slot * 0x18;
    int *entry = (int *)(base + 0xfe4);

    do {
        if (*entry == value) {
            found = true;
            if (index == 0) {
                return;
            }
            {
                int offset = index + slot * 6;
                int *target = (int *)((char *)this + offset * 4 + 0xfe0);
                *entry = *target;
                *target = value;
            }
        }
        index = index + 1;
        entry = entry + 1;
    } while (index < 6);
    if (!found) {
        *(int *)(base + 0xff8) = value;
    }
}
