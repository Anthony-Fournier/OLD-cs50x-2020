import sys
#Get Credit Card number from user
cc = input("Number: ")
#Check for valid length and index first digit(s) to determaine card type
if len(cc) == 15:
    if cc[0:2:1] == "34" or cc[0:2:1] == "37":
        card = "AMEX"
elif len(cc) == 16:
    if cc[0:2:1] == "51" or cc[0:2:1] == "52" or cc[0:2:1] == "53" \
    or cc[0:2:1] == "54" or cc[0:2:1] == "55":
        card = "MASTERCARD"
    elif cc[0:1:1] == "4":
        card = "VISA"
elif len(cc) == 13:
    if cc[0:1:1] == "4":
        card = "VISA"
else:
    sys.exit("INVALID")
#Apply Luhn's algorithm
digits_2_double = cc[-2: -(len(cc) + 1): -2]
digits_1_single = cc[-1: -(len(cc) + 1): -2]
singles_sum = 0
for i in digits_1_single:
    singles_sum += int(i)
doubles_sum = 0
for i in digits_2_double:
    temp = int(i) * 2
    if temp > 9:
        temp -= 9
    doubles_sum += temp
checksum = singles_sum + doubles_sum
if checksum % 10 != 0:
    sys.exit("INVALID")
#print valid card type
print(f"{card}")







