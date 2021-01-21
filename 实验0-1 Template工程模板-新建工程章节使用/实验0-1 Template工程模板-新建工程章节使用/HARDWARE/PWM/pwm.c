#include "pwm.h"

void pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ��GPIO����,������ʼ��GPIO
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//����һ��ʱ��Ľṹ�����,��ʼ����ʱ��
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;// PA6
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//TIM3��ʱ����ʼ��
	TIM_TimeBaseInitStructure.TIM_Period = 199; //PWM Ƶ��=72000/(199+1)=36Khz//�����Զ����ؼĴ������ڵ�ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7199;//����TIMxʱ��Ԥ��Ƶ
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;//??????:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseInitStructure);

	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//ӳ��ָ���Ĺܽ�	//pC6

	//PWM��ʼ��	  //����TIM_OCInitStructָ���Ĳ�����������TIMx
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//PWM���ʹ��
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	//????????TIM_OC1Init???TIM_OCInit,??????????????????
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);//??????TIMx?CCR1????????
	TIM_Cmd(TIM3,ENABLE);//??????TIMx??

}
