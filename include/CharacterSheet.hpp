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
    int getUsedXP();
};

struct AttributeTable {
    AttributeTable(const std::string &name) : tableName{name} {}

    // Table Name
    std::string tableName;

    // Attributes
    int body = 1;
    int mind = 1;
    int soul = 1;

    // Render Function
    void render();

    // Cost Function
    int getUsedXP();
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
          attributes{name + "_attributes"},
          mad{name + "_mad"} {}

    // Render Functions
    void renderViewer(const std::string &renderId) override;
    void renderEditor(const std::string &renderId) override;

    // Getter Functions
    int getUsedXP();
    std::string getName() override;
    int getIniative();
    int getTotalToughness();
    int getTotalMettle();
    int getTotalWounds();
    int getNaturalAwareness();

   private:
    // Update MAD Stats
    void setMADStats();

    // Character Name
    std::string charName;

    // Things that cost XP
    SkillTable skills;
    AttributeTable attributes;
    int xpCount = 35;
    int numberOfTalents = 0;

    // Things that don't
    int aquaGhyranis = 200;
    std::string shortTermGoal;
    std::string longTermGoal;

    int remainingMettle = 0;
    int remainingToughness = 0;
    int remainingWounds = 0;
    int armour = 0;

    // MAD Table
    MADTable mad;
    bool hasShield = false;
};
}  // namespace squigrodeo
