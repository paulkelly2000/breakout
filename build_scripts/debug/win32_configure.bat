
if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

if not exist ..\..\build\makefiles (
	mkdir ..\..\build\makefiles
)

pushd ..\..\build\debug
rem cmake -G"Visual Studio 14 2015 Win64" ../..
cmake -G"Visual Studio 17 2022" ../..
popd

rem pushd ..\..\build\makefiles
rem cmake -G"Unix Makefiles" ../..
rem popd
