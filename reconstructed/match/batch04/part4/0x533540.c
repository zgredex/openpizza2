/* PC2 byte-match candidate: Get_WidthHeight (0x533540, 27 bytes).
   Build: /O2 /TP.  Returns the two 16-bit dimensions as ints. */
struct Object {
    unsigned char pad_000[0x12];
    unsigned short width;
    unsigned short height;
    void GetWidthHeight(unsigned *pw, unsigned *ph);
};

void Object::GetWidthHeight(unsigned *pw, unsigned *ph)
{
    *pw = width;
    *ph = height;
}
