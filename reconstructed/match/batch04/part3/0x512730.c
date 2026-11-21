/* Product_HasStock: reports whether the indexed stock bucket is positive (0x512730). */
struct Product {
    char pad[0x64];
    int HasStock(unsigned int index);
};

int Product::HasStock(unsigned int index)
{
    return 0 < *(int *)((char *)this + (index & 0xff) * 4 + 0x64);
}
