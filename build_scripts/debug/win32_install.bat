if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

pushd ..\..\build\debug
rem 1.x conan install -g cmake_multi --build=missing -s build_type=Debug -if ./conan ../..
rem 1.x conan imports -imf . -if ./conan ../..
rem updated for 2.x
rem conan profile detect --force

where cmake
cmake --version
python -c "import shutil; print(shutil.which('cmake'))"
conan profile show -pr default



rem conan install ../.. --output-folder=build/Debug --build=missing -s build_type=Debug

conan install ../.. --output-folder=build/Debug --build=missing ^
  -s build_type=Debug ^
  -c tools.cmake:cmake_program="C:/Program Files/CMake/bin/cmake.exe"

rem - original cmake -S ../.. -B build/Debug -DCMAKE_TOOLCHAIN_FILE=build/Debug/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake -S ../.. -B . -DCMAKE_TOOLCHAIN_FILE=build/Debug/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
popd
