extern syscall_handler
section .text 
_syscall:
    mov qword [reg_rax],rax 
    mov qword [reg_rbx],rbx
    mov qword [reg_rdx],rdx
    mov qword [reg_rcx],rcx 
    call syscall_handler
    mov rax,qword [reg_rax]
    mov rbx,qword [reg_rbx]
    mov rdx,qword [reg_rdx]
    mov rcx,qword [reg_rcx]
    iret

section .data
reg_rax dq 0
reg_rdx dq 0
reg_rbx dq 0
reg_rcx dq 0


