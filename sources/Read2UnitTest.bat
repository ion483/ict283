@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Time_1.cpp ..\sources\WindRecType.cpp ..\sources\Read2.cpp Read2UnitTest.cpp -o Read2UnitTest
if %errorlevel% equ 0 (
    Read2UnitTest
)