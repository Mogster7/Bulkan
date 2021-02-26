//------------------------------------------------------------------------------
//
// File Name:	PhysicalDevice.h
// Author(s):	Jonathan Bourim (j.bourim)
// Date:        6/18/2020 
//
//------------------------------------------------------------------------------
#pragma once

namespace vk
{
    PhysicalDevice;
    Device;
}

class QueueFamilyIndices
{
public:
    std::optional<uint32_t> graphics;
    std::optional<uint32_t> present;

    bool isComplete() const
    {
        return graphics.has_value() && present.has_value();
    }
};

class Device;

class PhysicalDevice : public vk::PhysicalDevice
{
public:
    PhysicalDevice() = default;
    PhysicalDevice(const vk::PhysicalDevice& other);
    ~PhysicalDevice() = default;

    void Create(Instance& instance);
    void CreateLogicalDevice(Device& device);
    const QueueFamilyIndices& GetQueueFamilyIndices() const;
    vk::PhysicalDeviceProperties GetProperties() const { return properties; }
    vk::DeviceSize GetMinimumUniformBufferOffset() const;


    const Instance& GetInstance() const { return *instance; }


private:
    Instance* instance;
    static QueueFamilyIndices FindQueueFamilies(vk::PhysicalDevice pd);
    bool IsDeviceSuitable(vk::PhysicalDevice) const;
    bool CheckDeviceExtensionSupport(vk::PhysicalDevice) const;

    QueueFamilyIndices queueFamilyIndices;
    vk::PhysicalDeviceProperties properties;
};


