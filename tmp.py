from pwn import *
import re

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