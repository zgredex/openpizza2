/* Renderer_CreateChild (0x539ea0). */

struct Renderer;

struct RendererChild {
    char pad[0x9c];
    RendererChild(Renderer *parent);
};

struct Renderer {
    RendererChild *CreateChild();
};

RendererChild *Renderer::CreateChild()
{
    return new RendererChild(this);
}
