#pragma once

#include <string>
#include <vector>

#include "MADTable.hpp"
#include "Viewable.hpp"

namespace squigrodeo {
struct Attack {
    std::string name;
    int numD6 = 0;
    bool isRanged = false;
    int focus = 0;
};

class MonsterSheet : public Viewable {
   public:
    MonsterSheet(const std::string& name)
        : monsterName{name}, madValues{name + "_mad"} {}

    void renderViewer() override;
    void renderEditor() override;
    std::string getName() override;

   private:
    std::string monsterName;
    MADTable madValues;
    int initiative;
    int remainingToughness;
    int remainingWounds;
    int remainingMettle;
    int armour;
    std::vector<Attack> attacks;
};

}  // namespace squigrodeo
