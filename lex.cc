// Generated by Flexc++ V2.08.01 on Mon, 30 Aug 2021 14:14:26 +0700

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

//FBB
#include <filesystem>

// $insert class_ih
#include "Scanner.ih"


    // s_ranges_: use (unsigned) characters as index to obtain
    //           that character's range-number.
    //           The range for EOF is defined in a constant in the
    //           class header file
size_t const ScannerBase::s_ranges_[] =
{
     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
     3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 9,10,11,11,12,13,14,15,16,17,18,19,
    20,20,20,20,20,20,20,20,21,22,23,23,23,23,24,25,26,27,28,29,29,30,30,30,30,
    31,32,32,32,32,33,34,35,36,37,38,39,40,40,40,40,41,41,41,41,42,43,44,45,46,
    47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,68,69,69,
    69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
    69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
    69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
    69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
    69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
    69,69,69,69,69,69,
};

// $insert startcondinfo
    // s_dfa_ contains the rows of *all* DFAs ordered by start state.  The
    // enum class StartCondition_is defined in the baseclass header.
    // StartCondition_::INITIAL is always 0.  Each entry defines the row to
    // transit to if the column's character range was sensed. Row numbers are
    // relative to the used DFA, and d_dfaBase_ is set to the first row of
    // the subset to use.  The row's final two values are respectively the
    // rule that may be matched at this state, and the rule's FINAL flag. If
    // the final value equals FINAL (= 1) then, if there's no continuation,
    // the rule is matched. If the BOL flag (8) is also set (so FINAL + BOL (=
    // 9) is set) then the rule only matches when d_atBOL is also true.
int const ScannerBase::s_dfa_[][73] =
{
    // INITIAL
    {-1, 1, 2,-1, 1,-1, 3,-1, 4,-1, 5,-1, 6,-1, 7,-1, 8,-1, 9,10,
         10,-1,11,-1,12,13,13,13,14,13,13,15,13,16,13,17,18,19,13,13,
         13,-1,20,-1,21,13,22,23,13,13,13,24,13,25,13,13,26,27,28,29,
         13,30,31,13,13,13,13,32,13,-1,-1,    -1, -1},  // 0
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     0, -1},  // 1
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    22, -1},  // 2
    {33,33,-1,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,-1,    -1, -1},  // 3
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
         34,-1,34,-1,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
         34,34,34,34,34,34,34,34,34,-1,-1,    -1, -1},  // 4
    {35,35,-1,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
         35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
         35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
         35,35,35,35,35,35,35,35,35,35,-1,    -1, -1},  // 5
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     9, -1},  // 6
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    13, -1},  // 7
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 8
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37,37,
         37,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,39,-1,-1,-1,     2, -1},  // 9
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37,37,
         37,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     2, -1},  // 10
    {11,11,-1,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
         11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
         11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
         11,11,11,11,11,11,11,11,11,11,-1,    21, -1},  // 11
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     8, -1},  // 12
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 13
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,41,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 14
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,42,13,13,13,13,13,13,13,13,13,13,13,42,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 15
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,42,13,13,13,13,13,13,13,13,42,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 16
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,43,
         43,40,-1,-1,-1,43,43,43,43,43,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,43,43,43,43,43,43,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 17
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,42,13,13,13,13,42,13,13,13,13,13,42,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 18
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,42,13,13,13,13,13,13,13,13,13,13,42,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 19
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,20,
         20,-1,-1,-1,-1,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
         20,-1,20,-1,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
         20,20,20,20,20,20,20,20,20,-1,-1,    18, -1},  // 20
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,44,13,13,13,13,13,13,13,13,13,45,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 21
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,46,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 22
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,41,13,13,47,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 23
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,48,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 24
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,49,13,13,13,13,13,13,13,50,51,52,13,
         13,13,53,13,13,13,13,13,13,-1,-1,    18, -1},  // 25
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,54,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 26
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,55,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 27
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,56,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 28
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,57,13,13,13,13,-1,-1,    18, -1},  // 29
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,58,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 30
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,59,13,13,13,13,-1,-1,    18, -1},  // 31
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,60,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 32
    {33,33,-1,33,33,33,61,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,-1,    -1, -1},  // 33
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,34,
         34,-1,-1,-1,-1,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
         34,-1,34,-1,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,
         34,34,34,34,34,34,34,34,34,-1,-1,    19, -1},  // 34
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 35
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,63,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 36
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,64,64,
         64,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     2, -1},  // 37
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,65,65,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 38
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,66,
         66,-1,-1,-1,-1,66,66,66,66,66,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,66,66,66,66,66,66,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 39
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     6, -1},  // 40
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    12, -1},  // 41
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,     5, -1},  // 42
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,     4, -1},  // 43
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,49,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 44
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,56,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 45
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,49,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 46
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,67,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 47
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,68,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 48
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    16, -1},  // 49
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,69,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 50
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,49,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 51
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,49,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 52
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,56,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 53
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,49,13,13,13,-1,-1,    18, -1},  // 54
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,70,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 55
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    17, -1},  // 56
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,71,13,13,13,13,
         13,13,72,13,13,13,13,13,13,-1,-1,    18, -1},  // 57
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,56,13,13,13,13,
         13,56,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 58
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,49,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 59
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,56,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 60
    {33,33,-1,33,33,33,61,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,
         33,33,33,33,33,33,33,33,33,33,-1,    20, -1},  // 61
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    10, -1},  // 62
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,73,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 63
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     2, -1},  // 64
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,74,74,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 65
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,75,75,
         75,-1,-1,-1,-1,75,75,75,75,75,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,75,75,75,75,75,75,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     1, -1},  // 66
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    11, -1},  // 67
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,70,13,13,13,13,13,-1,-1,    18, -1},  // 68
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    15, -1},  // 69
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    14, -1},  // 70
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,13,13,13,13,56,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 71
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,13,
         13,40,-1,-1,-1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
         13,-1,13,-1,13,13,13,13,13,13,13,56,13,13,13,13,13,13,13,13,
         13,13,13,13,13,13,13,13,13,-1,-1,    18, -1},  // 72
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,76,-1,-1,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 73
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,77,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 74
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     1, -1},  // 75
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,78,-1,-1,-1,-1,-1,-1,-1,    -1, -1},  // 76
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,79,79,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 77
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     7, -1},  // 78
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,80,80,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 79
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,81,81,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 80
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,82,82,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 81
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,83,83,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 82
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     3, -1},  // 83
};


int const (*ScannerBase::s_dfaBase_[])[73] =
{
    s_dfa_ + 0,
};

size_t ScannerBase::s_istreamNr = 0;

// $insert inputImplementation
ScannerBase::Input::Input()
:
    d_in(0),
    d_lineNr(1)
{}

ScannerBase::Input::Input(std::istream *iStream, size_t lineNr)
:
    d_in(iStream),
    d_lineNr(lineNr)
{}

size_t ScannerBase::Input::get()
{
    switch (size_t ch = next())         // get the next input char
    {
        case '\n':
            ++d_lineNr;
        [[fallthrough]];

        default:
        return ch;
    }
}

size_t ScannerBase::Input::next()
{
    size_t ch;

    if (d_deque.empty())                // deque empty: next char fm d_in
    {
        if (d_in == 0)
            return AT_EOF;
        ch = d_in->get();
        return *d_in ? ch : static_cast<size_t>(AT_EOF);
    }

    ch = d_deque.front();
    d_deque.pop_front();

    return ch;
}

void ScannerBase::Input::reRead(size_t ch)
{
    if (ch < 0x100)
    {
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void ScannerBase::Input::reRead(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        reRead(str[idx]);
}

ScannerBase::ScannerBase(std::istream &in, std::ostream &out)
:
    d_out(new std::ostream(out.rdbuf())),
// $insert interactiveInit
    d_in(0),
    d_dfaBase_(s_dfa_)
{
    p_pushStream("(istream)", new std::istream(in.rdbuf()));
}

void ScannerBase::switchStream_(std::istream &in, size_t lineNr)
{
    d_input->close();
    d_streamStack.back().input = { new std::istream(in.rdbuf()), lineNr };
}


ScannerBase::ScannerBase(std::string const &infilename, std::string const &outfilename)
:
    d_out(outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
          outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                  new std::ofstream(outfilename)),
    d_dfaBase_(s_dfa_)
{
    p_pushStream(infilename, { new std::ifstream(infilename) });
}

void ScannerBase::switchStreams(std::istream &in, std::ostream &out)
{
    switchStream_(in, 1);
    switchOstream(out);
}

void ScannerBase::switchIstream(std::string const &infilename)
{
    d_input->close();
    d_filename = infilename;
    d_streamStack.back().input = new std::ifstream(infilename);
    d_atBOL = true;
}

void ScannerBase::switchStreams(std::string const &infilename,
                           std::string const &outfilename)
{
    switchOstream(outfilename);
    switchIstream(infilename);
}

void ScannerBase::pushStream(std::istream  &istr)
{
    p_pushStream("(istream)", new std::istream(istr.rdbuf())); //streamPtr);
}

void ScannerBase::pushStream(std::string const &name)
{
    std::istream *streamPtr = new std::ifstream(name);
    if (!*streamPtr)
    {
        delete streamPtr;
        throw std::runtime_error("Cannot read " + name);
    }
    p_pushStream(name, streamPtr);
}



// static
std::string ScannerBase::setCwd(std::string const &name)     // any name
{
    using namespace std;
    using namespace filesystem;

    error_code ec;
    if (not exists(name, ec))                           // not a filename
        return name;
                                                        // a filename: get its
    auto path = canonical(name);                        // full pathname
    current_path(path.parent_path(), ec);

    return path.string();                               // return the pathname
}

void ScannerBase::p_pushStream(std::string const &name, std::istream *streamPtr)
{
    if (d_streamStack.size() == s_maxSizeofStreamStack_)
    {
        delete streamPtr;
        throw std::length_error("Max stream stack size exceeded");
    }

    d_filename = name;
    d_streamStack.push_back(StreamStruct{setCwd(d_filename), { streamPtr } });

    d_input = &d_streamStack.back().input;

    d_atBOL = true;
}

void ScannerBase::switchOstream(std::ostream &out)
{
    *d_out << std::flush;
    d_out.reset(new std::ostream(out.rdbuf()));
}

// $insert debugFunctions
void ScannerBase::setDebug(bool onOff)
{}

bool ScannerBase::debug() const
{
    return false;
}

void ScannerBase::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input->reRead(d_matched, from);
    d_matched.resize(from);
}

void ScannerBase::switchOstream(std::string const &outfilename)
{
    *d_out << std::flush;
    d_out.reset(
            outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
            outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                    new std::ofstream(outfilename));
}


bool ScannerBase::popStream()
{
    using namespace std::filesystem;

    d_input->close();

    if (d_streamStack.size() <= 1)
        return false;

    d_streamStack.pop_back();

    d_filename = 
        path{ setCwd(d_streamStack.back().pushedName) }.filename().string();

    d_input = &d_streamStack.back().input;

    return true;
}



  // See the manual's section `Run-time operations' section for an explanation
  // of this member.
ScannerBase::ActionType_ ScannerBase::actionType_(size_t range)
{
    d_nextState = d_dfaBase_[d_state][range];

    if (d_nextState != -1)                  // transition is possible
        return ActionType_::CONTINUE;

    if (knownFinalState())                  // FINAL state reached
        return ActionType_::MATCH;         

    if (d_matched.size())
        return ActionType_::ECHO_FIRST;    // no match, echo the 1st char

    return range != s_rangeOfEOF_ ? 
                ActionType_::ECHO_CH 
            : 
                ActionType_::RETURN;
}

void ScannerBase::accept(size_t nChars)          // old name: less
{
    if (nChars < d_matched.size())
    {
        d_input->reRead(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

void ScannerBase::setMatchedSize(size_t length)
{
    d_input->reRead(d_matched, length);  // reread the tail section
    d_matched.resize(length);           // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  The final match length
  // is determined, the index of the matched rule is determined, and then
  // d_atBOL is updated. Finally the rule's index is returned.
  // The numbers behind the finalPtr assignments are explained in the 
  // manual's `Run-time operations' section.
size_t ScannerBase::matched_(size_t ch)
{
    d_input->reRead(ch);

    FinalData *finalPtr;
                            
    if (not d_atBOL)                    // not at BOL
        finalPtr = &d_final.std;        // then use the std rule (3, 4)

                                        // at BOL
    else if (not available(d_final.std.rule))   // only a BOL rule avail.
            finalPtr = &d_final.bol;            // use the BOL rule (6)

    else if (not available(d_final.bol.rule)) // only a std rule is avail.
        finalPtr = &d_final.std;        // use the std rule (7)
        
    else if (                           // Both are available (8)
        d_final.bol.length !=           // check lengths of matched texts
        d_final.std.length              // unequal lengths, use the rule
    )                                   // having the longer match length
        finalPtr =              
            d_final.bol.length > d_final.std.length ?
                &d_final.bol
            :
                &d_final.std;

    else                            // lengths are equal: use 1st rule
        finalPtr = 
            d_final.bol.rule < d_final.std.rule ?
                &d_final.bol
            :
                &d_final.std;

    setMatchedSize(finalPtr->length);

    d_atBOL = d_matched.back() == '\n';


    return finalPtr->rule;
}

size_t ScannerBase::getRange_(int ch)       // using int to prevent casts
{
    return ch == AT_EOF ? as<size_t>(s_rangeOfEOF_) : s_ranges_[ch];
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match
void ScannerBase::continue_(int ch)
{
    d_state = d_nextState;

    if (ch != AT_EOF)
        d_matched += ch;
}

void ScannerBase::echoCh_(size_t ch)
{
    *d_out << as<char>(ch);
    d_atBOL = ch == '\n';
}


   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void ScannerBase::echoFirst_(size_t ch)
{
    d_input->reRead(ch);
    d_input->reRead(d_matched, 1);
    echoCh_(d_matched[0]);
}

    // Update the rules associated with the current state, do this separately
    // for BOL and std rules.
    // If a rule was set, update the rule index and the current d_matched
    // length. 
void ScannerBase::updateFinals_()
{
    size_t len = d_matched.size();

    int const *rf = d_dfaBase_[d_state] + s_finIdx_;

    if (rf[0] != -1)        // update to the latest std rule
    {
        d_final.std = FinalData { as<size_t>(rf[0]), len };
    }

    if (rf[1] != -1)        // update to the latest bol rule
    {
        d_final.bol = FinalData { as<size_t>(rf[1]), len };
    }
}

void ScannerBase::reset_()
{
    d_final = Final{ 
                    FinalData{s_unavailable, 0}, 
                    FinalData {s_unavailable, 0} 
                };

    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
}

int Scanner::executeAction_(size_t ruleIdx)
try
{
    switch (ruleIdx)
    {
        // $insert actions
        case 1:
        {
#line 3 "lexer"
            return Parser::NUMBER_HEX;
        }
        break;
        case 2:
        {
#line 4 "lexer"
            return Parser::NUMBER_DEC;
        }
        break;
        case 3:
        {
#line 5 "lexer"
            return Parser::NUMBER_BIN;
        }
        break;
        case 4:
        {
#line 6 "lexer"
            return Parser::REG;
        }
        break;
        case 5:
        {
#line 7 "lexer"
            return Parser::REG;
        }
        break;
        case 6:
        {
#line 8 "lexer"
            return Parser::LABEL;
        }
        break;
        case 7:
        {
#line 9 "lexer"
            return Parser::START;
        }
        break;
        case 8:
        {
#line 10 "lexer"
            return Parser::REG_LINK;
        }
        break;
        case 9:
        {
#line 11 "lexer"
            return Parser::REG_LINK_LINK;
        }
        break;
        case 10:
        {
#line 12 "lexer"
            return Parser::NUMBER_CHAR;
        }
        break;
        case 11:
        {
#line 13 "lexer"
            return Parser::DEF;
        }
        break;
        case 12:
        {
#line 14 "lexer"
            return Parser::DB;
        }
        break;
        case 13:
        {
#line 15 "lexer"
            return Parser::COMMA;
        }
        break;
        case 14:
        {
#line 16 "lexer"
            return Parser::COMMAND_1;
        }
        break;
        case 15:
        {
#line 17 "lexer"
            return Parser::COMMAND_2;
        }
        break;
        case 16:
        {
#line 18 "lexer"
            return Parser::COMMAND_3;
        }
        break;
        case 17:
        {
#line 19 "lexer"
            return Parser::COMMAND_3;
        }
        break;
        case 18:
        {
#line 20 "lexer"
            return Parser::IDENTIFIER;
        }
        break;
        case 19:
        {
#line 21 "lexer"
            return Parser::VALUE;
        }
        break;
        case 20:
        {
#line 22 "lexer"
            return Parser::WORD;
        }
        break;
        case 22:
        {
#line 24 "lexer"
            return Parser::NEW_LINE;
        }
        break;
    }
    noReturn_();
    return 0;
}
catch (Leave_ value)
{
    return static_cast<int>(value);
}

int Scanner::lex_()
{
    reset_();
    preCode();

    while (true)
    {
        size_t ch = get_();                // fetch next char
        size_t range = getRange_(ch);      // determine the range

        updateFinals_();                    // update the state's Final info

        switch (actionType_(range))        // determine the action
        {
            case ActionType_::CONTINUE:
                continue_(ch);
            continue;

            case ActionType_::MATCH:
            {
                d_token_ = executeAction_(matched_(ch));
                if (return_())
                {
                    print();
                    postCode(PostEnum_::RETURN);
                    return d_token_;
                }
                break;
            }

            case ActionType_::ECHO_FIRST:
                echoFirst_(ch);
            break;

            case ActionType_::ECHO_CH:
                echoCh_(ch);
            break;

            case ActionType_::RETURN:
                if (!popStream())
                {
                     postCode(PostEnum_::END);
                     return 0;
                }
                postCode(PostEnum_::POP);
             continue;
        } // switch

        postCode(PostEnum_::WIP);

        reset_();
        preCode();
    } // while
}

void ScannerBase::print_() const
{
}


