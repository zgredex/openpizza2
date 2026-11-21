/* Object_HideLinkedElements: clears the active flag of every linked record
   (0x4f13b0). */
struct Record {
    void ClearActive48(int value);
};

struct Object {
    char pad[0xbc];
    int *head;
    void HideLinkedElements();
};

void Object::HideLinkedElements()
{
    int *link = head;
    while (link != 0) {
        ((Record *)link[0x16])->ClearActive48(link[0]);
        link = (int *)link[0x1c];
    }
}
