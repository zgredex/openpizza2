/* Object_ClearState: resets the animation state record attached to an object
   (0x4f5db0). */
struct State {
    char pad[0x1c];
    int frame;
    char pad2[0xc];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};

struct Holder {
    char pad[8];
    State *state;
};

void __stdcall Object_ClearState(Holder *holder)
{
    if (holder != 0 && holder->state != 0) {
        holder->state->frame = -1;
        holder->state->a = 0;
        holder->state->b = 0;
        holder->state->c = 0;
        holder->state->d = 0;
    }
}
