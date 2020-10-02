//sqrt子程序


MOV A, #03H
LJMP SQRT
// 此时A中即是结果

SQRT: PUSH DPH ; 保存DPH
      PUSH DPL ; 保存DPL
      MOV DPTR, #TAB1
      MOVC A, @A+DPTR
      POP DPL
      POP DPH
      RET
TAB1: DB 00H, 01H, 04H, 09H, 10H
      DB 19H, 24H, 31H, 40H, 51H