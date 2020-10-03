    MOV R2, n //n是数据的数量，决定了比较次数
    MOV A, R0   //R0存放数据区的首地址
    MOV R1, A   //通过A将R0的值送到R1,R1存放下一个数据的地址
    DEC R2      // 比较次数总比数据数量少一
    MOV A, @R1  // 取出第一个数给A
LOOP: MOV R3, A //A总存放当前最大的数 ，但是在比较时会改变A的值，所以用R3做备份，初始时是第一个数
    INC R1  //R1移到下一个数
    CLR C   //要用到subb必须先将C清零
    SUBB A, @R1 //做差比较，但是此时A已经被改变
    JNC LOOP1   // 如果C不为1，则A大，跳转到LOOP1
    MOV A, @R1  // 如果上一步没有跳转，则A小，将大的数复制给A
    SJMP LOOP2
LOOP1: MOV A,R3 //此时是A大，但是A值被SUBB改变，需要先恢复A的原始值
LOOP2: DJNZ R2, LOOP    //判断是否已经达到比较次数（先减一，再判断），不是0再跳回LOOP继续比较
    MOV @R0, A  //比较已经结束 将最大的数放到R0里
    END