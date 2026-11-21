/* Record_SetDoubles48: stores two integer values as doubles in a 0x48-byte
   record slot (0x5342e0). */
struct Record {
    char pad[0x48];
    int count;
    int *slots;
    int SetDoubles48(int index, int first, int second);
};

int Record::SetDoubles48(int index, int first, int second)
{
    if (index >= 0 && index < *(int *)((char *)this + 0x48)) {
        int *slot = (int *)(*(int *)((char *)this + 0x4c) + index * 0x48);

        if (*slot != -1) {
            *(double *)(slot + 2) = (double)first;
            *(double *)(*(int *)((char *)this + 0x4c) + 0x10 + index * 0x48)
                = (double)second;
            return 1;
        }
    }
    return 0;
}
