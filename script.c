#include<reg51.h>

sbit rf=P2^0; //right motor IN1
sbit rb=P2^1; //right motor IN2
sbit lf=P2^6; //left motor IN1
sbit lb=P2^7; //left motor IN2

sbit ls=P2^2; //left sensor
sbit rs=P2^3; //right sensor

void delay()
{
	
	TMOD=0x01;
	TH0=0xFC;
	TL0=0X18;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
	
}

void msdelay(int m)
{
	int i;
	for(i=0;i<m;i++)
	 delay();
}

void forward()
{
	lf=1;
	rf=1;
	lb=0;
	rb=0;
}

void backward()
{
	lb=1;
	rb=1;
	lf=0;
	rf=0;
}

void left()
{
	rf=1;
	rb=0;
	lb=1;
	lf=0;
}

void right()
{
	lf=1;
	lb=0;
	rb=1;
	rf=0;
}

void stop()
{
	lf=0;
	rf=0;
	lb=0;
	rb=0;
}

void main()
{
	while(1)
	{
		if(ls==0 && rs==0)
		{
			backward();
			msdelay(500);
			right();
			msdelay(100);
		}
		  
		else if(ls==0 && rs==1)
		{
			left();
			msdelay(100);
		}
		else if(rs==0 && ls==1)
		{
			right();
			msdelay(100);
		}
		else
		{
			forward();
			
		}
	}
}
			

		
		