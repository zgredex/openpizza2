/* Array_RemoveAt (0x522fe0). */
extern void _memmove(void *dst, void *src, unsigned int size);

struct CS {
    void Enter();
    void Leave();
};
struct Array {
    char pad0[4];
    void *data;             /* 0x04 */
    int field08;            /* 0x08 */
    int count;              /* 0x0c */
    int field10;            /* 0x10 */

    int RemoveAt(int index);
};
extern CS DAT_00584180;

int Array::RemoveAt(int index)
{
    int remaining;

    if (index < 0 || index >= count)
        return 0;
    DAT_00584180.Enter();
    field08--;
    field10--;
    remaining = count - index - 1;
    if (remaining > 0) {
        _memmove((char *)data + index * 4, (char *)data + index * 4 + 4,
                 remaining * 4);
    }
    DAT_00584180.Leave();
    return 1;
}
