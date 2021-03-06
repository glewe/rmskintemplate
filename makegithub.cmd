:: ============================================================================
::  MAKEGITHUB
::  ---------------------------------------------------------------------------
::  Author:  George Lewe
::  Date:    2020-01-03
::  ---------------------------------------------------------------------------
::  This batch intializes and pushes a reop to Github
:: ============================================================================
::
@echo off

IF [%1]==[] (
   echo ================================================================= START
   echo  Input Error
   echo -----------------------------------------------------------------
   echo  Please enter the Github repo name, e,g, "bsvconf"
   echo ================================================================= END
   echo.
   echo.
   GOTO:EOF
)

echo ================================================================= START
echo  Initializing Git repository...
echo -------------------------------------------------------------------------------
git init

echo ================================================================= START
echo  Staging all files and folders...
echo -------------------------------------------------------------------------------
git add --all

echo ================================================================= START
echo  Pushing origin to master...
echo -------------------------------------------------------------------------------
git commit -m "Initial commit"

echo ================================================================= START
echo  Add origin from Github...
echo -------------------------------------------------------------------------------
git remote add origin https://github.com/glewe/%1.git

echo ================================================================= START
echo  Push origin to Github...
echo -------------------------------------------------------------------------------
git push -u origin master
