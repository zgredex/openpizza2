extern "C" unsigned long (__stdcall *GetCurrentThreadId)();
extern "C" unsigned long (__stdcall *timeGetTime)();
extern "C" void __cdecl CRT_Srand(unsigned int);
extern "C" int DAT_00575094;
extern "C" int DAT_00575098;
extern "C" int DAT_0057509c;

struct SoundBase {
  int pad0;
  int threadId;
  SoundBase()
  {
    threadId = (*GetCurrentThreadId)();
    CRT_Srand((*timeGetTime)());
  }
};

struct NamedLockable {
  void Construct(const char *);
  NamedLockable(const char *name = 0) { Construct(name); }
  ~NamedLockable();
};

struct SoundSystem : SoundBase {
  char pad[0x170];
  NamedLockable lock;
  void ClampGlobalLimits();
  int ConvertVolumeSetting(int);
  SoundSystem();
};

SoundSystem::SoundSystem()
{
  unsigned int iVar3;
  unsigned int *puVar4;

  *(char *)((char *)this + 0xfc) = 0;
  *(int *)((char *)this + 0x18) = 1000;
  *(int *)((char *)this + 0x1c) = 1000;
  *(char *)((char *)this + 0xfd) = 0;
  *(int *)((char *)this + 0x108) = -1;
  *(int *)((char *)this + 0x160) = -1;
  *(int *)((char *)this + 0x164) = -1;
  *(char *)((char *)this + 0xfe) = 0;
  *(char *)((char *)this + 0xff) = 0;
  *(char *)((char *)this + 0x100) = 0;
  *(int *)((char *)this + 0x0) = 0;
  *(int *)((char *)this + 0x8) = 0;
  *(int *)((char *)this + 0xc) = 0;
  *(int *)((char *)this + 0x10) = 0;
  *(int *)((char *)this + 0xf4) = 0;
  *(int *)((char *)this + 0xf8) = 0;
  *(int *)((char *)this + 0x14) = 0;
  *(int *)((char *)this + 0x20) = 0;
  *(int *)((char *)this + 0x104) = 0;
  *(int *)((char *)this + 0x144) = 0;
  *(int *)((char *)this + 0x14c) = 0;
  *(int *)((char *)this + 0x148) = 0x3f800000;
  *(char *)((char *)this + 0x168) = 0;
  *(char *)((char *)this + 0x169) = 0;
  *(char *)((char *)this + 0x16a) = 0;
  *(char *)((char *)this + 0x140) = 0;
  *(int *)((char *)this + 0x16c) = 0;
  *(int *)((char *)this + 0x170) = 0x3f800000;
  *(int *)((char *)this + 0x150) = 0;
  *(int *)((char *)this + 0x154) = 0;
  *(int *)((char *)this + 0x158) = 0;
  *(int *)((char *)this + 0x15c) = 0;
  *(int *)((char *)this + 0x13c) = 0;
  ClampGlobalLimits();
  *(int *)((char *)this + 0x1d0) = DAT_00575094;
  *(int *)((char *)this + 0x1d4) = ConvertVolumeSetting(DAT_00575098);
  *(int *)((char *)this + 0x1d8) = ConvertVolumeSetting(DAT_0057509c);
  puVar4 = (unsigned int *)((char *)this + 0x24);
  for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (unsigned int *)((char *)this + 0x244);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (unsigned int *)((char *)this + 0x10c);
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(int *)((char *)this + 0x174) = 0;
  puVar4 = (unsigned int *)((char *)this + 0x1dc);
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 - 1) {
    *puVar4 = 1;
    puVar4 = puVar4 + 1;
  }
  return;
}
