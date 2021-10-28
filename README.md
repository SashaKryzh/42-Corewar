# Corewar
Corewar is a programming game in which two or more programs run on a simulated computer with the goal of terminating every other program. Read more on [Wikipedia](https://en.wikipedia.org/wiki/Core_War).

**Final grade:** 125/100 ✅

![Preview](/resources/preview.gif)

The project consists of two programs: Assembler and Virtual machine.
* Assembler: a program that will compile warriors into byte code.
* Virtual machine: an "arena" in which warriors will be executed.

**It is forbidden to use any library except for the [libft](https://github.com/SashaKryzh/libft.git) that was written by ourselves.**

Also, this is a group project and requires a team of 4 persons. My part was to write the Virtual machine. And my teammates wrote the Assembler and the battle visualization (bonus task).

## Usage
Compile all from the main folder:
> make

Then compile your wariors:
> ./asm/asm [warior_file.s ...]

Then start the battle:
> ./corewar/corewar [-nc graphical mode] [compiled_warior_file.cor ... (up to 4)]

## Example
You can find different warriors in the "warriors" folder.

Compile programs:
> make

![Compiling](/resources/compiling.jpg)

Compile wariours:
> ./asm/asm warriors/slider2.s warriors/turtle.s warriors/toto.s warriors/fluttershy.s

![Compiling wariours](/resources/compiling_warriors.jpg)

Start the battle with the graphical mode:
> ./corewar/corewar -nc warriors/slider2.cor warriors/turtle.cor warriors/toto.cor warriors/fluttershy.cor

**The result can be seen at the [beginning](#corewar).**