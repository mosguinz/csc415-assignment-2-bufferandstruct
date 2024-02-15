/**************************************************************
 * Class::  CSC-415-03 Spring 2024
 * Name::  Mos Kullathon
 * Student ID::  921425216
 * GitHub-Name::  mosguinz
 * Project:: Assignment 2 – Command Line Arguments
 *
 * File::  Kullathon_Mos_HW2_main.c
 *
 * Description::
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
        return -1;
    }

    // Step four is to allocate (using malloc) an instantiation of the
    // personInfo structure and to populate it.

    struct personalInfo *person = malloc(sizeof(struct personalInfo));

    // The firstName and the lastName are populated from the 1st
    // and second command line argument.
    person->firstName = argv[1];
    person->lastName = argv[2];

    // You will then assign your student ID to the studentID field,
    // you will populate the level (gradelevel) appropriately.
    person->studentID = 921425216;
    person->level = JUNIOR;

    // You will then populate the languages field.
    person->languages = (KNOWLEDGE_OF_JAVA | KNOWLEDGE_OF_CPLUSPLUS | KNOWLEDGE_OF_MIPS_ASSEMBLER);

    // The last part of populating the structure is to copy the third
    // command line parameter to the message field.
    strncpy(person->message, argv[3], 100);

    // Step five is to "write" your personal information structure
    // by calling writePersonalInfo
    if (writePersonalInfo(person) != 0)
    {
        // print error here
        return -2;
    }

    free(person);

    // Step six involves getting a series of C stings
    char *stringBuffer = malloc(BLOCK_SIZE);

    size_t bufferSize = BLOCK_SIZE;
    size_t bufferOffset = 0;

    char *string;

    while (string = getNext())
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
