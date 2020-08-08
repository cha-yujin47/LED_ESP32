#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define GPIO_OUTPUT 18
#define GPIO_OUTPUT_PIN_SEL (1ULL<<GPIO_OUTPUT) 

void app_main(void)
{
    gpio_config_t gpio;
    gpio.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    gpio.mode = GPIO_MODE_OUTPUT;
    gpio.pull_up_en = 0;
    gpio.pull_down_en = 0;
    gpio.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&gpio);

    int cnt = 0;
    while(1) {
        cnt++;
        vTaskDelay(1000 / portTICK_RATE_MS); //1sec
        gpio_set_level(GPIO_OUTPUT, cnt % 2);
        printf("%d",cnt);
         if (cnt % 2 == 0)
        {
            printf("LED OFF\n");
        }
        else
        {
            printf("LED ON\n");
        }
    }
}