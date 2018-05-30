@echo off

echo ============ DEPLOYER ============
echo.
echo RELEASE or DEBUG (r/d)?

:ask
set INPUT=
set /P INPUT=Deploy mode: %=%

If /I "%INPUT%"=="r" goto release
If /I "%INPUT%"=="d" goto debug
echo incorrect input
goto ask

:debug
rmdir /s /q ".\Deploy_Debug"
mkdir ".\Deploy_Debug"
xcopy /s /i ".\PhotonBox\engine-res" ".\Deploy_Debug\PhotonBox\engine-res"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\Game\res" ".\Deploy_Debug\Game\res"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\vendor\Debug" ".\Deploy_Debug\Game"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\Game\bin\x64\Debug\Game.exe" ".\Deploy_Debug\Game"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
goto succ


:release
rmdir /s /q ".\Deploy_Release"
mkdir ".\Deploy_Release"
xcopy /s /i ".\PhotonBox\engine-res" ".\Deploy_Release\Game\engine-res"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\Game\res" ".\Deploy_Release\Game\res"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\vendor\Release" ".\Deploy_Release\Game"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
xcopy /s /i ".\Game\bin\x64\Release\Game.exe" ".\Deploy_Release\Game"
IF %ERRORLEVEL% NEQ 0 (
	goto err
)
goto succ


:err
echo.
echo ==============================================
echo An error occured!
echo ==============================================
goto end

:succ
echo.
echo ==============================================
echo Deploying succesful!
echo ==============================================
goto end

:end
echo.
pause
exit