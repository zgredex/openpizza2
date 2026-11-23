/* Object_SyncChildState: adjusts the six child state values from a key code
   (0x5094a0). */
struct Object {
    void SyncChildState(void *child, int key);
};

void Object::SyncChildState(void *child, int key)
{
    int index = *(int *)((char *)child + 0x30);
    int i;
    int value;

    if (*(int *)((char *)this + 0x58) == index) {
        *(int *)((char *)this + 0x58) = -1;
    }
    if (key > 0x5f) {
        *(int *)((char *)this + index * 4 + 0x5c) = 100;
        *(int *)((char *)this + 0x58) = index;
        for (i = 0; i < 6; i++) {
            if (i != index) {
                *(int *)((char *)this + i * 4 + 0x5c) =
                    *(int *)((char *)this + i * 4 + 0x5c) - 10;
            }
        }
    } else if (key >= 0x55) {
        value = *(int *)((char *)this + index * 4 + 0x5c) + 10;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0x4b) {
        value = *(int *)((char *)this + index * 4 + 0x5c) + 8;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0x41) {
        value = *(int *)((char *)this + index * 4 + 0x5c) + 5;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0x37) {
        value = *(int *)((char *)this + index * 4 + 0x5c) + 3;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0x2d) {
    } else if (key >= 0x23) {
        value = *(int *)((char *)this + index * 4 + 0x5c) - 3;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0x19) {
        value = *(int *)((char *)this + index * 4 + 0x5c) - 5;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else if (key >= 0xf) {
        value = *(int *)((char *)this + index * 4 + 0x5c) - 10;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    } else {
        value = *(int *)((char *)this + index * 4 + 0x5c) - 0x14;
        *(int *)((char *)this + index * 4 + 0x5c) = value;
    }
    for (i = 0; i < 6; i++) {
        if (100 < *(int *)((char *)this + i * 4 + 0x5c)) {
            *(int *)((char *)this + i * 4 + 0x5c) = 100;
        }
        if (*(int *)((char *)this + i * 4 + 0x5c) < -100) {
            *(int *)((char *)this + i * 4 + 0x5c) = -100;
        }
    }
}
