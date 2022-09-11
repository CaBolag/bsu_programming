.586
.model flat
public _FindLocalMax@12
.code

_FindLocalMax@12 proc
mov ecx, dword ptr[esp+8]
sub ecx,2

mov esi,[esp+4]
mov edi,[esp+12]; local maxs
mov ebx,dword ptr[esp+4]
add ebx,4;  next element
mov edx,[esp+4]; previous element
cmp ebx,dword ptr[esi]
jl first_max
jmp _cycle

first_max:
mov dword ptr[edi],ebx


_cycle:
mov edx,dword ptr[esi]
add esi,4; cur element
mov ebx,esi
inc ebx
cmp dword ptr[esi],edx
jg _greater1
loop _cycle
_greater1:
cmp dword ptr[esi],ebx
jg _greater2
loop _cycle
_greater2:
inc edi
mov dword ptr[edi],ebx
loop _cycle

;last element
mov edx,dword ptr[esi]
add esi,4
cmp dword ptr[esi],edx
jg _last_greater
jmp _end
_last_greater:
inc edi
mov dword ptr[edi],ebx

_end:
ret 12
_FindLocalMax@12 endp

end