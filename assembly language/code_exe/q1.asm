data segment
data ends

code segment  
    MSG DB " This is Lower case letters. $" 
    assume cs:code,ds:data
 p  proc far
    mov ax,data
    mov ds,ax   

    ;���������ַ� al=�����ַ�
    mov ah,01h
    int 21h
    ;�Ƚϸ��ַ�
    cmp al,'a'
    jb input
    cmp al,'z'
    ja input

    ;����sub al,20h (hex)
    sub al,32   

input : 
    xchg dl,al
    mov ah,02h
    int 21h

    mov ah,4ch
    int 21h

    p endp
    code ends
    end p
