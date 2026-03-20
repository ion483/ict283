@echo off
g++ -I ..\headers ..\sources\Utility.cpp BSTUnitTest.cpp -o BSTUnitTest
if %errorlevel% equ 0 (
    BSTUnitTest
)