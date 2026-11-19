#!/usr/bin/env python3
"""Validation tests for the headless economy simulator."""

import os
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import sim_core as sc  # noqa: E402


class SimCoreTests(unittest.TestCase):
    def make_branch(self, quality=55, price=12.0, marketing=0.0):
        b = sc.Branch(id=0, company_id=0,
                      recipes=[sc.Recipe("Pizza", price, 4.0, quality)],
                      quality=quality, staff=8, capacity=40,
                      marketing=marketing)
        b.update_ratings(1.0)
        return b

    def test_city_ini(self):
        path = os.path.join(ROOT, "extracted", "daten", "ber.ini")
        city = sc.load_city_ini(path)
        self.assertEqual(city.name, "Berlin")
        self.assertEqual(city.short, "ber")
        self.assertEqual(city.population, 260)
        self.assertEqual(city.rent_factor, 65)
        self.assertEqual(len(city.group_shares), 8)
        self.assertAlmostEqual(sum(city.group_shares), 1.0)

    def test_all_city_ini_factors(self):
        import glob
        paths = sorted(glob.glob(os.path.join(
            ROOT, "extracted", "daten", "*.ini")))
        self.assertEqual(len(paths), 10)
        for path in paths:
            raw = {}
            with open(path, errors="replace") as fh:
                for line in fh:
                    line = line.split("//", 1)[0].strip()
                    if not line:
                        continue
                    key, *rest = line.split()
                    raw[key.upper()] = rest
            mieten = int(raw["MIETEN"][0])
            kauf = int(raw["KAUFPREIS"][0])
            volk = [int(x) for x in raw["VOLK"][:8]]
            city = sc.load_city_ini(path)
            self.assertEqual(city.rent_factor, mieten)
            self.assertEqual(city.price_factor, kauf)
            self.assertEqual(city.volk, volk)
            self.assertAlmostEqual(city.rent_trade_factor,
                                   mieten * 0.02, places=12)
            self.assertAlmostEqual(city.purchase_trade_factor,
                                   kauf * 0.02, places=12)
            self.assertEqual(city.ad_city_term,
                             100 - 3 * (volk[0] + volk[6]))
            self.assertAlmostEqual(sum(city.group_shares), 1.0, places=12)

    def test_city_trade_calibration(self):
        import glob
        paths = sorted(glob.glob(os.path.join(
            ROOT, "extracted", "daten", "*.ini")))
        rents = []
        for path in paths:
            city = sc.load_city_ini(path)
            offer = sc.trade_offer_price(
                2, purchase_factor=city.purchase_trade_factor)
            self.assertEqual(
                offer["buy"], int(6000 * city.purchase_trade_factor))
            rent = sc.special_trade_offer(
                1, 0, rent_factor=city.rent_trade_factor)
            rent3 = sc.special_trade_offer(
                3, 0, rent_factor=city.rent_trade_factor)
            self.assertEqual(rent, 2 * int(300 * city.rent_trade_factor))
            self.assertEqual(rent3, 2 * int(200 * city.rent_trade_factor))
            rents.append((city.rent_factor, rent))
        by_factor = [rent for _, rent in sorted(rents)]
        self.assertEqual(by_factor, sorted(by_factor))
        self.assertEqual(by_factor[0], 120)    # Moscow MIETEN 10
        self.assertEqual(by_factor[-1], 1200)  # Tokyo MIETEN 100
        neutral = sc.CityProfile(rent_factor=50, price_factor=50)
        self.assertAlmostEqual(neutral.rent_trade_factor, 1.0)
        self.assertAlmostEqual(neutral.purchase_trade_factor, 1.0)
        self.assertEqual(sc.special_trade_offer(1, 0, rent_factor=1.0), 600)
        self.assertEqual(
            sc.trade_offer_price(2, purchase_factor=1.0)["buy"], 6000)

    def test_city_sweep_conservation(self):
        import glob
        paths = sorted(glob.glob(os.path.join(
            ROOT, "extracted", "daten", "*.ini")))
        for path in paths:
            city = sc.load_city_ini(path)
            sim = sc.build_default(city=city)
            starts = [c.cash for c in sim.companies]
            sim.run(7)
            for company, start in zip(sim.companies, starts):
                self.assertAlmostEqual(
                    company.cash,
                    start + company.total_revenue - company.total_costs,
                    places=4, msg=city.name)
            for b in sim.branches:
                self.assertGreaterEqual(b.stock, 0, city.name)
            self.assertGreater(sim.companies[0].total_revenue, 0, city.name)

    def test_city_scaling(self):
        city = sc.CityProfile(population=520, rent_factor=130,
                              income_factor=130, quality_factor=130)
        sim = sc.Simulator(seed=1, city_traffic=1000, city=city)
        self.assertAlmostEqual(sim.city_traffic, 2000)
        a = sim.add_company("A")
        b = sim.add_branch(0, quality=50, rent_monthly=1000)
        self.assertEqual(b.quality, 100)
        self.assertEqual(b.rent_monthly, 2000)

    def test_rating_factor_from_player_fields(self):
        sim = sc.Simulator(seed=225, city_traffic=0)
        a = sim.add_company("A", 100000)
        a.trait_a = 10
        a.trait_b = 10
        self.assertEqual(a.rating_factor, 40)
        b = sim.add_branch(0, quality=60)
        b.update_ratings()
        self.assertLessEqual(max(b.avg8), 40)
        self.assertLessEqual(max(b.menu_rating), 40)
        self.assertLessEqual(max(b.price_rating), 40)

    def test_rating_group_expectation(self):
        expected = [sc.rating_group_expectation(1.3, 3.0, g)
                    for g in range(8)]
        self.assertAlmostEqual(expected[0], 10.9)
        self.assertAlmostEqual(expected[4], 22.1)
        self.assertAlmostEqual(expected[5], 24.0)
        self.assertAlmostEqual(expected[7], 15.0)

    def test_game_compute_skill_ratings(self):
        # Berlin EINKOMMEN 65 -> 1.3, difficulty 5 -> phase 3.0.
        price = 12.0
        self.assertEqual(
            sc.game_compute_skill_ratings(1.3, 0, price, 3.0),
            [-5, 4, 17, 12, 5, 0, 7, 12])
        self.assertEqual(
            sc.game_compute_skill_ratings(1.3, 0, 0.0, 3.0),
            [40, 10, 20, 30, 5, 0, 40, 20])
        self.assertEqual(
            sc.game_compute_skill_ratings(1.3, 0, 30.0, 3.0)[0], -87)
        boosted = sc.game_compute_skill_ratings(1.3, 1, price, 3.0)
        self.assertNotEqual(boosted, sc.game_compute_skill_ratings(
            1.3, 0, price, 3.0))

    def test_weighted_averages_market_data(self):
        recipe = sc.Recipe("T", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1), sc.RecipeTopping(2)])
        avg = recipe.weighted_averages()
        self.assertEqual(avg["total"], 367)
        self.assertEqual(avg["categories"], [100, 0, 0, 0, 0, 0])
        self.assertEqual(avg["taste"], -1)
        self.assertEqual(avg["price_adjust"], 0)
        self.assertEqual(avg["quality_adjust"], -1)

    def test_market_factor_real_inputs(self):
        recipe = sc.Recipe("T", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1), sc.RecipeTopping(2)])
        scores = recipe.market_factor_scores(
            city_matrix=sc.CityProfile().food_taste, price_competitive=1)
        self.assertEqual(scores,
                         [-75, -45, 10, -135, 20, -10, -165, -125])

    def test_recipe_price_competitiveness(self):
        sim = sc.Simulator(seed=228, city_traffic=0)
        sim.add_company("A", 100000)
        sim.add_company("B", 100000)
        b1 = sim.add_branch(0)
        b2 = sim.add_branch(1)
        toppings = [sc.RecipeTopping(0), sc.RecipeTopping(1),
                    sc.RecipeTopping(2)]
        r1 = sc.Recipe("R1", 12, 4, 50, toppings=toppings)
        r2 = sc.Recipe("R2", 12, 4, 50, toppings=toppings)
        b1.recipes = [r1]
        b2.recipes = [r2]
        self.assertEqual(sim.recipe_price_competitive(r1, 0), 0)
        r2.price = 20
        self.assertEqual(sim.recipe_price_competitive(r1, 0), 1)

    def test_rating_store_clamped_scores(self):
        self.assertEqual(
            sc.rating_store_clamped_scores(10, 20, 0.1, 30),
            [17, 13, 15, 16, 14, 20, 21, 48])
        self.assertEqual(
            sc.rating_store_clamped_scores(100, 15, 0, 50),
            [43, 74, 7, 73, 6, 21, 24, 100])

    def test_game_compute_market_factors(self):
        self.assertEqual(
            sc.game_compute_market_factors(c250=1, c254=2),
            [0, 0, 15, -10, 25, 30, 0, 10])
        self.assertEqual(
            sc.game_compute_market_factors(c250=1, c254=2, count=18),
            [-10, -10, 5, -20, 15, 20, -10, 0])
        self.assertEqual(
            sc.game_compute_market_factors(mission_flag=1)[4], 30)

    def test_base_skill_market_factor_input(self):
        recipe = sc.Recipe("Market", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(67)])
        plain = recipe.base_skill_ratings()
        boosted = recipe.base_skill_ratings([20] * 8)
        self.assertNotEqual(plain, boosted)
        self.assertGreaterEqual(sum(boosted), sum(plain))

    def test_color_histogram_from_sprites(self):
        recipe = sc.Recipe("Color", 12, 4, 50, toppings=[
            sc.RecipeTopping(1, variant=0)])
        hist = recipe.color_histogram()
        self.assertEqual(len(hist), 24)
        self.assertGreater(sum(hist), 0)
        score = sc.screen_score_color_histogram(hist)
        self.assertGreaterEqual(score, 0)
        self.assertLessEqual(score, 100)

    def test_surface_composition_and_scan(self):
        recipe = sc.Recipe("Surface", 12, 4, 50, toppings=[
            sc.RecipeTopping(1, variant=0, x=100, y=100)])
        surface = recipe.compose_surface()
        self.assertEqual(len(surface), 800 * 600)
        self.assertGreater(sum(1 for v in surface if 0 < v < 0xFF), 0)
        hist = recipe.color_histogram()
        self.assertGreater(sum(hist), 0)

    def test_branch_approach_line_generator(self):
        sim = sc.Simulator(seed=229, city_traffic=0)
        sim.add_company("A", 100000)
        recipe = sc.Recipe("Line", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1), sc.RecipeTopping(2)])
        b = sim.add_branch(0, recipes=[recipe], style="edel",
                           size_class=3)
        objects = b.approach_objects
        self.assertGreaterEqual(len(objects), 1)
        self.assertTrue(b.layout_iso.endswith("Iso_Filiale_edel_gross.iso"))
        for obj in objects:
            self.assertEqual(obj["source"], "iso")
            self.assertIn(obj["variant"], range(8))
        self.assertEqual(b.topping_orientations,
                         [o["variant"] for o in objects])
        deltas = recipe.orientation_deltas(b)
        self.assertEqual(len(deltas), 3)
        self.assertTrue(any(d != 0 for d in deltas))
        from iso_tool import IsoMap
        iso = IsoMap(b.layout_iso)
        floor = {(t.x, t.y) for t in iso.tiles
                 if t.layer2 and ("_M_L_" in t.layer2
                                  or "_M_K_" in t.layer2
                                  or t.layer2.startswith("KUECHE"))}
        self.assertTrue(all((o["x"], o["y"]) in floor for o in objects))
        first = [(o["x"], o["y"], o["variant"]) for o in objects]
        sim.generate_branch_layout(b)
        second = [(o["x"], o["y"], o["variant"])
                  for o in b.approach_objects]
        self.assertEqual(first, second)

    def test_all_branch_iso_fixtures(self):
        from iso_tool import IsoMap
        sim = sc.Simulator(seed=231, city_traffic=0)
        sim.add_company("A", 100000)
        for style in ("einf", "rust", "mode", "edel", "roh"):
            for size in (1, 2, 3):
                b = sim.add_branch(0, style=style, size_class=size)
                self.assertTrue(os.path.exists(b.layout_iso))
                iso = IsoMap(b.layout_iso)
                floor = {(t.x, t.y) for t in iso.tiles
                         if t.layer2 and ("_M_L_" in t.layer2
                                          or "_M_K_" in t.layer2
                                          or t.layer2.startswith("KUECHE"))}
                self.assertGreater(len(b.approach_objects), 0)
                self.assertTrue(all(o["source"] == "iso"
                                    and (o["x"], o["y"]) in floor
                                    for o in b.approach_objects))

    def test_generated_layout_feeds_ratings(self):
        sim = sc.Simulator(seed=230, city_traffic=0)
        sim.add_company("A", 100000)
        recipe = sc.Recipe("Line", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1), sc.RecipeTopping(2)])
        b = sim.add_branch(0, recipes=[recipe])
        b.approach_objects = [{"x": 266, "y": 274, "variant": 3},
                              {"x": 280, "y": 284, "variant": 3},
                              {"x": 294, "y": 294, "variant": 3}]
        deltas = recipe.orientation_deltas(b)
        matching = recipe.layout_quality_scores(
            orientation_deltas=[0, 0, 0])
        generated = recipe.layout_quality_scores(
            orientation_deltas=deltas)
        self.assertNotEqual(matching, generated)
        recipe.total_skill_ratings(b, 12)
        b.update_ratings()

    def test_orientation_delta_from_branch(self):
        recipe = sc.Recipe("Orient", 12, 4, 50, toppings=[
            sc.RecipeTopping(0, variant=0)])
        matching = recipe.layout_quality_scores(orientation_deltas=[0])
        rotated = recipe.layout_quality_scores(orientation_deltas=[-3])
        self.assertNotEqual(matching, rotated)
        self.assertEqual(recipe.layout_color_delta([-3]), 100)

    def test_layout_color_delta(self):
        recipe = sc.Recipe("Delta", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1)])
        self.assertEqual(recipe.layout_color_delta([0, 0]), 0)
        self.assertEqual(recipe.layout_color_delta([2, 2]), 0)
        self.assertEqual(recipe.layout_color_delta([3, 3]), 100)
        self.assertEqual(recipe.layout_color_delta([4, 4]), 100)

    def test_layout_quality_scores(self):
        recipe = sc.Recipe("Layout", 12, 4, 50, toppings=[
            sc.RecipeTopping(0), sc.RecipeTopping(1), sc.RecipeTopping(2)])
        self.assertEqual(
            recipe.layout_quality_scores(),
            [31, 14, 0, 9, 0, 0, 0, 18])

    def test_food_stats_pairs(self):
        empty = sc.Recipe("Empty", 12, 4, 50)
        self.assertEqual(empty.food_stats(), [0] * 8)
        paired = sc.Recipe("Pair", 12, 4, 50, toppings=[
            sc.RecipeTopping(0, tier=0), sc.RecipeTopping(67, tier=0)])
        stats = paired.food_stats()
        self.assertEqual(len(stats), 8)
        self.assertGreater(sum(stats), 0)
        self.assertNotEqual(stats, empty.food_stats())

    def test_track_recent_entry(self):
        sim = sc.Simulator(seed=226, city_traffic=0)
        sim.track_recent_entry(0, 5)
        self.assertEqual(sim.city_recent[0], [-1, -1, -1, -1, -1, 5])
        sim.track_recent_entry(0, 6)
        self.assertEqual(sim.city_recent[0], [-1, -1, -1, -1, -1, 6])
        sim.track_recent_entry(0, 5)
        self.assertEqual(sim.city_recent[0], [-1, -1, -1, -1, -1, 5])
        sim.track_recent_entry(0, 5)
        self.assertEqual(sim.city_recent[0], [-1, -1, -1, -1, 5, -1])

    def test_product_score_recent_ring(self):
        sim = sc.Simulator(seed=227, city_traffic=0)
        sim.add_company("A", 100000)
        b = sim.add_branch(0)
        recipe = sc.Recipe("Ring", 12, 4, 50, toppings=[
            sc.RecipeTopping(67, tier=0)])
        b.recipes = [recipe]
        empty = sc.game_compute_company_product_score(
            recipe, b, 0, 12.0, sim.city_recent)
        sim.track_recent_entry(0, 67)
        boosted = sc.game_compute_company_product_score(
            recipe, b, 0, 12.0, sim.city_recent)
        self.assertGreaterEqual(boosted, empty + 10)

    def test_group_rating_bounds(self):
        for quality in (0, 25, 50, 75, 100):
            b = self.make_branch(quality=quality)
            for g in range(8):
                r = b.group_rating(g)
                self.assertGreaterEqual(r, 0)
                self.assertLessEqual(r, 100)

    def test_city_adjust(self):
        self.assertEqual(sc.city_adjust(100, 0, 0), 100)
        self.assertEqual(sc.city_adjust(100, 10, 10), 40)
        self.assertEqual(sc.city_adjust(200, 0, 0), 100)
        self.assertEqual(sc.city_adjust(-10, 0, 0), 0)

    def test_freshness_table(self):
        self.assertEqual(sc.freshness(14.1, 0), 38)
        self.assertEqual(sc.freshness(14.1, 10), 28)
        self.assertEqual(sc.freshness(1.6, 100), 0)
        self.assertEqual(sc.freshness(999.0, 0), 0)

    def test_market_bonus(self):
        self.assertAlmostEqual(sc.market_bonus(0), 1.0)
        self.assertAlmostEqual(sc.market_bonus(10), 1.1)
        self.assertAlmostEqual(sc.market_bonus(-50), 0.5)

    def test_service_level(self):
        self.assertEqual(sc.service_level([10, 10, 10, 10], 0), 2)
        self.assertEqual(sc.service_level([24, 24, 24, 24], 0), 1)

    def test_order_economics(self):
        sim = sc.Simulator(seed=2, city_traffic=100)
        c = sim.add_company("A", 10000)
        b = sim.add_branch(0, recipes=[sc.Recipe("Pizza", 12.0, 4.0, 60)],
                           quality=60)
        b.update_ratings(1.0)
        customer = sc.Customer(group=0, price_tolerance=1.0, branch_id=0)
        rev, cost = sim.process_order(b, customer)
        self.assertGreater(rev, 0)
        self.assertGreater(cost, 0)
        self.assertAlmostEqual(c.cash, 10000 + rev - cost, places=6)
        self.assertGreaterEqual(b.served, 1)

    def test_run_conserves_cash(self):
        sim = sc.Simulator(seed=3, city_traffic=300)
        a = sim.add_company("A", 50000)
        sim.add_branch(0)
        start = a.cash
        sim.run(30)
        self.assertAlmostEqual(
            a.cash, start + a.total_revenue - a.total_costs, places=4)
        self.assertGreater(a.total_revenue, 0)

    def test_deterministic_seed(self):
        def run(seed):
            sim = sc.Simulator(seed=seed, city_traffic=200)
            sim.add_company("A", 50000)
            sim.add_branch(0)
            sim.run(20)
            return sim.summary()
        self.assertEqual(run(7), run(7))
        self.assertNotEqual(run(7)["companies"][0]["cash"],
                            run(8)["companies"][0]["cash"])

    def test_rating_demand_monotonic(self):
        def served(quality):
            sim = sc.Simulator(seed=5, city_traffic=400)
            sim.add_company("A", 50000)
            b = sim.add_branch(0, quality=quality)
            b.update_ratings(1.0)
            sim.run(20)
            return b.served, b.group_rating(0)
        low_served, low_rating = served(20)
        high_served, high_rating = served(90)
        self.assertGreater(high_rating, low_rating)
        self.assertGreaterEqual(high_served, low_served)

    def test_quarter_rollover(self):
        sim = sc.Simulator(seed=9, city_traffic=100)
        sim.add_company("A")
        sim.add_branch(0)
        sim.run(90)
        self.assertEqual(len(sim.quarter_rows), 1)
        self.assertEqual(sim.year, 1)
        self.assertEqual(sim.quarter, 1)
        self.assertEqual(sim.quarter_rows[0]["quarter"], 1)

    def test_size_score_bands(self):
        sim = sc.Simulator(seed=1)
        customer = sc.Customer(group=0)
        branch = sc.Branch(id=0, company_id=0, size_class=2)
        for rating, delta in [(96, 100), (90, 10), (80, 8), (70, 5),
                              (60, 3), (50, 0), (40, -3), (30, -5),
                              (20, -10), (10, -20)]:
            branch.group_rating = lambda g, pc=True, r=rating: r
            customer.scores = [0] * 6
            sim.update_size_score(customer, branch)
            if rating >= 96:
                self.assertEqual(customer.scores[2], 100)
            else:
                self.assertEqual(customer.scores[2], delta)

    def test_threshold_and_radius(self):
        sim = sc.Simulator(seed=1, city_traffic=10)
        sim.add_company("A")
        sim.add_branch(0, x=500, y=500, radius=100, size_class=0)
        sim.recompute_market()
        customer = sc.Customer(group=0, threshold=99, x=500, y=500)
        self.assertIsNone(sim.choose_branch(customer))
        customer.threshold = 0
        self.assertIsNotNone(sim.choose_branch(customer))
        customer.x = 900
        customer.y = 900
        self.assertIsNone(sim.choose_branch(customer))

    def test_tie_and_max_score(self):
        sim = sc.Simulator(seed=1, city_traffic=10)
        sim.add_company("A")
        sim.add_company("B")
        sim.add_branch(0, x=500, y=500, radius=500, size_class=0)
        sim.add_branch(1, x=500, y=500, radius=500, size_class=0)
        sim.recompute_market()
        customer = sc.Customer(group=0, threshold=0, x=500, y=500)
        # Equal scores: Game_PickBestScoredRecord keeps the later branch.
        self.assertEqual(sim.choose_branch(customer).id, 1)
        customer.scores[0] = 50
        # Later branch still wins on equal max.
        self.assertEqual(sim.choose_branch(customer).id, 1)

    def test_exact_hourly_spawn(self):
        sim = sc.Simulator(seed=1, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, staff=10, open_hours=[False] * 24)
        sim.branches[0].open_hours[10] = True
        sim.hour = 10
        sim._tick_exact_traffic()
        # one walk-in + one pedestrian (hour 10 is not %3? 10%3=1) => 1
        self.assertEqual(sim.total_spawned, 1)
        sim.hour = 11
        sim.branches[0].open_hours[11] = False
        before = sim.total_spawned
        sim._tick_exact_traffic()
        self.assertEqual(sim.total_spawned, before)
        sim.branches[0].open_hours[12] = True
        sim.hour = 12
        sim._tick_exact_traffic()
        # walk-in + pedestrian at hour 12
        self.assertEqual(sim.total_spawned, before + 2)

    def test_travel_and_conservation(self):
        sim = sc.Simulator(seed=2, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, staff=1, queue_capacity=1)
        sim.run(10)
        accounted = (sim.branches[0].served + sim.branches[0].lost
                     + len(sim.branches[0].queue) + len(sim.travelers))
        self.assertEqual(accounted, sim.total_spawned)
        self.assertGreater(sim.total_spawned, 0)

    def test_queue_capacity_loss(self):
        sim = sc.Simulator(seed=3, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, staff=1, queue_capacity=0)
        b = sim.branches[0]
        sim.hour = 10
        b.open_hours = [False] * 24
        b.open_hours[10] = True
        sim._tick_exact_traffic()
        # traveler not yet arrived, no loss
        sim.day = 10
        sim.travelers[0].arrival_hour = 0
        sim._tick_exact_traffic()
        self.assertGreaterEqual(b.lost, 1)

    def test_tick_timing(self):
        self.assertEqual(sc.TICKS_PER_HOUR, 360000)
        self.assertEqual(sc.service_ticks(0x0F), 80)
        self.assertEqual(sc.service_ticks(0x10), 30)
        self.assertEqual(sc.WALK_FRAME_DELAY_UNITS, 12)
        self.assertEqual(sc.walk_node_ms(), 83)
        self.assertEqual(sc.path_travel_ms(320, 160), 10 * 83)
        self.assertEqual(sc.travel_ticks(320, 160), 83)
        self.assertEqual(sc.travel_hours(0, 0), 0)
        self.assertEqual(sc.travel_hours(320, 160), 0)

    def test_iso_graph_pathfinding(self):
        sim = sc.Simulator(seed=30, city_traffic=0)
        graph = sim.load_path_graph(
            os.path.join(ROOT, "game", "Isokarten", "Ber.iso"))
        self.assertEqual(len(graph.nodes), 673)
        count, cost, path = graph.shortest_path(0, 100)
        self.assertEqual(count, 15)
        self.assertEqual(cost, 5184)
        self.assertEqual(len(path), count)
        self.assertEqual(graph.shortest_path(0, 7)[:2], (7, 2784))
        # Cost of every hop follows Object_Compare 0x4ED500.
        for u, v in zip(path, path[1:]):
            self.assertEqual(graph.step_cost(u, v),
                             3 * abs(graph.nodes[u].x - graph.nodes[v].x)
                             + 4 * abs(graph.nodes[u].y - graph.nodes[v].y))

    def test_iso_path_cell_count(self):
        # Grid steps: cell_x=(dx/32+dy/16)/2, cell_y=(dy/16-dx/32)/2.
        self.assertEqual(sc.path_cell_count(0, 0), 1)
        self.assertEqual(sc.path_cell_count(64, 0), 1)
        self.assertEqual(sc.path_cell_count(0, 32), 1)
        self.assertEqual(sc.path_cell_count(64, 32), 2)
        self.assertEqual(sc.path_cell_count(32, 16), 1)
        self.assertEqual(sc.path_cell_count(320, 160), 10)
        self.assertEqual(sc.iso_cell_delta(64, 32), (2.0, 0.0))
        self.assertEqual(sc.travel_ticks(320, 160), 83)

    def test_arrival_same_hour(self):
        sim = sc.Simulator(seed=6, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, x=500, y=500)
        sim.hour = 10
        sim._spawn_customer(sim.branches[0])
        customer = sim.travelers[0]
        self.assertEqual(customer.arrival_hour, 10)
        self.assertGreaterEqual(customer.path_cells, 1)
        now = sim.day * 24 * sc.TICKS_PER_HOUR + sim.hour * sc.TICKS_PER_HOUR
        self.assertEqual(customer.travel_ms,
                         customer.path_cells * sc.walk_node_ms())
        self.assertEqual(customer.arrival_tick - now,
                         customer.travel_ms // 10)

    def test_spawn_uses_iso_graph(self):
        sim = sc.Simulator(seed=31, city_traffic=0)
        sim.add_company("A")
        sim.load_path_graph(os.path.join(ROOT, "game", "Isokarten", "Ber.iso"))
        branch = sim.add_branch(0, x=500, y=500)
        branch.path_node = 100
        sim.hour = 10
        sim._spawn_customer(branch)
        customer = sim.travelers[0]
        # _spawn_customer picks a random start node, then uses the exact graph.
        self.assertGreaterEqual(customer.path_cells, 1)
        expected = sim.graph_path_cells(customer.path_node, branch.path_node)
        self.assertEqual(customer.path_cells, expected)
        self.assertEqual(customer.travel_ms,
                         customer.path_cells * sc.walk_node_ms())

    def test_character_party_size(self):
        rng = __import__("random").Random(1)
        sizes = []
        for _ in range(1000):
            c = sc.Character.create(rng)
            self.assertGreaterEqual(c.c4, 30)
            self.assertLessEqual(c.c4, 70)
            self.assertGreaterEqual(c.c8, 30)
            self.assertLessEqual(c.c8, 70)
            self.assertGreaterEqual(c.c12, 30)
            self.assertLessEqual(c.c12, 70)
            self.assertGreaterEqual(c.c16, 30)
            self.assertLessEqual(c.c16, 70)
            self.assertGreaterEqual(c.state, 18)
            self.assertLessEqual(c.state, 60)
            expected = (sc.rating_composite(c.c4, c.c8, c.c12, c.c16,
                                            c.state, c.flagged) >> 4) + 1
            self.assertEqual(c.party_size(), expected)
            sizes.append(c.party_size())
        self.assertGreaterEqual(min(sizes), 1)
        self.assertLessEqual(max(sizes), 7)

    def test_spawn_uses_character(self):
        sim = sc.Simulator(seed=8, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, x=300, y=300)
        sim.hour = 10
        sim._spawn_customer(sim.branches[0])
        customer = sim.travelers[0]
        self.assertIsNotNone(customer.character)
        self.assertEqual(customer.party_size, customer.character.party_size())

    def test_queue_drains_each_hour(self):
        sim = sc.Simulator(seed=7, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, staff=1, queue_capacity=100)
        b = sim.branches[0]
        b.open_hours = [False] * 24
        b.queue = [sc.Customer(group=0, party_size=1) for _ in range(10)]
        sim._tick_exact_traffic()
        self.assertEqual(len(b.queue), 0)

    def test_rating_composite(self):
        self.assertEqual(sc.rating_composite(50, 50, 50, 50, state=50), 56)
        self.assertEqual(sc.rating_composite(50, 50, 50, 50, state=60), 35)
        self.assertEqual(sc.rating_composite(50, 50, 50, 50, state=60,
                                             flagged=True), 17)
        self.assertEqual(sc.rating_composite(100, 100, 100, 100, state=50), 100)
        self.assertEqual(sc.rating_composite(0, 0, 0, 0, state=50), 0)

    def test_building_score_table(self):
        self.assertEqual(sc.BUILDING_WEIGHTS[0], -7)
        self.assertEqual(sc.BUILDING_WEIGHTS[28], 14)
        score = sc.building_score_for_group(
            0, sc.DEFAULT_FACILITIES, 0, 8 * 60 + 55)
        self.assertEqual(score, -4)

    def test_market_value_adjustment(self):
        self.assertEqual(sc.market_price_delta(-1), -40)
        self.assertEqual(sc.market_price_delta(0), 0)
        self.assertEqual(sc.market_price_delta(3), 40)
        self.assertEqual(
            sc.market_value_adjustment(0, 3, [2] * 6, 0, 0, 50, 12), 100)
        self.assertEqual(
            sc.market_value_adjustment(0, 3, [3] * 6, 0, 0, 50, 12), 40)

    def test_skill_and_product_score(self):
        self.assertEqual(sc.skill_ratings([50] * 8, 0),
                         [40, 10, 20, 30, 5, 0, 40, 20])
        self.assertEqual(sc.skill_ratings([50] * 8, 1),
                         [40, 10, 20, 30, 5, 0, 40, 20])
        self.assertEqual(sc.company_product_score([50, 50, 50], 20, 30), 100)
        self.assertEqual(sc.price_rating(12.0, 12.0), 100)
        self.assertEqual(sc.price_rating(14.0, 12.0), 80)

    def test_stock_conservation(self):
        sim = sc.Simulator(seed=12, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, stock_capacity=100)
        b = sim.branches[0]
        sim.run(20)
        self.assertAlmostEqual(
            b.stock, b.stock_capacity + b.units_delivered - b.units_consumed,
            places=6)

    def test_no_daily_reset(self):
        sim = sc.Simulator(seed=13, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, stock_capacity=100)
        b = sim.branches[0]
        sim.run(1)
        self.assertLess(b.stock, b.stock_capacity)

    def test_stockout(self):
        sim = sc.Simulator(seed=14, city_traffic=0)
        c = sim.add_company("A", 10000)
        sim.add_branch(0, stock_capacity=10)
        b = sim.branches[0]
        b.stock = 0
        b.batches = []
        b.supplier = False
        before = c.cash
        customer = sc.Customer(group=0, party_size=1)
        revenue, cost = sim.process_order(b, customer)
        self.assertEqual(revenue, 0)
        self.assertEqual(cost, 0)
        self.assertEqual(b.lost, 1)
        self.assertAlmostEqual(c.cash, before)

    def test_delivery_refill(self):
        sim = sc.Simulator(seed=15, city_traffic=0)
        c = sim.add_company("A", 10000)
        c.marketing_budget = 0
        sim.add_branch(0, stock_capacity=100, staff=0)
        b = sim.branches[0]
        b.open_hours = [False] * 24
        b.stock = 10
        b.batches = [sc.Batch(10, 4.0)]
        b.delivery_delay = 1
        unit = b.batch_unit_cost()
        before = c.cash
        sim.tick_hour()
        self.assertEqual(b.stock, 100)
        self.assertEqual(b.units_delivered, 90)
        self.assertAlmostEqual(c.cash, before - 90 * unit, places=4)
        self.assertAlmostEqual(b.batches[-1].unit_cost, unit, places=6)

    def test_market_share_quarter(self):
        sim = sc.Simulator(seed=16, city_traffic=0)
        a = sim.add_company("A")
        b = sim.add_company("B")
        a.period_revenue = 75
        b.period_revenue = 25
        self.assertAlmostEqual(sim.market_share()[0], 0.75)
        self.assertAlmostEqual(sim.market_share()[1], 0.25)
        sim.end_of_quarter()
        self.assertAlmostEqual(a.last_quarter_share, 0.75)
        self.assertAlmostEqual(b.last_quarter_share, 0.25)
        self.assertEqual(a.period_revenue, 0)
        self.assertAlmostEqual(sim.market_share()[0], 0.75)

    def test_supplier_city_batch_price(self):
        city = sc.CityProfile(price_factor=50, income_factor=50)
        sim = sc.Simulator(seed=18, city_traffic=0, city=city)
        sim.add_company("A")
        b = sim.add_branch(0, recipes=[sc.Recipe("P", 12, 4, 55)],
                           supplier_base_price=2.0)
        self.assertAlmostEqual(b.batch_unit_cost(), 2.0 * 1.5 * 0.97,
                               places=6)
        self.assertAlmostEqual(b.city_price_factor, 0.5)

    def test_ai_target_selection(self):
        sim = sc.Simulator(seed=19, city_traffic=0)
        a = sim.add_company("A")
        sim.add_company("B")
        low = sim.add_branch(0, quality=20)
        high = sim.add_branch(0, quality=100)
        low.update_ratings()
        high.update_ratings()
        low.yearly_profit = {1: -500}
        high.yearly_profit = {1: 900}
        ai = sc.CompanyAI()
        target = ai.select_best_plan_target(sim, a, action_type=2)
        self.assertEqual(target, low.id)
        self.assertEqual(ai.select_best_plan_target(
            sim, sc.Company(9, "Empty"), 2), -1)

    def test_plan_action_tables(self):
        self.assertEqual(sc.PLAN_ACTION_RANDOM[0], [0, 3, 6, 9])
        self.assertEqual(sc.PLAN_STEPS_RANDOM[0], [48, 6, 12, 24])
        self.assertEqual(sc.PLAN_ACTION_EXPANSION[1], [13, 16, 19, 22])
        self.assertEqual(sc.PLAN_STEPS_EXPANSION[1], [24, 24, 48, 80])
        self.assertEqual(sc.PLAN_ACTION_STRATEGY[0], [24, 27, 30, 33])
        self.assertEqual(sc.PLAN_STEPS_STRATEGY[3], [1, 2, 3, 4])
        ai = sc.CompanyAI()
        import random
        for group in ("random", "expansion", "strategy"):
            for personality in range(4):
                action, steps = ai.choose_plan_action(
                    group, personality, random.Random(personality))
                # 48 is the decoded "no action" sentinel.
                if action is None:
                    self.assertEqual(steps, 0)
                else:
                    self.assertLess(action, 0x18)
                    self.assertGreaterEqual(steps, 0)

    def test_plan_step_weights(self):
        ai = sc.CompanyAI()
        self.assertEqual(ai.plan_step_weight(4), 80)
        self.assertEqual(ai.plan_step_weight(5), 20)
        self.assertEqual(ai.plan_step_weight(6, branch_count=6), 120)
        self.assertEqual(ai.plan_step_weight(7), 0)
        self.assertEqual(ai.plan_step_weight(8), 100)
        self.assertEqual(ai.plan_step_weight(10), 200)
        self.assertEqual(ai.plan_step_weight(11), 40)
        self.assertEqual(ai.plan_step_weight(12, needs_supplier=True), 200)
        self.assertEqual(ai.plan_step_weight(12, needs_supplier=False), 20)
        self.assertEqual(ai.plan_step_weight(14, branch_count=4), 20)
        self.assertEqual(ai.plan_step_weight(16), 50)
        self.assertEqual(ai.plan_step_weight(18), 10)
        self.assertEqual(ai.plan_step_weight(19), 30)

    def test_yearly_branch_plan_scores(self):
        branch = sc.Branch(0, 0)
        branch.yearly_profit = {1: 100, 2: -50, 3: 20}
        self.assertEqual(branch.plan_scores(4, 4), [20, -50, 100])
        self.assertEqual(branch.plan_scores(3, 4), [-50, 100])
        company = sc.Company(0, "A")
        company.branches = [branch]
        ai = sc.CompanyAI()
        self.assertEqual(ai.plan_scores(company, current_year=4), [20, -50, 100])

    def test_plan_queue_semantics(self):
        company = sc.Company(0, "A")
        ai = sc.CompanyAI()
        for i in range(12):
            ai.push_action(company, 12, i)
        self.assertEqual(len(company.plan_actions), 10)
        self.assertEqual(company.plan_actions[0].target, 11)
        ai.push_action(company, 12, 5)
        self.assertEqual(len(company.plan_actions), 10)
        self.assertEqual(company.plan_actions[0].target, 5)
        self.assertEqual(sum(1 for a in company.plan_actions
                             if a.action == 12 and a.target == 5), 1)

    def test_game_compute_price(self):
        self.assertEqual(sc.CONSTRUCTION_BASE[3], 500.0)
        # (100 - 3*(10+10))*500*100*0.01 = 20000
        self.assertEqual(sc.game_compute_price(3, 100.0, 10.0, 10.0), 20000)
        self.assertEqual(sc.game_compute_price(1, 100.0, 0.0, 0.0), 2000)
        self.assertEqual(sc.game_compute_price(6, 100.0, 0.0, 0.0), 18000)
        self.assertEqual(sc.game_compute_price(0, 50.0, 0.0, 0.0), 1000)

    def test_market_weighted_price(self):
        prices = [10.0, 20.0, 30.0]
        usages = [1, 1, 0]
        self.assertAlmostEqual(
            sc.market_weighted_unit_price(prices, usages), 0.015)
        self.assertAlmostEqual(
            sc.weighted_order_cost(200000, 4.0, prices, usages), 12000.0)
        self.assertEqual(sc.market_weighted_unit_price([], []), 0.0)

    def test_market_table_loaded(self):
        self.assertEqual(len(sc.MARKET_RECORDS), 86)
        self.assertEqual(sc.MARKET_PRICES[:4], [5.5, 15.0, 8.0, 14.0])
        self.assertEqual(sc.MARKET_AMOUNTS[0], [140, 20, 5, 2])
        rec = sc.MARKET_RECORDS[0]
        self.assertEqual(rec["id"], 1)
        self.assertEqual(len(rec["sizes"]), 4)
        self.assertEqual(rec["sizes"][0][0], {"w": 139, "h": 140})
        self.assertEqual(rec["sizes"][3][7], {"w": 138, "h": 141})

    def test_usage_counters_derived(self):
        sim = sc.build_scenario()
        a = sim.companies[0]
        expected = {5: 5, 13: 30, 16: 17}
        got = {i: v for i, v in enumerate(a.product_usage) if v}
        self.assertEqual(got, expected)
        self.assertEqual(sum(a.product_usage), 52)
        self.assertAlmostEqual(sim.weighted_market_price(),
                               0.09486882190854848, places=10)
        raw = sc.market_weighted_unit_price(sc.MARKET_PRICES,
                                            a.product_usage)
        self.assertAlmostEqual(
            sim.weighted_market_price(),
            raw / sim.market_price_reference, places=12)

    def test_explicit_recipe_ingredients(self):
        sim = sc.Simulator(seed=40, city_traffic=0)
        sim.add_company("A")
        recipe = sc.Recipe("Custom", 12.0, 4.0, 55,
                           ingredients={0: 7, 1: 3})
        sim.add_branch(0, recipes=[recipe])
        self.assertEqual(sim.companies[0].product_usage[0], 7)
        self.assertEqual(sim.companies[0].product_usage[1], 3)
        self.assertEqual(sum(sim.companies[0].product_usage), 10)

    def test_auto_construction_cost(self):
        sim = sc.Simulator(seed=23, city_traffic=0)
        c = sim.add_company("A", 100000)
        c.marketing_budget = 0
        sim.add_branch(0, staff=0, stock_capacity=100)
        b = sim.branches[0]
        b.open_hours = [False] * 24
        b.supplier = False
        order = sim.add_construction(b, weeks=4)
        self.assertEqual(order.cost, b.construction_price())
        self.assertEqual(order.cost, sc.construction_order_price(
            3, 100.0, b.city_price_factor, b.city_tax_factor))
        before = c.cash
        sim._tick_construction()
        self.assertAlmostEqual(c.cash, before - order.cost / 4, places=4)
        self.assertAlmostEqual(c.ledger[3], order.cost / 4, places=4)

    def test_ai_expansion_uses_construction_cost(self):
        sim = sc.Simulator(seed=24, city_traffic=0)
        a = sim.add_company("A", 500000)
        sim.add_company("B", 100000)
        sim.add_branch(0, quality=40)
        sim.add_branch(1, quality=90)
        ai = sc.CompanyAI()
        price = sim.branch_expansion_cost()
        before = a.cash
        ai.push_action(a, 22, -1)
        decisions = ai.weekly(sim, a)
        self.assertIn("expand", {d[0] for d in decisions})
        self.assertAlmostEqual(a.cash, before - price, places=4)
        self.assertAlmostEqual(a.ledger[3], price, places=4)
        self.assertEqual(a.ledger[12], 0.0)
        new_branch = a.branches[-1]
        self.assertFalse(new_branch.opened)
        self.assertEqual([(x.action, x.target) for x in a.plan_actions],
                         [(10, new_branch.id), (8, new_branch.id),
                          (7, new_branch.id), (12, new_branch.id)])
        # Four weekly ticks run Player_CreateBranch's setup actions.
        for _ in range(4):
            ai.weekly(sim, a)
        self.assertTrue(new_branch.opened)
        self.assertTrue(new_branch.menu_ready)
        self.assertTrue(new_branch.supplier)

    def test_batch_cost_formula(self):
        self.assertAlmostEqual(
            sc.batch_unit_cost(2.0, 5, 1.5, 0.1, 0, 0), 4.5)
        self.assertAlmostEqual(
            sc.batch_unit_cost(2.0, 5, 1.5, 0.1, 5, 5), 3.15)

    def test_delivery_same_hour(self):
        sim = sc.Simulator(seed=17, city_traffic=0)
        c = sim.add_company("A", 10000)
        c.marketing_budget = 0
        sim.add_branch(0, stock_capacity=100, staff=0)
        b = sim.branches[0]
        b.open_hours = [False] * 24
        b.supplier = True
        b.delivery_delay = 0
        b.stock = 10
        b.batches = [sc.Batch(10, b.batch_unit_cost())]
        sim.tick_hour()
        self.assertEqual(b.stock, 100)
        self.assertEqual(b.units_delivered, 90)
        self.assertAlmostEqual(b.batches[-1].unit_cost,
                               b.batch_unit_cost(), places=6)

    def test_vehicle_convoy_count_and_delays(self):
        for level, expected in ((0, 1), (1, 2), (2, 3), (5, 3)):
            sim = sc.Simulator(seed=60 + level, city_traffic=0)
            sim.add_company("A", 100000)
            b = sim.add_branch(0, stock_capacity=100, storage_level=level)
            b.stock = 10
            convoy = sim.order_delivery(b)
            self.assertIsNotNone(convoy)
            self.assertEqual(convoy.vehicles, expected)
            self.assertEqual(len(convoy.delays), expected)
            for i, delay in enumerate(convoy.delays):
                self.assertGreaterEqual(delay, 4 * i + 1)
                self.assertLessEqual(delay, 7 * i + 1)
            self.assertEqual(b.vehicles_out, expected)

    def test_vehicle_uses_iso_path(self):
        sim = sc.Simulator(seed=64, city_traffic=0)
        sim.add_company("A", 100000)
        sim.load_path_graph(os.path.join(ROOT, "game", "Isokarten", "Ber.iso"))
        b = sim.add_branch(0, stock_capacity=100, storage_level=0)
        b.stock = 10
        b.supplier_node = 0
        b.storage_node = 100
        convoy = sim.order_delivery(b)
        self.assertEqual(convoy.path_cells, 15)
        self.assertEqual(convoy.arrivals, [convoy.delays[0] + 15])

    def test_delivery_conflict_and_capacity(self):
        sim = sc.Simulator(seed=65, city_traffic=0)
        c = sim.add_company("A", 100000)
        c.marketing_budget = 0
        b = sim.add_branch(0, stock_capacity=100, storage_level=2, staff=0)
        b.open_hours = [False] * 24
        b.stock = 10
        convoy = sim.order_delivery(b)
        self.assertIsNone(sim.order_delivery(b))  # active convoy blocks another
        self.assertEqual(sim.process_convoy(b, max_ticks=0), 0)
        self.assertEqual(b.vehicles_out, 3)
        arrived = sim.process_convoy(b)
        self.assertEqual(arrived, 3)
        self.assertIsNone(b.convoy)
        self.assertEqual(b.vehicles_out, 0)
        self.assertEqual(b.stock, 100)          # no overfill from 3 vehicles
        self.assertEqual(b.units_delivered, 90)  # only capacity-stock
        self.assertAlmostEqual(c.cash, 100000 - 90 * b.batch_unit_cost(),
                               places=4)

    def test_vehicle_end_to_end(self):
        sim = sc.Simulator(seed=66, city_traffic=0)
        c = sim.add_company("A", 100000)
        c.marketing_budget = 0
        b = sim.add_branch(0, stock_capacity=100, storage_level=1, staff=0)
        b.open_hours = [False] * 24
        b.stock = 10
        before = c.cash
        sim.tick_hour()
        self.assertEqual(b.stock, 100)
        self.assertEqual(b.units_delivered, 90)
        self.assertEqual(b.vehicles_out, 0)
        self.assertAlmostEqual(c.cash, before - 90 * b.batch_unit_cost(),
                               places=4)
        self.assertAlmostEqual(
            b.stock, 10 + b.units_delivered - b.units_consumed, places=6)

    def test_advertising_optimizer(self):
        sim = sc.Simulator(seed=101, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=60)
        a.product_usage = [0] * 86
        a.product_usage[11] = 40
        plan = sim.optimize_advertising(b, plan_type=3)
        self.assertGreaterEqual(plan["media_type"], 0)
        self.assertLessEqual(plan["media_type"], 12)
        self.assertEqual(plan["category"], 12)
        self.assertEqual(plan["budget"], 3500)
        self.assertLess(plan["flags"], 16)
        type3 = next(p for p in b.ad_plans if p.plan_type == 3)
        self.assertEqual(type3.monthly_cost, 3500)
        self.assertAlmostEqual(a.ledger[23], 0.0)

    def test_advertising_media_weights(self):
        self.assertEqual(len(sc.AD_WEIGHTS), 13)
        self.assertEqual(sc.AD_WEIGHTS[1], [6, 1, -2, -4, 2, -2, -6, -2])
        self.assertEqual(sc.AD_WEIGHTS[11], [-5, -6, 4, -5, 3, 5, 1, 6])
        plain = sc.advertising_effect(1, 0, 50, 50, flags=0)
        boosted = sc.advertising_effect(1, 0, 70, 50, flags=1)
        self.assertGreater(boosted, plain)

    def test_plan_category_metric(self):
        sim = sc.Simulator(seed=102, city_traffic=0)
        a = sim.add_company("A")
        b = sim.add_branch(0, quality=70)
        b.update_ratings()
        self.assertEqual(sc.plan_category_metric(b, 0, 1),
                         b.price_rating[0])
        self.assertEqual(sc.plan_category_metric(b, 0, 2),
                         b.menu_rating[0])
        self.assertEqual(sc.plan_category_metric(b, 0, 8), b.avg8[0])
        self.assertIsInstance(sc.plan_category_metric(b, 0, 4), int)

    def test_plan_metric_type_averaging(self):
        sim = sc.Simulator(seed=105, city_traffic=0)
        a = sim.add_company("A")
        b1 = sim.add_branch(0, quality=90)
        b2 = sim.add_branch(0, quality=30)
        b1.update_ratings()
        b2.update_ratings()
        b1.avg8 = [90] * 8
        b2.avg8 = [10] * 8
        c = sim.add_company("B")
        c1 = sim.add_branch(1, quality=50)
        c1.update_ratings()
        type1 = sc.plan_average_effect(
            1, 1, 8, a, b1, c, city_term=100)
        type3 = sc.plan_average_effect(
            3, 1, 8, a, b1, c, city_term=100)
        self.assertNotEqual(type1, type3)

    def test_advertising_target_selection(self):
        sim = sc.Simulator(seed=103, city_traffic=0)
        a = sim.add_company("A")
        b = sim.add_branch(0, quality=70)
        c = sim.add_company("B")
        c1 = sim.add_branch(1, quality=30)
        c1.menu_rating = [10] * 8
        b.update_ratings()
        c1.update_ratings()
        plan = sc.optimize_advertising_plan(
            a, branch=b, competitors=[c], plan_type=3)
        self.assertIn(plan["target"], (-1, c.id))
        self.assertGreaterEqual(plan["media_type"], 0)
        self.assertLessEqual(plan["media_type"], 12)
        self.assertIn(plan["flags"], range(16))

    def test_recipe_stream_roundtrip(self):
        import random
        recipe = sc.Recipe.random_construct(random.Random(5), name="Test")
        recipe.unit_cost = 4.25
        data = recipe.to_stream()
        loaded, offset = sc.Recipe.from_stream(data)
        self.assertEqual(offset, len(data))
        self.assertEqual(loaded.name, "Test")
        self.assertAlmostEqual(loaded.unit_cost, 4.25, places=5)
        self.assertEqual(len(loaded.toppings), len(recipe.toppings))
        self.assertEqual(loaded.usage, recipe.usage_counters())
        for a, b in zip(recipe.toppings, loaded.toppings):
            self.assertEqual((a.ingredient, a.category, a.tier, a.x, a.y),
                             (b.ingredient, b.category, b.tier, b.x, b.y))

    def test_recipe_stream_old_version(self):
        import random
        recipe = sc.Recipe.random_construct(random.Random(6))
        data = recipe.to_stream(save_version=0x2A)
        loaded, offset = sc.Recipe.from_stream(data, save_version=0x2A)
        self.assertEqual(offset, len(data))
        self.assertEqual(len(loaded.toppings), 7)

    def test_menu_stream_roundtrip(self):
        import random
        recipes = [sc.Recipe.random_construct(random.Random(i))
                   for i in range(3)]
        data = sc.Recipe.menu_to_stream(recipes)
        loaded, offset = sc.Recipe.load_menu(data)
        self.assertEqual(offset, len(data))
        self.assertEqual(len(loaded), 3)
        for src, dst in zip(recipes, loaded):
            self.assertEqual(src.usage_counters(), dst.usage)

    def test_recipe_stream_fuzz(self):
        import random
        rng = random.Random(20261118)
        for case in range(300):
            name = "".join(rng.choice(
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 -_")
                for _ in range(rng.randrange(0, 0x40)))
            toppings = []
            for _ in range(rng.randrange(0, 13)):
                toppings.append(sc.RecipeTopping(
                    ingredient=rng.randrange(86),
                    category=rng.randrange(32),
                    tier=rng.randrange(4),
                    x=rng.randrange(-100000, 100000),
                    y=rng.randrange(-100000, 100000),
                    variant=rng.randrange(256),
                    flag=rng.randrange(256),
                    reserved=bytes(rng.randrange(256)
                                   for _ in range(8))))
            recipe = sc.Recipe(name, 12.0, rng.random() * 50, 55,
                               toppings=toppings)
            version = 0x2A if case % 7 == 0 else 43
            data = recipe.to_stream(save_version=version)
            loaded, offset = sc.Recipe.from_stream(
                data, save_version=version)
            self.assertEqual(offset, len(data))
            expected = 860 + 21 * (len(toppings) - 7)
            if version < 0x2B:
                expected += 1
            self.assertEqual(len(data), expected)
            self.assertEqual(loaded.name, name)
            self.assertAlmostEqual(loaded.unit_cost, recipe.unit_cost,
                                   places=5)
            self.assertEqual(len(loaded.toppings), len(toppings))
            for src, dst in zip(toppings, loaded.toppings):
                self.assertEqual(
                    (src.ingredient, src.category, src.tier, src.x, src.y,
                     src.variant, src.flag, src.reserved),
                    (dst.ingredient, dst.category, dst.tier, dst.x, dst.y,
                     dst.variant, dst.flag, dst.reserved))

    def test_menu_stream_fuzz(self):
        import random
        rng = random.Random(20261119)
        for _ in range(100):
            recipes = []
            for i in range(rng.randrange(1, 7)):
                recipes.append(sc.Recipe.random_construct(
                    rng, name=f"R{i}", price=rng.uniform(6, 20)))
            data = sc.Recipe.menu_to_stream(recipes)
            loaded, offset = sc.Recipe.load_menu(data)
            self.assertEqual(offset, len(data))
            self.assertEqual(len(loaded), len(recipes))
            for src, dst in zip(recipes, loaded):
                self.assertEqual(src.usage_counters(), dst.usage)

    def test_recipe_topping_usage(self):
        import random
        recipe = sc.Recipe.random_construct(random.Random(4))
        self.assertEqual(len(recipe.toppings), 7)
        counters = recipe.usage_counters()
        self.assertEqual(len(counters), 86)
        self.assertGreater(sum(counters), 0)
        # Random toppings use index 0..85 and tier 0..3.
        for t in recipe.toppings:
            self.assertGreaterEqual(t.ingredient, 0)
            self.assertLess(t.ingredient, 86)
            self.assertIn(t.tier, range(4))

    def test_city_trade_factors_from_ini(self):
        path = os.path.join(ROOT, "extracted", "daten", "ber.ini")
        city = sc.load_city_ini(path)
        self.assertAlmostEqual(city.rent_trade_factor, 1.3)
        self.assertAlmostEqual(city.purchase_trade_factor, 1.4)

    def test_math_round_float_truncates(self):
        self.assertEqual(sc.math_round_float(2.9), 2)
        self.assertEqual(sc.math_round_float(-2.9), -2)

    def test_special_trade_offer_rent_table(self):
        # Type 1: 300/600/1200 * Berlin MIETEN 1.3, +100% neutral city term.
        self.assertEqual(sc.special_trade_offer(1, 0, rent_factor=1.3), 780)
        self.assertEqual(sc.special_trade_offer(1, 1, rent_factor=1.3), 1560)
        self.assertEqual(sc.special_trade_offer(1, 2, rent_factor=1.3), 3120)
        # Type 3 uses its own 200/400/800 table.
        self.assertEqual(sc.special_trade_offer(3, 0, rent_factor=1.3), 520)
        self.assertEqual(sc.special_trade_offer(3, 1, rent_factor=1.3), 1040)
        self.assertEqual(sc.special_trade_offer(3, 2, rent_factor=1.3), 2080)
        self.assertEqual(sc.special_trade_offer(2, 1, rent_factor=1.3), 0)

    def test_special_trade_offer_object_gate(self):
        # object+0x4C == 0 means no rent offer is produced.
        self.assertEqual(sc.special_trade_offer(
            1, 0, rent_factor=1.3, object_flag=False), 0)

    def test_special_trade_offer_modifiers(self):
        self.assertEqual(sc.special_trade_offer(1, 0, rent_factor=1.3,
                                                mission="half"), 390)
        self.assertEqual(sc.special_trade_offer(1, 0, rent_factor=1.3,
                                                mission="bonus"), 1170)
        self.assertEqual(sc.special_trade_offer(1, 0, rent_factor=1.3,
                                                mission="free"), 0)
        self.assertEqual(sc.special_trade_offer(
            1, 0, rent_factor=1.3, nearby_a=2, nearby_b=1,
            special_nearby=True), 1978)

    def test_special_trade_offer_city_factor(self):
        # City+0xCC8[slot] 40 => adjustment 1.1.
        self.assertEqual(sc.special_trade_offer(
            1, 0, rent_factor=1.3, city_factor=40), 819)

    def test_trade_offer_type2(self):
        # Security: base and value are zero, only 6000*KAUFPREIS is paid.
        offer = sc.trade_offer_price(2, purchase_factor=1.4)
        self.assertEqual(offer["buy"], 8400)
        self.assertEqual(offer["sell"], 6000)
        rival = sc.trade_offer_price(2, purchase_factor=1.4,
                                     current_player=False)
        self.assertEqual(rival["sell"], 8400)

    def test_trade_offer_invisible_object(self):
        self.assertEqual(sc.trade_offer_price(2, visible=False),
                         {"buy": 0, "sell": 6000})
        self.assertEqual(sc.trade_offer_price(1, visible=False),
                         {"buy": 0, "sell": 5000})

    def test_trade_offer_non_special(self):
        # Type 1: ((4+6)*20)//20 = 10; +5000; *1.4; +100% city; +5000*1.4.
        offer = sc.trade_offer_price(1, building_value=20,
                                     purchase_factor=1.4, usage_count=4)
        self.assertEqual(offer["buy"], 21028)
        self.assertEqual(offer["sell"], 5000)
        remote = sc.trade_offer_price(1, building_value=20,
                                      purchase_factor=1.4, usage_count=4,
                                      city_factor=40)
        self.assertEqual(remote["buy"], 21729)
        rival = sc.trade_offer_price(1, building_value=20,
                                     purchase_factor=1.4, usage_count=4,
                                     current_player=False)
        self.assertEqual(rival["sell"], 7000)

    def test_city_ad_term(self):
        path = os.path.join(ROOT, "extracted", "daten", "ber.ini")
        city = sc.load_city_ini(path)
        self.assertEqual(city.volk[0], 8)
        self.assertEqual(city.volk[6], 17)
        self.assertEqual(city.ad_city_term, 25)

    def test_percent_modifier(self):
        self.assertEqual(sc.company_percent_modifier(1, 10000), 100)
        self.assertEqual(sc.company_percent_modifier(2, 5000), 100)
        self.assertEqual(sc.company_percent_modifier(3, 3500), 100)
        self.assertEqual(sc.company_percent_modifier(1, 9000), 90)
        self.assertEqual(sc.company_percent_modifier(2, 4000), 80)

    def test_advertising_effect_formula(self):
        self.assertEqual(
            sc.advertising_effect(1, 0, metric=50, competitor=50), 70)
        self.assertEqual(
            sc.advertising_effect(2, 0, metric=50, competitor=50), 65)
        self.assertEqual(
            sc.advertising_effect(3, 0, metric=50, competitor=50), 60)

    def test_construction_cost_and_completion(self):
        sim = sc.Simulator(seed=20, city_traffic=0)
        c = sim.add_company("A", 10000)
        c.marketing_budget = 0
        sim.add_branch(0, staff=0, stock_capacity=100)
        b = sim.branches[0]
        b.open_hours = [False] * 24
        b.supplier = False
        before = c.cash
        sim.add_construction(b, 1000, weeks=4, facility_type=0x1F)
        sim.run(28)
        self.assertAlmostEqual(c.cash, before - 1000, places=4)
        self.assertAlmostEqual(c.ledger[3], 1000, places=4)
        self.assertEqual(b.facilities.get(0x1F, 0), 1)
        self.assertEqual(b.quality, 57)

    def test_advertising_cost_and_return(self):
        def run(ad):
            sim = sc.Simulator(seed=21, city_traffic=0)
            c = sim.add_company("A", 100000)
            c.marketing_budget = 0
            sim.add_branch(0, staff=10, stock_capacity=400)
            b = sim.branches[0]
            if ad:
                sim.add_advertising(b, media_type=1, category=0,
                                    monthly_cost=3500, plan_type=3)
            sim.run(30)
            return (b.revenue, c.cash, c.ledger[17], c.ledger[23],
                    b.ad_value)
        base_rev, base_cash, _, _, _ = run(False)
        ad_rev, ad_cash, ad_hourly, ad_setup, ad_value = run(True)
        # Type 3 keeps its 3500/day budget and charges ledger 17 hourly.
        self.assertAlmostEqual(
            ad_hourly, sc.f32(3500.0 * sc.F32_ONE_OVER_24) * 720, places=2)
        self.assertEqual(ad_setup, 0.0)
        self.assertLess(ad_cash, base_cash)
        # Berlin category effect < 51: no billboard pull, no ad_value ramp.
        self.assertEqual(ad_value, 0.0)
        self.assertEqual(ad_rev, base_rev)

    def test_advertising_daily_budget_and_ledger_slots(self):
        sim = sc.Simulator(seed=211, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        sim.add_advertising(b, monthly_cost=2400, plan_type=1)
        sim.add_advertising(b, monthly_cost=2400, plan_type=2)
        sim.add_advertising(b, monthly_cost=2400, plan_type=3)
        sim._update_advertising()
        expected = sc.f32(2400.0 * sc.F32_ONE_OVER_24)
        self.assertAlmostEqual(a.ledger[15], expected)
        self.assertAlmostEqual(a.ledger[16], expected)
        self.assertAlmostEqual(a.ledger[17], expected)

    def test_allocate_menu_sales_pool(self):
        city = sc.CityProfile(volk=[0, 12, 14, 15, 17, 11, 0, 6])
        sim = sc.Simulator(seed=217, city_traffic=0, city=city)
        a = sim.add_company("A", 100000)
        a.level = 3
        for _ in range(3):
            sim.add_branch(0, quality=90)
        for b in a.branches:
            b.update_ratings()
        a.net_stat_history = [4000.0] * 4
        pool = (16000 >> 5) + int(100000 * 0.05)
        self.assertEqual(pool, 5500)
        sim.allocate_menu_sales(a)
        plans = [p for p in a.ad_plans if p.plan_type == 1]
        plans += [p for b in a.branches for p in b.ad_plans
                  if p.plan_type == 2]
        self.assertTrue(plans)
        for p in plans:
            self.assertTrue(p.active)
            cap = 10000 if p.plan_type == 1 else 5000
            self.assertGreater(p.monthly_cost, 0)
            self.assertLessEqual(p.monthly_cost, cap)
        self.assertGreaterEqual(sum(p.monthly_cost for p in plans), 5499)
        self.assertLessEqual(sum(p.monthly_cost for p in plans), 5500)

    def test_allocate_menu_sales_deactivates_low_effect(self):
        sim = sc.Simulator(seed=218, city_traffic=0)  # Berlin term 25
        a = sim.add_company("A", 100000)
        a.level = 3
        for _ in range(3):
            sim.add_branch(0, quality=90)
        a.net_stat_history = [4000.0] * 4
        sim.allocate_menu_sales(a)
        self.assertFalse(any(p.active for p in a.ad_plans))
        self.assertFalse(any(p.active for b in a.branches
                             for p in b.ad_plans if p.plan_type == 2))

    def test_advertising_takeover_fee(self):
        sim = sc.Simulator(seed=212, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        sim.add_advertising(b, monthly_cost=3500, setup_cost=35000,
                            plan_type=3)
        self.assertAlmostEqual(a.ledger[23], 35000.0)
        sim.add_advertising(b, monthly_cost=3500, plan_type=3)
        self.assertAlmostEqual(a.ledger[23], 35000.0)

    def test_city_campaign_setup_and_settlement(self):
        sim = sc.Simulator(seed=219, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_company("B", 100000)
        ba = sim.add_branch(0)
        bb = sim.add_branch(1)
        ba.assigned_recipe = 0
        bb.assigned_recipe = 0
        ba.recipes[0].skill_ratings = [50, 10, 10, 10, 10, 10, 10, 10]
        bb.recipes[0].skill_ratings = [40, 10, 10, 10, 10, 10, 10, 10]
        camp = sim.start_city_ad_campaign()
        self.assertTrue(camp["active"])
        self.assertEqual(camp["pot"], 5000)
        self.assertEqual(camp["countdown"], 15)  # 12/(2-1)+3
        self.assertIn(camp["category"], range(8))
        sim.city_campaign["category"] = 0
        sim.city_campaign["countdown"] = 1
        sim.tick_hour()
        self.assertFalse(sim.city_campaign["active"])
        self.assertEqual(a.ledger[24], 5000)
        self.assertEqual(a.campaign_wins, 1)
        self.assertEqual(b.campaign_wins, 0)

    def test_city_campaign_timer_and_participants(self):
        sim = sc.Simulator(seed=220, city_traffic=0)
        self.assertIsNone(sim.start_city_ad_campaign())
        for i in range(3):
            sim.add_company(f"C{i}", 10000)
        camp = sim.start_city_ad_campaign()
        self.assertEqual(camp["pot"], 10000)
        self.assertEqual(camp["countdown"], 9)  # 12/2+3
        self.assertIn(camp["category"], range(8))

    def test_plan_effect_value_v_shape(self):
        self.assertEqual(sc.plan_effect_value(0), 40)
        self.assertEqual(sc.plan_effect_value(39), 1)
        self.assertEqual(sc.plan_effect_value(40), 0)
        self.assertEqual(sc.plan_effect_value(41), 1)
        self.assertEqual(sc.plan_effect_value(100), 108)

    def test_game_get_adjusted_value(self):
        self.assertEqual(sc.game_get_adjusted_value(0), 0)
        self.assertEqual(sc.game_get_adjusted_value(100), 175)
        self.assertEqual(sc.game_get_adjusted_value(108), 189)
        self.assertEqual(
            sc.game_get_adjusted_value(100, city_term=0), 100)
        self.assertLess(
            sc.game_get_adjusted_value(100, value_factor=0), 175)
        self.assertEqual(
            sc.game_get_adjusted_value(0, base_value=1), 60)

    def test_ad_value_widens_catchment(self):
        sim = sc.Simulator(seed=214, city_traffic=0)
        sim.add_company("A", 100000)
        b = sim.add_branch(0, x=500, y=500, radius=100)
        customer = sc.Customer(group=0, party_size=1, threshold=0,
                               scores=[0] * 6, x=750, y=500)
        self.assertIsNone(sim._choose_branch_exact(customer))
        b.ad_value = 100.0
        customer.x = 900
        self.assertEqual(sim._choose_branch_exact(customer), b)

    def test_type3_candidate_pull(self):
        sim = sc.Simulator(seed=215, city_traffic=0)
        sim.add_company("A", 100000)
        b = sim.add_branch(0, x=500, y=500, radius=50)
        customer = sc.Customer(group=0, party_size=1, threshold=100,
                               scores=[0] * 6, x=900, y=500)
        self.assertIsNone(sim._choose_branch_exact(customer))
        b.type3_ad_groups = {0}
        self.assertEqual(sim._choose_branch_exact(customer), b)

    def test_type1_ad_plan_approach(self):
        city = sc.CityProfile(volk=[0, 12, 14, 15, 17, 11, 0, 6])
        sim = sc.Simulator(seed=216, city_traffic=0, city=city)
        a = sim.add_company("A", 100000)
        a.level = 3
        b = sim.add_branch(0, quality=90)
        b2 = sim.add_branch(0, quality=90)
        sim.add_branch(0, quality=90)
        for branch in a.branches:
            branch.update_ratings()
        plan = sim.optimize_advertising(b, plan_type=1)
        self.assertTrue(plan["active"])
        sim._update_advertising()
        for branch in a.branches:
            self.assertGreater(branch.ad_value, 0.0)
        self.assertGreater(b.marketing, 0.0)

    def test_type2_ad_plan_activity(self):
        city = sc.CityProfile(volk=[0, 12, 14, 15, 17, 11, 0, 6])
        sim = sc.Simulator(seed=213, city_traffic=0, city=city)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        b.update_ratings()
        plan = sim.optimize_advertising(b, plan_type=2)
        self.assertGreaterEqual(plan["effect"], 41)
        self.assertTrue(plan["active"])
        sim._update_advertising()
        self.assertGreater(b.ad_value, 0.0)
        self.assertGreater(max(b.type2_ad_effect), 0)

    def test_action_type_distribution(self):
        import random
        ai = sc.CompanyAI()
        for strategy, expected in [(0, {"random"}), (1, {"expansion"}),
                                   (2, {"strategy"})]:
            ai.company_strategy = strategy
            rng = random.Random(1)
            kinds = {ai.select_action_type(rng) for _ in range(200)}
            self.assertEqual(kinds, expected)
        ai.company_strategy = 3
        rng = random.Random(1)
        kinds = [ai.select_action_type(rng) for _ in range(1000)]
        self.assertAlmostEqual(kinds.count("random") / 1000, 0.5, places=1)
        self.assertAlmostEqual(kinds.count("expansion") / 1000, 0.5, places=1)
        ai.company_strategy = 6
        rng = random.Random(1)
        kinds = [ai.select_action_type(rng) for _ in range(3000)]
        self.assertAlmostEqual(kinds.count("random") / 3000, 1/3, places=1)
        self.assertAlmostEqual(kinds.count("expansion") / 3000, 1/3, places=1)
        self.assertAlmostEqual(kinds.count("strategy") / 3000, 1/3, places=1)

    def test_plan_scores(self):
        ai = sc.CompanyAI()
        company = sc.Company(0, "A")
        company.profit_history = [10, 20, 30, 40]
        self.assertEqual(ai.plan_scores(company, 1, 2), [20, 30])
        self.assertEqual(ai.plan_scores(company, 0, 10), [10, 20, 30, 40])
        branch = sc.Branch(0, 0)
        branch.yearly_profit = {1: 10, 2: 20, 3: 30}
        company.branches = [branch]
        self.assertEqual(ai.plan_scores(company, current_year=4),
                         [30, 20, 10])

    def test_ledger_mapping(self):
        self.assertEqual(len(sc.LEDGER_NAMES), 25)
        self.assertEqual(sc.LEDGER_NAMES[12], "ingredients")
        self.assertEqual(sc.LEDGER_NAMES[19], "manager")
        self.assertEqual(sc.LEDGER_NAMES[22], "delivery_income")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[22], "delivery_income")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[23], "manager_income")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[0], "turnover_0")
        self.assertEqual(sc.LEDGER_NAMES[15], "city_advertising")
        self.assertEqual(sc.LEDGER_NAMES[16], "poster_advertising")
        self.assertEqual(sc.LEDGER_NAMES[17], "restaurant_advertising")
        self.assertEqual(sc.LEDGER_NAMES[20], "quarterly_bribes")
        self.assertEqual(sc.LEDGER_NAMES[21], "police_bribes")
        self.assertEqual(sc.LEDGER_NAMES[24], "advertising_campaign")

    def test_ledger_finance_mapping(self):
        # Labels resolved through SubMenu_BuildBranchBalance and
        # Language_MapStrings: stocks=0+14, rent=1, construction=2,
        # furnishings=4, misc=5+9, training=11, ingredients=12, manager=19.
        self.assertEqual(sc.LEDGER_NAMES[0], "stocks_warehouse")
        self.assertEqual(sc.LEDGER_NAMES[14], "stocks_warehouse_2")
        self.assertEqual(sc.LEDGER_NAMES[1], "rent_expenses")
        self.assertEqual(sc.LEDGER_NAMES[2], "construction")
        self.assertEqual(sc.LEDGER_NAMES[4], "furnishings")
        self.assertEqual(sc.LEDGER_NAMES[11], "training_cure")
        self.assertEqual(sc.LEDGER_NAMES[12], "ingredients")
        self.assertEqual(sc.LEDGER_NAMES[19], "manager")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[7], "turnover_7")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[21], "misc_income")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[22], "delivery_income")
        self.assertEqual(sc.INCOME_LEDGER_NAMES[23], "manager_income")

    def test_ledger_callsite_categories(self):
        # Non-displayed slots resolved by call sites.
        self.assertEqual(sc.LEDGER_NAMES[3], "expansion")
        self.assertEqual(sc.LEDGER_NAMES[6], "wage_cook")
        self.assertEqual(sc.LEDGER_NAMES[7], "wage_service")
        self.assertEqual(sc.LEDGER_NAMES[8], "wage_errand")
        self.assertEqual(sc.LEDGER_NAMES[9], "service_fees")
        self.assertEqual(sc.LEDGER_NAMES[10], "city_operations")
        self.assertEqual(sc.LEDGER_NAMES[13], "training_expense")
        self.assertEqual(sc.LEDGER_NAMES[18], "delivery_ingredients")
        self.assertEqual(sc.LEDGER_NAMES[23], "misc_admin")
        self.assertEqual(sc.LEDGER_NAMES[24], "advertising_campaign")

    def test_order_ledger_categories(self):
        sim = sc.Simulator(seed=48, city_traffic=0)
        c = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=60)
        b.update_ratings()
        before = c.cash
        rev, cost = sim.process_order(
            b, sc.Customer(group=0, party_size=1))
        self.assertGreater(rev, 0)
        self.assertAlmostEqual(c.ledger[0], rev, places=6)
        self.assertAlmostEqual(c.ledger[12], cost, places=6)
        self.assertAlmostEqual(c.ledger[19], 0.0)
        self.assertAlmostEqual(c.cash, before + rev - cost, places=6)

    def test_one_sale_python_contract(self):
        # Reference for crates/sim: one default sale moves stock 400 -> 399
        # and cash +13.420524712365806 after the market cost.
        sim = sc.Simulator(seed=0, city_traffic=0)
        c = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=60)
        b.update_ratings(1.0)
        self.assertEqual(b.stock, 400.0)
        before = c.cash
        rev, cost = sim.process_order(
            b, sc.Customer(group=0, party_size=1))
        self.assertAlmostEqual(rev, 13.8, places=9)
        self.assertAlmostEqual(cost, 0.3794752876341939, places=12)
        self.assertAlmostEqual(c.cash - before, 13.420524712365806, places=9)
        self.assertEqual(b.stock, 399.0)

    def test_recipe_price_formula(self):
        sim = sc.Simulator(seed=98, city_traffic=0)
        sim.add_company("A")
        b = sim.add_branch(0)
        r = b.recipes[0]
        r.base_price = 10.0
        b.price_percent = 100.0
        b.building_value = 1.0
        b.price_offset = 10.0
        self.assertEqual(b.recipe_price(r), 20.0)
        b.price_percent = 50.0
        self.assertEqual(b.recipe_price(r), 15.0)

    def test_auto_tune_price(self):
        sim = sc.Simulator(seed=99, city_traffic=0)
        sim.add_company("A")
        b = sim.add_branch(0, quality=90)
        b.update_ratings()
        before = b.recipe_price(b.recipes[0])
        offset = b.auto_tune_price([0.125] * 8)
        self.assertGreaterEqual(offset, 0)
        self.assertLessEqual(offset, 99)
        self.assertGreaterEqual(b.recipe_price(b.recipes[0]), before)

    def test_auto_tune_exact_search(self):
        sim = sc.Simulator(seed=106, city_traffic=0)
        sim.add_company("A")
        b = sim.add_branch(0, quality=60)
        ratings = [100, 100, 100, 100, 0, 0, 0, 0]
        b.group_rating = lambda g, price_comparison=True: ratings[g]
        b.price_offset = 20
        # weights sum 10 -> target 8; four high groups carry 2 each = 8.
        self.assertEqual(
            b.auto_tune_price([2, 2, 2, 2, 1, 1, 0, 0]), 20)
        # All-high ratings exceed the target: offset runs out of range -> 10.
        ratings[:] = [100] * 8
        b.price_offset = 0
        self.assertEqual(b.auto_tune_price([2] * 8), 10)

    def test_order_uses_price_offset(self):
        sim = sc.Simulator(seed=100, city_traffic=0)
        c = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=60)
        b.update_ratings()
        cst = sc.Customer(group=0, party_size=1)
        b.price_offset = 0
        rev0, _ = sim.process_order(b, cst)
        b.price_offset = 10
        rev1, _ = sim.process_order(b, cst)
        self.assertGreater(rev1, rev0)

    def test_ai_pricing(self):
        sim = sc.Simulator(seed=30, city_traffic=0)
        a = sim.add_company("A", 200000)
        sim.add_company("B", 200000)
        high = sim.add_branch(0, quality=100)
        low = sim.add_branch(1, quality=0)
        high.update_ratings()
        low.update_ratings()
        ai = sc.CompanyAI()
        before = high.recipe_price(high.recipes[0])
        decision, ok = ai.execute_action(sim, a, 19, high.id)
        self.assertTrue(ok)
        self.assertEqual(decision[0], "price_up")
        self.assertGreater(high.recipe_price(high.recipes[0]), before)

    def test_ai_expands_and_advertises(self):
        sim = sc.Simulator(seed=31, city_traffic=0)
        a = sim.add_company("A", 500000)
        sim.add_company("B", 100000)
        sim.add_branch(0, quality=40)
        sim.add_branch(1, quality=90)
        ai = sc.CompanyAI()
        ai.push_action(a, 22, -1)
        decisions = ai.weekly(sim, a)
        self.assertIn("expand", {d[0] for d in decisions})
        self.assertEqual(len(a.branches), 2)
        self.assertAlmostEqual(a.ledger[3], sim.branch_expansion_cost(),
                               places=4)
        branch = a.branches[0]
        ai.push_action(a, 23, branch.id)
        decisions = ai.weekly(sim, a)
        self.assertIn("ads_start", {d[0] for d in decisions})
        self.assertAlmostEqual(a.ledger[23], 0.0)

    def test_strategy_plan_decomposition(self):
        # AI_InitActionPlan ids 24..35 are mission-plan ids, not
        # Company_ExecuteAction codes.  Only the id and step budget exist.
        ai = sc.CompanyAI()
        for action in (24, 27, 30, 33, 35):
            self.assertEqual(ai.decompose_strategy(action), [action])
        company = sc.Company(0, "A")
        ai.push_strategy_plan(company, 30, target=7, steps=24)
        self.assertEqual([(a.action, a.target, a.steps)
                          for a in company.plan_actions], [(30, 7, 24)])

    def test_ai_city_tick(self):
        sim = sc.Simulator(seed=41, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=55)
        b.supplier = False
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertEqual(decision, ("city_tick", a.id))
        # Action 11 is City_TickBranches; suppliers belong to action 12.
        self.assertFalse(b.supplier)
        self.assertEqual(b.exterminator_tier, 2)
        self.assertAlmostEqual(a.ledger[5], 10000.0)
        sc.CompanyAI().execute_action(sim, a, 11)
        self.assertAlmostEqual(a.ledger[5], 10000.0)

    def test_ai_city_tick_coverage_tiers(self):
        low = sc.Simulator(seed=411, city_traffic=0)
        a = low.add_company("A", 20000)
        b = low.add_branch(0)
        sc.CompanyAI().execute_action(low, a, 11)
        self.assertEqual(b.exterminator_tier, 1)
        self.assertAlmostEqual(a.ledger[5], 1000.0)
        high = sc.Simulator(seed=412, city_traffic=0)
        c = high.add_company("A", 40000)
        d = high.add_branch(0)
        sc.CompanyAI().execute_action(high, c, 11)
        self.assertEqual(d.exterminator_tier, 2)
        self.assertAlmostEqual(c.ledger[5], 10000.0)

    def test_ai_city_tick_construction_cleanup(self):
        sim = sc.Simulator(seed=413, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        b.free_construction_slots = 0
        o0 = sc.ConstructionOrder(12000, 10)
        o1 = sc.ConstructionOrder(12000, 10, progress=2)
        o2 = sc.ConstructionOrder(12000, 10, progress=5)
        b.construction_orders = [o0, o1, o2]
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertIn(("construction_cleanup", b.id),
                      sim.last_city_tick_decisions)
        # progress 0 -> full 12,000; 20% -> 12,000*0.8*0.25 = 2,400.
        self.assertAlmostEqual(a.ledger[5], 14400.0)
        self.assertEqual(b.construction_orders, [o2])

    def test_ai_city_tick_flag_priority(self):
        sim = sc.Simulator(seed=414, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        order = sc.ConstructionOrder(1000, 4, progress=1)
        b.construction_orders = [order]
        b.flags = 0x24  # price tune wins over rebuild
        before = b.price_offset
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertEqual(decision, ("city_tick", a.id))
        self.assertIn(("price_tune", b.id),
                      sim.last_city_tick_decisions)
        self.assertEqual(b.flags & 0x04, 0x04)
        self.assertEqual(b.construction_orders, [order])
        self.assertNotEqual(b.price_offset, before)

    def test_ai_city_tick_menu_product(self):
        sim = sc.Simulator(seed=415, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        b.flags = 0x10
        b.assigned_recipe = None
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertIn(("assign_product", b.id),
                      sim.last_city_tick_decisions)
        self.assertEqual(b.assigned_recipe, 0)
        self.assertTrue(b.menu_ready)
        n = len(b.recipes)
        b.flags = 0x10
        sc.CompanyAI().execute_action(sim, a, 11)
        self.assertEqual(len(b.recipes), n + 1)

    def test_ai_city_tick_rebuild_refund(self):
        sim = sc.Simulator(seed=416, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        b.flags = 4
        order = sc.ConstructionOrder(4000, 4, progress=1, paid=500)
        b.construction_orders = [order]
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertIn(("rebuild", b.id), sim.last_city_tick_decisions)
        self.assertEqual(b.flags & 4, 0)
        self.assertEqual(b.construction_orders, [])
        self.assertAlmostEqual(a.ledger[21], 500.0)

    def test_ai_city_tick_validate_menu(self):
        sim = sc.Simulator(seed=417, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        b.flags = 2
        b.menu_ready = False
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertIn(("validate_menu", b.id),
                      sim.last_city_tick_decisions)
        self.assertTrue(b.menu_ready)
        self.assertEqual(b.flags & 2, 0)

    def test_ai_city_tick_sales_pruning(self):
        sim = sc.Simulator(seed=418, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.exterminator_tier = 2
        b.recipes = [sc.Recipe("High", 12, 4, 55),
                     sc.Recipe("Low", 12, 4, 55)]
        b.recipes[0].sales = 10
        b.recipes[1].sales = 1
        a.menu_prune_policy = True
        decision, ok = sc.CompanyAI().execute_action(sim, a, 11)
        self.assertTrue(ok)
        self.assertEqual(len(b.recipes), 1)
        self.assertEqual(b.recipes[0].name, "High")
        self.assertEqual(a.last_sales_refresh, 24)

    def test_action12_storage_rent_and_buy(self):
        sim = sc.Simulator(seed=221, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        self.assertEqual(sim.storage_rent_price, 520)
        self.assertEqual(sim.storage_buy_price, 19600)
        decision, ok = sc.CompanyAI().execute_action(sim, a, 12)
        self.assertTrue(ok)
        self.assertEqual(decision, ("assign_suppliers", a.id))
        self.assertEqual(a.storage_level, 1)
        self.assertTrue(b.supplier)
        self.assertAlmostEqual(a.ledger[2], 520.0)
        sc.CompanyAI().execute_action(sim, a, 12)
        self.assertAlmostEqual(a.ledger[2], 520.0)
        buy = sc.Simulator(seed=222, city_traffic=0)
        c = buy.add_company("A", 100000)
        c.storage_mode = "buy"
        buy.add_branch(0)
        sc.CompanyAI().execute_action(buy, c, 12)
        self.assertAlmostEqual(c.ledger[0], 19600.0)
        self.assertEqual(c.storage_level, 1)

    def test_action12_storage_expansion(self):
        sim = sc.Simulator(seed=223, city_traffic=0)
        a = sim.add_company("A", 100000)
        for _ in range(8):
            sim.add_branch(0)
        a.storage_level = 1
        sc.CompanyAI().execute_action(sim, a, 12)
        self.assertEqual(a.storage_level, 2)
        self.assertAlmostEqual(a.ledger[2], 2000.0)
        sc.CompanyAI().execute_action(sim, a, 12)
        self.assertAlmostEqual(a.ledger[2], 2000.0)
        a.cost_multiplier = 2.0
        a.storage_level = 1
        sc.CompanyAI().execute_action(sim, a, 12)
        self.assertAlmostEqual(a.ledger[2], 6000.0)  # 2000 + 4000

    def test_ai_guards_action(self):
        sim = sc.Simulator(seed=42, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.yearly_profit = {1: 10, 2: 10, 3: 10, 4: 10}
        b.year_income = 100000
        decision, ok = sc.CompanyAI().execute_action(sim, a, 13)
        self.assertTrue(ok)
        self.assertEqual(decision, ("guards", 2))
        self.assertEqual(b.guards, 2)
        self.assertAlmostEqual(a.ledger[4], 0.0)

    def test_guard_formula_calibration(self):
        sim = sc.Simulator(seed=49, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.year_income = 0
        b.yearly_profit = {1: 0, 2: 0}
        self.assertEqual(sc.CompanyAI().execute_action(sim, a, 13)[0],
                         ("guards", 1))
        b.year_income = 100000
        sim.guard_cap = 2
        self.assertEqual(sc.CompanyAI().execute_action(sim, a, 13)[0],
                         ("guards", 2))
        self.assertEqual(b.guards, 2)
        self.assertAlmostEqual(a.ledger[4], 0.0)
        a.level = 5
        sim.guard_cap = 2
        self.assertEqual(sc.CompanyAI().execute_action(sim, a, 13)[0],
                         ("guards", 4))
        self.assertEqual(a.reserve_guards, 2)

    def test_ai_security_action(self):
        sim = sc.Simulator(seed=43, city_traffic=0)
        a = sim.add_company("A", 1000000)
        b = sim.add_branch(0)
        decision, ok = sc.CompanyAI().execute_action(sim, a, 20, b.id)
        self.assertTrue(ok)
        self.assertEqual(decision, ("security", b.id))
        self.assertEqual(b.security, 1)
        self.assertAlmostEqual(a.ledger[2], 8400.0)
        # Type-2 trade-offer price is charged, and the cap is five.
        for _ in range(6):
            sc.CompanyAI().execute_action(sim, a, 20, b.id)
        self.assertEqual(b.security, 5)
        self.assertAlmostEqual(a.ledger[2], 5 * 8400.0)

    def test_ai_annoy_action(self):
        sim = sc.Simulator(seed=44, city_traffic=0)
        a = sim.add_company("A", 100000)
        sim.add_company("B", 100000)
        rival = sim.add_branch(1, quality=70)
        before = rival.quality
        sim.rng.random = lambda: 0.0
        decision, ok = sc.CompanyAI().execute_action(sim, a, 16)
        self.assertTrue(ok)
        self.assertEqual(decision, ("annoy", rival.id))
        self.assertEqual(rival.quality, before - 3)
        self.assertEqual(a.annoy_cooldown, 30)
        self.assertAlmostEqual(a.ledger[24], 2000)

    def test_ai_gangster_action(self):
        sim = sc.Simulator(seed=45, city_traffic=0)
        a = sim.add_company("A", 100000)
        sim.add_branch(0)
        decision, ok = sc.CompanyAI().execute_action(sim, a, 17)
        self.assertTrue(ok)
        self.assertEqual(decision, ("gangsters", 1))
        self.assertEqual(a.gangsters, 1)
        self.assertAlmostEqual(a.ledger[24], 1000)

    def test_ai_advancement_action(self):
        sim = sc.Simulator(seed=46, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        b.yearly_profit = {1: 1000, 2: 1000}
        decision, ok = sc.CompanyAI().execute_action(sim, a, 21)
        self.assertTrue(ok)
        self.assertEqual(decision, ("advancement", 5000))
        self.assertEqual(a.advancement_score, 5000)
        self.assertAlmostEqual(a.ledger[20], 5000)

    def test_ai_strategy_plan_queue(self):
        sim = sc.Simulator(seed=47, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        ai = sc.CompanyAI()
        ai.push_strategy_plan(a, 24, b.id, steps=48)
        decision = ai.execute_next_action(sim, a)
        self.assertEqual(decision, ("mission_plan", 24))
        self.assertEqual(a.plan_actions, [])

    def test_ai_cuts_advertising_when_negative(self):
        sim = sc.Simulator(seed=32, city_traffic=0)
        a = sim.add_company("A", -1000)
        sim.add_company("B", 1000)
        b = sim.add_branch(0, quality=40)
        sim.add_branch(1, quality=90)
        sim.add_advertising(b)
        ai = sc.CompanyAI()
        ai.weekly(sim, a)
        self.assertEqual(b.ad_plans, [])

    def test_ai_end_to_end(self):
        sim = sc.Simulator(seed=33, city_traffic=100)
        sim.ai_enabled = True
        player = sim.add_company("Player", 500000)
        rival = sim.add_company("Rival", 300000)
        sim.add_branch(player.id, quality=65)
        sim.add_branch(rival.id, quality=50)
        ai = sim.ai_controllers.setdefault(rival.id, sc.CompanyAI())
        ai.push_action(rival, 22, -1)
        sim.run(90)
        self.assertGreater(len(sim.branches), 2)
        self.assertGreater(len(sim.ai_log), 0)
        new_branch = rival.branches[-1]
        self.assertTrue(new_branch.opened)
        self.assertTrue(new_branch.menu_ready)
        self.assertTrue(new_branch.supplier)

    def test_security_price_uses_city_purchase_factor(self):
        sim = sc.Simulator(seed=87, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        decision, ok = sc.CompanyAI().execute_action(sim, a, 20, b.id)
        self.assertTrue(ok)
        self.assertEqual(decision, ("security", b.id))
        self.assertEqual(b.security, 1)
        self.assertAlmostEqual(a.ledger[2], 8400.0)

    def test_security_trade_offer_formula(self):
        city = sc.CityProfile(price_factor=125)
        sim = sc.Simulator(seed=88, city_traffic=0, city=city)
        a = sim.add_company("A", 1000000)
        b = sim.add_branch(0)
        decision, ok = sc.CompanyAI().execute_action(sim, a, 20, b.id)
        self.assertTrue(ok)
        self.assertEqual(decision, ("security", b.id))
        self.assertAlmostEqual(a.ledger[2], 15000.0)
        self.assertEqual(b.security, 1)

    def test_mission_plan_condition_and_reward(self):
        sim = sc.Simulator(seed=90, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        b.update_ratings()
        plan = sim.start_mission_plan(24, 5, b.id)
        self.assertTrue(sim.mission_condition(24, a))
        sim.tick_mission_plans()
        self.assertEqual(plan.counter, 1)
        self.assertEqual(sim.mission_plans, [])
        plan = sim.start_mission_plan(27, 5, b.id)
        if b.group_rating(0) > 80:
            sim.tick_mission_plans()
            self.assertEqual(sim.city_scores.get(27), 100)

    def test_mission_city_score_effects(self):
        sim = sc.Simulator(seed=94, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        b.avg8 = [90] * 8
        b.menu_rating = [90] * 8
        b.price_rating = [90] * 8
        b.building_rating = 90
        b.group_rating = lambda g, pc=True: 90
        sim.start_mission_plan(26, 1, 0)
        sim.tick_mission_plans()
        self.assertEqual(sim.city_company_scores["d40"][a.id], 100)
        sim.start_mission_plan(27, 1, 0)
        sim.tick_mission_plans()
        self.assertEqual(sim.city_company_scores["c98"][a.id], 100)

    def test_mission_renovation_and_stats(self):
        sim = sc.Simulator(seed=95, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        for _ in range(7):
            sim.start_mission_plan(31, 1, 0)
            sim.tick_mission_plans()
        self.assertEqual(b.renovation_level, 5)
        a.product_usage = [0] * 86
        a.product_usage[7] = 9
        a.product_usage[3] = 2
        sim.start_mission_plan(34, 1, 0)
        sim.tick_mission_plans()
        self.assertEqual(sim.player_stat_actions[a.id], (7, 9))
        self.assertEqual(a.mission_completions[34], 1)

    def test_mission_counter_effects(self):
        sim = sc.Simulator(seed=96, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        b.avg8 = [90] * 8
        b.menu_rating = [90] * 8
        b.price_rating = [90] * 8
        b.building_rating = 90
        b.group_rating = lambda g, pc=True: 90
        for action in (25, 28, 29, 33):
            sim.start_mission_plan(action, 1, 0)
            sim.tick_mission_plans()
            self.assertEqual(a.mission_completions.get(action), 1)
            self.assertEqual(sim.mission_stats.get(action), 1)

    def test_mission_advancement_reset(self):
        sim = sc.Simulator(seed=97, city_traffic=0)
        a = sim.add_company("A", 100000)
        a.advancement_score = 5000
        b = sim.add_branch(0, quality=90)
        b.avg8 = [90] * 8
        b.menu_rating = [90] * 8
        b.price_rating = [90] * 8
        b.building_rating = 90
        b.group_rating = lambda g, pc=True: 90
        sim.start_mission_plan(32, 1, 0)
        sim.tick_mission_plans()
        self.assertEqual(a.advancement_score, 0)
        self.assertEqual(sim.city_company_scores["cc8"][a.id], 60)

    def test_mission_timeout(self):
        sim = sc.Simulator(seed=91, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=0)
        b.update_ratings()
        plan = sim.start_mission_plan(30, 2, b.id)
        sim.tick_mission_plans()
        self.assertEqual(len(sim.mission_plans), 1)
        sim.tick_mission_plans()
        self.assertEqual(sim.mission_plans, [])

    def test_mission_reward_35(self):
        sim = sc.Simulator(seed=92, city_traffic=0)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0)
        before = a.cash
        plan = sim.start_mission_plan(35, 1, b.id)
        sim.tick_mission_plans()
        expected = (b.size_class * 5 + 5) * 20000
        self.assertAlmostEqual(a.cash, before + expected)
        self.assertEqual(plan.counter, 1)

    def test_mission_end_to_end(self):
        sim = sc.Simulator(seed=93, city_traffic=100)
        a = sim.add_company("A", 100000)
        b = sim.add_branch(0, quality=90)
        b.update_ratings()
        plan = sim.start_mission_plan(33, 8, b.id)
        sim.run(7)
        self.assertEqual(sim.mission_plans, [])
        self.assertEqual(sim.mission_stats.get(33), 1)

    def test_party_size_formula(self):
        self.assertEqual(sc.party_size_from_rating(0), 1)
        self.assertEqual(sc.party_size_from_rating(15), 1)
        self.assertEqual(sc.party_size_from_rating(16), 2)
        self.assertEqual(sc.party_size_from_rating(31), 2)
        self.assertEqual(sc.party_size_from_rating(32), 3)
        self.assertEqual(sc.party_size_from_rating(100), 7)

    def test_queue_seat_capacity(self):
        sim = sc.Simulator(seed=4, city_traffic=0)
        sim.add_company("A")
        sim.add_branch(0, queue_capacity=3)
        b = sim.branches[0]
        customer = sc.Customer(group=0, target_branch=0, party_size=4,
                               arrival_hour=0)
        sim.travelers.append(customer)
        sim._tick_exact_traffic()
        self.assertEqual(b.lost, 1)
        self.assertEqual(len(b.queue), 0)

    def test_sweep_direction(self):
        rows = {r["scenario"]: r for r in sc.sweep(30)}
        self.assertGreater(rows["price_+20%"]["revenue"],
                           rows["base"]["revenue"])
        self.assertLess(rows["price_-20%"]["revenue"],
                        rows["base"]["revenue"])
        self.assertGreater(rows["quality_+20%"]["avg_rating"],
                           rows["base"]["avg_rating"])
        self.assertAlmostEqual(rows["base"]["customer_share"], 0.5, places=1)

    def test_stock_refill(self):
        sim = sc.Simulator(seed=11, city_traffic=600)
        sim.add_company("A", 100000)
        b = sim.add_branch(0, stock_capacity=10)
        sim.run(10)
        self.assertGreater(b.served, 10)


if __name__ == "__main__":
    unittest.main(verbosity=2)
