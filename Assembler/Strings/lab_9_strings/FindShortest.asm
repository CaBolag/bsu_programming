.686
.model flat
public _FindShortest@8
.code
_FindShortest@8 proc
mov esi,[esp+4]
mov ecx,[esp+8]
mov ebx,0;cur length

mov dh,' '
_cycle:
cmp [esi], dh
je _space
inc esi
inc ebx
cmp ecx,1
je _space
loop _cycle
jmp _end

_space:
cmp ebx,eax
jl _less
inc esi
xor ebx,ebx
loop _cycle
jmp _end


_less:
mov eax,ebx
xor ebx,ebx
inc esi
loop _cycle

_end:

ret 8
_FindShortest@8 endp
end