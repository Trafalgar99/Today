// 从50个字节的无序表中查找一个关键字××”H。 
    ORG 1000H
    MOV 30H, #xxH
    MOV R1, #50
    MOV A, #0
    MOV DPTR, #TAB4
LOOP: PUSH ACC
LOOP2: MOVC A, @A+DPTR
    CJNE A, 30H, LOOP1

    MOV R2, DPH
    MOV R3, DPL

LOOP3: RET
LOOP1: INC DPTR
        CLR ACC
        DJNZ R1, LOOP2

        MOV R2, #00H
        MOV R3, #00H
        AJMP LOOP3
TAB4: DB ... ... ... ...