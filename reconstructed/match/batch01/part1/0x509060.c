/* UI_SetChildRecordVariant: sets the animation variant of a child record (0x509060). */
void __fastcall Record_SelectVariant(void *this_, int dummy, int key, int variant);

void __fastcall UI_SetChildRecordVariant(void *this_, int dummy, int variant)
{
    int *record;
    int key;

    if (variant == -1)
        return;
    record = *(int **)((char *)this_ + 0xc8);
    if (record == 0)
        return;
    if ((void *)record[0x16] == 0)
        return;
    key = *record;
    Record_SelectVariant((void *)record[0x16], dummy, key, variant);
    record = *(int **)((char *)this_ + 0xc8);
    if (record == 0)
        return;
    record[3] = variant;
}
