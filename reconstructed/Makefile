CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Werror
BUILD ?= build

SETTINGS_SRC = settings/settings.c settings/test_settings.c
SETTINGS_HDR = settings/settings.h
SETTINGS_BIN = $(BUILD)/test_settings

INGREDIENT_SRC = ingredient/ingredient.c ingredient/test_ingredient.c
INGREDIENT_HDR = ingredient/ingredient.h
INGREDIENT_BIN = $(BUILD)/test_ingredient

MISSION_SRC = mission/mission_state.c mission/test_mission.c
MISSION_HDR = mission/mission_state.h
MISSION_BIN = $(BUILD)/test_mission

.PHONY: all check clean

all: check

$(SETTINGS_BIN): $(SETTINGS_SRC) $(SETTINGS_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SETTINGS_SRC) -o $@

$(INGREDIENT_BIN): $(INGREDIENT_SRC) $(INGREDIENT_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INGREDIENT_SRC) -o $@

$(MISSION_BIN): $(MISSION_SRC) $(MISSION_HDR)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(MISSION_SRC) -o $@

check: $(SETTINGS_BIN) $(INGREDIENT_BIN) $(MISSION_BIN)
	./$(SETTINGS_BIN)
	./$(INGREDIENT_BIN)
	./$(MISSION_BIN)

clean:
	rm -rf $(BUILD)
