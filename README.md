# stm8

Template to compile any STM8 without any peripheral libraries.


## How to use

Install required software from [here](https://www.codementor.io/@hbendali/getting-started-with-stm8-development-tools-on-gnu-linux-zu59yo35x).

To compile, run:

``` sh
make
```

to flash:

``` sh
make flash
```

and to open a debugging session:

``` sh
make debug
```
Debugging right now is broken (atleast for the chip I'm testing: `stm8l101f2p6`), due to sdcc creating a weird elf file.
If you decide to change target the `flash` and `debug` commands must be updated in the makefile.

## Developing in WSL

If developing in `WSL`, you can quickly attach you'r st-link by running:

``` sh
./attach.sh
```

if multiple st-links are connected at once, this script will bonk.
