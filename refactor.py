import os

fileExtensions = [".txt", ".jsp",".cs"]

def deleteTextRecursively(whichDir, whichText, newText):
    for x in os.listdir(whichDir):
        filePath = os.path.join(whichDir, x)
        if(os.path.isdir(filePath)):
            # recurse
            deleteTextRecursively(filePath, whichText, newText)
        else:

            # ensure that the file has the correct file extension
            check = False
            for ext in fileExtensions:
                extSize = len(ext)
                fileExt = filePath[-extSize:]
                if fileExt == ext:
                    check = True

            if check:

                # open the file for reading and replace every instance of the given
                # text with an empty string
                with open(filePath, 'r') as whichFile:
                    text = whichFile.read()
                    text = text.replace(whichText, newText)

                # open the file again for writing (thereby clearing the file)
                # and write the new text to it            
                with open(filePath, 'w') as whichFile:
                    whichFile.write(text)

print("Which directory would you like to edit?")
directoryName = input()
print("What text would you like to delete?")
textToDelete = input()
print("What text would you like to replace it with?")
textToAdd = input()
deleteTextRecursively(directoryName, textToDelete, textToAdd)
print("Done")