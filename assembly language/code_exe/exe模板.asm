; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here
            
    lea dx, pkey
    
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h      ;从键盘上输入一个字符，将其对应字符的ASCII码送入AL中，并在屏幕上显示该字符。如果按下的是Ctrl＋Break组合键，
    ;则终止程序执行。1号功能调用无须入口参数，出口参数在AL中。
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
