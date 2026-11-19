#include "map_render.h"

#include "../assets/assets.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file(const char *path, size_t *length) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return NULL;
    }
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return NULL;
    }
    long size = ftell(file);
    if (size <= 0 || fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return NULL;
    }
    uint8_t *data = malloc((size_t)size);
    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    if (fread(data, 1, (size_t)size, file) != (size_t)size) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *length = (size_t)size;
    return data;
}

static uint16_t read_u16(const uint8_t *data, size_t offset) {
    return (uint16_t)data[offset] | ((uint16_t)data[offset + 1] << 8);
}

static void test_london_map_header(void) {
    size_t length = 0;
    uint8_t *data = load_file("../game/Isokarten/Lon.iso", &length);
    assert(data != NULL);
    IsoTile storage[ISO_MAX_TILES];
    IsoMap map;
    assert(iso_map_parse(data, length, &map, storage, ISO_MAX_TILES));
    assert(map.header.version == 0x10);
    assert(map.header.name_mode == 0);
    assert(map.header.view_w == 64);
    assert(map.header.view_h == 32);
    assert(map.header.grid_w == 164);
    assert(map.header.grid_h == 164);
    assert(map.header.origin_x == 2784);
    assert(map.header.origin_y == 1344);
    assert(strcmp(map.header.background, "london_a.tga") == 0);
    assert(map.tile_count == 1744);
    const IsoTile *tile = iso_map_tile_at(&map, 82, 83);
    assert(tile != NULL);
    assert(tile->index == 13694);
    int32_t world_x = 0;
    int32_t world_y = 0;
    iso_tile_world(&map, tile, &world_x, &world_y);
    assert(world_x == 5216);
    assert(world_y == 2640);
    free(data);
}

static void test_branch_map_header(void) {
    size_t length = 0;
    uint8_t *data = load_file("../game/Isokarten/Iso_Filiale_einf_klein.iso", &length);
    assert(data != NULL);
    IsoTile storage[ISO_MAX_TILES];
    IsoMap map;
    assert(iso_map_parse(data, length, &map, storage, ISO_MAX_TILES));
    assert(map.header.view_w == 16);
    assert(map.header.view_h == 8);
    assert(map.header.grid_w == 260);
    assert(map.header.grid_h == 260);
    assert(map.header.list1_count == 0);
    assert(map.header.list2_count == 0);
    assert(strcmp(map.header.background, "filiale_klein_einf_back.tga") == 0);
    assert(map.tile_count == 40);
    bool kitchen = false;
    for (size_t index = 0; index < map.tile_count; index++) {
        if (strcmp(map.tiles[index].layer2, "KUECHE_00.SPR") == 0) {
            kitchen = true;
        }
    }
    assert(kitchen);
    free(data);
}

static void test_city_render(void) {
    size_t map_length = 0;
    uint8_t *map_data = load_file("../game/Isokarten/Lon.iso", &map_length);
    assert(map_data != NULL);
    IsoTile storage[ISO_MAX_TILES];
    IsoMap map;
    assert(iso_map_parse(map_data, map_length, &map, storage, ISO_MAX_TILES));

    size_t tga_length = 0;
    uint8_t *tga_data = load_file("../extracted/backgrounds/lon.tga", &tga_length);
    assert(tga_data != NULL);
    uint32_t width = 0;
    uint32_t height = 0;
    uint8_t tga_header[18];
    memcpy(tga_header, tga_data, sizeof(tga_header));
    uint16_t tga_width = read_u16(tga_header, 12);
    uint16_t tga_height = read_u16(tga_header, 14);
    size_t tga_capacity = (size_t)tga_width * tga_height * 4;
    uint8_t *tga_pixels = malloc(tga_capacity);
    assert(tga_pixels != NULL);
    assert(tga_decode_rgba(tga_data, tga_length, tga_pixels, tga_capacity, &width,
                           &height));
    assert(width == 4096);
    assert(height == 2048);
    RgbaSprite background = {width, height, tga_pixels};

    uint8_t *frame = malloc(800 * 600 * 4);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, 800 * 600 * 4, 800, 600));
    const MapMarker markers[2] = {
        {82, 83, {20, 230, 90, 255}, 5},
        {85, 83, {230, 40, 40, 255}, 4},
    };
    assert(map_render_city_view(&surface, &background, (int32_t)map.header.origin_x,
                                (int32_t)map.header.origin_y, &map, 13694, markers,
                                2));
    size_t center = ((size_t)300 * 800 + 400) * 4;
    assert(frame[center + 1] == 230 && frame[center + 2] == 90);
    size_t rival = ((size_t)(300 + 48) * 800 + 400 + 96) * 4;
    assert(frame[rival] == 230 && frame[rival + 1] == 40);

    uint8_t *baseline = malloc(800 * 600 * 4);
    assert(baseline != NULL);
    RenderSurface baseline_surface;
    assert(render_surface_init(&baseline_surface, baseline, 800 * 600 * 4, 800,
                               600));
    assert(map_render_city_view(&baseline_surface, &background,
                                (int32_t)map.header.origin_x,
                                (int32_t)map.header.origin_y, &map, 13694, NULL, 0));
    assert(memcmp(frame, baseline, 800 * 600 * 4) != 0);

    free(baseline);
    free(frame);
    free(tga_pixels);
    free(tga_data);
    free(map_data);
}

typedef struct LoadedSprite {
    uint8_t *pixels;
    RgbaSprite rgba;
} LoadedSprite;

static void test_branch_interior_render(void) {
    size_t map_length = 0;
    uint8_t *map_data = load_file("../game/Isokarten/Iso_Filiale_einf_klein.iso",
                                  &map_length);
    assert(map_data != NULL);
    IsoTile storage[ISO_MAX_TILES];
    IsoMap map;
    assert(iso_map_parse(map_data, map_length, &map, storage, ISO_MAX_TILES));

    size_t background_length = 0;
    uint8_t *background_data = load_file(
        "../extracted/isodaten/sprites/filiale_klein_einf_back.spr",
        &background_length);
    assert(background_data != NULL);
    uint16_t background_w = read_u16(background_data, 7);
    uint16_t background_h = read_u16(background_data, 9);
    size_t background_capacity = (size_t)background_w * background_h * 4;
    uint8_t *background_pixels = malloc(background_capacity);
    assert(background_pixels != NULL);
    SpriteAsset background_sprite;
    assert(spr_decode(background_data, background_length, &background_sprite,
                      background_pixels, background_capacity));
    assert(background_sprite.width == 799);
    assert(background_sprite.height == 551);
    assert(background_sprite.bpp == 8);
    RgbaSprite background = {background_sprite.width, background_sprite.height,
                             background_pixels};

    LoadedSprite loaded[40];
    MapSpriteDraw draws[40];
    size_t draw_count = 0;
    memset(loaded, 0, sizeof(loaded));
    for (size_t index = 0; index < map.tile_count; index++) {
        const IsoTile *tile = &map.tiles[index];
        if (!tile->has_layer2) {
            continue;
        }
        char path[128];
        char lower[ISO_LAYER_NAME_SIZE];
        size_t length = strlen(tile->layer2);
        if (length >= sizeof(lower)) {
            continue;
        }
        for (size_t ch = 0; ch < length; ch++) {
            char value = tile->layer2[ch];
            lower[ch] = value >= 'A' && value <= 'Z' ? (char)(value - 'A' + 'a')
                                                     : value;
        }
        lower[length] = '\0';
        snprintf(path, sizeof(path), "../extracted/isodaten/sprites/%s", lower);
        size_t sprite_length = 0;
        uint8_t *sprite_data = load_file(path, &sprite_length);
        assert(sprite_data != NULL);
        uint16_t sprite_w = read_u16(sprite_data, 7);
        uint16_t sprite_h = read_u16(sprite_data, 9);
        size_t capacity = (size_t)sprite_w * sprite_h * 4;
        uint8_t *pixels = malloc(capacity);
        assert(pixels != NULL);
        SpriteAsset sprite;
        assert(spr_decode(sprite_data, sprite_length, &sprite, pixels, capacity));
        free(sprite_data);
        loaded[draw_count].pixels = pixels;
        loaded[draw_count].rgba = (RgbaSprite){sprite.width, sprite.height, pixels};
        int32_t world_x = 0;
        int32_t world_y = 0;
        iso_tile_world(&map, tile, &world_x, &world_y);
        draws[draw_count].sprite = loaded[draw_count].rgba;
        draws[draw_count].world_x = world_x;
        draws[draw_count].world_y = world_y;
        draw_count += 1;
    }
    assert(draw_count == 40);

    uint8_t *frame = malloc(800 * 600 * 4);
    uint8_t *background_frame = malloc(800 * 600 * 4);
    assert(frame != NULL);
    assert(background_frame != NULL);
    RenderSurface surface;
    RenderSurface background_surface;
    assert(render_surface_init(&surface, frame, 800 * 600 * 4, 800, 600));
    assert(render_surface_init(&background_surface, background_frame, 800 * 600 * 4,
                               800, 600));
    assert(map_render_branch_interior(&surface, &background,
                                      (int32_t)map.header.origin_x,
                                      (int32_t)map.header.origin_y, &map, draws,
                                      draw_count));
    assert(map_render_branch_interior(&background_surface, &background,
                                      (int32_t)map.header.origin_x,
                                      (int32_t)map.header.origin_y, &map, NULL, 0));
    size_t different = 0;
    for (size_t index = 0; index < 800 * 600 * 4; index += 4) {
        if (memcmp(frame + index, background_frame + index, 3) != 0) {
            different += 1;
        }
    }
    assert(different > 1000);

    free(background_frame);
    free(frame);
    for (size_t index = 0; index < draw_count; index++) {
        free(loaded[index].pixels);
    }
    free(background_pixels);
    free(background_data);
    free(map_data);
}

static void test_stats_panel_mask(void) {
    size_t map_length = 0;
    uint8_t *map_data = load_file("../game/Isokarten/Lon.iso", &map_length);
    assert(map_data != NULL);
    IsoTile storage[ISO_MAX_TILES];
    IsoMap map;
    assert(iso_map_parse(map_data, map_length, &map, storage, ISO_MAX_TILES));

    size_t panel_length = 0;
    uint8_t *panel_data = load_file("../extracted/pictures/bg003.tga", &panel_length);
    size_t mask_length = 0;
    uint8_t *mask_data = load_file("../extracted/pictures/mask.tga", &mask_length);
    size_t city_length = 0;
    uint8_t *city_data = load_file("../extracted/backgrounds/lon.tga", &city_length);
    assert(panel_data != NULL);
    assert(mask_data != NULL);
    assert(city_data != NULL);

    uint8_t *panel_pixels = malloc(800 * 600 * 4);
    uint8_t *mask_pixels = malloc(800 * 600 * 4);
    uint8_t *city_pixels = malloc((size_t)4096 * 2048 * 4);
    assert(panel_pixels != NULL);
    assert(mask_pixels != NULL);
    assert(city_pixels != NULL);
    uint32_t width = 0;
    uint32_t height = 0;
    assert(tga_decode_rgba(panel_data, panel_length, panel_pixels, 800 * 600 * 4,
                           &width, &height));
    assert(width == 800 && height == 600);
    assert(tga_decode_rgba(mask_data, mask_length, mask_pixels, 800 * 600 * 4, &width,
                           &height));
    assert(width == 800 && height == 600);
    assert(tga_decode_rgba(city_data, city_length, city_pixels,
                           (size_t)4096 * 2048 * 4, &width, &height));
    assert(width == 4096 && height == 2048);
    RgbaSprite panel = {800, 600, panel_pixels};
    RgbaSprite city = {4096, 2048, city_pixels};

    uint8_t *frame = malloc(800 * 600 * 4);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, 800 * 600 * 4, 800, 600));
    const MapMarker marker = {82, 83, {20, 230, 90, 255}, 5};
    assert(map_render_stats_panel(&surface, &panel, &city,
                                  (int32_t)map.header.origin_x,
                                  (int32_t)map.header.origin_y, &map, 13694,
                                  mask_pixels, 800, 600, &marker, 1));
    assert(memcmp(frame, panel_pixels, 4) == 0);
    size_t center = ((size_t)300 * 800 + 400) * 4;
    assert(frame[center + 1] == 230 && frame[center + 2] == 90);
    size_t inside = ((size_t)100 * 800 + 100) * 4;
    assert(memcmp(frame + inside, panel_pixels + inside, 4) != 0);

    free(frame);
    free(city_pixels);
    free(mask_pixels);
    free(panel_pixels);
    free(city_data);
    free(mask_data);
    free(panel_data);
    free(map_data);
}

int main(void) {
    test_london_map_header();
    test_branch_map_header();
    test_city_render();
    test_branch_interior_render();
    test_stats_panel_mask();
    puts("map render reconstruction: OK");
    return 0;
}
