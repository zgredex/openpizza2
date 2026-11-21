/* UI_RemoveProfileStatElements (0x4a5360): removes the profile statistic
   gadgets from a window. */
struct UI {
    void RemoveObjectByKey(int key);
};

extern "C" void UI_RemoveProfileStatElements(UI *ui)
{
    ui->RemoveObjectByKey(0x1f67);
    ui->RemoveObjectByKey(0x1f66);
    ui->RemoveObjectByKey(0x433);
    ui->RemoveObjectByKey(0x43a);
    ui->RemoveObjectByKey(0x1f61);
    ui->RemoveObjectByKey(0x1f63);
    ui->RemoveObjectByKey(0x1f62);
    ui->RemoveObjectByKey(0x1f65);
    ui->RemoveObjectByKey(0x1f64);
    ui->RemoveObjectByKey(0x439);
}
