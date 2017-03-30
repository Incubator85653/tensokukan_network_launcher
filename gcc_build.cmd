@cd /d %~dp0

@echo Generate icon resource
@echo.
windres gcc_tensokukan_network_launcher.rc -O coff -o gcc_tensokukan_network_launcher.res
@echo.

@echo Create exe
@echo.
g++ -std=c++11 -D_UNICODE -DUNICODE -o gcc_Build\tensokukan_network_launcher.exe *.cpp *.res -lShlwapi
@echo.

@exit