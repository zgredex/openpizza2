extern "C" void Mem_Free(void *);

struct SpriteBase {
  virtual ~SpriteBase();
};

struct Palette {
  void Free();
};

struct SpriteFile : SpriteBase {
  virtual ~SpriteFile();
};

SpriteFile::~SpriteFile()
{
  void *puVar1;

  if (*(int *)((char *)this + 0x88) != 0) {
    Mem_Free(*(void **)((char *)this + 0x30));
    *(int *)((char *)this + 0x30) = 0;
  }
  if (*(void **)((char *)this + 0x50) != 0) {
    Mem_Free(*(void **)((char *)this + 0x50));
  }
  if (*(void **)((char *)this + 0x4c) != 0) {
    Mem_Free(*(void **)((char *)this + 0x4c));
  }
  {
    void **pp;
    if ((*(char *)((char *)this + 0x34) != 0) &&
        ((pp = (void **)*(int *)((char *)this + 0x80)), (*pp != 0)) &&
        (*(char *)((char *)this + 0x35) != 0)) {
      Mem_Free(*pp);
    }
  }
  if (*(void **)((char *)this + 0x38) != 0) {
    Mem_Free(*(void **)((char *)this + 0x38));
  }
  if (*(void **)((char *)this + 0x80) != 0) {
    Mem_Free(*(void **)((char *)this + 0x80));
  }
  if (*(void **)((char *)this + 0x20) != 0) {
    Mem_Free(*(void **)((char *)this + 0x20));
  }
  puVar1 = *(void **)((char *)this + 0x78);
  if (puVar1 != 0) {
    ((Palette *)puVar1)->Free();
    Mem_Free(puVar1);
  }
  return;
}
