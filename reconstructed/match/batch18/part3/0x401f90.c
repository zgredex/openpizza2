extern "C" char *__cdecl strcpy(char *dest, const char *source);

/* ResourceIterator_Next: advances a resource iterator and copies the current
   record into the caller's descriptor (0x401f90). */

struct ResourceItem {
    int value0;
    int value1;
    int value2;
    int value3;
    char *name;
};

struct ResourceGroup {
    int *count;
    ResourceItem *items;
    char pad[0x120 - 8];
};

struct ResourceIterator {
    char pad[0x1684];
    int count;
    int Next(char *out);
};

int ResourceIterator::Next(char *out)
{
    int group_index = *(int *)(out + 0x114);
    int item_index;
    ResourceGroup *group;
    ResourceItem *item;

    if (group_index >= count) {
        return 0;
    }
    item_index = *(int *)(out + 0x118);
    *(int *)(out + 0x118) = item_index + 1;
    group = (ResourceGroup *)((char *)this + group_index * 0x120 + 0x110);
    if (item_index + 1 >= *group->count) {
        *(int *)(out + 0x118) = 0;
        *(int *)(out + 0x114) = group_index + 1;
        if (group_index + 1 >= count) {
            return 0;
        }
    }
    group = (ResourceGroup *)((char *)this + *(int *)(out + 0x114) * 0x120 + 0x110);
    item = &group->items[*(int *)(out + 0x118)];
    strcpy(out, item->name);
    *(int *)(out + 0x104) = item->value0;
    *(int *)(out + 0x108) = item->value1;
    *(int *)(out + 0x10c) = item->value2;
    *(int *)(out + 0x110) = item->value3;
    return 1;
}
