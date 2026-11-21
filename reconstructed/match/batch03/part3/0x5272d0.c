struct UI {
    char pad0[0x82e4];
    int paramA;
    int paramB;

    void SetLayoutParams(int a, int b);
};

void UI::SetLayoutParams(int a, int b)
{
    paramA = a;
    paramB = b;
}
