.686
.model flat 
public _IsPrime@4
.code

_IsPrime@4 proc
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

		cmp ebx,1
		je _prime_num
	    jmp _not_prime_num
	    _prime_num:
	    mov eax,1
		jmp the_end
		_not_prime_num:
		mov eax,0
	    the_end:
ret 4
_IsPrime@4 endp
end
