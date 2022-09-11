.586
.model flat
public _FindZeroAmount@16
.code
_FindZeroAmount@16 proc
push ebp
mov ebp,esp
mov esi,dword ptr[ebp+8];matrix_adress
mov ecx,dword ptr[ebp+16]; columns
mov edi,dword ptr[ebp+20];result_matrix_adress
mov eax,4
imul ecx
mov edx,eax

_cycle:
xor ebx,ebx

push ecx
push esi
mov ecx,dword ptr[ebp+12];rows
_cycle_2:
cmp dword ptr[esi],0
je _equal
add esi,edx
loop _cycle_2
jmp _end

_equal:
inc ebx
add esi,edx
loop _cycle_2

_end:
mov dword ptr[edi],ebx
add edi,4
pop esi
mov eax,4
add esi,eax
pop ecx
loop _cycle
pop ebp
ret 16
_FindZeroAmount@16 endp
end