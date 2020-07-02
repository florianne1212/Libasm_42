global ft_strlen
section .text

ft_strlen:
    push rcx      ; on appelle rcx
    xor rcx, rcx  ; permet de mettre rcx a 0

_count:       
    cmp BYTE [rdi], 0 ; on compare si c'es égal a 0
    jz _fin           ; si oui on va a la fin

    inc rcx           ; si non on incremente rcx pour compter
    inc rdi           ; et on incremente rdi poucontinuer a comparer
    jmp _count        ; et on retourne au debut de la fonction

_fin:        
    mov rax, rcx      ; ont met la valeur de rcx dans rax pour retourner la valeur
    pop rcx           ; on restore rcx
    ret               ; on retourne