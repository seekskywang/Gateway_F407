#include "sys.h"
#include "delay.h"
#include "includes.h"

/*
**********************************************************************************************************
函数声明
**********************************************************************************************************
*/
static void vTaskTaskUserIF(void *pvParameters);
static void vTaskLED(void *pvParameters);
static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void AppTaskCreate (void);
/*
**********************************************************************************************************
变量声明
**********************************************************************************************************
*/
static TaskHandle_t xHandleTaskUserIF = NULL;
static TaskHandle_t xHandleTaskLED = NULL;
static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;

int main(void)
{ 
	__set_PRIMASK(1);
	
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	
	/* 创建任务 */
	AppTaskCreate();
	
    /* 启动调度，开始执行任务 */
    vTaskStartScheduler();
	
	while(1)
	{
	}
}

/*
*********************************************************************************************************
*	函 数 名: vTaskTaskUserIF
*	功能说明: 接口消息处理，这里用作LED闪烁	
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 1  (数值越小优先级越低，这个跟uCOS相反)
*********************************************************************************************************
*/
static void vTaskTaskUserIF(void *pvParameters)
{
    while(1)
    {
		LedToggle(1);
        vTaskDelay(500);
		LedToggle(2);
		vTaskDelay(500);
	}
}

/*
*********************************************************************************************************
*	函 数 名: vTaskLED
*	功能说明: LED闪烁	
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 2  
*********************************************************************************************************
*/
static void vTaskLED(void *pvParameters)
{
    while(1)
    {
//		LedToggle(2);
        vTaskDelay(1100);
    }
}

/*
*********************************************************************************************************
*	函 数 名: vTaskMsgPro
*	功能说明: 信息处理，这里是用作LED闪烁	
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 3  
*********************************************************************************************************
*/
static void vTaskMsgPro(void *pvParameters)
{
    while(1)
    {
//		LedToggle(1);
//        vTaskDelay(500);
//		LedToggle(2);
		vTaskDelay(1200);
    }
}

/*
*********************************************************************************************************
*	函 数 名: vTaskStart
*	功能说明: 启动任务，也就是最高优先级任务，这里用作LED闪烁
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 4  
*********************************************************************************************************
*/
static void vTaskStart(void *pvParameters)
{
    while(1)
    {
//		/* LED闪烁 */
//		LedToggle(2);
        vTaskDelay(1300);
    }
}

/*
*********************************************************************************************************
* 函 数 名: AppTaskCreate
* 功能说明: 创建应用任务
* 形 参: 无 * 返 回 值: 无
*********************************************************************************************************
*/
static void AppTaskCreate (void)
{
	xTaskCreate( vTaskTaskUserIF, /* 任务函数 */
	"vTaskUserIF", /* 任务名 */
	512, /* stack 大小，单位 word，也就是 4 字节 */
	NULL, /* 任务参数 */
	1, /* 任务优先级*/
	&xHandleTaskUserIF ); /* 任务句柄 */
	xTaskCreate( vTaskLED, /* 任务函数 */
	"vTaskLED", /* 任务名 */
	512, /* stack 大小，单位 word，也就是 4 字节 */
	NULL, /* 任务参数 */
	2, /* 任务优先级*/
	&xHandleTaskLED ); /* 任务句柄 */
	xTaskCreate( vTaskMsgPro, /* 任务函数 */
	"vTaskMsgPro", /* 任务名 */
	512, /* stack 大小，单位 word，也就是 4 字节 */
	NULL, /* 任务参数 */
	3, /* 任务优先级*/
	&xHandleTaskMsgPro ); /* 任务句柄 */
	xTaskCreate( vTaskStart, /* 任务函数 */
	"vTaskStart", /* 任务名 */
	512, /* stack 大小，单位 word，也就是 4 字节 */
	NULL, /* 任务参数 */
	4, /* 任务优先级*/
	&xHandleTaskStart ); /* 任务句柄 */
}

 



