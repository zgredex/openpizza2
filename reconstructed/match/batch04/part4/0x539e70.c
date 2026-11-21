/* PC2 byte-match candidate: Renderer_CopyStateToChildren (0x539e70,
   29 bytes).  Build: /O2 /TP.  Walks the child list and forwards state. */
struct RendererNode {
    struct Renderer *child;
    RendererNode *next;
};

struct Renderer {
    unsigned char pad_000[0x50];
    RendererNode *children;
    void CopyState(void *parent);
    void CopyStateToChildren();
};

void Renderer::CopyStateToChildren()
{
    for (RendererNode *node = children; node != 0; node = node->next)
        node->child->CopyState(this);
}
