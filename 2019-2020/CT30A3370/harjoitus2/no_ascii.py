# no_ascii.py

from ctypes import *

libc = CDLL("libc.so.6")

libc.printf("hello everybody\n")

# eof


