

with open("test3.in", "r") as file:
    output = open("ifelse.cpp", "w")
    count = 0
    for words in file:
        if count >= 3:
            words = words.strip("\n").split(" ")
            if len(words) == 0: break
            elif words[0] == "IF":
                output.write('if (categories["' + words[3] + '"] == true) {')
            elif words[0] == "output":
                output.write("cout << " + '"' + words[1] + '"' + ";")
            elif words[0] == ")" and len(words) == 3:
                output.write("} else {")
            else:
                output.write("}")
            #output += "\n"

        count += 1
    output.write("}")
