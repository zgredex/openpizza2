extern unsigned int DAT_00569f94[];
extern int DAT_0057d654;
class Window { public: void GadgetNotify_Button_SetState(int id, int state); };
class UI { public: void SetChildVisibleByID(int id, int visible); void SetButtonRecordVariant(int id, int variant); };

extern "C" void __cdecl Glossary_IngredientList_Update(void *window, int entry)
{
    unsigned int *record = &DAT_00569f94[entry * 3];
    int row = entry * 3;
    int id;
    for (id = 0x42c; id < 0x43e; id++) {
        ((Window *)window)->GadgetNotify_Button_SetState(id, row == DAT_0057d654);
        if (row < 0x38) {
            ((UI *)window)->SetChildVisibleByID(id, 1);
            ((UI *)window)->SetChildVisibleByID(id + 0xb74, 1);
            ((UI *)window)->SetButtonRecordVariant(id + 0xb74, *record);
        } else {
            ((UI *)window)->SetChildVisibleByID(id, 0);
            ((UI *)window)->SetChildVisibleByID(id + 0xb74, 0);
        }
        record++;
        row++;
    }
}
