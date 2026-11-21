/* BranchInfo_UpdateRatingBars: refreshes the branch header and its eight
   building-rating bars (0x48f860). */
extern int DAT_00582320;
extern int DAT_0057c670;
extern void CompanyRating_InitHeaderRow(void *branch);
extern int __fastcall Branch_ComputeBuildingRating(void *building, int maximum,
                                                   int index);
extern void Rating_UpdateBarByKey(void *branch, int key, int index, int value,
                                  int maximum);

void BranchInfo_UpdateRatingBars(void *branch)
{
    int i;

    CompanyRating_InitHeaderRow(branch);
    for (i = 0; i < 8; i++) {
        int *game = (int *)DAT_0057c670;

        Rating_UpdateBarByKey(
            branch, 0x4e2, i,
            Branch_ComputeBuildingRating(*(void **)((char *)game + 0x9c),
                                         DAT_00582320, i),
            DAT_00582320);
    }
}
