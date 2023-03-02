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
