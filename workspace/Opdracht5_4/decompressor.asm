	.cpu cortex-m0
	.text
	.align 1
	.global print_asciz
	.global decompressor
	.global string
	.global decompress
	.global make_string

	
	
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
	
	add r5, r5, #1 			// Verhoog de pointer index in de string naar de offset
	ldrb r0, [ r5 ]			// Haal het offset character op
	mov r6, r0 				// Store de offset in r6
	
	add r5, r5, #1			// Verhoog de pointer index in de string naar de size
	ldrb r0, [ r5 ]			// Haal het size character op
	mov r7, r0				// Store de size in r7
	
	sub r6, r6, #'0'		// Haal '0' van de offset af om de waarde te krijgen
	add r6,r6,#1
	sub r7, r7, #'0'		// Haal '0' van de size af om de waarde te krijgen
	
	mov r3, r4
	sub r3, r3, r6
	
	
	
	//sub r5, r5, #2
	//sub r5, r5, r6
	
	b loop2
	
loop2:
	cmp r7, #0
	beq decompress_done
	ldrb r0, [r3]
	strb r0, [r4]
	sub r7, r7, #1
	add r3, r3, #1
	add r4, r4, #1
	b loop2
	
decompress_done:
	add r5, r5, #1
	b filling

done: 
   pop  { r5, pc }
   



//   ########################################################################################
//  ## Test met de string naar storage schrijven en vervolgens de storage weer uitprinten ##
// ########################################################################################



	.bss					// Buffer moet opgeslagen worden in .bss (of .data)
mybuffer:					
	.skip 3600				// Maak de buffer aan met gedefinieerde grootte
	
	
	.text					// Ga weer terug naar .text stuk, om code te schrijven
	.align 1				// Align de string? (vergeten wat dit precies deed)

make_string:				// Functie call voor lezen van een string naar storage en vanaf de storage weer uitprinten
	push { r5, lr }
	ldr r0, =string  		// string is de input
	mov r5, r0				// r5 is alijd de pointer naar het begin 
	ldr r4, =mybuffer		// r3 de positie in het buffer
filling:
	ldrb r0, [ r5 ]			// Laad index r5 uit de string in r0
	add r0, r0, #0 			// check voor end of string
	beq print_storage		// Print de storage na het einde van de string
	cmp r0, #'@'
	beq compressed_item
	strb r0, [r4]			// Store r0 in r4 (mybuffer)
	//bl uart_put_char
	add  r4, r4, #1			// Verhoog de index pointer van de storage
	add  r5, r5, #1			// Verhoog de index pointer van de string
	b    filling			// Loop


print_storage:
	add r4, r4, #1			// Verhoog de index pointer van de Storage
	strb r0, [r4]			// Zet end of string (#0) dat nog in r0 stond in de storage
	ldr r4, =mybuffer		// Zet r4 naar het begin van de storage
storage_print_loop:
	ldrb r0, [ r4 ]			// Laad index r4 uit de storage in r0
	cmp r0,  #0				// check voor end of string
	beq done				// Return als het einde van de string gevonden is
	bl   uart_put_char		// Print het character uit de storage
	add r4,  #1				// Verhoog de index pointer van de storage
	b    storage_print_loop	// Loop
	






















