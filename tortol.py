from tkinter import *

top = Tk()


C = Canvas(top, bg = "white", height = 500, width = 500)
coord = 10, 50, 240, 210
arc = C.create_arc(coord, start = 0, extent = 150, fill = "red")
line = C.create_line(10,10,200,200,fill = 'white')
C.pack()

L1 = Label(top, text = "Comando")
L1.pack(side = LEFT)
E1 = Entry(top, bd = 5)
E1.pack(side = RIGHT)

top.mainloop()
