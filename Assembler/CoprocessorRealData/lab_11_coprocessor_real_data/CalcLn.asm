.586
.model flat
.data

one dq 1.0; dq-qword
two dq 2.0
four dq 4.0
result dq 0.0
sum dq 0.0
log dq 0.0
k dd 0; dd-dword


public _CalcLn@4

.code

_CalcLn@4 proc
push ebp
mov ebp,esp

mov ecx,[ebp+8]
		finit

		_cycle:
		mov k, ecx
			fld one
			fild k
			fild k
			fld four
			fmul; 4 * k
			fmul; 4k ^ 2
			fsubr; 4k ^ 2 - 1
			fld two
			fild k
			fmul; 2 * k
			fmul;2*k(4k ^ 2 - 1)
			fld one
			fdivr

			fstp result
			fld sum
			fld result
			fadd
			fstp sum
			loop _cycle

		fld one
		fld two
		fdiv
		fld sum
		fadd
		fstp log

		lea eax,log
		pop ebp
ret 4
_CalcLn@4 endp

end