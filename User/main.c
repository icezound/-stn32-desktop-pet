#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "BlueTooth.h"
#include "Servo.h"
#include "PetAction.h"
#include "Face_Config.h"
#include "PWM.h"
#include "PowerDetection.h"
#include "Variable.h"
#include "Led_Breathing.h"

/***************************************************************************************
  * 本程序由博主我Sngels_wyh创建并免费开源共享
  * 你可以任意查看、使用和修改，并应用到自己的项目之中
  * 
  * 程序名称：				基于STM32F103C8T6单片机的桌面宠物小项目
  * 此程序更新时间：			2025.8.20
  * 
  * 主要在立创开源平台、CSDN网站、哔哩哔哩、抖音分享自己的作品。
	*	相关的资料可以去立创开源硬件平台网站上搜索,作品附件放置更新网盘，如有更新可方便快速查看
	* 地址:https://oshwhub.com/sngelswyh/stm32-smart-desktop-pet
  ***************************************************************************************/
int main(void)
{
	GetBattery_Init();//电量检测初始化
	Servo_Init();//舵机初始化
	OLED_Init();//OLED初始化
	BlueTooth_Init();//蓝牙初始化

	OLED_ShowImage(0,0,128,64,Face_eyes);
	OLED_Update();
	while(1)
	{	
		/*动作判断*/
		PetAction_Perform();
		/*显示表情(电量)*/
		Face_Config();
	}
}

/*每20ms进一次中断*/
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{	
		/*电量检测*/
		GetCur_Power();
		/*呼吸灯*/
		LED_Breathing();
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}
