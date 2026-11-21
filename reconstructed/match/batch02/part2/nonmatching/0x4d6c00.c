/* First attempt for 0x4d6c00 - does not match (dummy edx argument). */
extern void __fastcall City_RemovePersonAndMaintainPopulation(void *this_,
                                                              int unused,
                                                              int person_id);

void __fastcall City_RemovePersonEntry(void *this_, int unused, int *person)
{
    City_RemovePersonAndMaintainPopulation(this_, 0, *person);
}
