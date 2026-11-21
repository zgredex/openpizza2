/* FurniturePriceMenu_Init - 0x4bb650, 16 bytes */
extern void Window_UpdateBranchInfoPage(void *page, char mode);

void FurniturePriceMenu_Init(void *page)
{
    Window_UpdateBranchInfoPage(page, 1);
}
