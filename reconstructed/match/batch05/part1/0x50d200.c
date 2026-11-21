/* Object_SetFrame5: stores a frame index scaled by five, with -1 kept
   (0x50d200). */
struct Object {
    char pad[0x94];
    int frame5;
    void SetFrame5(int frame);
};

void Object::SetFrame5(int frame)
{
    if (frame == -1) {
        frame5 = -1;
        return;
    }
    frame5 = frame * 5;
}
