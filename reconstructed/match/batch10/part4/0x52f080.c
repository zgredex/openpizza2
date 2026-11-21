/* Gadget_SetTextf (0x52f080): formats the caller's arguments into a 1024-byte
   stack buffer and sends a text notification to the owning window. */
extern "C" {
int CRT_Vsprintf(char *buffer, const char *format, void *arguments);
}

struct Window {
    void GadgetNotify(int id, int type, int code, int value, void *data);
};

void Gadget_SetTextf(void *gadget, int id, char *format, int argument)
{
    char buffer[1024];

    CRT_Vsprintf(buffer, format, &argument);
    ((Window *)gadget)->GadgetNotify(id, 0, 0xe, 0, buffer);
}
