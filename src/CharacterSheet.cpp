#include "CharacterSheet.hpp"

#include "imgui.h"
#include "imgui_stdlib.h"

void squigrodeo::SkillTable::render() {
    if (ImGui::BeginTable(tableName.data(), 3)) {
        // Setup Column Headers
        ImGui::TableSetupColumn("Skill");
        ImGui::TableSetupColumn("Training");
        ImGui::TableSetupColumn("Focus");
        ImGui::TableHeadersRow();

        // Setup Column Button Labels
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(1);
        ImGui::Text(" 0   1   2   3");
        ImGui::TableSetColumnIndex(2);
        ImGui::Text(" 0   1   2   3");
        ImGui::TableSetColumnIndex(2);

        for (int skillIndex = 0; skillIndex < SKILL_NAMES.size();
             skillIndex++) {
            ImGui::TableNextRow();

            // Display Skill Name
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", SKILL_NAMES[skillIndex].data());

            // Display Training as 3 radio buttons on the same line
            ImGui::TableSetColumnIndex(1);

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_training_0")
                    .data(),
                &skillValues[skillIndex].training, 0);
            ImGui::SameLine();

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_training_1")
                    .data(),
                &skillValues[skillIndex].training, 1);

            ImGui::SameLine();
            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_training_2")
                    .data(),
                &skillValues[skillIndex].training, 2);

            ImGui::SameLine();

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_training_3")
                    .data(),
                &skillValues[skillIndex].training, 3);

            // Display Focus as 3 radio buttons on the same line
            ImGui::TableSetColumnIndex(2);

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_focus_0")
                    .data(),
                &skillValues[skillIndex].focus, 0);

            ImGui::SameLine();

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_focus_1")
                    .data(),
                &skillValues[skillIndex].focus, 1);

            ImGui::SameLine();

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_focus_2")
                    .data(),
                &skillValues[skillIndex].focus, 2);

            ImGui::SameLine();

            ImGui::RadioButton(
                ("##" + tableName + "_" + std::string(SKILL_NAMES[skillIndex]) +
                 "_focus_3")
                    .data(),
                &skillValues[skillIndex].focus, 3);
        }

        ImGui::EndTable();
    }
}

int squigrodeo::SkillTable::getUsedXP() {
    int totalCost = 0;

    for (std::size_t idx = 0; idx < skillValues.size(); ++idx) {
        totalCost += SKILL_COST_PER_LEVEL[skillValues[idx].training];
        totalCost += SKILL_COST_PER_LEVEL[skillValues[idx].focus];
    }

    return totalCost;
}

void squigrodeo::AttributeTable::render() {
    if (ImGui::BeginTable(tableName.data(), 3)) {
        // Setup Column Headers
        ImGui::TableSetupColumn("Body");
        ImGui::TableSetupColumn("Mind");
        ImGui::TableSetupColumn("Soul");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();

        // Display Body
        ImGui::TableSetColumnIndex(0);
        ImGui::InputInt(("##" + tableName + "_body").data(), &body);

        // Display Mind
        ImGui::TableSetColumnIndex(1);
        ImGui::InputInt(("##" + tableName + "_mind").data(), &mind);

        // Display Soul
        ImGui::TableSetColumnIndex(2);
        ImGui::InputInt(("##" + tableName + "_soul").data(), &soul);

        ImGui::EndTable();
    }
}

int squigrodeo::AttributeTable::getUsedXP() {
    int totalCost = 0;

    totalCost += ATTRIBUTE_COST_PER_LEVEL[body];

    totalCost += ATTRIBUTE_COST_PER_LEVEL[mind];

    totalCost += ATTRIBUTE_COST_PER_LEVEL[soul];

    return totalCost;
}

void squigrodeo::CharacterSheet::renderEditor() {
    // Display Character Name
    ImGui::Text("Character Name: ");
    ImGui::SameLine();
    ImGui::InputText(("##" + charName + "_display_name").data(), &charName);

    // Display XP
    int remainingXp = xpCount - getUsedXP();
    ImGui::Text("XP: %d / ", remainingXp);
    ImGui::SameLine();
    ImGui::InputInt(("##" + charName + "_xp").data(), &xpCount);

    ImGui::Separator();

    // Left Child Window
    ImGui::BeginChild((charName + "_child_l").data(),
                      ImVec2(ImGui::GetContentRegionAvail().x * 0.5f,
                             ImGui::GetContentRegionAvail().y));
    skills.render();
    ImGui::EndChild();

    ImGui::SameLine();

    // Right Child Window
    ImGui::BeginChild((charName + "_child_r").data(),
                      ImVec2(0, ImGui::GetContentRegionAvail().y));

    attributes.render();

    ImGui::Separator();

    // Display Currency
    ImGui::Text("Aqua Ghyranis");
    ImGui::SameLine();
    ImGui::InputInt(("##" + charName + "_aqua_ghyranis").data(), &aquaGhyranis);

    // Set MAD Stats
    setMADStats();

    // Display MAD Table
    mad.renderEditor();

    // Display Has Shield? Checkbox
    ImGui::Text("Has Shield?");
    ImGui::SameLine();
    ImGui::Checkbox(("Toggle##" + charName + "_has_shield_toggle").data(),
                    &hasShield);

    // Display Short Term Goal
    ImGui::Text("Short Term Goal");
    ImGui::InputTextMultiline(("##" + charName + "_short_term_goal").data(),
                              &shortTermGoal,
                              ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 8));

    // Display Long Term Goal
    ImGui::Text("Long Term Goal");
    ImGui::InputTextMultiline(("##" + charName + "_long_term_goal").data(),
                              &longTermGoal,
                              ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 8));
    ImGui::EndChild();
}

void squigrodeo::CharacterSheet::renderViewer() {
    // TODO
}

std::string squigrodeo::CharacterSheet::getName() { return charName; }

int squigrodeo::CharacterSheet::getUsedXP() {
    int totalCost = 0;

    totalCost += skills.getUsedXP();
    totalCost += attributes.getUsedXP();

    return totalCost;
}

void squigrodeo::CharacterSheet::setMADStats() {
    mad.melee = (attributes.body +
                 skills.skillValues[WEAPON_SKILL_INDEX].training - 1) /
                2;

    mad.accuracy = (attributes.mind +
                    skills.skillValues[BALLISTIC_SKILL_INDEX].training - 1) /
                   2;

    mad.defence = (attributes.body +
                   skills.skillValues[REFLEXES_SKILL_INDEX].training - 1) /
                      2 +
                  (hasShield ? 1 : 0);
}