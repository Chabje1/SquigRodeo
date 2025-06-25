#pragma once

#include <vector>

#include "CharacterSheet.hpp"

namespace squigrodeo {
struct CharacterList {
    std::vector<CharacterSheet> monsters;

    void renderWindow();
};
}  // namespace squigrodeo