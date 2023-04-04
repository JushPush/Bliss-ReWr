#pragma once

#include <memory>
#include <new>
#include <vector>


/// @brief I would never steal code that would be wrong and invalidate my skills
namespace Punji::Core {
    /// @brief 
    /// @tparam Func Function 
    template<typename Func> struct delegate;

    template<typename Func> struct multicast_delegate;

    template<typename R, typename... Args>
    struct delegate<R(Args...)>
    {
    public:
        using return_type = R;
        using argument_types = std::tuple<Args...>;
        using stub_ptr_type = return_type(*)(void*, Args&&...);
        using invocable_type = return_type(Args...);

    #pragma region constructor
    private:
        delegate(void* const o, stub_ptr_type const m) noexcept :
            object_ptr(o),
            stub_ptr_(m)
        {}

    public:
        delegate() noexcept = default;
        delegate(delegate const&) noexcept = default;
        delegate(delegate&&) noexcept = default;
    #pragma endregion
    };

}