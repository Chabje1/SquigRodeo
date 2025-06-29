#include "obr_sdk_wrapper/BroadcastApi.hpp"

#include "emscripten/bind.h"

EMSCRIPTEN_BINDINGS(emscripten_obr_sdk) {
    // Bind MessageEvent<string>
    emscripten::value_object<emscripten_obr_sdk::MessageEvent<std::string>>(
        "MessageEvent_String")
        .field("data", &emscripten_obr_sdk::MessageEvent<std::string>::data)
        .field("connectionId",
               &emscripten_obr_sdk::MessageEvent<std::string>::connectionId);

    // Bind std::function<void()> as a class
    emscripten::class_<std::function<void()>>("Function_Void_Void")
        .constructor()  // Allow JavaScript to create instances
        .function("opCall",
                  &std::function<void()>::operator());  // Bind operator()

    // Bind std::function<void()> as a class
    emscripten::class_<
        std::function<void(emscripten_obr_sdk::MessageEvent<std::string>)>>(
        "Function_Void_MessageEvent_String")
        .function(
            "opCall",
            &std::function<void(emscripten_obr_sdk::MessageEvent<
                                std::string>)>::operator());  // Bind operator()

    // Bind SendMessageOption as a class
    emscripten::value_object<emscripten_obr_sdk::SendMessageOption>(
        "SendMessageOption")
        .field("destination",
               &emscripten_obr_sdk::SendMessageOption::destination);
}