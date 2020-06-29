data segment
        
    pmax db 0dh,0ah , 'MAX :   ','$'
    pmin db 0dh,0ah , 'MIN :   ','$'
    buf dw 48,-2 ,49,50,30,-78,-88,-60,-1,48
    max dw 99
    min dw 20
data ends

code segment
    assume cs:code , ds:data
    
main proc far
start:    
    mov ax,data
    mov ds,ax    
    
    call compare
    
    lea dx,pmax
    mov ah,09h
    int 21h    
    mov ax,max[0]
    call printit
    
    
    
    lea dx,pmin
    mov ah,09h
    int 21h
    mov ax,min[0]
    call printit

    
    mov ah,4ch
    int 21h
    ret
main endp
compare proc near
    mov si,0
    mov ax,buf[si]
    mov bx,ax
    mov dx,ax
    add si,2
    mov cl,9
comp:
    mov ax,buf[si]
    add si,2    
    cmp bx,ax
    jl movbx
    cmp ax,dx
    jl movdx    
    sub cl,1
    cmp cl,0
    jnz comp
    
    mov max[0],bx
    mov min[0],dx    
    ret
movbx:
    mov bx,ax
    sub cl,1
    jmp comp
movdx:
    mov dx,ax
    sub cl,1
    jmp comp
    
    

compare endp

printit proc near
    
    test ax,8000h
    jz p
    neg ax    
    mov cx,ax
    mov dx,2dh
    mov ah,2
    int 21h
    mov ax,cx
    mov dx,0
p:    mov bx ,10
    div bx
    mov bx,dx
    mov dx,ax
    add dx,30h
    mov ah,02h
    int 21h
    mov dx,bx
    add dx,30h
    mov ah,02h
    int 21h
    ret
printit endp

code ends
    end main