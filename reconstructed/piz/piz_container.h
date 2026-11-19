#ifndef PC2_RECONSTRUCTED_PIZ_CONTAINER_H
#define PC2_RECONSTRUCTED_PIZ_CONTAINER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../save/save_state.h"

#define PIZ_HEADER_SIZE 0xF0u
#define PIZ_DIRECTORY_SIZE 0x20u
#define PIZ_PREAMBLE_SIZE (PIZ_HEADER_SIZE + PIZ_DIRECTORY_SIZE)
#define PIZ_VERSION 0x11u
#define PIZ_MAGIC 0x13738317u
#define PIZ_START_MARKER 0x2Eu
#define PIZ_END_MARKER 0x2Au

#pragma pack(push, 1)
typedef struct PizHeader {
    char title[0x40];            /* 0x00 */
    char company[0x40];          /* 0x40 */
    char city[0x40];             /* 0x80 */
    uint8_t player_count;        /* 0xC0 */
    uint8_t player_flags[7];     /* 0xC1 */
    uint32_t game_calendar[4];   /* 0xC8 */
    uint16_t system_time[8];     /* 0xD8 */
    uint32_t version;            /* 0xE8 */
    uint32_t magic;              /* 0xEC */
} PizHeader;

typedef struct PizContainer {
    PizHeader header;
    SaveState save;
} PizContainer;
#pragma pack(pop)

/*
 * Minimal .piz container reconstructed from tools/piz_payload.py and
 * save_schema.json: 0xF0 header, 0x20 directory, start marker, payload and
 * end marker. The payload is the reconstructed SaveState blob.
 */
void piz_container_init(PizContainer *container, const char *title,
                        const char *company, const char *city);
size_t piz_container_size(void);
size_t piz_container_encode(const PizContainer *container, uint8_t *buffer,
                            size_t capacity);
bool piz_container_decode(PizContainer *container, const uint8_t *buffer,
                          size_t length);

#endif
