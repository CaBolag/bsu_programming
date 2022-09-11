.586
.model flat
public _PowerFunction@8
public _FindRoots@16

.DATA 
ONE Dq 1.0
two dq 2.0
a dq ?
b dq ?
c_ dq ?
x_1 dq ?
x_2 dd ?
power dq ?
discr dq ?
.code


_PowerFunction@8 proc
FINIT
FLD dword ptr[esp+8]
FLD dword ptr[esp+4]
FYL2X
FLD ONE
FSCALE
FSTP power
lea eax, power
RET 8
_PowerFunction@8 endp



_FindRoots@16 proc
FINIT
fild dword ptr[esp+4]
fild dword ptr[esp+8]
fild dword ptr[esp+12]
fstp c_
fstp b
fstp a


;discr=b^2-4ac
fld a
fld b
fld c_
fmul st, st(2)
fild two
fmul st, st ;4
fmul st, st(1)
fld b
fmul st, st
fsub st, st(1)
fst discr

fsqrt
fld a
fadd st, st(0)
fld b
fchs
fadd st, st(2)
fdiv st, st(1)
fstp x_1
fld st(3)
fchs
fsub st, st(2)
fdiv st, st(1)
fstp x_2

lea eax,x_1
mov ebx,x_2
mov dword ptr[esp+16],ebx
RET 16
_FindRoots@16 endp
end