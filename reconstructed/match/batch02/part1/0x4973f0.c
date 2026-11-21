/* Supplier_GetValuePlusOne: returns supplier table value plus one, or zero for
   no supplier (0x4973f0). */
extern int DAT_0057c718[];

int __cdecl Supplier_GetValuePlusOne(int supplier)
{
    if (supplier == 0)
        return 0;
    return DAT_0057c718[supplier] + 1;
}
