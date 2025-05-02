@echo off
setlocal
set BUILD_TESTS=OFF
if not "%1"=="" set BUILD_TESTS=%1
cmake -B build -S . -DBUILD_TESTS=%BUILD_TESTS%
cmake --build build
if "%BUILD_TESTS%"=="ON" (
    build\tests.exe
) else (
    build\Pazymiu_skaiciuokle.exe
)
endlocal

