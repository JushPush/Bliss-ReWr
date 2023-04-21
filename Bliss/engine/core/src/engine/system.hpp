#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "module.hpp"

namespace Punji::Core {
    class System {
        friend class Module;

    public:
        System() {}
        ~System() {} 
    };
}

#endif