/* ResetScreenRegistry: clears the five 100-entry screen registry tables
   (0x403580). */
extern int DAT_00563364;
extern int DAT_00579ffc[100];
extern int DAT_00579e68[100];
extern int DAT_0057b31c[100];
extern int DAT_0057a18c[100];
extern int DAT_00579b48[100];

void ResetScreenRegistry(void)
{
    int i;

    for (i = 0; i < 100; i++) {
        DAT_00579ffc[i] = DAT_00563364;
    }
    for (i = 0; i < 100; i++) {
        DAT_00579e68[i] = 0;
    }
    for (i = 0; i < 100; i++) {
        DAT_0057b31c[i] = 0;
    }
    for (i = 0; i < 100; i++) {
        DAT_0057a18c[i] = 0;
    }
    for (i = 0; i < 100; i++) {
        DAT_00579b48[i] = 0;
    }
}
