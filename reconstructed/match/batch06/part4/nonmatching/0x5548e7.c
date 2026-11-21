/* Heap_FindBlock: finds the first heap block whose end is within one megabyte
   after the requested address (0x5548e7).  Build: /O2.

   NONMATCHING: closest genuine-C attempt.  Bytes 0..4 match, then the
   register allocator picks ecx for the block count and keeps two live
   temporaries for the "address - block[0xc]" comparison, so it also saves
   esi/edi and the function grows from 43 to 64 bytes.

   original:                         candidate:
     mov eax,ds:0x585bd8               mov ecx,ds:0x585bd8
     lea ecx,[eax+eax*4]               mov eax,ds:0x585bdc
     mov eax,ds:0x585bdc               push esi
     lea ecx,[eax+ecx*4]               push edi
     cmp eax,ecx                       lea ecx,[ecx+ecx*4]
     jae fail                          lea ecx,[eax+ecx*4]
     mov edx,[esp+4]                   cmp ecx,eax
     sub edx,[eax+0xc]                 jae fail
     cmp edx,0x100000                  ...
     jb return
     add eax,0x14
     jmp cmp

   The original keeps the difference in edx (sub edx,[eax+0xc]); every
   source spelling tried (value/pointer block types, extra count/end
   temporaries, /O1, /Ox, /G5, /G6, /Oa, /Ow, /Op, /TP) instead allocates a
   second temporary.  Kept here for the next attempt. */
unsigned int Heap_FindBlock(unsigned int address)
{
    unsigned int count = *(unsigned int *)0x585bd8;
    unsigned int block = *(unsigned int *)0x585bdc;
    unsigned int end = block + count * 0x14;

    while (block < end) {
        if (address - *(unsigned int *)(block + 0xc) < 0x100000)
            return block;
        block += 0x14;
    }
    return 0;
}
