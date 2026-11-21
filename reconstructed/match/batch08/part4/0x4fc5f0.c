/* Company_RefreshMenuSalesIfDue: refreshes menu sales when the cached date
   is due (0x4fc5f0). */
extern void *DAT_0057c670;

struct Company {
    int RefreshMenuSalesIfDue(int index);
};

struct Game {
    int GetDateField0C();
    void RecomputeCompanyMenuSales(int index);
};

int Company::RefreshMenuSalesIfDue(int index)
{
    int date = ((Game *)DAT_0057c670)->GetDateField0C();

    if (date >= *(int *)((char *)this + index * 0x168 + 0x44)) {
        *(int *)((char *)this + index * 0x168 + 0x44) = date + 0x18;
        ((Game *)this)->RecomputeCompanyMenuSales(index);
    }
    return 1;
}
