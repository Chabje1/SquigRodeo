#pragma once

#include <vector>

#include "CharacterSheet.hpp"

namespace squigrodeo {
struct CharacterList {
    std::vector<CharacterSheet> characters;

    void renderWindow();
};
}  // namespace squigrodeo