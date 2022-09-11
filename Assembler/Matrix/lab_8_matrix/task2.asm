.586
.model flat
public _FindRow@12
.code
_FindRow@12 proc
mov ecx,[esp+8]
mov eax,0; row with max amount of 1
mov edx,0; max amount of 1
xor ebx,ebx
mov edi,[esp+4]

_cycle:
push ecx
mov ecx,[esp+16]


_row:
cmp dword ptr[edi],1
je _equal1
inc edi
loop _row
jmp _end
_equal1:
inc ebx
inc edi
loop _row
_end:

cmp ebx,edx
jg _greater
jmp _end_row
_greater:
pop ecx
mov edx,ebx
mov eax,[esp+8]
sub eax,ecx
inc eax
xor ebx,ebx
loop _cycle


_end_row:
pop ecx
xor ebx,ebx
loop _cycle
ret 12
_FindRow@12 endp
end