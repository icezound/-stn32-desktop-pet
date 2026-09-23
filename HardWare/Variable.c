/*在这里定义所有的变量，并允许外部引用*/
#include "stm32f10x.h"                  // Device header
#include "Variable.h"


/*动作相关*/
uint16_t PAnumbers=Chongfunumber;//动作重复次数
uint16_t TiaoTurn=0;             //向前跳
uint16_t TiaoTurn2=0;            //向后跳
uint16_t Action_Mode=2;   //动作模式,上电后是站立状态
uint16_t SpeedDelay=200;  //运动速度
uint16_t SwingDelay=6;    //摇摆速度
uint16_t Face_Mode=5;     //表情切换，上电是两个眼睛表情
uint8_t WeiBa_Bit=0;      //摇尾巴判断
uint8_t WeiBa_Value=90;   //摇尾巴的compare值
int8_t WeiBa_Dir=1;       //摇尾巴方向判断
uint16_t Sustainedmove=0; //持续运动


/*呼吸灯相关*/
uint16_t Time;            //呼吸灯间隔时间
uint16_t HuXi;            //呼吸灯输出脉冲数
uint16_t PanDuan=1;       //呼吸灯模式
uint16_t Wait=0;          //间隔时间
uint16_t AllLed=1;        //开启灯光
uint16_t BreatheLed=0;    //开启呼吸灯

/*测电量相关*/
float Battery_Value=0;
uint16_t temp;            //每200ms测得的当前电量
uint16_t temp1=0;         //每20ms测得的当前电量
uint16_t CurBattery;      //当前电量
uint8_t Battery_num=0;    //获取电量滤波系数
uint8_t Battery_Bit=1;
