#include <graphics/api/api_vulkan.h>

namespace Punji::Graphics
{
    void ASSERT_VULKAN(VkResult value)
    {
        if (value != VK_SUCCESS) { std::cout << "ASSERT FAILED\n" << value; }
    }

    void VulkanInit(bl_VulkanData vulkan) {
        //APPLICATION INFO//

        vulkan.appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        vulkan.appInfo.pNext = NULL;
        vulkan.appInfo.pApplicationName = "VULKAN TUTORIAL";
        vulkan.appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        vulkan.appInfo.pEngineName = "DEEZ NUTS";
        vulkan.appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        vulkan.appInfo.apiVersion = VK_API_VERSION_1_0;

        uint32_t numberofLayers = 0;

        vkEnumerateInstanceLayerProperties(&numberofLayers, nullptr);

        VkLayerProperties *layers = new VkLayerProperties[numberofLayers];

        vkEnumerateInstanceLayerProperties(&numberofLayers, layers);

        std::cout << "\n              HELLO VULKAN X86 \n\n DEVICE PROPERTIES\n";

        std::cout << "\n Number of Instance Layers: " << numberofLayers << "\n";

        for (uint32_t i = 0; i < numberofLayers; i++)
        {
            std::cout << " Name:                    " << layers[i].layerName << "\n";
            std::cout << " Spec Version:            " << layers[i].specVersion << "\n";
            std::cout << " Implementation Version:  " << layers[i].implementationVersion << "\n";
            std::cout << " Description:             " << layers[i].description << "\n\n";
        }

        uint32_t numberofExtensions = 0;

        vkEnumerateInstanceExtensionProperties(nullptr, &numberofExtensions, nullptr);

        VkExtensionProperties *extensions = new VkExtensionProperties[numberofExtensions];

        vkEnumerateInstanceExtensionProperties(nullptr, &numberofExtensions, extensions);

        std::cout << "\n Number of Extensions:      " << numberofExtensions << "\n";

        for (uint32_t i = 0; i < numberofExtensions; i++)
        {
            std::cout << " Name:                    " << extensions[i].extensionName << "\n";

            std::cout << " Spec Version:            " << extensions[i].specVersion << "\n";
        }

        const std::vector<const char*> validationLayers = { "VK_LAYER_LUNARG_standard_validation" };

        const std::vector<const char*> usedExtensions = { };


        //INSTANCE INFO//

        VkInstanceCreateInfo instanceInfo;

        instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceInfo.pNext = nullptr;
        instanceInfo.flags = 0;
        instanceInfo.pApplicationInfo = &vulkan.appInfo;
        instanceInfo.enabledLayerCount = 0;
        instanceInfo.ppEnabledLayerNames = nullptr;
        instanceInfo.enabledExtensionCount = usedExtensions.size();
        instanceInfo.ppEnabledExtensionNames = usedExtensions.data();

        //INSTANCE CREATION//

        VkResult result = vkCreateInstance(&instanceInfo, nullptr, &vulkan.instance);

        //SURFACE INFO//

        /*VkWin32SurfaceCreateInfoKHR surfaceCreateInfo;

        surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;

        surfaceCreateInfo.pNext = nullptr;

        surfaceCreateInfo.flags = 0;

        surfaceCreateInfo.hinstance = nullptr;

        surfaceCreateInfo.hwnd = nullptr;*/

        //ASSERT_VULKAN(result);

        //UNSURE CONCERNING ORDER OF SURFACE AND PROCADDR HERE//

        //VkSurfaceKHR surface;

        //result = vkCreateWin32SurfaceKHR(instance, &surfaceCreateInfo, nullptr, &surface);
        ASSERT_VULKAN(result);


        vkGetInstanceProcAddr(vulkan.instance, "");

        uint32_t numberofPhysicalDevices = 0;

        result = vkEnumeratePhysicalDevices(vulkan.instance, &numberofPhysicalDevices, nullptr);
        ASSERT_VULKAN(result);

        //VkPhysicalDevice *physicalDevices = new VkPhysicalDevice[numberofPhysicalDevices];

        std::vector<VkPhysicalDevice> physicalDevices;

        physicalDevices.resize(numberofPhysicalDevices);

        result = vkEnumeratePhysicalDevices(vulkan.instance, &numberofPhysicalDevices, physicalDevices.data());
        ASSERT_VULKAN(result);

        for (uint32_t i = 0; i < numberofPhysicalDevices; i++)
        {
            //printStats(physicalDevices[i]);
        }

        //QUEUE INFO//

        float queuePriorities[] = { 1.0f, 1.0f, 1.0f, 1.0f };

        VkDeviceQueueCreateInfo deviceQueueCreateInfo;

        deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        deviceQueueCreateInfo.pNext = nullptr;
        deviceQueueCreateInfo.flags = 0;
        deviceQueueCreateInfo.queueFamilyIndex = 0; // TO DO SELECT CORRECT FAMILY INDEX
        deviceQueueCreateInfo.queueCount = 4;       // TO DO CHECK IF THIS IS A VALID NUMBER
        deviceQueueCreateInfo.pQueuePriorities = nullptr;       // TO DO CHECK IF THIS IS A VALID NUMBER

        //PHYSICAL DEVICE//

        VkPhysicalDeviceFeatures usedFeatures = {};

        VkDeviceCreateInfo deviceCreateInfo;

        deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        deviceCreateInfo.pNext = nullptr;
        deviceCreateInfo.flags = 0;
        deviceCreateInfo.queueCreateInfoCount = 1;
        deviceCreateInfo.pQueueCreateInfos = &deviceQueueCreateInfo;
        deviceCreateInfo.enabledLayerCount = 0;
        deviceCreateInfo.ppEnabledLayerNames = nullptr;
        deviceCreateInfo.enabledExtensionCount = 0;
        deviceCreateInfo.ppEnabledExtensionNames = nullptr;
        deviceCreateInfo.pEnabledFeatures = &usedFeatures;

        result = vkCreateDevice(physicalDevices[0], &deviceCreateInfo, nullptr, &vulkan.device);
        ASSERT_VULKAN(result);

        VkQueue queue;

        vkGetDeviceQueue(vulkan.device, 0, 0, &queue);

        vkDeviceWaitIdle(vulkan.device);

        vkDestroyDevice(vulkan.device, nullptr);
        vkDestroySurfaceKHR(vulkan.instance, vulkan.surface, nullptr);
        vkDestroyInstance(vulkan.instance, nullptr);


        delete[] layers;

        delete[] extensions;
    }

    void VulkanKill(bl_VulkanData vulkan) {
        
    }
}