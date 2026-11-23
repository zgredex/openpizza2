extern "C" int __cdecl Math_RoundFloat(float value);

/* Game_ComputePrice: computes a recipe price from a rating table (0x4e4060). */
struct Game {
    int ComputePrice(void *recipe);
};

int Game::ComputePrice(void *recipe)
{
    double factors[7] = {0.0, 20.0, 100.0, 500.0, 150.0, 300.0, 180.0};
    int index = *(int *)((char *)this + 8);

    if (index < 1 || 6 < index) {
        index = 1;
    }
    return Math_RoundFloat(
        (float)((*(int *)((char *)recipe + 0x54) + *(int *)((char *)recipe + 0x3c)) * -3 + 100) *
        (float)factors[index] * (float)*(double *)((char *)this + 0x70) * 0.01f);
}
