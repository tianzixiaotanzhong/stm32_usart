# 适用于所有串口的初始化函数
*(使用的芯片为stm32f103zet6)*
******
**函数原型为：**  
`void usart_init(u32 BaudRate);`
* 参数BautRate为串口的波特率，32位长度
* 该函数无返回值

**例程代码：**
```
#include "usart.h"
#include "stdio.h"

int main()
{
    usart_init(115200);
    while (1)
    {
        printf("hello world！\r\n");
    }
    
}
```
> 该函数默认初始化**USART1**  
若要进行修改，可将**usart.h**文件里的宏定义  
**#define DEBUG_USART1**  
修改为:  
**#define DEBUG_USART2**  
或
**#define DEBUG_USART3**