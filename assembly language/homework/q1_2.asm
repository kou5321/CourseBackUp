                     .MODEL SMALL
.STACK 200H
.DATA
MAXP DB "MAX:$"
MINP DB "MIN:$"
NUM1 DW 123, 12666, 1, 8, 3, 38, 28, 83, 178, 12
.CODE
START:
MOV AX, @DATA
MOV DS, AX    ;移入数据段
LEA SI, NUM1  
MOV DI, 506H  ;显示屏的偏移地址
MOV CX, 10    ;数据段的10个数据，用作循环计数
CALL DISP     ;调用函数 ，显示
LEA SI, NUM1
MOV CX, 10    ;数据段的10个数据，用作循环计数
CALL SORT     ;数据段偏移地址
LEA SI, NUM1
MOV DI, 646H  ;显示屏的偏移地址
MOV CX, 2     ;显示两个数
CALL DISPMAX  ;调用函数
INT 21H


MOV AX, 4C00H ;结束程序
INT 21H
;-----------------------------------
SORT:
DEC CX
S0: PUSH CX
MOV DI, SI ;DI是此时显示屏的地址
S1: MOV AX, [DI]
CMP AX, [DI + 2]
JB S2
XCHG AX, [DI + 2]  ;大于则交换位置
MOV [DI], AX
S2: ADD DI, 2      ;小于则与下一个数字继续比较
LOOP S1
POP CX
LOOP S0
RET
;-----------------------------------
DISPMAX:
PUSH CX
CALL DTOC ;调用函数，在显示屏显示
ADD SI, 18
ADD DI, 18 ;指向下一个显示位置
POP CX
LOOP DISP
RET
;-----------------------------------
DISP:
PUSH CX   ;CX是10个数据的循环次数，之后会被用于数字位数覆盖，先储存
CALL DTOC ;调用函数，在显示屏显示
ADD SI, 2
ADD DI, 2 ;指向下一个显示位置
POP CX
LOOP DISP
RET
;-----------------------------------
DTOC:   ;显示数字
MOV AX, [SI]
MOV BX, 10
MOV CX, 0
D_LOOP1:
SUB DX, DX ;DX清零
DIV BX     ;除以10，dx存放余数，ax存放商
PUSH DX    ;余数放到栈中
INC CX     ;CX是数据的位数，同时是显示数据时的循环次数
CMP AX, 0  
JNZ D_LOOP1;如果商不为零那么继续除以10
;MOV AH, 2    
D_LOOP2:
POP DX
CALL SHOW_STR ;调用显示子程序
LOOP D_LOOP2
RET
;-----------------------------------
SHOW_STR: ;显示str
MOV BX, 0B800H ;0b800h是文本模式下显存起始地址
MOV ES, BX
ADD DX, 4A30H ;化为ASCII码
MOV ES:[DI], DX
ADD DI, 2     ;指向下一个显示位置
RET
;-----------------------------------
END START
