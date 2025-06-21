#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "CharacterConstants.hpp"

namespace squigrodeo {

struct Skill {
    int training = 0;
    int focus = 0;
};

struct SkillTable {
    SkillTable(const std::string &name) : tableName{name} {}

    // Table Name
    std::string tableName;

    // Skills
    std::array<Skill, SKILL_NAMES.size()> skillValues;

    // Render Function
    void render();

    // Cost Function
    int getCost();
};

struct AttributeTable {
    AttributeTable(const std::string &name) : tableName{name} {}

    // Table Name
    std::string tableName;

    // Attributes
    int body = 0;
    int mind = 0;
    int soul = 0;

    // Render Function
    void render();

    // Cost Function
    int getCost();
};

struct CharacterSheet {
    CharacterSheet(const std::string &name)
        : charName{name},
          skills{name + "_skills"},
          attributes{name + "_attributes"} {
        strcpy(displayCharName.data(), name.data());
    }

    // Character Name
    std::string charName;
    std::array<char, MAX_CHAR_NAME_SIZE> displayCharName;

    SkillTable skills;
    AttributeTable attributes;
    int aquaGhyranis = 0;
    int xpCount = 35;

    // Render Function
    void render();

    // Cost Function
    int getCost();
};
}  // namespace squigrodeo
