/* Array_Construct: allocate an Array with the requested capacity. */
extern "C" void *operator_new(unsigned int size);

struct Array {
    Array *Construct(int count);
};

Array *Array::Construct(int count)
{
    *(void **)this = (void *)0x55c774;
    if (count == 0) {
        *(int *)((char *)this + 4) = 0;
        *(int *)((char *)this + 0xc) = 0;
        *(int *)((char *)this + 8) = 0;
        *(int *)((char *)this + 0x10) = 0;
        return this;
    }
    *(void **)((char *)this + 4) = operator_new(count * 4);
    *(int *)((char *)this + 0xc) = count;
    *(int *)((char *)this + 8) = 0;
    *(int *)((char *)this + 0x10) = 0;
    return this;
}
