********** Testing main01.cpp **********
//
main01.cpp Passed!
Running valgrind to check for memory leaks.
valgrind reported errors!
//---------- valgrind output (last 5000 characters): 
==23598== Memcheck, a memory error detector
==23598== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==23598== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==23598== Command: ./hw3
==23598== 
Testing Empty Queue
==23598== 
==23598== HEAP SUMMARY:
==23598==     in use at exit: 81,504 bytes in 5 blocks
==23598== d4  total heap usage: 5 allocs, 0 frees, 81,504 bytes allocated
==23598== 
==23598== 8 bytes in 1 blocks are definitely lost in loss record 1 of 5
==23598==    at 0x4C2A73D: operator new[](unsigned long) (vg_replace_malloc.c:422)
==23598==    by 0x4013FB: GrocerySim::GrocerySim(int, int, int) (GrocerySim.cpp:11)
==23598==    by 0x401221: main (main01.cpp:20)
==23598== 
==23598== 32 bytes in 1 blocks are still reachable in loss record 2 of 5
==23598==    at 0x4C2A73D: operator new[](unsigned long) (vg_replace_malloc.c:422)
==23598==    by 0x401344: GrocerySim::GrocerySim(int, int, int) (GrocerySim.cpp:10)
==23598==    by 0x401221: main (main01.cpp:20)
==23598== 
==23598== 568 bytes in 1 blocks are still reachable in loss record 3 of 5
==23598==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==23598==    by 0x573558C: __fopen_internal (iofopen.c:73)
==23598==    by 0x4EE46CF: std::__basic_file<char>::open(char const*, std::_Ios_Openmode, int) (basic_file.cc:238)
==23598==    by 0x4F21849: std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (fstream.tcc:184)
==23598==    by 0x4F21A0F: std::basic_ifstream<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (fstream:597)
==23598==    by 0x40124A: main (main01.cpp:23)
==23598== 
==23598== 8,192 bytes in 1 blocks are still reachable in loss record 4 of 5
==23598==    at 0x4C2A73D: operator new[](unsigned long) (vg_replace_malloc.c:422)
==23598==    by 0x4F1D8D7: std::basic_filebuf<char, std::char_traits<char> >::_M_allocate_internal_buffer() (fstream.tcc:55)
==23598==    by 0x4F21861: std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (fstream.tcc:187)
==23598==    by 0x4F21A0F: std::basic_ifstream<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (fstream:597)
==23598==    by 0x40124A: main (main01.cpp:23)
==23598== 
==23598== 72,704 bytes in 1 blocks are still reachable in loss record 5 of 5
==23598==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==23598==    by 0x4EBF17F: pool (eh_alloc.cc:117)
==23598==    by 0x4EBF17F: __static_initialization_and_destruction_0 (eh_alloc.cc:244)
==23598==    by 0x4EBF17F: _GLOBAL__sub_I_eh_alloc.cc (eh_alloc.cc:307)
==23598==    by 0x400F502: call_init (dl-init.c:82)
==23598==    by 0x400F502: _dl_init (dl-init.c:131)
==23598==    by 0x40011A9: ??? (in /usr/lib64/ld-2.17.so)
==23598== 
==23598== LEAK SUMMARY:
==23598==    definitely lost: 8 bytes in 1 blocks
==23598==    indirectly lost: 0 bytes in 0 blocks
==23598==      possibly lost: 0 bytes in 0 blocks
==23598==    still reachable: 81,496 bytes in 4 blocks
==23598==                       of which reachable via heuristic:
==23598==                         newarray           : 32 bytes in 1 blocks
==23598==         suppressed: 0 bytes in 0 blocks
==23598== 
==23598== For counts of detected and suppressed errors, rerun with: -v
==23598== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 3 from 3)
********** Done Testing main01.cpp **********

********** Testing main02.cpp **********
//
main02.cpp Passed!
Running valgrind to check for memory leaks.
valgrind reported errors!
//---------- valgrind output (last 5000 characters): 
==23648== Memcheck, a memory error detector
==23648== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==23648== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==23648== Command: ./hw3
==23648== 
==23648== Conditional jump or move depends on uninitialised value(s)
==23648==    at 0x40197A: GrocerySim::shortest_queue(int&, int) (GrocerySim.cpp:62)
==23648==    by 0x401DC2: GrocerySim::distribute() (GrocerySim.cpp:142)
==23648==    by 0x401830: GrocerySim::simulate() (GrocerySim.cpp:214)
==23648==    by 0x401727: GrocerySim::run(std::istream&) (GrocerySim.cpp:32)
==23648==    by 0x40125F: main (main02.cpp:26)
==23648== 
Testing Singleton In
Shopper 1 arrived at 0 with 5 items, took 5 units
==23648== 
==23648== HEAP SUMMARY:
==23648==     in use at exit: 72,704 bytes in 1 blocks
==23648==   total heap usage: 8 allocs, 7 frees, 81,544 bytes allocated
==23648== 
==23648== 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
==23648==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==23648==    by 0x4EBF17F: pool (eh_alloc.cc:117)
==23648==    by 0x4EBF17F: __static_initialization_and_destruction_0 (eh_alloc.cc:244)
==23648==    by 0x4EBF17F: _GLOBAL__sub_I_eh_alloc.cc (eh_alloc.cc:307)
==23648==    by 0x400F502: call_init (dl-init.c:82)
==23648==    by 0x400F502: _dl_init (dl-init.c:131)
==23648==    by 0x40011A9: ??? (in /usr/lib64/ld-2.17.so)
==23648== 
==23648== LEAK SUMMARY:
==23648==    definitely lost: 0 bytes in 0 blocks
==23648==    indirectly lost: 0 bytes in 0 blocks
==23648==      possibly lost: 0 bytes in 0 blocks
==23648==    still reachable: 72,704 bytes in 1 blocks
==23648==         suppressed: 0 bytes in 0 blocks
==23648== 
==23648== For counts of detected and suppressed errors, rerun with: -v
==23648== Use --track-origins=yes to see where uninitialised values come from
==23648== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 3 from 3)
********** Done Testing main02.cpp **********

********** Testing main03.cpp **********
//
main03.cpp Passed!
Running valgrind to check for memory leaks.
valgrind reported errors!
//---------- valgrind output (last 5000 characters): 
==23696== Memcheck, a memory error detector
==23696== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==23696== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==23696== Command: ./hw3
==23696== 
==23696== Conditional jump or move depends on uninitialised value(s)
==23696==    at 0x40197A: GrocerySim::shortest_queue(int&, int) (GrocerySim.cpp:62)
==23696==    by 0x401DC2: GrocerySim::distribute() (GrocerySim.cpp:142)
==23696==    by 0x401830: GrocerySim::simulate() (GrocerySim.cpp:214)
==23696==    by 0x401727: GrocerySim::run(std::istream&) (GrocerySim.cpp:32)
==23696==    by 0x40125F: main (main03.cpp:29)
==23696== 
Testing Gap
Shopper 1 arrived at 1 with 5 items, took 5 units
Shopper 2 arrived at 2 with 10 items, took 10 units
Shopper 3 arrived at 100 with 5 items, took 5 units
==23696== 
==23696== HEAP SUMMARY:
==23696==     in use at exit: 72,704 bytes in 1 blocks
==23696==   total heap usage: 14 allocs, 13 frees, 81,672 bytes allocated
==23696== 
==23696== 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
==23696==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==23696==    by 0x4EBF17F: pool (eh_alloc.cc:117)
==23696==    by 0x4EBF17F: __static_initialization_and_destruction_0 (eh_alloc.cc:244)
==23696==    by 0x4EBF17F: _GLOBAL__sub_I_eh_alloc.cc (eh_alloc.cc:307)
==23696==    by 0x400F502: call_init (dl-init.c:82)
==23696==    by 0x400F502: _dl_init (dl-init.c:131)
==23696==    by 0x40011A9: ??? (in /usr/lib64/ld-2.17.so)
==23696== 
==23696== LEAK SUMMARY:
==23696==    definitely lost: 0 bytes in 0 blocks
==23696==    indirectly lost: 0 bytes in 0 blocks
==23696==      possibly lost: 0 bytes in 0 blocks
==23696==    still reachable: 72,704 bytes in 1 blocks
==23696==         suppressed: 0 bytes in 0 blocks
==23696== 
==23696== For counts of detected and suppressed errors, rerun with: -v
==23696== Use --track-origins=yes to see where uninitialised values come from
==23696== ERROR SUMMARY: 3 errors from 1 contexts (suppressed: 3 from 3)
********** Done Testing main03.cpp **********

********** Testing main04.cpp **********
//
main04.cpp Passed!
Running valgrind to check for memory leaks.
No memory leaks!
********** Done Testing main04.cpp **********

********** Testing main05.cpp **********
//
main05.cpp Passed!
Running valgrind to check for memory leaks.
valgrind reported errors!
//---------- valgrind output (last 5000 characters): 
==23799== Memcheck, a memory error detector
==23799== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==23799== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==23799== Command: ./hw3
==23799== 
==23799== Conditional jump or move depends on uninitialised value(s)
==23799==    at 0x40197A: GrocerySim::shortest_queue(int&, int) (GrocerySim.cpp:62)
==23799==    by 0x401DC2: GrocerySim::distribute() (GrocerySim.cpp:142)
==23799==    by 0x401830: GrocerySim::simulate() (GrocerySim.cpp:214)
==23799==    by 0x401727: GrocerySim::run(std::istream&) (GrocerySim.cpp:32)
==23799==    by 0x40125F: main (main05.cpp:28)
==23799== 
Testing Same Exit
Shopper 1 arrived at 1 with 10 items, took 10 units
Shopper 2 arrived at 2 with 9 items, took 9 units
==23799== 
==23799== HEAP SUMMARY:
==23799==     in use at exit: 72,704 bytes in 1 blocks
==23799==   total heap usage: 11 allocs, 10 frees, 81,616 bytes allocated
==23799== 
==23799== 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
==23799==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==23799==    by 0x4EBF17F: pool (eh_alloc.cc:117)
==23799==    by 0x4EBF17F: __static_initialization_and_destruction_0 (eh_alloc.cc:244)
==23799==    by 0x4EBF17F: _GLOBAL__sub_I_eh_alloc.cc (eh_alloc.cc:307)
==23799==    by 0x400F502: call_init (dl-init.c:82)
==23799==    by 0x400F502: _dl_init (dl-init.c:131)
==23799==    by 0x40011A9: ??? (in /usr/lib64/ld-2.17.so)
==23799== 
==23799== LEAK SUMMARY:
==23799==    definitely lost: 0 bytes in 0 blocks
==23799==    indirectly lost: 0 bytes in 0 blocks
==23799==      possibly lost: 0 bytes in 0 blocks
==23799==    still reachable: 72,704 bytes in 1 blocks
==23799==         suppressed: 0 bytes in 0 blocks
==23799== 
==23799== For counts of detected and suppressed errors, rerun with: -v
==23799== Use --track-origins=yes to see where uninitialised values come from
==23799== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 3 from 3)
********** Done Testing main05.cpp **********

********** Testing main06.cpp **********
//
main06.cpp Passed!
Running valgrind to check for memory leaks.
No memory leaks!
********** Done Testing main06.cpp **********

*/*/*/*/*/ Some of the tests failed! /*/*/*/*/*
Tests that failed: valgrind(main01.cpp), valgrind(main02.cpp), valgrind(main03.cpp), valgrind(main05.cpp), 



//@@                       at 2017-09-29 22:46:57
//@@ ======== SUBMISSION SCREENING END =====

...done preparing for testing.
your submission has been accepted!
cleaning up after testing...
Cleaning up...
...done cleaning up after testing
your submission is complete!
