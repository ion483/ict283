@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Time_1.cpp ..\sources\WindRecType.cpp WindRecTypeUnitTest.cpp -o WindRecTypeUnitTest
if %errorlevel% equ 0 (
    WindRecTypeUnitTest
)