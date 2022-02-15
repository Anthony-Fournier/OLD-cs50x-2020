# A program that computes the Coleman-Liau index value of a target string of input text
# index = 0.0588 * L - 0.296 * S - 15.8
# Anthony-Fournier 10/2020 for Harvardx cs50 pset6
from cs50 import get_string
text = get_string("Text: ")
(letters, words, sentences) = (0, 1, 0)
for i in range (len(text)):
    if text[i].isalpha():
        letters += 1
    if text[i] == " ":
        words += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
index = 0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8
grade = round(index)
if grade < 1:
    print("Before Grade 1")
if grade > 16:
    print("Grade 16+")
else:
    print(f"Grade", grade)