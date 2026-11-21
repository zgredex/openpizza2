/* Storage_SetSupplierBuilding: select the supplier building of a storage. */
extern int DAT_0057c670;
extern "C" void __fastcall Storage_OrderDelivery(void *storage);

struct UI {
    void QueueControlCommand(int command, int type, int value);
};

struct Storage {
    void SetSupplierBuilding(int building);
};

void Storage::SetSupplierBuilding(int building)
{
    void *ui;

    *(int *)((char *)this + 0x30) = building;
    ui = *(void **)(DAT_0057c670 + 0x264);
    if (ui != 0) {
        ((UI *)ui)->QueueControlCommand(-99868, 0x23, 0);
        ((UI *)ui)->QueueControlCommand(-99929, 0x23, 0);
    }
    if (building != -1)
        Storage_OrderDelivery(this);
}
