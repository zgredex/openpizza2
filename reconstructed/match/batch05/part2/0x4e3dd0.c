/* Player_InitSlotFlags: marks a slot active and clears two per-slot fields
   (0x4e3dd0). */
struct Player {
    char pad[0xac];
    char active[8];
    int fieldB4[6];
    int fieldCC[6];
    void InitSlotFlags(int index);
};

void Player::InitSlotFlags(int index)
{
    active[index] = 1;
    fieldCC[index] = 0;
    fieldB4[index] = 0;
}
