#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_
#endif

#define GPIO_A 0x40020000u
#define GPIO_B 0x40020400u
#define GPIO_C 0x40020800u
#define GPIO_D 0x40020C00u
#define GPIO_E 0x40021000u
#define GPIO_F 0x40021400u
#define GPIO_G 0x40021800u
#define GPIO_H 0x40021C00u
#define GPIO_I 0x40022000u
#define GPIO_J 0x40022400u
#define GPIO_K 0x40022800u

#define mode_reg 0x00u
#define speed_reg 0x08u
#define pull_reg 0x0Cu
#define input_reg 0x10u
#define set_reg 0x18u



#include "bsp.h"

void hwInit(void);
void MyApp();

int main(void)
{
   hwInit();

   MyApp();
}

void hwInit(void)
{

  bspInit();
  // More Init later
}

void MyDelay(unsigned int n)
{
   volatile unsigned int delay;
   for(delay=0; delay<=n*3600000; delay++);
}

int CheckClockStatus(int GPIOPort)
{
	if (*(volatile unsigned int*)(0x40023830U)&&(0x01u<<GPIOPort-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void ClockEnable(int GPIOPort)
{
	*(volatile unsigned int*)(0x40023830U)|=(0x01u<<GPIOPort-1);
}

void LEDenable(unsigned char No)
{
		if (No==1) // SYS_USER_LED1 PG12
		{
		// Mode RG: Output
			*(volatile unsigned int*)(0x40021800U)&=~(0x03<<2*12);
			*(volatile unsigned int *)(0x40021800u) |= (0x01u)<<(2*12);
		// output speed: Very high speed
			*(volatile unsigned int*)(0x40021808U)|=(0x03<<2*12);
		// pull-up pull down: pull up
			*(volatile unsigned int*)(0x4002180CU)&=~(0x03<<2*12);
			*(volatile unsigned int*)(0x4002180CU)|=(0x01<<2*12);
		}
		else if (No==2) // SYS_USER_LED2 PE5
		{
		// Mode RG: Output
			*(volatile unsigned int*)(0x40021000U)&=~(0x03<<2*5);
			*(volatile unsigned int*)(0x40021000U)|=(0x01<<2*5);
		// output speed: Very high speed
			*(volatile unsigned int*)(0x40021008U)|=(0x03<<2*5);
		// pull-up pull down: pull up
			*(volatile unsigned int*)(0x4002180CU)&=~(0x03<<2*5);
			*(volatile unsigned int*)(0x4002180CU)|=(0x01<<2*5);
		}
		else if (No==3) // SYS_USER_LED3 PE4
		{
		// Mode RG: Output
			*(volatile unsigned int*)(0x40021000U)&=~(0x03<<2*4);
			*(volatile unsigned int*)(0x40021000U)|=(0x01<<2*4);
		// output speed: Very high speed
			*(volatile unsigned int*)(0x40021008U)|=(0x03<<2*4);
		// pull-up pull down: pull up
			*(volatile unsigned int*)(0x4002180CU)&=~(0x03<<2*4);
			*(volatile unsigned int*)(0x4002180CU)|=(0x01<<2*4);
		}
		else if (No==4) // SYS_USER_LED4 PG10
		{
		// Mode RG: Output
			*(volatile unsigned int*)(0x40021800U)&=~(0x03<<2*10);
			*(volatile unsigned int*)(0x40021800U)|=(0x01<<2*10);
		// output speed: Very high speed
			*(volatile unsigned int*)(0x40021808U)|=(0x03<<2*10);
		// pull-up pull down: pull up
			*(volatile unsigned int*)(0x4002180CU)&=~(0x03<<2*10);
			*(volatile unsigned int*)(0x4002180CU)|=(0x01<<2*10);
		}
}


void GPIOEnable(unsigned char num)
{
	if (num==1) //PC2
	{
		*(volatile unsigned int*)(GPIO_C+mode_reg)&=~(0x03<<2*2);
		*(volatile unsigned int *)(GPIO_C+mode_reg) |= (0x01u)<<(2*2);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_C+speed_reg)|=(0x03<<2*2);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_C+pull_reg)&=~(0x03<<2*2);
		*(volatile unsigned int*)(GPIO_C+pull_reg)|=(0x01<<2*2);
	}
	if (num==2) //PA3
	{
		*(volatile unsigned int*)(GPIO_A+mode_reg)&=~(0x03<<2*3);
		*(volatile unsigned int *)(GPIO_A+mode_reg) |= (0x01u)<<(2*3);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_A+speed_reg)|=(0x03<<2*3);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_A+pull_reg)&=~(0x03<<2*3);
		*(volatile unsigned int*)(GPIO_A+pull_reg)|=(0x01<<2*3);
	}
	if (num==3) //PB9
	{
		*(volatile unsigned int*)(GPIO_B+mode_reg)&=~(0x03<<2*9);
		*(volatile unsigned int *)(GPIO_B+mode_reg) |= (0x01u)<<(2*9);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_B+speed_reg)|=(0x03<<2*9);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_B+pull_reg)&=~(0x03<<2*9);
		*(volatile unsigned int*)(GPIO_B+pull_reg)|=(0x01<<2*9);
	}
	if (num==4) //PB15
	{
		*(volatile unsigned int*)(GPIO_B+mode_reg)&=~(0x03<<2*15);
		*(volatile unsigned int *)(GPIO_B+mode_reg) |= (0x01u)<<(2*15);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_B+speed_reg)|=(0x03<<2*15);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_B+pull_reg)&=~(0x03<<2*15);
		*(volatile unsigned int*)(GPIO_B+pull_reg)|=(0x01<<2*15);
	}
	if (num==5) //PB14
	{
		*(volatile unsigned int*)(GPIO_B+mode_reg)&=~(0x03<<2*14);
		*(volatile unsigned int *)(GPIO_B+mode_reg) |= (0x01u)<<(2*14);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_B+speed_reg)|=(0x03<<2*14);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_B+pull_reg)&=~(0x03<<2*14);
		*(volatile unsigned int*)(GPIO_B+pull_reg)|=(0x01<<2*14);
	}
}

void GPIOset(unsigned char num)
{
	if (num==1) //PC2
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<2+16);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<2);
	}
	if (num==2) //PA3
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<3+16);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<3);
	}
	if (num==3) //PB9
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<9+16);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<9);
	}
	if (num==4) //PB15
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<15+16);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<15);
	}
	if (num==5) //PB14
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<14+16);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<14);
	}
}

void GPIOreset(unsigned char num)
{
	if (num==1)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<2);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<2+16);
	}
	if (num==2) //PA3
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<3);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<3+16);
	}
	if (num==3) //PB9
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<9);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<9+16);
	}
	if (num==4) //PB15
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<15);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<15+16);
	}
	if (num==5) //PB14
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<14);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<14+16);
	}
	if (num==6) //PA9
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<9);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<9+16);
	}
}

void TurnOnOneLED(unsigned char No)
{
	if (No==1) 	// SYS_USER_LED1 PG12
	{
	// set/reset:
		*(volatile unsigned int*)(0x40021818U)&=~(0x01<<12);
		*(volatile unsigned int*)(0x40021818U)|=(0x01u<<(12+16));
	}
	else if (No==2) // SYS_USER_LED2 PE5
	{
		*(volatile unsigned int*)(0x40021018U)&=~(0x01u<<5);
		*(volatile unsigned int*)(0x40021018U)|=(0x01u<<(5+16));
	}
	else if (No==3) // SYS_USER_LED3 PE4
	{
		*(volatile unsigned int*)(0x40021018U)&=~(0x01u<<4);
		*(volatile unsigned int*)(0x40021018U)|=(0x01u<<(4+16));
	}
	else if (No==4) // SYS_USER_LED4 PG10
	{
		*(volatile unsigned int*)(0x40021818U)&=~(0x01u<<10);
		*(volatile unsigned int*)(0x40021818U)|=(0x01u<<(10+16));
	}
}

void TurnOffOneLED(unsigned char No)
{
	if (No==1) 	// SYS_USER_LED1 PG12
	{
	// set/reset:
		*(volatile unsigned int*)(0x40021818U)&=~(0x01u<<(12+16));
		*(volatile unsigned int*)(0x40021818U)|=(0x01u<<12);
	}
	else if (No==2) // SYS_USER_LED2 PE5
	{
		*(volatile unsigned int*)(0x40021018U)&=~(0x01u<<(5+16));
		*(volatile unsigned int*)(0x40021018U)|=(0x01u<<5);
	}
	else if (No==3) // SYS_USER_LED3 PE4
	{
		*(volatile unsigned int*)(0x40021018U)&=~(0x01u<<(4+16));
		*(volatile unsigned int*)(0x40021018U)|=(0x01u<<4);
	}
	else if (No==4) // SYS_USER_LED4 PG10
	{
		*(volatile unsigned int*)(0x40021818U)&=~(0x01u<<(10+16));
		*(volatile unsigned int*)(0x40021818U)|=(0x01u<<10);
	}
}

void ButtonEnable(unsigned char num)
{
	//BUT_USER1 - PC12
	if (num==1)
	{
		*(volatile unsigned int*)(GPIO_C+mode_reg)&=~(0x03u<<2*12);
		*(volatile unsigned int*)(GPIO_C+speed_reg)&=~(0x03u<<2*12);
		*(volatile unsigned int*)(GPIO_C+pull_reg)&=~(0x03u<<2*12);
	}
	//BUT_USER2 - PG3
	if (num==2)
	{
		*(volatile unsigned int*)(GPIO_G+mode_reg)&=~(0x03u<<2*3);
		*(volatile unsigned int*)(GPIO_G+speed_reg)&=~(0x03u<<2*3);
		*(volatile unsigned int*)(GPIO_G+pull_reg)&=~(0x03u<<2*3);
	}
}

int ButtonPressed(unsigned char Button)
{
	if (Button==1)//BUT_USER1 - PC12
	{
		if (*(volatile unsigned int*)(GPIO_C+input_reg)&(0x01u<<12))
		{
			return 1;
		}
		return 0;
	}
	if (Button==2)//BUT_USER2 - PG3
	{
		if (*(volatile unsigned int*)(GPIO_G+input_reg)&(0x01u<<3))
		{
			return 2;
		}
		return 0;
	}
}

int ButtonFlag[3]={0,};

int ButtonPressed_edge(unsigned char Button)
{
	if (Button==1)//BUT_USER1 - PC12
	{
		if (ButtonPressed(1)==1)
		{
			ButtonFlag[1]=1;
			return 0;
		}
		if (ButtonFlag[1]==1&&ButtonPressed(1)==0)
		{
			ButtonFlag[1]=0;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (Button==2)
	{
		if (ButtonPressed(2)==2)
		{
			ButtonFlag[2]=1;
			return 0;
		}
		if (ButtonFlag[2]==1&&!ButtonPressed(2)==0)
		{
			ButtonFlag[2]=0;
			return 2;
		}
		else
		{
			return 0;
		}
	}
}

unsigned char skip_flag=0;

int Skip_Pressed()
{
	//PF10
	// input mode
	*(volatile unsigned int*)(GPIO_F+mode_reg)&=~(0x03u<<2*10);
	// output speed: Low speed
	*(volatile unsigned int*)(GPIO_F+speed_reg)&=~(0x03<<2*10);
	// No pull up
	*(volatile unsigned int*)(GPIO_F+pull_reg)&=~(0x03<<2*10);
	if (*(volatile unsigned int*)(GPIO_F+input_reg)&(0x01<<10))
	{
		skip_flag=1;
		return 0;
	}
	if (skip_flag==1&&!(*(volatile unsigned int*)(GPIO_F+input_reg)&(0x01<<10)))
	{
		skip_flag=0;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Sevenseg_Enable(unsigned char No)
{
	//PC7
	if (No==0)
	{
		*(volatile unsigned int*)(GPIO_C+mode_reg)&=~(0x03<<2*7);
		*(volatile unsigned int *)(GPIO_C+mode_reg) |= (0x01u)<<(2*7);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_C+speed_reg)|=(0x03<<2*7);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_C+pull_reg)&=~(0x03<<2*7);
		*(volatile unsigned int*)(GPIO_C+pull_reg)|=(0x01<<2*7);
	}
	// PC6
	if (No==1)
	{
		*(volatile unsigned int*)(GPIO_C+mode_reg)&=~(0x03<<2*6);
		*(volatile unsigned int *)(GPIO_C+mode_reg) |= (0x01u)<<(2*6);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_C+speed_reg)|=(0x03<<2*6);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_C+pull_reg)&=~(0x03<<2*6);
		*(volatile unsigned int*)(GPIO_C+pull_reg)|=(0x01<<2*6);
	}
	// PG6
	if (No==2)
	{
		*(volatile unsigned int*)(GPIO_G+mode_reg)&=~(0x03<<2*6);
		*(volatile unsigned int *)(GPIO_G+mode_reg) |= (0x01u)<<(2*6);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_G+speed_reg)|=(0x03<<2*6);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_G+pull_reg)&=~(0x03<<2*6);
		*(volatile unsigned int*)(GPIO_G+pull_reg)|=(0x01<<2*6);
	}
	// PB4
	if (No==3)
	{
		*(volatile unsigned int*)(GPIO_B+mode_reg)&=~(0x03<<2*4);
		*(volatile unsigned int *)(GPIO_B+mode_reg) |= (0x01u)<<(2*4);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_B+speed_reg)|=(0x03<<2*4);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_B+pull_reg)&=~(0x03<<2*4);
		*(volatile unsigned int*)(GPIO_B+pull_reg)|=(0x01<<2*4);
	}
	// PG7
	if (No==4)
	{
		*(volatile unsigned int*)(GPIO_G+mode_reg)&=~(0x03<<2*7);
		*(volatile unsigned int *)(GPIO_G+mode_reg) |= (0x01u)<<(2*7);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_G+speed_reg)|=(0x03<<2*7);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_G+pull_reg)&=~(0x03<<2*7);
		*(volatile unsigned int*)(GPIO_G+pull_reg)|=(0x01<<2*7);
	}
	// PA8
	if (No==5)
	{
		*(volatile unsigned int*)(GPIO_A+mode_reg)&=~(0x03<<2*8);
		*(volatile unsigned int *)(GPIO_A+mode_reg) |= (0x01u)<<(2*8);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_A+speed_reg)|=(0x03<<2*8);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_A+pull_reg)&=~(0x03<<2*8);
		*(volatile unsigned int*)(GPIO_A+pull_reg)|=(0x01<<2*8);
	}
	// PA2
	if (No==6)
	{
		*(volatile unsigned int*)(GPIO_A+mode_reg)&=~(0x03<<2*2);
		*(volatile unsigned int *)(GPIO_A+mode_reg) |= (0x01u)<<(2*2);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_A+speed_reg)|=(0x03<<2*2);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_A+pull_reg)&=~(0x03<<2*2);
		*(volatile unsigned int*)(GPIO_A+pull_reg)|=(0x01<<2*2);
	}
	// PC1
	if (No==7)
	{
		*(volatile unsigned int*)(GPIO_C+mode_reg)&=~(0x03<<2*1);
		*(volatile unsigned int *)(GPIO_C+mode_reg) |= (0x01u)<<(2*1);
		// output speed: Very high speed
		*(volatile unsigned int*)(GPIO_C+speed_reg)|=(0x03<<2*1);
		// pull-up pull down: pull up
		*(volatile unsigned int*)(GPIO_C+pull_reg)&=~(0x03<<2*1);
		*(volatile unsigned int*)(GPIO_C+pull_reg)|=(0x01<<2*1);
	}
}

void Sevenseg_Set(unsigned char No)
{
	//PC7
	if (No==0)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<7+16);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<7);
	}
	// PC6
	if (No==1)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<6+16);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<6);
	}
	// PG6
	if (No==2)
	{
		*(volatile unsigned int*)(GPIO_G+set_reg)&=~(0x01<<6+16);
		*(volatile unsigned int*)(GPIO_G+set_reg)|=(0x01u<<6);
	}
	// PB4
	if (No==3)
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<4+16);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<4);
	}
	// PG7
	if (No==4)
	{
		*(volatile unsigned int*)(GPIO_G+set_reg)&=~(0x01<<7+16);
		*(volatile unsigned int*)(GPIO_G+set_reg)|=(0x01u<<7);
	}
	// PA8
	if (No==5)
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<8+16);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<8);
	}
	// PA2
	if (No==6)
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<2+16);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<2);
	}
	// PC1
	if (No==7)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<1+16);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<1);
	}
}

void Sevenseg_Reset(unsigned char No)
{
	//PC7
	if (No==0)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<7);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<7+16);
	}
	// PC6
	if (No==1)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<6);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<6+16);
	}
	// PG6
	if (No==2)
	{
		*(volatile unsigned int*)(GPIO_G+set_reg)&=~(0x01<<6);
		*(volatile unsigned int*)(GPIO_G+set_reg)|=(0x01u<<6+16);
	}
	// PB4
	if (No==3)
	{
		*(volatile unsigned int*)(GPIO_B+set_reg)&=~(0x01<<4);
		*(volatile unsigned int*)(GPIO_B+set_reg)|=(0x01u<<4+16);
	}
	// PG7
	if (No==4)
	{
		*(volatile unsigned int*)(GPIO_G+set_reg)&=~(0x01<<7);
		*(volatile unsigned int*)(GPIO_G+set_reg)|=(0x01u<<7+16);
	}
	// PA8
	if (No==5)
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<8);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<8+16);
	}
	// PA2
	if (No==6)
	{
		*(volatile unsigned int*)(GPIO_A+set_reg)&=~(0x01<<2);
		*(volatile unsigned int*)(GPIO_A+set_reg)|=(0x01u<<2+16);
	}
	// PC1
	if (No==7)
	{
		*(volatile unsigned int*)(GPIO_C+set_reg)&=~(0x01<<1);
		*(volatile unsigned int*)(GPIO_C+set_reg)|=(0x01u<<1+16);
	}
}

void Seven_seg(unsigned char No)
{
	char Seven[8]={0xc0,0xf9,0xa4, // 0,1,2
								 0xb0,0x99,0x92, // 3,4,5
								 0x82,0xf8};		// 6,7
	unsigned char cnt=0x01;
	unsigned char num=0;
	do
	{
		if (Seven[No]&(cnt))
		{
			Sevenseg_Set(num);
		}
		else
		{
			Sevenseg_Reset(num);
		}
		cnt<<=1;
		num++;
	}while(cnt!=0);
}

void traffic_delay(unsigned char *state, unsigned char *cnt, unsigned int duration)
{
	for (int i=0;i<3;i++)
	{
		if (*state&(0x01<<i))
		{
			GPIOset(3-i);
		}
		else
		{
			GPIOreset(3-i);
		}
	}
	for (unsigned int time=0;time<duration*300000;time++)
	{
		for (int i=0;i<4;i++)
		{
			if (*cnt&(0x01<<i))
			{
				TurnOnOneLED(i+1);
			}
			else
			{
				TurnOffOneLED(i+1);
			}
		}
		if (*state==0)
		{
			Seven_seg(7-(time/300000));
			if (time<=5*300000)
			{
				GPIOreset(4);
			}
			else
			{
				if ((time%100000)<50000)
				{
					GPIOreset(4);
				}
				else
				{
					GPIOset(4);
				}
			}
		}
		if (*state==4)
		{
			Seven_seg(7-(time/300000));
			if (time<=5*300000)
			{
				GPIOreset(5);
			}
			else
			{
				if ((time%100000)<50000)
				{
					GPIOreset(5);
				}
				else
				{
					GPIOset(5);
				}
			}
		}
		if (ButtonPressed_edge(1)==1)
		{
			*cnt=0;
		}
		if (Skip_Pressed()==1)
		{
			break;
		}
	}
	(*state)++;
}


void traffic()
{
	for (int i=0;i<=7;i++)
	{
		if (i==1)
		{
			ButtonEnable(1);
		}
		if (i>0)
		{
			ClockEnable(i);
		}
		if (i<4)
		{
			LEDenable(i+1);
			TurnOffOneLED(i+1);
		}
		if (i<5)
		{
			GPIOEnable(i+1);
			GPIOset(i+1);
		}
		Sevenseg_Enable(i);
		Sevenseg_Set(i);
	}
	unsigned char state=0;
	unsigned char cnt=0;
	while(1)
	{
		while(1)
		{
			if (state==0||state==4)
			{
				traffic_delay(&state,cnt,7);
				break;
			}
			if (state==2||state==6)
			{
				traffic_delay(&state,cnt,20);
				break;
			}
			else
			{
				traffic_delay(&state,cnt,7);
				break;
			}
		}
		Seven_seg(0);
		GPIOset(4);
		GPIOset(5);
		if (state==8)
		{
			state=0;
			cnt++;
		}
		if (cnt==16)
		{
			cnt=0;
		}
	}
}


void MyApp()
{
	traffic();
}




