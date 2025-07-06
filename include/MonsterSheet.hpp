#pragma once

#include <string>
#include <vector>

#include "MADTable.hpp"
#include "Viewable.hpp"

namespace squigrodeo {
struct Attack {
    Attack(const std::string& name) : attackName(name) {}

    std::string attackName;
    int numD6 = 0;
    bool isRanged = false;
    int focus = 0;
};

class MonsterSheet : public Viewable {
   public:
    MonsterSheet(const std::string& name)
        : monsterName{name}, madValues{name + "_mad"} {}

    void renderViewer(const std::string& renderId) override;
    void renderEditor(const std::string& renderId) override;
    std::string getName() override;

   private:
    std::string monsterName;
    int size = -1;
    std::string species;
    int type = -1;
    MADTable madValues;
    int initiative = 0;
    int remainingToughness = 0;
    int remainingWounds = 0;
    int remainingMettle = 0;
    int armour = 0;
    std::vector<Attack> attacks;
};

}  // namespace squigrodeo
