/* Text_SetMetrics: stores the text metrics triplets (0x535520). */
struct Text {
    void SetMetrics(int first, int second, int third);
};

void Text::SetMetrics(int first, int second, int third)
{
    *(int *)((char *)this + 0x9a0) = first;
    *(int *)((char *)this + 0x9bc) = first;
    *(int *)((char *)this + 0x9a8) = first;
    *(int *)((char *)this + 0x9a4) = second - *(int *)((char *)this + 0x9b4);
    *(int *)((char *)this + 0x9c0) = second - *(int *)((char *)this + 0x9b4);
    *(int *)((char *)this + 0x9ac) = second - *(int *)((char *)this + 0x9b4);
    *(int *)((char *)this + 0x9c4) = third;
}
