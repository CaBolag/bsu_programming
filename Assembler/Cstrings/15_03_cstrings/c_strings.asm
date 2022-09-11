.686
.model flat
public @FindLength@4
public _FindPositionOnRight@8
public _FindPositionOnRight@8
public _FindSubstring@16
.code

@FindLength@4 proc
xor eax, eax
_length:
inc eax
cmp byte ptr [ecx+eax],0
jne _length
ret
@FindLength@4 endp



_FindPositionOnLeft@8 proc
;find length
xor eax, eax
mov ebx,dword ptr[esp+4]
_length:
inc eax
cmp byte ptr [ebx+eax],0
jne _length

;find position
mov ecx,eax
mov al,byte ptr [esp+8]
mov edi,dword ptr[esp+4]
cld
repne scasb
jecxz _not_found
mov eax,ecx
jmp _end
_not_found:
mov eax,-1
_end:

ret 8
_FindPositionOnLeft@8 endp



_FindPositionOnRight@8 proc
xor eax, eax
mov ebx,dword ptr[esp+4]
_length:
inc eax
cmp byte ptr [ebx+eax],0
jne _length

mov ecx,eax
mov esi,dword ptr[esp+4]
add esi,eax
mov al,byte ptr [esp+8]
std
repne scasb
jecxz _not_found
mov eax,ecx
jmp _end
_not_found:
mov eax,-1
_end:

ret 8
_FindPositionOnRight@8 endp


_FindSubstring@16 proc
cld
mov ecx,[esp+12]
mov ebx,[esp+8]
mov esi,[esp+4]
add esi,ebx
mov edi,dword ptr[esp+16]
rep movsb

ret 16
_FindSubstring@16 endp
end