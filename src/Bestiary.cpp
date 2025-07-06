#include "Bestiary.hpp"

#include "imgui.h"

void squigrodeo::Bestiary::renderWindow() {
    if (monsters.size() != 0) {
        if (ImGui::BeginCombo("##BestiaryComboMenu",
                              monsters[selectedMonster].getName().data())) {
            for (int idx = 0; idx < monsters.size(); idx++) {
                const bool is_selected = (selectedMonster == idx);

                if (ImGui::Selectable(
                        (monsters[idx].getName() + "##BestiaryComboMenu_item_" +
                         std::to_string(idx))
                            .data(),
                        is_selected)) {
                    selectedMonster = idx;
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
        monsters.emplace_back("<Monster Name>");
    }

    if (monsters.size() != 0) {
        ImGui::SameLine();

        if (ImGui::Button("-")) {
            monsters.erase(std::next(monsters.begin(), selectedMonster));
            selectedMonster = 0;
        }

        monsters[selectedMonster].renderEditor("BestiaryEditor");
    }
}