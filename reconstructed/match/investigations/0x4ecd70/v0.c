struct Stream { void Read(void *b, int n); };
struct Record { void SetDoubles48(int k,int a,int b); void SetDoubles48B(int k,double a,double b); void ClearActive48(int k); void SelectVariant(int k,int v); };
struct ActorObject { void SetShort28(int v); };
struct FieldArray { void Clear(); void Grow(int i); };
struct RecordSet { int FindRecordByKey28(int f, int k); };
extern "C" { extern int DAT_0057c668; __declspec(dllimport) int __stdcall SetRect(void *r,int l,int t,int rt,int b); }
struct Actor { void ReadFromStream(Stream *stream, int *actor); };
void Actor::ReadFromStream(Stream *stream, int *actor)
{
    int local_18, local_14, local_10, local_c, local_8, local_4;
    Stream *s = stream; int flag; int iVar1;
    s->Read(&stream, 1);
    s->Read(&local_18, 4); s->Read(&local_10, 4);
    ((Record *)*(int *)((char *)actor + 0x58))->SetDoubles48(*actor, local_18, local_10);
    s->Read(&local_18, 4); s->Read(&local_10, 4);
    ((Record *)*(int *)((char *)actor + 0x58))->SetDoubles48B(*actor, (double)local_18, (double)local_10);
    s->Read((char *)actor + 8, 2); s->Read((char *)actor + 10, 2);
    s->Read((char *)actor + 12, 4); s->Read((char *)actor + 16, 1);
    s->Read(&local_4, 4);
    ((ActorObject *)actor)->SetShort28(local_4);
    s->Read((char *)actor + 0x2c, 4); s->Read((char *)actor + 0x30, 8);
    s->Read((char *)actor + 0x38, 8); s->Read((char *)actor + 0x40, 4);
    if (DAT_0057c668 < 0x2a) { *(int *)((char *)actor + 0x44) = -1; s->Read((char *)actor + 0x48, 4); }
    else s->Read((char *)actor + 0x44, 8);
    s->Read((char *)actor + 0x54, 4);
    if (DAT_0057c668 < 0x2a) { *(int *)((char *)actor + 0x4c) = -1; s->Read((char *)actor + 0x50, 4); }
    else s->Read((char *)actor + 0x4c, 8);
    SetRect((char *)actor + 0x5c, 0xffff, 0xffff, -1, -1);
    local_c = (int)this;
    flag = (actor[1] != -1);
    s->Read(&local_8, 4);
    ((FieldArray *)((char *)actor + 0x14))->Clear();
    local_18 = 0;
    if (0 < local_8) {
        do { s->Read(&local_14, 2); iVar1 = ((RecordSet *)local_c)->FindRecordByKey28(flag, local_14 & 0xffff);
             ((FieldArray *)((char *)actor + 0x14))->Grow(iVar1); local_18++; } while (local_18 < local_8);
    }
    s->Read(&local_18, 4);
    if (local_18 == 0) actor[8] = 0;
    else { s->Read(&local_14, 2); actor[8] = ((RecordSet *)local_c)->FindRecordByKey28(flag, local_14 & 0xffff); }
    s->Read(&local_18, 4);
    if (local_18 == 0) actor[9] = 0;
    else { s->Read(&local_14, 2); actor[9] = ((RecordSet *)local_c)->FindRecordByKey28(flag, local_14 & 0xffff); }
    ((Record *)*(int *)((char *)actor + 0x58))->ClearActive48(*actor);
    if ((char)stream != '\0') ((Record *)*(int *)((char *)actor + 0x58))->SelectVariant(*actor, actor[3]);
}
