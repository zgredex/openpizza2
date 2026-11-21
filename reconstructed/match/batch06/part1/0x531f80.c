/* UI_ReleaseChildBufferByKey: releases the child buffer with the given key (0x531f80). */
struct Buffer {
    void ReleaseField0C();
};

int __fastcall BinarySearch8(void *self, int dummy, int key, int zero);

void __fastcall UI_ReleaseChildBufferByKey(char *ui, int dummy, int key)
{
    int index = BinarySearch8(ui, dummy, key, 0);

    if (index != -1) {
        Buffer *buffer = *(Buffer **)(*(char **)(ui + 0xe8) + index * 8);
        buffer->ReleaseField0C();
    }
}
