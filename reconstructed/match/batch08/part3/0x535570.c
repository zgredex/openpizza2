/* Text_SetMetrics2: stores three metrics into the six cached positions
   (0x535570). */
struct Text {
    char pad[0x9a0];
    int m9a0;
    int m9a4;
    int m9a8;
    int m9ac;
    int m9b0;
    int m9b4;
    int m9b8;
    int m9bc;
    int m9c0;
    int m9c4;
    void SetMetrics2(int a, int b, int c);
};

void Text::SetMetrics2(int a, int b, int c)
{
    m9a0 = a;
    m9bc = a;
    m9a8 = a;
    m9a4 = b;
    m9c0 = b;
    m9ac = b;
    m9c4 = c;
}
