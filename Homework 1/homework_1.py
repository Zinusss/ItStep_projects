from tkinter import *
import tkinter as tk  
root = tk.Tk()
root.title('Записник звичок')
list_habit = tk.Listbox(root)
input_habit = Entry()
input_habit_text = Label(text='Введіть звичку:')
most_popular = Label()
habits_history = []
numbers_list = []
history_label = Label(text="Ваша історія:")
history = Text(root, height=12, width=40)
habits_data = {}
habits_count = 0
current_green = 0
statistic_label = Label(text="Ваша статистика:")
statistic = Text(root, height=12, width=40)
statistic.configure(state='disabled')
history.configure(state='disabled')
def add_habits():
    if(input_habit.get() != ''):
        list_habit.insert(tk.END, input_habit.get())
    habits_data[input_habit.get()] = 0
def complete_habit():
    global habits_count
    global current_green
    try:
        list_habit.itemconfigure(
        current_green, 
        background='white', 
        ) 
        habits_history.append(list_habit.get(list_habit.curselection()))
        habits_data[list_habit.get(list_habit.curselection())] += 1
        item_number = list_habit.curselection()[0]
        list_habit.itemconfigure(
        item_number, 
        background='green', #Я зеленим позначаю останню виконану звичку щоб весь список не був зелений
        )
        current_green = item_number
        history.configure(state='normal')
        statistic.configure(state='normal')
        statistic.delete(1.0, END)
        history.delete(1.0, END)
        for i in habits_history:
            history.insert(1.0, f"{i} \n") 
        history.configure(state='disabled')
        habits_count += 1 
        for i in habits_data:
            numbers_list.append(habits_data[i])
            most_popular_count = max(numbers_list)
            if(i != ''):
                statistic.insert(1.0, f'{i}: {habits_data[i]} \n')
        most_popular_name = (list (habits_data.keys())[list(habits_data.values()).index(most_popular_count)])
        most_popular.config(text= f"Найпопулярніша звичка: {most_popular_name}, к-сть раз {most_popular_count}")
        statistic.insert(1.0, f'Загальна к-сть виконаних звичок: {habits_count} \n')
        statistic.configure(state='disabled')
    except:
        return
def delete_habits():
    try:
        list_habit.delete(list_habit.curselection())
        del habits_data[list_habit.get(list_habit.curselection())] 
    except:
        return
add_habit = Button(text = 'Додати звичку', command=add_habits)
complete_habit_button = Button(root, text = 'Виконати звичку', command=complete_habit)
delete_habit = Button(text = 'Видалити звичку', command= delete_habits)
most_popular.pack()
input_habit_text.pack()
input_habit.pack()
list_habit.pack()
add_habit.pack()
complete_habit_button.pack()
delete_habit.pack()
statistic_label.pack()
statistic.pack()
history_label.pack()
history.pack()
root.mainloop()