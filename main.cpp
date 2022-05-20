/** \file lab1.cpp
* \brief Small drawing program
* \details This program..
* \author Keven aggrey
* \version 0.1
* \date 2022
* \copyright University of Nicosia.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

// Fun protoypes
void showMenu();
void drawHorizontalLine(const int length, const char ch);
void drawVerticalLine(const int length, const char ch);
void drawSquare(const int size, const char ch);
void drawRectangle(const int height, const int length, const char ch);
void drawShapes(const int NO_SHAPES, const int maxLen);
void drawTriangle(const int size, const char ch);
void drawPyramid(const int size, const char ch);

/**
* The driver of the program
* @return Returns 0
*/
int main() {
    int choice, length, size, height, noShapes, maxLen;
    char ch;

    srand(time(NULL)); //seed rand generator

    do {
        showMenu();
        cin >> choice;

        if (1 == choice) {
            do {
                cout << "\nEnter length: ";
                cin >> length;
            } while (length < 1);
            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawHorizontalLine(length, ch);
        }
        else if (2 == choice) {
            do {
                cout << "\nEnter length: ";
                cin >> length;
            } while (length < 1);
            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawVerticalLine(length, ch);
        }
        else if (3 == choice) {
            do {
                cout << "\nEnter size: ";
                cin >> size;
            } while (size < 2);
            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawSquare(size, ch);
        }
        else if (4 == choice) {
            do {
                cout << "\nEnter height: ";
                cin >> height;
            } while (height < 2);

            do {
                cout << "\nEnter length: ";
                cin >> length;
            } while (length < 2);

            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawRectangle(height, length, ch);
        }
        else if (5 == choice) {
            do {
                cout << "\nEnter size: ";
                cin >> size;
            } while (size < 2);

            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawTriangle(size, ch);
        }
        else if (6 == choice) {
            do {
                cout << "\nEnter size: ";
                cin >> size;
            } while (size < 2);

            cout << "\nEnter drawing symbol: ";
            cin >> ch;

            drawPyramid(size, ch);
        }
        else if (7 == choice) {
            do {
                cout << "\nEnter number of shapes: ";
                cin >> noShapes;
            } while (noShapes < 1);

            do {
                cout << "\nEnter maximum length: ";
                cin >> maxLen;
            } while (maxLen < 2);
            drawShapes(noShapes, maxLen);
        }
        else if (8 != choice) {
            cerr << "\nWrong choice!\n";
        }

    } while (choice != 8);
}

/**
* Function <code>showMenu</code>, prints the menu for choice
*/
void showMenu() {
    cout << "\n1)Draw a horizontal line";
    cout << "\n2)Draw a vertical line";
    cout << "\n3)Draw a square";
    cout << "\n4)Draw a rectangle";
    cout << "\n5)Draw a triangle";
    cout << "\n6)Draw a pyramid";
    cout << "\n7)Draw shapes";
    cout << "\n8)Quit";
    cout << "\nEnter choice: ";
}

/**
* Function <code>drawHorizontalLine</code>,
* draws a horizontal line using supplied char.
* <BR>
* @param length The length of the line
* @param ch The symbol used to draw the line
*/
void drawHorizontalLine(const int length, const char ch) {
    // Testing pre-condition
    assert(length > 0);

    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

/**
* Function <code>drawVerticalLine</code>,
* draws one vertical line using supplied char.
* <BR>
* @param length The length of the line
* @param ch The symbol used to draw the line
*/
void drawVerticalLine(const int length, const char ch) {
    // Testing pre-condition
    assert(length > 0);

    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << ch << endl;
    }
    cout << endl;
}

/**
* Function <code>drawSquare</code>,
* draws one square using supplied char.
* <BR>
* @param size The length of sides of the square
* @param ch The symbol used to draw the square
*/
void drawSquare(const int size, const char ch) {
    // Testing pre-condition
    assert(size > 1);

    cout << endl;
    if (size == 1) {
        cout << ch;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << ch;
    }
    cout << endl;

    for (int i = 0; i < size - 2; i++) {
        cout << ch;
        for (int i = 0; i < size - 2; i++) {
            cout << " ";
        }
        cout << ch << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << ch;
    }
    cout << endl;
}

/**
* Function <code>drawRectangle</code>,
* draws one rectangle using supplied char.
* <BR>
* @param height The height of the rectangle
* @param length The length of the rectangle
* @param ch The symbol used to draw the rectangle
*/
void drawRectangle(const int height, const int length, const char ch) {
    // Testing pre-condition
    assert(height > 1);
    assert(length > 1);

    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;

    for (int i = 0; i < height - 2; i++) {
        cout << ch;
        for (int i = 0; i < length - 2; i++) {
            cout << " ";
        }
        cout << ch << endl;
    }

    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

/**
* Function <code>drawShapes</code>,
* draws a number of randomly generated shapes
* <BR>
* @param noShapes The number of shapes that will be drawn
* @param maxLen The maximum length of shapes
*/
void drawShapes(const int noShapes, const int maxLen) {
    // Testing pre-condition
    assert(noShapes > 0);
    assert(maxLen > 1);

    int shape;
    int len,height;
    char sym;

    for (int i = 0; i < noShapes; i++) {
        shape = 1 + rand() % 7;
        len = 2 + rand() % (maxLen-1);
        height = 2 + rand() % (maxLen-1);
        sym = 33 + rand() % 94; // printable chars [33;126]

        switch (shape) {
        case 1:
            drawVerticalLine(len, sym);
            break;
        case 2:
            drawHorizontalLine(len, sym);
            break;
        case 3:
            drawSquare(len, sym);
            break;
        case 4:
            drawRectangle(len, height, sym);
            break;
        case 5:
            drawTriangle(len, sym);
            break;
        case 6:
            drawPyramid(height, sym);
            break;
        case 7:
            // safeguard
            break;
        }
    }
}

/**
* Function <code>drawTriangle</code>,
* draws one triangle using supplied char.
* <BR>
* @param size The length of sides of the triangle
* @param ch The symbol used to draw the triangle
*/
void drawTriangle(const int size, const char ch) {
    // Testing pre-condition
    assert(size > 1);

    cout << endl;

    cout << ch << endl;

    for (int i = 1; i < size-1; i++) {
        cout << ch;
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << ch;
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << ch;
    }

    cout << endl;
}

/**
* Function <code>drawPyramid</code>,
* draws one pyramid using supplied char.
* <BR>
* @param size The length of sides of the pyramid
* @param ch The symbol used to draw the pyramid
*/
void drawPyramid(const int size, const char ch) {
    // Testing pre-condition
    assert(size > 1);

    int i, j;
    cout << endl;

    for (i = 1;i <= size-1;i++) {
        for (j = 1; j <= size - i;j++)
            cout << " ";

        cout << ch;
        for (j = 1; j <= 2 * i - 3;j++)
            cout << " ";

        if (i != 1)
            cout << ch;
        cout << endl;
    }

    for (i = 0;i < size*2-1;i++)
        cout << ch;
}
