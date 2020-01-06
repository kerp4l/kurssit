# sys_print.py

import sys

def printf(format, *args):
	sys.stdout.write(format % args)

printf("Foobar!\n")

# eof
