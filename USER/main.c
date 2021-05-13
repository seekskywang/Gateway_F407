#include "sys.h"
#include "delay.h"
#include "includes.h"

/*
**********************************************************************************************************
��������
**********************************************************************************************************
*/
static void vTaskTaskUserIF(void *pvParameters);
static void vTaskLED(void *pvParameters);
static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void AppTaskCreate (void);
/*
**********************************************************************************************************
��������
**********************************************************************************************************
*/
static TaskHandle_t xHandleTaskUserIF = NULL;
static TaskHandle_t xHandleTaskLED = NULL;
static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;

int main(void)
{ 
	__set_PRIMASK(1);
	
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	
	/* �������� */
	AppTaskCreate();
	
    /* �������ȣ���ʼִ������ */
    vTaskStartScheduler();
	
	while(1)
	{
	}
}

/*
*********************************************************************************************************
*	�� �� ��: vTaskTaskUserIF
*	����˵��: �ӿ���Ϣ������������LED��˸	
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
*   �� �� ��: 1  (��ֵԽС���ȼ�Խ�ͣ������uCOS�෴)
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
*	�� �� ��: vTaskLED
*	����˵��: LED��˸	
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
*   �� �� ��: 2  
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
*	�� �� ��: vTaskMsgPro
*	����˵��: ��Ϣ��������������LED��˸	
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
*   �� �� ��: 3  
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
*	�� �� ��: vTaskStart
*	����˵��: ��������Ҳ����������ȼ�������������LED��˸
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
*   �� �� ��: 4  
*********************************************************************************************************
*/
static void vTaskStart(void *pvParameters)
{
    while(1)
    {
//		/* LED��˸ */
//		LedToggle(2);
        vTaskDelay(1300);
    }
}

/*
*********************************************************************************************************
* �� �� ��: AppTaskCreate
* ����˵��: ����Ӧ������
* �� ��: �� * �� �� ֵ: ��
*********************************************************************************************************
*/
static void AppTaskCreate (void)
{
	xTaskCreate( vTaskTaskUserIF, /* ������ */
	"vTaskUserIF", /* ������ */
	512, /* stack ��С����λ word��Ҳ���� 4 �ֽ� */
	NULL, /* ������� */
	1, /* �������ȼ�*/
	&xHandleTaskUserIF ); /* ������ */
	xTaskCreate( vTaskLED, /* ������ */
	"vTaskLED", /* ������ */
	512, /* stack ��С����λ word��Ҳ���� 4 �ֽ� */
	NULL, /* ������� */
	2, /* �������ȼ�*/
	&xHandleTaskLED ); /* ������ */
	xTaskCreate( vTaskMsgPro, /* ������ */
	"vTaskMsgPro", /* ������ */
	512, /* stack ��С����λ word��Ҳ���� 4 �ֽ� */
	NULL, /* ������� */
	3, /* �������ȼ�*/
	&xHandleTaskMsgPro ); /* ������ */
	xTaskCreate( vTaskStart, /* ������ */
	"vTaskStart", /* ������ */
	512, /* stack ��С����λ word��Ҳ���� 4 �ֽ� */
	NULL, /* ������� */
	4, /* �������ȼ�*/
	&xHandleTaskStart ); /* ������ */
}

 



