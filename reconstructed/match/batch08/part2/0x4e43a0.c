/* Game_SetHQLevel: maps an HQ level to its size (0x4e43a0). */
struct Game { char pad[8]; int hqSize; void SetHQLevel(int level); };
void Game::SetHQLevel(int level)
{
    switch (level) {
    case 0:
        *(int *)((char *)this + 8) = 0x78;
        break;
    case 1:
        *(int *)((char *)this + 8) = 0x8c;
        break;
    case 2:
        *(int *)((char *)this + 8) = 0xa0;
        break;
    case 3:
        *(int *)((char *)this + 8) = 0;
        break;
    default:
        *(int *)((char *)this + 8) = 0;
        break;
    }
}
