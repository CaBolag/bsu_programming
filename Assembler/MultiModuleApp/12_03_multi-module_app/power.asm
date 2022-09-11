.@.586
.model flat
;public _power@8;function declaration
public @power@8
.code
@power@8 proc
mov ebx,ecx
mov ecx,edx
mov eax,1
cycle:
imul eax,ebx
loop cycle
ret 
@power@8 endp



_power@8 proc
mov ecx,[esp+8]
mov eax,1
cycle:
imul eax,[esp+4]
loop cycle
ret 8
_power@8 endp

end