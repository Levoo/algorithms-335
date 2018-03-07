# Author: Fernando Cuevas
# Class: CPSC 440 MON/WEN 1-2:15
# Professor: Heckethorn
# Program: Assignment 6, Fahrenheit/Celsius converter


.data
    scaletype: .asciiz "Enter Scale     : "
    tempNum:   .asciiz "Enter Temperature: "
    cConvert:  .asciiz "Celsius Temperature: "
    cPost:     .asciiz " C\n\n"
    fPost:     .asciiz " F\n\n"
    fConvert:  .asciiz "Fahrenheit Temperature: "
    endCard:   .asciiz "\nFINISHED..."
    quitFlag:  .asciiz "Q"
    newline:   .asciiz "\n"
.text 
.globl main

main:
    li $t5, 'F'
    li $t6, 'C'
    li $t7, 'Q'

dowhile:
    li $v0, 4
    la $a0, scaletype       # load and print scale prompt
    syscall 

    li $v0, 12				# read char from input
	syscall
	move $t0, $v0           # $t0 holds the user input for Scale

    beq $t7, $t0, quitProg  # check if they want to quit
    
    li $v0, 4               # new line it
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, tempNum # laod and print temp prompt
    syscall
    

    li $v0, 5       # v0 now has int
    syscall
    move $t1, $v0  # move temp value into t1

    beq $t5, $t0, convertFtoC   # f to c
    beq $t6, $t0, convertCtoF   # c to f

convertCtoF:
    mul $t2, $t1, 9
    div $t2, $t2, 5
    add $t2, $t2, 32

    li $v0, 4
    la $a0, cConvert
    syscall

    li $v0, 1
    move $a0, $t2
    syscall

    li $v0, 4
    la $a0, fPost
    syscall
    j dowhile
convertFtoC:
    add $t2, $t1, -32
    mul $t2, $t2, 5
    div $t2, $t2, 9

    li $v0, 4
    la $a0, cConvert
    syscall

    li $v0, 1
    move $a0, $t2
    syscall

    li $v0, 4
    la $a0, cPost
    syscall
    j dowhile

quitProg:
    li $v0, 4
    la $a0, endCard  # end card to let user kow its oger now
    syscall
    li $v0, 10      # end program
    syscall

.end
