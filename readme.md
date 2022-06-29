# 本文件为提示文档

## 文件说明

* src文件夹中包含程序源代码以及测试代码，具体如下：

1. core.h为源代码的函数声明，类的声明等
2. core.cpp为主要代码，包括接口函数的具体实现
3. covertest.cpp为测试总体代码覆盖率函数代码
4. error.cpp为函数遇到边界情况的测试代码
5. testforinsert.cpp为测试int core::insert(string word)函数正确性的代码

* run_cover_test.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\run_cover_test.bat 或者直接运行该文件。

2. 运行结果：编译src\covertest.cpp、在当前路径下生成covertest.exe文件并运行这个exe文件，输出测试的数据以及数据结构的内容，生成solution.txt(该文件为接口函数写入结果的问件，在此无作用)和debug.txt(该文件为测试接口函数的输出结果)。

* run_error_test.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\run_error_test.bat 或者直接运行该文件。

2. 运行结果：编译src\error.cpp、创建文件夹something并将生成的error.exe文件放在something中，运行这个exe文件。

* run_insert_test.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\run_insert_test.bat 或者直接运行该文件。

2. 运行结果：编译src\testforinsert.cpp、生成testforinsert.exe文件并运行这个exe文件。

* test_cover.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\test_cover.bat 或者直接运行该文件。

2. 运行结果：编译src\covertest.cpp、在当前路径下生成一系列文件，包括exe（在something文件夹）、gcov、gcda、gcno，然后运行exe文件，输出测试的数据以及数据结构的内容，生成solution.txt(该文件为接口函数写入结果的问件，在此无作用)和debug.txt(该文件为测试接口函数的输出结果)。终端输出一些文件代码覆盖率，然后打开core.cpp.gcov(可以查看core.cpp中代码执行情况)和debug.txt(查看测试输出)。

* test_error.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\test_error.bat 或者直接运行该文件。

2. 运行结果：编译src\error.cpp、在当前路径下生成一系列文件，包括exe（在something文件夹)、gcov、gcda、gcno，然后运行exe文件，终端输出测试结果和一些文件代码覆盖率，然后打开core.cpp.gcov(可以查看core.cpp中代码执行情况)。

* test_insert.bat文件为脚本文件

1. 使用方法：在本文件下使用命令行 .\test_insert.bat 或者直接运行该文件。

2. 运行结果：编译src\testforinsert.cpp、在当前路径下生成一系列文件，包括exe（在something文件夹）、gcov、gcda、gcno，然后运行exe文件，终端输出测试结果和一些文件代码覆盖率，然后打开core.cpp.gcov(可以查看core.cpp中代码执行情况)。


### 注：所有生成的exe文件都将放在something文件夹中，若文件夹不存在，将创建。已经编译好的文件可以直接在somrthing文件夹中去运行该可执行文件。
