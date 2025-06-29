#pragma once

#include <vector>

#include "CharacterSheet.hpp"

namespace squigrodeo {
struct CharacterList {
    std::vector<CharacterSheet> characters;
    uint32_t nextId = 0;
    void renderWindow();
};
}  // namespace squigrodeo