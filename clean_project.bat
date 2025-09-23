@echo off
echo Cleaning Intermediate, Saved and DerivedDataCache folders...
for /d %%x in (*) do (
    if exist "%%x\Intermediate" rd /s /q "%%x\Intermediate"
    if exist "%%x\Saved" rd /s /q "%%x\Saved"
    if exist "%%x\DerivedDataCache" rd /s /q "%%x\DerivedDataCache"
)
echo Done!
pause