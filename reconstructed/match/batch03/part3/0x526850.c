struct Dialog {
    char pad0[0x27c];
    int result;
    int hasResult;

    void SetResult(int value);
};

void Dialog::SetResult(int value)
{
    hasResult = 1;
    result = value;
}
