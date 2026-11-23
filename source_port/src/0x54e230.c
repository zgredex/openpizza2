// _memmove: ported from Pizza Connection 2 at 0x54e230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e230
#include "pc2_port.h"

uint32_t * __cdecl _memmove(uint32_t *arg1,uint32_t *arg2,uint32_t arg3)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  uint32_t *uptr4;
  
  if ((arg2 < arg1) && (arg1 < (uint32_t *)(arg3 + (intptr_t)arg2))) {
    uptr3 = (uint32_t *)((arg3 - 4) + (intptr_t)arg2);
    uptr4 = (uint32_t *)((arg3 - 4) + (intptr_t)arg1);
    if (((uint32_t)uptr4 & 3) == 0) {
      uvalue1 = arg3 >> 2;
      uvalue2 = arg3 & 3;
      if (7 < uvalue1) {
        for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
          *uptr4 = *uptr3;
          uptr3 = uptr3 + -1;
          uptr4 = uptr4 + -1;
        }
        switch(uvalue2) {
        case 0:
          return arg1;
        case 2:
          goto switchD_0054e3e7_caseD_2;
        case 3:
          goto switchD_0054e3e7_caseD_3;
        }
        goto switchD_0054e3e7_caseD_1;
      }
    }
    else {
      switch(arg3) {
      case 0:
        goto switchD_0054e3e7_caseD_0;
      case 1:
        goto switchD_0054e3e7_caseD_1;
      case 2:
        goto switchD_0054e3e7_caseD_2;
      case 3:
        goto switchD_0054e3e7_caseD_3;
      default:
        uvalue1 = arg3 - ((uint32_t)uptr4 & 3);
        switch((uint32_t)uptr4 & 3) {
        case 1:
          uvalue2 = uvalue1 & 3;
          *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
          uptr3 = (uint32_t *)((intptr_t)uptr3 + -1);
          uvalue1 = uvalue1 >> 2;
          uptr4 = (uint32_t *)((intptr_t)uptr4 - 1);
          if (7 < uvalue1) {
            for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
              *uptr4 = *uptr3;
              uptr3 = uptr3 + -1;
              uptr4 = uptr4 + -1;
            }
            switch(uvalue2) {
            case 0:
              return arg1;
            case 2:
              goto switchD_0054e3e7_caseD_2;
            case 3:
              goto switchD_0054e3e7_caseD_3;
            }
            goto switchD_0054e3e7_caseD_1;
          }
          break;
        case 2:
          uvalue2 = uvalue1 & 3;
          *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
          uvalue1 = uvalue1 >> 2;
          *(uint8_t *)((intptr_t)uptr4 + 2) = *(uint8_t *)((intptr_t)uptr3 + 2);
          uptr3 = (uint32_t *)((intptr_t)uptr3 + -2);
          uptr4 = (uint32_t *)((intptr_t)uptr4 - 2);
          if (7 < uvalue1) {
            for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
              *uptr4 = *uptr3;
              uptr3 = uptr3 + -1;
              uptr4 = uptr4 + -1;
            }
            switch(uvalue2) {
            case 0:
              return arg1;
            case 2:
              goto switchD_0054e3e7_caseD_2;
            case 3:
              goto switchD_0054e3e7_caseD_3;
            }
            goto switchD_0054e3e7_caseD_1;
          }
          break;
        case 3:
          uvalue2 = uvalue1 & 3;
          *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
          *(uint8_t *)((intptr_t)uptr4 + 2) = *(uint8_t *)((intptr_t)uptr3 + 2);
          uvalue1 = uvalue1 >> 2;
          *(uint8_t *)((intptr_t)uptr4 + 1) = *(uint8_t *)((intptr_t)uptr3 + 1);
          uptr3 = (uint32_t *)((intptr_t)uptr3 + -3);
          uptr4 = (uint32_t *)((intptr_t)uptr4 - 3);
          if (7 < uvalue1) {
            for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
              *uptr4 = *uptr3;
              uptr3 = uptr3 + -1;
              uptr4 = uptr4 + -1;
            }
            switch(uvalue2) {
            case 0:
              return arg1;
            case 2:
              goto switchD_0054e3e7_caseD_2;
            case 3:
              goto switchD_0054e3e7_caseD_3;
            }
            goto switchD_0054e3e7_caseD_1;
          }
        }
      }
    }
    switch(uvalue1) {
    case 7:
      uptr4[7 - uvalue1] = uptr3[7 - uvalue1];
    case 6:
      uptr4[6 - uvalue1] = uptr3[6 - uvalue1];
    case 5:
      uptr4[5 - uvalue1] = uptr3[5 - uvalue1];
    case 4:
      uptr4[4 - uvalue1] = uptr3[4 - uvalue1];
    case 3:
      uptr4[3 - uvalue1] = uptr3[3 - uvalue1];
    case 2:
      uptr4[2 - uvalue1] = uptr3[2 - uvalue1];
    case 1:
      uptr4[1 - uvalue1] = uptr3[1 - uvalue1];
      uptr3 = uptr3 + -uvalue1;
      uptr4 = uptr4 + -uvalue1;
    }
    switch(uvalue2) {
    case 1:
switchD_0054e3e7_caseD_1:
      *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
      return arg1;
    case 2:
switchD_0054e3e7_caseD_2:
      *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
      *(uint8_t *)((intptr_t)uptr4 + 2) = *(uint8_t *)((intptr_t)uptr3 + 2);
      return arg1;
    case 3:
switchD_0054e3e7_caseD_3:
      *(uint8_t *)((intptr_t)uptr4 + 3) = *(uint8_t *)((intptr_t)uptr3 + 3);
      *(uint8_t *)((intptr_t)uptr4 + 2) = *(uint8_t *)((intptr_t)uptr3 + 2);
      *(uint8_t *)((intptr_t)uptr4 + 1) = *(uint8_t *)((intptr_t)uptr3 + 1);
      return arg1;
    }
switchD_0054e3e7_caseD_0:
    return arg1;
  }
  uptr3 = arg1;
  if (((uint32_t)arg1 & 3) == 0) {
    uvalue1 = arg3 >> 2;
    uvalue2 = arg3 & 3;
    if (7 < uvalue1) {
      for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
        *uptr3 = *arg2;
        arg2 = arg2 + 1;
        uptr3 = uptr3 + 1;
      }
      switch(uvalue2) {
      case 0:
        return arg1;
      case 2:
        goto switchD_0054e265_caseD_2;
      case 3:
        goto switchD_0054e265_caseD_3;
      }
      goto switchD_0054e265_caseD_1;
    }
  }
  else {
    switch(arg3) {
    case 0:
      goto switchD_0054e265_caseD_0;
    case 1:
      goto switchD_0054e265_caseD_1;
    case 2:
      goto switchD_0054e265_caseD_2;
    case 3:
      goto switchD_0054e265_caseD_3;
    default:
      uvalue1 = (arg3 - 4) + ((uint32_t)arg1 & 3);
      switch((uint32_t)arg1 & 3) {
      case 1:
        uvalue2 = uvalue1 & 3;
        *(uint8_t *)arg1 = *(uint8_t *)arg2;
        *(uint8_t *)((intptr_t)arg1 + 1) = *(uint8_t *)((intptr_t)arg2 + 1);
        uvalue1 = uvalue1 >> 2;
        *(uint8_t *)((intptr_t)arg1 + 2) = *(uint8_t *)((intptr_t)arg2 + 2);
        arg2 = (uint32_t *)((intptr_t)arg2 + 3);
        uptr3 = (uint32_t *)((intptr_t)arg1 + 3);
        if (7 < uvalue1) {
          for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
            *uptr3 = *arg2;
            arg2 = arg2 + 1;
            uptr3 = uptr3 + 1;
          }
          switch(uvalue2) {
          case 0:
            return arg1;
          case 2:
            goto switchD_0054e265_caseD_2;
          case 3:
            goto switchD_0054e265_caseD_3;
          }
          goto switchD_0054e265_caseD_1;
        }
        break;
      case 2:
        uvalue2 = uvalue1 & 3;
        *(uint8_t *)arg1 = *(uint8_t *)arg2;
        uvalue1 = uvalue1 >> 2;
        *(uint8_t *)((intptr_t)arg1 + 1) = *(uint8_t *)((intptr_t)arg2 + 1);
        arg2 = (uint32_t *)((intptr_t)arg2 + 2);
        uptr3 = (uint32_t *)((intptr_t)arg1 + 2);
        if (7 < uvalue1) {
          for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
            *uptr3 = *arg2;
            arg2 = arg2 + 1;
            uptr3 = uptr3 + 1;
          }
          switch(uvalue2) {
          case 0:
            return arg1;
          case 2:
            goto switchD_0054e265_caseD_2;
          case 3:
            goto switchD_0054e265_caseD_3;
          }
          goto switchD_0054e265_caseD_1;
        }
        break;
      case 3:
        uvalue2 = uvalue1 & 3;
        *(uint8_t *)arg1 = *(uint8_t *)arg2;
        arg2 = (uint32_t *)((intptr_t)arg2 + 1);
        uvalue1 = uvalue1 >> 2;
        uptr3 = (uint32_t *)((intptr_t)arg1 + 1);
        if (7 < uvalue1) {
          for (; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
            *uptr3 = *arg2;
            arg2 = arg2 + 1;
            uptr3 = uptr3 + 1;
          }
          switch(uvalue2) {
          case 0:
            return arg1;
          case 2:
            goto switchD_0054e265_caseD_2;
          case 3:
            goto switchD_0054e265_caseD_3;
          }
          goto switchD_0054e265_caseD_1;
        }
      }
    }
  }
  switch(uvalue1) {
  case 7:
    uptr3[uvalue1 - 7] = arg2[uvalue1 - 7];
  case 6:
    uptr3[uvalue1 - 6] = arg2[uvalue1 - 6];
  case 5:
    uptr3[uvalue1 - 5] = arg2[uvalue1 - 5];
  case 4:
    uptr3[uvalue1 - 4] = arg2[uvalue1 - 4];
  case 3:
    uptr3[uvalue1 - 3] = arg2[uvalue1 - 3];
  case 2:
    uptr3[uvalue1 - 2] = arg2[uvalue1 - 2];
  case 1:
    uptr3[uvalue1 - 1] = arg2[uvalue1 - 1];
    arg2 = arg2 + uvalue1;
    uptr3 = uptr3 + uvalue1;
  }
  switch(uvalue2) {
  case 1:
switchD_0054e265_caseD_1:
    *(uint8_t *)uptr3 = *(uint8_t *)arg2;
    return arg1;
  case 2:
switchD_0054e265_caseD_2:
    *(uint8_t *)uptr3 = *(uint8_t *)arg2;
    *(uint8_t *)((intptr_t)uptr3 + 1) = *(uint8_t *)((intptr_t)arg2 + 1);
    return arg1;
  case 3:
switchD_0054e265_caseD_3:
    *(uint8_t *)uptr3 = *(uint8_t *)arg2;
    *(uint8_t *)((intptr_t)uptr3 + 1) = *(uint8_t *)((intptr_t)arg2 + 1);
    *(uint8_t *)((intptr_t)uptr3 + 2) = *(uint8_t *)((intptr_t)arg2 + 2);
    return arg1;
  }
switchD_0054e265_caseD_0:
  return arg1;
}
