#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "CharacterConstants.hpp"
#include "MADTable.hpp"
#include "Viewable.hpp"

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

struct Talent {
    std::string name;
    std::string description;
};

class CharacterSheet : public Viewable {
   public:
    CharacterSheet(const std::string &name)
        : charName{name},
          skills{name + "_skills"},
          attributes{name + "_attributes"} {}

    // Render Functions
    void renderViewer() override;
    void renderEditor() override;

    // Getter Functions
    int getCost();
    std::string getName() override;

   private:
    // Character Name
    std::string charName;

    // Things that cost XP
    SkillTable skills;
    AttributeTable attributes;
    int xpCount = 35;

    // Things that don't
    int aquaGhyranis = 200;
    std::string shortTermGoal;
    std::string longTermGoal;

    // MAD Table
    MADTable mad;
};
}  // namespace squigrodeo
