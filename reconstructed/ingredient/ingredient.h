#ifndef PC2_RECONSTRUCTED_INGREDIENT_H
#define PC2_RECONSTRUCTED_INGREDIENT_H

#include <stddef.h>
#include <stdint.h>

/*
 * Prefix of the 0xD8-byte ingredient object allocated by Ingredient_Construct.
 * Game_SetBuildingDesc writes the display name at +0x88 and the descriptor
 * fields at +0xA8..+0xCD. Only those observed fields are named here.
 */
#pragma pack(push, 1)
typedef struct Ingredient {
    uint8_t reserved_00[0x88];
    char name[0x20];          /* 0x088 */
    uint8_t kind;             /* 0x0A8 */
    uint8_t reserved_a9[3];
    uint32_t price_class;     /* 0x0AC */
    uint32_t field_b0;        /* 0x0B0 */
    uint32_t field_b4;        /* 0x0B4 */
    uint32_t field_b8;        /* 0x0B8 */
    uint32_t field_bc;        /* 0x0BC */
    uint32_t field_c0;        /* 0x0C0 */
    uint32_t field_c4;        /* 0x0C4 */
    uint8_t flag_c8;          /* 0x0C8 */
    uint8_t flag_c9;          /* 0x0C9 */
    uint8_t flag_ca;          /* 0x0CA */
    uint8_t flag_cb;          /* 0x0CB */
    uint8_t flag_cc;          /* 0x0CC */
    uint8_t flag_cd;          /* 0x0CD */
    uint8_t reserved_ce[2];
    uint8_t reserved_d0[8];
} Ingredient;
#pragma pack(pop)

/*
 * Reconstructed from Game_SetBuildingDesc (0x4E4860). The original copies a
 * null-terminated name into +0x88 and stores the 13 descriptor values at the
 * offsets above. Arguments are grouped by their observed field order.
 */
void game_set_building_desc(Ingredient *ingredient, const char *name,
                            uint8_t kind, uint32_t field_a, uint32_t field_b,
                            uint32_t field_c, uint32_t field_d, uint32_t field_e,
                            uint32_t field_f, uint8_t flag_g, uint8_t flag_h,
                            uint8_t flag_i, uint8_t flag_j, uint8_t flag_k,
                            uint8_t flag_l);

#endif
