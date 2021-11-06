#!/usr/bin/env python
'''
CodeWars 2013

Morse Code Palindrom
'''
import sys

alphabet = {'A': '.-',
            'B': '-...',
            'C': '-.-.',
            'D': '-..',
            'E': '.',
            'F': '..-.',
            'G': '--.',
            'H': '....',
            'I': '..',
            'J': '.---',
            'K': '-.-',
            'L': '.-..',
            'M': '--',
            'N': '-.',
            'O': '---',
            'P': '.--.',
            'Q': '--.-',
            'R': '.-.',
            'S': '...',
            'T': '-',
            'U': '..-',
            'V': '...-',
            'W': '.--',
            'X': '-..-',
            'Y': '-.--',
            'Z': '--..',
            }


def convert_to_morse(line):
    retval = ''
    for char in line.upper().replace(' ', ''):
        morse = alphabet[char]
        retval += morse
    return retval


def is_palindrome(morse):
    size = len(morse)
    half = int(size / 2)
    left = morse[:half]
    right = morse[-half:]
    return left == right[::-1]


def get_output(is_palindrome):
    if is_palindrome:
        return 'is a Morse code palindrome'
    else:
        return 'is not a Morse code palindrome'


if __name__ == '__main__':
    for linen in sys.stdin:
        line = linen.rstrip()
        if line == '.':
            break

        morse = convert_to_morse(line)
        pal = is_palindrome(morse)
        out = get_output(pal)
        print (line, out)
