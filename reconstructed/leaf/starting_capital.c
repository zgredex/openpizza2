#include <stdint.h>

/* Game_GetStartingCapital (0x48D3A0). The original-image linker binds this
 * global to 0x0057BB24. Keeping it external preserves the original entry ABI. */
extern const uint32_t game_difficulty;

uint32_t game_get_starting_capital(void) {
    static const uint32_t capital[] = {
        1000000, 500000, 200000, 100000, 75000,
        50000, 40000, 30000, 25000, 22000,
    };
    uint32_t difficulty = game_difficulty;
    return difficulty < sizeof capital / sizeof *capital ? capital[difficulty] : 20000;
}
