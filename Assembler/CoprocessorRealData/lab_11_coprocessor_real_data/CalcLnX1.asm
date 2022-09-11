.586
.model flat
.data

one dd -1.0; dq-qword
x dd 0.0
;result dq 0.0
sum dq 0.0
k dd 0; dd-dword
size_ dd -1.0

public _CalcLnX1@8

.code

_CalcLnX1@8 proc

mov ecx,[esp+4]
mov ebx,dword ptr[esp+8]
mov x,ebx
finit

_cycle:
mov k,ecx


push ecx
; (-1)^k+1
mov ecx,k
_size:
fld one
fld size_
fmul
fstp size_
loop _size
pop ecx

;x^k/k
fild k
fild x
fyl2x
f2xm1
fld one
fsub
fild k
fdiv

fld size_
fmul

fld sum
fadd
fstp sum
mov ebx,one
mov size_,ebx
loop _cycle

lea eax,sum
ret 8
_CalcLnX1@8 endp

end