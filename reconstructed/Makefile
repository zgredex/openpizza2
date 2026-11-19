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

SAVE_SRC = save/save_state.c settings/settings.c save/test_save_state.c
SAVE_HDR = save/save_state.h settings/settings.h mission/mission_state.h
SAVE_BIN = $(BUILD)/test_save_state

MENU_SRC = menu/menu_state.c menu/test_menu_state.c
MENU_HDR = menu/menu_state.h
MENU_BIN = $(BUILD)/test_menu_state

CITY_SRC = city/city_state.c city/test_city_state.c $(MISSION_STATE_SRC) branch/branch_economy.c
CITY_HDR = city/city_state.h $(MISSION_STATE_HDR) branch/branch_economy.h
CITY_BIN = $(BUILD)/test_city_state

GAME_SRC = settings/settings.c ingredient/ingredient.c mission/mission_state.c \
           mission/mission_goals.c branch/branch_economy.c city/city_state.c \
           menu/menu_state.c save/save_state.c test_game.c
GAME_BIN = $(BUILD)/test_game

.PHONY: all check clean

all: check

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

$(SAVE_BIN): $(SAVE_SRC) $(SAVE_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SAVE_SRC) -o $@

$(MENU_BIN): $(MENU_SRC) $(MENU_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MENU_SRC) -o $@

$(CITY_BIN): $(CITY_SRC) $(CITY_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(CITY_SRC) -lm -o $@

$(GAME_BIN): $(GAME_SRC) $(CITY_HDR) $(BRANCH_HDR) $(INGREDIENT_HDR) $(SETTINGS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(GAME_SRC) -lm -o $@

check: $(SETTINGS_BIN) $(INGREDIENT_BIN) $(MISSION_STATE_BIN) $(MISSION_GOALS_BIN) $(BRANCH_BIN) $(SAVE_BIN) $(MENU_BIN) $(CITY_BIN) $(GAME_BIN)
	./$(SETTINGS_BIN)
	./$(INGREDIENT_BIN)
	./$(MISSION_STATE_BIN)
	./$(MISSION_GOALS_BIN)
	./$(BRANCH_BIN)
	./$(SAVE_BIN)
	./$(MENU_BIN)
	./$(CITY_BIN)
	./$(GAME_BIN)

clean:
	rm -rf $(BUILD)
