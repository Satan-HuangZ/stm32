#include "pwm.h"

void pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个GPIO变量,用来初始化GPIO
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//声明一个时间的结构体变量,初始化定时器
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;// PA6 PA7
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推免输出
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//TIM3定时器初始化
	TIM_TimeBaseInitStructure.TIM_Period = 199; //PWM 频率=72000/(199+1)=36Khz//设置自动重载寄存器周期的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7199;//设置TIMx时钟预分频
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;//??????:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM向上计数模式
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseInitStructure);

	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//映射指定的管脚	//pC6

	//PWM初始化	  //根据TIM_OCInitStruct指定的参数设置外设TIMx
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//PWM输出使能
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

	TIM_OC1Init(TIM3,&TIM_OCInitStructure);//通道1
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);//通道2
	
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_Cmd(TIM3,ENABLE);//使能定时器3

}
