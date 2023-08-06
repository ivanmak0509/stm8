# stm8
Template to compile any STM8 without any peripheral libraries

## How to use

Install required software from [here](https://www.codementor.io/@hbendali/getting-started-with-stm8-development-tools-on-gnu-linux-zu59yo35x).

To compile, run `make`, to flash `make flash` and to open a debugging session `make debug`.
If changing target keep in mind you must also change the target in the `flash` and `debug` commands in the makefile.

Flashing and debugging will be tested soon

## Devloping in WSL

You can attach your st-link to WSL using the `attach.sh` script. You might have to run it 
first through an elevated powershell (depends on your elevation when you invoked `wsl`).
