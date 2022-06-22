#include "mxkey.h"
#include <regx52.h>
#include "dk.h"
#include "LCD1602.h"
#include "Buzzer.h"
#define k1 P3_1
#define k2 P3_0
#define k3 P3_2
#define k4 P3_3
unsigned int count,ho,mi,se,kn,ho1,mi1,se1;
void main()
{
	Timer0_Init();
	LCD_Init();
	
	while(1)
	{
		LCD_ShowNum(1,1,ho,2);
		LCD_ShowChar(1,3,':');
		LCD_ShowNum(1,4,mi,2);
		LCD_ShowChar(1,6,':');
		LCD_ShowNum(1,7,se,2);
		LCD_ShowNum(2,1,ho1,2);
		LCD_ShowChar(2,3,':');
		LCD_ShowNum(12,4,mi1,2);
		LCD_ShowChar(2,6,':');
		LCD_ShowNum(2,7,se1,2);
		while(se==60)
		{
			mi++;
			se=0;
		}
		while(mi==60)
		{
			mi=0;
			ho++;
		}
		if(k1==0)		
		{
			delay(20);
			while(k1==0);
			delay(20);
			se++;
		}
				if(k2==0)		
		{
			delay(20);
			while(k2==0);
			delay(20);
			mi++;
		}
				if(k3==0)		
		{
			delay(20);
			while(k3==0);
			delay(20);
			ho++;
		}
		if(k4==0)		
		{
			delay(20);
			while(k4==0);
			delay(20);
			se1=ho1=mi1=0;
		}
		kn=mxkey();
			switch(kn)
			{
				case 1:se1++;break;
				case 2:mi1++;break;
				case 3:ho1++;break;
			}
			while(se==se1 && mi==mi1 && ho==ho1)
			{
				Buzzer_Time(100);
			}
	}
}

void Timer0_Routine() interrupt 1
{
	TH0=64535/256;
	TL0=64535%256;
	count++;
	if(count>+1000)
	{
		count=0;
		se++;
	}
		
}
