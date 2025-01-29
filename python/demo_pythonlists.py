list_1 = [(2321.213,0.123),"123",9,f"abc",[0,2,4],423.3242]

# Append
list_1.append("123")
print(f"Append")
print(f"Original list: \t{list_1}\n")
print(f'Append "123": \t{list_1}\n')

# Copy
list_2 = list_1.copy()
print(f"Copy")
print(f"Original list: \t{list_1}")
print(f'Copy of List: \t{list_2}\n')

# Clear copy
print(f"Clear")
print(f'Copy of List: \t{list_2}')
list_2.clear()
print(f'Copy of List: \t{list_2}\n')

# Count list
print(f"Count")
print(f"Original list: \t{list_1}")
print(f'# of "123": \t{list_1.count(f"123")}\n')

# Extend
print(f"Extend")
extended_list = [1,2,3,4]
list_2 = list_1.copy()
list_2.extend(extended_list)
print(f"Original list: \t{list_1}")
print(f"Additional: \t{extended_list}")
print(f"Extended list: \t{list_2}\n")

# Index 
print(f"Index")
print(f"Original list: \t{list_1}")
print(f'Index "123": \t{list_1.index(f"123")}\n')

# Insert 
print(f"Insert")
print(f"Original list: \t{list_1}")
list_2 = list_1.copy()
list_2.insert(5,f"Hello")
print(f'Insert"Hello": \t{list_2}\n')

# Pop
print(f"Pop")
print(f"Original list: \t{list_1}")
list_2 = list_1.copy()
num = list_2.pop(list_1.index(f"123"))
print(f'Pop "123": \t{num} {list_2}\n')

# Remove
print(f"Remove")
print(f"Original list: \t{list_1}")
list_2 = list_1.copy()
num = list_2.remove(f"123")
print(f'Remove "123": \t{list_2}\n')

# Reverse
print(f"Reverse")
list_1 = [4,12,6,2,36,1,24,25,6]
print(f"Original list: \t{list_1}")
list_1.reverse()
print(f"Reversed list: \t{list_1}\n")

# Sort
print(f"Sort")
list_1 = [4,12,6,2,36,1,24,25,6]
print(f"Original list: \t{list_1}")
list_1.sort()
print(f"Sorted list: \t{list_1}")