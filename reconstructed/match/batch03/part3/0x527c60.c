struct Array {
    void InsertGrow(int value);
};

struct UI {
    char pad0[0x8324];
    Array effects;

    void AddEffectObject(int value);
};

void UI::AddEffectObject(int value)
{
    effects.InsertGrow(value);
}
