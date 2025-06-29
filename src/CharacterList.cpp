#include "CharacterList.hpp"

#include "imgui.h"

void squigrodeo::CharacterList::renderWindow() {
    if (ImGui::BeginTabBar("CharacterListTabBar",
                           ImGuiTabBarFlags_AutoSelectNewTabs)) {
        if (ImGui::TabItemButton(
                "+", ImGuiTabItemFlags_Trailing | ImGuiTabItemFlags_NoTooltip))
            characters.emplace_back("characters_" +
                                    std::to_string(characters.size()));

        for (int idx = 0; idx < characters.size();) {
            bool open = true;
            if (ImGui::BeginTabItem(characters[idx].getName().data(), &open,
                                    ImGuiTabItemFlags_None)) {
                characters[idx].renderEditor();
                ImGui::EndTabItem();
            }

            if (!open)
                characters.erase(std::next(characters.begin(), idx));
            else
                idx++;
        }

        ImGui::EndTabBar();
    }
}