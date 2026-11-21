/* RegistryKey_Close: closes and clears a registry key handle (0x4032e0). */
typedef void *HKEY;

__declspec(dllimport) long __stdcall RegCloseKey(HKEY key);

void __fastcall RegistryKey_Close(HKEY *key)
{
    if (*key != 0)
        RegCloseKey(*key);
    *key = 0;
}
