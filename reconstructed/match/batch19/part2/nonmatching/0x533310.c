// Record_CopyTemplate98: copies a fixed-size record template.

extern "C" {
char *strcpy(char *dst, const char *src);
}

struct SourceRec {
    short field0;
    short pad02;
    short field4;
    short pad06;
    int flag;
    char fieldC;
    char pad13[3];
};

struct DestRec {
    short field0;
    short field2;
    char field4;
    char field5;
};

void Record_CopyTemplate98(char *src, char *dst)
{
    int i;

    strcpy(dst + 0x80, src);
    *(int *)(dst + 0x60) = *(int *)(src + 0x70);
    *(int *)(dst + 0x64) = *(int *)(src + 0x74);
    *(int *)(dst + 0x68) = *(int *)(src + 0x78);
    *(int *)(dst + 0x6c) = *(int *)(src + 0x7c);
    *(char *)(dst + 0x90) = (char)(*(double *)(src + 0x80) * 1000.0);
    *(int *)(dst + 0x70) = *(int *)(src + 0x88);
    *(int *)(dst + 0x74) = *(int *)(src + 0x8c);
    *(int *)(dst + 0x78) = *(int *)(src + 0x90);
    *(int *)(dst + 0x7c) = *(int *)(src + 0x94);
    for (i = 0; i < 6; i++) {
        DestRec *out = (DestRec *)dst + i;
        SourceRec *in = (SourceRec *)(src + 0x10) + i;
        out->field0 = in->field0;
        out->field2 = in->field4;
        out->field5 = in->flag == 1;
        out->field4 = in->fieldC;
    }
    for (i = 0; i < 10; i++) {
        DestRec *out = (DestRec *)(dst + 0x24) + i;
        out->field0 = -1;
        out->field2 = 0;
        out->field4 = 0;
        out->field5 = 0;
    }
}
