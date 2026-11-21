/* Game_SetMessageField34: stores a value in the message record's field 0x34 (0x48c040). */
struct MessageList {
    void SetField34(int key, int value);
};

struct Game {
    char pad[0x304];
    MessageList messages;
    void SetMessageField34(int key, int value);
};

void Game::SetMessageField34(int key, int value)
{
    messages.SetField34(key, value);
}
