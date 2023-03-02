# Avance en programación

```python
from tkinter import *
import re

### Using the regex library from python
# pattern = re.compile()


def showCommand (user_inputs) :
    print(user_inputs.get("1.0", "end"))

# Erase whole canvas canvas.delete("all")

# Global variables
canvas_height = 500
canvas_width  = 500 
canvas_center = [canvas_width/2, canvas_height/2]


## window instance
top = Tk(className = "Tortuga")

## drawing canvas
C = Canvas(top, bg = "white", height = canvas_height, width = canvas_width)

### cursor shape WIP
# cursor_size = 10
# cursor_points = [canvas_center[0] + cursor_size, canvas_center[1] + cursor_size, 
#                 canvas_center[0] + cursor_size, canvas_center[0],
#                 canvas_center[0] - cursor_size, canvas_center[0]] 
# C.create_polygon(cursor_points, outline = "blue", fill = "orange")

C.pack()

# label for input
L1 = Label(top, text = "Comando")
L1.pack(side = LEFT)

# text
userInputs = Text(top)

# input field
sendButton = Button(top, text="Get input", command=showCommand(userInputs) )
sendButton.pack(side = RIGHT)

E1 = Entry(top, bd = 5, textvariable = userInputs)
E1.pack(side = RIGHT)

## Line coordinates test to define function
x1 = canvas_center[0]
y1 = canvas_center[1]
x2 = 0
y2 = 0
coordinates = [x1,y1,x2,y2]
C.create_line(x1,y1,0,10, fill="green")

# window loop
top.mainloop()

```

## To-do's

1. Define line drawing function
2. Define clear canvas function (tk("delete"))
3. Reposition shape (use canvas center coordinates)
4. Cursor shape

### Lista de comandos a definir

`ade` 
Mueve el cursor adelante *n* pixeles
regex: /ade \d+/

`atr`
Mueve el cursor atrás *n* pixeles
regex: /atr \d+/

`der`
Rota el cursor hacia la derecha *n* grados
regex: /der \d+/

`izq`
Rota el cursor hacia la izquierda *n* grados
regex: /izq \d+/

`cnt`
Regresa el cursor al centro
regex: /cnt/

`brr`
Borra la pantalla
regex: /brr/

`sid`
Sí dibuja en la pantalla
regex: /sid/

`nod`
No dibuja en la pantalla
regex: /nod/

`rep`
Repite la instrucciones
regex: /rep \[{1}\d+\]{1}/

`col`
Color *n* donde n va del 1 - 10
regex: col (10|[1-9])

# Secuencias logo-turtle

## Letter L

fd 10 rt 90 fd 2 rt 90 fd 8 lt 90 fd 4 rt 90 fd 2 rt 90 fd 6 rt 90

## Letter T

cs fd 8 lt 90 fd 4 rt 90 fd 4 rt 90 fd 12 rt 90 fd 4 rt 90 fd 4 lt 90 fd 8 rt 90 fd 4

## Letter F

cs fd 8 rt 90 fd 5 rt 90 fd 2 rt 90 fd 3 lt 90 fd 1 lt 90 fd 2 rt 90 fd 2 rt 90 fd 2 lt 90 fd 3 rt 90 fd 2 rt 90

## Labyrinth

tiempo: 40 seg

cs repeat 2[fd 15 rt 90] fd 15 rt 45 fd 15 rt 60 fd 8 rt 40 fd 9 rt 45 fd 15 lt 100 fd 10 lt 90 fd 20

## Golf

5 shots

cs rt 75 fd 18 lt 15 bk 45 lt 45 fd 28 rt 115 fd 40 lt 210 fd 30

# square

repeat 4[fd 10 rt 90]

# pentagon

repeat 5[fd 10 rt 72]

# hexagon

repeat 6[fd 10 rt 60]

# double square

repeat 4[fd 10 rt 90]
pu fd 15 rt 90
pd bk 5
fd 20 rt 90
fd 20 rt 90
fd 20 rt 90 fd 20

# flowers

lt 45
fd 12
pc 5
repeat 72[fd 5 bk 5 lt 5]

ct
fd 12
pc 2
repeat 72[fd 5 bk 5 lt 5]

ct
rt 45
fd 12
pc 8
repeat 72[fd 5 bk 5 lt 5]