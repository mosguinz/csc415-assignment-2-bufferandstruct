/**************************************************************
 * Class::  CSC-415-03 Spring 2024
 * Name::  Mos Kullathon
 * Student ID::  921425216
 * GitHub-Name::  mosguinz
 * Project::  Assignment 2 – Buffering and Structures
 *
 * File::  Kullathon_Mos_HW2_main.c
 *
 * Description::  To demonstrate the use of pointers, buffers,
 * block operations, and interpreting hexadecimal dumps to
 * debug code.
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assignment2.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Not enough arguments: expected 3, got %d\n", argc - 1);
        return -1;
    }

    struct personalInfo *person = malloc(sizeof(struct personalInfo));

    person->firstName = argv[1];
    person->lastName = argv[2];
    person->studentID = 921425216;
    person->level = JUNIOR;
    person->languages = (KNOWLEDGE_OF_C |
                         KNOWLEDGE_OF_JAVA |
                         KNOWLEDGE_OF_JAVASCRIPT |
                         KNOWLEDGE_OF_PYTHON |
                         KNOWLEDGE_OF_CPLUSPLUS |
                         KNOWLEDGE_OF_SQL |
                         KNOWLEDGE_OF_HTML |
                         KNOWLEDGE_OF_MIPS_ASSEMBLER);

    // Truncate message length to 100
    strncpy(person->message, argv[3], 100);

    if (writePersonalInfo(person))
    {
        fprintf(stderr, "Something went wrong writing personal information\n");
        return -2;
    }

    free(person);

    // Step six involves getting a series of C stings
    char *stringBuffer = malloc(BLOCK_SIZE);

    size_t bufferSize = BLOCK_SIZE;
    size_t bufferOffset = 0;

    const char *string;

    while ((string = getNext()))
    {
        // get string size
        size_t remainingBytes = strlen(string);
        size_t stringOffset = 0;

        while (1)
        {
            if (remainingBytes < bufferSize)
            {
                memcpy(stringBuffer + bufferOffset, string + stringOffset, remainingBytes); // commit everything
                bufferSize -= remainingBytes;
                bufferOffset += remainingBytes;
                break;
            }

            memcpy(stringBuffer + bufferOffset, string + stringOffset, bufferSize); // commit what you can
            commitBlock(stringBuffer);
            stringOffset += bufferSize;
            remainingBytes -= bufferSize;
            bufferSize = BLOCK_SIZE;
            bufferOffset = 0;
        }
    }

    commitBlock(stringBuffer);
    free(stringBuffer);

    checkIt();
    return 0;
}
