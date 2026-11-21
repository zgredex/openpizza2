/* PC2 byte-match candidate: _malloc (0x551f8b, 18 bytes).
   Build: /O1 /TP.  CRT malloc forwards to __nh_malloc with the new-handler flag. */
typedef unsigned int size_t;

extern "C" void *__cdecl __nh_malloc(size_t size, int flag);
extern "C" int DAT_005858f8;

extern "C" void *__cdecl _malloc(size_t size)
{
    return __nh_malloc(size, DAT_005858f8);
}
