#pragma once

#include <optional>

#include "emscripten/val.h"

namespace emscripten_obr_sdk {

struct NotificationApi {
    NotificationApi(emscripten::val js) : notificationJs{js} {}

    std::string show(const std::string& message,
                     const std::string& variant = "DEFAULT") {
        emscripten::val aReturn =
            notificationJs.call<emscripten::val>("show", message, variant)
                .await();

        return aReturn.as<std::string>();
    }

    void close(const std::string& id) {
        notificationJs.call<emscripten::val>("close", id).await();
    }

    emscripten::val notificationJs;
};

}  // namespace emscripten_obr_sdk