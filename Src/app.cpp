#include "app.h"

#include "tim.h"
#include "led/Ledstrip.h"

Ledstrip<5, 4, 8> strip;

[[noreturn]]
void app() {
    LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);
    strip.update();
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_5, reinterpret_cast<uint32_t>(strip.get_array_address()));
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_5, 0x40000034);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_5);
    LL_TIM_EnableCounter(TIM2);

    while (true) {
        LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
        LL_mDelay(500);
    }
}