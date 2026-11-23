struct RefCounted { int pad; unsigned int count; };
extern "C" unsigned int __stdcall RefCount_AddRef(RefCounted *self)
{
    return ++self->count;
}