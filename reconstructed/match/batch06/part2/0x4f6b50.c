/* Game_CompleteMissionStage: selects the mission result and queues it (0x4f6b50). */
struct UI {
    void QueueChildCommand(int command, int value);
};

extern char DAT_0057bb20;
extern UI *DAT_0057c5e0;
extern int DAT_0057c5c0;

void Game_CompleteMissionStage(void)
{
    DAT_0057c5c0 = DAT_0057bb20 ? 5 : 3;
    DAT_0057c5e0->QueueChildCommand(-0x18684, 0);
}
