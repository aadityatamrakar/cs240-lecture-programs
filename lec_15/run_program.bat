@echo off
gcc program11.c -o program11
program11 %1
if %errorlevel% equ 0 (
  echo Successfully executed file
) else (
  echo Could not execute program file
)