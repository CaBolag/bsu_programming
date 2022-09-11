.686
.model flat
public _DeleteDigits@4

.code
_DeleteDigits@4 proc
    mov eax, [esp+4]
	xor edi,edi; new number
	push eax
	mov ecx,1
	_begin :
	mov ebx, 10
		pop eax
		cmp eax, 0
		je _end
		cdq
		idiv ebx
		push eax
		cmp edx, 3
		jne not_3
		jmp _begin

		not_3 :
	    cmp edx, 6
		jne not_6
		jmp _begin

		not_6 :

		imul edx, ecx
		add edi, edx
		imul ecx, 10
		jmp _begin
		_end :
		mov eax,edi
		ret 4
_DeleteDigits@4 endp

end
