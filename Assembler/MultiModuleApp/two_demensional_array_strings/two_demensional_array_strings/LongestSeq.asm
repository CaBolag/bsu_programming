.586
.model flat
public _LongestSeq@8

.code

_LongestSeq@8 proc
mov esi, [esp+4]
mov ah,[esi]; current char
mov cl,1; current length
mov bh,0; max index
mov ch,0; max length
inc esi
mov al,[esi]; next char
mov bl,1; current index

curcle:
   cmp ah,al
   jne _not_equal
   ; if equal
   inc cl
jmp check_end
_not_equal:
    cmp cl,ch; compare cur and max length
    jg _new_max
    jmp check_end

    _new_max:
    mov ch,cl
    mov bh,bl
    mov cl,1
    jmp check_end

    check_end:
    inc bl
    mov ah,[esi]; renew cur char
    inc esi
    mov al,[esi];renew next char
    cmp al,0
    jne curcle
    
    xor eax,eax
    mov al,bh
    sub al,ch
    mov edx,[esp+8]
    mov [edx],ch


ret 8
_LongestSeq@8 endp

end