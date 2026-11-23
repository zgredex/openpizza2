// Game_OpenObjectView @ 0x48bef0 (154 bytes)
// Opens the city or branch view for a selected object or person.

class Sound;
extern Sound *DAT_0057ba0c;

class Game {
public:
    char pad0[0x9c];
    int field9c;
    char pad1[0x21c - 0xa0];
    int field21c;
    char pad2[0x290 - 0x220];
    int mode;
    char pad3[0x2da8 - 0x294];
    int field2da8;

    void OpenObjectView(int object);
    int GetPlayerSubmapValue(int first, int second);
    void SetViewMode(int mode, int flag);
};

class SubMenu {
public:
    void SetSelection(int first, int object, int third, int fourth);
};

class Sound {
public:
    void SelectCurrentTrack();
};

void Game::OpenObjectView(int object)
{
    int value;

    this->field21c = object;
    this->field2da8 = 1;
    if (*(int *)(object + 0x74) != 0) {
        int *info = *(int **)(object + 0xfc);
        int second = info[0xb];
        value = this->GetPlayerSubmapValue(info[2], second);
        if (value == 0)
            return;
        if (this->mode != 4) {
            this->field9c = value;
            DAT_0057ba0c->SelectCurrentTrack();
            this->SetViewMode(4, 1);
            return;
        }
    } else {
        if (this->mode != 1 && this->mode != 3 && this->mode != 2) {
            this->SetViewMode(1, 1);
            return;
        }
    }
    ((SubMenu *)this)->SetSelection(0, object, 0, 1);
}
