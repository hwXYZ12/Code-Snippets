whichFile = "quick.txt"
gpa1 = "AMS"
gpa2 = "CSE"

file = open(whichFile, 'r')

relevant = [line for line in file if len(line) != 0 and (line[:3]==gpa1 or line[:3]==gpa2)]
relevant1 = [x for x in relevant if x[:3]==gpa1]
relevant2 = [x for x in relevant if x[:3]==gpa2 and (x[len(x)-2:] != "T\n" and x[len(x)-2:] != "F\n" and x[len(x)-2:] != "W\n")]
relevant2 = relevant2[:-1]

# get total credits
credits1 = sum([int(x[len(x)-20:len(x)-19]) for x in relevant1])
credits2 = sum([int(x[len(x)-20:len(x)-19]) for x in relevant2])

# get total grade
totalGrade1 = sum([float(x[len(x)-7:]) for x in relevant1])
totalGrade2 = sum([float(x[len(x)-7:]) for x in relevant2])

# factor in one failed course.....
credits2 += 3

# divide to get cum gpa per major
GPA1 = totalGrade1 / credits1
GPA2 = totalGrade2 / credits2

for x in relevant1:
    print x

print ""

for x in relevant2:
    print x

print GPA1
print GPA2