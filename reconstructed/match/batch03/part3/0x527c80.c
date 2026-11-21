struct Array {
    void RemoveValueLocked(int value);
};

struct UI {
    char pad0[0x8324];
    Array effects;

    void RemoveEffectObject(int value);
};

void UI::RemoveEffectObject(int value)
{
    effects.RemoveValueLocked(value);
}
