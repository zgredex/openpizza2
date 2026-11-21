/* First attempt for 0x4d42e0 - does not match.
 * An int return makes MSVC load the field into edx and zero eax before
 * "setg al" (11 bytes).  The shipped 9-byte form returns char through a
 * named char local, which lets the field load and the setcc share eax.
 */
int __fastcall State_HasPositive(void *this_)
{
    return *(int *)((char *)this_ + 0x20) > 0;
}
