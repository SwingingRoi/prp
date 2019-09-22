//******************************************************************************/
//  文 件 名   : touch.h
//  版 本 号   : v1.0
//  作    者   : liuweiwen
//  生成日期   : 2018-0301
//  功能描述   : TFT_LCD 接口程序
//              说明: 
//              -此部分为不带触摸接口，BLK为背光开关
//              GND    电源地
//              VCC    3.3v电源
//              CLK    接PB3
//              MOSI   接PA7
//              RES    接PC0
//              DC     接PB6
//              CS1    接PB4    
//              BLK    接PB7
//              -以下为触摸控制接口
//              MISO  接PA6
//              CS2   接PB5
//              PEN   接PC1  
//All rights reserved
//******************************************************************************/

#ifndef __TOUCH_H
#define __TOUCH_H	

/* touch panel interface define */
#define  CMD_RDX  0xD0	 //触摸IC读坐标积存器
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
extern struct tp_pix_  tp_pixad,tp_pixlcd;	 //当前触控坐标的AD值,前触控坐标的像素值   
extern u16 vx,vy;  //比例因子，此值除以1000之后表示多少个AD值代表一个像素点
extern u16 chx,chy;//默认像素点坐标为0时的AD起始值
u8 tpstate(void);
void spistar(void);  
void Touch_Adjust(void);
void point(void); //绘图函数
void getpos(void);//获得坐标值
u16 ReadFromCharFrom7843();         //SPI 读数据
#endif  
	 
	 



