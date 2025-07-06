#pragma once

#include <vector>

#include "MonsterSheet.hpp"

namespace squigrodeo {
struct Bestiary {
    Bestiary(Viewable*& rpFocused) : parentFocused{rpFocused} {}

    Viewable*& parentFocused;
    std::vector<MonsterSheet> monsters;
    uint32_t nextId = 0;
    int selectedMonster = 0;
    void renderWindow();
};
}  // namespace squigrodeo