# Postfix (Reverse Polish) Notation Calculator

.data

	expression: .space 64
	stack:    .space 64
	zero:	.ascii "0"
	one:	.asciiz "1"
	two:	.asciiz "2"
	three:	.asciiz "3"
	four:	.asciiz "4"
	five:	.asciiz "5"
	six:	.asciiz "6"
	seven:	.asciiz "7"
	eight:	.asciiz "8"
	nine:	.asciiz "9"
	plus:	.asciiz "+"
	minus:  .asciiz "-"
	times:  .asciiz "*"
	divides: .asciiz "/"
	newline:  .asciiz "\n"
	space: .asciiz " "

.text

main:

	li  $v0, 8
	la  $a0, expression
	li  $a1, 64
	syscall
	
	addi $t1, $0, 2608
	
	lh $t0, expression($0)
	
	beq  $t0, $t1, end
	
	add $s0, $0, $0		# stack counter
	add $s1, $0, $0		# loop counter
	
loop:
	
	lb  $t0, expression($s1)
	
	lb $t1, zero
	beq $t0, $t1, push_zero
	
	lb $t1, one
	beq $t0, $t1, push_one
	
	lb $t1, two
	beq $t0, $t1, push_two
	
	lb $t1, three
	beq $t0, $t1, push_three
	
	lb $t1, four
	beq $t0, $t1, push_four
	
	lb $t1, five
	beq $t0, $t1, push_five
	
	lb $t1, six
	beq $t0, $t1, push_six
	
	lb $t1, seven
	beq $t0, $t1, push_seven
	
	lb $t1, eight
	beq $t0, $t1, push_eight
	
	lb $t1, nine
	beq $t0, $t1, push_nine
	
	
	
loop_operators:

	lb $t0, expression($s1)
	
	lb $t1, plus
	beq $t0, $t1, addition
	
	lb $t1, minus
	beq $t0, $t1, subtraction
	
	lb $t1, times
	beq $t0, $t1, multiplication
	
	lb $t1, divides
	beq $t0, $t1, division
		
end_loop:
	
	addi $s1, $s1, 1
	lb, $t0, expression($s1) 	
	addi $t1, $0, 10
	bne $t0, $t1, loop
	
	lw $a0, stack($0)
	
	li $v0, 1
	syscall
	
	   				# Print a newline
  	addi 	$v0, $0, 4  			# system call 4 is for printing a string
  	la 	$a0, newline 			
  	syscall           			# print the string
  	
  	jal empty
	
	j main

empty:

	add  $s0, $0, $0
	jr $ra

push_zero:
	sw $0, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_one:

	addi $s2, $0, 1
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_two:

	addi $s2, $0, 2
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_three:

	addi $s2, $0, 3
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_four:

	addi $s2, $0, 4
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_five:

	addi $s2, $0, 5
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_six:

	addi $s2, $0, 6
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_seven:

	addi $s2, $0, 7
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_eight:

	addi $s2, $0, 8
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

push_nine:

	addi $s2, $0, 9
	sw $s2, stack($s0)
	addi $s0, $s0, 4
	j loop_operators

pop:
	addi $s0, $s0, -4
	
	lw $v0, stack($s0)
	
	jr $ra

addition:

	jal pop
	add $a0, $0, $v0
	
	jal pop
	add $a1, $0, $v0

	add $v0, $a0, $a1

	sw $v0, stack($s0)
	addi $s0, $s0, 4
	
	j end_loop

subtraction:

	jal pop
	add $a0, $0, $v0
	
	jal pop
	add $a1, $0, $v0
	
	sub $v0, $a1, $a0
	
	sw $v0, stack($s0)
	
	addi $s0, $s0, 4

	j end_loop

multiplication:

	jal pop
	add $a0, $0, $v0
	
	jal pop
	add $a1, $0, $v0
	
	mult $a0, $a1
	
	mflo $v0
	
	sw $v0, stack($s0)
	addi $s0, $s0, 4

	j end_loop

division:

	jal pop
	add $a1, $0, $v0
	
	jal pop
	add $a0, $0, $v0
	
	div $a0, $a1
	
	mflo $v0
	
	sw $v0, stack($s0)
	addi $s0, $s0, 4

	j end_loop

end:
     ori   $v0, $0, 10  # system call 10 for exit
     syscall            # we are out of here.
