extern unsigned int game_difficulty;

unsigned int pc2_get_starting_capital(void) {
    unsigned int difficulty = game_difficulty;
    switch (difficulty) {
    case 0: return 1000000;
    case 1: return 500000;
    case 2: return 200000;
    case 3: return 100000;
    case 4: return 75000;
    case 5: return 50000;
    case 6: return 40000;
    case 7: return 30000;
    case 8: return 25000;
    case 9: return 22000;
    default: return 20000;
    }
}
