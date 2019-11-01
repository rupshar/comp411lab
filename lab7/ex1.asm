.data
  AA:     		.space 400  		# int AA[100]
  BB:     		.space 400  		# int BB[100]
  CC:     		.space 400  		# int CC[100]
  m:      		.space 4   		# m is an int whose value is at most 10
          	           			# actual size of the above matrices is mxm
                     		
  newline:		.asciiz "\n"
  space:		.asciiz " "
  

      # You may add more variables here if you need to



.text

main:


#------- INSERT YOUR CODE HERE for main -------
#
#  Best is to convert the C program line by line
#    into its assembly equivalent.  Carefully review
#    the coding templates near the end of Lecture 8.
#
#
#  1.  First, read m (the matrices will then be size mxm).
#  2.  Next, read matrix A followed by matrix B.
#  3.  Compute matrix product.  You will need triple-nested loops for this.
#  4.  Print the result, one row per line, with one (or more) space(s) between
#      values within a row.
#  5.  Exit.
#
#------------ END CODE ---------------

				# Read in m
  addi	$v0, $0, 5			# system call 5 is for reading an integer
  syscall 				# integer value read is in $v0
  add	$8, $0, $v0			# copy m into $8
  
  mult  $8, $8                    	# square $8 to know how many numbers are needed to be stored in AA and BB
  
  mflo  $t1				# move lo to $t1
  
  addi  $t2, $0, 4			# set $t2 to 4
  
  mult  $t1, $t2			# multiply $t1 by 4 to account for words
  mflo  $t3				# move lo to $t1
  
  addi  $t4, $0, 0

loopA: 
  
  addi  $v0, $0, 5
  syscall
  add   $t5, $0, $v0
  
  sll   $t6, $t4, 2
 
  #la    $t7, AA
  #add   $t7, $t7, $t6
  sw    $t5, AA($t6)
  
  addi  $t4, $t4, 1
  bne   $t4, $t1, loopA
  
  add   $t4, $0, $0
  
loopB: 
  
  addi  $v0, $0, 5
  syscall
  add   $t5, $0, $v0
  
  sll   $t6, $t4, 2
 
  #la    $t7, AA
  #add   $t7, $t7, $t6
  sw    $t5, BB($t6)
  
  addi  $t4, $t4, 1
  bne   $t4, $t1, loopB
  
  add   $t4, $0, $0
  
  add   $t7, $0, $0
  
loopC1:
  add   $t8, $0, $0
  

loopC2:
  add   $t9, $0, $0
  


loopC3:

  mult  $8, $t7
  mflo  $s0
  add   $s0, $s0, $t8
  
  mult  $8, $t7
  mflo  $s1
  add   $s1, $s1, $t9
  
  mult  $8, $t9
  mflo  $s2
  add   $s2, $s2, $t8
  
  sll   $s1, $s1, 2
  sll   $s2, $s2, 2
  
  lw    $s3, AA($s1)
  lw    $s4, BB($s2)
  
  mult  $s3, $s4
  mflo  $s5
  
  sll   $s0, $s0, 2
  
  lw    $s7, CC($s0)
  
  add   $s7, $s7, $s5
  
  sw    $s7, CC($s0)

  addi  $t9, $t9, 1
  bne   $t9, $8, loopC3
  addi  $t8, $t8, 1
  bne   $t8, $8, loopC2
  addi  $t7, $t7, 1
  bne   $t7, $8, loopC1
  add   $s0, $0, $0
  
   
print1:
  add   $s1, $0, $0
  
print2:

  mult  $8, $s0
  mflo  $s6
  add   $s6, $s6, $s1
  
  sll   $s6, $s6, 2
  lw    $10, CC($s6)
  
  				# Print the contents of CC at each index in row-major
  addi 	$v0, $0, 1  			# system call 1 is for printing an integer
  add 	$a0, $0, $10 			# bring the array value from $10 into $a0
  syscall           			# print the integer
  
      				# Print a space
  addi 	$v0, $0, 4  			# system call 4 is for printing a string
  la 	$a0, space 			# address of space string is in $a0
  syscall           			# print the string
  
  addi  $s1, $s1, 1
  bne   $s1, $8, print2
  
    				# Print a newline
  addi 	$v0, $0, 4  			# system call 4 is for printing a string
  la 	$a0, newline 			# address of newline string is in $a0
  syscall           			# print the string
  
  addi  $s0, $s0, 1
  bne   $s0, $8, print1

  
exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



#------- If you decide to make other functions, place their code here -------
#
#  You do not have to use helper methods, but you may if you would like to.
#  If you do use them, be sure to do all the proper stack management.
#  For this exercise though, it is easy enough to write all your code
#  within main.
#
#------------ END CODE ---------------
