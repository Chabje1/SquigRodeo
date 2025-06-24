#include "MADTable.hpp"

#include "imgui.h"

const char*
    squigrodeo::MADTable::VALUES_STR[squigrodeo::MADTable::NUM_MAD_VALUES] = {
        "POOR", "AVERAGE", "GOOD", "GREAT", "SUPERB", "EXTRAORDINARY"};

void squigrodeo::MADTable::renderViewer() {
    // TODO Viewer
}

void squigrodeo::MADTable::renderEditor() {
    ImGui::BeginDisabled();
    if (ImGui::BeginTable(tableName.data(), 3)) {
        // Setup Column Headers
        ImGui::TableSetupColumn("Melee");
        ImGui::TableSetupColumn("Accuracy");
        ImGui::TableSetupColumn("Defence");
        ImGui::TableHeadersRow();

        // Render Value Editors
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::ListBox(("##" + tableName + "_melee").data(), &melee, VALUES_STR,
                       squigrodeo::MADTable::NUM_MAD_VALUES);
        ImGui::TableSetColumnIndex(1);
        ImGui::ListBox(("##" + tableName + "_accuracy").data(), &accuracy,
                       VALUES_STR, squigrodeo::MADTable::NUM_MAD_VALUES);
        ImGui::TableSetColumnIndex(2);
        ImGui::ListBox(("##" + tableName + "_defence").data(), &defence,
                       VALUES_STR, squigrodeo::MADTable::NUM_MAD_VALUES);
        ImGui::EndTable();
    }
    ImGui::EndDisabled();
}