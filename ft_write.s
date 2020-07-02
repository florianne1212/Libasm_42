extern __errno_location
section .text
global ft_write

ft_write:
            mov	rax, 1      ; on met rax a 1 car c'est le nombre correspondant au syscall de write sur linux (0x2000004 sur os)
			syscall         ; system call
            cmp rax, 0      ; on verifie que rdi ne soit pas null
            jl _error       ; on passe a la fonction _error si inferieur a 0
			ret             ; sinon on retourne rax

_error:
            neg rax         ; permet de mettre en positif erreur -9 en 9
            mov rcx, rax    ; en appelant errno on recupere l'erreur correspondant a rax
            push rcx
            call __errno_location
            pop  rcx
            mov [rax], rcx
            mov rax, -1     ; on met rax a -1
            ret             ; on retourne rax