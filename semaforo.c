#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

const int TEMPO_SEMAFORO_MS = 3000;
const int TEMPO_SERIAL_MS = 1000;

int estado_semaforo = 0;

bool semaforo_callback(struct repeating_timer *t) {

    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            printf("Semáforo: Vermelho\n");
            break;
        case 1:
            gpio_put(LED_AMARELO, 1);
            printf("Semáforo: Amarelo\n");
            break;
        case 2:
            gpio_put(LED_VERDE, 1);
            printf("Semáforo: Verde\n");
            break;
    }

    
    estado_semaforo = (estado_semaforo + 1) % 3;
    return true;
}

int main() {
    
    stdio_init_all();

    
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    
    struct repeating_timer semaforo_timer;
    add_repeating_timer_ms(TEMPO_SEMAFORO_MS, semaforo_callback, NULL, &semaforo_timer);

    uint32_t contador = 0;

    while (true) {
        
        printf("Contador serial: %d segundos\n", contador++);
        sleep_ms(TEMPO_SERIAL_MS);
    }
}