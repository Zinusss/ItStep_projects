first_number = int(input(""))
second_number = int(input(""))
logical_operator = input("")
result = 0
def calculate(first_number, second_number, logical_operator):
    match logical_operator:
        case "+":
            result = first_number + second_number
        case "-":
            result = first_number - second_number
        case "*":
            result = first_number * second_number
        case "/":
            result = first_number / second_number
    return result
print(calculate(first_number, second_number, logical_operator))
            
