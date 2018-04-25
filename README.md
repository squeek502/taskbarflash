# taskbarflash

Simple program to flash the taskbar icon and/or window of the calling console window (e.g. to flash the window from a `.bat` file).

```
Usage: taskbarflash [options] [num_flashes [flash_rate_ms]]

  Options:
    -h, --help          Print this help screen
    -t, --tray          Flash the taskbar icon (default)
    -w, --window        Flash the window caption
    -c, --caption       Alias for --window
    --all               Flash both the taskbar icon and the window caption
```

## Installation
- [Download `taskbarflash.exe` from the releases page](https://github.com/squeek502/taskbarflash/releases/latest)
- To be able to call `taskbarflash` from any `.bat` file, put `taskbarflash.exe` in a directory that is included in your system's [`PATH` environment variable](https://en.wikipedia.org/wiki/PATH_\(variable\)).

## Building
To build taskbarflash, you'll need to install [`cmake`](https://cmake.org) and some version of [Visual Studio](https://www.visualstudio.com/).

### Using `make.bat`
- To build, run `make.bat` (the `.exe` will be in `build/Release`)
- To create a Visual Studio solution, run `make.bat projects` (the `.sln` will be in `build/`)
- To remove all build artifacts, run `make.bat clean`

### Using `cmake-gui`
- Run `cmake-gui`
- Browse to the taskbarflash directory and also set the build directory (typically just add `/build` to the source directory path)
- Click *Configure*
- Select the Generator and hit *Finish*
- Hit Generate and then Open Project to open the project in Visual Studio
- Build the project in Visual Studio as normal

### Using `cmake`
Open a command line in the `taskbarflash` directory and do the following:
```sh
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
If needed, you can specify a [generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) by doing `cmake -G "Visual Studio 14 2015 Win64" ..` instead of `cmake ..`
