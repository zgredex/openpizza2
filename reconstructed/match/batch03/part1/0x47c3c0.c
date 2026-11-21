/* Array_Copy68: copies 0x68 dwords from offset 0x151c to a caller buffer (0x47c3c0). */
struct Array {
    char pad[0x151c];
    unsigned int data[0x68];
    void Copy68(unsigned int *dest);
};

struct Block {
    unsigned int words[0x68];
};

void Array::Copy68(unsigned int *dest)
{
    *(Block *)dest = *(Block *)data;
}
