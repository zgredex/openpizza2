/* Non-matching candidate.
   First difference: offset 0x5, 98 bytes differ.
   original keeps count in ebx and this in edi before the category branch; candidate swaps them.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

int __cdecl Random_RangeFast(int low, int high);

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct City {
    unsigned GetTopProductCategory();
};

struct Player {
    void SelectRandomPlayerCompany(int slot);
};

void Player::SelectRandomPlayerCompany(int slot)
{
    int count;
    unsigned category;
    if (slot != -1)
        category = ((City *)((Game *)DAT_0057c670)->GetPlayerBySlot(slot))
                       ->GetTopProductCategory();
    else
        category = Random_RangeFast(0, 5);
    count = 0;
    int *flags = (int *)((char *)this + 0xc8);
    int *cursor = flags;
    int remaining = 6;
    do {
        if (*cursor == 1)
            count++;
        cursor++;
        remaining--;
    } while (remaining != 0);
    if (count >= 2) {
        count = 0;
        while (*flags != 1) {
            count++;
            flags++;
            if (count > 5) {
                *(int *)((char *)this + category * 4 + 0xc8) = 1;
                return;
            }
        }
        *(int *)((char *)this + count * 4 + 0xc8) = 0;
    }
    *(int *)((char *)this + category * 4 + 0xc8) = 1;
}
