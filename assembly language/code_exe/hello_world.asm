;hello,world!
DATA    SEGMENT
MESS    DB   'Hello,World!' ,0DH,0AH,24H
DATA    ENDS

STACK   SEGMENT PARA STACK 
        DW  256 DUP(?)    ;���ٳ�256���ֵ�Ԫ�ռ�
STACK   ENDS

CODE    SEGMENT
        ASSUME  CS:CODE,DS:DATA
BEGIN:  MOV AX,DATA
        MOV DS,AX
        MOV DX,OFFSET MdESS   ;
        MOV AH,9         ;��ʾ�ַ���
        INT 21H          
        MOV AX,4C00H     ;�����ж�21h��4ch�Ź���
        INT 21H
CODE    ENDS
        END  BEGIN