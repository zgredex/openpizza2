/* Entity_ApplyTypeProperties: copy the property triple for a type from the
   type table (0x4d2b40). */
extern "C" int DAT_0056b468[];

struct Entity {
    void ApplyTypeProperties(int type);
};

void Entity::ApplyTypeProperties(int type)
{
    int index = 0;
    int property1;
    int property0;

    *(int *)((char *)this + 0x20) = type;
    if (DAT_0056b468[0] != type) {
        while (1) {
            index += 4;
            if (DAT_0056b468[index] == -1)
                return;
            if (DAT_0056b468[index] == type)
                break;
        }
    }
    property1 = DAT_0056b468[index + 2];
    property0 = DAT_0056b468[index + 1];
    *(int *)((char *)this + 0x40) = property0;
    *(int *)((char *)this + 0x44) = property1;
    *(int *)((char *)this + 0x48) = DAT_0056b468[index + 3];
}
