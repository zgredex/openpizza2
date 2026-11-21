/* Object_EnsureFirstChild: initializes the first child slot on demand (0x4f5ab0). */
void __stdcall Object_EnsureFirstChild(int object, int unused, int *result)
{
    int *field = *(int **)(object + 8);

    if (field[0xe] == 0) {
        *(int *)(*(int *)(object + 8) + 0x38) = 1;
        *result = **(int **)(object + 8);
    }
}
