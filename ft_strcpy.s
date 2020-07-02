section .text
global ft_strcpy

ft_strcpy:
            push rcx        ; on appelle rcx
            xor rcx, rcx    ; permet de mettre rcx a 0
            cmp rsi, 0      ; on verifie que src ne soit pas null
            jz _fin         ; si rsi (src) est null on finit

_copy:
            mov dl, BYTE [rsi + rcx]    ; on copie src dans dl
            mov BYTE [rdi + rcx], dl    ; on copie dl dans dest
            cmp dl, 0                   ; on verifie que l'on ne soit pas a la fin
            jz _fin                     ; si ont est a la fin on termine le programme

            inc rcx                     ; sinon on incremente rcx
            jmp _copy                   ; et on retourne au debut de la fonction

_fin:
            mov rax, rdi                ; ont met la destination dans rax pour être retourné
            pop rcx                     ; on restore rcx
            ret                         ; on retourne