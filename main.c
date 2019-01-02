#include "stm32f4xx.h"
#include "led.h"
#include "key.h"

void delay(volatile int d){
    while(d--);
}

int main(void){
    LED_Init();
    KEY_Init();
    if(1);

    /* 循环点亮 */
    while(1){
        /*KEY1*/
        if((GPIOG->IDR & (1<<7)) == (1<<7)){    /* KEY1--->PG7 */
            /*松开*/
            GPIOH->ODR |= (1<<7);
        }else{
            /*按下*/
            GPIOH->ODR &= ~(1<<7);
        }

        /* KEY2 */
        if((GPIOA->IDR & (1<<8)) == (1<<8)){    /* KEY2--->PA8 */
            /*松开*/
            GPIOD->ODR |= (1<<13);
        }else{
            /*按下*/
            GPIOD->ODR &= ~(1<<13);
        }

        /* KEY3 */
        if((GPIOD->IDR & (1<<3)) == (1<<3)){    /* KEY3--->PD3 */
            /*松开*/
            GPIOI->ODR |= (1<<11);
        }else{
            /*按下*/
            GPIOI->ODR &= ~(1<<11);
        }

        /* KEY4 */
        if((GPIOG->IDR & (1<<9)) == (1<<9)){    /* KEY2--->PA8 */
            /*松开*/
            GPIOC->ODR |= (1<<13);
        }else{
            /*按下*/
            GPIOC->ODR &= ~(1<<13);
        }

        /* KEY5 */
        if((GPIOG->IDR & (1<<10)) == (1<<10)){    /* KEY2--->PA8 */
            /*松开*/
            GPIOI->ODR |= (1<<8);
        }else{
            /*按下*/
            GPIOI->ODR &= ~(1<<8);
        }

        delay(100000);
        GPIOH->ODR &= ~(1<<7);
        delay(100000);

    }
    return 0;
}
