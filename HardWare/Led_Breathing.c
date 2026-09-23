#include "stm32f10x.h"                  // Device header
#include "Variable.h"
#include "PWM.h"

/*注意LED的GPIO与PWM配置已经在PWM.c中配置好了，这个函数是在中断中执行的函数*/
void LED_Breathing(void)
{
		if(AllLed==1 && BreatheLed==0)//如果灯光开启且不开启呼吸灯,亮度拉满
		{
			PWM_LED1(20000);
			PWM_LED2(20000);
		}
		else if(AllLed==1 && BreatheLed==1)//如果灯光开启且开启呼吸灯
		{
			if(PanDuan==1)
			{
				HuXi+=100;
				PWM_LED1(HuXi);
				PWM_LED2(HuXi);
				if(HuXi==20000)PanDuan=2;
			}
			else if(PanDuan==2)
			{
				HuXi-=100;
				PWM_LED1(HuXi);
				PWM_LED2(HuXi);
				if(HuXi==0)PanDuan=3;	
			}
			else if(PanDuan==3)
			{
				Wait+=1000;
				if(Wait==20000)
				{
					PanDuan=1;
					Wait=0;
				}
			}
		}
		else if(AllLed==0)
		{
			PWM_LED1(0);
			PWM_LED2(0);
		}
}
