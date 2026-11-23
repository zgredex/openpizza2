extern float DAT_0055c2e4;
extern float DAT_0055c320;

/* Game_GetAverageRecordValueByByte8: averages field 0xc across records whose
   byte 8 matches the requested player (0x47c9a0). */
struct Game {
    int GetPlayerByte8();
};

struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Map {
    unsigned char GetAverageRecordValueByByte8(char value);
};

extern "C" int __cdecl Math_RoundFloat(float value);

unsigned char Map::GetAverageRecordValueByByte8(char value)
{
    int i = 0;
    int count = 0;
    float sum = 0.0f;

    if (0 < *(int *)((char *)this + 0x170c)) {
        do {
            int record = (int)((IDMap *)((char *)this + 0x16f8))->Lookup(i, 0);

            if (record != 0) {
                char byte8 = (char)((Game *)record)->GetPlayerByte8();

                if (byte8 == value) {
                    count = count + 1;
                    sum = (float)*(int *)(record + 0xc) + sum;
                }
            }
            i = i + 1;
        } while (i < *(int *)((char *)this + 0x170c));
        if (0 < count) {
            sum = sum / (float)count;
            if (sum > DAT_0055c320) {
                sum = 100.0f;
                return Math_RoundFloat(sum);
            }
            if (sum < DAT_0055c2e4) {
                sum = 0.0f;
            }
            return Math_RoundFloat(sum);
        }
    }
    return 0;
}
