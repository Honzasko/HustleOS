section .text

GetCR3:
    enter 0,0
    mov rax,cr3
    leave 
    ret

SetCR3:
    enter 0,0
    mov cr3,rdi
    leave
    ret