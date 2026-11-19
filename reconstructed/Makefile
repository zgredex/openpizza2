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

check: $(SETTINGS_BIN) $(INGREDIENT_BIN) $(MISSION_STATE_BIN) $(MISSION_GOALS_BIN)
	./$(SETTINGS_BIN)
	./$(INGREDIENT_BIN)
	./$(MISSION_STATE_BIN)
	./$(MISSION_GOALS_BIN)

clean:
	rm -rf $(BUILD)
