#pragma once

#include <vector>

#include "CharacterSheet.hpp"

namespace squigrodeo {
struct CharacterList {
    CharacterList(Viewable*& rpFocused) : parentFocused{rpFocused} {}

    Viewable*& parentFocused;
    std::vector<CharacterSheet> characters;
    uint32_t nextId = 0;
    int selectedCharacter = 0;
    void renderWindow();
};
}  // namespace squigrodeo