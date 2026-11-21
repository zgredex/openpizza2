/* Input_CompleteEvent (0x403b60, 47 bytes).  Build: /O2 /TP.
   Clears the event record's pending field and signals the input thread. */
extern int (__stdcall *DAT_0055c094)(void *event);

struct List {
    int *FindByKey(int key);
};

struct Input {
    int CompleteEvent(int key);
};

int Input::CompleteEvent(int key)
{
    int *record = ((List *)this)->FindByKey(key);

    if (record == 0)
        return 0;
    record[3] = 0;
    DAT_0055c094(*(void **)((char *)this + 0x6c));
    return 1;
}
