#include "CompanionApp.hpp"

#include "imgui.h"

constexpr int COMPANION_SIDE2SIDE_WINDOW_LENGTHS = 260;

squigrodeo::CompanionApp::CompanionApp(bool gmFlag)
    : isGM{gmFlag},
      randomDevice{},
      engine{randomDevice()},
      d6Distribution{1, 6} {}

void squigrodeo::CompanionApp::renderMainMode() {
    //
    ImGui::BeginChild("CompanionChildTL",
                      ImVec2(ImGui::GetContentRegionAvail().x * 0.5f,
                             COMPANION_SIDE2SIDE_WINDOW_LENGTHS));

    ImGui::PushItemWidth(100);
    ImGui::Button("Character List", ImVec2(-1, 0));

    if (isGM && ImGui::Button("Bestiary", ImVec2(-1, 0))) {
    }

    ImGui::Button("Battle Mode", ImVec2(-1, 0));
    ImGui::PopItemWidth();

    ImGui::BeginChild("CompanionChatWindow", ImGui::GetContentRegionAvail(),
                      ImGuiChildFlags_Border);

    for (std::size_t msgIdx = 0; msgIdx < chatMessageHead; msgIdx++) {
        ImGui::Text("%s", chatMessages[msgIdx]);
    }

    ImGui::EndChild();
    ImGui::EndChild();

    ImGui::SameLine();

    //
    if (!isGM) ImGui::BeginDisabled();

    ImGui::BeginChild("CompanionParty",
                      ImVec2(0, COMPANION_SIDE2SIDE_WINDOW_LENGTHS));

    ImGui::Text("Party:");

    ImGui::EndChild();

    if (!isGM) ImGui::EndDisabled();

    //
    ImGui::BeginChild("CompanionCharacterSheet", ImVec2(0, 260),
                      ImGuiChildFlags_Border);

    if (focusedViewable) {
        focusedViewable->renderViewer();
    }

    ImGui::EndChild();

    //
    ImGui::Dummy(ImVec2(0, 0));
    ImGui::SameLine(ImGui::GetContentRegionAvail().x * 0.2f);
    ImGui::Text("Dice ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(200);
    ImGui::InputInt(("##companion_dice_input"), &diceNumber);
    //
    ImGui::SameLine(ImGui::GetContentRegionAvail().x * 0.5f);
    ImGui::Text("DN ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(200);
    ImGui::InputInt(("##companion_difficulty_number"), &difficultyNumber);
    //
    ImGui::SameLine(ImGui::GetContentRegionAvail().x * 0.8f);
    if (ImGui::Button("Roll!##companion_roll_button")) {
        int successes = rollDice();
        snprintf(
            tempMessageBuffer, MAX_MESSAGE_SIZE, "%s: rolled %u successes!",
            (focusedViewable) ? focusedViewable->getName().c_str() : "Someone",
            successes);
        sendMessage();
    }

    if (chatMessageHead >= MAX_MESSAGE_HISTORY_SIZE) {
        chatMessageHead = 0;
    }
}

int squigrodeo::CompanionApp::rollDice() {
    int numberOfSuccesses = 0;

    for (int itr = 0; itr < diceNumber; ++itr) {
        if (d6Distribution(engine) >= difficultyNumber) ++numberOfSuccesses;
    }

    return numberOfSuccesses;
}

void squigrodeo::CompanionApp::sendMessage() {
    // Copy message into local ring
    strcpy(chatMessages[chatMessageHead], tempMessageBuffer);
    ++chatMessageHead;
}