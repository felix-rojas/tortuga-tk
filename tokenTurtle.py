from tkinter import *
from typing import NamedTuple
import re

# each token has a type, value, line and column
class Token(NamedTuple):
    type: str
    value: str
    line: int
    column: int

# lexical scanner finds tokens and invalid characters
def tokenize(code):
    keywords = {'ade', # moves forward 
                'atr', # moves backward
                'izq', # rotates left
                'der', # rotates right
                'rep', # repeat instructions
                'col'  # specify color
                }
    
    lone_keywords = {
                'sid', # puts pen down to draw
                'nod', # puts pen up to avoid drawing
                'brr', # clear canvas
                'cnt', # center turtle
    }

    token_specification = [
        ('NUMBER',   r'[1-9][0-9]*'),  # Integer
        ('OPEN_BRACKET',   r'\['),     # Open bracket
        ('CLOSED_BRACKET',   r'\]'),   # Close Bracket
        ('NEWLINE',  r'\n'),           # Line endings
        ('ID',       r'[A-Za-z]+'),    # Identifiers
        ('SKIP',     r'[ \t]+'),       # Skip over spaces and tabs
        ('MISMATCH', r'.'),            # Any other character
    ]
    # joins all the tokens with OR
    tok_regex = '|'.join('(?P<%s>%s)' % pair for pair in token_specification)
    line_num = 1
    line_start = 0

    for matchingOuputs in re.finditer(tok_regex, code):
        kind = matchingOuputs.lastgroup
        value = matchingOuputs.group()
        column = matchingOuputs.start() - line_start
        if kind == 'NUMBER':
            value = int(value)
        elif kind == 'ID' and value in keywords:
            kind = 'KEYWORD'
        elif kind == 'ID' and value in lone_keywords:
            kind = 'LONE_KEYWORD'
        elif kind == 'ID' and value not in keywords:
            raise RuntimeError(f'{value!r} unexpected string on line {line_num}')
        elif kind == 'NEWLINE':
            value = 'NEWLINE'
            line_start = matchingOuputs.end()
            line_num += 1
            continue
        elif kind == 'SKIP':
            continue
        elif kind == 'MISMATCH':
            raise RuntimeError(f'{value!r} unexpected on line {line_num}')
        yield Token(kind, value, line_num, column)

statements = '''ade 15
                atr 12
                izq 1
                der 2
                sid 
                nod 
                brr 
                cnt 
                col'''

for token in tokenize(statements):
    print(token)



