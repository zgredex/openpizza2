/* Company_AddStaffMember: registers a person as a company staff member
   (0x4e2080). */
extern int *DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Person {
    char pad[0x74];
    int hasRoute;
    char pad1[0x98];
    int companyId;

    void GetPlayerValue(int value);
    void SetRouteToBuilding(int building);
    void SetBuildingRecordForAllCompanies(int type, int building);
};

struct List {
    void Add(void *value);
};

struct Company {
    char pad[0x48];
    int id;
    char pad1[0x16c];
    char list[0x20];
    int building;

    void AddStaffMember(int personId, int type);
};

extern "C" void *operator_new(unsigned int size);

void Company::AddStaffMember(int personId, int type)
{
    Person *person = (Person *)((struct IDMap *)((char *)DAT_0057c670 + 0x3c))
                         ->Lookup(personId, 0);

    if (person != 0) {
        person->companyId = id;
        if (type != 0x1f) {
            person->GetPlayerValue(-1);
        }
        if (person->hasRoute != 0) {
            person->SetBuildingRecordForAllCompanies(0x1c, building);
        } else {
            person->SetRouteToBuilding(building);
        }
        {
            int *entry = (int *)operator_new(8);

            entry[0] = personId;
            entry[1] = type;
            ((List *)((char *)this + 0x1b8))->Add(entry);
        }
    }
}
