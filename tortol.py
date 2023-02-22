from tkinter import *

# window instance
top = Tk()

# drawing canvas
C = Canvas(top, bg = "white", height = 500, width = 500)
C.pack()

# label for input
L1 = Label(top, text = "Comando")
L1.pack(side = LEFT)

# text
userInputs = Text(top)

# input field
sendButton = Button(top, text="Get input")
sendButton.pack(side = RIGHT)

E1 = Entry(top, bd = 5, textvariable = userInputs)
E1.pack(side = RIGHT)


# window loop
top.mainloop()
