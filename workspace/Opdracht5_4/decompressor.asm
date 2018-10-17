	.cpu cortex-m0
	.text
	.align 1
	.global string
	.global make_string

	
compressed_item:
	
	add r5, r5, #1 			// Verhoog de pointer index in de string naar de offset
	ldrb r0, [ r5 ]			// Haal het offset character op
	mov r6, r0 				// Store de offset in r6
	
	add r5, r5, #1			// Verhoog de pointer index in de string naar de size
	ldrb r0, [ r5 ]			// Haal het size character op
	mov r7, r0				// Store de size in r7
	
	sub r6, r6, #'0'		// Haal '0' van de offset af om de waarde te krijgen
	sub r7, r7, #'0'		// Haal '0' van de size af om de waarde te krijgen
	
	ldr r2, =mybuffer
	add r3, r2, r6			// zet r3 naar het begin van de buffer + de offset
	
loop2:
	cmp r7, #0				// Als lengte 0 is, break
	beq decompress_done
	
	ldrb r0, [r3]			// Haal het r3e waarde uit de buffer en stop in r0
	bl move_buffer			// Verschuif alle waarden in de buffer
	ldr r2, =mybuffer		// Laad het begin van de buffer opnieuw, want r2 is weg door bl commando
	strb r0, [r2]			// Store de waarde r0 in het begin van de buffer
	bl uart_put_char
	sub r7, r7, #1			// Haal 1 van de lengte af
	b loop2
	
	
decompress_done:
	add r5, r5, #1			// Tel 1 bij de waarde op, zodat de '@'  overgeslagen wordt.
	b filling


done: 
   pop  { r5, pc }
   



	.bss					// Buffer moet opgeslagen worden in .bss (of .data)
mybuffer:					
	.skip 50				// Maak de buffer aan met gedefinieerde grootte
	
	
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
	beq done
	cmp r0, #'@'
	beq compressed_item
	bl move_buffer			// Verschuif de buffer met 1 plaats
	strb r0, [r4]			// Store r0 in r4 (begin van mybuffer)
	add  r5, r5, #1			// Verhoog de index pointer van de string
	bl uart_put_char
	b    filling			// Loop





move_buffer:
	ldr r6, =mybuffer		// Zet r6 op het begin van de buffer
	add r6, r6, #40			// zet r6 naar het eind van de buffer
	mov r4, r6				// Zet r4 naar het eind van de buffer
	sub r4, r4, #1			// zet r4 op de 1 na laatste plaats van de buffer
	

move_buffer_loop:
	ldrb r2, [r4]
	strb r2, [r6]
	
	ldr r1, =mybuffer
	cmp r4, r1
	beq move_buffer_done
	
	sub r4, r4, #1
	sub r6, r6, #1
	
	b move_buffer_loop
	
move_buffer_done:
	mov pc, lr
























