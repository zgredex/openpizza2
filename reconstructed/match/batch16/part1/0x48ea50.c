extern char *DAT_0057c670;
class Game { public: void DestroyRootWindow(); };
class SubMenu { public: void CreateBuildingPage(); };
class Window { public: class GadgetNotify_Button { public: void SetState(int id,int state); }; };
class Array { public: void ToggleObjectActive(int id,int state); };
class UI { public: void SetChildVisibleByID(int id,int visible); };
void __cdecl Game_ReturnToPlayScreen(void)
{
    char *game = DAT_0057c670;
    Window *window = *(Window **)(game + 0x260);
    *(int *)(game + 0x21c) = 0;
    *(int *)(game + 0x2da8) = 1;
    game = DAT_0057c670;
    *(volatile int *)(game + 0x2c8) = *(volatile int *)(game + 0x2a8);
    *(volatile int *)(game + 0x2a8) = 1;
    ((Game *)DAT_0057c670)->DestroyRootWindow();
    ((SubMenu *)DAT_0057c670)->CreateBuildingPage();
    ((Window::GadgetNotify_Button *)window)->SetState(0x3f4, 1);
    ((Array *)window)->ToggleObjectActive(0x3f4, 1);
    ((Window::GadgetNotify_Button *)window)->SetState(0x3fd, 0);
    ((Array *)window)->ToggleObjectActive(0x3fd, 0);
    ((UI *)window)->SetChildVisibleByID(0x3fd, 0);
}
