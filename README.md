# CANSART


CANSART is a Application Layer for interfacing a Serial Bus (UART).

The use of the library is focused for fast interface between two machines, where you set an Database which will be the same for both ends (MCU-MCU; MCU-PC), this allows you to run an update function and the database will automatically update on both machines.

MAKE SURE WHEN YOU ARE WORKING WITH TWO MICROCONTROLLERS OU MICROPROCESSORS TO CHECK THE SLAVE_MODE ON CANSART_DB.H, YOU HAVE TO CHANGE IT FOR SLAVE AND MASTER.

Features:
- Arduino Compatibility;
- STM32 Compatibility;
- LabView Compatibility (needs python 3.6 on your machine);
- Non blocking, (most of the execution does not run on loops) -> This means message transaction between ends wont affect much of your performance, however this is will be more improved.
- Message IDs, Write/Read only IDs, helps on code reading and organization;
- One of the best: Multiplatform -> You can design your code for one unit, and if you need to change for any other architecture, you can simply import the library and change the database, it will be fully compatible.

Latest Updates:

v2.0

- One library for all platforms;
- One Labview Example with read/write operations;
- Faster read/write operations;
- No support for PIC32 yet;
- No support for Renesas yet;

Currently Supported:
- STM32 MCUs;
- Most arduino platforms with USART;

Each folder has instructions for use, pay attention to it, it is easy.