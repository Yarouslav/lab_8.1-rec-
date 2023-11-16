#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str, int i, int k) {
    if (str[i] == '\0')
        return k;
    else if (str[i] == ',')
        return Count(str, i + 1, k + 1);
    else
        return Count(str, i + 1, k);
}

char* Change(char* str, char* tmp, char* t, size_t len, size_t i) {
    if (i < len) {
        if (str[i] == ',') {
            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
        return Change(str, tmp, t, len, i);
    }
    else {
        strcpy(str, tmp);
        return tmp;
    }
}


int FindThirdCommaPositionRecursion(char* str, int i, int commaCount) {
    if (str[i] == '\0')
        return -1;

    if (str[i] == ',') {
        commaCount++;
        if (commaCount == 3) {
            return i; 
        }
    }

    return FindThirdCommaPositionRecursion(str, i + 1, commaCount);
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int thirdCommaPosition = FindThirdCommaPositionRecursion(str, 0, 0);
    if (thirdCommaPosition != -1) {
        cout << "Position of the third comma: " << thirdCommaPosition << endl;
    }
    else {
        cout << "The third comma was not found." << endl;
    }

    cout << "String contained " << Count(str, 0, 0) << " groups of ',,,'" << endl;

    char* tmp = new char[strlen(str) * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t len = strlen(str);
    char* dest = Change(str, tmp, t, len, 0);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] tmp; 

    return 0;
}