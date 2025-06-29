#pragma once

#include "BroadcastApi.hpp"
#include "NotificationApi.hpp"
#include "PlayerApi.hpp"
#include "emscripten/bind.h"

namespace emscripten_obr_sdk {

struct OBR {
    OBR(emscripten::val js)
        : obrJs(js),
          player{js["player"]},
          notification{js["notification"]},
          broadcast{js["broadcast"]} {}

    // viewportApi viewport;
    PlayerApi player;
    // partyApi party;
    NotificationApi notification;
    // sceneApi scene;
    // contextMenuApi contextMenu;
    // toolApi tool;
    // popoverApi popover;
    // modalApi modal;
    // actionApi action;
    // interactionApi interaction;
    // roomApi room;
    // themeApi theme;
    // assetsApi assets;
    BroadcastApi broadcast;

    emscripten::val obrJs;
};

}  // namespace emscripten_obr_sdk
