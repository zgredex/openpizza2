/* Object_AccumulateIncome: adds the pending income field to the total (0x480740). */
void __fastcall Object_AccumulateIncome(char *this_)
{
    *(int *)(this_ + 0x16bc) =
        *(int *)(this_ + 0x16bc) + *(int *)(this_ + 0x14d4);
}
