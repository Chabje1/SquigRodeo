#include "CharacterList.hpp"

#include "imgui.h"

void squigrodeo::CharacterList::renderWindow() {
    if (characters.size() != 0) {
        if (ImGui::BeginCombo("##CharacterListComboMenu",
                              characters[selectedCharacter].getName().data())) {
            for (int idx = 0; idx < characters.size(); idx++) {
                const bool is_selected = (selectedCharacter == idx);

                if (ImGui::Selectable(
                        (characters[idx].getName() +
                         "##CharacterListComboMenu_item_" + std::to_string(idx))
                            .data(),
                        is_selected)) {
                    selectedCharacter = idx;
                }

                // Set the initial focus when opening the combo (scrolling +
                // keyboard navigation focus)
                if (is_selected) ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }

        ImGui::SameLine();
    }

    if (ImGui::Button("+")) {
        characters.emplace_back("<Character Name>");
    }

    if (characters.size() != 0) {
        ImGui::SameLine();

        if (ImGui::Button("-")) {
            characters.erase(std::next(characters.begin(), selectedCharacter));
            selectedCharacter = 0;
        }

        ImGui::SameLine();

        if (ImGui::Button(
                "Play this Character##CharacterListEditor_play_button")) {
            parentFocused = &characters[selectedCharacter];
        }

        characters[selectedCharacter].renderEditor("CharacterListEditor");
    }
}