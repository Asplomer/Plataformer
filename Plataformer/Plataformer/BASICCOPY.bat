:: mkdir "$(TargetDir)res"
:: xcopy "$(SolutionDir)res" "$(TargetDir)res" /E /I /Y

:: en eventos posteriores a la compilacion
:: $(ProjectDir)BASICCOPY.bat "$(TargetDir)" "$(SolutionDir)"

echo copiando archivos...

mkdir "%1res"
xcopy "%2res" "%1res" /E /I /Y

echo copiados