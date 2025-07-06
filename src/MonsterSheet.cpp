#include "MonsterSheet.hpp"

#include "imgui.h"
#include "imgui_stdlib.h"

static const char* SIZE_LABELS[] = {"Tiny",  "Small",    "Medium",
                                    "Large", "Enormous", "Monstrous"};

static const char* TYPE_LABELS[] = {"Automaton", "Beast",  "Daemon",
                                    "Mortal",    "Spirit", "Undead"};

void squigrodeo::MonsterSheet::renderViewer(const std::string& renderId) {}

void squigrodeo::MonsterSheet::renderEditor(const std::string& renderId) {
    // Display Monster Name
    ImGui::Text("Monster Name: ");
    ImGui::SameLine();
    ImGui::InputText(("##" + renderId + "_display_name").data(), &monsterName);

    // Display Table
    if (ImGui::BeginTable((renderId + "_type_size_species").data(), 3)) {
        ImGui::TableNextRow();

        // Display Size
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Size: ");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
        ImGui::Combo(("##" + renderId + "_size").data(), &size, SIZE_LABELS,
                     IM_ARRAYSIZE(SIZE_LABELS));
        ImGui::SameLine();

        // Display Species
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("Species: ");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.75f);
        ImGui::InputText(("##" + renderId + "_species").data(), &species);
        ImGui::SameLine();

        // Display Type
        ImGui::TableSetColumnIndex(2);
        ImGui::Text("Type: ");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
        ImGui::Combo(("##" + renderId + "_type").data(), &type, TYPE_LABELS,
                     IM_ARRAYSIZE(TYPE_LABELS));

        ImGui::EndTable();
    }

    ImGui::Separator();

    // -------------------------- Stats Child Window ---------------------------

    ImGui::BeginChild((renderId + "_child_l").data(),
                      ImVec2(ImGui::GetContentRegionAvail().x * 0.5f,
                             ImGui::GetTextLineHeightWithSpacing() * 9));
    // Display Table
    if (ImGui::BeginTable((renderId + "_stat_table").data(), 2)) {
        // Display Initiative
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Initiative: ");
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + renderId + "_initiative").data(), &initiative);

        // Display Remaining Toughness
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Remaining Toughness: ");
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + renderId + "_remainingToughness").data(),
                        &remainingToughness);

        // Display Remaining Wounds
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Remaining Wounds: ");
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + renderId + "_remainingWounds").data(),
                        &remainingWounds);

        // Display Remaining Mettle
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Remaining Mettle: ");
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + renderId + "_remainingMettle").data(),
                        &remainingMettle);

        // Display Armour
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Armour: ");
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + renderId + "_armour").data(), &armour);

        ImGui::EndTable();
    }

    ImGui::EndChild();

    ImGui::SameLine();

    // ------------------------- MAD Child Window ----------------------------

    ImGui::BeginChild((renderId + "_child_r").data(),
                      ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 9));
    madValues.renderEditor();
    ImGui::EndChild();

    // ------------------------------ Attacks --------------------------------

    ImGui::Text("Attacks: ");
    // Display Table
    if (ImGui::BeginTable((renderId + "_attacks").data(), 5)) {
        ImGui::TableNextRow();
        // Display Headers
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("Xd6");
        ImGui::TableSetColumnIndex(2);
        ImGui::Text("Ranged?");
        ImGui::TableSetColumnIndex(3);
        ImGui::Text("Focus");

        for (size_t idx = 0; idx < attacks.size();) {
            std::string attackLabel =
                "##" + renderId + "attack_" + std::to_string(idx);

            ImGui::TableNextRow();

            // Display Attack Name
            ImGui::TableSetColumnIndex(0);
            ImGui::InputText((attackLabel + "_name").data(),
                             &attacks[idx].attackName);

            // Display Attack Xd6
            ImGui::TableSetColumnIndex(1);
            ImGui::InputInt((attackLabel + "_numD6").data(),
                            &attacks[idx].numD6);

            // Display Attack isRanged
            ImGui::TableSetColumnIndex(2);
            ImGui::Checkbox((attackLabel + "_is_ranged").data(),
                            &attacks[idx].isRanged);

            // Display Attack isRanged
            ImGui::TableSetColumnIndex(3);
            ImGui::InputInt((attackLabel + "_focus").data(),
                            &attacks[idx].focus);

            // Display Attack Delete
            ImGui::TableSetColumnIndex(4);
            if (ImGui::Button(("Del" + attackLabel + "del_button").data())) {
                attacks.erase(std::next(attacks.begin(), idx));
            } else {
                ++idx;
            }
        }

        ImGui::EndTable();
    }

    if (ImGui::Button(
            ("Add Attack##" + renderId + "_add_button_attack").data())) {
        attacks.emplace_back("<Attack Name>");
    }
}

std::string squigrodeo::MonsterSheet::getName() { return monsterName; }