// RecordArray_CompactEmpty48: drops empty records and compacts the array.

extern "C" void *_memmove(void *dst, const void *src, unsigned int size);

struct VObject {
    virtual void Destroy(int flag);
};

struct RecordArray {
    void CompactEmpty48();
};

void RecordArray::CompactEmpty48()
{
    int index = 0;
    int offset = 0;
    char *records = *(char **)((char *)this + 0x82f8);

    while (index < *(int *)((char *)this + 0x82fc)) {
        if (*(int *)(records + offset + 0x44) == 0) {
            int end = index;
            int savedOffset = offset;
            int removed;
            int move;
            int k;
            while (end < *(int *)((char *)this + 0x82fc) &&
                   *(int *)(records + end * 0x48 + 0x44) == 0)
                end++;
            end--;
            removed = end - index + 1;
            for (k = index; k <= end; k++) {
                void *object = *(void **)(records + offset + 0x40);
                if (object != 0)
                    ((VObject *)object)->Destroy(1);
                offset += 0x48;
            }
            move = *(int *)((char *)this + 0x82fc) - end - 1;
            if (move > 0)
                _memmove(records + savedOffset, records + (end + 1) * 0x48,
                         move * 0x48);
            *(int *)((char *)this + 0x82fc) -= removed;
            offset = savedOffset;
        }
        index++;
        offset += 0x48;
    }
}
