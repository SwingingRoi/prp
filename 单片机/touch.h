//******************************************************************************/
//  �� �� ��   : touch.h
//  �� �� ��   : v1.0
//  ��    ��   : liuweiwen
//  ��������   : 2018-0301
//  ��������   : TFT_LCD �ӿڳ���
//              ˵��: 
//              -�˲���Ϊ���������ӿڣ�BLKΪ���⿪��
//              GND    ��Դ��
//              VCC    3.3v��Դ
//              CLK    ��PB3
//              MOSI   ��PA7
//              RES    ��PC0
//              DC     ��PB6
//              CS1    ��PB4    
//              BLK    ��PB7
//              -����Ϊ�������ƽӿ�
//              MISO  ��PA6
//              CS2   ��PB5
//              PEN   ��PC1  
//All rights reserved
//******************************************************************************/

#ifndef __TOUCH_H
#define __TOUCH_H	

/* touch panel interface define */
#define  CMD_RDX  0xD0	 //����IC�����������
#define  CMD_RDY  0x90
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long

//#define PEN  	HAL_GPIO_ReadPin(GPIOC,LCD_TOUCH_PEN_EXT1_Pin)  	//PC1 INT
//#define MISO 	HAL_GPIO_ReadPin(GPIOA,SPIIN_Pin)   	               //PA6  MISO
//#define CS2  	PCout(0)  	//PC0  CS 


struct tp_pix_
{
	u16 x;
	u16 y;
};
struct tp_pixu32_
{
	u32 x;
	u32 y;
};
extern struct tp_pix_  tp_pixad,tp_pixlcd;	 //��ǰ���������ADֵ,ǰ�������������ֵ   
extern u16 vx,vy;  //�������ӣ���ֵ����1000֮���ʾ���ٸ�ADֵ����һ�����ص�
extern u16 chx,chy;//Ĭ�����ص�����Ϊ0ʱ��AD��ʼֵ
u8 tpstate(void);
void spistar(void);  
void Touch_Adjust(void);
void point(void); //��ͼ����
void getpos(void);//�������ֵ
u16 ReadFromCharFrom7843();         //SPI ������
#endif  
	 
	 



