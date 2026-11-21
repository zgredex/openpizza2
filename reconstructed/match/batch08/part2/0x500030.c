/* UI_UpdateAllSlots: schedules deadlines for the six company slots
   (0x500030). */
struct Company {
    void ScheduleDeadline(int index, int days);
};

extern int DAT_0057bb24;

struct UI {
    char pad[0x118];
    int slots[1];
    void UpdateAllSlots();
};

void UI::UpdateAllSlots()
{
    int index = 0;
    int *slot = (int *)((char *)this + 0x118);

    do {
        if (*slot != 0) {
            ((struct Company *)this)
                ->ScheduleDeadline(index, 10 - DAT_0057bb24);
        }
        index++;
        slot += 0x5a;
    } while (index < 6);
}
