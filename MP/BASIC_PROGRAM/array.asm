%macro print 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data 
array: dq 10,19,18,0xAA,-110
count: dq 05H
cnt: db  10H
colon db ": "
newline db 0xA

section .bss
result resq 1
section .text
global _start

_start:
	mov r9,array
ll:

	mov rax,r9
	call HtA
	print colon,1
	mov rax,qword[r9]
	call HtA
	print newline,1
	add r9,8
	dec byte[count]
	jnz ll

	mov rax,60
	mov rdi,60
	syscall
		
HtA:
      mov rsi,result
      mov byte[cnt],10H
label1:       rol rax,4
              mov bl,al
              and bl,0FH
              cmp bl,09H
              jbe label2
              add bl,07H

label2:	      add bl,30H
               mov byte[rsi],bl
               inc rsi
               dec byte[cnt]
               jnz label1
         	print result,16
          ret
      

