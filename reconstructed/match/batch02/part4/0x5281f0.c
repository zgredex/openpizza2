/* PC2 byte-match candidate: UI_SetEventCallback (0x5281f0, 13 bytes).
   Build: /O2 /TP; entry ?SetEventCallback@UI_Manager@@QAEXH@Z. */
struct UI_Manager {
    char pad_0000[0x8308];
    int eventCallback;

    void SetEventCallback(int callback);
};

void UI_Manager::SetEventCallback(int callback)
{
    eventCallback = callback;
}
