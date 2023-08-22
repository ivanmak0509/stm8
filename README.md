# stm8

Template to compile any STM8 without any peripheral libraries, although I have provided bare-metal headers for the stm8l101f2.


## How to use

Install required software from [here](https://www.codementor.io/@hbendali/getting-started-with-stm8-development-tools-on-gnu-linux-zu59yo35x).

Unfortunately I couldn't get stm8flash to work (atleast for the stm8l101f2), so the only way to flash as of right now is to open a debugging session with openocd and stm8-gdb and use the `load` command:

``` sh
openocd -f openocd.cfg
stm8-gdb # in another shell window
```

then from within gdb, run `load`. After that you'll probably have to manually reset the stm8, either through nrst or power cycle.

## Developing in WSL

You can attach your st-link to WSL using the `attach.sh` script. You might have to run it 
first through an elevated powershell (depends on your elevation when you invoked `wsl`).
