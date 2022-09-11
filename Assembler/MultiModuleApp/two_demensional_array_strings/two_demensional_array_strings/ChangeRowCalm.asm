.586
.model flat
public _ChangeRowCalm@12

.code

_ChangeRowCalm@12 proc
push ebp
mov ebp,esp
xor ecx,ecx
	cycle:
		mov eax, [ebp+12]
			imul ecx
			add eax, [ebp+16]
			mov edi, eax; index in colmn

			mov ebx, [ebp+16]
			mov eax, [ebp+12]
			imul ebx
			add eax, ecx
			mov esi, eax; index in row

			mov edx, [ebp+8]

			mov eax, [edx][esi * 4]
			mov ebx, [edx][edi * 4]
			mov[edx][esi * 4], ebx; swap
			mov[edx][edi * 4],eax
			
			inc ecx
			mov eax,[ebp+12]
			cmp ecx,eax
			jl cycle
			pop ebp
			ret 12
_ChangeRowCalm@12 endp
end