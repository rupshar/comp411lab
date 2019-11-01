# Starter file for ex1.asm

.data
	#...
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
    
    	beq  $a0, $0, end			#end the program if N = 0
    
    				# Read in K
    	addi $v0, $0, 5			# system call 5 is for reading an integer
    	syscall				# integer value read is in $v0
    	add  $a1, $0, $v0			# copy K into $a1	
    
    	addi    $sp, $sp, -8        # Make room on stack for saving $ra and $fp
    	sw      $ra, 4($sp)         # Save $ra
    	sw      $fp, 0($sp)         # Save $fp

    	addi    $fp, $sp, 4         # Set $fp to the start of proc1's stack frame

    
    	jal NchooseK		# jump and link to NchooseK
    
    	lw      $ra, 4($sp)
    	lw      $fp, 0($sp)
    	addi    $sp, $sp, 8
    
    				# Print the NchooseK value
    	add  $a0, $0, $v0
    	addi $v0, $0, 1
    	syscall
    
       				# Print a newline
    	addi $v0, $0, 4  			# system call 4 is for printing a string
    	la 	 $a0, newline 			
    	syscall           			# print the string
    
    	j main			# repeat the above steps, as the program only ends if a 0 is received as first input


end: 
	ori   $v0, $0, 10     # system call 10 for exit
	syscall               # we are out of here.



NchooseK:    		# PLEASE DO NOT CHANGE THE NAME "NchooseK"
	#----------------------------------------------------------------#
	# $a0 has the number n, $a1 has k, from which to compute n choose k
	#
	# Write code here to implement the function you wrote in C.
	# Your implementation MUST be recursive; an iterative
	# implementation is not acceptable.
	#
	# $v0 should have the NchooseK result to be returned to main.
	#----------------------------------------------------------------#

	#...
	#...
	
	addi    $sp, $sp, -8       # Make room on stack for saving $ra and $fp
    	sw      $ra, 4($sp)         # Save $ra
    	sw      $fp, 0($sp)         # Save $fp
    	
    	addi    $fp, $sp, 4
    	
    	li      $v0, 1
    	
    	beq     $a1, $0, return_from_proc1
    	
    	beq     $a0, $a1, return_from_proc1
    	
    	addi    $sp, $sp, -16
    	
    	sw	$s0, 12($sp)
    	sw      $s1, 8($sp)
    	sw      $s2, 4($sp)
    	
 	addi    $s0, $a0, 0
    	addi    $s1, $a1, 0
    	
    	addi    $a0, $a0, -1
    	addi    $a1, $a1, -1
    	
    	jal     NchooseK
    	
        add     $s2, $0, $v0
    	
    	add     $a0, $0, $s0
    	add     $a1, $0, $s1
    	
    	addi    $a0, $a0, -1
    	
    	jal     NchooseK
    	
    	add     $v0, $v0, $s2
    	
    	lw      $s0, -8($fp) 
    	lw      $s1, -12($fp)
    	lw      $s2, -16($fp)
	
return_from_proc1:
	addi  $sp, $fp, 4
	lw    $ra, 0($fp)
	lw    $fp, -4($fp)
	jr    $ra