#include <stdbool.h>
#include "main.h"
// declaración de variables
enum led_t{ LED_RED, LED_GREEN, LED_YELLOW, LED_BLUE } ;
uint8_t button_IsEnabled (void);
uint8_t ReadButton;

//configuration of the button

void Button_Init (void) {
        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //Input Pullup

        GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//read the button

uint8_t button_IsEnabled (void) {
        return (GPIO_ReadInputDataBit (GPIOA, GPIO_Pin_15));
}


//configure the outputs
void LED_Init(void){
 GPIO_InitTypeDef GPIO_InitStructure; 

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

GPIO_InitStructure.GPIO_Pin   =     GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;

GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;     
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOB, &GPIO_InitStructure);             
 }


//function define led colors for the each pin

void LED_Set(enum led_t led, bool state){

  switch(led){

  case LED_RED:
  if(state==1){ GPIO_SetBits(GPIOB,GPIO_Pin_14); }
  else
              { GPIO_ResetBits(GPIOB,GPIO_Pin_14); }
  break;

  case LED_GREEN:
  if(state==1){ GPIO_SetBits(GPIOB,GPIO_Pin_12); }
  else
              { GPIO_ResetBits(GPIOB,GPIO_Pin_12); }
  break;

  case LED_YELLOW:
  if(state==1){ GPIO_SetBits(GPIOB,GPIO_Pin_13); }
  else
              { GPIO_ResetBits(GPIOB,GPIO_Pin_13); }
  break;

  case LED_BLUE:
  if(state==1){ GPIO_SetBits(GPIOB,GPIO_Pin_15); }
  else
              { GPIO_ResetBits(GPIOB,GPIO_Pin_15); }
  break;
        }
}

//programa principal

int main(void)
 {

 LED_Init();
 Button_Init ();

 while (1){
                
        if(button_IsEnabled()!=0){
                        LED_Set(LED_RED, 1);
                        LED_Set(LED_YELLOW, 1);
                        LED_Set(LED_BLUE, 0);
                        LED_Set(LED_GREEN, 0);
        }
        else {                 
                        LED_Set(LED_RED, 0);
                        LED_Set(LED_YELLOW, 0);
                        LED_Set(LED_BLUE, 1);
                        LED_Set(LED_GREEN, 1);
        }
  }
}
