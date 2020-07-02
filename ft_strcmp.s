section .texte
global ft_strcmp

ft_strcmp:
         xor rcx, rcx           ; on met rcx a 0
         cmp rdi, 0             ; on verifie que rdi ne soit pas null
         jz _null               ; si rdi est null on va la fonction null
         cmp rsi, 0             ; on verifie que rsi ne soit pas null
         jz _null               ; si rsi est null on va la fonction null
         jmp _cmp               ; on va a la fonction cmp

_null:
        cmp rdi, rsi            ; on compare rdi et rsi pour voire si les deux sont null ou non
        jg _greater             ; si superieur on va la fonction greater (ret 1)
        jl _less                ; si inferieur on va a la fonction less  (ret -1)
        jmp _equal              ; si egal on fa la fonction equal (ret 0)

_cmp:
        cmp BYTE [rdi + rcx], 0         ; on compare si on est la fin de rdi
        jz _test_end                    ; si oui on va a la focntion test end
        cmp BYTE [rsi + rcx], 0         ; on compare si on est la fin de rsi
        jz _test_end                    ; si oui on va a la focntion test end
        mov dl, BYTE [rdi + rcx]        ; on met rdi + rcx dans dl pour pour pouvoir comparer
        cmp dl, BYTE [rsi + rcx]        ; on compare dl (= rdi + rcx) à [rsi + rcx]
        jg _greater                     ; si superieur on va la fonction greater (ret 1)
        jl _less                        ; si inferieur on va a la fonction less  (ret -1)

        inc rcx                         ; sinon c'est égal et on incrémente rcx
        jmp _cmp                        ; et on retourne au debut de la fonction

_test_end:
        mov dl, BYTE [rdi + rcx]        ; on met rdi + rcx dans dl pour pour pouvoir comparer
        cmp dl, BYTE [rsi + rcx]        ; on compare dl (= rdi + rcx) à [rsi + rcx] pour voir si les deux sont a la fin
        jg _greater                     ; si superieur on va la fonction greater (ret 1)
        jl _less                        ; si inferieur on va a la fonction less  (ret -1)
        jmp _equal                      ; si egal on fa la fonction equal (ret 0)


_greater:
        mov rax, 1                      ; met la valeur 1 dans rax
        ret                             ; retourne rax

_less:
        mov rax, -1                     ; met la valeur -1 dans rax
        ret                             ; retourne rax

_equal:
        mov rax, 0                      ; met la valeur 0 dans rax 
        ret                             ; retourne rax
