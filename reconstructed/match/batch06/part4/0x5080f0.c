/* Object_IsSiteRatingSufficient: compares the object's site rating with the
   customer-group rating of its branch (0x5080f0).  Build: /O2 /TP. */
struct Branch {
    char pad[0x2c];
    int rating;
    int GetCustomerGroupRating(int group, int flag);
};

struct Object {
    char pad[0x2c];
    int rating;
    char pad2[4];
    int group;
    bool IsSiteRatingSufficient(Branch *branch, int unused);
};

bool Object::IsSiteRatingSufficient(Branch *branch, int unused)
{
    if (branch->rating != 0)
        return false;
    if (branch->GetCustomerGroupRating(group, 0) >= rating)
        return true;
    return false;
}
