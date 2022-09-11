.686
.model flat
public @CalcSin@8
.data
msx dd 1.0
sum dq 0.0
helpfact dd 0.0
helpfact1 dd 0.0
fact dd 1.0
minone dd -1.0
two dd 2.0
x dd 1.0
dr dd ?
.code
@CalcSin@8 proc
dec ecx

finit
fld qword ptr[edx]
fst sum
fst x
fld qword ptr[edx]
fmul
fld minone
fmul
fstp msx

_cycle:
fld helpfact
fld two
fadd
fst helpfact

fld1
fadd
fst helpfact1
fld helpfact
fmul
fld fact
fmul
fstp fact

fld x
fld msx
fmul
fst x
fld fact
fdiv
fst dr
fld sum
fadd
fstp sum
loop _cycle

lea eax,sum
ret
@CalcSin@8 endp
end