#include "stm32f10x.h"
#include "pwm.h"
#include "SysTick.h"
#include "sys.h"

/************************************************
 ALIENTEK ��ӢSTM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main()
{
	pwm_init();
	while(1)
	{
		//delay_ms(100);
		//TIM_SetCompare1(TIM3, 190);//0?
		//delay_ms(100);
		TIM_SetCompare1(TIM3, 185);
	}
}



