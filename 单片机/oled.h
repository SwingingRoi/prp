//******************************************************************************/
//  �� �� ��   : oled.h
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
#ifndef __OLED_H
#define __OLED_H

#include "stm32l0xx_hal.h"

#define LCD_W 240
#define LCD_H 320
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long


//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	   

//-----------------OLED�˿ڶ���----------------  					   
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

 		     
#define OLED_CMD  0	                                  //д����
#define OLED_DATA 1	                                  //д����

extern  u16 BACK_COLOR, POINT_COLOR;                     //����ɫ������ɫ

void Lcd_Init(void); 
void LCD_Clear(u16 Color);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void LCD_WR_DATA8(char da);                             //��������-8λ����
void LCD_WR_DATA(int da);
void LCD_WR_REG(char da);

void LCD_DrawPoint(u16 x,u16 y);                        //����
void LCD_DrawPoint_big(u16 x,u16 y);                    //��һ�����
u16  LCD_ReadPoint(u16 x,u16 y);                         //����
void Draw_Circle(u16 x0,u16 y0,u8 r);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode);          //��ʾһ���ַ�
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len);           //��ʾ����
void LCD_Show2Num(u16 x,u16 y,u16 num,u8 len);          //��ʾ2������
void LCD_ShowString(u16 x,u16 y,const u8 *p);		 //��ʾһ���ַ���,16����
 
void showhanzi16(unsigned int x,unsigned int y,unsigned char index);
void showhanzi24(unsigned int x,unsigned int y,unsigned char index);
void shownum32(unsigned int x,unsigned int y,unsigned char index);



//������ɫ
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
#define BROWN 		 0XBC40 //��ɫ
#define BRRED 		 0XFC07 //�غ�ɫ
#define GRAY  		 0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 		 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)


					  		 
#endif  
	 
	 



