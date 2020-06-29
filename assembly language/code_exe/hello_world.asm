;hello,world!
DATA    SEGMENT
MESS    DB   'Hello,World!' ,0DH,0AH,24H
DATA    ENDS

STACK   SEGMENT PARA STACK 
        DW  256 DUP(?)    ;开辟出256个字单元空间
STACK   ENDS

CODE    SEGMENT
        ASSUME  CS:CODE,DS:DATA
BEGIN:  MOV AX,DATA
        MOV DS,AX
        MOV DX,OFFSET MdESS   ;
        MOV AH,9         ;显示字符串
        INT 21H          
        MOV AX,4C00H     ;调用中断21h的4ch号功能
        INT 21H
CODE    ENDS
        END  BEGIN