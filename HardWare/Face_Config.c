#include "stm32f10x.h"      
#include "OLED.h"
#include "BlueTooth.h"
#include "Variable.h"

//实现表情变化，调节是进中断后
void Face_Config(void)
{
	/*图案处理*/
	switch(Face_Mode)
	{
		case 0:
	    OLED_Clear();
	    OLED_ShowImage(0,0,128,64,Face_sleep);//睡觉
		  break;
		case 1:
			OLED_Clear();
		  OLED_ShowImage(0,0,128,64,Face_stare);//瞪大眼
		  break;
		case 2:
			OLED_Clear();
	  	OLED_ShowImage(0,0,128,64,Face_happy);//快乐
		  break;
	  case 3:
			OLED_Clear();
	  	OLED_ShowImage(0,0,128,64,Face_mania);//狂热
		  break;
		case 4:
			OLED_Clear();
	  	OLED_ShowImage(0,0,128,64,Face_very_happy);//非常快乐
		  break;
		case 5:
			OLED_Clear();
	  	OLED_ShowImage(0,0,128,64,Face_eyes);//眼睛
		 break;
		case 6:
			OLED_Clear();
	  	OLED_ShowImage(0,0,128,64,Face_hello);//打招呼
			break;
	}
	
	/*电量处理*/
	if(Battery_Bit)
	{
		OLED_ShowString(0,0,"Power:",OLED_6X8);
		if(CurBattery>=110) OLED_ShowString(36,0,"Charging",OLED_6X8);
		else if(CurBattery>=100)OLED_ShowNum(36,0,CurBattery,3,OLED_6X8);
		else OLED_ShowNum(36,0,CurBattery,2,OLED_6X8);
	}
	
	/*显示图案*/
		OLED_Update();
}
