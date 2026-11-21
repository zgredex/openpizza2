struct Tooltip {
    void SetBackgroundImage(char *name);
};

struct UI {
    char pad0[0x244];
    Tooltip *tooltip;

    void SetFontName(char *name);
};

void UI::SetFontName(char *name)
{
    tooltip->SetBackgroundImage(name);
}
