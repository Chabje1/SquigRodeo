#pragma once

#include <optional>

#include "emscripten/val.h"

namespace emscripten_obr_sdk {

struct PlayerApi {
    PlayerApi(emscripten::val js) : playerJs{js} {}

    std::optional<std::string[]> getSelection();

    void select(const std::vector<std::string>& items, bool replace = true);

    void deselect(
        const std::optional<std::vector<std::string>>& items = std::nullopt);

    std::string getName() {
        return playerJs.call<emscripten::val>("getName")
            .await()
            .as<std::string>();
    }

    void setName(const std::string& name) {
        playerJs.call<emscripten::val>("setName", name).await();
    }

    std::string getColor() {
        return playerJs.call<emscripten::val>("getColor")
            .await()
            .as<std::string>();
    }

    void setColor(const std::string& color) {
        playerJs.call<emscripten::val>("setColor", color).await();
    }

    bool getSyncView() {
        return playerJs.call<emscripten::val>("getSyncView").await().as<bool>();
    }

    void setSyncView(bool syncView) {
        playerJs.call<emscripten::val>("setSyncView", syncView).await();
    }

    std::string getId() {
        return playerJs.call<emscripten::val>("getId")
            .await()
            .as<std::string>();
    }

    std::string getRole() {
        return playerJs.call<emscripten::val>("getRole")
            .await()
            .as<std::string>();
    }

    // Metadata getMetadata();

    // void setMetadata(Partial<Metadata> update);

    bool hasPermission(const std::string& permission) {
        return playerJs.call<emscripten::val>("hasPermission", permission)
            .await()
            .as<bool>();
    }

    std::string getConnectionId() {
        return playerJs.call<emscripten::val>("getConnectionId")
            .await()
            .as<std::string>();
    }

    emscripten::val playerJs;
};

}  // namespace emscripten_obr_sdk