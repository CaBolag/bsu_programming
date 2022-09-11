.586
.model flat
public _MaxSeq@12

.code
_MaxSeq@12 proc
mov ecx,[esp+8] ;array size
mov esi,[esp+4] ;array
xor edi,edi ;sum of max sequance
xor edx,edx ;sum of cur sequance
xor ebx,ebx ;cur sequance size
xor eax,eax ;start of sequance

cycle:
cmp dword ptr[esi],0
push ecx
mov ecx,dword ptr[esi]
pop ecx
jl _negative
add edx,[esi]
inc ebx
cmp ecx,1
je _array_end
jmp _end

_array_end:
cmp edx,edi
jg _greater
jmp _end


_negative:
cmp edx,edi
jg _greater
mov ebx,0
mov edx,0
jmp _end


_greater:

; find the start of the sequance
mov eax,[esp+8]
sub eax,ecx

;put in a seq_size the value
push ecx
mov ecx,[esp+16]
mov [ecx],ebx
pop ecx
mov edi,edx

mov ebx,0
mov edx,0
jmp _end


_end:
add esi,4
loop cycle
ret 12
_MaxSeq@12 endp
end