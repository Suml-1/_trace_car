#include <INTRINS.H>
void Delay(unsigned int xms)	//@11.0592MHz 延迟1毫秒
{
	unsigned char data i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}