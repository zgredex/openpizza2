struct UI { int FindWindowByID(int id, int *index); };
int UI::FindWindowByID(int id, int *index)
{
    int count = *(int *)((char *)this + 0x23c);
    int i;
    for (i = 0; i < count; i++) {
        int window = *(int *)((char *)this + 0x14 + i * 4);
        if (window != 0 && *(int *)(window + 4) == id) {
            if (index != 0) *index = i;
            return window;
        }
    }
    if (index != 0) *index = -1;
    return 0;
}
