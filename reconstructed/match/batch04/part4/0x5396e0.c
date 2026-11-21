/* PC2 byte-match candidate: Surface_Reset (0x5396e0, 25 bytes).
   Build: /O2 /TP.  Resets the surface geometry from its 16-bit limits. */
struct Surface {
    unsigned char pad_000[4];
    int field_004;
    int field_008;
    int field_00c;
    int field_010;
    unsigned char pad_014[6];
    unsigned short limit_width;
    unsigned short limit_height;
    void Reset();
};

void Surface::Reset()
{
    field_00c = 0;
    field_004 = 0;
    field_008 = limit_width;
    field_010 = limit_height;
}
