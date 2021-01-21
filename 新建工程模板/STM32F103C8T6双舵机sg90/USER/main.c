#include "stm32f10x.h"
#include "pwm.h"
#include "SysTick.h"
 
 int main(void)
 {
	SysTick_Init(72);	 
  pwm_init();
  while(1)
	{
		delay_ms(500);
	  TIM_SetCompare1(TIM3, 175);
		TIM_SetCompare2(TIM3, 175);
		delay_ms(500);
		TIM_SetCompare1(TIM3, 180);
		TIM_SetCompare2(TIM3, 180);
		delay_ms(500);
		TIM_SetCompare1(TIM3, 185);
		TIM_SetCompare2(TIM3, 185);
		delay_ms(500);
		TIM_SetCompare1(TIM3, 190);
		TIM_SetCompare2(TIM3, 190);
		delay_ms(500);
		TIM_SetCompare1(TIM3, 195);
		TIM_SetCompare2(TIM3, 195);
	}
 }
