// SchoolMenu_UpdatePage: refreshes the school page and competitor matrix.

extern char DAT_0057c670[];
extern char DAT_005840d4[];
extern "C" int g_Text_1701_Maximum;

struct Game {
    int CanShowObject();
};

struct Window {
    void GadgetNotify_Text_SetText(int id, char *text);
};

struct UI {
    void RemoveObjectByKey(int id);
};

struct Rating {
    void UpdateBarByKey(int key, int index, int value, int maximum);
};

void Submenu_SetObjectPicture(void *window, int picture, int a, int key, int b,
                              void *record);
void SchoolMenu_FillLocalStructure(void *window);
void Stats_BuildCompetitorMatrix(int *matrix);
void Rating_UpdateBarByKey(void *window, int id, int index, int value,
                           int maximum);

void SchoolMenu_UpdatePage(void *window)
{
    char *record = *(char **)(*(char **)DAT_0057c670 + 0x218);
    int maxima[8];
    int matrix[64];
    int i;
    int j;

    for (i = 0; i < 8; i++)
        maxima[i] = 0;
    ((Window *)window)->GadgetNotify_Text_SetText(
        0x43b, ((char **)DAT_005840d4)[*(int *)(record + 4)]);
    if (((Game *)record)->CanShowObject() == 0) {
        ((UI *)window)->RemoveObjectByKey(0x1f42);
        ((UI *)window)->RemoveObjectByKey(0x1f43);
    }
    Submenu_SetObjectPicture(window, *(int *)(record + 0x20), 1, 0x1f4c, -1,
                             record);
    SchoolMenu_FillLocalStructure(window);
    Stats_BuildCompetitorMatrix(matrix);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (matrix[i * 8 + j] > maxima[i])
                maxima[i] = matrix[i * 8 + j];
        }
    }
    for (i = 0; i < 8; i++)
        Rating_UpdateBarByKey(window, 0x1fd4, i, maxima[i],
                              g_Text_1701_Maximum);
}
