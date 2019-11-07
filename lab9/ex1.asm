# Starter file for ex1.asm

.data 0x0
	#...
	pattern:        .space 80
	newline:	.asciiz "\n"		
        
.text 

main:
	#...
	#...

	#----------------------------------------------------------------#
	# Write code here to do exactly what main does in the C program.
	#
	# Please follow these guidelines:
	#
	#	Use syscall 5 each time to read an integer (scanf("%d", ...))
	#	Then call NchooseK to compute the function
	#	Then use syscall 1 to print the result
	#   Put all of the above inside a loop
	#----------------------------------------------------------------#
	
				# Read in N
    	addi $v0, $0, 5			# system call 5 is for reading an integer
   	syscall 				# integer value read is in $v0
    	add  $a0, $0, $v0			# copy N into $a0
    	
    	addi $t9, $0, 4
    	mult $a0, $t9
    	mflo $a0
    	
    	add     $a3, $a0, $0
    	
    	addi     $a1, $0, 0
    
    	addi    $sp, $sp, -8        # Make room on stack for saving $ra and $fp
    	sw      $ra, 4($sp)         # Save $ra
    	sw      $fp, 0($sp)         # Save $fp

    	addi    $fp, $sp, 4         # Set $fp to the start of proc1's stack frame

    
    	jal 	binaryMaker		# jump and link to binaryMaker
    
    	lw      $ra, 4($sp)
    	lw      $fp, 0($sp)
    	addi    $sp, $sp, 8
    
    	j end			# repeat the above steps, as the program only ends if a 0 is received as first input


end: 
	ori   $v0, $0, 10     # system call 10 for exit
	syscall               # we are out of here.



binaryMaker:    		
	
	addi    $sp, $sp, -8       # Make room on stack for saving $ra and $fp
    	sw      $ra, 4($sp)         # Save $ra
    	sw      $fp, 0($sp)         # Save $fp
    	
    	addi    $fp, $sp, 4
    	
    	li      $v0, 1
    	
    	add	$t4, $0, $0
    	
    	beq     $a0, $a1, printArray
    	
    	addi    $sp, $sp, -8
    	
    	add     $s0, $0, $a0
    	add     $s1, $0, $a1
    	
    	sw	$s0, 4($sp)
    	sw      $s1, 0($sp)
    	
 	addi    $s0, $a0, 0

    	sw      $0, pattern($a1)
    	
    	addi    $a1, $a1, 4
    	
    	jal     binaryMaker
    	  	
    	lw      $s0, -8($fp) 
    	lw      $s1, -12($fp)  	
    	  	
    	add     $a0, $0, $s0
    	add     $a1, $0, $s1
    	
    	addi    $t1, $0, 1
    	
    	sw      $t1, pattern($a1)
    	
    	addi    $a1, $a1, 4
    	
    	jal     binaryMaker
    	
    	add     $v0, $v0, $s2
    	
    	lw      $s0, -8($fp) 
    	lw      $s1, -12($fp)
	
return_from_proc1:

	addi  $sp, $fp, 4
	lw    $ra, 0($fp)
	lw    $fp, -4($fp)
	jr    $ra

printArray:
	
	lw 	$10, pattern($t4)
	
	addi 	$v0, $0, 1  			# system call 1 is for printing an integer
  	add 	$a0, $0, $10 			# bring the array value from $10 into $a0
  	syscall
  	
  	addi    $t4, $t4, 4
  	
  	slt    $t5, $t4, $a3
  	
  	bne    $t5, $0, printArray
  	
  	   				# Print a newline
  	addi 	$v0, $0, 4  			# system call 4 is for printing a string
  	la 	$a0, newline 			
  	syscall           			# print the string
  	      	
  	j return_from_proc1     