#About: This uses the Calculator functions that are expoed from C++


import Calculator


def GetOperation(): 
    #Valid operations are +, -, *, /
    
    toRepeat = True
    while(toRepeat):
        
        #Get user input - operation, numbers
        print "\nPress + for addition\nPress - for subtraction\nPress * for multiplication\nPress / for division\n\n"
        inputOperation = raw_input("Please enter your choice: ");            

        if inputOperation in ['+','-','*','/']:
            #Valid operation 
            toRepeat = False
            return inputOperation
        else:
            print "Invalid input! Please enter valid operation"
            toRepeat = True    


def GetNumber(msg): 
    #Get float number
    
    toRepeat = True
    while(toRepeat):    
        try:
            number = float(raw_input(msg))
            return number
        except ValueError, e:
            print "Invalid input! Please enter number ..."
            
            
def Calculate():
    #Get user input and perform opration
    
    inputOperation = GetOperation()
    
    number1 = GetNumber("Enter 1st number:")
    number2 = GetNumber("Enter 2nd number:")
        
    #Create calculator object and perform operation  
    obj = Calculator.MyCalculator(number1, number2)
    print
    if inputOperation == '+': 
        obj.Add()
    elif inputOperation == '-': 
        obj.Subtract()
    elif inputOperation == '*': 
        obj.Multiply()
    elif inputOperation == '/': 
        obj.Divide()    


def Execute():
    
    toRepeat = True
    Calculator.SayAboutApplication() #Print application details
    
    while(toRepeat):
        try:
            Calculate() 
            
            print "\n\nDo you want to continue ?"
            toContinue = raw_input("Press y/Y to continue ..\n")
            if not toContinue in ['y','Y']:
                toRepeat = False
    
        except Exception, e:
            print"Exception occured"
            print "Exception: %s" %str(e)
    
    print "\nThank you for using this application ..."
    raw_input("\nPress any key to exit ...")
    

if __name__ == "__main__":
    Execute()

