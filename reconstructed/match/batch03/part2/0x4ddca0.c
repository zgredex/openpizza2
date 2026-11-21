/* Player_RemoveObjectReference - 0x4ddca0, 19 bytes */
struct IDMap
{
    void RemoveByKey(int key);
};

struct Player
{
    char pad[0x180];
    IDMap objects;

    void RemoveObjectReference(int key);
};

void Player::RemoveObjectReference(int key)
{
    objects.RemoveByKey(key);
}
