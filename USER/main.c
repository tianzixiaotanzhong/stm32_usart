#include "usart.h"
#include "stdio.h"


int main()
{
	usart_init(115200);
    while (1)
    {
        printf("hello world£¡\r\n");
    }
    
}
