#pragma once

#include <vector>

#include "CharacterSheet.hpp"

namespace squigrodeo {
struct Party {
    std::vector<CharacterSheet> players;
    int soulfire = 0;
    int doom = 0;
};
}  // namespace squigrodeo