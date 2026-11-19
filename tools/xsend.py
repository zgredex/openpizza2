#!/usr/bin/env python3
"""Send synthetic X11 key events to one window through XTEST.

This is an acceptance helper for the real GTK/winit window: it does not call
the application's key handler directly.  Requires libX11 and libXtst.
"""

from __future__ import annotations

import ctypes
import sys
import time

X11 = ctypes.CDLL("libX11.so.6")
XTST = ctypes.CDLL("libXtst.so.6")
X11.XOpenDisplay.restype = ctypes.c_void_p
X11.XStringToKeysym.restype = ctypes.c_ulong
X11.XKeysymToKeycode.argtypes = [ctypes.c_void_p, ctypes.c_ulong]
X11.XKeysymToKeycode.restype = ctypes.c_ubyte
X11.XSetInputFocus.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.c_int, ctypes.c_ulong]
XTST.XTestFakeKeyEvent.argtypes = [ctypes.c_void_p, ctypes.c_uint, ctypes.c_int, ctypes.c_ulong]
X11.XFlush.argtypes = [ctypes.c_void_p]


def main() -> int:
    if len(sys.argv) < 3:
        print("usage: xsend.py <window-id> <key> [key ...]", file=sys.stderr)
        return 2
    display = X11.XOpenDisplay(None)
    if not display:
        print("cannot open X display", file=sys.stderr)
        return 2
    window = int(sys.argv[1], 0)
    X11.XSetInputFocus(display, window, 1, 0)
    time.sleep(0.1)
    for name in sys.argv[2:]:
        keysym = X11.XStringToKeysym(name.encode())
        if not keysym:
            print(f"unknown key {name!r}", file=sys.stderr)
            return 2
        keycode = X11.XKeysymToKeycode(display, keysym)
        if not keycode:
            print(f"no keycode for {name!r}", file=sys.stderr)
            return 2
        XTST.XTestFakeKeyEvent(display, keycode, 1, 0)
        X11.XFlush(display)
        time.sleep(0.04)
        XTST.XTestFakeKeyEvent(display, keycode, 0, 0)
        X11.XFlush(display)
        time.sleep(0.12)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
