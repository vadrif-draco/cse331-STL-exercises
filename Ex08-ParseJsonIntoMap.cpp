#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map<string, string> parseColorsJson(string filename) {

    // Create a new empty map
    map<string, string> myColorsMap;

    // Open file in same folder with provided name for input (i.e, read-only mode)
    // Make sure to change the path to where your file would be located w.r.t your executable
    // For example, my colors.json file is in the "Lab 07 Codes (Self Study)" folder
    // My executable is in the parent folder, that's why I need to write the path like this
    fstream myColorsFile("Lab 07 Codes (Self Study)/" + filename, ios::in);

    // Make sure file is open before proceeding
    if (myColorsFile.is_open()) {

        // We will now parse the text file line by line into hexCode and colorName:
        string line;
        string hexCode;
        string colorName;
        while (getline(myColorsFile, line)) {

            // We can make use of the fact that we know how this specific JSON file is formatted
            // Two lines are of interest to us:
            // "Hex": "#some_hex_code"
            // "Color": "name_of_color"
            // So, in each line, we could look to find the ":"
            // If it exists, we know we have one of the two lines that we want
            // The string .find method returns the index when found, or -1 if not found
            int colonIndex = line.find(':');
            if (colonIndex != -1) {

                // Ok great, it's one of the two lines. Let's now parse the value next to it
                // The optonal second argument to the .find method tells it where to start
                // We can start from after the colon, in which case we will find the first "
                // To get the second ", we can search from after where the first one was found
                int firstDoubleQuoteIndex = line.find('"', colonIndex);
                int secondDoubleQuoteIndex = line.find('"', firstDoubleQuoteIndex + 1);

                // Great! Let's get the value now that we know where it starts and ends!
                // Remember that .substr takes the starting position, then the length of the substring required
                // The + 1 is to skip the first quote, we don't need it; likewise the - 1 skips the last quote
                string value = line.substr(firstDoubleQuoteIndex + 1, secondDoubleQuoteIndex - firstDoubleQuoteIndex - 1);

                // Let's see if its "Hex" or "Color" and set the variables accordingly
                if (line.find("Hex") != -1) hexCode = value;
                else if (line.find("Color") != -1) colorName = value;

                // Once the two variables are set, add them to the map, then clear them
                // Setting values in a map are similar to how you expect a HashMap to work
                // You put the unique key (in this case, hexCode) is the index
                // It performs some internal hashing mechanism to get an index...
                // ...then stores the value (colorName) in the resulting index
                if (!hexCode.empty() && !colorName.empty()) {
                    myColorsMap[hexCode] = colorName;
                    hexCode.clear();
                    colorName.clear();
                }

            }

        }

        // Close file when done reading from it
        myColorsFile.close();

    }

    return myColorsMap;

}