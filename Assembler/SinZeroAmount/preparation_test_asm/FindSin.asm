.586
.model flat
.data
one dq -1.0
two dq 2.0
sum dq 0.0
x dd 0.0
size_ dq -1.0
n dd 0.0
fact_n dd 0.0; 2n-1
fact dd 0.0

public _FindSin@8
.code

_FindSin@8 proc
mov ecx,[esp+4]
mov n,ecx

finit
;2n-1
fld two
fild n
fmul
fld one
fadd
fistp fact_n
push fact_n


;(2n-1)!
mov fact,1
mov ecx,fact_n
dec ecx
_fact:
fild fact_n
fild fact
fmul
fistp fact
;n-1
fild fact_n
fld one
fadd
fistp fact_n
loop _fact

pop fact_n


mov ecx,n
_cycle:
mov n,ecx
mov ebx,dword ptr[esp+8]
fld dword ptr[ebx]
fstp x
push ecx

; (-1)^n-1
mov ecx,n
dec ecx
dec ecx
_size:
fld one
fld size_
fmul
fstp size_
loop _size

;x^(2n-1)
fild fact_n
fld x
FYL2X
FLD1
FSCALE
;F2XM1
;FLD ONE
;fsub

fld size_
fild fact
fdiv
fmul

fld sum
fadd
fstp sum



fild fact
fild n
fdiv
fist fact

fild fact_n
fld one
fadd
fstp fact_n
pop ecx
loop _cycle

lea eax,sum
ret 8
_FindSin@8 endp

end