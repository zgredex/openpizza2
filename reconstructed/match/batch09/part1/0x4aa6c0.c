/* StatisticsBalance_Load: reads the four balance counters from a stream
   (0x4aa6c0). */
struct CRT_Istream {
    void Read(void *destination, int size);
};

void __cdecl StatisticsBalance_Load(void *stream)
{
    ((struct CRT_Istream *)stream)->Read((void *)0x569354, 4);
    ((struct CRT_Istream *)stream)->Read((void *)0x57d5c8, 4);
    ((struct CRT_Istream *)stream)->Read((void *)0x57d5d0, 4);
    ((struct CRT_Istream *)stream)->Read((void *)0x569358, 4);
}
