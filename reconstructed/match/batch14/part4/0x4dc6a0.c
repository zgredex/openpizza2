/* Calendar_InterpolateMonthlyValue (0x4dc6a0): interpolates the monthly
   value between two stored calendar entries. */
struct CalendarGlobal {
    char pad[0x94];
    unsigned char *date;
};

extern CalendarGlobal *DAT_0057c670;

struct Calendar {
    char pad[0xa4];
    int monthly[4];

    int InterpolateMonthlyValue();
};

int Calendar::InterpolateMonthlyValue()
{
    int month = DAT_0057c670->date[7];
    int index = DAT_0057c670->date[8];
    int previous;
    int current;
    int next;

    if (month < 0xc) {
        previous = monthly[(index - 1) & 3] - 6;
        current = monthly[index];
        return previous + ((current - previous + 6) * month) / 12;
    }
    current = monthly[index];
    next = current + 6;
    return next + ((current - next - 6) * (month - 0xc)) / 12;
}
