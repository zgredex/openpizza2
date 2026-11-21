/* Map_ComputeIsoOffsets: derives the isometric width/height offsets (0x4ed010). */
struct Map {
    char pad0[0xc];
    int width;
    int height;
    char pad1[0xd8 - 0x14];
    int offsetD8;
    int offsetDC;
    int offsetE0;
    int offsetE4;
    void ComputeIsoOffsets();
};

void Map::ComputeIsoOffsets()
{
    int width = *(int *)((char *)this + 0xc) << 1;

    *(int *)((char *)this + 0xd8) = width;
    *(int *)((char *)this + 0xdc) = width;
    int height = *(int *)((char *)this + 0x10);
    *(int *)((char *)this + 0xe0) = height * 2;
    *(int *)((char *)this + 0xe4) = height * 3;
}
