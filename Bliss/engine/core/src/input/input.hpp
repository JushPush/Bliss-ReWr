#ifndef INPUT_HPP
#define INPUT_HPP

#include "../containers/containers.hpp"

namespace Punji::Core {
    class InputHandler {
        SinglecastDelegate<void()> on_input;
    };
}

#endif