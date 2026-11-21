/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
void *operator new(unsigned int);
struct UI_Bar {
    virtual ~UI_Bar();
    unsigned char data[0x4f4];
    UI_Bar(int a, int b, int c, int d, unsigned e, void *mgr, char *name, int g, int &result);
};
struct UI_Manager {
    void EnsureObjectArray(void *object, int id);
    int CreateSlider(int p1, int p2, int p3, unsigned p4, char *p5, int p6, int p7);
};
int UI_Manager::CreateSlider(int p1, int p2, int p3, unsigned p4, char *p5, int p6, int p7)
{
    int result;
    UI_Bar *bar = new UI_Bar(p1, p6, p2, p3, p4, this, p5, p7, result);
    if (result != 0) {
        if (bar != 0)
            delete bar;
        return 0;
    }
    EnsureObjectArray(bar, p1);
    return 1;
}
