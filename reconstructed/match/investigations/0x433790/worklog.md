# Window_BuildStatisticsBranchBalancePage (0x433790)

Second-largest function in the executable: 29,960 bytes, ending at
`0x43ac97`. It is a generated UI page builder with 1,151 direct calls to ten
UI methods:

```text
UI_CreateWindow                0x523bb0
UI_FindWindowByID              0x528040
UI_CreateBitmapGadget          0x531c60
UI_AddText                     0x52f850
UI_AddImage                    0x52f5b0
UI_AddSprite                   0x531850
UI_CreateSlider                0x52fc00
Window_GadgetNotify_Text_SetTextColor
Window_GadgetNotify_Text_SetLayout
Window_GadgetNotify_Slider_SetGradientColors
```

The draft in `nonmatching/window_build.cpp` is a mechanical transcription of
the Ghidra call sequence, with the UI/Text/Slider methods declared as
`__thiscall` members and the four gradient colors as a local `int[4]`. It
compiles with `/O2 /TP`.

## Near miss

This section records the earlier hand-written draft. The shared generator
now verifies all 29,960 bytes under `/O2 /TP` and links the function into a
byte-identical scratch PE. See the [cohort verification](../ui-builder-generation.md#verify-the-full-cohort).

```text
original:  83 ec 10 8b 0d e0 c5 57 00 56 57 68 ... 33 ff ...
candidate: 83 ec 10 8b 0d e0 c5 57 00 55 56 68 ... 33 ed ...
first diff: offset 9, original 0x57 (push edi) vs candidate 0x55 (push ebp)
difference_count: 16,893 of 29,960
```

The call sequence, arguments and stack frame size agree. The remaining
difference is global register allocation: the original keeps zero in `edi`
and saves `edi` at entry, reusing it later for slider constants and saving
`ebx`/`ebp` locally. VC6 12.00.8447 chooses `ebp` for the zero value and saves
`ebp` at entry for this source.

Tried without changing the call sequence:

```text
/O1, /Ox, /O2 /G3..G6, /O2 /Oy-, /O2 /GX
typed vs untyped UI pointers
int[4] vs struct vs separate local declarations
all six local declaration orders
```

All variants select `ebp` for zero and keep the offset-9 first difference.

This is not counted as a strict match. The next step is a source-shape search
or a permuter, or compiling the original translation unit so the allocator
sees the same surrounding context.
