CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Werror
BUILD ?= build

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

ASSETS_SRC = assets/assets.c assets/test_assets.c
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
               ui_screen/ui_screen.c options/options_state.c statistics/statistics_state.c ai/ai_state.c recipes/recipe_state.c personnel/personnel_state.c render/render_state.c operations/branch_operations.c assets/assets.c save/save_state.c piz/piz_container.c \
               construction/construction_state.c mission/mission_state.c \
               mission/mission_goals.c branch/branch_economy.c city/city_state.c
GAME_SRC = $(GAME_MODULES) test_game.c
GAME_BIN = $(BUILD)/test_game

FULL_GAME_BIN = $(BUILD)/pc2-reconstructed
FULL_GAME_SRC = $(GAME_MODULES) full_game.c

.PHONY: all check full-game clean

all: check full-game

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

$(ASSETS_BIN): $(ASSETS_SRC) $(ASSETS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(ASSETS_SRC) -o $@

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

check: $(SETTINGS_BIN) $(INGREDIENT_BIN) $(MISSION_STATE_BIN) $(MISSION_GOALS_BIN) $(BRANCH_BIN) $(CONSTRUCTION_BIN) $(SAVE_BIN) $(PIZ_BIN) $(AI_BIN) $(RECIPE_BIN) $(PERSONNEL_BIN) $(RENDER_BIN) $(OPERATIONS_BIN) $(ASSETS_BIN) $(MENU_BIN) $(UI_BIN) $(OPTIONS_BIN) $(STATISTICS_BIN) $(CITY_BIN) $(GAME_BIN)
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
	./$(ASSETS_BIN)
	./$(MENU_BIN)
	./$(UI_BIN)
	./$(OPTIONS_BIN)
	./$(STATISTICS_BIN)
	./$(CITY_BIN)
	./$(GAME_BIN)

clean:
	rm -rf $(BUILD)
