/* Game_ClearObjectReferences: clears the two globals that may still point at
   an object (0x49f190).  Build: /O2. */
void Game_ClearObjectReferences(int object)
{
    if (object == *(int *)0x57cda0)
        *(int *)0x57cda0 = 0;
    if (*(int *)(*(int *)0x57c670 + 0x98) == object)
        *(int *)(*(int *)0x57c670 + 0x98) = 0;
}
