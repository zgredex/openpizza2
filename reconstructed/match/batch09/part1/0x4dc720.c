/* Game_PlaceObjectInPlayerCity: places a map object in a player's city
   (0x4dc720). */
struct MapObject {
    void SetCityFromPlayer(void *player, int index);
};

struct Game {
    void PlaceObjectInPlayerCity(struct MapObject *object, int index);
};

void Game::PlaceObjectInPlayerCity(struct MapObject *object, int index)
{
    object->SetCityFromPlayer(*(void **)((char *)this + 0xfa8), index);
    *(int *)(*(int *)((char *)this + 0xfa8) + 0xf4) = 1;
    if (index == -1)
        *(int *)((char *)object + 0x38) = 0;
}
