/* UI_Group_Create (0x532330). */
typedef char *va_list;
#define va_start(ap, last) ((ap) = (char *)&(last) + sizeof(last))
#define va_arg(ap, type) (*(type *)(((ap) += sizeof(type)) - sizeof(type)))

struct Array {
    char pad[0x14];
    void Construct(int value);
    int InsertGrow(void *item);
};

struct SelectionGroup {
    int field0;
    Array members;
    SelectionGroup(int value) { members.Construct(value); }
};

struct UI {
    char pad[0x148];
    Array groups;
    int Group_Create(int field0, int count, ...);
    void ApplyMemberSelection(void *group, int flag);
};

int UI::Group_Create(int field0, int count, ...)
{
    SelectionGroup *group = new SelectionGroup(0);
    int result = -1;
    if (0 < count) {
        va_list ap;
        int i = 1;
        va_start(ap, count);
        group->members.InsertGrow((void *)va_arg(ap, int));
        if (i < count) {
            do {
                int value = va_arg(ap, int);
                if (value == -1)
                    break;
                group->members.InsertGrow((void *)value);
                i++;
            } while (i < count);
        }
        group->field0 = field0;
        result = groups.InsertGrow(group);
        ApplyMemberSelection(group, -1);
    }
    return result;
}
