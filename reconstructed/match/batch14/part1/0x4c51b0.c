/* CityInfo_UpdateDemandRatingBars (0x4c51b0): fills the city demand-rating
   bars from the weather-weighted category demand table. */
extern int DAT_0057c670;
extern int DAT_00580ed4;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Economy {
    int ApplyTablePercent(int index);
};

int __cdecl Rating_UpdateBarByKey(void *target, int key, int index, int value,
                                  int extra);
void __cdecl Submenu_SetObjectPicture(void *target, int picture, int arg3,
                                      int arg4, int arg5, void *owner);
void __cdecl CityInfo_InitQuarterPanel(void *target);

void __cdecl CityInfo_UpdateDemandRatingBars(void *param_1)
{
    void *city;
    int index;

    city = ((IDMap *)(DAT_0057c670 + 4))
               ->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);
    index = 0;
    do {
        int value = ((Economy *)city)->ApplyTablePercent(index);
        Rating_UpdateBarByKey(param_1, 0x58e, index, value, DAT_00580ed4);
        index = index + 1;
    } while (index < 8);
    Submenu_SetObjectPicture(
        param_1, *(int *)(*(int *)(DAT_0057c670 + 0x218) + 0x20), 1, 0x1f55,
        -1, *(void **)(DAT_0057c670 + 0x218));
    CityInfo_InitQuarterPanel(param_1);
}
