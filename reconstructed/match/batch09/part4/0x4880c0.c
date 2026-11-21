/* Game_UpdateLoadProgress: converts stream progress into the loading slider
   value and pumps the message queue (0x4880c0). */
extern "C" {
extern int DAT_0057c5f4;
extern int DAT_0057c5e0;
}

struct IStream {
    int GetReadPosition();
};

struct Window {
    void GadgetNotifySliderSetValue(int id, int value, int flags);
    int ProcessMessageQueue(int flags);
};

int Game_UpdateLoadProgress(IStream *stream, int total)
{
    int position = stream->GetReadPosition();

    if (0 < total)
        position = position * 0x50 / total + 0x14;
    else
        position = 0x14;
    ((Window *)DAT_0057c5f4)
        ->GadgetNotifySliderSetValue(0x3f7, position, 0);
    return ((Window *)DAT_0057c5e0)->ProcessMessageQueue(0);
}
