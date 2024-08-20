cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release -S . -B build

cmake --build build --config Release

.\build\Release\MyProject.exe
