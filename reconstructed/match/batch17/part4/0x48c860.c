struct UI {
    void QueueControlCommand(int command, int arg1, int arg2);
    void ShiftChildRect();
    void DestroyChildObject();
};

struct Object {
    void SetState(int state);
    void SetFlag104(int value);
};

struct Game {
    char pad0[0x21c];
    void *activeObject;
    char pad1[0x25c - 0x220];
    UI *ui;
    char pad2[0x2da8 - 0x260];
    int field2DA8;
    void HandleObjectDeath(void *object);
};

extern int DAT_0057c1e0;
extern char DAT_00568330[];
extern char DAT_0056833c[];
extern char DAT_00568348[];

extern "C" void DebugConsole_Printf(int console, int level, const char *text, ...);

void Game::HandleObjectDeath(void *object)
{
    if (*(void **)((char *)this + 0x21c) == object) {
        ((UI *)*(void **)((char *)this + 0x25c))
            ->QueueControlCommand(-0x18624, 0x23, 0);
        *(void **)((char *)this + 0x21c) = 0;
        *(int *)((char *)this + 0x2da8) = 1;
    }
    int type = *(int *)((char *)object + 0x30);
    switch (type) {
    case 0xd:
        DebugConsole_Printf(DAT_0057c1e0, 0xff, DAT_00568330);
        break;
    case 0x17:
        DebugConsole_Printf(DAT_0057c1e0, 0xff, DAT_0056833c);
        break;
    case 0x1d:
        DebugConsole_Printf(DAT_0057c1e0, 0xff, DAT_00568348);
        break;
    }

    ((UI *)object)->ShiftChildRect();
    *(int *)((char *)object + 0x30) = 0x23;
    ((Object *)object)->SetState(2);
    ((Object *)object)->SetFlag104(1);
    *(int *)((char *)object + 0x74) = 0;
    ((UI *)object)->DestroyChildObject();
}
