@echo off
:: Defs
set PROJECT_DIR=.
set SRC_DIR=%PROJECT_DIR%/src
set LIB_DIR=%PROJECT_DIR%/lib
set INCLUDE_DIR=%PROJECT_DIR%/include
set PROJECT_NAME=MyEditor
set EXE_DIR=%PROJECT_DIR%/bin

:: Flags
set GFLAGS=-fdiagnostics-color=always -Wall -Wextra -g

:: Dirs
set SOURCE_DIRS=%SRC_DIR%/*.cpp %LIB_DIR%/imgui/*.cpp
set INCLUDE_DIRS=-I%INCLUDE_DIR% -I%LIB_DIR%/imgui -I%LIB_DIR%/sdl2/include
set LIB_DIRS=-L%LIB_DIR% -L%LIB_DIR%/sdl2/lib

:: Libs
set LDLIBS=-lgdi32 -lopengl32 -lmingw32 -lSDL2main -lSDL2 -mwindows
echo Compilando...
@echo on
g++ %GFLAGS% %SOURCE_DIRS% %INCLUDE_DIRS% %LIB_DIRS% %LDLIBS% -o %EXE_DIR%/%PROJECT_NAME%.exe
