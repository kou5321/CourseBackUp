; multi-segment executable file template.
assume cs:code, ss:stack

stack segment
    dw   20  dup(0)
ends

code segment  
start:  
; set segment registers:
    mov si, 0  ;set ds:si point to the input letter

    mov ah, 1
    int 21h        ;input letter
    
    ;transfer to capital letter
    and al, 11011111b  
    ;ascll in lowercase minus 20h equals ascll in capital letter
    mov [si],al
    mov ah, 9      ;ouput letter
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
