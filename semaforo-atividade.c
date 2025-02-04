#include <stdio.h>
#include "pico/stdlib.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Representa os estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} LightState;

LightState currentState = RED;

// Função de callback do timer
bool timer_callback(struct repeating_timer *t) {
    // Contador de tempo
    static int counter = 0;
    // Alterna o estado do semáforo
    switch(currentState) {
        case RED:
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            if (counter >= 3) {
                currentState = YELLOW;
                counter = 0;
            }
            break;
        case YELLOW:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            if (counter >= 3) {
                currentState = GREEN;
                counter = 0;
            }
            break;
        case GREEN:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            if (counter >= 3) {
                currentState = RED;
                counter = 0;
            }
            break;
    }
    // Incrementa o contador
    counter++;
    return true;
}

int main()
{
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o timer
    struct repeating_timer timer;
    // Chama a função de callback a cada 1000ms
    add_repeating_timer_ms(1000, timer_callback, NULL, &timer);

    while (true) {
        // Mantém o loop ocupado
        tight_loop_contents();
        sleep_ms(10);
    }
    
    return 0;
}
