	ORG 0000H
    MOV B, #10H     ;����
    MOV R0, #7AH
    MOV R1, #7BH
	MOV A, #81H

    MOV R2, A  ; ����
    MOV A, #00H
    MOVX @R0, A
    MOVX @R1, A
    MOV A, R2


    DIV AB ; ȡλ
    MOVX @R1, A
    MOV A, B
    MOVX @R0, A
	MOVX A, @R0
	MOVX A, @R1
    END