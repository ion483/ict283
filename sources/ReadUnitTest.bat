@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Time_1.cpp ..\sources\WindRecType.cpp ..\sources\Read.cpp ReadUnitTest.cpp -o ReadUnitTest
if %errorlevel% equ 0 (
    ReadUnitTest
)