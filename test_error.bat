mkdir something
g++ -lgcov -fprofile-arcs -ftest-coverage -o .\something\error.exe .\src\error.cpp
.\something\error.exe
gcov -a .\error.cpp

%open the file core.cpp.gcov%
core.cpp.gcov