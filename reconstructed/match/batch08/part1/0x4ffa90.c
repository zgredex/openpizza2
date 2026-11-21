/* Company_ScheduleDeadline: records a deadline for one of the company's
   slots and logs the change (0x4ffa90). */
int __fastcall Game_GetDateField0C(char *game);
extern int DAT_0057c670;

struct Company {
    void PushRecentEntry(int index, int action, int first, int second);
    void ScheduleDeadline(int index, int days);
};

void Company::ScheduleDeadline(int index, int days)
{
    int date = Game_GetDateField0C((char *)DAT_0057c670);

    *(int *)((char *)this + index * 0x168 + 0x54) = date + days;
    PushRecentEntry(index, 1, -1, -1);
}
