struct IDMap { void *Lookup(int index, int *out); };
struct Record { void *GetStride60(int index); };
struct World { char pad[4]; char map[0x14]; char pad2[0x200]; void *player; char pad3[0xd8]; int playerIndex; };
extern int DAT_0057c670;
extern int DAT_0057d730;
void ExclusiveImport_UpdatePage(int *page);
void MarketShareMenu_Init(int *page)
{
    int i = 0;
    int *player = (int *)((struct World *)DAT_0057c670)->player;

    while (i < 5) {
        struct Record *record = (struct Record *)
            ((struct IDMap *)((char *)DAT_0057c670 + 4))->Lookup(
                ((struct World *)DAT_0057c670)->playerIndex, 0);
        int *entry = (int *)record->GetStride60(i);

        if (entry[4] == player[9])
            break;
        i++;
    }
    DAT_0057d730 = i;
    ExclusiveImport_UpdatePage(page);
}
