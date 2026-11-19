#include "construction_state.h"

#include <assert.h>
#include <stdio.h>

static void test_order_construct_and_enqueue(void) {
    ConstructionOrder order;
    construction_order_construct(&order, 7, 3);
    assert(order.type == 7);
    assert(order.quality == 3);
    assert(order.duration == 100);
    assert(order.state == 0);
    assert(order.tile_variant == -1);
    assert(order.cell_x == -1);
    assert(order.cell_y == -1);
    assert(order.cell_index == 0);

    construction_order_enqueue(&order, 10, 20, 164);
    assert(order.cell_x == 10);
    assert(order.cell_y == 20);
    assert(order.cell_index == 20u * 164u + 10u);
}

static void test_completion_owns_object(void) {
    ConstructionSite site;
    construction_site_begin(&site, 7, 0, 13694, 10, 20, 164, 100);
    assert(site.order.cell_index == 3290);
    assert(site.object.tile_index == 13694);
    assert(site.object.type == 7);
    assert(site.object.state == 1);
    assert(!site.object.owned);
    assert(!site.object.player_controlled);
    assert(site.ticks_remaining == 100);
    assert(!site.complete);

    for (uint32_t tick = 10; tick < 1000; tick += 10) {
        assert(!construction_site_tick(&site, tick));
    }
    assert(site.ticks_remaining == 1);
    assert(construction_site_tick(&site, 1000));
    assert(site.complete);
    assert(site.ticks_remaining == 0);
    assert(site.order.state == 2);
    assert(site.object.state == 2);
    assert(site.object.owned);
    assert(site.object.player_controlled);
    assert(construction_site_tick(&site, 1010));
}

int main(void) {
    test_order_construct_and_enqueue();
    test_completion_owns_object();
    puts("construction state reconstruction: OK");
    return 0;
}
