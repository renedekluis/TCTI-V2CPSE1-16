	.cpu cortex-m0
	.text
	.align 1
	.global print_asciz
	.global decompressor
	.global string
	.global decompress


	
	
decompressor:
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

   
   
decompress:
	push { r5, lr }
	ldr r0, =string
	mov r5, r0
	mov r4 ,#0
	
loop1:
	ldrb r0, [ r5 ]
	add r0, r0, #0
	beq done
	cmp r0, #'@'
	beq compressed_item
	bl   uart_put_char
	add  r5, r5, #1
	b    loop1	

compressed_item:
	
	add r5, r5, #1
	ldrb r0, [ r5 ]
	mov r6, r0
	
	add r5, r5, #1
	ldrb r0, [ r5 ]
	mov r7, r0
	
	sub r6, r6, #'0'
	sub r6,r6,r4
	sub r7, r7, #'0'
	
	mov r3, r7

	sub r5, r5, #2
	sub r5, r5, r6
	
	b loop2
	
loop2:
	ldrb r0, [r5]
	cmp r7,#0
	beq decompress_done
	bl	uart_put_char
	sub r7, r7, #1
	add r5, r5, #1
	b loop2
	
decompress_done:
	sub r3,r3,#3
	add r4, r4,r3
	sub r6,r6,r3
	add r5,r5,r6
	b loop1

done: 
   pop  { r5, pc }
   
 
