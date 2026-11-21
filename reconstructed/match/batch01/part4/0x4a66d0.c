/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct Employee {
    int FindCityIndex(void);    /* __thiscall */
};

struct UIObject {
    void RemoveObjectByKey(int key);
    void ShowChildByID(int id);
    void SetButtonSpriteByName(int id, const char *name);
};

extern "C" int __cdecl String_Format(char *buf, const char *fmt, ...);

extern "C" void __cdecl Personnel_SetEmployeePhotoByKey(void *ui, int id, int employee)
{
    char local_100[256];

    if (employee != 0) {
        int field = *(int *)(employee + 0x1e0);
        int city = ((Employee *)employee)->FindCityIndex();
        String_Format(local_100, (const char *)0x569148, field + 1, city + 1);
        ((UIObject *)ui)->ShowChildByID(id);
        ((UIObject *)ui)->SetButtonSpriteByName(id, local_100);
    } else {
        ((UIObject *)ui)->RemoveObjectByKey(id);
    }
}
