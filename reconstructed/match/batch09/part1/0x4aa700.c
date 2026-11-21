/* StatisticsBalance_Save: writes the four balance counters to a stream
   (0x4aa700). */
struct CRT_Ostream {
    void Write(void *source, int size);
};

void __cdecl StatisticsBalance_Save(void *stream)
{
    ((struct CRT_Ostream *)stream)->Write((void *)0x569354, 4);
    ((struct CRT_Ostream *)stream)->Write((void *)0x57d5c8, 4);
    ((struct CRT_Ostream *)stream)->Write((void *)0x57d5d0, 4);
    ((struct CRT_Ostream *)stream)->Write((void *)0x569358, 4);
}
