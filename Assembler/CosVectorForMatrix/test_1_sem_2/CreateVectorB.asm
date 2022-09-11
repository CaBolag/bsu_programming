.586
.model flat
public _CreateVectorB
.data
minone dd -1.0
abs dd ?
.code

_CreateVectorB proc
push ebp
mov ebp,esp
mov esi,dword ptr[ebp+8]; matrix_address
mov ecx,dword ptr[ebp+16]; columns
mov edi,dword ptr[ebp+20]; result_address


_cycle:
xor ebx,ebx ;sum of positive elements in column

mov eax,4
imul ecx
mov edx,eax
xor eax,eax ;sum of negative elements in column

push ecx
push esi
mov ecx,dword ptr[ebp+12]; amount of elements in column
_cycle_2:
cmp dword ptr[esi],0
jl _negative
;positive
add ebx,dword ptr[esi]
jmp _next_element

_negative:
add eax,dword ptr[esi]

_next_element:
add esi,edx
loop _cycle_2

_end:
add ebx,eax
cmp ebx,0
jg greater
mov dword ptr[edi],0
jmp next_

greater:
mov dword ptr[edi],1

next_:
add edi,4
pop esi
mov eax,4
add esi,eax
pop ecx
loop _cycle
pop ebp
ret
_CreateVectorB endp
end