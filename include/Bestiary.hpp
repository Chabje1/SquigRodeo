#pragma once

#include <vector>

#include "MonsterSheet.hpp"

namespace squigrodeo {
struct Bestiary {
    std::vector<MonsterSheet> monsters;
    uint32_t nextId = 0;
    void renderWindow();
};
}  // namespace squigrodeo