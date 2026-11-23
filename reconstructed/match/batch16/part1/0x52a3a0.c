// UI_SetClampedValue @ 0x52a3a0 (152 bytes)
// Stores a value into a UI array, clamped to the configured range.

extern "C" void String_Format(char *buffer, char *format, int value);

typedef void (__stdcall *UI_Notify)(int command, int argument, char *text);

class UI {
public:
    char pad0[0x8c];
    int values[4];
    int low;
    int high;
    char pad1[0xb8 - 0xa4];
    void *listener;
    char *format;
    char pad2[0x388 - 0xc0];
    int enabled;

    void SetClampedValue(int value, int index);
};

void UI::SetClampedValue(int value, int index)
{
    char buffer[260];

    if (this->enabled != 0) {
        int lower = this->low;
        int upper = this->high;
        if (lower < upper) {
            if (value < lower)
                value = lower;
            if (value > upper)
                value = upper;
        } else {
            if (value > lower)
                value = lower;
            if (value < upper)
                value = upper;
        }
    }
    this->values[index] = value;
    if (this->listener != 0) {
        String_Format(buffer, this->format, value);
        (*(UI_Notify *)(*(int *)this->listener + 0xc))(0xe, 0, buffer);
    }
}
