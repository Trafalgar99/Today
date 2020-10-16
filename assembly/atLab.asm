/*
    1. 数据移动指令
*/
...
/*
    2. 最大数
*/
    ORG 0000H
    MOV R2, {V} 
    MOV A, R0  
    MOV R1, A   
    DEC R2      
    MOV A, @R1  
LOOP: MOV R3, A 
    INC R1  
    CLR C   
    SUBB A, @R1 
    JNC LOOP1   
    MOV A, @R1  
    SJMP LOOP2
LOOP1: MOV A,R3 
LOOP2: DJNZ R2, LOOP    
    MOV @R0, A  
    END
/*
    3. 冒泡排序
*/
    ORG 0000H
SORT: MOV A, R0 ; 取首地址
    MOV R1, A
    MOV A, R2   ; 取字节数
    MOV R5, A   ; 字节数送入R5
    CLR F0  ; 用作记录一次循环中有没有发生交换
    DEC R5  ; 比较次数总比数据个数小一
    MOV A, @R1  ; 取第一个数

LOOP: MOV R3, A
    INC R1  ; 找第二个数
    CLR C
    MOV A, @R1  ; 将下一个数送入A
    SUBB A, R3
    JNC LOOP1   ; 后一个数大于前一个数 A>=R3
    SETB F0     ; 满足交换条件 
    MOV A, R3
    XCH A, @R1
    DEC R1
    XCH A, @R1
    INC R1

LOOP1: MOV A, @R1
    DJNZ R5, LOOP
    JB F0, SORT
    RET 
/*
    4. 定时
*/

/*
    5. 平方表
*/
    ORG 0000H
    LJMP A1 ; 跳过中断区域
    ORG 0080H
A1: NOP ; 等待外部接口加载
    NOP
    MOV SP, #60H ; 将栈指针放到合适的位置去
    MOV DPTR, #TAB
    MOV A, #03H ; 将0-9之间的任意一个数赋给A
    MOVC A, @A+DPTR
    SJMP $ ; 阻塞
TAB: DB 00h, 01h, 04h, 09h, 10h, 19h, 24h, 31h, 40h, 51h
     END
/*
    6. 二字节查表
*/