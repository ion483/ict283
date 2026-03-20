@echo off
g++ -I ..\headers VectorUnitTest.cpp -o VectorUnitTest
if %errorlevel% equ 0 (
    VectorUnitTest
)