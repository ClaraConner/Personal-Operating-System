# Personal-Operating-System
Creating my own personal operating system. In Progress. . .

## How to Run
This program was created in a Linux/UNIX environment <br/>
  Step One:   Open main.c and notice that a comment indicates where to change the input file name <br/>
  Step Two:   Change the file name to your desired file ( I provide two example files ) <br/>
  Step Three: Run the Makefile by typing "make" in terminal <br/>
  Step Four:  Observe the program executing the input file. The first 20 spots of memory will be printed <br/>

## About My OS

### Phase One

main.c     - This file declares the input file and simulates the clock cycle by using a loop to call the CPU.

disk.c     - This file reads the instructions from the input file and translates the instructions to their opcodes. 
             It then stores them in memory.

memory.c   - This file maintains the memory of the OS. It can read from and write to memory.

cpu.c      - This file reads the opcodes from the memory and executes their functions.

Phase One can be tested using inputFile.txt and inputFile2.txt

## Compatible Instructions

Here is a list of instructions compatible with my OS:

<table>
  <tr>
    <th>Instruction</th>
    <th>OPCODE</th>
    <th>Argument</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>exit</th>
    <td>0</th>
    <td>None</th>
    <td>Signals the end of the current program</th>
  </tr>
  <tr>
    <td>load_const</th>
    <td>1</th>
    <td>int</th>
    <td>Load the integer given by int into the AC register</th>
  </tr>
  <tr>
    <td>move_from_mbr</th>
    <td>2</th>
    <td>None</th>
    <td>Move the integer in the MBR register into the AC register</th>
  </tr>
  <tr>
    <td>move_from_mar</th>
    <td>3</th>
    <td>None</th>
    <td>Move the integer in the MAR register into the AC register</th>
  </tr>
  <tr>
    <td>move_to_mbr</th>
    <td>4</th>
    <td>None</th>
    <td>Move the integer in the AC register into the MBR register</th>
  </tr>
  <tr>
    <td>move_to_mar</th>
    <td>5</th>
    <td>None</th>
    <td>Move the integer of the AC register into the MAR register</th>
  </tr>
  <tr>
    <td>load_at_addr</th>
    <td>6</th>
    <td>None</th>
    <td>Load an integer in memory using the address in the MAR register into the MBR register</th>
  </tr>
  <tr>
    <td>write_at_addr</th>
    <td>7</th>
    <td>None</th>
    <td>Write the integer in the MBR register to memory at the address in the MAR register</th>
  </tr>
  <tr>
    <td>add</th>
    <td>8</th>
    <td>None</th>
    <td>Add the contents of the MBR register to the AC register</th>
  </tr>
  <tr>
    <td>multiply</th>
    <td>9</th>
    <td>None</th>
    <td>Multiply the contents of the MBR register by the AC register and store the result in the AC register</th>
  </tr>
  <tr>
    <td>and</th>
    <td>10</th>
    <td>None</th>
    <td>Perform the logical AND operation between the MBR register and the AC register. 0 is False, all other numbers are True. Store the result in the AC register </td>
  </tr>
  <tr>
    <td>or</th>
    <td>11</th>
    <td>None</th>
    <td>Perform the logical OR operation between the MBR register and the AC register. 0 is False, all other numbers are True. Store the result in the AC register.</th>
  </tr>
  <tr>
    <td>ifgo</th>
    <td>12</th>
    <td>Addr</th>
    <td>If the contents of the AC register is not 0, then load the integer (addr - 1) into the PC register. Otherwise, do nothing </td>
  </tr>
  <tr>
    <td>sleep</th>
    <td>13</th>
    <td>None</th>
    <td>Do Nothing</th>
  </tr>
  <tr>
    <td>//</th>
    <td>None</th>
    <td>None</th>
    <td>A Comment! Ignore</th>
  </tr>
</table>

## Working On Next:
Creating the scheduler. This OS will use Round Robin Scheduling. I may implement more scheduling styles in the future.



Thanks!! <3



