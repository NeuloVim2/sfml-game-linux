### Build project

Create or go to build folder
`cd builder/linux-debug`

Build project
`cmake --build .` 

### Execute test
`cd builder/linux-debug`

Run tests
`ctest .`

For Linux, install libs
`sudo apt update`
`sudo apt install \`
   `libxrandr-dev \`
    `libxcursor-dev \`
    `libudev-dev \`
    `libopenal-dev \`
    `libflac-dev \`
    `libvorbis-dev \`
    `libgl1-mesa-dev \`
    `libegl1-mesa-dev \`
    `libdrm-dev \`
    `libgbm-dev `