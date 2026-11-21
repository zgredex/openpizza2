/* MissionMap_RegisterCleanup - 0x4cb3a0, 12 bytes */
extern int CRT_Atexit(int function);
extern void MissionMap_Cleanup(void);

void MissionMap_RegisterCleanup(void)
{
    CRT_Atexit((int)MissionMap_Cleanup);
}
