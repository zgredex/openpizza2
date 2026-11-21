/* Rect_ScaleAndOffset: scales a rectangle down by the tile size and offsets
   it by the tile origin (0x539930). */
struct RectOwner {
    char pad[0x58];
    int tileWidth;
    int offsetX;
    int offsetY;

    void ScaleAndOffset(int *rect);
};

void RectOwner::ScaleAndOffset(int *rect)
{
    rect[0] = rect[0] / tileWidth + offsetX;
    rect[1] = rect[1] / tileWidth + offsetY;
    rect[2] = (rect[2] - 1 + tileWidth) / tileWidth + offsetX;
    rect[3] = (rect[3] - 1 + tileWidth) / tileWidth + offsetY;
}
