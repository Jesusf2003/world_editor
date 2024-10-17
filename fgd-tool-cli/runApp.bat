@echo off

:: Defs
set EXE_DIR=./bin
set PROJECT_NAME=FGDTool

echo Corriendo proyecto...
@echo off
cd %EXE_DIR%
%PROJECT_NAME%.exe --help
cd ..