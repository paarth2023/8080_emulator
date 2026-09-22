# Tutorial for loading 8080/Z80 tests that need a CP/M stub

First off: implementing a basic memory map. A fully read/write array of size `0x10000` should suffice. Make sure to load the ROM starting at address 0x100, and initializing your pc to 0x100

Second of all: implementing the necessary cp/m calls for the rom to print stuff to the terminal

A CALL to 5 means that the program is attempting to start a CP/M system call.
How these system calls work:

-Before calling 5, the program places the number of the syscall it wants to start into register `c` and the parameters to the syscall in register `DE`

The test programs use two syscalls:
    - One that happens when c == 2. This syscall prints the character that corresponds to the ASCII code stored in register e.

     - One syscall that happens when c == 9. This syscall prints all characters stored in memory starting from address (DE), and ending when the character "$" is found.

To handle the syscalls you can do something like this in yer main loop (not optimal but you're not planning on emulating the OS so who cares)

```py
 if (pc == 5):
    if (c == 2):
        print (e) 
    elif (c == 9):
         i = DE
         while (mem.read (i) != "$"):
              print (mem.read(i))
              i++
```

You'll also have to patch in the opcode "0xC9" (RET) at address 0x7, so that your interpreter will return from the syscall