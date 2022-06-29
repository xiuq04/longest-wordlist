mkdir something
g++ -lgcov -fprofile-arcs -ftest-coverage -o .\something\covertest.exe .\src\covertest.cpp
.\something\covertest.exe
gcov -a covertest.cpp

%open the file core.cpp.gcov%
core.cpp.gcov

%open the file debug.txt%
debug.txt