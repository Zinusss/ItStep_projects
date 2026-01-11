from tkinter import Tk
from tkinter import *
import random
root = Tk()
number = random.randint(1,100)
text = Label(root, text = " ")
def check_number():
    if(number == int(your_number.get())):
        text.config(text= "Вгадав")
    else:
        text.config(text= "Не вгадав")

your_number = Entry(root)
button = Button(root, text='Вгадати', command=check_number)
your_number.pack()
button.pack()
text.pack()

root.mainloop()
