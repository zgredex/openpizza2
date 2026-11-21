/* First attempt for 0x4d2a90 - does not match (dummy edx argument).
 * The matched candidate is a C++ member function so the adjusted this
 * pointer stays in ecx with no edx setup.
 */
extern int __fastcall IDMap_RemoveRecursive(void *this_, int unused, int key);

void __fastcall Game_RemoveLocalEntryRecursive(void *this_, int unused, int key)
{
    IDMap_RemoveRecursive((char *)this_ + 0x78, 0, key);
}
