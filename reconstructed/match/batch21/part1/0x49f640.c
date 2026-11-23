/* UI_RecordList_SetVisibleRange (0x49f640). */
struct Sound;

extern "C" struct Sound *g_SoundManager;

struct Slot {
    short value;
    short first;
    short last;
};

struct Record {
    int GetValue48(int index);
    void SetSlot6_98(int row, int column, Slot *slot);
};

struct RecordList {
    void ReadSlot98(int row, int column, Slot *slot);
    int GetCount();
};

struct Sound {
    void TriggerSoundById(int id);
};

struct UI {
    void ClearButtonRecordAnimation(int id);
    void *GetButtonContext(int id, int *out);
    void SetButtonRecordVariant(int id, int variant);
};

void __cdecl UI_RecordList_SetVisibleRange(UI *ui, int id, int visible)
{
    Slot slot;
    int buttonId = id;
    RecordList *list;

    ui->ClearButtonRecordAnimation(buttonId);
    list = (RecordList *)ui->GetButtonContext(buttonId, &id);
    if (list != 0) {
        list->ReadSlot98(1, 0, &slot);
        int value = ((Record *)list)->GetValue48(id);
        int count = list->GetCount();
        slot.value = (short)value;
        if (visible != 0) {
            slot.last = (short)(count - 1);
            g_SoundManager->TriggerSoundById(0xd);
        } else {
            slot.last = 0;
        }
        ((Record *)list)->SetSlot6_98(1, 0, &slot);
        ui->SetButtonRecordVariant(0x438, 1);
    }
}
