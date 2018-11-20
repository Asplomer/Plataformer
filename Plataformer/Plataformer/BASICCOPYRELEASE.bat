:: mkdir "$(TargetDir)res"
:: xcopy "$(SolutionDir)res" "$(TargetDir)res" /E /I /Y

:: en eventos posteriores a la compilacion
:: $(ProjectDir)BASICCOPY.bat "$(TargetDir)" "$(SolutionDir)"

:: C:\Users\Administrador\Desktop\repo\Plataformer\Plataformer\lib\SFML-2.5.1\bin

echo copiando archivos...

echo %1
echo %2


mkdir "%1res"
xcopy "%2res" "%1res" /E /I /Y

copy "%2lib\SFML-2.5.1\bin\sfml-window-2.dll" "%1" /y
copy "%2lib\SFML-2.5.1\bin\sfml-graphics-2.dll" "%1" /y
copy "%2lib\SFML-2.5.1\bin\sfml-system-2.dll" "%1" /y
copy "%2lib\STP\bin\STP.dll" "%1"
copy "%2lib\STP\bin\zlib.dll" "%1"
echo copiados