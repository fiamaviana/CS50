from cs50 import get_string

s = get_string("Text: ").strip()
letters, words, sentences = 0, 0, 0

for i in range(len(s)):
    if s[i].isalpha():
        letters += 1
    if (i == 0 and s[i] != ' ') or (i != len(s) - 1 and s[i] == ' ' and s[i + 1] != ' '):
        words += 1
    if s[i] == '.' or s[i] == '!' or s[i] == '?':
        sentences += 1

L = letters / words * 100
S = sentences / words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1\n")
elif (index >= 16):
    print("Grade 16+\n")
else:
    print(f"Grade{index}\n")
