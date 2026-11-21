/* Distance_Manhattan3: weighted Manhattan distance of two points (0x4ed570). */
int abs(int value);
#pragma intrinsic(abs)

int __stdcall Distance_Manhattan3(int firstX, int firstY, int secondX, int secondY)
{
    return abs(firstX - secondX) * 3 + abs(firstY - secondY) * 4;
}
