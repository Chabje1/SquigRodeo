#pragma once

#include <vector>

#include "MonsterSheet.hpp"

namespace squigrodeo {
struct Bestiary {
    std::vector<MonsterSheet> monsters;

    void renderWindow();
};
}  // namespace squigrodeo