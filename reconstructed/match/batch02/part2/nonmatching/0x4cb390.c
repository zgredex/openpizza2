/* First attempt for 0x4cb390 - does not match.
 * The dummy second __fastcall argument is materialized in edx before the
 * this-pointer load; the matched candidate calls a C++ member instead.
 */
extern void __fastcall List_Construct(void *this_, int unused, unsigned flags);
extern char DAT_0057de38;

void MissionMap_InitList(void)
{
    List_Construct(&DAT_0057de38, 0, 0);
}
