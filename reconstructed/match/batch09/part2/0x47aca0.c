/* Rating_ComputePenalty: penalty derived from the adjusted rating
   (0x47aca0). */
struct Rating {
    int ClampAdjusted(void);
};

int __fastcall Rating_ComputePenalty(int rating)
{
    if (*(int *)(rating + 0x14c4) != 0) {
        int adjusted = ((struct Rating *)*(int *)(rating + 0x14c4))->ClampAdjusted();
        int divisor = adjusted / 10;

        if (divisor < 1)
            divisor = 1;
        return -(*(int *)(rating + 0x14d4) / divisor);
    }
    return 0;
}
