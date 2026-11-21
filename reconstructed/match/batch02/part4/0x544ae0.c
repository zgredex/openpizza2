/* PC2 byte-match candidate: List_UnlinkNode (0x544ae0, 15 bytes).
   Build: /O2 /TP; entry _List_UnlinkNode. */
struct List {
    void RemoveNodeLocked(void *node);
};

extern "C" void __cdecl List_UnlinkNode(List *list, void *node)
{
    list->RemoveNodeLocked(node);
}
