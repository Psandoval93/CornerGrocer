#import re
#import string

#def printsomething():
	#print("Hello Phillip Sandoval from Python!")

import re
import string

def GetFrequencyOfEachItem(string = ""):             # Returns a string which contains all items & frequency of items
    f = open("input.txt", "r")                       # Opens input data file to read and assigns to variable f
    data = f.read()                                  # Read file and assign to data
    list_of_items = data.split()                     # Split the data or file into individual items & stores them in a list_of_items
    frequency = {}                                   # Creates dictionary to store item frequency
        
    for item in list_of_items:                       # For loop created to iterate through items in list_of_items
        frequency[item] = frequency.get(item, 0) + 1 # Calculates frequency
        return_string = ""                           # Creates empty string named return_string for return statement

    for item,freq in frequency.items():                     # For loop created to iterate through item and frequency in list and appends data to return string
        return_string += item + " : " + str(freq) + "\n"    # Appends data with colon between then frequency and followed by a new line
    print(return_string)                                    # Returns answer string to C++ program

def GetFrequencyOfSingleItem(item):                   # Returns a string that contains the given item & frequency of item
    f = open("input.txt", "r")                        # Opens input data file to read and assigns to f variable

    data = f.read()                                   # Read file and assign to data
    list_of_items = data.split()                      # Split the data or file into individual items & stores them in a list_of_items
    frequency = {}                                    # Creates dictionary to store item frequency
        
    user_item = input("Enter the name of the item you want to check frequency of: \n")
    for item in list_of_items:                        # For loop created to iterate through items in list_of_items
        frequency[item] = frequency.get(item, 0) + 1  # Calculates frequency

    if user_item in frequency:                        # If item is present in the string
        return(frequency[user_item])                  # Returns the frequency
    else:
        print("No such item present")                 # Else if item is not present return "No such item present"

def ShowHistogram():
    f = open("input.txt", "r")                        # Opens input data file to read and assigns to variable f
    data = open("frequency.dat", "w")
    items = f.read()                                   # Read file and assign to data 
    list_of_items = items.split()                      # Split the data or file into individual items & stores them in a list_of_items
    
    items_dict = {}                                    # Creates dictionary to store items and count

    for item in list_of_items:                         # Iterates through the items in the list from input text file
        if item in items_dict:                         # If item is in the dictionary
            items_dict[item] = items_dict[item] + 1    # If item is in dictionary add to count
        else:                                          # Else do not increment count
            items_dict[item] = 1

    for item,count in items_dict.items():              # For item and count in the dictionary
    	data.write(f"{item} {count} \n")               # Write the item and count to text file followed by a new line


    data.close()                                       # Closes the file

    with open("frequency.dat", "r") as histo_gram:     # Opens file and assigns histo_gram to open file
        item_data = histo_gram.readlines()             # Reads the lines in file and assigns to item_data
        for line in item_data:                         # For line read from output file "frequency.dat"
            line_parts = line.split(" ")               # Split the lines read using a space
            num_ast = int(line_parts[1])               # Assign num_ast to count 
            print(line_parts[0] + " " + "*"*num_ast)   # Prints item a space and the count in asterisks
