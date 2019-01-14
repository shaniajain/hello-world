###############################################################################
# CS 21A Python Programming: Lab #3
# Name: Shania Jain
# Description: Password Verification Program
# Filename: ShaniaJainLab3.py
# Date: 07/25/17
###############################################################################


def main():
    str1 = input("Enter password: ")
    str2 = input("Re-enter password: ")
    
    while str1!=str2:
        print("Passwords do not match. Try again.")
        str1 = input("Enter password: ")
        str2 = input("Re-enter password: ")
        
    check_length(str1, str2)
    check_uppercase(str1, str2)
    check_digits(str1, str2)
    check_lowercase(str1, str2)


def check_length(str1, str2):
    
    #check if password is atleast 8 characters long
    
    chars = len(str1)
    MIN_LENGTH = 8

    if chars >= MIN_LENGTH:
        return
    else:
        print("That password didn't have the required properties.")
        main()
        return

    
def check_uppercase(str1, str2):

    #check if password has atleast one uppercase letter
    
    while str1 == str2:
        for char in str1:
            if char >= "A" and char <= "Z":
                return
        else:
            print("That password didn't have the required properties.")
            main()
            return


def check_digits(str1, str2):

    #check if password has atleast one digit
    
    while str1 == str2:       
        for char in str1:
            if char >= "0" and char <= "9":
                return
        else:
            print("That password didn't have the required properties.")
            main()
            return


def check_lowercase(str1, str2):

    #check if password has atleast one lowercase letter
    
    while str1 == str2:
        for char in str1:
            if char >= "a" and char <= "z":
                print("That pair of passwords will work.")
                return
        else:
            print("That password didn't have the required properties.")
            main()
            return
                      
main()

'''
Enter password: Abc12
Re-enter password: Abc12
That password didn't have the required properties.
Enter password: abcd12345
Re-enter password: abcd12345
That password didn't have the required properties.
Enter password: ABCDabcd
Re-enter password: ABCDabcd
That password didn't have the required properties.
Enter password: ABCD12345
Re-enter password: ABCD12345
That password didn't have the required properties.
Enter password: Hello1234
Re-enter password: Ello12345
Passwords do not match. Try again.
Enter password: 123ABCabc
Re-enter password: 456ABCabc
Passwords do not match. Try again.
Enter password: ABCabc123
Re-enter password: ABCabc123
That pair of passwords will work.
'''
