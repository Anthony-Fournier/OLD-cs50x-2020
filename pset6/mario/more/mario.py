from cs50 import get_int
height = 0
while height < 1 or height > 8:
    height = get_int("height: ")    
spaces = height
hashs = 0
for i in range(height):
    spaces -= 1
    hashs += 1
    print(" " * spaces, end="")
    print("#" * hashs, end="")
    print("  ", end="")
    print("#" * hashs, end="")
    print("")