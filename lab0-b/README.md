# Word counter

This program counts the words in the specified txt file and outputs the result to the specified csv file in the form of a table:
1) Word
2) Frequency
3) Frequency as a percentage

## Example for use

`word_count.exe input.txt output.csv`


## Valgrind's memcheck result:

    ==2197== Memcheck, a memory error detector
    ==2197== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==2197== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
    ==2197== Command: ./a.out
    ==2197==
    More arguettes are needed==2197== 
    ==2197== HEAP SUMMARY:
    ==2197==     in use at exit: 0 bytes in 0 blocks
    ==2197==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
    ==2197==
    ==2197== All heap blocks were freed -- no leaks are possible
    ==2197==
    ==2197== For lists of detected and suppressed errors, rerun with: -s
    ==2197== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)