/* Surface_SetBounds (0x539660): clamps the requested rectangle against the
   surface limits and stores the effective bounds. */
struct Surface {
    char pad[4];
    int x;
    int right;
    int y;
    int bottom;
    char pad2[0x64 - 0x14];
    int limit64;
    int limit68;
    int limit6c;
    int limit70;

    void SetBounds(int left, int top, int right, int bottom);
};

void Surface::SetBounds(int left, int top, int right, int bottom)
{
    x = limit64 <= left ? left : limit64;
    y = limit68 <= top ? top : limit68;
    this->right = limit6c < right ? limit6c : right;
    this->bottom = limit70 < bottom ? limit70 : bottom;
}
