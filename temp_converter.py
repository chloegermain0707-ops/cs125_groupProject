#CS118 HW6
#Chloe Germain

def c_to_f(celsius):
    '''convert celsius temp to fahrenheit'''
    fahrenheit = (celsius * 9/5) + 32
    return(fahrenheit)


def f_to_c(fahrenheit):
    '''convert fahrenheit temp to celsius'''
    celsius = (fahrenheit - 32) * 5/9
    return(celsius)

def c_to_k(celsius):
    '''convert celsius temp to kelvin'''
    kelvin = celsius+273.15
    return(kelvin)

