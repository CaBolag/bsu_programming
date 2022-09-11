.586
.model flat
public _ReplaceNegative@8
.code
_ReplaceNegative@8 proc
mov esi,[esp+4]
mov ecx,[esp+8]
mov ebx,1000; max available element

_min:
cmp dword ptr[esi],ebx
jl _less
jmp _end_min

_less:
cmp dword ptr[esi],0
jg _replace_min
jmp _end_min
_replace_min:
mov ebx,dword ptr[esi]
jmp _end_min

_end_min:
add esi,4
loop _min

mov esi,[esp+4]
mov ecx,[esp+8]
_cycle:
cmp dword ptr[esi],0
jl _replace
add esi,4
loop _cycle
jmp _the_end

_replace:
mov edx,esi
mov [edx],ebx
add esi,4
loop _cycle
_the_end:

ret 8
_ReplaceNegative@8 endp
end