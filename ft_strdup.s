section .text
global ft_strdup
extern malloc

ft_strdup:
            cmp rdi, 0         ; on verifie que rdi ne soit pas null
            jz _error          ; si ca l'est on termine et on retourne 0
            xor rcx, rcx       ; ont met rcx a 0

_len:
            cmp BYTE [rdi + rcx], 0         ; on compare rdi + rcx a 0 pour savoir si on est a la fin
            jz _malloc_space                ; si oui on va a la fonction malloc space
            inc rcx                         ; si non on augmente rcx pour compter la taille de rdi
            jmp _len                        ; et on recommence jusqu'a la fin

_malloc_space:
            inc rcx                         ; on augmente rcx de 1 pour le /0
            push rdi                        
            mov rdi, rcx                    ; on met la longueur de la chaine dans rdi
            call malloc                     ; on appelle malloc
            pop rdi
            cmp rax, 0                      ; rax est le resultat de malloc on verifie que ca ne soit pas null
            jz _error                       ; si ca l'est on termine et on retourne 0
            xor rcx, rcx                    ; on met rcx a 0

_copy:
        mov dl, BYTE [rdi + rcx]            ; ont fait une copie en mettant rdi+rcx dans dl
        mov BYTE [rax + rcx], dl            ; puis dl dans rax = l'espace mallocé
        cmp dl, 0                           ; on verifie si ont est a la fin
        jz _fin                             ; si oui on va a _fin
        
        inc rcx                             ; si non on augmente rcx pour parcourir la chaine
        jmp _copy                           ; et on recommence jusqu'a la fin

_fin:
        ret                                 ; on retourne rax soit la copie de rdi

_error:     
        mov rax, rax                        ; ont met rax a 0
        ret                                 ; on retourne rax
