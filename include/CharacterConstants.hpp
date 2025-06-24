#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace squigrodeo {

constexpr uint8_t WEAPON_SKILL_INDEX = 23;
constexpr uint8_t BALLISTIC_SKILL_INDEX = 3;
constexpr uint8_t REFLEXES_SKILL_INDEX = 19;

constexpr auto SKILL_NAMES = std::to_array<std::string_view>(
    {"Arcana",         "Athletics",    "Awareness", "Ballistic Skill",
     "Beast Handling", "Channelling",  "Crafting",  "Determination",
     "Devotion",       "Dexterity",    "Entertain", "Fortitude",
     "Guile",          "Intimidation", "Intuition", "Lore",
     "Medicine",       "Might",        "Nature",    "Reflexes",
     "Stealth",        "Survival",     "Theology",  "Weapon Skill"});

constexpr std::size_t MAX_CHAR_NAME_SIZE = 32;

constexpr uint8_t TALENT_BASE_COST = 2;

constexpr uint8_t MAX_SKILL_LEVEL = 3;

constexpr std::array<uint8_t, MAX_SKILL_LEVEL + 1> SKILL_COST_PER_LEVEL = {
    0, 1, 3, 7};

constexpr uint8_t MAX_ATTRIBUTE_LEVEL = 8;

constexpr std::array<uint8_t, MAX_ATTRIBUTE_LEVEL + 1>
    ATTRIBUTE_COST_PER_LEVEL = {0, 0, 2, 7, 14, 23, 34, 47, 62};

}  // namespace squigrodeo
