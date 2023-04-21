#ifndef MODULE_HPP
#define MODULE_HPP

#include "../containers/containers.hpp"

namespace Punji::Core
{
    class Module 
    {
    public:
        Module() noexcept = default;

        MulticastDelegate<void()> setup_functions;
        MulticastDelegate<void()> update_functions;
        MulticastDelegate<void()> shutdown_functions;
    };
}

#endif