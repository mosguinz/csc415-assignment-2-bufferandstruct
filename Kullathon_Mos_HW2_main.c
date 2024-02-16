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

    // Check if all required arguments are provided.
    if (argc < 4)
    {
        fprintf(stderr, "Not enough arguments: expected 3, got %d\n", argc - 1);
        return -1;
    }

    struct personalInfo *person = malloc(sizeof(struct personalInfo));

    // Per instructions, these fields are from the respective arguments.
    person->firstName = argv[1];
    person->lastName = argv[2];

    // Per instructions, these fields are hardcoded.
    person->studentID = 921425216;
    person->level = JUNIOR;

    // Each language values are powers of two. As such, their binary
    // representation will contain a one at their respective power. Since these
    // values are sequential, binary OR can be used to join them together.
    person->languages = (KNOWLEDGE_OF_C |
                         KNOWLEDGE_OF_JAVA |
                         KNOWLEDGE_OF_JAVASCRIPT |
                         KNOWLEDGE_OF_PYTHON |
                         KNOWLEDGE_OF_CPLUSPLUS |
                         KNOWLEDGE_OF_SQL |
                         KNOWLEDGE_OF_HTML |
                         KNOWLEDGE_OF_MIPS_ASSEMBLER);

    // Message must be at most 100 characters, as defined in `personalInfo`.
    // Here, we use `strncpy` to ensure that we do not exceed the limit.
    strncpy(person->message, argv[3], 100);

    // Abort if writing personal info fails.
    if (writePersonalInfo(person))
    {
        fprintf(stderr, "Something went wrong writing personal information\n");
        return -2;
    }

    free(person);

    // Create buffer of `BLOCK_SIZE` and keep track of how much of the block
    // is remaining, so that we may commit appropriately.
    char *stringBuffer = malloc(BLOCK_SIZE);
    size_t bufferSize = BLOCK_SIZE;
    size_t bufferOffset = 0;

    const char *string;

    // Retrieve strings to write to the buffer.
    while ((string = getNext()))
    {
        // Similarly, we keep track how much of the string we need to write,
        // so that we may determine: (a) if the current block size is sufficient
        // and (b) the position in the string from which to write, should (a)
        // not be met.
        size_t remainingBytes = strlen(string);
        size_t stringOffset = 0;

        // Loop terminates iff. the entirety of the string is written.
        while (1)
        {
            // If the remaining block is sufficient, write the entirety of the
            // remaining bytes.
            if (remainingBytes < bufferSize)
            {
                memcpy(stringBuffer + bufferOffset, string + stringOffset, remainingBytes);
                bufferSize -= remainingBytes;
                bufferOffset += remainingBytes;
                break;
            }

            // Otherwise, fill up the remainder and commit the block.
            memcpy(stringBuffer + bufferOffset, string + stringOffset, bufferSize);
            commitBlock(stringBuffer);
            stringOffset += bufferSize;
            remainingBytes -= bufferSize;
            bufferSize = BLOCK_SIZE;
            bufferOffset = 0;
        }
    }

    // Commit the final portion of the block, if any.
    if (bufferSize)
    {
        commitBlock(stringBuffer);
    }

    free(stringBuffer);
    return checkIt();
}
