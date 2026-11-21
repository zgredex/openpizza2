/* Surface_GetCursorRect: exports the four cursor rectangle fields (0x5396b0). */
struct Surface {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    void GetCursorRect(int *left, int *right, int *top, int *bottom);
};

void Surface::GetCursorRect(int *left, int *right, int *top, int *bottom)
{
    *left = field4;
    *right = fieldC;
    *top = field8;
    *bottom = field10;
}
