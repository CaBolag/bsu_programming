.586
.model flat
.data

.data
two dq 2.0
five dq 5.0
twopi dq 6.283
h dq 0.0
sum dq 0.0
a dq 0.0
b dq 0.0
fa dq 0.0
fb dq 0.0
k dd 0

public _IntegralA@4

.code

_IntegralA@4 proc
push ebp
mov ebp,esp
mov ecx,[ebp+8]
		finit
		mov k,ecx
		fild k
		fld twopi
		fld a
		fsub
		fdivr
		fstp h
		dec ecx

		fld a ;calc f(a)
		fld a
		fmul
		fsin
		fld five
		fld a
		fmul
		fadd
		fstp fa

		fld twopi ;calc f(b)
		fld twopi
		fmul
		fsin
		fld five
		fld twopi
		fmul
		fadd
		fstp fb

		fld fa; (f(a)+f(b))/2
		fld fb
		fadd
		fld two
		fdiv
		fstp sum

		_cycle:
		fld a ;a+=h
		fld h
		fadd
		fstp a

		fld a ;calc f(a)
		fld a
		fmul
		fsin
		fld five
		fld a
		fmul
		fadd
		
		;fstp fa
		;fld fa
		fld sum 
		fadd
		fstp sum
		loop _cycle

		fld h
		fld sum
		fmul
		fstp sum

		lea eax,sum
		pop ebp
ret 4
_IntegralA@4 endp

end
