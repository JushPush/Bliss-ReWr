#pragma once

#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

namespace Punji::Graphics
{
    struct bl_VulkanData {
        VkApplicationInfo appInfo;
        VkInstance instance;
        VkSurfaceKHR surface;
        VkDevice device;
    };
    void ASSERT_VULKAN(VkResult value);

    void VulkanInit(bl_VulkanData vulkan);
    void VulkanKill(bl_VulkanData vulkan);
}