/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct UIObject {
    void RemoveObjectByKey(int key);
    void ShowChildByID(int id);
    void ReleaseChildBufferByKey(int id);
    void SetObjectTextByKey(int id, const char *text);
};

extern "C" int __cdecl String_Format(char *buf, const char *fmt, ...);

extern "C" char *g_ratingFormatA;       /* 0x580f44 */
extern "C" char *g_ratingFormatB;       /* 0x580f54 */
extern "C" int g_ratingOffsetsA[8];     /* 0x569288 */
extern "C" int g_ratingOffsetsB[8];     /* 0x5834d4 */

extern "C" void __cdecl Rating_UpdateBarByKey(void *param_1, int param_2,
                                              int param_3, int param_4,
                                              int param_5)
{
    int iVar1;
    int iVar2;
    int i;
    int key;
    char local_100[256];

    local_100[0] = '\0';
    if (param_5 != 0) {
        if (param_3 >= 0 && param_3 < 8)
            String_Format(local_100, g_ratingFormatA, param_5,
                          g_ratingOffsetsB[param_3], param_4);
        else
            String_Format(local_100, g_ratingFormatB, param_5, param_4);
    }
    if (param_3 < 0)
        param_3 = 0;
    iVar1 = g_ratingOffsetsA[param_3] + -0x10 + param_2;
    for (i = 0; i < 0x11; i++) {
        ((UIObject *)param_1)->RemoveObjectByKey(i + iVar1);
    }
    if (param_4 < 0)
        param_4 = 0;
    else if (100 < param_4)
        param_4 = 100;
    iVar2 = (param_4 * 0x10 + 0x32) / 100;
    if (100 < iVar2)
        iVar2 = 100;
    key = iVar2 + iVar1;
    ((UIObject *)param_1)->ShowChildByID(key);
    if (local_100[0] != '\0') {
        ((UIObject *)param_1)->SetObjectTextByKey(key, local_100);
    } else {
        ((UIObject *)param_1)->ReleaseChildBufferByKey(key);
    }
}
