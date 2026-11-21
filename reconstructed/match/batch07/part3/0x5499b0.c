/* Sound_ProcessEventWithCooldown: processes a sound event when the channel
   is enabled and off cooldown (0x5499b0). */
struct Sound {
    char pad[0xfc];
    unsigned char enabled;
    char pad2[0x5b];
    int cooldown;
    void ProcessEvent(int id, int zero, char flag);
    void ProcessEventWithCooldown(int id, char flag);
};

void Sound::ProcessEventWithCooldown(int id, char flag)
{
    if (enabled != 0 && cooldown <= 0) {
        cooldown = 2;
        ProcessEvent(id, 0, flag);
    }
}
