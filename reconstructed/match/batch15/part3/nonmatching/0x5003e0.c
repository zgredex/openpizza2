/* Non-matching candidate.
   First difference: offset 0x30, 31 bytes differ.
   original keeps the account double on the x87 stack (fcom, fadd st,st(2)); candidate reloads it (fcomp, fadd m64).
   Kept for evidence; not part of the strict match set. */
struct Game { void UpdateCompanyAccount(int *company); };
void Game::UpdateCompanyAccount(int *company)
{
    int index = *(int *)((char *)company + 0x4c);
    if (index != 0) {
        int *account = (int *)((char *)this + index * 0x168 + 0x19c);
        int balance = *(int *)((char *)this + index * 0x168 + 0x19c);
        if (balance >= 1) {
            if (*(double *)((char *)company + 0x108) < 0.0) {
                double credit = (double)balance;
                if (1000.0 < credit)
                    credit = 1000.0;
                *(double *)((char *)company + 0x108) = credit + *(double *)((char *)company + 0x108);
                *account = *account - (int)credit;
                return;
            }
            *account = balance - 0xfa;
            if (balance - 0xfa < 0)
                *account = 0;
        }
    }
}
