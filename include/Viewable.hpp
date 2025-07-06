#pragma once

#include <string>

namespace squigrodeo {
class Viewable {
   public:
    virtual void renderViewer(const std::string& renderId) = 0;
    virtual void renderEditor(const std::string& renderId) = 0;
    virtual std::string getName() = 0;
};
}  // namespace squigrodeo
