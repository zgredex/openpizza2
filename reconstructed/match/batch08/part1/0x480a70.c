/* Game_SetObjectValue100: prices an object, checks affordability and sets
   its mode byte to 100 (0x480a70). */
struct Game {
    float ComputeCityPriceShare(void *object, float *out);
    void CanAfford(int type, float amount, char flag, int extra);
    void SetModeByte(unsigned int mode);
    char SetObjectValue100(struct Game *object);
};

char Game::SetObjectValue100(struct Game *object)
{
    float price = ComputeCityPriceShare(object, 0);

    CanAfford(5, price, 0, -1);
    object->SetModeByte(100);
    return 1;
}
