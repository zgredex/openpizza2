/* Map_SetScrollPosition: clamps both scroll coordinates and reports whether
   either one moved (0x4ed440). */
struct UI {
    int ClampScrollY(int value);
};

struct Map {
    int ClampScrollY(int value);
    int SetScrollPosition(int x, int y);
};

int Map::SetScrollPosition(int x, int y)
{
    UI *ui = (UI *)this;
    int movedX = ui->ClampScrollY(x);
    int movedY = ClampScrollY(y);

    if (movedX == 0 && movedY == 0)
        return 0;
    return 1;
}
