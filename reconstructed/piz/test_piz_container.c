#include "piz_container.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool load_fails(Settings *settings) {
    (void)settings;
    return false;
}

static uint32_t random_low(uint32_t low, uint32_t high) {
    (void)high;
    return low;
}

static PizContainer make_container(void) {
    PizContainer container;
    piz_container_init(&container, "My Save", "Ada Pizza", "London");
    container.header.player_flags[0] = 1;
    container.header.game_calendar[0] = 1999;
    container.header.game_calendar[1] = 7;
    container.header.game_calendar[2] = 14;
    container.header.game_calendar[3] = 11;
    container.header.system_time[0] = 1999;
    container.header.system_time[1] = 7;
    container.header.system_time[2] = 3;
    container.header.system_time[3] = 14;
    container.header.system_time[4] = 10;
    container.header.system_time[5] = 55;
    settings_init_defaults(&container.save.settings, load_fails, random_low);
    container.save.mission.goals[0] = 0;
    container.save.mission.goals[1] = 1;
    container.save.mission.goals[2] = 2;
    container.save.mission.goal_progress[1] = 1;
    container.save.mission.deadline = 120;
    container.save.mission.completed[0] = 1;
    container.save.mission.completed[1] = 1;
    container.save.mission.completed[2] = 1;
    return container;
}

static void test_round_trip(const char *write_path) {
    PizContainer original = make_container();
    uint8_t buffer[PIZ_PREAMBLE_SIZE + 4 + 0x240 + 4];
    size_t written = piz_container_encode(&original, buffer, sizeof(buffer));
    assert(written == piz_container_size());
    assert(piz_container_size() == PIZ_PREAMBLE_SIZE + 4 + 0x23C + 4);
    assert(buffer[0xE8] == PIZ_VERSION);
    assert(buffer[0xEC] == (PIZ_MAGIC & 0xff));
    assert(buffer[0x110] == (PIZ_START_MARKER & 0xff));
    assert(buffer[written - 4] == (PIZ_END_MARKER & 0xff));

    PizContainer restored;
    memset(&restored, 0x55, sizeof(restored));
    assert(piz_container_decode(&restored, buffer, written));
    assert(strcmp(restored.header.title, "My Save") == 0);
    assert(strcmp(restored.header.company, "Ada Pizza") == 0);
    assert(strcmp(restored.header.city, "London") == 0);
    assert(restored.header.player_count == 1);
    assert(restored.header.player_flags[0] == 1);
    assert(restored.header.game_calendar[0] == 1999);
    assert(restored.header.system_time[5] == 55);
    assert(memcmp(&restored.save.settings, &original.save.settings,
                  sizeof(Settings)) == 0);
    assert(restored.save.mission.deadline == 120);
    assert(restored.save.mission.completed[0] == 1);
    assert(restored.save.mission.completed[1] == 1);
    assert(restored.save.mission.completed[2] == 1);

    if (write_path != NULL) {
        FILE *file = fopen(write_path, "wb");
        assert(file != NULL);
        assert(fwrite(buffer, 1, written, file) == written);
        fclose(file);
    }
}

static void test_rejects_damage(void) {
    PizContainer original = make_container();
    uint8_t buffer[PIZ_PREAMBLE_SIZE + 4 + 0x240 + 4];
    size_t written = piz_container_encode(&original, buffer, sizeof(buffer));
    assert(written == piz_container_size());

    PizContainer restored;
    assert(!piz_container_decode(&restored, buffer, written - 1));
    buffer[0xEC] ^= 0xff;
    assert(!piz_container_decode(&restored, buffer, written));
    buffer[0xEC] ^= 0xff;
    buffer[written - 4] = 0;
    assert(!piz_container_decode(&restored, buffer, written));
}

int main(int argc, char **argv) {
    test_round_trip(argc > 1 ? argv[1] : NULL);
    test_rejects_damage();
    puts("piz container reconstruction: OK");
    return 0;
}
