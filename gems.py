from sys import stdin

gems = set()

for i in range(int(stdin.readline())):

    line = stdin.readline()
    line = line.replace('\n', '')
    rock = set()

    for letter in line:
        rock.add(letter)

    if i is 0:
        gems = gems.union(rock)
    else:
        gems = gems.intersection(rock)

print(len(gems))
