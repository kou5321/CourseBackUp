data segment
data ends

code segment  
    MSG DB " This is Lower case letters. $" 
    assume cs:code,ds:data
 p  proc far
    mov ax,data
    mov ds,ax   

    ;接受输入字符 al=输入字符
    mov ah,01h
    int 21h
    ;比较该字符
    cmp al,'a'
    jb input
    cmp al,'z'
    ja input

    ;可以sub al,20h (hex)
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
