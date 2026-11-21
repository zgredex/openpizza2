/* UI_DispatchCallback: forwards a callback through the manager stored at
   offset 0x134 of the object at offset 8 (0x520fd0). */
struct UI {
    void InvokeCallback(void *a, void *b, void *c, void *d);
};

struct Dispatcher {
    char pad[4];
    void *field4;
    void *field8;
    char pad2[0x40 - 0xc];
    void *field40;
    void DispatchCallback(void *param);
};

void Dispatcher::DispatchCallback(void *param)
{
    UI *ui = *(UI **)((char *)field8 + 0x134);
    ui->InvokeCallback(field8, field4, field40, param);
}
