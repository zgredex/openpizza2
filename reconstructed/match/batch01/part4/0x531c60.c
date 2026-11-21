/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
void *operator new(unsigned int);
struct UI_ImageChild {
    unsigned char data[0xa0];
    UI_ImageChild(int a,int b,int c,unsigned d,int e,unsigned f, void *mgr);
};
struct UI_Manager { void EnsureObjectArray(void *obj, int id); void *CreateBitmapGadget(int a,int b,int c,unsigned d,int e,unsigned f); };
void *UI_Manager::CreateBitmapGadget(int a,int b,int c,unsigned d,int e,unsigned f)
{
    UI_ImageChild *p = new UI_ImageChild(a, b, c, d, e, f, this);
    EnsureObjectArray(p, a);
    return p;
}
