                     .MODEL SMALL
.STACK 200H
.DATA
MAXP DB "MAX:$"
MINP DB "MIN:$"
NUM1 DW 123, 12666, 1, 8, 3, 38, 28, 83, 178, 12
.CODE
START:
MOV AX, @DATA
MOV DS, AX    ;�������ݶ�
LEA SI, NUM1  
MOV DI, 506H  ;��ʾ����ƫ�Ƶ�ַ
MOV CX, 10    ;���ݶε�10�����ݣ�����ѭ������
CALL DISP     ;���ú��� ����ʾ
LEA SI, NUM1
MOV CX, 10    ;���ݶε�10�����ݣ�����ѭ������
CALL SORT     ;���ݶ�ƫ�Ƶ�ַ
LEA SI, NUM1
MOV DI, 646H  ;��ʾ����ƫ�Ƶ�ַ
MOV CX, 2     ;��ʾ������
CALL DISPMAX  ;���ú���
INT 21H


MOV AX, 4C00H ;��������
INT 21H
;-----------------------------------
SORT:
DEC CX
S0: PUSH CX
MOV DI, SI ;DI�Ǵ�ʱ��ʾ���ĵ�ַ
S1: MOV AX, [DI]
CMP AX, [DI + 2]
JB S2
XCHG AX, [DI + 2]  ;�����򽻻�λ��
MOV [DI], AX
S2: ADD DI, 2      ;С��������һ�����ּ����Ƚ�
LOOP S1
POP CX
LOOP S0
RET
;-----------------------------------
DISPMAX:
PUSH CX
CALL DTOC ;���ú���������ʾ����ʾ
ADD SI, 18
ADD DI, 18 ;ָ����һ����ʾλ��
POP CX
LOOP DISP
RET
;-----------------------------------
DISP:
PUSH CX   ;CX��10�����ݵ�ѭ��������֮��ᱻ��������λ�����ǣ��ȴ���
CALL DTOC ;���ú���������ʾ����ʾ
ADD SI, 2
ADD DI, 2 ;ָ����һ����ʾλ��
POP CX
LOOP DISP
RET
;-----------------------------------
DTOC:   ;��ʾ����
MOV AX, [SI]
MOV BX, 10
MOV CX, 0
D_LOOP1:
SUB DX, DX ;DX����
DIV BX     ;����10��dx���������ax�����
PUSH DX    ;�����ŵ�ջ��
INC CX     ;CX�����ݵ�λ����ͬʱ����ʾ����ʱ��ѭ������
CMP AX, 0  
JNZ D_LOOP1;����̲�Ϊ����ô��������10
;MOV AH, 2    
D_LOOP2:
POP DX
CALL SHOW_STR ;������ʾ�ӳ���
LOOP D_LOOP2
RET
;-----------------------------------
SHOW_STR: ;��ʾstr
MOV BX, 0B800H ;0b800h���ı�ģʽ���Դ���ʼ��ַ
MOV ES, BX
ADD DX, 4A30H ;��ΪASCII��
MOV ES:[DI], DX
ADD DI, 2     ;ָ����һ����ʾλ��
RET
;-----------------------------------
END START
