/* Random_Mod: returns rand() modulo a caller-supplied range (0x4034b0). */
int rand(void);

unsigned __cdecl Random_Mod(unsigned modulus)
{
    if (modulus <= 0)
        return 0;
    return rand() % modulus;
}
