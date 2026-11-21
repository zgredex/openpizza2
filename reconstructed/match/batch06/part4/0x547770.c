/* Options_GetGlobalSettings: copies the four global option values into a
   caller buffer (0x547770).  Build: /O2. */
void __stdcall Options_GetGlobalSettings(int *settings)
{
    settings[0] = *(int *)0x575090;
    settings[1] = *(int *)0x575094;
    settings[2] = *(int *)0x575098;
    settings[3] = *(int *)0x57509c;
}
