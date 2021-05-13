#include "led.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com							  
////////////////////////////////////////////////////////////////////////////////// 	 

//初始化PA6和PA7为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOA时钟

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIO
	
	GPIO_SetBits(GPIOD,GPIO_Pin_0 | GPIO_Pin_1);//设置高，灯灭

}

void LedToggle(u8 bit)
{
	if(bit == 1)
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_0);  //LED0对应引脚GPIOA.6拉低，亮  等同LED0=0;
		GPIO_SetBits(GPIOD,GPIO_Pin_1);   //LED1对应引脚GPIOA.7拉高，灭 等同LED1=1;
	}else if(bit == 2){
		GPIO_SetBits(GPIOD,GPIO_Pin_0);	   //LED0对应引脚GPIOA.6拉高，灭  等同LED0=1;
		GPIO_ResetBits(GPIOD,GPIO_Pin_1); //LED1对应引脚GPIOA.7拉低，亮 等同LED1=0;
	}
}




