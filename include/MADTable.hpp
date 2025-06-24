#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace squigrodeo {
struct MADTable {
    // MAD Table
    static constexpr uint8_t NUM_MAD_VALUES = 6;
    static const char* VALUES_STR[NUM_MAD_VALUES];

    // MAD Table Struct
    MADTable(const std::string& name) : tableName(name) {}

    std::string tableName;

    int melee = 0;
    int accuracy = 0;
    int defence = 0;

    void renderViewer();
    void renderEditor();
};
}  // namespace squigrodeo
