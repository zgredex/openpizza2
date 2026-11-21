/* Random_Range: returns a pseudo-random value in an inclusive range
   (0x546fd0). */
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);
extern "C" void __cdecl CRT_Srand(unsigned seed);
extern "C" int __cdecl _rand(void);

struct Random {
    unsigned thread;

    int Range(int low, int high);
};

int Random::Range(int low, int high)
{
    int value;

    if (thread != GetCurrentThreadId()) {
        CRT_Srand(timeGetTime());
        thread = GetCurrentThreadId();
    }
    value = _rand() * ((high - low) + 1) / 0x8000 + low;
    if (value < low) {
        return low;
    }
    if (value > high) {
        value = high;
    }
    return value;
}
