mkdir something
g++ -lgcov -fprofile-arcs -ftest-coverage -o .\something\testforinsert.exe .\src\testforinsert.cpp
.\something\testforinsert.exe
gcov -a .\testforinsert.cpp

%open the file core.cpp.gcov%
core.cpp.gcov