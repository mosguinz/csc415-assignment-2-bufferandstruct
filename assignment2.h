/**************************************************************
* Class:  CSC-415-0# Spring 2024
* Name: Robert Bierman
* Student ID: 
* GitHub Name: bierman
* Project: Assignment 2 – Command Line Arguments
*
* File: assignment2.h
*
* Description: To show how to use ...
*
**************************************************************/
#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H   1

#ifdef USEDECIMAL
#define KNOWLEDGE_OF_C				1
#define KNOWLEDGE_OF_JAVA			2
#define KNOWLEDGE_OF_JAVASCRIPT 	4
#define KNOWLEDGE_OF_PYTHON			8
#define KNOWLEDGE_OF_CPLUSPLUS		16
#define KNOWLEDGE_OF_PASCAL			32
#define KNOWLEDGE_OF_FORTRAN		64
#define KNOWLEDGE_OF_RUBY			128
#define KNOWLEDGE_OF_ADA			256
#define KNOWLEDGE_OF_LISP			512
#define KNOWLEDGE_OF_SQL			1024
#define KNOWLEDGE_OF_HTML			2048
#define KNOWLEDGE_OF_SWIFT			4096
#define KNOWLEDGE_OF_PROLOG			8192
#define KNOWLEDGE_OF_C_SHARP		16384
#define KNOWLEDGE_OF_PL1			32768
#define KNOWLEDGE_OF_INTEL_ASSEMBLER	65536
#define KNOWLEDGE_OF_IBM_ASSEMBLER	131072
#define KNOWLEDGE_OF_MIPS_ASSEMBLER	262144
#define KNOWLEDGE_OF_ARM_ASSEMBLER	524288
#define KNOWLEDGE_OF_COBOL			1048576
#define KNOWLEDGE_OF_APL			2097152
#define KNOWLEDGE_OF_R				4194304
#define KNOWLEDGE_OF_OBJECTIVE_C	8388608
#define KNOWLEDGE_OF_BASIC			16777216
#define KNOWLEDGE_OF_PHP			33554432
#define KNOWLEDGE_OF_GO				67108864

#else

#define KNOWLEDGE_OF_C                          0x00000001
#define KNOWLEDGE_OF_JAVA                       0x00000002
#define KNOWLEDGE_OF_JAVASCRIPT         	0x00000004
#define KNOWLEDGE_OF_PYTHON                     0x00000008
#define KNOWLEDGE_OF_CPLUSPLUS          	0x00000010
#define KNOWLEDGE_OF_PASCAL                     0x00000020
#define KNOWLEDGE_OF_FORTRAN            	0x00000040
#define KNOWLEDGE_OF_RUBY                       0x00000080
#define KNOWLEDGE_OF_ADA                        0x00000100
#define KNOWLEDGE_OF_LISP                       0x00000200
#define KNOWLEDGE_OF_SQL                        0x00000400
#define KNOWLEDGE_OF_HTML                       0x00000800
#define KNOWLEDGE_OF_SWIFT                      0x00001000
#define KNOWLEDGE_OF_PROLOG                     0x00002000
#define KNOWLEDGE_OF_C_SHARP            	0x00004000
#define KNOWLEDGE_OF_PL1                        0x00008000
#define KNOWLEDGE_OF_INTEL_ASSEMBLER    	0x00010000
#define KNOWLEDGE_OF_IBM_ASSEMBLER      	0x00020000
#define KNOWLEDGE_OF_MIPS_ASSEMBLER     	0x00040000
#define KNOWLEDGE_OF_ARM_ASSEMBLER      	0x00080000
#define KNOWLEDGE_OF_COBOL                      0x00100000
#define KNOWLEDGE_OF_APL                        0x00200000
#define KNOWLEDGE_OF_R                          0x00400000
#define KNOWLEDGE_OF_OBJECTIVE_C        	0x00800000
#define KNOWLEDGE_OF_BASIC                      0x01000000
#define KNOWLEDGE_OF_PHP                        0x02000000
#define KNOWLEDGE_OF_GO                         0x04000000


#endif
typedef struct personalInfo 
    {
    char * firstName;
    char * lastName;
    int studentID;
    enum gradelevel {FRESHMAN=17, SOPHMORE, JUNIOR, SENIOR, GRAD, INSTRUCTOR} level;
    int languages; // See #defines for the bitmap values
    char message[100];
    } personalInfo;
    
#define BLOCK_SIZE					256

int writePersonalInfo (personalInfo * pi);  //Write your personal info structure
const char * getNext(void);					//Get the next line to buffer write
void commitBlock (char * buffer);			//Flush out your 256 byte Buffer
int checkIt (void);							//Called at the end of your program to check the results

#else
#error Do Not include header file assignment2.h more than once
#endif
