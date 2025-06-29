#pragma once

#include <functional>
#include <string>

#include "emscripten/val.h"

namespace emscripten_obr_sdk {

struct SendMessageOption {
    std::string destination;
};

template <typename T>
struct MessageEvent {
    T data;
    std::string connectionId;
};

struct BroadcastApi {
    BroadcastApi(emscripten::val js) : broadcastJs{js} {}

    template <typename T>
    void sendMessage(const std::string& channel, const T& data,
                     const std::string& options = "REMOTE") {
        broadcastJs
            .call<emscripten::val>("sendMessage", channel, data,
                                   SendMessageOption{options})
            .await();
    }

    template <typename T>
    emscripten::val onMessage(
        const std::string& channel,
        const std::function<void(MessageEvent<T>)>& callback) {
        emscripten::val JsFunction =
            emscripten::val::global("wrapCallback")(emscripten::val(callback));

        return broadcastJs.call<emscripten::val>("onMessage", channel,
                                                 JsFunction);
    }

    emscripten::val broadcastJs;
};
}  // namespace emscripten_obr_sdk
