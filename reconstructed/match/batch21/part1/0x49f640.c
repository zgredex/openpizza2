/* UI_RecordList_SetVisibleRange (0x49f640).
   The 6-byte slot copies through ReadSlot98/SetSlot6_98, but only its first
   two shorts are range fields; the third short is untouched. The button id
   passed to GetButtonContext is a separate local so that `id` stays a plain
   value parameter and is cached in ESI across the first call. */
struct Sound;

extern "C" struct Sound *g_SoundManager;

struct Slot {
    short value;
    short last;
    short reserved;
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
    RecordList *list;

    int outId;
    ui->ClearButtonRecordAnimation(id);
    list = (RecordList *)ui->GetButtonContext(id, &outId);
    if (list != 0) {
        list->ReadSlot98(1, 0, &slot);
        int value = ((Record *)list)->GetValue48(outId);
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
