#pragma once

#include "../containers/multicast_delegate.hpp"

namespace Punji::Core
{
    class Module 
    {
    public:
        Module() noexcept = default;

        MulticastDelegate<void()> init_functions;
        MulticastDelegate<void()> update_functions;
    };
}