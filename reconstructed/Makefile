CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Werror
BUILD ?= build
DECOMP_PYTHON ?= python3

LEAF_SRC = leaf/leaf_functions.c leaf/test_leaf_functions.c
LEAF_HDR = leaf/leaf_functions.h
LEAF_BIN = $(BUILD)/test_leaf_functions

FREEPLAY_SRC = freeplay/freeplay_profiles.c freeplay/test_freeplay_profiles.c
FREEPLAY_HDR = freeplay/freeplay_profiles.h
FREEPLAY_BIN = $(BUILD)/test_freeplay_profiles

CHARACTER_SRC = character/character_state.c character/test_character_state.c
CHARACTER_HDR = character/character_state.h
CHARACTER_BIN = $(BUILD)/test_character_state

PLAYER_SRC = player/player_state.c player/test_player_state.c
PLAYER_HDR = player/player_state.h character/character_state.h
PLAYER_BIN = $(BUILD)/test_player_state

RATING_SRC = rating/rating_state.c rating/test_rating_state.c
RATING_HDR = rating/rating_state.h
RATING_BIN = $(BUILD)/test_rating_state

ADVERTISING_SRC = advertising/value_state.c advertising/test_value_state.c
ADVERTISING_HDR = advertising/value_state.h
ADVERTISING_BIN = $(BUILD)/test_value_state

MAP_SRC = map/iso_map.c map/map_render.c map/test_map_render.c render/render_state.c assets/assets.c
MAP_HDR = map/iso_map.h map/map_render.h render/render_state.h assets/assets.h
MAP_BIN = $(BUILD)/test_map_render

SETTINGS_SRC = settings/settings.c settings/test_settings.c
SETTINGS_HDR = settings/settings.h
SETTINGS_BIN = $(BUILD)/test_settings

INGREDIENT_SRC = ingredient/ingredient.c ingredient/test_ingredient.c
INGREDIENT_HDR = ingredient/ingredient.h
INGREDIENT_BIN = $(BUILD)/test_ingredient

MISSION_STATE_SRC = mission/mission_state.c mission/mission_goals.c
MISSION_STATE_HDR = mission/mission_state.h mission/mission_goals.h
MISSION_STATE_BIN = $(BUILD)/test_mission
MISSION_GOALS_BIN = $(BUILD)/test_mission_goals

BRANCH_SRC = branch/branch_economy.c branch/test_branch_economy.c
BRANCH_HDR = branch/branch_economy.h
BRANCH_BIN = $(BUILD)/test_branch_economy

CONSTRUCTION_SRC = construction/construction_state.c construction/test_construction_state.c
CONSTRUCTION_HDR = construction/construction_state.h
CONSTRUCTION_BIN = $(BUILD)/test_construction_state

SAVE_SRC = save/save_state.c settings/settings.c save/test_save_state.c
SAVE_HDR = save/save_state.h settings/settings.h mission/mission_state.h
SAVE_BIN = $(BUILD)/test_save_state

MENU_SRC = menu/menu_state.c menu/test_menu_state.c
MENU_HDR = menu/menu_state.h
MENU_BIN = $(BUILD)/test_menu_state

SCREEN_SRC = screen/screen_render.c screen/statistics_balance_layout.c screen/office_desk_layout.c screen/character_select_layout.c screen/free_play_layout.c screen/warehouse_layout.c screen/building_project_layout.c screen/end_results_layout.c screen/personnel_record_layout.c screen/test_screen_render.c ui_render/ui_render.c assets/assets.c assets/ani.c render/render_state.c menu/menu_state.c statistics/statistics_state.c
SCREEN_HDR = screen/screen_render.h ui_render/ui_render.h assets/assets.h render/render_state.h menu/menu_state.h statistics/statistics_state.h
SCREEN_BIN = $(BUILD)/test_screen_render

UI_RENDER_SRC = ui_render/ui_render.c ui_render/test_ui_render.c assets/assets.c render/render_state.c
UI_RENDER_HDR = ui_render/ui_render.h assets/assets.h render/render_state.h
UI_RENDER_BIN = $(BUILD)/test_ui_render

ASSETS_SRC = assets/assets.c assets/ani.c assets/test_assets.c
ASSETS_HDR = assets/assets.h
ASSETS_BIN = $(BUILD)/test_assets

OPERATIONS_SRC = operations/branch_operations.c operations/test_branch_operations.c
OPERATIONS_HDR = operations/branch_operations.h
OPERATIONS_BIN = $(BUILD)/test_branch_operations

RENDER_SRC = render/render_state.c render/test_render_state.c
RENDER_HDR = render/render_state.h
RENDER_BIN = $(BUILD)/test_render_state

AI_SRC = ai/ai_state.c ai/test_ai_state.c
AI_HDR = ai/ai_state.h
AI_BIN = $(BUILD)/test_ai_state

RECIPE_SRC = recipes/recipe_state.c recipes/test_recipe_state.c
RECIPE_HDR = recipes/recipe_state.h
RECIPE_BIN = $(BUILD)/test_recipe_state

PERSONNEL_SRC = personnel/personnel_state.c personnel/test_personnel_state.c
PERSONNEL_HDR = personnel/personnel_state.h
PERSONNEL_BIN = $(BUILD)/test_personnel_state

PIZ_SRC = piz/piz_container.c settings/settings.c save/save_state.c piz/test_piz_container.c
PIZ_HDR = piz/piz_container.h settings/settings.h save/save_state.h
PIZ_BIN = $(BUILD)/test_piz_container

STATISTICS_SRC = statistics/statistics_state.c statistics/test_statistics_state.c
STATISTICS_HDR = statistics/statistics_state.h
STATISTICS_BIN = $(BUILD)/test_statistics_state

OPTIONS_SRC = options/options_state.c settings/settings.c options/test_options_state.c
OPTIONS_HDR = options/options_state.h settings/settings.h
OPTIONS_BIN = $(BUILD)/test_options_state

UI_SRC = ui_screen/ui_screen.c ui_screen/test_ui_screen.c menu/menu_state.c
UI_HDR = ui_screen/ui_screen.h menu/menu_state.h
UI_BIN = $(BUILD)/test_ui_screen

CITY_SRC = city/city_state.c city/test_city_state.c $(MISSION_STATE_SRC) branch/branch_economy.c
CITY_HDR = city/city_state.h $(MISSION_STATE_HDR) branch/branch_economy.h
CITY_BIN = $(BUILD)/test_city_state

GAME_MODULES = settings/settings.c ingredient/ingredient.c menu/menu_state.c \
               ui_screen/ui_screen.c options/options_state.c statistics/statistics_state.c ai/ai_state.c recipes/recipe_state.c personnel/personnel_state.c render/render_state.c operations/branch_operations.c advertising/value_state.c rating/rating_state.c assets/assets.c assets/ani.c leaf/leaf_functions.c freeplay/freeplay_profiles.c character/character_state.c player/player_state.c map/iso_map.c map/map_render.c ui_render/ui_render.c screen/screen_render.c screen/statistics_balance_layout.c screen/office_desk_layout.c screen/character_select_layout.c screen/free_play_layout.c screen/warehouse_layout.c screen/building_project_layout.c screen/end_results_layout.c screen/personnel_record_layout.c save/save_state.c piz/piz_container.c \
               construction/construction_state.c mission/mission_state.c \
               mission/mission_goals.c branch/branch_economy.c city/city_state.c
GAME_SRC = $(GAME_MODULES) test_game.c
GAME_BIN = $(BUILD)/test_game

FULL_GAME_BIN = $(BUILD)/pc2-reconstructed
FULL_GAME_SRC = $(GAME_MODULES) full_game.c

.PHONY: all check check-decomp full-game clean

all: check full-game

check-decomp:
	$(DECOMP_PYTHON) ../tools/check_decomp.py check
	$(DECOMP_PYTHON) ../tools/check_decomp.py self-test

$(LEAF_BIN): $(LEAF_SRC) $(LEAF_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(LEAF_SRC) -o $@

$(FREEPLAY_BIN): $(FREEPLAY_SRC) $(FREEPLAY_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(FREEPLAY_SRC) -o $@

$(CHARACTER_BIN): $(CHARACTER_SRC) $(CHARACTER_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(CHARACTER_SRC) -o $@

$(PLAYER_BIN): $(PLAYER_SRC) $(PLAYER_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(PLAYER_SRC) -o $@

$(RATING_BIN): $(RATING_SRC) $(RATING_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(RATING_SRC) -o $@

$(ADVERTISING_BIN): $(ADVERTISING_SRC) $(ADVERTISING_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(ADVERTISING_SRC) -lm -o $@

$(MAP_BIN): $(MAP_SRC) $(MAP_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MAP_SRC) -o $@

$(SETTINGS_BIN): $(SETTINGS_SRC) $(SETTINGS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SETTINGS_SRC) -o $@

$(INGREDIENT_BIN): $(INGREDIENT_SRC) $(INGREDIENT_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INGREDIENT_SRC) -o $@

$(MISSION_STATE_BIN): $(MISSION_STATE_SRC) $(MISSION_STATE_HDR) mission/test_mission.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MISSION_STATE_SRC) mission/test_mission.c -o $@

$(MISSION_GOALS_BIN): $(MISSION_STATE_SRC) $(MISSION_STATE_HDR) mission/test_mission_goals.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MISSION_STATE_SRC) mission/test_mission_goals.c -o $@

$(BRANCH_BIN): $(BRANCH_SRC) $(BRANCH_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(BRANCH_SRC) -lm -o $@

$(CONSTRUCTION_BIN): $(CONSTRUCTION_SRC) $(CONSTRUCTION_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(CONSTRUCTION_SRC) -o $@

$(SAVE_BIN): $(SAVE_SRC) $(SAVE_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SAVE_SRC) -o $@

$(MENU_BIN): $(MENU_SRC) $(MENU_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MENU_SRC) -o $@

$(SCREEN_BIN): $(SCREEN_SRC) $(SCREEN_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SCREEN_SRC) -o $@

$(UI_RENDER_BIN): $(UI_RENDER_SRC) $(UI_RENDER_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(UI_RENDER_SRC) -o $@

$(ASSETS_BIN): $(ASSETS_SRC) $(ASSETS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(ASSETS_SRC) -o $@

ANI_SRC = assets/ani.c assets/test_ani.c
ANI_HDR = assets/ani.h render/render_state.h
ANI_BIN = $(BUILD)/test_ani

$(ANI_BIN): $(ANI_SRC) $(ANI_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(ANI_SRC) -o $@

$(OPERATIONS_BIN): $(OPERATIONS_SRC) $(OPERATIONS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(OPERATIONS_SRC) -lm -o $@

$(RENDER_BIN): $(RENDER_SRC) $(RENDER_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(RENDER_SRC) -o $@

$(AI_BIN): $(AI_SRC) $(AI_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(AI_SRC) -o $@

$(RECIPE_BIN): $(RECIPE_SRC) $(RECIPE_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(RECIPE_SRC) -lm -o $@

$(PERSONNEL_BIN): $(PERSONNEL_SRC) $(PERSONNEL_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(PERSONNEL_SRC) -o $@

$(PIZ_BIN): $(PIZ_SRC) $(PIZ_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(PIZ_SRC) -o $@

$(STATISTICS_BIN): $(STATISTICS_SRC) $(STATISTICS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(STATISTICS_SRC) -o $@

$(OPTIONS_BIN): $(OPTIONS_SRC) $(OPTIONS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(OPTIONS_SRC) -o $@

$(UI_BIN): $(UI_SRC) $(UI_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(UI_SRC) -o $@

$(CITY_BIN): $(CITY_SRC) $(CITY_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(CITY_SRC) -lm -o $@

$(GAME_BIN): $(GAME_SRC) $(CITY_HDR) $(BRANCH_HDR) $(INGREDIENT_HDR) $(SETTINGS_HDR) $(UI_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(GAME_SRC) -lm -o $@

$(FULL_GAME_BIN): $(FULL_GAME_SRC) $(CITY_HDR) $(BRANCH_HDR) $(INGREDIENT_HDR) $(SETTINGS_HDR) $(UI_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(FULL_GAME_SRC) -lm -o $@

full-game: $(FULL_GAME_BIN)
	./$(FULL_GAME_BIN)

check: $(SETTINGS_BIN) $(INGREDIENT_BIN) $(MISSION_STATE_BIN) $(MISSION_GOALS_BIN) $(BRANCH_BIN) $(CONSTRUCTION_BIN) $(SAVE_BIN) $(PIZ_BIN) $(AI_BIN) $(RECIPE_BIN) $(PERSONNEL_BIN) $(RENDER_BIN) $(OPERATIONS_BIN) $(ADVERTISING_BIN) $(RATING_BIN) $(LEAF_BIN) $(FREEPLAY_BIN) $(CHARACTER_BIN) $(PLAYER_BIN) $(ASSETS_BIN) $(ANI_BIN) $(MAP_BIN) $(UI_RENDER_BIN) $(SCREEN_BIN) $(MENU_BIN) $(UI_BIN) $(OPTIONS_BIN) $(STATISTICS_BIN) $(CITY_BIN) $(GAME_BIN)
	./$(SETTINGS_BIN)
	./$(INGREDIENT_BIN)
	./$(MISSION_STATE_BIN)
	./$(MISSION_GOALS_BIN)
	./$(BRANCH_BIN)
	./$(CONSTRUCTION_BIN)
	./$(SAVE_BIN)
	./$(PIZ_BIN)
	./$(AI_BIN)
	./$(RECIPE_BIN)
	./$(PERSONNEL_BIN)
	./$(RENDER_BIN)
	./$(OPERATIONS_BIN)
	./$(ADVERTISING_BIN)
	./$(RATING_BIN)
	./$(LEAF_BIN)
	./$(FREEPLAY_BIN)
	./$(CHARACTER_BIN)
	./$(PLAYER_BIN)
	./$(ASSETS_BIN) $(ANI_BIN)
	./$(MAP_BIN)
	./$(UI_RENDER_BIN)
	./$(SCREEN_BIN)
	./$(MENU_BIN)
	./$(UI_BIN)
	./$(OPTIONS_BIN)
	./$(STATISTICS_BIN)
	./$(CITY_BIN)
	./$(GAME_BIN)

clean:
	rm -rf $(BUILD)
