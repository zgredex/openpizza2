//! Small deterministic branch simulation used by the playable viewer.
//!
//! The constants and one-sale arithmetic are taken from the Python order and
//! ledger model (`Simulator.process_order`): rating 50, recipe price 12.0,
//! one serving per customer, batch cost 4.0, and the market factor produced by
//! the default Berlin market table. A sale therefore has revenue 13.80,
//! ingredient/market cost 0.3794752876341939 and a cash delta of
//! 13.420524712365806, with stock moving 400 -> 399.

use serde::{Deserialize, Serialize};
use std::path::Path;

pub const START_CASH: f64 = 10_000.0;
pub const START_STOCK: f64 = 400.0;
pub const STOCK_CAPACITY: f64 = 400.0;
pub const UNIT_COST: f64 = 4.0;
pub const MARKET_PRICE_FACTOR: f64 = 0.094_868_821_908_548_48;
pub const RATING: i32 = 50;
pub const STEP_MINUTES: u32 = 15;
/// Original game-loop timer unit: `Game_GetTimeByMode` counts down tenths of
/// a second in 10 ms ticks (`0x50d200` stores `mode * 5` and the loop ticks
/// at 100 Hz).
pub const TICK_MS: u32 = 10;
/// Queue movement mode 4 is `0x104 ± 10` ticks (2.50-2.70 s).
pub const QUEUE_WALK_TICKS: u32 = 260;
/// Production mode 6 is 80 ticks; the no-prepared-order cooking path is 180.
pub const PRODUCTION_TICKS: u32 = 180;
pub const SERVICE_TICKS: u32 = 80;
/// Queue capacity remains a model parameter: the retained branch export does
/// not expose a proven admission limit. 40 matches the existing Python model.
pub const QUEUE_CAPACITY: u32 = 40;

/// Derived from the native London save fixture. The save itself is at 08:05;
/// this focused visit checkpoint is 10:55, the last five-minute boundary before
/// the first observed customer. The native trace records customer 100017,
/// branch 100000, player slot 0, four employees, cash 493015.00 and stock
/// 200000 at load.
pub const LONDON_CHECKPOINT_CASH: f64 = 493_015.0;
pub const LONDON_CHECKPOINT_STOCK: f64 = 200_000.0;
pub const LONDON_CHECKPOINT_MINUTE: u32 = 10 * 60 + 55;
pub const LONDON_BRANCH_ID: u32 = 100_000;
pub const LONDON_PLAYER_SLOT: u8 = 0;
pub const LONDON_STAFF_COUNT: u32 = 4;
pub const LONDON_FIRST_CUSTOMER_ID: u32 = 100_017;
/// Native SALE/PAYMENT line: the order consumes 16,100 stock units and pays
/// 1,387.28. The pre-payment cash includes costs incurred between the saved
/// 08:05 state and the 11:00 visit.
pub const LONDON_PRE_ORDER_STOCK: f64 = 400_000.0;
pub const LONDON_ORDER_STOCK_DROP: f64 = 16_100.0;
pub const LONDON_ORDER_SERVINGS: u32 = 100;
pub const LONDON_ORDER_REVENUE: f64 = 1_387.28;
pub const LONDON_ORDER_CASH_BEFORE: f64 = 492_344.45;
pub const LONDON_ORDER_CASH_AFTER: f64 = 493_731.73;
pub const LONDON_ORDER_PRICE: f64 = LONDON_ORDER_REVENUE / (LONDON_ORDER_SERVINGS as f64 * 1.15);

/// London city sites.  A native city-object scan after staffing reported the
/// stationary player branch at cell 12592 and the rival branch at cell 14628
/// across two snapshots; 13885 is an unowned type-20 plot for the headquarters.
pub const LONDON_HQ_TILE: u32 = 13_885;
pub const LONDON_HQ_WORLD: (i32, i32) = (6_048, 3_088);
pub const LONDON_RIVAL_TILE: u32 = 14_628;
pub const LONDON_RIVAL_WORLD: (i32, i32) = (3_424, 1_936);
pub const LONDON_RIVAL_BRANCH_ID: u32 = 100_001;
/// `CompanyInfo_FillActions` (`0x4a2a10`) quotes HQ expansion from
/// `Stats_GetCombinedValue(4, level)`.  The level-one quote is the shipped
/// 3424 value; the higher tiers scale with the same dynamic multiplier.
pub const HQ_EXPANSION_COSTS: [u32; 3] = [3_424, 4_565, 5_706];
/// The native expansion sets `MapObject+0x38 = 4`; `City_TickSimulation`
/// (`0x4d8d50`, case 0x1c) decrements it once per city hour and increments C20
/// when it reaches zero.  Four ticks therefore equal four in-game hours.
pub const HQ_CONSTRUCTION_MINUTES: u32 = 4 * 60;
/// `SubMenu_BuildAnnoyances` rat order: 5000 cost, courier travel time.
pub const RAT_DELIVERY_COST: u32 = 5_000;
pub const RAT_DELIVERY_MINUTES: u32 = 60;

/// `Game_GetStartingCapital` (`0x48d3a0`). The difficulty index is
/// `DAT_0057bb24`; every other value falls through to 20,000.
pub fn starting_capital(difficulty: u8) -> u32 {
    match difficulty {
        0 => 1_000_000,
        1 => 500_000,
        2 => 200_000,
        3 => 100_000,
        4 => 75_000,
        5 => 50_000,
        6 => 40_000,
        7 => 30_000,
        8 => 25_000,
        9 => 22_000,
        _ => 20_000,
    }
}

/// `Game_InitScenario` (`0x481d90`) multiplies the difficulty table by the
/// player company's ownership percentage at `DAT_0057bcd8` and divides by 100
/// before storing the company cash double at `+0x108` (`0x482048..0x4820c1`).
pub fn starting_capital_with_ownership(difficulty: u8, ownership_percent: u32) -> u32 {
    starting_capital(difficulty) * ownership_percent / 100
}

/// `Branch_ComputeRecipePrice` (`0x513bf0`).
///
/// Inputs: recipe base unit price, branch price percent (`+0x14a8`), branch
/// building value, and branch price offset (`+0x14ac`). Returns the menu price
/// used by the production worker's candidate record. The caller
/// `Action_AddBestRecipeToBranchMenu` (`0x509580`) passes `-999` for the percent
/// so the branch's stored percent is used.
pub fn recipe_price(
    base_price: f64,
    price_percent: f64,
    building_value: f64,
    price_offset: f64,
) -> f64 {
    base_price * (price_percent * 0.01 * building_value) + price_offset
}

/// `Game_GetSkillRating` (`0x5139e0`) aggregation over the two nine-entry
/// arrays filled by `Game_ComputeSkillRatings` (`0x513760`): skill/craft at
/// `+0x2c4` and `+0x2e4`. Category 8 is remapped to 5; category -1 averages
/// `(skill[i] + craft[i])` over eight categories.
pub fn skill_rating(skill: &[i32; 9], craft: &[i32; 9], category: i32) -> i32 {
    let category = if category == 8 { 5 } else { category };
    if category == -1 {
        let sum: i32 = (0..8).map(|index| skill[index] + craft[index]).sum();
        return (sum + (sum >> 31 & 7)) >> 3;
    }
    if (0..9).contains(&category) {
        return skill[category as usize] + craft[category as usize];
    }
    0
}

/// Returned candidate score from `Game_ComputeObjectDetails` (`0x5092b0`).
///
/// The bounded disassembly computes:
/// `clamp(0..100, trunc((rating_offset + 100) * quality * 0.01))`.
/// The raw market/skill score is written only to optional output pointers; the
/// `0x509580` caller passes those pointers as null and ranks candidates by this
/// returned value. `rating_offset` is branch `+0x14c0`, used only when
/// `+0x14c4` is non-zero.
pub fn candidate_score(quality: i32, rating_offset: i32) -> i32 {
    let value = ((rating_offset + 100) as f64 * quality as f64 * 0.01) as i32;
    value.clamp(0, 100)
}

/// Exact rank selection in `Action_AddBestRecipeToBranchMenu` (`0x509580`)
/// after the candidate list has been sorted by descending score.
///
/// With fewer than four candidates the choice is uniform. With at least four:
/// roll 51..100 -> rank 0, 21..50 -> rank 1, 6..20 -> rank 2, 1..5 -> uniform.
pub fn select_candidate_index(count: usize, roll: u32, fallback_roll: u32) -> Option<usize> {
    if count == 0 {
        return None;
    }
    if count >= 4 {
        if roll > 50 {
            return Some(0);
        }
        if roll > 20 {
            return Some(1);
        }
        if roll > 5 {
            return Some(2);
        }
    }
    Some(fallback_roll as usize % count)
}

/// Inputs observed immediately before a native `Branch_ProcessCustomerOrder`
/// call. The order's price and recipe quantities are read from the lifted
/// order object. `recipe_id` is the host-computed fingerprint of the recipe
/// quantities, and `rating`/`tip_base` are the values used by
/// `Branch_ProcessCustomerOrder` to derive the tip.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct OrderInput {
    pub customer_id: u32,
    pub minute: u32,
    pub menu_price: f64,
    pub recipe_id: u32,
    pub ingredient_units: u32,
    pub servings: u32,
    pub rating: u32,
    pub tip_base: i32,
}

impl OrderInput {
    pub fn stock_use(&self) -> f64 {
        self.ingredient_units as f64 * self.servings as f64
    }

    /// `local_17c = (rating - customer_base) >> 1`, clamped at zero.
    pub fn tip(&self) -> i32 {
        ((self.rating as i32 - self.tip_base) >> 1).max(0)
    }

    /// Native order revenue: `((tip + 100) * servings * price * 0.01) + 0.5`,
    /// stored as a single-precision float by `Branch_ProcessCustomerOrder`.
    pub fn revenue(&self) -> f64 {
        let raw = (self.tip() as f64 + 100.0) * self.servings as f64 * self.menu_price * 0.01;
        f64::from((raw + 0.5) as f32)
    }
}

/// First verified London customer order (100017): menu 11.85281086,
/// 161 ingredient units, 100 servings, rating 66, tip base 32 -> tip 17,
/// 16,100 stock units and revenue 1387.28.
pub const CAMPAIGN_LONDON_ORDER: OrderInput = OrderInput {
    customer_id: 100_017,
    minute: 0,
    menu_price: 11.852_810_86,
    recipe_id: 0x0143_7164,
    ingredient_units: 161,
    servings: 100,
    rating: 66,
    tip_base: 32,
};

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Sale {
    pub clock_minutes: u32,
    pub recipe_id: u32,
    pub price: f64,
    pub servings: u32,
    pub revenue: f64,
    pub stock_cost: f64,
    pub market_cost: f64,
    pub cash_delta: f64,
}

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Snapshot {
    pub open: bool,
    pub price: f64,
    pub cash: f64,
    pub stock: f64,
    pub stock_capacity: f64,
    pub clock_minutes: u32,
    pub servings_sold: u32,
    pub customers_served: u32,
    pub customers_lost: u32,
    pub sales: u32,
    pub steps: u32,
    pub last_sale: Option<Sale>,
}

#[derive(Clone, Debug, PartialEq)]
pub enum StepOutcome {
    Sale(Sale),
    Closed,
    StockOut,
}

#[derive(Clone, Debug)]
pub struct BranchSim {
    open: bool,
    price: f64,
    cash: f64,
    starting_cash: f64,
    stock: f64,
    stock_capacity: f64,
    servings_per_sale: u32,
    stock_units_per_serving: f64,
    market_factor: f64,
    clock_minutes: u32,
    servings_sold: u32,
    customers_served: u32,
    customers_lost: u32,
    sales: u32,
    recipe_sales: Vec<(u32, u32)>,
    steps: u32,
    last_sale: Option<Sale>,
}

impl Default for BranchSim {
    fn default() -> Self {
        Self {
            open: false,
            price: 12.0,
            cash: START_CASH,
            starting_cash: START_CASH,
            stock: START_STOCK,
            stock_capacity: STOCK_CAPACITY,
            servings_per_sale: 1,
            stock_units_per_serving: 1.0,
            market_factor: MARKET_PRICE_FACTOR,
            clock_minutes: 10 * 60,
            servings_sold: 0,
            customers_served: 0,
            customers_lost: 0,
            sales: 0,
            recipe_sales: Vec::new(),
            steps: 0,
            last_sale: None,
        }
    }
}

impl BranchSim {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn snapshot(&self) -> Snapshot {
        Snapshot {
            open: self.open,
            price: self.price,
            cash: self.cash,
            stock: self.stock,
            stock_capacity: self.stock_capacity,
            clock_minutes: self.clock_minutes,
            servings_sold: self.servings_sold,
            customers_served: self.customers_served,
            customers_lost: self.customers_lost,
            sales: self.sales,
            steps: self.steps,
            last_sale: self.last_sale.clone(),
        }
    }

    pub fn set_open(&mut self, open: bool) {
        self.open = open;
    }

    /// `Object_UpdateCustomerQueue` (`0x409d80`) increments branch `+0x16e0`
    /// on the rejection path. The admission threshold itself is not exposed by
    /// the retained export.
    pub fn record_lost_customer(&mut self) {
        self.customers_lost += 1;
    }

    /// Applies the scenario's starting capital. `Game_GetStartingCapital`
    /// supplies the value for free games; campaign games use the city's
    /// `STARTGELD`.
    pub fn set_starting_cash(&mut self, cash: f64) {
        self.starting_cash = cash;
        self.cash = cash;
    }

    pub fn set_price(&mut self, price: f64) {
        self.price = price.clamp(0.01, 999.99);
    }

    pub fn set_stock(&mut self, stock: f64) {
        self.stock = stock.max(0.0);
    }

    pub fn set_stock_capacity(&mut self, capacity: f64) {
        self.stock_capacity = capacity.max(0.0);
    }

    /// Calibrate one settled order against the native SALE trace.
    pub fn set_order_profile(
        &mut self,
        servings: u32,
        stock_units_per_serving: f64,
        market_factor: f64,
    ) {
        self.servings_per_sale = servings.max(1);
        self.stock_units_per_serving = stock_units_per_serving.max(0.0);
        self.market_factor = market_factor.max(0.0);
    }

    pub fn set_price_from_recipe(
        &mut self,
        base_price: f64,
        price_percent: f64,
        building_value: f64,
        price_offset: f64,
    ) {
        self.set_price(recipe_price(
            base_price,
            price_percent,
            building_value,
            price_offset,
        ));
    }

    pub fn step(&mut self) -> StepOutcome {
        self.steps = self.steps.wrapping_add(1);
        self.clock_minutes = self.clock_minutes.wrapping_add(STEP_MINUTES);
        self.settle_sale_at(self.clock_minutes)
    }

    /// Settle one scripted customer at an explicit clock time without
    /// advancing the 15-minute prototype step. The clock replay
    /// (`ClockReplay`) uses this at the hourly boundary.
    pub fn settle_sale_at(&mut self, clock_minutes: u32) -> StepOutcome {
        if !self.open {
            return StepOutcome::Closed;
        }
        let servings = self.servings_per_sale;
        let stock_units = servings as f64 * self.stock_units_per_serving;
        if self.stock < stock_units {
            self.customers_lost += 1;
            return StepOutcome::StockOut;
        }
        let tip = ((RATING - 20).max(0) / 2) as f64;
        let revenue = (100.0 + tip) * servings as f64 * self.price * 0.01;
        let ingredient_cost = UNIT_COST * servings as f64;
        let market_cost = ingredient_cost * self.market_factor;
        let cash_delta = revenue - market_cost;
        self.stock -= stock_units;
        self.servings_sold += servings;
        self.customers_served += 1;
        self.sales += 1;
        self.cash += cash_delta;
        let sale = Sale {
            clock_minutes,
            recipe_id: 0,
            price: self.price,
            servings,
            revenue,
            stock_cost: ingredient_cost,
            market_cost,
            cash_delta,
        };
        self.last_sale = Some(sale.clone());
        StepOutcome::Sale(sale)
    }

    /// Book an order from captured native inputs. Stock and the sales record
    /// change here; cash is credited separately when the payment event runs.
    pub fn settle_order_input(&mut self, order: &OrderInput) -> StepOutcome {
        if !self.open {
            return StepOutcome::Closed;
        }
        let stock_use = order.stock_use();
        if self.stock < stock_use {
            self.customers_lost += 1;
            return StepOutcome::StockOut;
        }
        let revenue = order.revenue();
        self.stock -= stock_use;
        self.servings_sold += order.servings;
        self.customers_served += 1;
        self.sales += 1;
        match self
            .recipe_sales
            .iter_mut()
            .find(|(recipe_id, _)| *recipe_id == order.recipe_id)
        {
            Some((_, records)) => *records += 1,
            None => self.recipe_sales.push((order.recipe_id, 1)),
        }
        let sale = Sale {
            clock_minutes: order.minute,
            recipe_id: order.recipe_id,
            price: order.menu_price,
            servings: order.servings,
            revenue,
            stock_cost: 0.0,
            market_cost: 0.0,
            cash_delta: revenue,
        };
        self.last_sale = Some(sale.clone());
        StepOutcome::Sale(sale)
    }

    /// Number of native-style sales records appended to one recipe.
    pub fn recipe_sales(&self, recipe_id: u32) -> u32 {
        self.recipe_sales
            .iter()
            .find(|(id, _)| *id == recipe_id)
            .map(|(_, records)| *records)
            .unwrap_or(0)
    }

    /// Native payment event: credit the order revenue after the cashier path.
    pub fn credit_payment(&mut self, sale: &Sale) {
        self.cash += sale.cash_delta;
    }

    pub fn set_clock_minutes(&mut self, clock_minutes: u32) {
        self.clock_minutes = clock_minutes;
    }

    pub fn from_snapshot(snapshot: &Snapshot) -> Self {
        Self {
            open: snapshot.open,
            price: snapshot.price,
            cash: snapshot.cash,
            starting_cash: snapshot.cash,
            stock: snapshot.stock,
            stock_capacity: snapshot.stock_capacity,
            servings_per_sale: 1,
            stock_units_per_serving: 1.0,
            market_factor: MARKET_PRICE_FACTOR,
            clock_minutes: snapshot.clock_minutes,
            servings_sold: snapshot.servings_sold,
            customers_served: snapshot.customers_served,
            customers_lost: snapshot.customers_lost,
            sales: snapshot.sales,
            recipe_sales: Vec::new(),
            steps: snapshot.steps,
            last_sale: snapshot.last_sale.clone(),
        }
    }

    pub fn apply(&mut self, command: Command) -> StepOutcome {
        match command {
            Command::SetOpen(open) => {
                self.set_open(open);
                StepOutcome::Closed
            }
            Command::SetPrice(price) => {
                self.set_price(price);
                StepOutcome::Closed
            }
            Command::Step => self.step(),
        }
    }

    pub fn snapshot_json(&self) -> String {
        let snapshot = self.snapshot();
        let last = snapshot
            .last_sale
            .as_ref()
            .map(sale_json)
            .unwrap_or_else(|| "null".to_string());
        format!(
            "{{\"open\":{},\"price\":{:.6},\"cash\":{:.6},\"stock\":{:.6},\"stock_capacity\":{:.6},\"clock_minutes\":{},\"servings_sold\":{},\"customers_served\":{},\"customers_lost\":{},\"sales\":{},\"steps\":{},\"last_sale\":{}}}",
            snapshot.open,
            snapshot.price,
            snapshot.cash,
            snapshot.stock,
            snapshot.stock_capacity,
            snapshot.clock_minutes,
            snapshot.servings_sold,
            snapshot.customers_served,
            snapshot.customers_lost,
            snapshot.sales,
            snapshot.steps,
            last
        )
    }

    pub fn cash_delta(&self) -> f64 {
        self.cash - self.starting_cash
    }
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Command {
    SetOpen(bool),
    SetPrice(f64),
    Step,
}

fn sale_json(sale: &Sale) -> String {
    format!(
        "{{\"clock_minutes\":{},\"recipe_id\":{},\"price\":{:.6},\"servings\":{},\"revenue\":{:.6},\"stock_cost\":{:.6},\"market_cost\":{:.6},\"cash_delta\":{:.6}}}",
        sale.clock_minutes,
        sale.recipe_id,
        sale.price,
        sale.servings,
        sale.revenue,
        sale.stock_cost,
        sale.market_cost,
        sale.cash_delta
    )
}

/// Player/company choices carried from the character-selection screen into
/// the running branch world.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum GameMode {
    Campaign,
    FreeGame,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct CharacterProfile {
    pub mode: GameMode,
    pub gender: u8,
    pub head: u8,
    pub eyes: u8,
    pub hair: u8,
    pub mouth: u8,
    pub logo: u8,
    pub color: u8,
    pub difficulty: u8,
    pub attributes: [i32; 6],
    pub player_name: String,
    pub enterprise_name: String,
}

impl CharacterProfile {
    #[allow(clippy::too_many_arguments)]
    pub fn new(
        gender: u8,
        head: u8,
        eyes: u8,
        hair: u8,
        mouth: u8,
        logo: u8,
        color: u8,
        difficulty: u8,
        attributes: [i32; 6],
        player_name: String,
        enterprise_name: String,
    ) -> Self {
        Self {
            mode: GameMode::Campaign,
            gender,
            head,
            eyes,
            hair,
            mouth,
            logo,
            color,
            difficulty,
            attributes,
            player_name,
            enterprise_name,
        }
    }

    pub fn with_mode(mut self, mode: GameMode) -> Self {
        self.mode = mode;
        self
    }
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct CampaignBranch {
    pub owner_slot: u8,
    pub size: u8,
    pub style: u8,
    pub owned: bool,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct CampaignMission {
    pub starting_cash: u32,
    pub difficulty_percent: u32,
    pub goal_ids: Vec<u32>,
    pub rival_count: u8,
    pub player_start_hq: u32,
    pub rival_start_hq: u32,
    pub starting_branches: Vec<CampaignBranch>,
    pub property_offer: Option<CampaignPropertyOffer>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct CampaignPropertyOffer {
    pub tile_index: u32,
    pub price: u32,
    /// One-time notary/lease fee charged with the first month's rent.
    pub fee: u32,
}

/// A headquarters expansion started from the city expansion page.  The level
/// is awarded when `complete_minute` is reached, not when the order is placed.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct HeadquartersProject {
    pub target_level: u32,
    pub site_tile: u32,
    pub cost: u32,
    pub complete_minute: u32,
}

/// A courier order carrying rats to the rival restaurant.  Mission state slot
/// 1 is written when the courier reaches the branch, not when it is dispatched.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct RatDelivery {
    pub target_branch: u32,
    pub cost: u32,
    pub complete_minute: u32,
}

impl CampaignPropertyOffer {
    pub fn total_cost(self) -> u32 {
        self.price.saturating_add(self.fee)
    }
}

/// The launch values committed by `Screen_FreePlaySetup` / the Start handler
/// at `0x4cd33d..0x4cd4cc`. The selected city record's `+0x40` short name is
/// copied to `DAT_0057bb44`; `DAT_0057bb28` is the population, `DAT_0057bb2c`
/// the game length, and `DAT_0057bb48/4c/50` are the three opponent slots.
#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct ScenarioSetup {
    pub mode: GameMode,
    pub city_code: String,
    pub city_name: String,
    pub map_name: String,
    pub population: u32,
    pub game_length_years: u32,
    pub opponents: [i32; 3],
    ownership_percent: u32,
    pub campaign_mission: Option<CampaignMission>,
}

/// `Settings_InitDefaults` (`0x406a90`) plus the first `daten/*.ini` entry
/// (`ber.ini`, short name `ber`). Those are the defaults Free Play Setup
/// commits when the screen is accepted without changing a control.
pub const FREE_PLAY_POPULATION: u32 = 250;
pub const FREE_PLAY_GAME_LENGTH: u32 = 11;
pub const BERLIN_START_CAPITAL: u32 = 70_000;
const DEFAULT_OWNERSHIP_PERCENT: u32 = 100;

impl ScenarioSetup {
    pub fn free_play_berlin() -> Self {
        Self {
            mode: GameMode::FreeGame,
            city_code: "ber".into(),
            city_name: "Berlin".into(),
            map_name: "Ber.iso".into(),
            population: FREE_PLAY_POPULATION,
            game_length_years: FREE_PLAY_GAME_LENGTH,
            opponents: [-1, -1, -1],
            ownership_percent: DEFAULT_OWNERSHIP_PERCENT,
            campaign_mission: None,
        }
    }

    pub fn campaign_berlin() -> Self {
        Self {
            mode: GameMode::Campaign,
            city_code: "ber".into(),
            city_name: "Berlin".into(),
            map_name: "Ber.iso".into(),
            population: 260,
            game_length_years: 3,
            opponents: [0, 1, -1],
            ownership_percent: DEFAULT_OWNERSHIP_PERCENT,
            campaign_mission: None,
        }
    }

    pub fn from_campaign_mission(
        city_code: String,
        city_name: String,
        population: u32,
        game_length_years: u32,
        mission: CampaignMission,
    ) -> Self {
        Self {
            mode: GameMode::Campaign,
            map_name: format!("{city_code}.iso"),
            city_code,
            city_name,
            population,
            game_length_years,
            opponents: [-1; 3],
            ownership_percent: DEFAULT_OWNERSHIP_PERCENT,
            campaign_mission: Some(mission),
        }
    }

    /// Free games derive the starting cash from difficulty through
    /// `Game_GetStartingCapital` (`0x48d3a0`) and the ownership percentage.
    /// Campaign games use the city's `STARTGELD` (`extracted/daten/ber.ini`: 70000).
    pub fn starting_capital(&self, difficulty: u8) -> u32 {
        match self.mode {
            GameMode::FreeGame => {
                starting_capital_with_ownership(difficulty, self.ownership_percent)
            }
            GameMode::Campaign => self
                .campaign_mission
                .as_ref()
                .map_or(BERLIN_START_CAPITAL, |mission| mission.starting_cash),
        }
    }

    /// Encode the standalone scenario override shared by Free Play and replay.
    /// Installed campaign missions are stored directly in the world snapshot.
    pub fn encode(&self) -> String {
        format!(
            "mode={};city={};name={};map={};population={};length={};opponents={};ownership_percent={}",
            if self.mode == GameMode::FreeGame {
                "free"
            } else {
                "campaign"
            },
            self.city_code,
            self.city_name,
            self.map_name,
            self.population,
            self.game_length_years,
            self.opponents
                .iter()
                .map(i32::to_string)
                .collect::<Vec<_>>()
                .join(","),
            self.ownership_percent,
        )
    }

    pub fn decode(value: &str) -> Result<Self, String> {
        let mut setup = Self::free_play_berlin();
        for item in value.split(';') {
            let Some((key, raw)) = item.split_once('=') else {
                continue;
            };
            let number = |raw: &str| {
                raw.parse::<u32>()
                    .map_err(|_| format!("invalid scenario value: {raw}"))
            };
            match key {
                "mode" => {
                    setup.mode = if raw == "free" {
                        GameMode::FreeGame
                    } else {
                        GameMode::Campaign
                    }
                }
                "city" => setup.city_code = raw.to_string(),
                "name" => setup.city_name = raw.to_string(),
                "map" => setup.map_name = raw.to_string(),
                "population" => setup.population = number(raw)?,
                "length" => setup.game_length_years = number(raw)?,
                "ownership_percent" => {
                    let percent = number(raw)?;
                    if !(70..=990).contains(&percent) {
                        return Err(format!(
                            "ownership_percent must be between 70 and 990: {raw}"
                        ));
                    }
                    setup.ownership_percent = percent;
                }
                "opponents" => {
                    let mut opponents = [-1; 3];
                    for (slot, value) in opponents.iter_mut().zip(raw.split(',')) {
                        *slot = value
                            .parse::<i32>()
                            .map_err(|_| format!("invalid scenario opponent: {value}"))?;
                    }
                    setup.opponents = opponents;
                }
                _ => {}
            }
        }
        Ok(setup)
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum VisitState {
    Idle,
    Waiting,
    Producing,
    Departing,
}

/// Per-party state for the one-slot queue model.
///
/// `Object_UpdateCustomerQueue` (`0x409d80`) holds queued parties outside the
/// active service slot, then `0x409c60`/`0x409d40` move the next queued party
/// onto the target once `0x409bb0`/`0x409b10` can claim it again.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum CustomerPhase {
    Queued,
    Waiting,
    Producing,
    Departing,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct Customer {
    pub id: u32,
    pub party_size: u32,
    pub phase: CustomerPhase,
    pub slot: Option<u32>,
    pub arrived_minute: u32,
    pub phase_started: u32,
    pub timer_ticks: u32,
}

/// Native employee role codes used by `Company_AssignEmployee`.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum EmployeeRole {
    Cook = 0,
    Service = 2,
    Errand = 3,
}

impl EmployeeRole {
    pub fn parse(value: &str) -> Result<Self, &'static str> {
        match value {
            "0" | "cook" => Ok(Self::Cook),
            "2" | "service" => Ok(Self::Service),
            "3" | "errand" => Ok(Self::Errand),
            _ => Err("unknown employee role"),
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct EmployeeCandidate {
    pub id: u32,
    pub role: EmployeeRole,
}

/// Candidate IDs observed in the lifted London staffing replay.
pub const CAMPAIGN_EMPLOYEE_CANDIDATES: [EmployeeCandidate; 4] = [
    EmployeeCandidate {
        id: 100_280,
        role: EmployeeRole::Cook,
    },
    EmployeeCandidate {
        id: 100_300,
        role: EmployeeRole::Service,
    },
    EmployeeCandidate {
        id: 100_310,
        role: EmployeeRole::Errand,
    },
    EmployeeCandidate {
        id: 100_312,
        role: EmployeeRole::Errand,
    },
];

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct Employee {
    pub id: u32,
    pub role: EmployeeRole,
    pub owner_slot: u8,
    pub branch_id: u32,
}

/// A player-created pizza. Stock use is `(tomato + cheese) * servings`.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Recipe {
    pub id: u32,
    pub name: String,
    pub tomato: u32,
    pub cheese: u32,
    pub price: f64,
    pub on_menu: bool,
}

/// A branch owned or rented by the current player. The first London lease
/// creates one of these; the mission goal evaluator reads the player branch
/// count (`Game_GetPlayerFieldC20`, `0x4e2280`) and the owned-branch flag
/// (`Game_CountRecordsWithFlag16F4`, `0x4de710`).
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct PlayerBranch {
    pub branch_id: u32,
    pub tile_index: u32,
    pub owner_slot: u8,
    pub staff_count: u32,
    pub size: u8,
    pub style: u8,
    pub owned: bool,
    pub player_controlled: bool,
    pub rent: u32,
    pub sales: u32,
    pub revenue: f64,
    pub employees: Vec<Employee>,
    pub warehouse_id: Option<u32>,
    pub warehouse_name: Option<String>,
    pub supplier: Option<String>,
    pub warehouse_capacity: f64,
    pub deliveries_enabled: bool,
    pub route_branch_id: Option<u32>,
    pub delivery_due_hour: Option<u8>,
    pub delivery_batch: f64,
    pub opening_hours: Option<(u8, u8)>,
    pub recipes: Vec<Recipe>,
    pub menu_recipe: Option<u32>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum GoalStatus {
    Pending,
    Complete,
    Failed,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub struct MissionGoalState {
    pub id: u32,
    pub status: GoalStatus,
    pub progress: u32,
    pub target: u32,
    pub description: String,
}

#[derive(Clone, Debug, PartialEq)]
pub enum ClockEvent {
    Tick {
        minute: u32,
    },
    Hourly {
        minute: u32,
        hour: u32,
        hour_index: u32,
    },
    Phase(&'static str),
    Arrival {
        minute: u32,
        queue: u32,
    },
    ProductionStart {
        minute: u32,
    },
    QueueService {
        minute: u32,
        remaining_queue: u32,
    },
    Sale {
        minute: u32,
        stock: f64,
        cash_delta: f64,
    },
    Departure {
        minute: u32,
    },
    HeadquartersComplete {
        minute: u32,
        level: u32,
    },
    RatDelivered {
        minute: u32,
        count: u32,
    },
    QuarterBoundary {
        minute: u32,
        hour: u32,
    },
}

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct WorldSnapshot {
    pub minute: u32,
    pub queue: u32,
    pub hourly_count: u32,
    pub visit_state: VisitState,
    pub state_started: u32,
    pub customers: Vec<Customer>,
    pub queue_capacity: u32,
    pub player_branches: Vec<PlayerBranch>,
    pub mission_goals: Vec<MissionGoalState>,
    pub mission_complete: bool,
    pub hq_level: u32,
    pub rats_placed: u32,
    pub hq_project: Option<HeadquartersProject>,
    pub rat_delivery: Option<RatDelivery>,
    pub profile: Option<CharacterProfile>,
    pub scenario: Option<ScenarioSetup>,
    pub leased_property: Option<u32>,
    pub sim: Snapshot,
}

/// Authoritative headless world: one five-minute clock, one scripted customer
/// visit and the branch economy. The viewer and CLI use this same object.
#[derive(Clone, Debug)]
pub struct World {
    minute: u32,
    queue: u32,
    hourly_count: u32,
    visit_state: VisitState,
    state_started: u32,
    next_customer_id: u32,
    customers: Vec<Customer>,
    queue_capacity: u32,
    player_branches: Vec<PlayerBranch>,
    mission_goals: Vec<MissionGoalState>,
    mission_complete: bool,
    hq_level: u32,
    rats_placed: u32,
    hq_project: Option<HeadquartersProject>,
    rat_delivery: Option<RatDelivery>,
    profile: Option<CharacterProfile>,
    scenario: Option<ScenarioSetup>,
    leased_property: Option<u32>,
    sim: BranchSim,
}

impl World {
    pub fn new(start_minute: u32) -> Self {
        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.set_clock_minutes(start_minute);
        Self {
            minute: start_minute,
            queue: 0,
            hourly_count: 0,
            visit_state: VisitState::Idle,
            state_started: start_minute,
            next_customer_id: 1,
            customers: Vec::new(),
            queue_capacity: QUEUE_CAPACITY,
            player_branches: Vec::new(),
            mission_goals: Vec::new(),
            mission_complete: false,
            hq_level: 0,
            rats_placed: 0,
            hq_project: None,
            rat_delivery: None,
            profile: None,
            scenario: None,
            leased_property: None,
            sim,
        }
    }

    /// Focused customer-visit fixture derived from the native London save.
    pub fn london_checkpoint() -> Self {
        let mut world = Self::new(LONDON_CHECKPOINT_MINUTE);
        world.sim.set_starting_cash(LONDON_ORDER_CASH_BEFORE);
        world.sim.set_stock(LONDON_PRE_ORDER_STOCK);
        world.sim.set_stock_capacity(LONDON_PRE_ORDER_STOCK);
        world.sim.set_price(LONDON_ORDER_PRICE);
        world.sim.set_order_profile(
            LONDON_ORDER_SERVINGS,
            LONDON_ORDER_STOCK_DROP / LONDON_ORDER_SERVINGS as f64,
            0.0,
        );
        world.sim.set_open(true);
        world.next_customer_id = LONDON_FIRST_CUSTOMER_ID;
        world.player_branches.push(PlayerBranch {
            branch_id: LONDON_BRANCH_ID,
            tile_index: 0,
            owner_slot: LONDON_PLAYER_SLOT,
            staff_count: LONDON_STAFF_COUNT,
            size: 0,
            style: 0,
            owned: true,
            player_controlled: true,
            rent: 0,
            sales: 0,
            revenue: 0.0,
            employees: CAMPAIGN_EMPLOYEE_CANDIDATES
                .iter()
                .map(|candidate| Employee {
                    id: candidate.id,
                    role: candidate.role,
                    owner_slot: LONDON_PLAYER_SLOT,
                    branch_id: LONDON_BRANCH_ID,
                })
                .collect(),
            warehouse_id: None,
            warehouse_name: None,
            supplier: None,
            warehouse_capacity: 0.0,
            deliveries_enabled: false,
            route_branch_id: None,
            delivery_due_hour: None,
            delivery_batch: 200_000.0,
            opening_hours: None,
            recipes: Vec::new(),
            menu_recipe: None,
        });
        world
    }

    /// A New Game campaign starts with no player branch, no employees, and an
    /// empty pantry. The lease and later preparation steps supply them.
    pub fn prepare_campaign_new_game(&mut self) {
        if self.campaign_mission().is_none() {
            return;
        }
        self.sim.set_stock(0.0);
        self.sim.set_stock_capacity(0.0);
        self.sim.set_open(false);
        self.leased_property = None;
        self.player_branches
            .retain(|branch| !branch.player_controlled);
    }

    pub fn with_profile(mut self, profile: CharacterProfile) -> Self {
        self.profile = Some(profile);
        self.apply_starting_capital();
        self
    }

    pub fn with_scenario(mut self, scenario: ScenarioSetup) -> Self {
        self.scenario = Some(scenario);
        if !self.can_enter_branch() {
            self.sim.set_open(false);
        }
        self.apply_starting_capital();
        self.reset_mission_goals();
        self
    }

    pub fn profile(&self) -> Option<&CharacterProfile> {
        self.profile.as_ref()
    }

    pub fn scenario(&self) -> Option<&ScenarioSetup> {
        self.scenario.as_ref()
    }

    fn campaign_mission(&self) -> Option<&CampaignMission> {
        self.scenario.as_ref()?.campaign_mission.as_ref()
    }

    pub fn player_branches(&self) -> &[PlayerBranch] {
        &self.player_branches
    }

    pub fn player_branch_count(&self) -> u32 {
        self.player_branches.len() as u32
    }

    pub fn mission_goals(&self) -> &[MissionGoalState] {
        &self.mission_goals
    }

    pub fn mission_complete(&self) -> bool {
        self.mission_complete
    }

    pub fn hq_level(&self) -> u32 {
        self.hq_level
    }

    pub fn rats_placed(&self) -> u32 {
        self.rats_placed
    }

    pub fn mission_summary(&self) -> Option<String> {
        let mission = self.campaign_mission()?;
        let completed = self
            .mission_goals
            .iter()
            .filter(|goal| goal.status == GoalStatus::Complete)
            .count();
        let city = self
            .scenario
            .as_ref()
            .map_or("MISSION", |scenario| scenario.city_name.as_str());
        let hq = match self.hq_project {
            Some(project) => format!(
                "HQ {}/3 (+{}h)",
                self.hq_level,
                project.complete_minute.saturating_sub(self.minute) / 60
            ),
            None => format!("HQ {}/3", self.hq_level),
        };
        let rat = match self.rat_delivery {
            Some(delivery) => format!(
                "RAT {}/1 (+{}m)",
                self.rats_placed,
                delivery.complete_minute.saturating_sub(self.minute)
            ),
            None => format!("RAT {}/1", self.rats_placed),
        };
        Some(format!(
            "MISSION: {}   GOALS {}/{}   {}   {}   BRANCHES {}",
            city.to_ascii_uppercase(),
            completed,
            mission.goal_ids.len(),
            hq,
            rat,
            self.player_branch_count()
        ))
    }

    pub fn mission_goal_text(&self) -> Option<String> {
        let goals = self
            .mission_goals
            .iter()
            .map(|goal| {
                let status = match goal.status {
                    GoalStatus::Pending => " ",
                    GoalStatus::Complete => "X",
                    GoalStatus::Failed => "!",
                };
                format!(
                    "[{}] {} ({}/{})",
                    status, goal.description, goal.progress, goal.target
                )
            })
            .collect::<Vec<_>>()
            .join("   ");
        (!goals.is_empty()).then_some(goals)
    }

    pub fn mission_sales(&self) -> u32 {
        self.player_branches.iter().map(|branch| branch.sales).sum()
    }

    fn record_branch_sale(&mut self, sale: &Sale) {
        if let Some(branch) = self.player_branches.first_mut() {
            branch.sales += sale.servings;
            branch.revenue += sale.revenue;
        }
        self.evaluate_mission_goals();
    }

    fn reset_mission_goals(&mut self) {
        let goal_ids = self
            .campaign_mission()
            .map_or_else(Vec::new, |mission| mission.goal_ids.clone());
        self.mission_goals = goal_ids
            .into_iter()
            .map(|id| {
                // Mission_EvaluateGoals (0x4f5fd0) reads:
                //   0: Game_GetPlayerFieldC20(player) > 2  (HQ level 3)
                //   1: mission-state +0x14 > 0           (rat delivered)
                //   2: Game_CountRecordsWithFlag16F4 != 0 (owned/leased branch)
                // Unicorn probe: tools/emulate_mission_goals.py.
                let (target, description) = match id {
                    0 => (3, "Build HQ level 3".to_string()),
                    1 => (1, "Rat a rival branch".to_string()),
                    2 => (1, "Own a branch".to_string()),
                    other => (1, format!("Mission goal {other}")),
                };
                MissionGoalState {
                    id,
                    status: GoalStatus::Pending,
                    progress: 0,
                    target,
                    description,
                }
            })
            .collect();
        self.mission_complete = false;
        self.evaluate_mission_goals();
    }

    fn evaluate_mission_goals(&mut self) {
        if self.mission_goals.is_empty() {
            self.mission_complete = false;
            return;
        }
        let owned_count = self
            .player_branches
            .iter()
            .filter(|branch| branch.player_controlled)
            .count() as u32;
        for goal in &mut self.mission_goals {
            goal.progress = match goal.id {
                0 => self.hq_level,
                1 => self.rats_placed,
                2 => owned_count,
                _ => goal.progress,
            };
            goal.status = if goal.progress >= goal.target {
                GoalStatus::Complete
            } else {
                GoalStatus::Pending
            };
        }
        self.mission_complete = self
            .mission_goals
            .iter()
            .all(|goal| goal.status == GoalStatus::Complete);
    }

    pub fn campaign_property_offer(&self) -> Option<CampaignPropertyOffer> {
        self.campaign_mission()?.property_offer
    }

    /// The real London headquarters plot.  The city view uses the same tile
    /// constant when it draws the marker, so the panel cannot drift to an
    /// offset from Atrium.
    pub fn hq_site_tile(&self) -> Option<u32> {
        self.campaign_mission().map(|_| LONDON_HQ_TILE)
    }

    /// The rival restaurant selected by the rat order.
    pub fn rival_branch_id(&self) -> Option<u32> {
        (self.campaign_mission()?.rival_count > 0).then_some(LONDON_RIVAL_BRANCH_ID)
    }

    pub fn hq_project(&self) -> Option<HeadquartersProject> {
        self.hq_project
    }

    pub fn rat_delivery(&self) -> Option<RatDelivery> {
        self.rat_delivery
    }

    /// Quote the next headquarters stage from `CompanyInfo_FillActions`
    /// (`0x4a2a10`).  The expansion page shows this value before the player
    /// confirms.
    pub fn hq_expansion_cost(&self) -> Option<u32> {
        if self.campaign_mission().is_none() || self.hq_level >= 3 {
            return None;
        }
        HQ_EXPANSION_COSTS.get(self.hq_level as usize).copied()
    }

    /// Start the shipped headquarters expansion action.  The level is awarded
    /// by `City_TickSimulation` (`0x4d8d50`, case `0x1c`) when construction
    /// completes; placing the order only debits the quote and records the
    /// completion minute.
    pub fn start_hq_construction(
        &mut self,
        site_tile: u32,
    ) -> Result<HeadquartersProject, &'static str> {
        if self.campaign_mission().is_none() {
            return Err("headquarters missions require a campaign");
        }
        if self.hq_project.is_some() {
            return Err("headquarters construction is already in progress");
        }
        if self.hq_level >= 3 {
            return Err("headquarters is already level 3");
        }
        if site_tile != LONDON_HQ_TILE {
            return Err("headquarters must be built on the designated plot");
        }
        let cost = self
            .hq_expansion_cost()
            .ok_or("headquarters is already level 3")?;
        let charge = f64::from(cost);
        if self.sim.cash < charge {
            return Err("insufficient funds");
        }
        self.sim.cash -= charge;
        let project = HeadquartersProject {
            target_level: self.hq_level + 1,
            site_tile,
            cost,
            complete_minute: self.minute + HQ_CONSTRUCTION_MINUTES,
        };
        self.hq_project = Some(project);
        Ok(project)
    }

    /// Dispatch a courier with rats to the actual rival restaurant.  The
    /// mission slot is written on arrival by `Object_UpdateBranchOpenClose`
    /// (`0x408a70`, case 3), matching the shipped annoyances page.
    pub fn dispatch_rats(&mut self, target_branch: u32) -> Result<RatDelivery, &'static str> {
        let mission = self
            .campaign_mission()
            .ok_or("rat deliveries require a campaign")?;
        if mission.rival_count == 0 {
            return Err("there is no rival branch");
        }
        if self.hq_level < 3 {
            return Err("headquarters level 3 is required for couriers");
        }
        if self.rat_delivery.is_some() {
            return Err("a rat delivery is already on the way");
        }
        if target_branch != LONDON_RIVAL_BRANCH_ID {
            return Err("rats must be sent to the rival branch");
        }
        let charge = f64::from(RAT_DELIVERY_COST);
        if self.sim.cash < charge {
            return Err("insufficient funds");
        }
        self.sim.cash -= charge;
        let delivery = RatDelivery {
            target_branch,
            cost: RAT_DELIVERY_COST,
            complete_minute: self.minute + RAT_DELIVERY_MINUTES,
        };
        self.rat_delivery = Some(delivery);
        Ok(delivery)
    }

    /// Apply any construction/delivery whose completion minute has passed.
    /// This is the single clock path used by the headless replay and the UI.
    fn complete_campaign_projects(&mut self) -> Vec<ClockEvent> {
        let mut events = Vec::new();
        if let Some(project) = self.hq_project {
            if self.minute >= project.complete_minute {
                self.hq_project = None;
                self.hq_level = project.target_level;
                self.evaluate_mission_goals();
                events.push(ClockEvent::HeadquartersComplete {
                    minute: self.minute,
                    level: self.hq_level,
                });
            }
        }
        if let Some(delivery) = self.rat_delivery {
            if self.minute >= delivery.complete_minute {
                self.rat_delivery = None;
                self.rats_placed += 1;
                self.evaluate_mission_goals();
                events.push(ClockEvent::RatDelivered {
                    minute: self.minute,
                    count: self.rats_placed,
                });
            }
        }
        events
    }

    pub fn can_enter_branch(&self) -> bool {
        self.campaign_mission().is_none() || self.leased_property.is_some()
    }

    pub fn lease_campaign_property(&mut self, tile_index: u32) -> Result<u32, &'static str> {
        let offer = self
            .campaign_property_offer()
            .filter(|offer| offer.tile_index == tile_index)
            .ok_or("property is unavailable")?;
        if self.leased_property.is_some() {
            return Err("property is already leased");
        }
        let total = offer.total_cost();
        let cost = f64::from(total);
        if self.sim.cash < cost {
            return Err("insufficient funds");
        }
        self.sim.cash -= cost;
        self.sim.set_stock(0.0);
        self.sim.set_stock_capacity(0.0);
        self.leased_property = Some(tile_index);
        self.player_branches.push(PlayerBranch {
            branch_id: LONDON_BRANCH_ID,
            tile_index,
            owner_slot: LONDON_PLAYER_SLOT,
            staff_count: 0,
            size: 0,
            style: 0,
            owned: false,
            player_controlled: true,
            rent: offer.price,
            sales: 0,
            revenue: 0.0,
            employees: Vec::new(),
            warehouse_id: None,
            warehouse_name: None,
            supplier: None,
            warehouse_capacity: 0.0,
            deliveries_enabled: false,
            route_branch_id: None,
            delivery_due_hour: None,
            delivery_batch: 200_000.0,
            opening_hours: None,
            recipes: Vec::new(),
            menu_recipe: None,
        });
        self.evaluate_mission_goals();
        Ok(total)
    }

    fn campaign_branch_mut(&mut self) -> Option<&mut PlayerBranch> {
        self.player_branches
            .iter_mut()
            .find(|branch| branch.player_controlled)
    }

    pub fn campaign_branch(&self) -> Option<&PlayerBranch> {
        self.player_branches
            .iter()
            .find(|branch| branch.player_controlled)
    }

    pub fn campaign_employee_candidates() -> &'static [EmployeeCandidate] {
        &CAMPAIGN_EMPLOYEE_CANDIDATES
    }

    pub fn hire_campaign_candidate(&mut self, candidate_id: u32) -> Result<Employee, &'static str> {
        let candidate = CAMPAIGN_EMPLOYEE_CANDIDATES
            .iter()
            .find(|candidate| candidate.id == candidate_id)
            .copied()
            .ok_or("employee is unavailable")?;
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        if branch
            .employees
            .iter()
            .any(|employee| employee.id == candidate_id)
        {
            return Err("employee is already assigned");
        }
        let employee = Employee {
            id: candidate.id,
            role: candidate.role,
            owner_slot: branch.owner_slot,
            branch_id: branch.branch_id,
        };
        branch.employees.push(employee.clone());
        branch.staff_count = branch.employees.len() as u32;
        Ok(employee)
    }

    pub fn hire_campaign_employee(&mut self, role: EmployeeRole) -> Result<u32, &'static str> {
        let hired: Vec<u32> = self
            .campaign_branch()
            .map(|branch| {
                branch
                    .employees
                    .iter()
                    .map(|employee| employee.id)
                    .collect()
            })
            .unwrap_or_default();
        let candidate = CAMPAIGN_EMPLOYEE_CANDIDATES
            .iter()
            .find(|candidate| candidate.role == role && !hired.contains(&candidate.id))
            .copied()
            .ok_or("employee is unavailable")?;
        self.hire_campaign_candidate(candidate.id)?;
        Ok(self
            .campaign_branch()
            .map_or(0, |branch| branch.staff_count))
    }

    pub fn create_campaign_recipe(
        &mut self,
        tomato: u32,
        cheese: u32,
    ) -> Result<Recipe, &'static str> {
        if tomato == 0 || cheese == 0 {
            return Err("place tomato and cheese first");
        }
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        let id = 100_000 + branch.recipes.len() as u32 + 1;
        let recipe = Recipe {
            id,
            name: "Tomato & Cheese".into(),
            tomato,
            cheese,
            price: 12.0,
            on_menu: false,
        };
        branch.recipes.push(recipe.clone());
        Ok(recipe)
    }

    pub fn campaign_recipe(&self) -> Option<&Recipe> {
        self.campaign_branch()
            .and_then(|branch| branch.recipes.last())
    }

    pub fn campaign_menu_recipe(&self) -> Option<&Recipe> {
        let branch = self.campaign_branch()?;
        let id = branch.menu_recipe?;
        branch.recipes.iter().find(|recipe| recipe.id == id)
    }

    pub fn set_campaign_recipe_price(&mut self, price: f64) -> Result<f64, &'static str> {
        if !price.is_finite() || price <= 0.0 {
            return Err("invalid recipe price");
        }
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        let recipe = branch.recipes.last_mut().ok_or("save a recipe first")?;
        recipe.price = price.clamp(0.01, 999.99);
        let price = recipe.price;
        self.sim.set_price(price);
        Ok(price)
    }

    pub fn add_campaign_recipe_to_menu(&mut self) -> Result<u32, &'static str> {
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        let recipe = branch.recipes.last_mut().ok_or("save a recipe first")?;
        recipe.on_menu = true;
        let id = recipe.id;
        let price = recipe.price;
        branch.menu_recipe = Some(id);
        self.sim.set_price(price);
        Ok(id)
    }

    /// Lease the lifted `London 1` storage. Its save record is storage ID
    /// `100000`; the storage fill target is 400,000 units.
    pub fn lease_campaign_warehouse(&mut self, storage_id: u32) -> Result<(), &'static str> {
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        if branch.warehouse_id.is_some() {
            return Err("warehouse is already leased");
        }
        if storage_id != 100_000 {
            return Err("warehouse is unavailable");
        }
        branch.warehouse_id = Some(storage_id);
        branch.warehouse_name = Some("London 1".into());
        branch.warehouse_capacity = 400_000.0;
        Ok(())
    }

    /// Select the lifted supplier `Central Market Partners` for `London 1`.
    pub fn assign_campaign_supplier(&mut self, supplier: &str) -> Result<(), &'static str> {
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        if branch.warehouse_id.is_none() {
            return Err("lease a warehouse first");
        }
        if supplier != "central-market" && supplier != "Central Market Partners" {
            return Err("supplier is unavailable");
        }
        branch.supplier = Some("Central Market Partners".into());
        Ok(())
    }

    /// Enable the single Atrium route. The first 200,000-unit batch is due at
    /// the lifted 09:00 dispatch; stock remains zero until then.
    pub fn enable_campaign_deliveries(&mut self) -> Result<(), &'static str> {
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        if branch.warehouse_id.is_none() {
            return Err("lease a warehouse first");
        }
        if branch.supplier.is_none() {
            return Err("assign a supplier first");
        }
        if branch.deliveries_enabled {
            return Err("route is already enabled");
        }
        let branch_id = branch.branch_id;
        branch.deliveries_enabled = true;
        branch.route_branch_id = Some(branch_id);
        branch.delivery_due_hour = Some(9);
        Ok(())
    }

    fn receive_campaign_delivery(&mut self, hour: u8) -> bool {
        let Some((batch, capacity)) = self.campaign_branch().and_then(|branch| {
            (branch.deliveries_enabled
                && branch.supplier.is_some()
                && branch.delivery_due_hour == Some(hour))
            .then_some((branch.delivery_batch.max(0.0), branch.warehouse_capacity))
        }) else {
            return false;
        };
        let current = self.sim.snapshot().stock;
        let stock = current + batch;
        self.sim.set_stock(stock);
        if stock > self.sim.snapshot().stock_capacity {
            self.sim.set_stock_capacity(stock.max(capacity));
        }
        if let Some(branch) = self.campaign_branch_mut() {
            branch.delivery_due_hour = None;
        }
        true
    }

    /// Receive one 200,000-unit batch immediately. Used by tests; the
    /// playable path calls this from the 09:00 hourly clock.
    pub fn deliver_campaign_stock(&mut self) -> Result<f64, &'static str> {
        let due = self
            .campaign_branch()
            .map(|branch| {
                if !branch.deliveries_enabled || branch.supplier.is_none() {
                    Err("enable deliveries first")
                } else {
                    Ok(branch.delivery_due_hour.unwrap_or(9))
                }
            })
            .unwrap_or(Err("lease the campaign property first"))?;
        self.receive_campaign_delivery(due);
        Ok(self.sim.snapshot().stock)
    }

    pub fn is_campaign(&self) -> bool {
        self.campaign_mission().is_some()
    }

    /// Move the campaign clock without advancing customer timers.
    pub fn set_minute(&mut self, minute: u32) {
        self.minute = minute;
        self.sim.set_clock_minutes(minute);
    }

    /// Campaign opening gate: staff, warehouse, deliveries, stock, and the
    /// configured opening window must all be present.
    pub fn set_campaign_open(&mut self, open: bool) -> Result<(), &'static str> {
        if !self.is_campaign() {
            self.set_open(open);
            return Ok(());
        }
        if open {
            let (staff, warehouse, deliveries, hours, stock) = {
                let branch = self
                    .campaign_branch()
                    .ok_or("lease the campaign property first")?;
                (
                    branch.staff_count,
                    branch.warehouse_id,
                    branch.deliveries_enabled,
                    branch.opening_hours,
                    self.sim.snapshot().stock,
                )
            };
            if staff == 0 {
                return Err("hire staff first");
            }
            if warehouse.is_none() {
                return Err("lease a warehouse first");
            }
            if !deliveries {
                return Err("enable deliveries first");
            }
            if stock <= 0.0 {
                return Err("deliver stock first");
            }
            if let Some((start, end)) = hours {
                let hour = ((self.minute / 60) % 24) as u8;
                if hour < start || hour >= end {
                    return Err("outside opening hours");
                }
            }
        }
        self.set_open(open);
        Ok(())
    }

    pub fn next_action_text(&self) -> String {
        let Some(branch) = self.campaign_branch() else {
            return "CITY: click the vacant storefront 13694 and confirm the lease".into();
        };
        if branch.staff_count == 0 {
            return "CITY: open Employment Office (E) and hire a cook".into();
        }
        if branch.warehouse_id.is_none() {
            return "CITY: open Supply Office (L) and lease London 1".into();
        }
        if branch.supplier.is_none() {
            return "SUPPLY: select Central Market Partners (S)".into();
        }
        if !branch.deliveries_enabled {
            return "SUPPLY: enable the Atrium route (R)".into();
        }
        if self.sim.snapshot().stock <= 0.0 {
            return "CLOCK: advance to 09:00 for the first 200,000-unit delivery".into();
        }
        if self.campaign_menu_recipe().is_none() {
            return "BRANCH: recipe editor (R), place tomato/cheese, save and add to menu".into();
        }
        if branch.opening_hours.is_none() || !self.sim.snapshot().open {
            return "BRANCH: set opening hours (H) and open (O)".into();
        }
        if let Some(project) = self.hq_project {
            let remaining = project.complete_minute.saturating_sub(self.minute);
            return format!(
                "CITY: headquarters level {} under construction at tile {} ({}h left)",
                project.target_level, project.site_tile, remaining
            );
        }
        if self.hq_level < 3 {
            let cost = self.hq_expansion_cost().unwrap_or(0);
            return format!(
                "CITY: select the HQ plot {LONDON_HQ_TILE} and expand (cost {cost}, {} hours)",
                HQ_CONSTRUCTION_MINUTES / 60
            );
        }
        if let Some(delivery) = self.rat_delivery {
            let remaining = delivery.complete_minute.saturating_sub(self.minute);
            return format!(
                "CITY: rats are on the way to branch {} ({}m left)",
                delivery.target_branch, remaining
            );
        }
        if !self.mission_complete() {
            return format!(
                "CITY: select rival branch {LONDON_RIVAL_BRANCH_ID} and send the rat courier (cost {RAT_DELIVERY_COST})"
            );
        }
        "MISSION COMPLETE: London is running".into()
    }

    pub fn branch_status_text(&self) -> String {
        if self.sim.snapshot().open {
            return "OPEN".into();
        }
        if let Some((start, end)) = self
            .campaign_branch()
            .and_then(|branch| branch.opening_hours)
        {
            let hour = ((self.minute / 60) % 24) as u8;
            if hour < start || hour >= end {
                return format!("CLOSED - HOURS {start:02}:00-{end:02}:00");
            }
        }
        "CLOSED".into()
    }

    pub fn set_campaign_opening_hours(
        &mut self,
        open_hour: u8,
        close_hour: u8,
    ) -> Result<(), &'static str> {
        if open_hour >= 24 || close_hour > 24 || open_hour >= close_hour {
            return Err("invalid opening hours");
        }
        let branch = self
            .campaign_branch_mut()
            .ok_or("lease the campaign property first")?;
        branch.opening_hours = Some((open_hour, close_hour));
        Ok(())
    }

    fn apply_starting_capital(&mut self) {
        let Some(profile) = self.profile.as_ref() else {
            return;
        };
        let cash = match self.scenario.as_ref() {
            Some(scenario) => scenario.starting_capital(profile.difficulty),
            None if profile.mode == GameMode::FreeGame => starting_capital(profile.difficulty),
            None => START_CASH as u32,
        };
        self.sim.set_starting_cash(cash as f64);
    }

    pub fn starting_capital(&self) -> f64 {
        let Some(profile) = self.profile.as_ref() else {
            return START_CASH;
        };
        match self.scenario.as_ref() {
            Some(scenario) => scenario.starting_capital(profile.difficulty) as f64,
            None if profile.mode == GameMode::FreeGame => {
                starting_capital(profile.difficulty) as f64
            }
            None => START_CASH,
        }
    }

    pub fn attribute_total(&self) -> Option<i32> {
        self.profile
            .as_ref()
            .map(|profile| profile.attributes.iter().sum())
    }

    /// `Game_InitCompanySlots` (`0x4f6e70`) calls
    /// `Random_RangeFast(difficulty * 6, difficulty * 9)` and stores the
    /// result in the company slot's short field at `+0x128`.
    pub fn company_slot_roll_range(&self) -> Option<(u32, u32)> {
        self.profile
            .as_ref()
            .map(|profile| (profile.difficulty as u32 * 6, profile.difficulty as u32 * 9))
    }

    /// Seed queued parties. The first party claims the single service slot and
    /// starts in `Waiting`; the rest remain `Queued` behind it.
    pub fn with_queue(mut self, queue: u32) -> Self {
        self.customers.clear();
        self.next_customer_id = 1;
        for _ in 0..queue.min(self.queue_capacity) {
            self.push_queued_party(1);
        }
        self.admit_next();
        self
    }

    /// Add one arriving party. This is the replay/CLI hook for the two-party
    /// fixture; automatic hourly arrivals use the same path.
    pub fn enqueue_party(&mut self, party_size: u32) -> u32 {
        if self.queue >= self.queue_capacity {
            self.sim.record_lost_customer();
            return 0;
        }
        let id = self.push_queued_party(party_size.max(1));
        self.admit_next();
        id
    }

    pub fn set_queue_capacity(&mut self, capacity: u32) -> Result<(), String> {
        if capacity == 0 {
            return Err("queue capacity must be greater than zero".into());
        }
        self.queue_capacity = capacity;
        Ok(())
    }

    pub fn queue_capacity(&self) -> u32 {
        self.queue_capacity
    }

    pub fn customers(&self) -> &[Customer] {
        &self.customers
    }

    pub fn active_customer(&self) -> Option<&Customer> {
        self.customers
            .iter()
            .find(|customer| customer.slot.is_some())
    }

    fn push_queued_party(&mut self, party_size: u32) -> u32 {
        let id = self.next_customer_id;
        self.next_customer_id += 1;
        self.customers.push(Customer {
            id,
            party_size,
            phase: CustomerPhase::Queued,
            slot: None,
            arrived_minute: self.minute,
            phase_started: self.minute,
            timer_ticks: 0,
        });
        self.sync_queue();
        id
    }

    /// `0x409c60`/`0x409d40` scan the queue for the next party while the
    /// single target slot is free; `0x409b10` is the claim that sets the
    /// target to state `0xb` and records its id on the customer at `+0x10c`.
    fn admit_next(&mut self) -> bool {
        if self.active_customer_index().is_some() {
            return false;
        }
        let Some(index) = self
            .customers
            .iter()
            .position(|customer| customer.phase == CustomerPhase::Queued)
        else {
            return false;
        };
        let customer = &mut self.customers[index];
        customer.phase = CustomerPhase::Waiting;
        customer.phase_started = self.minute;
        customer.slot = Some(0);
        customer.timer_ticks = QUEUE_WALK_TICKS;
        self.sync_queue();
        true
    }

    fn active_customer_index(&self) -> Option<usize> {
        self.customers
            .iter()
            .position(|customer| customer.slot.is_some())
    }

    fn queued_count(&self) -> u32 {
        self.customers
            .iter()
            .filter(|customer| customer.phase == CustomerPhase::Queued)
            .count() as u32
    }

    fn sync_queue(&mut self) {
        self.queue = self.customers.len() as u32;
        let active = self.active_customer_index().map(|index| {
            let customer = &self.customers[index];
            (customer.phase, customer.phase_started)
        });
        match active {
            Some((CustomerPhase::Waiting, started)) => {
                self.visit_state = VisitState::Waiting;
                self.state_started = started;
            }
            Some((CustomerPhase::Producing, started)) => {
                self.visit_state = VisitState::Producing;
                self.state_started = started;
            }
            Some((CustomerPhase::Departing, started)) => {
                self.visit_state = VisitState::Departing;
                self.state_started = started;
            }
            _ => {
                self.visit_state = VisitState::Idle;
                self.state_started = self.minute;
            }
        }
    }

    pub fn set_open(&mut self, open: bool) {
        self.sim.set_open(open && self.can_enter_branch());
    }

    pub fn set_price(&mut self, price: f64) {
        self.sim.set_price(price);
    }

    pub fn set_cash(&mut self, cash: f64) {
        self.sim.set_starting_cash(cash);
    }

    pub fn snapshot(&self) -> Snapshot {
        self.sim.snapshot()
    }

    pub fn snapshot_json(&self) -> String {
        self.sim.snapshot_json()
    }

    /// Queue/customer view used by the two-party replay evidence.
    pub fn queue_snapshot_json(&self) -> String {
        let customers = self
            .customers
            .iter()
            .map(|customer| {
                let phase = match customer.phase {
                    CustomerPhase::Queued => "queued",
                    CustomerPhase::Waiting => "waiting",
                    CustomerPhase::Producing => "producing",
                    CustomerPhase::Departing => "departing",
                };
                let slot = customer
                    .slot
                    .map_or_else(|| "null".to_string(), |slot| slot.to_string());
                format!(
                    "{{\"id\":{},\"party_size\":{},\"phase\":\"{}\",\"slot\":{},\"arrived_minute\":{},\"phase_started\":{},\"timer_ticks\":{}}}",
                    customer.id,
                    customer.party_size,
                    phase,
                    slot,
                    customer.arrived_minute,
                    customer.phase_started,
                    customer.timer_ticks
                )
            })
            .collect::<Vec<_>>()
            .join(",");
        let visit_state = match self.visit_state {
            VisitState::Idle => "idle",
            VisitState::Waiting => "waiting",
            VisitState::Producing => "producing",
            VisitState::Departing => "departing",
        };
        format!(
            "{{\"queue\":{},\"queue_capacity\":{},\"visit_state\":\"{}\",\"state_started\":{},\"customers\":[{}]}}",
            self.queue, self.queue_capacity, visit_state, self.state_started, customers
        )
    }

    pub fn sim(&self) -> &BranchSim {
        &self.sim
    }

    pub fn visit_state(&self) -> VisitState {
        self.visit_state
    }

    pub fn customer_visible(&self) -> bool {
        !matches!(self.visit_state, VisitState::Idle)
    }

    pub fn minute(&self) -> u32 {
        self.minute
    }

    pub fn world_snapshot(&self) -> WorldSnapshot {
        WorldSnapshot {
            minute: self.minute,
            queue: self.queue,
            hourly_count: self.hourly_count,
            visit_state: self.visit_state,
            state_started: self.state_started,
            customers: self.customers.clone(),
            queue_capacity: self.queue_capacity,
            player_branches: self.player_branches.clone(),
            mission_goals: self.mission_goals.clone(),
            mission_complete: self.mission_complete,
            hq_level: self.hq_level,
            rats_placed: self.rats_placed,
            hq_project: self.hq_project,
            rat_delivery: self.rat_delivery,
            profile: self.profile.clone(),
            scenario: self.scenario.clone(),
            leased_property: self.leased_property,
            sim: self.sim.snapshot(),
        }
    }

    pub fn from_snapshot(snapshot: &WorldSnapshot) -> Self {
        Self {
            minute: snapshot.minute,
            queue: snapshot.queue,
            hourly_count: snapshot.hourly_count,
            visit_state: snapshot.visit_state,
            state_started: snapshot.state_started,
            next_customer_id: snapshot
                .customers
                .iter()
                .map(|customer| customer.id)
                .max()
                .unwrap_or(0)
                + 1,
            customers: snapshot.customers.clone(),
            queue_capacity: snapshot.queue_capacity,
            player_branches: snapshot.player_branches.clone(),
            mission_goals: snapshot.mission_goals.clone(),
            mission_complete: snapshot.mission_complete,
            hq_level: snapshot.hq_level,
            rats_placed: snapshot.rats_placed,
            hq_project: snapshot.hq_project,
            rat_delivery: snapshot.rat_delivery,
            profile: snapshot.profile.clone(),
            scenario: snapshot.scenario.clone(),
            leased_property: snapshot.leased_property,
            sim: BranchSim::from_snapshot(&snapshot.sim),
        }
    }

    pub fn save_campaign(&self, path: &Path) -> Result<(), String> {
        let bytes =
            bincode::serialize(&self.world_snapshot()).map_err(|error| error.to_string())?;
        std::fs::write(path, bytes).map_err(|error| error.to_string())
    }

    pub fn load_campaign(path: &Path) -> Result<Self, String> {
        let bytes = std::fs::read(path).map_err(|error| error.to_string())?;
        let snapshot: WorldSnapshot =
            bincode::deserialize(&bytes).map_err(|error| error.to_string())?;
        Ok(Self::from_snapshot(&snapshot))
    }

    pub fn step(&mut self) -> Vec<ClockEvent> {
        self.advance_to(self.minute + 5)
    }

    /// Advance the original 10 ms queue/service timers without moving the
    /// five-minute game clock. This is the precise timer lane used by queue
    /// fixtures; `advance_to` keeps the existing five-minute phase cadence.
    fn settle_current_sale(&mut self) -> StepOutcome {
        if self.is_campaign() && self.campaign_branch().is_some() {
            let recipe = self.campaign_menu_recipe().cloned();
            let mut order = recipe.map_or(CAMPAIGN_LONDON_ORDER, |recipe| OrderInput {
                customer_id: CAMPAIGN_LONDON_ORDER.customer_id,
                minute: self.minute,
                menu_price: recipe.price,
                recipe_id: recipe.id,
                ingredient_units: recipe.tomato + recipe.cheese,
                servings: 100,
                rating: 66,
                tip_base: 32,
            });
            order.minute = self.minute;
            let outcome = self.sim.settle_order_input(&order);
            if let StepOutcome::Sale(sale) = &outcome {
                self.sim.credit_payment(sale);
            }
            outcome
        } else {
            self.sim.settle_sale_at(self.minute)
        }
    }

    pub fn advance_millis(&mut self, millis: u32) -> Vec<ClockEvent> {
        self.advance_queue_ticks(millis / TICK_MS)
    }

    pub fn advance_queue_ticks(&mut self, ticks: u32) -> Vec<ClockEvent> {
        let mut events = Vec::new();
        for _ in 0..ticks {
            let Some(index) = self.active_customer_index() else {
                self.admit_next();
                if self.active_customer_index().is_none() {
                    break;
                }
                continue;
            };
            let phase = self.customers[index].phase;
            if self.customers[index].timer_ticks > 0 {
                self.customers[index].timer_ticks -= 1;
            }
            if self.customers[index].timer_ticks != 0 {
                continue;
            }
            match phase {
                CustomerPhase::Waiting => {
                    self.customers[index].phase = CustomerPhase::Producing;
                    self.customers[index].phase_started = self.minute;
                    self.customers[index].timer_ticks = PRODUCTION_TICKS;
                    self.sync_queue();
                    events.push(ClockEvent::ProductionStart {
                        minute: self.minute,
                    });
                }
                CustomerPhase::Producing => {
                    let remaining = self.queued_count();
                    self.customers[index].phase = CustomerPhase::Departing;
                    self.customers[index].phase_started = self.minute;
                    self.customers[index].timer_ticks = SERVICE_TICKS;
                    self.sync_queue();
                    events.push(ClockEvent::QueueService {
                        minute: self.minute,
                        remaining_queue: remaining,
                    });
                    if let StepOutcome::Sale(sale) = self.settle_current_sale() {
                        self.record_branch_sale(&sale);
                        events.push(ClockEvent::Sale {
                            minute: self.minute,
                            stock: self.sim.snapshot().stock,
                            cash_delta: sale.cash_delta,
                        });
                    }
                }
                CustomerPhase::Departing => {
                    self.customers.remove(index);
                    self.sync_queue();
                    events.push(ClockEvent::Departure {
                        minute: self.minute,
                    });
                    self.admit_next();
                }
                CustomerPhase::Queued => {}
            }
        }
        events
    }

    /// Advance in the original five-minute worker increments. The hourly
    /// dispatch creates one arrival when the branch is open and idle. The next
    /// ticks move it Waiting -> Producing -> settlement -> Departing -> Idle.
    pub fn advance_to(&mut self, end_minute: u32) -> Vec<ClockEvent> {
        let mut events = Vec::new();
        while self.minute < end_minute {
            self.minute += 5;
            self.sim.set_clock_minutes(self.minute);
            events.push(ClockEvent::Tick {
                minute: self.minute,
            });
            events.extend(self.complete_campaign_projects());
            let minute_of_day = self.minute % (24 * 60);
            if minute_of_day % 60 == 0 {
                let hour = (minute_of_day / 60) % 24;
                self.receive_campaign_delivery(hour as u8);
                if self.sim.snapshot().open {
                    if let Some((_, close)) = self
                        .campaign_branch()
                        .and_then(|branch| branch.opening_hours)
                    {
                        if hour as u8 >= close {
                            self.sim.set_open(false);
                        }
                    }
                }
                self.hourly_count += 1;
                events.push(ClockEvent::Hourly {
                    minute: self.minute,
                    hour,
                    hour_index: self.hourly_count,
                });
                for phase in [
                    "characters",
                    "cities",
                    "missions",
                    "companies",
                    "object_cleanup",
                    "recipes",
                ] {
                    events.push(ClockEvent::Phase(phase));
                }
                if hour == 0 {
                    events.push(ClockEvent::QuarterBoundary {
                        minute: self.minute,
                        hour,
                    });
                }
                if self.customers.is_empty() && self.sim.snapshot().open {
                    self.push_queued_party(1);
                    self.admit_next();
                    events.push(ClockEvent::Arrival {
                        minute: self.minute,
                        queue: self.queue,
                    });
                }
            }

            let Some(index) = self.active_customer_index() else {
                self.admit_next();
                continue;
            };
            let phase = self.customers[index].phase;
            let started = self.customers[index].phase_started;
            match phase {
                CustomerPhase::Waiting if self.minute >= started + 5 => {
                    self.customers[index].phase = CustomerPhase::Producing;
                    self.customers[index].phase_started = self.minute;
                    self.customers[index].timer_ticks = PRODUCTION_TICKS;
                    self.sync_queue();
                    events.push(ClockEvent::ProductionStart {
                        minute: self.minute,
                    });
                }
                CustomerPhase::Producing if self.minute >= started + 5 => {
                    let remaining = self.queued_count();
                    self.customers[index].phase = CustomerPhase::Departing;
                    self.customers[index].phase_started = self.minute;
                    self.customers[index].timer_ticks = SERVICE_TICKS;
                    self.sync_queue();
                    events.push(ClockEvent::QueueService {
                        minute: self.minute,
                        remaining_queue: remaining,
                    });
                    if let StepOutcome::Sale(sale) = self.settle_current_sale() {
                        self.record_branch_sale(&sale);
                        events.push(ClockEvent::Sale {
                            minute: self.minute,
                            stock: self.sim.snapshot().stock,
                            cash_delta: sale.cash_delta,
                        });
                    }
                }
                CustomerPhase::Departing if self.minute >= started + 5 => {
                    self.customers.remove(index);
                    self.sync_queue();
                    events.push(ClockEvent::Departure {
                        minute: self.minute,
                    });
                    // The target is free after departure; 0x409d40 first tries
                    // the queued list through 0x409c60.
                    self.admit_next();
                }
                _ => {}
            }
        }
        events
    }
}

pub type ClockReplay = World;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn one_sale_matches_python_case() {
        let mut sim = BranchSim::new();
        sim.set_open(true);
        let outcome = sim.step();
        let StepOutcome::Sale(sale) = outcome else {
            panic!("expected sale");
        };
        assert_eq!(sale.servings, 1);
        assert!((sale.revenue - 13.8).abs() < 1e-9);
        assert!((sale.stock_cost - 4.0).abs() < 1e-9);
        assert!((sale.market_cost - 0.379_475_287_634_193_9).abs() < 1e-9);
        assert!((sale.cash_delta - 13.420_524_712_365_806).abs() < 1e-9);
        let snapshot = sim.snapshot();
        assert_eq!(snapshot.stock, 399.0);
        assert!((snapshot.cash - 10_013.420_524_712_366).abs() < 1e-9);
        assert_eq!(snapshot.servings_sold, 1);
        assert_eq!(snapshot.sales, 1);
        assert!((sim.cash_delta() - 13.420_524_712_365_806).abs() < 1e-9);
    }

    #[test]
    fn recipe_price_0x513bf0_matches_python_contract() {
        // Mirror tests/test_sim_core.py::test_recipe_price_formula.
        assert_eq!(recipe_price(10.0, 100.0, 1.0, 10.0), 20.0);
        assert_eq!(recipe_price(10.0, 50.0, 1.0, 10.0), 15.0);
        assert_eq!(recipe_price(12.0, 100.0, 1.0, 0.0), 12.0);
        assert_eq!(recipe_price(12.0, 200.0, 2.0, 3.0), 51.0);
    }

    #[test]
    fn price_from_recipe_drives_next_sale_0x513bf0() {
        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.set_price_from_recipe(12.0, 100.0, 1.0, 0.0);
        let StepOutcome::Sale(sale) = sim.step() else {
            panic!("sale");
        };
        assert!((sale.price - 12.0).abs() < 1e-9);
        assert!((sale.revenue - 13.8).abs() < 1e-9);
    }

    #[test]
    fn shortage_0x47d4a0_posts_nothing() {
        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.stock = 0.0;
        let outcome = sim.step();
        assert_eq!(outcome, StepOutcome::StockOut);
        let snapshot = sim.snapshot();
        assert_eq!(snapshot.stock, 0.0);
        assert_eq!(snapshot.cash, START_CASH);
        assert_eq!(snapshot.sales, 0);
        assert_eq!(snapshot.customers_lost, 1);
        assert_eq!(snapshot.steps, 1);
        assert!(snapshot.last_sale.is_none());
    }

    #[test]
    fn quality_95_replay_0x47d910_0x509580_0x47d4a0() {
        // Fixture row38-counter returns quality 95; two recipes exercise choice,
        // then the selected price is settled through 0x47d4a0.
        let mut candidates = vec![
            (candidate_score(95, 0), 14.0),
            (candidate_score(80, 0), 12.0),
        ];
        candidates.sort_by(|a, b| b.0.cmp(&a.0));
        let selected = select_candidate_index(candidates.len(), 75, 0).unwrap();
        assert_eq!(selected, 0);
        assert_eq!(candidates[selected], (95, 14.0));

        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.set_price_from_recipe(candidates[selected].1, 100.0, 1.0, 0.0);
        let StepOutcome::Sale(sale) = sim.step() else {
            panic!("sale");
        };
        assert!((sale.revenue - 16.1).abs() < 1e-9);
        assert!((sale.cash_delta - 15.720_524_712_365_806).abs() < 1e-9);
        assert_eq!(sim.snapshot().stock, 399.0);
        assert_eq!(sim.snapshot().sales, 1);
    }

    #[test]
    fn skill_rating_0x5139e0_aggregates_arrays() {
        let mut skill = [0i32; 9];
        let mut craft = [0i32; 9];
        for index in 0..9 {
            skill[index] = index as i32 * 10;
            craft[index] = index as i32;
        }
        // Category 2: 20 + 2.
        assert_eq!(skill_rating(&skill, &craft, 2), 22);
        // Category 8 is category 5.
        assert_eq!(skill_rating(&skill, &craft, 8), 55);
        // Category -1 averages (skill + craft) over 0..7.
        let expected = (0..8).map(|i| i as i32 * 11).sum::<i32>() / 8;
        assert_eq!(skill_rating(&skill, &craft, -1), expected);
        assert_eq!(skill_rating(&skill, &craft, 99), 0);
    }

    #[test]
    fn candidate_score_0x5092b0_matches_disassembly() {
        // Disassembly: (rating_offset + 100) * quality * 0.01, truncated and
        // clamped to 0..100.
        assert_eq!(candidate_score(55, 0), 55);
        assert_eq!(candidate_score(55, 20), 66);
        assert_eq!(candidate_score(70, 15), 80);
        assert_eq!(candidate_score(100, 100), 100);
        assert_eq!(candidate_score(0, 50), 0);
    }

    #[test]
    fn candidate_rank_0x509580_matches_bands() {
        // Four or more candidates: 51..100 best, 21..50 second, 6..20 third,
        // 1..5 fall through to a uniform choice.
        assert_eq!(select_candidate_index(4, 75, 0), Some(0));
        assert_eq!(select_candidate_index(4, 30, 0), Some(1));
        assert_eq!(select_candidate_index(4, 10, 0), Some(2));
        assert_eq!(select_candidate_index(4, 3, 7), Some(3));
        // Fewer than four is uniform.
        assert_eq!(select_candidate_index(3, 75, 7), Some(1));
        assert_eq!(select_candidate_index(0, 75, 0), None);
    }

    #[test]
    fn scoring_selection_settlement_0x5092b0_0x509580_0x47d4a0() {
        // Two controlled candidates. The score is quality-based in this caller;
        // the selected price then drives the settlement replay.
        let mut candidates = vec![
            (candidate_score(55, 0), 12.0),
            (candidate_score(70, 15), 15.0),
        ];
        candidates.sort_by(|a, b| b.0.cmp(&a.0));
        let selected = select_candidate_index(candidates.len(), 75, 0).unwrap();
        assert_eq!(selected, 0);
        assert_eq!(candidates[selected], (80, 15.0));

        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.set_price_from_recipe(candidates[selected].1, 100.0, 1.0, 0.0);
        let StepOutcome::Sale(sale) = sim.step() else {
            panic!("sale");
        };
        assert!((sale.revenue - 17.25).abs() < 1e-9);
        assert!((sale.cash_delta - 16.870_524_712_365_804).abs() < 1e-9);
        assert_eq!(sim.snapshot().stock, 399.0);
    }

    #[test]
    fn closed_branch_makes_no_sale() {
        let mut sim = BranchSim::new();
        let outcome = sim.step();
        assert_eq!(outcome, StepOutcome::Closed);
        let snapshot = sim.snapshot();
        assert_eq!(snapshot.stock, 400.0);
        assert_eq!(snapshot.cash, START_CASH);
        assert_eq!(snapshot.sales, 0);
        assert!(snapshot.last_sale.is_none());
    }

    #[test]
    fn price_change_changes_next_sale() {
        let mut sim = BranchSim::new();
        sim.set_open(true);
        let StepOutcome::Sale(first) = sim.step() else {
            panic!("first sale");
        };
        sim.set_price(24.0);
        let StepOutcome::Sale(second) = sim.step() else {
            panic!("second sale");
        };
        assert!(second.revenue > first.revenue);
        assert!(second.cash_delta > first.cash_delta);
        assert!((second.cash_delta - 27.220_524_712_365_806).abs() < 1e-9);
        assert_eq!(sim.snapshot().stock, 398.0);
    }

    #[test]
    fn replay_is_deterministic() {
        let commands = [
            Command::SetOpen(true),
            Command::Step,
            Command::Step,
            Command::SetPrice(18.0),
            Command::Step,
            Command::SetOpen(false),
            Command::Step,
        ];
        let run = || {
            let mut sim = BranchSim::new();
            for command in commands {
                sim.apply(command);
            }
            sim.snapshot_json()
        };
        assert_eq!(run(), run());
        let mut sim = BranchSim::new();
        for command in commands {
            sim.apply(command);
        }
        assert_eq!(sim.snapshot().sales, 3);
        assert_eq!(sim.snapshot().stock, 397.0);
        assert!(
            (sim.cash_delta() - (13.420_524_712_365_806 * 2.0 + 20.320_524_712_365_806)).abs()
                < 1e-9
        );
    }

    #[test]
    fn clock_10_55_to_11_05_creates_arrival_and_hourly_once() {
        let mut world = ClockReplay::new(10 * 60 + 55);
        let events = world.advance_to(11 * 60 + 5);
        assert_eq!(
            events
                .iter()
                .filter(|event| matches!(event, ClockEvent::Hourly { .. }))
                .count(),
            1
        );
        assert!(events.contains(&ClockEvent::Hourly {
            minute: 660,
            hour: 11,
            hour_index: 1
        }));
        assert!(events.contains(&ClockEvent::Arrival {
            minute: 660,
            queue: 1
        }));
        assert!(events.contains(&ClockEvent::ProductionStart { minute: 665 }));
        assert!(!events
            .iter()
            .any(|event| matches!(event, ClockEvent::Sale { .. })));
        assert_eq!(world.snapshot().clock_minutes, 665);
        assert_eq!(world.snapshot().stock, 400.0);
        assert_eq!(world.snapshot().cash, START_CASH);
    }

    #[test]
    fn clock_closed_branch_has_no_arrival_or_sale() {
        let mut world = ClockReplay::new(10 * 60 + 55);
        world.set_open(false);
        let events = world.advance_to(11 * 60 + 20);
        assert!(!events
            .iter()
            .any(|event| matches!(event, ClockEvent::Arrival { .. } | ClockEvent::Sale { .. })));
        assert_eq!(world.snapshot().stock, 400.0);
        assert_eq!(world.snapshot().cash, START_CASH);
        assert_eq!(world.snapshot().sales, 0);
    }

    #[test]
    fn clock_full_visit_settles_once_and_departs() {
        let mut world = ClockReplay::new(10 * 60 + 55);
        let events = world.advance_to(11 * 60 + 20);
        assert_eq!(
            events
                .iter()
                .filter(|event| matches!(event, ClockEvent::Sale { .. }))
                .count(),
            1
        );
        assert!(events.contains(&ClockEvent::Arrival {
            minute: 660,
            queue: 1
        }));
        assert!(events.contains(&ClockEvent::ProductionStart { minute: 665 }));
        assert!(events.contains(&ClockEvent::QueueService {
            minute: 670,
            remaining_queue: 0
        }));
        assert!(events.contains(&ClockEvent::Departure { minute: 675 }));
        assert_eq!(world.snapshot().stock, 399.0);
        assert!((world.snapshot().cash - 10_013.420_524_712_366).abs() < 1e-9);
        assert_eq!(world.snapshot().clock_minutes, 680);
        assert_eq!(world.visit_state(), VisitState::Idle);
    }

    #[test]
    fn london_two_orders_predict_from_captured_inputs() {
        // Captured from the verified London reload. The first order is
        // customer 100017 at 11:09; the second is customer 100004 at 12:01.
        // Their recipes and menu prices differ, so each appends its own sales
        // record. The native PAYMENT events clear at 493856.19 and 495184.20.
        let first = OrderInput {
            customer_id: 100_017,
            minute: 11 * 60 + 9,
            menu_price: 12.426_362_04,
            recipe_id: 0xE931_2127,
            ingredient_units: 194,
            servings: 100,
            rating: 65,
            tip_base: 31,
        };
        let second = OrderInput {
            customer_id: 100_004,
            minute: 12 * 60 + 1,
            menu_price: 11.852_810_86,
            recipe_id: 0x0143_7164,
            ingredient_units: 161,
            servings: 100,
            rating: 66,
            tip_base: 42,
        };
        assert_ne!(first.recipe_id, second.recipe_id);
        assert_eq!(first.tip(), 17);
        assert_eq!(second.tip(), 12);
        assert_eq!(first.stock_use(), 19_400.0);
        assert_eq!(second.stock_use(), 16_100.0);
        assert!((first.revenue() - 1_454.384_399_414_062_5).abs() < 1e-9);
        assert!((second.revenue() - 1_328.014_770_507_812_5).abs() < 1e-9);

        let mut sim = BranchSim::new();
        sim.set_open(true);
        sim.set_stock(200_000.0);
        sim.set_stock_capacity(200_000.0);
        sim.set_starting_cash(492_401.80);

        let StepOutcome::Sale(first_sale) = sim.settle_order_input(&first) else {
            panic!("expected the first captured order to sell");
        };
        assert_eq!(first_sale.recipe_id, first.recipe_id);
        assert_eq!(first_sale.clock_minutes, first.minute);
        assert_eq!(sim.snapshot().stock, 180_600.0);
        assert_eq!(sim.snapshot().sales, 1);
        assert_eq!(sim.recipe_sales(first.recipe_id), 1);
        assert_eq!(sim.recipe_sales(second.recipe_id), 0);
        assert!((sim.snapshot().cash - 492_401.80).abs() < 1e-9);

        sim.credit_payment(&first_sale);
        // The native PAYMENT line prints the credited cash to cents.
        assert!((sim.snapshot().cash - 493_856.19).abs() < 0.01);
        assert!((first_sale.cash_delta - 1_454.38).abs() < 0.01);

        // A delivery occurs between the two sales.
        sim.set_stock(580_600.0);
        sim.set_stock_capacity(580_600.0);
        sim.set_starting_cash(493_856.19);
        let StepOutcome::Sale(second_sale) = sim.settle_order_input(&second) else {
            panic!("expected the second captured order to sell");
        };
        assert_eq!(second_sale.recipe_id, second.recipe_id);
        assert_eq!(second_sale.clock_minutes, second.minute);
        assert_eq!(sim.snapshot().stock, 564_500.0);
        assert_eq!(sim.snapshot().sales, 2);
        assert_eq!(sim.recipe_sales(first.recipe_id), 1);
        assert_eq!(sim.recipe_sales(second.recipe_id), 1);
        assert!((sim.snapshot().cash - 493_856.19).abs() < 1e-9);

        sim.credit_payment(&second_sale);
        assert!((sim.snapshot().cash - 495_184.20).abs() < 0.01);
        assert!((second_sale.cash_delta - 1_328.01).abs() < 0.01);
        assert_eq!(
            sim.snapshot().servings_sold,
            first.servings + second.servings
        );
    }

    #[test]
    fn london_checkpoint_completes_one_customer_visit() {
        let mut world = World::london_checkpoint();
        let before = world.snapshot();
        assert_eq!(LONDON_CHECKPOINT_CASH, 493_015.0);
        assert_eq!(LONDON_CHECKPOINT_STOCK, 200_000.0);
        assert_eq!(before.cash, LONDON_ORDER_CASH_BEFORE);
        assert_eq!(before.stock, LONDON_PRE_ORDER_STOCK);
        assert_eq!(before.stock_capacity, LONDON_PRE_ORDER_STOCK);
        assert_eq!(world.player_branch_count(), 1);
        assert_eq!(world.player_branches()[0].branch_id, LONDON_BRANCH_ID);
        assert_eq!(world.player_branches()[0].owner_slot, LONDON_PLAYER_SLOT);
        assert_eq!(world.player_branches()[0].staff_count, LONDON_STAFF_COUNT);
        assert_eq!(world.player_branches()[0].sales, 0);

        let arrival = world.advance_to(11 * 60);
        assert!(arrival.contains(&ClockEvent::Arrival {
            minute: 660,
            queue: 1
        }));
        assert_eq!(world.customers().len(), 1);
        assert_eq!(world.customers()[0].id, LONDON_FIRST_CUSTOMER_ID);

        let visit = world.advance_to(11 * 60 + 20);
        let sales: Vec<_> = visit
            .iter()
            .filter(|event| matches!(event, ClockEvent::Sale { .. }))
            .collect();
        assert_eq!(sales.len(), 1);
        assert!(visit.contains(&ClockEvent::ProductionStart { minute: 665 }));
        assert!(visit.contains(&ClockEvent::QueueService {
            minute: 670,
            remaining_queue: 0
        }));
        assert!(visit.contains(&ClockEvent::Departure { minute: 675 }));

        let after = world.snapshot();
        assert_eq!(
            after.stock,
            LONDON_PRE_ORDER_STOCK - LONDON_ORDER_STOCK_DROP
        );
        assert!((after.cash - LONDON_ORDER_CASH_AFTER).abs() < 1e-9);
        assert_eq!(after.sales, 1);
        assert_eq!(after.servings_sold, LONDON_ORDER_SERVINGS);
        assert_eq!(world.player_branches()[0].sales, LONDON_ORDER_SERVINGS);
        let sale = after.last_sale.expect("last sale");
        assert_eq!(sale.servings, LONDON_ORDER_SERVINGS);
        assert!((sale.revenue - LONDON_ORDER_REVENUE).abs() < 1e-9);
        assert!((sale.cash_delta - LONDON_ORDER_REVENUE).abs() < 1e-9);
        assert_eq!(world.customers().len(), 0);
    }

    #[test]
    fn two_party_one_slot_serializes_and_resumes_from_contention() {
        let mut world = ClockReplay::new(10 * 60 + 55);
        world.set_open(true);
        let _ = world.advance_to(11 * 60);
        assert_eq!(world.customers().len(), 1);
        assert_eq!(world.visit_state(), VisitState::Waiting);

        let second_id = world.enqueue_party(1);
        assert_eq!(second_id, 2);
        assert_eq!(world.customers().len(), 2);
        assert_eq!(world.customers()[1].phase, CustomerPhase::Queued);
        assert_eq!(world.queue, 2);

        let first = world.advance_to(11 * 60 + 10);
        assert_eq!(world.snapshot().sales, 1);
        assert_eq!(world.customers()[0].phase, CustomerPhase::Departing);
        assert_eq!(world.customers()[1].phase, CustomerPhase::Queued);
        assert!(first.contains(&ClockEvent::QueueService {
            minute: 670,
            remaining_queue: 1,
        }));
        assert!(first
            .iter()
            .any(|event| matches!(event, ClockEvent::Sale { minute: 670, .. })));

        let contention = world.world_snapshot();
        assert_eq!(contention.queue, 2);
        assert_eq!(contention.visit_state, VisitState::Departing);
        assert_eq!(contention.customers.len(), 2);
        assert_eq!(contention.customers[0].slot, Some(0));
        assert_eq!(contention.customers[1].slot, None);

        let expected = world.advance_to(11 * 60 + 25);
        assert_eq!(world.snapshot().sales, 2);
        assert_eq!(world.snapshot().stock, 398.0);
        assert_eq!(world.customers().len(), 1);
        assert_eq!(world.customers()[0].id, second_id);
        assert_eq!(world.customers()[0].phase, CustomerPhase::Departing);
        assert!(expected.contains(&ClockEvent::Departure { minute: 675 }));
        assert!(expected.contains(&ClockEvent::ProductionStart { minute: 680 }));
        assert!(expected.contains(&ClockEvent::QueueService {
            minute: 685,
            remaining_queue: 0,
        }));

        let mut restored = ClockReplay::from_snapshot(&contention);
        let actual = restored.advance_to(11 * 60 + 25);
        assert_eq!(actual, expected);
        assert_eq!(restored.world_snapshot(), world.world_snapshot());

        let _ = world.advance_to(11 * 60 + 30);
        assert_eq!(world.queue, 0);
        assert!(world.customers().is_empty());
        assert_eq!(world.visit_state(), VisitState::Idle);
    }

    #[test]
    fn original_10ms_timers_drive_waiting_production_and_service() {
        let mut world = ClockReplay::new(11 * 60);
        world.enqueue_party(1);
        assert_eq!(world.visit_state(), VisitState::Waiting);
        assert_eq!(world.customers()[0].timer_ticks, QUEUE_WALK_TICKS);

        let events = world.advance_queue_ticks(QUEUE_WALK_TICKS - 1);
        assert!(events.is_empty());
        assert_eq!(world.visit_state(), VisitState::Waiting);
        assert_eq!(world.customers()[0].timer_ticks, 1);

        let events = world.advance_queue_ticks(1);
        assert_eq!(world.visit_state(), VisitState::Producing);
        assert_eq!(world.customers()[0].timer_ticks, PRODUCTION_TICKS);
        assert!(events.contains(&ClockEvent::ProductionStart { minute: 660 }));

        let events = world.advance_queue_ticks(PRODUCTION_TICKS);
        assert_eq!(world.snapshot().sales, 1);
        assert_eq!(world.visit_state(), VisitState::Departing);
        assert_eq!(world.customers()[0].timer_ticks, SERVICE_TICKS);
        assert!(events
            .iter()
            .any(|event| matches!(event, ClockEvent::Sale { minute: 660, .. })));

        let events = world.advance_queue_ticks(SERVICE_TICKS);
        assert_eq!(world.visit_state(), VisitState::Idle);
        assert!(world.customers().is_empty());
        assert!(events.contains(&ClockEvent::Departure { minute: 660 }));
        assert_eq!(world.queue, 0);
    }

    #[test]
    fn advance_millis_uses_the_original_10ms_unit() {
        let mut world = ClockReplay::new(11 * 60);
        world.enqueue_party(1);
        world.advance_millis(2590);
        assert_eq!(world.customers()[0].timer_ticks, 1);
        assert_eq!(world.visit_state(), VisitState::Waiting);
        world.advance_millis(10);
        assert_eq!(world.visit_state(), VisitState::Producing);
        assert_eq!(world.customers()[0].timer_ticks, PRODUCTION_TICKS);
    }

    #[test]
    fn full_queue_rejects_without_stock_or_cash_change() {
        let mut world = ClockReplay::new(11 * 60);
        world.set_queue_capacity(1).unwrap();
        world.set_open(true);
        assert_eq!(world.enqueue_party(1), 1);
        assert_eq!(world.enqueue_party(1), 0);
        assert_eq!(world.snapshot().customers_lost, 1);
        assert_eq!(world.snapshot().sales, 0);
        assert_eq!(world.snapshot().stock, 400.0);
        assert_eq!(world.snapshot().cash, START_CASH);
        assert_eq!(world.queue, 1);
        assert_eq!(world.customers().len(), 1);
        assert_eq!(world.queue_capacity(), 1);
    }

    #[test]
    fn world_snapshot_carries_character_profile() {
        let profile = CharacterProfile::new(
            1,
            2,
            3,
            4,
            5,
            1,
            2,
            6,
            [0, 1, 0, -1, 2, 0],
            "Ada".into(),
            "Ada Pizza".into(),
        )
        .with_mode(GameMode::FreeGame);
        let scenario = ScenarioSetup::free_play_berlin();
        let world = World::new(10 * 60 + 55)
            .with_profile(profile.clone())
            .with_scenario(scenario.clone());
        let snapshot = world.world_snapshot();
        assert_eq!(world.attribute_total(), Some(2));
        assert_eq!(world.company_slot_roll_range(), Some((36, 54)));
        assert_eq!(world.starting_capital(), 40_000.0);
        assert_eq!(snapshot.sim.cash, 40_000.0);
        assert_eq!(snapshot.profile, Some(profile.clone()));
        assert_eq!(snapshot.scenario, Some(scenario));
        let restored = World::from_snapshot(&snapshot);
        assert_eq!(restored.profile(), Some(&profile));
        assert_eq!(restored.scenario(), snapshot.scenario.as_ref());
    }

    #[test]
    fn free_play_berlin_starts_with_difficulty_capital_and_first_sale() {
        let profile = CharacterProfile::new(
            0,
            7,
            4,
            6,
            3,
            5,
            6,
            9,
            [3, -1, 2, 0, -2, 1],
            "Ada".into(),
            "Ada Pizza".into(),
        )
        .with_mode(GameMode::FreeGame);
        let scenario = ScenarioSetup::free_play_berlin();
        assert_eq!(scenario.starting_capital(profile.difficulty), 22_000);
        let mut world = World::new(10 * 60 + 55)
            .with_profile(profile)
            .with_scenario(scenario.clone());
        assert_eq!(world.snapshot().cash, 22_000.0);
        assert_eq!(
            world.scenario().map(|setup| setup.map_name.as_str()),
            Some("Ber.iso")
        );
        world.set_open(true);
        let events = world.advance_to(11 * 60 + 20);
        assert_eq!(
            events
                .iter()
                .filter(|event| matches!(event, ClockEvent::Sale { .. }))
                .count(),
            1
        );
        assert_eq!(world.snapshot().stock, 399.0);
        assert!(
            (world.snapshot().cash - 22_013.420_524_712_366).abs() < 1e-9,
            "cash was {}",
            world.snapshot().cash
        );
        assert_eq!(world.snapshot().sales, 1);
        let snapshot = world.world_snapshot();
        assert_eq!(
            snapshot.profile.map(|profile| profile.player_name),
            Some("Ada".into())
        );
        assert_eq!(snapshot.scenario, Some(scenario));
    }

    #[test]
    fn scenario_setup_roundtrips_and_uses_campaign_startgeld() {
        let free = ScenarioSetup::free_play_berlin();
        assert_eq!(ScenarioSetup::decode("mode=free"), Ok(free.clone()));
        assert_eq!(ScenarioSetup::decode(&free.encode()), Ok(free));

        let free = ScenarioSetup::decode("mode=free;ownership_percent=110").unwrap();
        assert_eq!(ScenarioSetup::decode(&free.encode()), Ok(free.clone()));
        let profile = CharacterProfile::new(
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            9,
            [0; 6],
            "Ada".into(),
            "Ada Pizza".into(),
        )
        .with_mode(GameMode::FreeGame);
        let world = World::new(10 * 60 + 55)
            .with_profile(profile)
            .with_scenario(free);
        assert_eq!(world.snapshot().cash, 24_200.0);
        assert!(ScenarioSetup::decode("ownership_percent=69").is_err());
        assert!(ScenarioSetup::decode("ownership_percent=991").is_err());

        let campaign = ScenarioSetup::campaign_berlin();
        assert_eq!(
            ScenarioSetup::decode(&campaign.encode()),
            Ok(campaign.clone())
        );
        assert_eq!(campaign.starting_capital(9), 70_000);
        let campaign_override =
            ScenarioSetup::decode("mode=campaign;ownership_percent=110").unwrap();
        assert_eq!(campaign_override.starting_capital(9), 70_000);
        assert_eq!(campaign.city_code, "ber");
        assert_eq!(campaign.map_name, "Ber.iso");
    }

    #[test]
    fn game_get_starting_capital_matches_original_table() {
        let expected = [
            1_000_000, 500_000, 200_000, 100_000, 75_000, 50_000, 40_000, 30_000, 25_000, 22_000,
            20_000,
        ];
        for (difficulty, capital) in expected.into_iter().enumerate() {
            assert_eq!(starting_capital(difficulty as u8), capital);
        }
    }

    #[test]
    fn ownership_percentage_fixtures_match_the_binary() {
        // Settings_InitDefaults writes 100 at 0x406b90; the setup arrows
        // adjust the working value in steps of 10.
        assert_eq!(starting_capital_with_ownership(9, 100), 22_000);
        assert_eq!(starting_capital_with_ownership(9, 110), 24_200);
    }

    #[test]
    fn campaign_lease_debits_once_and_rejections_leave_the_world_unchanged() {
        let scenario = ScenarioSetup::from_campaign_mission(
            "lon".into(),
            "London".into(),
            280,
            2,
            CampaignMission {
                starting_cash: 500_000,
                difficulty_percent: 10,
                goal_ids: vec![0, 1, 2],
                rival_count: 1,
                player_start_hq: 0,
                rival_start_hq: 1,
                starting_branches: Vec::new(),
                property_offer: Some(CampaignPropertyOffer {
                    tile_index: 13_694,
                    price: 2_812,
                    fee: 1_000,
                }),
            },
        );
        let mut world = World::new(0).with_scenario(scenario);
        world.sim.set_starting_cash(500_000.0);
        world.prepare_campaign_new_game();
        assert_eq!(world.snapshot().stock, 0.0);
        assert_eq!(world.player_branch_count(), 0);
        world.set_open(true);
        let before = world.world_snapshot();
        assert!(!world.can_enter_branch());
        assert!(!before.sim.open);
        assert_eq!(
            world.lease_campaign_property(13_693),
            Err("property is unavailable")
        );
        assert_eq!(world.world_snapshot(), before);

        let mut low_cash = before;
        low_cash.sim.cash = 3_811.0;
        let mut poor = World::from_snapshot(&low_cash);
        assert_eq!(
            poor.lease_campaign_property(13_694),
            Err("insufficient funds")
        );
        assert_eq!(poor.world_snapshot(), low_cash);

        assert_eq!(world.lease_campaign_property(13_694), Ok(3_812));
        assert!(world.can_enter_branch());
        let leased = world.world_snapshot();
        assert_eq!(leased.leased_property, Some(13_694));
        assert_eq!(leased.sim.cash, 496_188.0);
        assert_eq!(leased.player_branches.len(), 1);
        assert_eq!(leased.player_branches[0].tile_index, 13_694);
        assert_eq!(leased.player_branches[0].branch_id, LONDON_BRANCH_ID);
        assert_eq!(leased.player_branches[0].owner_slot, 0);
        assert!(!leased.player_branches[0].owned);
        assert_eq!(leased.player_branches[0].rent, 2_812);
        assert!(leased.player_branches[0].employees.is_empty());
        assert_eq!(leased.player_branches[0].warehouse_id, None);
        assert!(!leased.player_branches[0].deliveries_enabled);
        assert_eq!(leased.player_branches[0].opening_hours, None);
        assert_eq!(world.set_campaign_open(true), Err("hire staff first"));
        assert_eq!(leased.mission_goals[0].status, GoalStatus::Pending);
        assert_eq!(leased.mission_goals[1].status, GoalStatus::Pending);
        assert_eq!(leased.mission_goals[2].status, GoalStatus::Complete);
        assert!(!leased.mission_complete);
        assert_eq!(world.hire_campaign_employee(EmployeeRole::Cook), Ok(1));
        assert_eq!(world.hire_campaign_employee(EmployeeRole::Service), Ok(2));
        assert_eq!(world.hire_campaign_employee(EmployeeRole::Errand), Ok(3));
        assert_eq!(world.hire_campaign_employee(EmployeeRole::Errand), Ok(4));
        assert_eq!(world.lease_campaign_warehouse(100_000), Ok(()));
        assert_eq!(world.assign_campaign_supplier("central-market"), Ok(()));
        assert_eq!(world.enable_campaign_deliveries(), Ok(()));
        assert_eq!(world.deliver_campaign_stock(), Ok(200_000.0));
        assert_eq!(world.set_campaign_opening_hours(6, 22), Ok(()));
        assert_eq!(world.campaign_branch().unwrap().staff_count, 4);
        assert_eq!(
            world.campaign_branch().unwrap().warehouse_name.as_deref(),
            Some("London 1")
        );
        assert_eq!(
            world.campaign_branch().unwrap().supplier.as_deref(),
            Some("Central Market Partners")
        );
        assert!(world.campaign_branch().unwrap().deliveries_enabled);
        assert_eq!(
            world.campaign_branch().unwrap().opening_hours,
            Some((6, 22))
        );
        assert_eq!(world.snapshot().stock, 200_000.0);
        assert_eq!(world.set_campaign_open(true), Err("outside opening hours"));
        world.set_minute(360);
        assert_eq!(world.set_campaign_open(true), Ok(()));
        world.enqueue_party(1);
        world.advance_queue_ticks(QUEUE_WALK_TICKS + PRODUCTION_TICKS);
        let sold = world.world_snapshot();
        assert_eq!(sold.player_branches[0].sales, 100);
        assert_eq!(sold.sim.stock, 183_900.0);
        assert!((sold.sim.cash - 497_575.278_930_664_1).abs() < 1e-9);
        assert!((sold.player_branches[0].revenue - 1_387.278_930_664_062_5).abs() < 1e-9);
        let last_sale = sold.sim.last_sale.as_ref().expect("last sale");
        assert_eq!(last_sale.servings, 100);
        assert!((last_sale.price - 11.852_810_86).abs() < 1e-9);
        // The shipped goal 1 is "place a rat", not sales, so a sale must not
        // advance it.  This is the Unicorn-confirmed +0x14 slot.
        assert_eq!(sold.mission_goals[1].status, GoalStatus::Pending);
        assert_eq!(sold.mission_goals[0].progress, 0);
        assert!(world.mission_summary().unwrap().contains("GOALS 1/3"));
        assert!(!sold.mission_complete);

        world.set_open(false);
        let mut hq_cost = 0;
        for expected in 1..=3 {
            let cash_before = world.snapshot().cash;
            let project = world.start_hq_construction(LONDON_HQ_TILE).unwrap();
            assert_eq!(cash_before - world.snapshot().cash, project.cost as f64);
            hq_cost += project.cost;
            assert_eq!(project.target_level, expected);
            assert_eq!(world.hq_level(), expected - 1);
            assert_eq!(world.hq_project(), Some(project));
            world.advance_to(project.complete_minute);
            assert_eq!(world.hq_level(), expected);
            assert_eq!(world.hq_project(), None);
        }
        assert_eq!(
            world.start_hq_construction(LONDON_HQ_TILE),
            Err("headquarters is already level 3")
        );
        assert_eq!(hq_cost, 13_695);
        assert_eq!(world.mission_goals()[0].status, GoalStatus::Complete);
        assert!(!world.mission_complete());

        assert_eq!(
            world.dispatch_rats(123),
            Err("rats must be sent to the rival branch")
        );
        let cash_before = world.snapshot().cash;
        let delivery = world.dispatch_rats(LONDON_RIVAL_BRANCH_ID).unwrap();
        assert_eq!(
            cash_before - world.snapshot().cash,
            RAT_DELIVERY_COST as f64
        );
        assert_eq!(world.rats_placed(), 0);
        assert_eq!(world.rat_delivery(), Some(delivery));
        world.advance_to(delivery.complete_minute);
        assert_eq!(world.rats_placed(), 1);
        assert_eq!(world.mission_goals()[1].status, GoalStatus::Complete);
        assert!(world.mission_complete());
        assert!(world.mission_summary().unwrap().contains("GOALS 3/3"));
        assert!(world.mission_summary().unwrap().contains("HQ 3/3"));
        assert!(world.mission_summary().unwrap().contains("RAT 1/1"));

        let completed = world.world_snapshot();
        let mut restored = World::from_snapshot(&completed);
        assert!(restored.can_enter_branch());
        assert_eq!(restored.hq_level(), 3);
        assert_eq!(restored.rats_placed(), 1);
        assert_eq!(
            restored.lease_campaign_property(13_694),
            Err("property is already leased")
        );
        assert_eq!(restored.world_snapshot(), completed);
    }

    #[test]
    fn campaign_route_stays_empty_until_the_nine_oclock_batch() {
        let scenario = ScenarioSetup::from_campaign_mission(
            "lon".into(),
            "London".into(),
            280,
            2,
            CampaignMission {
                starting_cash: 500_000,
                difficulty_percent: 10,
                goal_ids: vec![0, 1, 2],
                rival_count: 1,
                player_start_hq: 0,
                rival_start_hq: 1,
                starting_branches: Vec::new(),
                property_offer: Some(CampaignPropertyOffer {
                    tile_index: 13_694,
                    price: 2_812,
                    fee: 1_000,
                }),
            },
        );
        let mut world = World::new(0).with_scenario(scenario);
        world.set_cash(500_000.0);
        world.prepare_campaign_new_game();
        world.lease_campaign_property(13_694).unwrap();
        world.hire_campaign_employee(EmployeeRole::Cook).unwrap();
        world.lease_campaign_warehouse(100_000).unwrap();
        world.assign_campaign_supplier("central-market").unwrap();
        world.enable_campaign_deliveries().unwrap();
        assert_eq!(world.snapshot().stock, 0.0);
        assert_eq!(
            world.campaign_branch().unwrap().route_branch_id,
            Some(100_000)
        );
        assert_eq!(world.campaign_branch().unwrap().delivery_due_hour, Some(9));

        world.advance_to(8 * 60 + 55);
        assert_eq!(world.snapshot().stock, 0.0);

        world.advance_to(9 * 60);
        assert_eq!(world.snapshot().stock, 200_000.0);
        assert_eq!(world.snapshot().stock_capacity, 400_000.0);
        assert_eq!(world.campaign_branch().unwrap().delivery_due_hour, None);
    }

    #[test]
    fn campaign_player_recipe_drives_sale_stock_and_revenue() {
        let scenario = ScenarioSetup::from_campaign_mission(
            "lon".into(),
            "London".into(),
            280,
            2,
            CampaignMission {
                starting_cash: 500_000,
                difficulty_percent: 10,
                goal_ids: vec![0, 1, 2],
                rival_count: 1,
                player_start_hq: 0,
                rival_start_hq: 1,
                starting_branches: Vec::new(),
                property_offer: Some(CampaignPropertyOffer {
                    tile_index: 13_694,
                    price: 2_812,
                    fee: 1_000,
                }),
            },
        );
        let mut world = World::new(0).with_scenario(scenario);
        world.set_cash(500_000.0);
        world.prepare_campaign_new_game();
        world.lease_campaign_property(13_694).unwrap();
        world.hire_campaign_employee(EmployeeRole::Cook).unwrap();
        world.lease_campaign_warehouse(100_000).unwrap();
        world.assign_campaign_supplier("central-market").unwrap();
        world.enable_campaign_deliveries().unwrap();
        world.advance_to(9 * 60);
        let recipe = world.create_campaign_recipe(30, 20).unwrap();
        assert_eq!(recipe.tomato, 30);
        assert_eq!(recipe.cheese, 20);
        world.set_campaign_recipe_price(15.0).unwrap();
        world.add_campaign_recipe_to_menu().unwrap();
        world.set_campaign_opening_hours(6, 22).unwrap();
        assert_eq!(world.set_campaign_open(true), Ok(()));

        world.enqueue_party(1);
        world.advance_queue_ticks(QUEUE_WALK_TICKS + PRODUCTION_TICKS);
        let snapshot = world.world_snapshot();
        assert_eq!(snapshot.sim.stock, 195_000.0);
        let sale = snapshot.sim.last_sale.as_ref().expect("recipe sale");
        assert_eq!(sale.recipe_id, recipe.id);
        assert_eq!(sale.servings, 100);
        assert!((sale.price - 15.0).abs() < 1e-9);
        assert!((sale.revenue - 1_755.5).abs() < 1e-6);
        assert!((snapshot.sim.cash - 497_943.5).abs() < 1e-6);
        assert_eq!(world.sim.recipe_sales(recipe.id), 1);
        world.advance_to(22 * 60);
        assert!(!world.snapshot().open);
    }

    #[test]
    fn campaign_save_and_load_preserve_the_ui_state() {
        let scenario = ScenarioSetup::from_campaign_mission(
            "lon".into(),
            "London".into(),
            280,
            2,
            CampaignMission {
                starting_cash: 500_000,
                difficulty_percent: 10,
                goal_ids: vec![0, 1, 2],
                rival_count: 1,
                player_start_hq: 0,
                rival_start_hq: 1,
                starting_branches: Vec::new(),
                property_offer: Some(CampaignPropertyOffer {
                    tile_index: 13_694,
                    price: 2_812,
                    fee: 1_000,
                }),
            },
        );
        let mut world = World::new(0).with_scenario(scenario);
        world.set_cash(500_000.0);
        world.prepare_campaign_new_game();
        world.lease_campaign_property(13_694).unwrap();
        world.hire_campaign_employee(EmployeeRole::Cook).unwrap();
        world.lease_campaign_warehouse(100_000).unwrap();
        world.assign_campaign_supplier("central-market").unwrap();
        world.enable_campaign_deliveries().unwrap();
        world.advance_to(540);
        world.create_campaign_recipe(30, 20).unwrap();
        world.set_campaign_recipe_price(15.0).unwrap();
        world.add_campaign_recipe_to_menu().unwrap();
        world.set_campaign_opening_hours(6, 22).unwrap();
        let project = world.start_hq_construction(LONDON_HQ_TILE).unwrap();
        assert_eq!(world.hq_level(), 0);

        let path =
            std::env::temp_dir().join(format!("pc2-campaign-save-{}.bin", std::process::id()));
        world.save_campaign(&path).unwrap();
        let mut loaded = World::load_campaign(&path).unwrap();
        assert_eq!(loaded.world_snapshot(), world.world_snapshot());
        assert_eq!(loaded.hq_project(), Some(project));
        assert_eq!(loaded.hq_level(), 0);
        loaded.advance_to(project.complete_minute);
        assert_eq!(loaded.hq_level(), 1);
        assert_eq!(
            loaded
                .campaign_recipe()
                .map(|recipe| (recipe.tomato, recipe.cheese, recipe.price)),
            Some((30, 20, 15.0))
        );
        assert_eq!(
            loaded.campaign_branch().unwrap().warehouse_id,
            Some(100_000)
        );
        std::fs::remove_file(path).ok();
    }

    #[test]
    fn campaign_actions_require_a_mission_and_rival() {
        let mut world = World::new(0);
        assert_eq!(
            world.start_hq_construction(LONDON_HQ_TILE),
            Err("headquarters missions require a campaign")
        );
        assert_eq!(
            world.dispatch_rats(LONDON_RIVAL_BRANCH_ID),
            Err("rat deliveries require a campaign")
        );

        let scenario = ScenarioSetup::from_campaign_mission(
            "lon".into(),
            "London".into(),
            280,
            2,
            CampaignMission {
                starting_cash: 500_000,
                difficulty_percent: 10,
                goal_ids: vec![0, 1, 2],
                rival_count: 0,
                player_start_hq: 0,
                rival_start_hq: 1,
                starting_branches: Vec::new(),
                property_offer: None,
            },
        );
        let mut no_rival = World::new(0).with_scenario(scenario);
        no_rival.set_cash(500_000.0);
        no_rival.set_open(false);
        for _ in 0..3 {
            let project = no_rival.start_hq_construction(LONDON_HQ_TILE).unwrap();
            no_rival.advance_to(project.complete_minute);
        }
        assert_eq!(
            no_rival.dispatch_rats(LONDON_RIVAL_BRANCH_ID),
            Err("there is no rival branch")
        );
    }

    #[test]
    fn clock_customer_visibility_follows_world_state() {
        let mut world = ClockReplay::new(10 * 60 + 55);
        assert!(!world.customer_visible());
        let _ = world.advance_to(11 * 60);
        assert_eq!(world.visit_state(), VisitState::Waiting);
        assert!(world.customer_visible());
        let _ = world.advance_to(11 * 60 + 5);
        assert_eq!(world.visit_state(), VisitState::Producing);
        assert!(world.customer_visible());
        let _ = world.advance_to(11 * 60 + 10);
        assert_eq!(world.visit_state(), VisitState::Departing);
        assert!(world.customer_visible());
        let _ = world.advance_to(11 * 60 + 15);
        assert_eq!(world.visit_state(), VisitState::Idle);
        assert!(!world.customer_visible());
    }

    #[test]
    fn clock_midnight_rolls_hour_and_quarter_once() {
        let mut world = ClockReplay::new(23 * 60 + 55);
        let events = world.advance_to(24 * 60 + 5);
        assert_eq!(
            events
                .iter()
                .filter(|event| matches!(event, ClockEvent::Hourly { .. }))
                .count(),
            1
        );
        assert_eq!(
            events
                .iter()
                .filter(|event| matches!(event, ClockEvent::QuarterBoundary { .. }))
                .count(),
            1
        );
        assert!(events.contains(&ClockEvent::Hourly {
            minute: 1440,
            hour: 0,
            hour_index: 1
        }));
        assert!(events.contains(&ClockEvent::Arrival {
            minute: 1440,
            queue: 1
        }));
        assert!(events.contains(&ClockEvent::QuarterBoundary {
            minute: 1440,
            hour: 0
        }));
        assert_eq!(world.snapshot().clock_minutes, 1445);
    }

    #[test]
    fn clock_snapshot_while_waiting_resumes_identically() {
        let mut uninterrupted = ClockReplay::new(10 * 60 + 55);
        let _ = uninterrupted.advance_to(11 * 60);
        let snapshot = uninterrupted.world_snapshot();
        assert_eq!(snapshot.minute, 11 * 60);
        assert_eq!(snapshot.sim.clock_minutes, 11 * 60);
        assert_eq!(snapshot.visit_state, VisitState::Waiting);
        assert_eq!(snapshot.queue, 1);
        let expected = uninterrupted.advance_to(11 * 60 + 20);

        let mut restored = ClockReplay::from_snapshot(&snapshot);
        let actual = restored.advance_to(11 * 60 + 20);
        assert_eq!(actual, expected);
        assert_eq!(restored.snapshot(), uninterrupted.snapshot());
        assert_eq!(restored.snapshot().clock_minutes, 680);
    }
}
