#include "Bestiary.hpp"

#include "imgui.h"

void squigrodeo::Bestiary::renderWindow() {
    if (ImGui::BeginTabBar("BestiaryTabBar",
                           ImGuiTabBarFlags_AutoSelectNewTabs)) {
        if (ImGui::TabItemButton("+", ImGuiTabItemFlags_Trailing |
                                          ImGuiTabItemFlags_NoTooltip)) {
            monsters.emplace_back("monsters_" + std::to_string(nextId));
            ++nextId;
        }

        for (int idx = 0; idx < monsters.size();) {
            bool open = true;
            if (ImGui::BeginTabItem(monsters[idx].getName().data(), &open,
                                    ImGuiTabItemFlags_None)) {
                monsters[idx].renderEditor();
                ImGui::EndTabItem();
            }

            if (!open)
                monsters.erase(std::next(monsters.begin(), idx));
            else
                idx++;
        }

        ImGui::EndTabBar();
    }
}