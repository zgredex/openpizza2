extern char DAT_0055c4ec;

struct Destroyable {
    virtual ~Destroyable();
};

struct ListNode {
    ~ListNode();
};

struct MapObject {
    void *vtable;              /* 0x00 */
    int type;                  /* 0x04 */
    char pad[0x58 - 8];
    ListNode node58;           /* 0x58 */
    char pad2[0x74 - 0x59];
    Destroyable *extra;        /* 0x74 */
    ListNode node78;           /* 0x78 */
    ~MapObject();
};

MapObject::~MapObject()
{
    *(void **)this = &DAT_0055c4ec;
    if (type == 0x1b && extra != 0) {
        delete extra;
        extra = 0;
    }
    __try {
        node78.~ListNode();
    } __finally {
        node58.~ListNode();
    }
}
