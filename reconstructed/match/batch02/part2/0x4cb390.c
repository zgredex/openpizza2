/* MissionMap_InitList - 0x4cb390, 13 bytes */
struct List
{
    void Construct(unsigned flags);
};

extern char DAT_0057de38;

void MissionMap_InitList(void)
{
    ((List *)&DAT_0057de38)->Construct(0);
}
