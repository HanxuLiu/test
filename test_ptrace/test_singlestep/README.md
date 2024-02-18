## compile command

gcc test_step.c -o test_step
gcc test_stepper.c -o test_stepper
gcc test_trace.c -o test_trace

## result 1

lhx@ubuntu:~/test/test_ptrace/test_singlestep$ ./test_step demo-asm/hello
Child stopped: 5
Hello, world!
Child exited: 1
Detaching
counter = 7

## result 2

lhx@ubuntu:~/test/test_ptrace/test_singlestep$ ./test_stepper demo-asm/hello
counter = 1, pc = 0x00401000, insn = 0x00000eba
counter = 2, pc = 0x00401005, insn = 0x402000b9
counter = 3, pc = 0x0040100a, insn = 0x000001bb
counter = 4, pc = 0x0040100f, insn = 0x000004b8
counter = 5, pc = 0x00401014, insn = 0x01b880cd
Hello, world!
counter = 6, pc = 0x00401016, insn = 0x000001b8
counter = 7, pc = 0x0040101b, insn = 0x000080cd
the child executed 7 instructions

## result 3

lhx@ubuntu:~/test/test_ptrace/test_singlestep$ ./test_trace demo-asm/hello
[10165] debugger started
[10166] target started. will run 'demo-asm/hello'
[10165] icounter = 1.  EIP = 0x00401000.  instr = 0x00000eba
[10165] icounter = 2.  EIP = 0x00401005.  instr = 0x402000b9
[10165] icounter = 3.  EIP = 0x0040100a.  instr = 0x000001bb
[10165] icounter = 4.  EIP = 0x0040100f.  instr = 0x000004b8
[10165] icounter = 5.  EIP = 0x00401014.  instr = 0x01b880cd
Hello, world!
[10165] icounter = 6.  EIP = 0x00401016.  instr = 0x000001b8
[10165] icounter = 7.  EIP = 0x0040101b.  instr = 0x000080cd
[10165] the child executed 7 instructions
