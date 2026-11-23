// Profiler_DumpReport: ported from Pizza Connection 2 at 0x4035d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4035d0
#include "pc2_port.h"

void Profiler_DumpReport(void)

{
  char cVar1;
  int *ptr2;
  FILE *pFVar3;
  int value4;
  uint32_t uvalue5;
  int value6;
  uint32_t uvalue7;
  char *cptr8;
  uint32_t *uptr9;
  char *cptr10;
  char *cptr11;
  uint8_t local_res0;
  char cStack00000100;
  uint32_t uStack00000101;
  
  __chkstk(local_res0);
  if (DAT_0057b558 != 0) {
    cStack00000100 = DAT_00579aec;
    uptr9 = &uStack00000101;
    for (value4 = 0x7ff; value4 != 0; value4 = value4 + -1) {
      *uptr9 = 0;
      uptr9 = uptr9 + 1;
    }
    *(uint16_t *)uptr9 = 0;
    *(uint8_t *)((intptr_t)uptr9 + 2) = 0;
    value4 = 0;
    ptr2 = &DAT_00579b48;
    do {
      if (*ptr2 != 0) break;
      ptr2 = ptr2 + 1;
      value4 = value4 + 1;
    } while ((intptr_t)ptr2 < 0x579cd8);
    if (value4 != 100) {
      value4 = 0;
      do {
        if (*(int *)((intptr_t)&DAT_00579b48 + value4) != 0) {
          String_Format(&local_res0,(uint8_t *)s____s___d_calls____ld_ms___ld_ave_005637c4,
                        *(uint32_t *)((intptr_t)&DAT_00579ffc + value4));
          uvalue5 = 0xffffffff;
          cptr8 = (char *)register0x00000010;
          do {
            cptr11 = cptr8;
            if (uvalue5 == 0) break;
            uvalue5 = uvalue5 - 1;
            cptr11 = cptr8 + 1;
            cVar1 = *cptr8;
            cptr8 = cptr11;
          } while (cVar1 != '\0');
          uvalue5 = ~uvalue5;
          value6 = -1;
          cptr8 = &cStack00000100;
          do {
            cptr10 = cptr8;
            if (value6 == 0) break;
            value6 = value6 + -1;
            cptr10 = cptr8 + 1;
            cVar1 = *cptr8;
            cptr8 = cptr10;
          } while (cVar1 != '\0');
          cptr8 = cptr11 + -uvalue5;
          cptr11 = cptr10 + -1;
          for (uvalue7 = uvalue5 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
            *(uint32_t *)cptr11 = *(uint32_t *)cptr8;
            cptr8 = cptr8 + 4;
            cptr11 = cptr11 + 4;
          }
          for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *cptr11 = *cptr8;
            cptr8 = cptr8 + 1;
            cptr11 = cptr11 + 1;
          }
          String_Format(&local_res0,(uint8_t *)s___longest_call__d_ms___d_call__0056379c,
                        *(uint32_t *)((intptr_t)&DAT_0057b31c + value4));
          uvalue5 = 0xffffffff;
          cptr8 = (char *)register0x00000010;
          do {
            cptr11 = cptr8;
            if (uvalue5 == 0) break;
            uvalue5 = uvalue5 - 1;
            cptr11 = cptr8 + 1;
            cVar1 = *cptr8;
            cptr8 = cptr11;
          } while (cVar1 != '\0');
          uvalue5 = ~uvalue5;
          value6 = -1;
          cptr8 = &cStack00000100;
          do {
            cptr10 = cptr8;
            if (value6 == 0) break;
            value6 = value6 + -1;
            cptr10 = cptr8 + 1;
            cVar1 = *cptr8;
            cptr8 = cptr10;
          } while (cVar1 != '\0');
          cptr8 = cptr11 + -uvalue5;
          cptr11 = cptr10 + -1;
          for (uvalue7 = uvalue5 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
            *(uint32_t *)cptr11 = *(uint32_t *)cptr8;
            cptr8 = cptr8 + 4;
            cptr11 = cptr11 + 4;
          }
          for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *cptr11 = *cptr8;
            cptr8 = cptr8 + 1;
            cptr11 = cptr11 + 1;
          }
        }
        value4 = value4 + 4;
      } while (value4 < 400);
      MessageBoxA((HWND)0x0,&cStack00000100,s_Profile_Stat_s_0056378c,0x1000);
      pFVar3 = (FILE *)CRT_Fopen(s_profile_txt_0056377c,&DAT_00563788);
      if (pFVar3 != (FILE *)0x0) {
        CRT_Fputs(&cStack00000100,(int *)pFVar3);
        CRT_Fclose(pFVar3);
      }
    }
  }
  return;
}
