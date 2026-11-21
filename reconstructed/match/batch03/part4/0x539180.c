/* PC2 byte-match candidate: Surface_IsReady (0x539180, 23 bytes).
   Build: /O2.  Queries the surface's virtual "is lost" method and reports
   readiness as the logical negation of a non-zero result. */
int __stdcall Surface_IsReady(int *surface)
{
    return (*(int (__stdcall **)(int *, int))(*surface + 0x80))(surface, 0) == 0;
}
