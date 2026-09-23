#include "stm32f10x.h"                  // Device header
#include "AD.h"
#include "Variable.h"



/*初始化ADC函数*/

void GetBattery_Init(void)
{
	AD_Init();
}

/*获取一次电量(平均前)*/
uint16_t GetBattery(void)
{
	Battery_Value=(3.3*4*Get_ADC()/4096)*100-300;
	return (uint16_t)Battery_Value;
}

/*获取平均电量(读取10次adc对应的电量值，再取平均数)*/
void GetCur_Power(void)
{
		if(++Battery_num<=100)
		{
			temp=GetBattery();
			temp1+=temp;
		}
		else
		{
			CurBattery=(uint16_t)(temp1/100);
			temp1=0;
			Battery_num=0;
		}
}
