// 求 0~9 的平方
    ORG 0000H
    LJMP A1 ; 跳过中断区域
    ORG 0080H
A1: NOP ; 等待外部接口加载
    NOP
    MOV SP, #60H ; 将栈指针放到合适的位置去
    MOV DPTR, #tab
    MOV A, #03H ; 将0-9之间的任意一个数赋给A
    MOVC A, @A+DPTR
    SJMP $ ; 阻塞
tab: DB 00h, 01h, 04h, 09h, 10h, 19h, 24h, 31h, 40h, 51h
     END
    