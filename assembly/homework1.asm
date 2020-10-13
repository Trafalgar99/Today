/*
编写程序将内RAM30H开始的10个数转移到外RAM2000H开始的单元中去。
*/

    ORG 0000H
    MOV R0, #30H
    MOV R1, #10
    MOV DPTR, #2000H

LOOP: MOV A, @R0
    MOVX @DPTR, A
    INC DPTR
    INC R0

    DJNZ R1, LOOP
    END

/*
编写程序找出内RAM40H开始的10个数的最大数，并将这个数存入50H单元中。
*/
    MOV R0, #40H
    MOV R1, #10
    DEC R1
    MOV A, @R0

LOOP2:  INC R0
    CLR C
    PUSH ACC
    SUBB A, @R0
    POP ACC
    JNC LOOP1
    XCH A, @R0

LOOP1: DJNZ R1, LOOP2
    MOV 50H, A
    END

/*
1.试编写程序，将内部RAM20H~80H单元的数据传送到外部以3000H为首址的存储区。
*/
    ORG 0000H
    MOV R0, #20H
    MOV DPTR, #3000H

LOOP: MOV A, @R0
    MOVX @DPTR, A
    INC R0
    INC DPTR
    CJNE R0, #80H, 
    
    MOV A, @R0  ; 如果#80H也被包括，则加上这两句
    MOVX @DPTR, A
    
    END

/*
2.试编写程序，将ROM从2000H单元开始存放的100个数据按序传送到外部RAM00H开始的单元中。
*/
    ORG 0000H
    MOV DPTR, #2000H
    MOV R0, #00H
    MOV R1, #100
LOOP: MOVC A, @A+DPTR
    MOVX @R0, A
    INC R0
    INC DPTR
    DJNZ R1, LOOP
    END
/*
3.从内部RAM40H单元开始存有20个带符号数，把正数传送到外部RAM4000H开始的单元，
负数传送到外部RAM4050H开始的单元，零不传送。
*/
    ORG 0000H
    MOV SP, #60H
    MOV P2, #40H
    MOV B,  #00H
    PUSH B  ; 保存pos地址
    MOV R0, #40H
    MOV R1, #50H
    MOV R2, #20
                ; R0->内RAM地址，POS地址； R1->NEG地址； R2->次数

MAIN: MOV A, @R0
    INC R0
    CLR C
    CJNE A, #0, LOOP
    LJMP CMP
LOOP: JC NEG
POS: POP B     ;B临时保存一下pos时的目标地址
    PUSH R0     ; 保存内RAM值
    LCALL B2R0
    MOVX @R0, A
    INC RO
    POP B  ; 拿出内RAM地址
    PUSH R0   ; 保存 pos地址
    LCALL B2R0
    DJNZ R2, MAIN
    LJMP STOP
NEG: MOVX @R1, A
    INC R1
CMP: DJNZ R2, MAIN
STOP:SJMP STOP
B2R0: PUSH ACC      ;通过A将B送入R0，A的值有效，要保存
    MOV A, B
    MOV R0, A
    POP ACC
    RET


/*
4.将片内RAM30H~60H单元的数据块全部搬迁到片外RAM1000H~1030H区域，并
将原数据区全部清零。
*/
    ORG 0000H
    MOV DPTR, #1000H
    MOV R0, #30H
    MOV R2, #30

LOOP: MOV A, @R0
    MOVX @DPTR, A 
    MOV @R0, #00H
    INC R0
    INC DPTR

    DJNZ R2, LOOP
    END
/*
5.外部RAM中有一数据块，存有若干字符数据，首址为SOUCE(8位）。要求将该数
据块传送到内部RAM从DIST开始的区域，直到遇到字符“$”时为止。
*/
    SOUCE EQU XXH
    DIST EQU YYH
    ORG 0000H
    MOV P2, #00H
    MOV R0, #SOUCE
    MOV R1, #DIST

MAIN: MOVX A, @R0
    INC R0
    CJNE A, #24H, LOOP 
    SJMP STOP
LOOP: MOV @R1, A
    INC R1
    SJMP MAIN
STOP: SJMP STOP
/*
6.设有100个无符号数，连续存放在以2000H为首地址的存储区中，试统计奇数与偶
数的个数。
*/
    ORG 0000H
    MOV DPTR, #2000H
    MOV R2, #100
    MOV R3, #0 ;ODD
    MOV R4, #0  ;EVEN

LOOP: MOVX A, @DPTR
    INC DPTR
    RRC A ;
    JC ODD
    INC R4
    LJMP JUDGE
ODD: INC R3
JUDGE: DJNZ R2 LOOP
    END
/*
7.统计P1口输入的数串中正数、负数和零的个数。
*/
    ORG 0000H
    MOV R3, #0  ;+
    MOV R4, #0  ;0
    MOV R5, #0  ;-

MAIN: MOV A, P1
    CLR C
    CJNE A, #0, JUD
    INC R4
    LJMP TRANS
JUD: JC NEG
    INC R3
    LJMP TRANS
NEG: INC R5
TRANS: LJMP MAIN

/*
8.试编写程序，统计内部RAM的20H~50H单元中出现00H的次数，并将统计结果存
入51H单元。
*/
    ORG 0000H
    MOV R0, #20H
    MOV R2, #30
    MOV R3, #0
    
LOOP: MOV A, @R0
    INC R0
    CJNE A, #00H, CMP
    INC R3
CMP: DJNZ R2, LOOP
    MOV 51H, R3
    END

/*
9.试编写若累加器A内容分别满足以下条件则程序转到LABEL处的程序。
(1)A≥10。
(2)A≤10。
(3)A>10。
(4)A<10。
*/

/*
10.若在ROM中2000H单元开始存有一数据表，每一数据占有二个单元，共有127个
数据。要求按存于片内RAM30H单元中的给定数据（00H~7FH)查表，并将结果存入片内RAM40H、41H单元。
*/
    ORG 0000H
    MOV DPTR, #2000H
    MOV R0, #30H
    MOV SP #60H

    MOV A, @R0
    RL A
    PUSH ACC
    MOVC A, @A+DPTR
    MOV 40H, A
    INC DPTR
    POP ACC
    MOVC A, @A+DPTR
    MOV 41H, A
    END

/*
11.试编写程序，将累加器A中的低4位送外部RAM7AH单元，将累加器A中的高4
位送外部RAM7BH单元，7AH、7BH单元高4位均清0。/每隔1s读一次P1.0,如果所读的
状态为“1”，内部RAM10H单元加1,如果所读的状态为“0”，内部RAM11H单元加1.
采用软件方法实现定时。
*/
    ORG 0000H
    MOV B, #10H     ;基数
    MOV R0, #7AH
    MOV R1, #7BH
    MOV SP, #60H

    PUSH ACC  ; 清零
    MOV A, #00H
    MOVX @R0, A
    MOVX @R1, A
    POP ACC

    DIV A B ; 取位
    MOVX @R1, A
    MOV A, B
    MOVX @R0, A
    END
--------------------------------------------------------------------------------
    ORG 0000H
    MOV R0, #10H
    MOV R1, #11H
    MOV SP, #60H

SEC: LCALL DEL
    MOV C, P1.0
    JC TAG1
    INC @R1
    SJMP SEC
TAG1: INC @R0
TRANS: LJMP SEC

DEL: MOV R7, #20
DEL3: MOV R6, #200
DEL2: MOV R5, #125
DEL1: DJNZ R5, DEL1
    DJNZ R6, DEL2
    DJNZ R7, DEL3
    RET

/*
12.试编写程序，将两双字节压缩的BCD码数相加，两待加数分别按先低后高原则分别
存放在30H、31H和40H、41H单元，和放回30H、31H单元。
*/




------------------------------------------------------------------------------------
> AUTHOR: WKD
> OPTIMIZATION: 10.10
    > DESCRIBE: 修改了部分错误，对某些程序进行了优化