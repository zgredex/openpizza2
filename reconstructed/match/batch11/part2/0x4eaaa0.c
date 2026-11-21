/* Game_SaveTileNameTable: writes the 2500 fixed-size tile names to the save
   stream (0x4eaaa0). */
struct CRT {
    void Ostream_Write(void *data, unsigned int size);
};

extern "C" char *__cdecl strcpy(char *destination, const char *source);

struct Game {
    char pad[0x25];

    void SaveTileNameTable(CRT *stream);
};

void Game::SaveTileNameTable(CRT *stream)
{
    char name[52];
    char *source = (char *)this + 0x25;
    int remaining = 0x9c4;

    do {
        strcpy(name, source);
        stream->Ostream_Write(name, 0x32);
        source += 0x48;
        remaining--;
    } while (remaining != 0);
}
