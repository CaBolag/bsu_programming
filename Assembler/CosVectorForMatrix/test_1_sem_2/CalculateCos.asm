.686
.model flat
public @CalculateCos@8

.data
x dq ?
new_x dq ?
msx dd 1.0
sum dq 0.0
helpfact1 dd -1.0
helpfact2 dd 0.0
fact dd 1.0
minone dd -1.0
two dd 2.0
four dd 4.0
dr dd ?
result dd ?

.code
@CalculateCos@8 proc
dec ecx
fldpi
fld four
fdiv 
fstp x

finit
fld1
fstp sum
fld x
fld x
fmul
fld minone
fmul
fstp msx
fld1
fstp new_x

_cycle:
fld helpfact1
fld two
fadd
fst helpfact1

fld1
fadd
fst helpfact2
fld helpfact1
fmul
fld fact
fmul
fstp fact

fld new_x
fld msx
fmul
fst new_x
fld fact
fdiv
fst dr
fld sum
fadd
fstp sum
loop _cycle

fld sum
fld x
fcos
fsub
fstp dword ptr[edx]

;fld sum
;fstp result
;mov eax,result
lea eax,sum
ret
@CalculateCos@8 endp
end