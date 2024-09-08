echo off

set PYTHON_HOME=D:\temp\Python312
set SWIG=D:\temp\swig-4.2.1
set Path=%PYTHON_HOME%;%SWIG%;%Path%

del /f C:\Users\%USERNAME%\AppData\Local\Microsoft\WindowsApps\python.exe
del /f C:\Users\%USERNAME%\AppData\Local\Microsoft\WindowsApps\python3.exe

rem 17 release
cmake -G "Visual Studio 17 2022" -A x64 -T host=x64 -DLLDB_EMBED_PYTHON_HOME=OFF -DLLDB_INCLUDE_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;lldb" -DCMAKE_SYSTEM_PROCESSOR=x86_64 -B buildMSVC17Release llvm-project-17.0.1.src\llvm\

@rem out:
@rem -- Could NOT find PythonAndSwig (missing: Python3_LIBRARIES Python3_INCLUDE_DIRS LLDB_ENABLE_SWIG)
@rem -- Enable Python scripting support in LLDB: FALSE
@rem -- Could NOT find LibXml2 (missing: LIBXML2_LIBRARY LIBXML2_INCLUDE_DIR) (Required is at least version "2.8")
@rem -- Enable Libxml 2 support in LLDB: FALSE
@rem -- Enable libfbsdvmcore support in LLDB: 0

