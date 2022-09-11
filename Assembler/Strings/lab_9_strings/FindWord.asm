.586
.model flat
public _FindWord@16 
.code

_FindWord@16  proc


mov ecx,dword ptr [esp+8] ;str length
mov edi,[esp+12]; first word element
mov al,byte ptr[edi]
mov edi,dword ptr [esp+4]
_cycle:
cld
repne scasb ;поиск вхождения первого символа s2 в s1
jecxz _not ;подстрока не найдена

push edi
push ecx
mov ecx,[esp+24]
;dec ecx
mov esi,[esp+20]
inc esi
dec edi

cld
repe cmpsb
jecxz _found
;not_found
pop ecx
pop edi
jmp _cycle

_not:
mov eax,0
jmp _end

_found:
pop ecx
pop edi
mov ebx,[esp+8]
sub ebx,ecx
mov eax,ebx
_end:


ret 16
_FindWord@16 endp

end