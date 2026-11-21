/* Game_IsRatingBelowThreshold: compares a product price level against a
   per-category threshold (0x480b40). */
struct Game {
    int IsRatingBelowThreshold(int index);
};

int __fastcall City_GetProductPriceLevel(void *city);

int Game::IsRatingBelowThreshold(int index)
{
    int limits[8] = {0xe, 0x10, 0x14, 0xd, 0x14, 0x14, 0x18, 0x11};
    int level = City_GetProductPriceLevel(this);

    return level > limits[index];
}
