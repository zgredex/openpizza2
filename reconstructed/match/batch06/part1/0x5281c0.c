/* UI_InvokeCallback: forwards four arguments to the stored callback (0x5281c0). */
struct UI {
    char pad[0x8308];
    void (__cdecl *callback)(int first, int second, int third, int fourth);
    void InvokeCallback(int first, int second, int third, int fourth);
};

void UI::InvokeCallback(int first, int second, int third, int fourth)
{
    if (callback != 0) {
        callback(first, second, third, fourth);
    }
}
