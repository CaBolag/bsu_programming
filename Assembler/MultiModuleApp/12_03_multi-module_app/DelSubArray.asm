.586
.model flat
public _DelSubArray@16
.code
_DelSubArray@16 proc
push ebp
mov ebp, esp
mov eax, dword ptr [esp+8] ; первый массив arr
mov ebx, dword ptr [esp+12]; второй массив subArr
mov edx,[esp+16];size1
dec edx
mov ecx,[esp+20];size2
dec ecx
mov esi,0

;пробегаемся по первому массиву
compare_elem_1:
mov esi,0
push ecx
compare_elem_2:
mov ecx,[eax]
cmp ecx,dword ptr[ebx]
je equal
jne not_equal


equal:
inc esi
add ebx,4
;add eax,4
;cmp edx,esi
;jne compare_elem_2

not_equal:
add eax,4
pop ecx
cmp ecx,esi
push ecx

jne compare_elem_2
 mov ecx,esi
 imul ecx,4
sub ebx,ecx
sub eax,ecx
add eax,4
pop ecx
cmp esi,ecx
je the_end
jmp compare_elem_1
the_end:

fill_zeros:
mov dword ptr [eax],0
add eax,4
loop fill_zeros

ret 16
_DelSubArray@16 endp
end