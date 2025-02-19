# Assembly notes

I never looked deep into x86 assembly before, I want to note some things
Using wikipedia for brief overview:
https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture

Negative numbers are two's complement...


## Immediates
### AT&T Syntax
``$`` precedes any immediate values.
Example: 
```
addl $0x04, %eax
```

hex 4 added to eax register

## Registers

What are all the registers?
| Register Name   |  Basic Description  | 64-bit | 32-bit | 16-bit | High 8-bit | Low 8-bit |
| --------|-------- | -------- | ------- | ------ | ----- | ----|
| Accumulator   | Used for sums/results: constants with Accumulator are 1-byte opcodes | RAX | EAX | AX | AH | AL |
| Base   | Used for reference pointer to data | RBX | EBX | BX | BH | BL |
| Counter   | Used in Shift/Rotate instructions and loops   | RCX | ECX | CX | CH | CL |
| Stack Pointer   | Pointer to top of stack   | RSP | ESP | SP | -- | SPL |
| Base Pointer   | Pointer to bottom/base of stack   | RBP | EBP | BP | -- | BPL |
| Destination Index   | Pointer to destination in stream operations | RDI | EDI | DI | -- | DIL |
| Source Index   | Pointer to source in stream operations | RSI | ESI | SI | -- | SIL |
| Data Register   | Data used in arithmetic or IO ops   | RDX | EDX | DX | DH | DL |

Segment registers? never heard of those
SS = Stack Segment
CS = Code Segment
DS = Data Segment
ES = Extra Segment
FS = More extra data segment
GS = More More Extra Data Segment

Instruction pointer: EIP (only readable in stack after call instruction)

EFlags register: collection of bits storing results of operation in the processor

31	30	29	28	27	26	25	24	23	22	21	20	19	18	17	16
0	0	0	0	0	0	0	0	0	0	ID	VIP	VIF	AC	VM	RF
15	14	13	12	11	10	9	8	7	6	5	4	3	2	1	0
0	NT	IOPL	OF	DF	IF	TF	SF	ZF	0	AF	0	PF	1	CF

0.	CF : Carry Flag. Set if the last arithmetic operation carried (addition) or borrowed (subtraction)
             a bit beyond the size of the register. This is then checked when the operation is followed
             with an add-with-carry or subtract-with-borrow to deal with values too large for just one register to contain.
2.	PF : Parity Flag. Set if the number of set bits in the least significant byte is a multiple of 2.
4.	AF : Adjust Flag. Carry of Binary Code Decimal (BCD) numbers arithmetic operations.
6.	ZF : Zero Flag. Set if the result of an operation is Zero (0).
7.	SF : Sign Flag. Set if the result of an operation is negative.
8.	TF : Trap Flag. Set if step by step debugging.
9.	IF : Interruption Flag. Set if interrupts are enabled.
10.	DF : Direction Flag. Stream direction. If set, string operations will decrement their pointer rather than incrementing it, reading memory backwards.
11.	OF : Overflow Flag. Set if signed arithmetic operations result in a value too large for the register to contain.
12-13.	IOPL : I/O Privilege Level field (2 bits). I/O Privilege Level of the current process.
14.	NT : Nested Task flag. Controls chaining of interrupts. Set if the current process is linked to the next process.
16.	RF : Resume Flag. Response to debug exceptions.
17.	VM : Virtual-8086 Mode. Set if in 8086 compatibility mode.
18.	AC : Alignment Check. Set if alignment checking of memory references is done.
19.	VIF : Virtual Interrupt Flag. Virtual image of IF.
20.	VIP : Virtual Interrupt Pending flag. Set if an interrupt is pending.
21.	ID : Identification Flag. Support for CPUID instruction if can be set.
            
### AT&T Syntax
``%`` precedes any registers.
Example: 
```
addl $0x04, %eax
movl %eax, $0x00(%esi, %ecx, 4) # offset(Base, index, multiplier)
```

The add instruction adds an immediate to eax register,
the movl stores the data at eax into the location for the location computed
as [offset + base + index * multiplier]



## Addressing
Byte order is little-endian
| B0 | B1 | B2 | B3 |

Ox1BA583D4 -> OxD4 Ox83 OxA5 Ox1B
