#include <string>
#include <iostream>

std::string toLowerString(std::string temp) { // convert string to lowercase
    for (int i = 0; i < temp.size(); i++) {
        temp[i] = tolower(temp[i]);
    }
    return temp;
}

int max(int integer1, int integer2) // max helper function to compare int size
{
    return (integer1 > integer2) ? integer1 : integer2;
}

int lcsLength(const std::string& string1, const std::string& string2) // bottom up method runtime = O(m*n)
{
    const int m = string1.size();
    const int n = string2.size();
    int arr[m + 1][n + 1]; // initialize matrix

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // if either string is empty, return 0
            {
                arr[i][j] = 0;
            }

            else if (string1[i - 1] == string2[j - 1]) // if the last character matches, add 1 to count and move to the next character
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }

            else // if last character does not match, don't add 1
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    return arr[m][n];
}


std::string lcsString(const std::string& string1, const std::string& string2) // bottom up method runtime = O(m*n)
{
    const int m = string1.size();
    const int n = string2.size();
    int arr[m + 1][n + 1]; // initialize matrix

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // if either string is empty, return 0
            {
                arr[i][j] = 0;
            }

            else if (string1[i - 1] == string2[j - 1]) // if the last character matches, add 1 to count and move to the next character
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }

            else // if last character does not match, don't add 1
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    int lcsLength = arr[m][n]; // get lcsLength
    char lcsString[lcsLength + 1]; // initialize character array for substring (+1 is for terminating character)
    lcsString[lcsLength] = '\0';

    // backtracking
    int i = m;
    int j = n;

    while (i > 0 && j > 0) // if any of my indices = 0, then program is done
    {
        if (string1[i - 1] == string2[j - 1]) // if value previous indices are equal, move diagonally up left
        {
            lcsString[--lcsLength] = string1[i - 1]; // get the char at that index
            i--;
            j--;
        }

        else if (arr[i - 1][j] > arr[i][j - 1]) // if value at previous index i > value at previous index j, move up
        {
            i--;
        }

        else // move left
            j--;
    }
    return lcsString;
}


int main(int argc, char* argv[])
{
    std::cout << "==== Welcome to James' LCS Calculator ====" << std::endl;
    char answer;

    do{
	std::string string1;
	std::string string2;

	std::cout << "Please enter the first string: " << std::endl;
	std::getline(std::cin >> std::ws, string1);

	std::cout << "Please enter the second string: " << std::endl;
	std::getline(std::cin >> std::ws, string2);

    std::string temp1 = toLowerString(string1);
    std::string temp2 = toLowerString(string2);

    std::cout << "The substring of the LCS is: " << lcsString(temp1, temp2) << std::endl;
	std::cout << "The length of the LCS is: " << lcsLength(temp1, temp2) << std::endl;

    std::cout << "Would you compare another pair of strings? (y/n)" << std::endl;
    std::cin >> answer;
    } while (tolower(answer) == 'y');
    std::cout << "======= Thank You! See you again! =======" << std::endl;
    std::cout << "  ⣿⣿⣿⣿⠿⢋⣩⣤⣴⣶⣶⣦⣙⣉⣉⣉⣉⣙⡛⢋⣥⣶⣶⣶⣶⣶⣬⡙⢿⣿" << std::endl;
    std::cout << "  ⣿⣿⠟⣡⣶⣿⢟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠙" << std::endl;
    std::cout << "  ⣿⢋⣼⣿⠟⣱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⢿⣿⣿⣿⣿⣧" << std::endl;
    std::cout << "  ⠃⣾⣯⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⣿⡈⢿⣿⣿⣿⣿" << std::endl;
    std::cout << "  ⢰⣶⣼⣿⣷⣿⣽⠿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⣿⣷⡀⠛⢿⣿⣿" << std::endl;
    std::cout << "  ⢃⣺⣿⣿⣿⢿⠏⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡾⣿⣿⣿⣷⢹⣿⣷⣄⠄⠈⠉" << std::endl;
    std::cout << "  ⡼⣻⣿⣷⣿⠏⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣞⣿⣿⣿⠸⣿⣿⣿⣿⣶⣤" << std::endl;
    std::cout << "  ⣇⣿⡿⣿⠏⣸⣎⣻⣟⣿⣿⣿⢿⣿⣿⣿⣿⠟⣩⣼⢆⠻⣿⡆⣿⣿⣿⣿⣿⣿" << std::endl;
    std::cout << "  ⢸⣿⡿⠋⠈⠉⠄⠉⠻⣽⣿⣿⣯⢿⣿⣿⡻⠋⠉⠄⠈⠑⠊⠃⣿⣿⣿⣿⣿⣿" << std::endl;
    std::cout << "  ⣿⣿⠄⠄⣰⠱⠿⠄⠄⢨⣿⣿⣿⣿⣿⣿⡆⢶⠷⠄⠄⢄⠄⠄⣿⣿⣿⣿⣿⣿" << std::endl;
    std::cout << "  ⣿⣿⠘⣤⣿⡀⣤⣤⣤⢸⣿⣿⣿⣿⣿⣿⡇⢠⣤⣤⡄⣸⣀⡆⣿⣿⣿⣿⣿⣿" << std::endl;
    std::cout << "  ⣿⣿⡀⣿⣿⣷⣌⣉⣡⣾⣿⣿⣿⣿⣿⣿⣿⣌⣛⣋⣴⣿⣿⢣⣿⣿⣿⣿⡟⣿" << std::endl;
    std::cout << "  ⢹⣿⢸⣿⣻⣶⣿⢿⣿⣿⣿⢿⣿⣿⣻⣿⣿⣿⡿⣿⣭⡿⠻⢸⣿⣿⣿⣿⡇⢹" << std::endl;
    std::cout << "  ⠈⣿⡆⠻⣿⣏⣿⣿⣿⣿⣿⡜⣭⣍⢻⣿⣿⣿⣿⣿⣛⣿⠃⣿⣿⣿⣿⡿⠄⣼" << std::endl;
    std::cout << "  ⣦⠘⣿⣄⠊⠛⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣼⣿⣿⣿⡿⠁⠄⠟" << std::endl;
    return 0;
}