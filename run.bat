@echo off
setlocal
cmake -B build -S . 
cmake --build build
build\Pazymiu_skaiciuokle.exe
endlocal
