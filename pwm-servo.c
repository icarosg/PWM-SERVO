#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22 
#define LED_B 12

const uint16_t WRAP_PERIOD = 40000; // período aprox 50Hz (20ms)
const float PWM_DIVISER = 64.0; // divisor de clock para obter 50Hz

// função para configurar o módulo PWM do servo
void pwm_setup()
{
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_B, GPIO_FUNC_PWM);

    uint slice_servo = pwm_gpio_to_slice_num(SERVO_PIN);
    uint slice_LED = pwm_gpio_to_slice_num(LED_B);

    pwm_set_clkdiv(slice_servo, PWM_DIVISER);
    pwm_set_wrap(slice_servo, WRAP_PERIOD);

    pwm_set_clkdiv(slice_LED, PWM_DIVISER);
    pwm_set_wrap(slice_LED, WRAP_PERIOD);

    pwm_set_gpio_level(SERVO_PIN, 0);
    pwm_set_gpio_level(LED_B, 0);
    
    pwm_set_enabled(slice_servo, true);
    pwm_set_enabled(slice_LED, true);


}

// função para mover o servo para um determinado duty cycle
void move_servo(uint16_t pulse_width)
{
    uint16_t duty_cycle = (pulse_width * WRAP_PERIOD) / 20000; // conversão para ciclo PWM
    pwm_set_gpio_level(SERVO_PIN, duty_cycle);
}

// função para ajustar o brilho do LED
void level_led(uint16_t pulse_width) {
    uint16_t duty_cycle = (pulse_width * WRAP_PERIOD) / 2400; // 500-2400 para 0-100% brilho
    pwm_set_gpio_level(LED_B, duty_cycle);
}

int main()
{
    stdio_init_all();
    pwm_setup();

    sleep_ms(2000); // aguarda 2 segundos antes de iniciar

    // movimentos fixos do servo
    printf("Movimento 180°\n");
    move_servo(2400); // 180 graus
    level_led(2400);
    sleep_ms(5000);

    printf("Movimento 90°\n");
    move_servo(1470); // 90 graus
    level_led(1470);
    sleep_ms(5000);

    printf("Movimento 0°\n");
    move_servo(500);  // 0 graus
    level_led(500);
    sleep_ms(5000);

    // movimentação suave entre 0° e 180°
    while (true)
    {
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) // De 0° a 180°
        {   
            if( pulse == 500)
                printf("Movimento de 0° a 180°\n");
            
            move_servo(pulse);
            level_led(pulse);
            sleep_ms(10);
        }
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) // De 180° a 0°
        {   
            if (pulse == 2400)
                printf("Movimento de 180° a 0°\n");

            move_servo(pulse);
            level_led(pulse);
            sleep_ms(10);
        }
    }
}