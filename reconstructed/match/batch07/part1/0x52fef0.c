/* Window_GetGadgetChecked (0x52fef0, 47 bytes).  Build: /O2 /TP.
   Returns the gadget record or reports a missing gadget and returns zero. */
extern char DAT_0057447c;
extern "C" int DebugConsole_Errorf(int console, int value, char *format,
                                  int gadget);

struct Array {
    int GetRecordByKey(int key);
};

struct Window {
    int GetGadgetChecked(int gadget);
};

int Window::GetGadgetChecked(int gadget)
{
    int record = ((Array *)this)->GetRecordByKey(gadget);

    if (record == 0) {
        DebugConsole_Errorf(*(int *)((char *)this + 0x134), 0, &DAT_0057447c,
                            gadget);
        record = 0;
    }
    return record;
}
