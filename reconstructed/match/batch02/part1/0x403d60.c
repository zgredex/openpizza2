/* MissionBriefing_InitList: constructs the global mission briefing list
   (0x403d60). */
struct List {
    void Construct(int value);
};

extern char DAT_0057c590;

void MissionBriefing_InitList(void)
{
    ((List *)&DAT_0057c590)->Construct(0);
}
