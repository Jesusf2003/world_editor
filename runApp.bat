@echo off
echo Compilacion exitosa
echo Corriendo ejecutable...
cd %EXE_DIR%
%PROJECT_NAME%.exe -help
cd ..