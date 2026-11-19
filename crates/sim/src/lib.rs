//! Small deterministic branch simulation used by the playable viewer.
//!
//! The constants and one-sale arithmetic are taken from the Python order and
//! ledger model (`Simulator.process_order`): rating 50, recipe price 12.0,
//! one serving per customer, batch cost 4.0, and the market factor produced by
//! the default Berlin market table. A sale therefore has revenue 13.80,
//! ingredient/market cost 0.3794752876341939 and a cash delta of
//! 13.420524712365806, with stock moving 400 -> 399.

pub const START_CASH: f64 = 10_000.0;
pub const START_STOCK: f64 = 400.0;
pub const STOCK_CAPACITY: f64 = 400.0;
pub const UNIT_COST: f64 = 4.0;
pub const MARKET_PRICE_FACTOR: f64 = 0.094_868_821_908_548_48;
pub const RATING: i32 = 50;
pub const STEP_MINUTES: u32 = 15;

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

#[derive(Clone, Debug, PartialEq)]
pub struct Sale {
    pub clock_minutes: u32,
    pub price: f64,
    pub servings: u32,
    pub revenue: f64,
    pub stock_cost: f64,
    pub market_cost: f64,
    pub cash_delta: f64,
}

#[derive(Clone, Debug, PartialEq)]
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
    clock_minutes: u32,
    servings_sold: u32,
    customers_served: u32,
    customers_lost: u32,
    sales: u32,
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
            clock_minutes: 10 * 60,
            servings_sold: 0,
            customers_served: 0,
            customers_lost: 0,
            sales: 0,
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
            stock_capacity: STOCK_CAPACITY,
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
        if self.stock < 1.0 {
            self.customers_lost += 1;
            return StepOutcome::StockOut;
        }
        let servings = 1u32;
        let tip = ((RATING - 20).max(0) / 2) as f64;
        let revenue = (100.0 + tip) * servings as f64 * self.price * 0.01;
        let ingredient_cost = UNIT_COST * servings as f64;
        let market_cost = ingredient_cost * MARKET_PRICE_FACTOR;
        let cash_delta = revenue - market_cost;
        self.stock -= servings as f64;
        self.servings_sold += servings;
        self.customers_served += 1;
        self.sales += 1;
        self.cash += cash_delta;
        let sale = Sale {
            clock_minutes,
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
            clock_minutes: snapshot.clock_minutes,
            servings_sold: snapshot.servings_sold,
            customers_served: snapshot.customers_served,
            customers_lost: snapshot.customers_lost,
            sales: snapshot.sales,
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
        "{{\"clock_minutes\":{},\"price\":{:.6},\"servings\":{},\"revenue\":{:.6},\"stock_cost\":{:.6},\"market_cost\":{:.6},\"cash_delta\":{:.6}}}",
        sale.clock_minutes,
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
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum GameMode {
    Campaign,
    FreeGame,
}

#[derive(Clone, Debug, PartialEq, Eq)]
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

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct CampaignBranch {
    pub owner_slot: u8,
    pub size: u8,
    pub style: u8,
    pub owned: bool,
}

#[derive(Clone, Debug, PartialEq, Eq)]
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

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct CampaignPropertyOffer {
    pub tile_index: u32,
    pub price: u32,
}

/// The launch values committed by `Screen_FreePlaySetup` / the Start handler
/// at `0x4cd33d..0x4cd4cc`. The selected city record's `+0x40` short name is
/// copied to `DAT_0057bb44`; `DAT_0057bb28` is the population, `DAT_0057bb2c`
/// the game length, and `DAT_0057bb48/4c/50` are the three opponent slots.
#[derive(Clone, Debug, PartialEq, Eq)]
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

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
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
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum CustomerPhase {
    Queued,
    Waiting,
    Producing,
    Departing,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Customer {
    pub id: u32,
    pub party_size: u32,
    pub phase: CustomerPhase,
    pub slot: Option<u32>,
    pub arrived_minute: u32,
    pub phase_started: u32,
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
    QuarterBoundary {
        minute: u32,
        hour: u32,
    },
}

#[derive(Clone, Debug, PartialEq)]
pub struct WorldSnapshot {
    pub minute: u32,
    pub queue: u32,
    pub hourly_count: u32,
    pub visit_state: VisitState,
    pub state_started: u32,
    pub customers: Vec<Customer>,
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
            profile: None,
            scenario: None,
            leased_property: None,
            sim,
        }
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

    pub fn campaign_property_offer(&self) -> Option<CampaignPropertyOffer> {
        self.campaign_mission()?.property_offer
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
        let price = f64::from(offer.price);
        if self.sim.cash < price {
            return Err("insufficient funds");
        }
        self.sim.cash -= price;
        self.leased_property = Some(tile_index);
        Ok(offer.price)
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
        for _ in 0..queue {
            self.push_queued_party(1);
        }
        self.admit_next();
        self
    }

    /// Add one arriving party. This is the replay/CLI hook for the two-party
    /// fixture; automatic hourly arrivals use the same path.
    pub fn enqueue_party(&mut self, party_size: u32) -> u32 {
        let id = self.push_queued_party(party_size.max(1));
        self.admit_next();
        id
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
                    "{{\"id\":{},\"party_size\":{},\"phase\":\"{}\",\"slot\":{},\"arrived_minute\":{},\"phase_started\":{}}}",
                    customer.id,
                    customer.party_size,
                    phase,
                    slot,
                    customer.arrived_minute,
                    customer.phase_started
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
            "{{\"queue\":{},\"visit_state\":\"{}\",\"state_started\":{},\"customers\":[{}]}}",
            self.queue, visit_state, self.state_started, customers
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
            profile: snapshot.profile.clone(),
            scenario: snapshot.scenario.clone(),
            leased_property: snapshot.leased_property,
            sim: BranchSim::from_snapshot(&snapshot.sim),
        }
    }

    pub fn step(&mut self) -> Vec<ClockEvent> {
        self.advance_to(self.minute + 5)
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
            let minute_of_day = self.minute % (24 * 60);
            if minute_of_day % 60 == 0 {
                let hour = (minute_of_day / 60) % 24;
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
                    self.sync_queue();
                    events.push(ClockEvent::ProductionStart {
                        minute: self.minute,
                    });
                }
                CustomerPhase::Producing if self.minute >= started + 5 => {
                    let remaining = self.queued_count();
                    self.customers[index].phase = CustomerPhase::Departing;
                    self.customers[index].phase_started = self.minute;
                    self.sync_queue();
                    events.push(ClockEvent::QueueService {
                        minute: self.minute,
                        remaining_queue: remaining,
                    });
                    if let StepOutcome::Sale(sale) = self.sim.settle_sale_at(self.minute) {
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
                    price: 5_730,
                }),
            },
        );
        let mut world = World::new(0).with_scenario(scenario);
        world.sim.set_starting_cash(500_000.0);
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
        low_cash.sim.cash = 5_729.0;
        let mut poor = World::from_snapshot(&low_cash);
        assert_eq!(
            poor.lease_campaign_property(13_694),
            Err("insufficient funds")
        );
        assert_eq!(poor.world_snapshot(), low_cash);

        assert_eq!(world.lease_campaign_property(13_694), Ok(5_730));
        assert!(world.can_enter_branch());
        let leased = world.world_snapshot();
        assert_eq!(leased.leased_property, Some(13_694));
        assert_eq!(leased.sim.cash, 494_270.0);
        let mut restored = World::from_snapshot(&leased);
        assert!(restored.can_enter_branch());
        assert_eq!(
            restored.lease_campaign_property(13_694),
            Err("property is already leased")
        );
        assert_eq!(restored.world_snapshot(), leased);
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
