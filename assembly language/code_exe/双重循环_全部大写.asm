;编程：将datasg中每个单词改为大写字母
assume cs:code, ds.data
data segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
data ends

code segment
start:
    mov ax,data
    mov ds,ax
    mov bx,0  ;row

    mov cx,4 
    
a0: mov dx,cx ;save cx
    mov si,0  ;colomn
    mov cx,3
     
a:  mov al,[bx+si]
    and al,11011111b 
    mov [bx+si],al
    inc si
    
    loop a

    add si,16
    mov cx,dx ;release cx
    loop a0  
    
    mov ax,4c00h
    int 21h
        
code ends
end start