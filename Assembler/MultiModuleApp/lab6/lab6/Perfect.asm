.586
.model flat
public _IsPerfect@4
.code

_IsPerfect@4 proc
       mov ebx,0; sum of digits in the number
		mov ecx,[esp+4] ;number
		dec ecx
		_repeat:
		mov eax,[esp+4]
		cdq
		div ecx
		cmp edx,0
		je _divider
		loop _repeat

		_divider:
		add ebx, ecx
		loop _repeat

		mov eax, [esp+4]
		cmp eax, ebx
		je _perfect_num
		jmp _not_perfect
		_perfect_num:
		mov eax,1
		jmp _end
		_not_perfect:
		mov eax,0
		_end:
ret 4
_IsPerfect@4 endp

end
