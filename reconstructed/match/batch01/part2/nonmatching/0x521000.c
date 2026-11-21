void *operator new(unsigned int);
extern "C" void *DAT_0057c5c8;

struct Array {
  void Construct(int);
  Array(int v) { Construct(v); }
};

struct Object {
  void ClearFieldsA();
};

struct UI_Child {
  char pad[0x80];
  UI_Child(int, int, int, int);
  void SetAbsolutePosition(unsigned int, int);
  virtual ~UI_Child();
};

struct Sprite {
  void CreateRaw(int, int, int, unsigned int, int);
  Sprite(int a, int b, int c, unsigned int d, int e) { CreateRaw(a, b, c, d, e); }
  void SetColorKey(unsigned int);
  void FillTransparentColor(int);
  void RealizeLazy();
};

struct Renderer {
  Sprite *CreateChild();
  unsigned int ColorKey(int);
  void Configure(int, unsigned short, unsigned short, int);
};

struct UI_ImageChild : UI_Child {
  Array arr;
  UI_ImageChild(int param_1, int param_2, int param_3, unsigned int param_4,
                int param_5, unsigned int param_6, int param_7);
  virtual ~UI_ImageChild();
};

UI_ImageChild::UI_ImageChild(int param_1, int param_2, int param_3, unsigned int param_4,
                             int param_5, unsigned int param_6, int param_7)
  : UI_Child(param_3, param_2, param_4, param_7), arr(0)
{
  Renderer *this_00;
  Sprite *puVar1;
  Sprite *pvVar2;
  unsigned int uVar3;
  unsigned int uVar4;

  if ((int)param_6 < 8) {
    param_6 = (unsigned int)((int)param_6 >> 3);
  }
  uVar4 = param_6 & 0x38;
  if (uVar4 == 0) {
    uVar4 = 0x10;
  }
  ((Object *)this)->ClearFieldsA();
  *(int *)((char *)this + 0x7c) = 0;
  *(int *)((char *)this + 0x80) = 0;
  *(int *)((char *)this + 0x98) = 0;
  *(int *)((char *)this + 0x40) = 7;
  SetAbsolutePosition(param_4, param_5);
  if ((int)param_4 < 1) {
    param_4 = 1;
  }
  if (param_5 < 1) {
    param_5 = 1;
  }
  puVar1 = ((Renderer *)DAT_0057c5c8)->CreateChild();
  *(Sprite **)((char *)this + 0x68) = puVar1;
  pvVar2 = new Sprite((int)param_4, param_5, 0, uVar4, 0);
  *(Sprite **)((char *)this + 0x60) = pvVar2;
  if (uVar4 == 0x10) {
    uVar3 = ((Renderer *)*(void **)((char *)this + 0x68))->ColorKey(0xff00);
    puVar1 = *(Sprite **)((char *)this + 0x60);
  }
  else {
    uVar3 = 0;
  }
  puVar1->SetColorKey(uVar3);
  (*(Sprite **)((char *)this + 0x60))->FillTransparentColor(-1);
  pvVar2 = *(Sprite **)((char *)this + 0x60);
  this_00 = (Renderer *)*(void **)((char *)this + 0x68);
  if (*(char *)((char *)pvVar2 + 0x39) == 0) {
    pvVar2->RealizeLazy();
  }
  this_00->Configure(*(int *)((char *)pvVar2 + 0x2c),
                     (unsigned short)((int)*(short *)((char *)pvVar2 + 6) >> 1),
                     *(unsigned short *)((char *)pvVar2 + 8),
                     (int)*(short *)((char *)pvVar2 + 6));
  return;
}
