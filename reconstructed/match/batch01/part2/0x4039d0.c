extern "C" char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)

struct Lockable { void Construct(const char *); };

extern "C" void *(__stdcall *CreateEventA)(void *, int, int, const char *);
extern "C" int __cdecl CRT_BeginThread(void *, unsigned int, void *);
extern "C" char s_timer_crit[];
extern "C" char s_TimerClassHandle[];

struct TimerClass {
  void *Construct();
};

void *TimerClass::Construct()
{
  ((Lockable *)((char *)this + 0x10))->Construct(0);
  *(void **)this = (void *)0x55c308;
  strcpy((char *)this + 0x2c, s_timer_crit);
  *(int *)((char *)this + 0x4) = 0;
  *(int *)((char *)this + 0x8) = 0;
  *(int *)((char *)this + 0xc) = 0;
  *(int *)((char *)this + 0x68) = 0;
  *(void **)((char *)this + 0x6c) = (*CreateEventA)(0, 0, 0, s_TimerClassHandle);
  CRT_BeginThread((void *)0x4039c0, 0, this);
  return this;
}
