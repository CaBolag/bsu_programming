.586
.model flat
public @Replace@8
.code 

@Replace@8 proc
 	    mov esi, ecx
		mov ebx, ecx;max element
		mov ecx, edx
		dec ecx
		_repeat:
		    add esi, 4
			mov edx, [esi]
		    cmp edx,[ebx]
			jg _greater
			loop _repeat
			jmp _end
			
		_greater:
		    mov ebx,esi
			loop _repeat

			_end:

			mov ecx,dword ptr [esi]
			mov eax, dword ptr [ebx]
			mov dword ptr[esi],eax
			mov dword ptr[ebx],ecx
ret
@Replace@8 endp

end
