#include "win32hle.h"

/* PC2 imports that the tested win32hle revision does not answer yet. Each is
 * a stdcall shim: args are read from the guest stack and RET() pops them. */

static void p_IsIconic(void) {
    RET(0, 1);
}

static void p_GetSystemMenu(void) {
    RET(0, 2);
}

static void p_SetClassLongA(void) {
    RET(0, 3);
}

static void p_UnregisterClassA(void) {
    RET(1, 2);
}

static void p_GetSaveFileNameA(void) {
    RET(0, 1);
}

static void p_BinkGetSummary(void) {
    uint32_t out = A32(1);
    if (out) {
        for (uint32_t i = 0; i < 32; i += 4) {
            MEM32(out + i) = 0;
        }
    }
    RET(0, 2);
}


/* The native movie player replaces Movie_Play. These Bink exports stay bound
 * only so the executable's import table resolves; no path calls them. */
static void p_BinkOpen(void) { RET(0, 2); }
static void p_BinkOpenDirectSound(void) { RET(0, 1); }
static void p_BinkDoFrame(void) { RET(0, 1); }
static void p_BinkCopyToBuffer(void) { RET(0, 7); }
static void p_BinkNextFrame(void) { RET(0, 1); }
static void p_BinkWait(void) { RET(0, 1); }
static void p_BinkGoto(void) { RET(0, 3); }
static void p_BinkClose(void) { RET(0, 1); }
static void p_BinkSetSoundSystem(void) { RET(0, 2); }

static const win32hle_shim pc2_shims[] = {
    { "IsIconic", p_IsIconic },
    { "GetSystemMenu", p_GetSystemMenu },
    { "SetClassLongA", p_SetClassLongA },
    { "UnregisterClassA", p_UnregisterClassA },
    { "GetSaveFileNameA", p_GetSaveFileNameA },
    { "_BinkGetSummary@8", p_BinkGetSummary },
    { "_BinkOpen@8", p_BinkOpen },
    { "_BinkOpenDirectSound@4", p_BinkOpenDirectSound },
    { "_BinkDoFrame@4", p_BinkDoFrame },
    { "_BinkCopyToBuffer@28", p_BinkCopyToBuffer },
    { "_BinkNextFrame@4", p_BinkNextFrame },
    { "_BinkWait@4", p_BinkWait },
    { "_BinkGoto@12", p_BinkGoto },
    { "_BinkClose@4", p_BinkClose },
    { "_BinkSetSoundSystem@8", p_BinkSetSoundSystem },
    { 0, 0 }
};

int pc2_register_shims(void) {
    return win32hle_register(pc2_shims);
}
