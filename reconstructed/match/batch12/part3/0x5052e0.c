/* Person_Save (0x5052e0). */

struct Ostream {
    void CRT_Ostream_Write(void *data, int size);
};

struct MapSprite {
    void MapSprite_Save(void *stream, int size);
};

struct Person {
    void Save(void *stream);
};

void Person::Save(void *stream)
{
    int flag;

    if (*(int *)((char *)this + 0xc8) == 0) {
        flag = 0;
        ((struct Ostream *)stream)->CRT_Ostream_Write(&flag, 4);
        return;
    }
    flag = 1;
    ((struct Ostream *)stream)->CRT_Ostream_Write(&flag, 4);
    ((struct MapSprite *)*(void **)((char *)this + 0xc4))->MapSprite_Save(
        stream, *(int *)((char *)this + 0xc8));
}
