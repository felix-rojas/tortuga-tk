# Test file for regex patterns
# Using the regex library from python
# this is the library python has by default, full docs here https://docs.python.org/3/library/re.html#re.findall
import re

# test patterns
notAPositiveIntegerPattern = re.compile("[^0-9]+")
positiveIntegerPattern = re.compile("[0-9]+")
binaryPattern = re.compile("[0-1]+")
fullNamePattern = re.compile("[A-Za-z]")
initialsNamePattern = re.compile("[A-Z]")
emailPattern = re.compile("[\w]+@+[\w]+\.[\w]{2,3}")

# re library does not accept numbers, only strings or "byte-like objects"
# actualNumber=12
# print(re.search(positiveIntegerPattern, actualNumber))


# returns: <re.Match object; span=(0, 2), match='12'>
stringNumber="12"
print("re.search(positiveIntegerPattern, stringNumber): ", re.search(positiveIntegerPattern, stringNumber))


# returns: <re.Match object; span=(0, 2), match='12'>
# it only does it for the FIRST match
stringNumberSpaces="12       1239832      123123 0    "
print("re.search(positiveIntegerPattern, stringNumberSpaces): ", re.search(positiveIntegerPattern, stringNumberSpaces))
print("re.findall(positiveIntegerPattern, stringNumberSpaces): ", re.findall(positiveIntegerPattern, stringNumberSpaces) )
print("re.match(positiveIntegerPattern, stringNumberSpaces): ", re.match(positiveIntegerPattern, stringNumberSpaces) )

# returns: None
# it looks for the entire expression to match
print("re.fullmatch(positiveIntegerPattern, stringNumberSpaces): ", re.fullmatch(positiveIntegerPattern, stringNumberSpaces))

# returns: array of strings
# it looks for the objects between those who match the given pattern

# ['', '       ', '      ', ' ', '    ']
print("re.split(positiveIntegerPattern, stringNumberSpaces): ", re.split(positiveIntegerPattern, stringNumberSpaces))

# ['12', '1239832', '123123', '0', '']
print("re.split(notAPositiveIntegerPattern, stringNumberSpaces): ", re.split(notAPositiveIntegerPattern, stringNumberSpaces))

# extracts all chars that follow the regex pattern
print('''re.findall(fullNamePattern, "J23123uan Po3424kemon L1212o1412ng 22"): ''', re.findall(fullNamePattern, "J23123uan Pa3424sc4ac1111io!#!!$ Ru1212i1412z 22"))
print('''re.findall(initialsNamePattern, "Juan Pokemon Long"): ''', re.findall(initialsNamePattern, "Juan Pedro Longaniza Pascacio"))

# split extracts all chars that do not follow the provided regex pattern
# which is to say, it splits characters when they have a specific pattern
print('''re.split(emailPattern, "a01201946@tec.mx felix@tec.mx feliadkjqwhfx@tec.maaax")''', (re.split(emailPattern, "a01201946@tec.mx felix@tec.mx feliadkjqwhfx@tec.maaax")))
print('''re.findall(emailPattern, "a01201946@tec.mx felix@tec.mx feliadkjqwhfx@tec.maaax")''', (re.findall(emailPattern, "a01201946@tec.mx felix@tec.mx feliadkjqwhfx@tec.maaax")))
print('''re.search(emailPattern, "a01201946@tec.mx felix@tec.mx")''', (re.search(emailPattern, "a01201946@tec.mx felix@tec.mx")))
print('''re.fullmatch(emailPattern, "a01201946@tec.mx felix@tec.mx")''', (re.fullmatch(emailPattern, "a01201946@tec.mx felix@tec.mx")))

print(re.search(binaryPattern, "30123123123 2"))
print(re.match(binaryPattern, "30123123123 2"))
print(re.search(binaryPattern, "01010101010100 011101010"))
print(re.findall(binaryPattern, "01010101010100 011101010"))