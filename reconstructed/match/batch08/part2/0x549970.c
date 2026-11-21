/* Sound_ProcessEventForSelectedObject: forwards an event when the object
   belongs to the selected player (0x549970). */
extern int DAT_0057c670;

struct Sound {
    char pad[0xfc];
    unsigned char enabled;
    void ProcessEvent(int first, int second, char flag);
    void ProcessEventForSelectedObject(int object, int first, int second,
                                       char flag);
};

void Sound::ProcessEventForSelectedObject(int object, int first, int second,
                                          char flag)
{
    if (enabled != 0 && object == *(int *)(DAT_0057c670 + 0x9c)) {
        ProcessEvent(first, second, flag);
    }
}
