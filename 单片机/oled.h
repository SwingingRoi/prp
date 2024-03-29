//******************************************************************************/
//  文 件 名   : oled.h
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
#ifndef __OLED_H
#define __OLED_H

#include "stm32l0xx_hal.h"

#define LCD_W 240
#define LCD_H 320
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long


//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	   

//-----------------OLED端口定义----------------  					   
#define OLED_CS_Clr()   HAL_GPIO_WritePin(GPIOB,LCD_CS1_Pin,GPIO_PIN_RESET)   //CS1
#define OLED_CS_Set()   HAL_GPIO_WritePin(GPIOB,LCD_CS1_Pin,GPIO_PIN_SET)

#define OLED_RST_Clr()  HAL_GPIO_WritePin(GPIOC,LCD_RES_Pin,GPIO_PIN_RESET)   //RES
#define OLED_RST_Set()  HAL_GPIO_WritePin(GPIOC,LCD_RES_Pin,GPIO_PIN_SET)

#define OLED_DC_Clr()   HAL_GPIO_WritePin(GPIOB,LCD_DC_Pin,GPIO_PIN_RESET)    //DC
#define OLED_DC_Set()   HAL_GPIO_WritePin(GPIOB,LCD_DC_Pin,GPIO_PIN_SET)


#define OLED_SCLK_Clr() HAL_GPIO_WritePin(GPIOB,SPICLK_Pin,GPIO_PIN_RESET)  //CLK
#define OLED_SCLK_Set() HAL_GPIO_WritePin(GPIOB,SPICLK_Pin,GPIO_PIN_SET)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(GPIOA,SPIOUT_Pin,GPIO_PIN_RESET)     //DIN
#define OLED_SDIN_Set() HAL_GPIO_WritePin(GPIOA,SPIOUT_Pin,GPIO_PIN_SET)

 		     
#define OLED_CMD  0	                                  //写命令
#define OLED_DATA 1	                                  //写数据

extern  u16 BACK_COLOR, POINT_COLOR;                     //背景色，画笔色

void Lcd_Init(void); 
void LCD_Clear(u16 Color);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void LCD_WR_DATA8(char da);                             //发送数据-8位参数
void LCD_WR_DATA(int da);
void LCD_WR_REG(char da);

void LCD_DrawPoint(u16 x,u16 y);                        //画点
void LCD_DrawPoint_big(u16 x,u16 y);                    //画一个大点
u16  LCD_ReadPoint(u16 x,u16 y);                         //读点
void Draw_Circle(u16 x0,u16 y0,u8 r);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode);          //显示一个字符
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len);           //显示数字
void LCD_Show2Num(u16 x,u16 y,u16 num,u8 len);          //显示2个数字
void LCD_ShowString(u16 x,u16 y,const u8 *p);		 //显示一个字符串,16字体
 
void showhanzi16(unsigned int x,unsigned int y,unsigned char index);
void showhanzi24(unsigned int x,unsigned int y,unsigned char index);
void shownum32(unsigned int x,unsigned int y,unsigned char index);



//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 		 0XFFE0
#define GBLUE		 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 		 0XBC40 //棕色
#define BRRED 		 0XFC07 //棕红色
#define GRAY  		 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 		 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)


					  		 
#endif  
	 
	 



