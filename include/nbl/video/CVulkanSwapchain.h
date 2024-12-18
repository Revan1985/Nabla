#ifndef _NBL_VIDEO_C_VULKAN_SWAPCHAIN_H_INCLUDED_
#define _NBL_VIDEO_C_VULKAN_SWAPCHAIN_H_INCLUDED_

#include "nbl/video/ISwapchain.h"

#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"

namespace nbl::video
{

class ILogicalDevice;

class CVulkanSwapchain final : public ISwapchain
{
    public:
        NBL_API2 static core::smart_refctd_ptr<CVulkanSwapchain> create(core::smart_refctd_ptr<const ILogicalDevice>&& logicalDevice, ISwapchain::SCreationParams&& params, core::smart_refctd_ptr<CVulkanSwapchain>&& oldSwapchain=nullptr);

        core::smart_refctd_ptr<IGPUImage> createImage(const uint32_t imageIndex) override;

        void setObjectDebugName(const char* label) const override;

        inline const void* getNativeHandle() const override {return &m_vkSwapchainKHR;}
        inline VkSwapchainKHR getInternalObject() const {return m_vkSwapchainKHR;}
        
        // returns the maximum number of time acquire can be called without releasing the image index through present.
        inline uint8_t getMaxBlockingAcquiresBeforePresent() const override { return m_maxBlockingAcquiresBeforePresent; }
        
        // returns the maximum number of acquires you can request without waiting for previous acquire semaphores to signal.
        uint8_t getMaxAcquiresInFlight() const override { return m_maxAcquiresInFlight; }

    private:
        CVulkanSwapchain(
            core::smart_refctd_ptr<const ILogicalDevice>&& logicalDevice,
            SCreationParams&& params,
            const uint32_t imageCount,
            core::smart_refctd_ptr<CVulkanSwapchain>&& oldSwapchain,
            const VkSwapchainKHR swapchain,
            const VkSemaphore* const _acquireAdaptorSemaphores,
            const VkSemaphore* const _prePresentSemaphores,
            const VkSemaphore* const _presentAdaptorSemaphores,
            const uint8_t maxAcquiresBeforePresent,
            const uint8_t maxAcquiresInFlight
        );
        ~CVulkanSwapchain();

        bool unacquired(const uint8_t imageIndex) const override;
        ACQUIRE_IMAGE_RESULT acquireNextImage_impl(const SAcquireInfo& info, uint32_t* const out_imgIx) override;
        PRESENT_RESULT present_impl(const SPresentInfo& info) override;

        core::smart_refctd_ptr<ISwapchain> recreate_impl(SSharedCreationParams&& params) override;

        const IDeviceMemoryBacked::SDeviceMemoryRequirements m_imgMemRequirements;
        const VkSwapchainKHR m_vkSwapchainKHR;
        VkImage m_images[ISwapchain::MaxImages];
        VkSemaphore m_acquireAdaptorSemaphores[ISwapchain::MaxImages];
        VkSemaphore m_prePresentSemaphores[ISwapchain::MaxImages];
        VkSemaphore m_presentAdaptorSemaphores[ISwapchain::MaxImages];
        uint64_t m_perImageAcquireCount[ISwapchain::MaxImages] = { 0 };
        // nasty way to fight UB of the Vulkan spec
        bool m_needToWaitIdle = true;
        uint8_t m_maxBlockingAcquiresBeforePresent = 0u;
        uint8_t m_maxAcquiresInFlight = 0u;
};

}

#endif