set_01 = set()
list_01 = []

for i in range(11):
    set_01.add((i % 5))
    list_01.append((i % 5))

print(f"Set (i % 5 from 0 to 10): {set_01}")
print(f"List (i % 5 from 0 to 10): {list_01}")