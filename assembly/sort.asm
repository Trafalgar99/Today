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