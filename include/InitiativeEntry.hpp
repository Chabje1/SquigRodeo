#pragma once

#include <set>
#include <vector>

#include "Viewable.hpp"

namespace squigrodeo {
struct InitiativeEntry {
    int initative = 0;
    Viewable* participant;

    bool operator<(const InitiativeEntry& other) const {
        return initative < other.initative;
    }
};
}  // namespace squigrodeo