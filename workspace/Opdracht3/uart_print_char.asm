   .cpu cortex-m0
   .text
   .align 1
   .global print_asciz
   .global application
   .global convert_char

string: 
	.asciz " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ " 

	

application:
	push { lr }
	ldr r0, =string
	bl print_asciz
	pop { pc }

print_asciz:
   push { r5, lr }
   mov  r5, r0
   
loop: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  done
   bl   uart_put_char
   add  r5, r5, #1
   b    loop
   
done: 
   pop  { r5, pc }

	
	
	
convert_char:
	push { lr }
	mov r1, r0
	sub r1, r1, #'A' 
	blt else
	sub r1, r1, #26
	blt to_lowercase
	bgt else
	b return_c
	
	
else:
	mov r1, r0 
	sub r1, r1, #'a' 
	blt return_c
	sub r1, r1, #26
	blt to_uppercase
	bgt return_c
	b return_c

to_lowercase:
	sub r0, r0, #'A'
	add r0, r0, #'a'  
	b return_c 

to_uppercase:   
	sub r0, r0, #'a'
	add r0, r0, #'A' 
	b return_c

return_c:
	pop { pc }