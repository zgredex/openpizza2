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

    assert(piz_container_add_briefing(&container, 7, "Welcome to London"));
    assert(piz_container_add_briefing(&container, 8, "Build your first branch"));
    assert(piz_container_set_tile_name(&container, 0, "tile-zero"));
    assert(piz_container_set_tile_name(&container, 1, "tile-one"));

    container.character_count = 1;
    container.characters[0].id = 99;
    strcpy(container.characters[0].name, "Ada");
    container.characters[0].skill = 70;
    container.characters[0].motivation = 80;

    container.mapobject_count = 1;
    container.mapobjects[0].id = 500;
    container.mapobjects[0].type = 0x1c;
    container.mapobjects[0].owner_slot = 0;
    container.mapobjects[0].tile_index = 13694;
    container.mapobjects[0].state = 2;

    container.person_count = 1;
    container.persons[0].id = 1;
    container.persons[0].profession = 0;
    container.persons[0].branch_id = 13694;
    container.persons[0].skill = 70;

    container.car_count = 1;
    container.cars[0].id = 3;
    container.cars[0].type = 1;

    container.players[0].present = 1;
    container.players[0].slot = 0;
    strcpy(container.players[0].name, "Ada");
    container.players[0].cash = 494270.0;

    container.companies[0].present = 1;
    container.companies[0].slot = 0;
    strcpy(container.companies[0].name, "Ada Pizza");
    container.companies[0].cash = 494270.0;
    container.companies[0].recipe_count = 1;
    container.companies[0].recipes[0].id = 42;
    strcpy(container.companies[0].recipes[0].name, "Margherita");
    container.companies[0].branch_count = 1;
    container.companies[0].branches[0].id = 13694;
    container.companies[0].report_count = 1;
    container.companies[0].storage_count = 1;
    container.companies[0].storage[0].id = 7;
    container.companies[0].share_x100 = 10000;

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
    uint8_t buffer[PIZ_MAX_CONTAINER_SIZE];
    size_t written = piz_container_encode(&original, buffer, sizeof(buffer));
    assert(written == piz_container_size(&original));
    assert(written > 125000);
    assert(buffer[0xE8] == PIZ_VERSION);
    assert(buffer[0xEC] == (PIZ_MAGIC & 0xff));
    assert(buffer[0x110] == (PIZ_START_MARKER & 0xff));
    assert(buffer[written - 4] == (PIZ_END_MARKER & 0xff));
    uint32_t directory[8];
    memcpy(directory, buffer + PIZ_HEADER_SIZE, sizeof(directory));
    assert(directory[7] == written);
    assert(directory[1] <= directory[2]);
    assert(directory[2] <= directory[0]);
    assert(directory[0] <= directory[6]);
    assert(directory[6] <= directory[4]);
    assert(directory[4] <= directory[3]);
    assert(directory[3] <= directory[5]);

    PizContainer restored;
    memset(&restored, 0x55, sizeof(restored));
    assert(piz_container_decode(&restored, buffer, written));
    assert(strcmp(restored.header.title, "My Save") == 0);
    assert(strcmp(restored.header.company, "Ada Pizza") == 0);
    assert(strcmp(restored.header.city, "London") == 0);
    assert(restored.header.player_count == 1);
    assert(restored.header.game_calendar[0] == 1999);
    assert(restored.briefing_count == 2);
    assert(restored.briefings[0].id == 7);
    assert(strcmp(restored.briefings[0].text, "Welcome to London") == 0);
    assert(strcmp(restored.tile_names[0], "tile-zero") == 0);
    assert(strcmp(restored.tile_names[1], "tile-one") == 0);
    assert(restored.character_count == 1);
    assert(strcmp(restored.characters[0].name, "Ada") == 0);
    assert(restored.mapobject_count == 1);
    assert(restored.mapobjects[0].tile_index == 13694);
    assert(restored.person_count == 1);
    assert(restored.persons[0].branch_id == 13694);
    assert(restored.car_count == 1);
    assert(restored.cars[0].id == 3);
    assert(restored.players[0].present == 1);
    assert(strcmp(restored.players[0].name, "Ada") == 0);
    assert(restored.players[0].cash == 494270.0);
    assert(restored.companies[0].present == 1);
    assert(strcmp(restored.companies[0].name, "Ada Pizza") == 0);
    assert(restored.companies[0].slot == 0);
    assert(restored.companies[0].cash == 494270.0);
    assert(restored.companies[0].recipe_count == 1);
    assert(restored.companies[0].recipes[0].id == 42);
    assert(strcmp(restored.companies[0].recipes[0].name, "Margherita") == 0);
    assert(restored.companies[0].branch_count == 1);
    assert(restored.companies[0].branches[0].id == 13694);
    assert(restored.companies[0].report_count == 1);
    assert(restored.companies[0].storage_count == 1);
    assert(restored.companies[0].storage[0].id == 7);
    assert(memcmp(&restored.save.settings, &original.save.settings,
                  sizeof(Settings)) == 0);
    assert(restored.save.mission.deadline == 120);
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
    uint8_t buffer[PIZ_MAX_CONTAINER_SIZE];
    size_t written = piz_container_encode(&original, buffer, sizeof(buffer));
    assert(written > 0);

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
