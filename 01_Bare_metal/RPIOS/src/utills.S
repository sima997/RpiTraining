.globl delay 
delay:
    subs x0, x0, #1 //first argument loaded into x1, second x2, etc.
    bne delay
    ret

.globl put32
put32:
    str w1, [x0] //wx represents lower 32-bit of xx register
    ret

.globl get32
get32:
    ldr w0, [x0] 
    ret