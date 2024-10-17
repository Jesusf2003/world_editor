@echo off

:: Defs
set PROJECT_DIR=.
set SRC_DIR=%PROJECT_DIR%/src
set PROJECT_NAME=FGDTool
set EXE_DIR=%PROJECT_DIR%/bin

:: Flags
set GFLAGS=-fdiagnostics-color=always -Wall -Wextra -g

:: Dirs
set SOURCE_DIRS=%SRC_DIR%/*.cpp %SRC_DIR%/cmds/*.cpp

echo Compilando...
@echo on

g++ %GFLAGS% %SOURCE_DIRS% -o %EXE_DIR%/%PROJECT_NAME%.exe