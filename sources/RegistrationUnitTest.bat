@echo off
g++ -I ..\headers ..\sources\Unit.cpp ..\sources\Date.cpp ..\sources\Result.cpp ..\sources\Registration.cpp RegistrationUnitTest.cpp -o RegistrationUnitTest
if %errorlevel% equ 0 (
    RegistrationUnitTest
)