extern printf
extern scanf
global _start
section .text
_start:
    ; mov rdi, format
    ; mov rsi, number
    ; call scanf
    mov rdi, format
    mov rsi, number
    call printf
    mov eax, 1
    mov ebx, 0
    int 0x80
section .data
number:
dd 0
format:
db "%d", 0