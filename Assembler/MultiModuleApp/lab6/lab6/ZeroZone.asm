.586
.model flat
public @ZeroZone@8
.code
@ZeroZone@8 proc
		mov ebx, ecx
		mov ecx, edx
		xor eax,eax
		_repeat:
		    mov esi,0
		    cmp [ebx],esi
			je _zero
			jne _not_zero
		_zero:
		       inc eax
			mov esi, [ebx]
			add ebx, 4
			cmp esi, [ebx]
			je _next
			jne _the_end

		_next:
		    dec ecx
		    mov esi, [ebx]
			add ebx, 4
			cmp esi, [ebx]
			je _next
			jne _the_end
			
	    _not_zero:
		    add ebx,4
			loop _repeat
        
		_the_end:
			loop _repeat
			ret
@ZeroZone@8 endp

end