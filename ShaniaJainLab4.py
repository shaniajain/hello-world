###############################################################################
# CS 21A Python Programming: Lab #4
# Name: Shania Jain
# Description: Creating a Dictionary of Identifiers
# Filename: ShaniaJainLab4.py
# Date: 08/01/17
###############################################################################

def main():
    
    file_name = input("Enter file name: ")
    infile = open(file_name, 'r')
    data = infile.readlines()
    infile.close()

    index = 0
    while index < len(data):
        data[index] = data[index].rstrip(' \n')
        index += 1
    
    create_dictionary(data)


    
    
def create_dictionary(data):

    #checks for valid identifier and adds it to the dictionary

    my_dictionary = {}
    
    index = 0
    while index < len(data):
        for item in data:
            if item.isalnum() or item == "_":
                if item not in my_dictionary:
                    my_dictionary[item] = [index + 1]
                    index += 1
                else:
                    my_dictionary[item].append(index + 1)
                    index += 1                   

            else:
                exit
                index += 1


    for key, value in my_dictionary.items():
        print(key, value)
        


main()



'''
Enter file name: t4.py
apple [1, 11]
1 [2, 3]
ball [4, 19]
art [5]
dog [6]
pen [8, 21]
rat [9]
4 [10]
carrot [13]
orange [15]
ant [16, 17, 18]
stick [20]
_ [22]
goodbye [25]
'''

