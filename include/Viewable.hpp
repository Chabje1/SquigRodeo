#pragma once

#include <string>

namespace squigrodeo {
class Viewable {
   public:
    virtual void renderViewer() = 0;
    virtual void renderEditor() = 0;
    virtual std::string getName() = 0;
};
}  // namespace squigrodeo
