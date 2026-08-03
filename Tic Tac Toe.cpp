#include <iostream>
#include <limits>
using namespace std;
struct Node {
    char data;
    Node* next;
};
Node* initializeBoard() {
    Node* head = NULL;
    for (char i = '9'; i >= '1'; --i) {
        head = new Node{i, head};
    }
    return head;
}
void displayBoard(Node* head) {
    system("cls");
    cout << "\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << (head->data) << " ";
            if (j < 2) {
                cout << "|";
            }
            head = head->next;
        }
        cout << endl;
        if (i < 2) {
            cout << " --- --- ---" << endl;
        }
    }
    cout << endl;
}
int checkwin(Node* head) {
    for (int i = 0; i < 3; ++i) {
        if ((head->data == head->next->data && head->next->data == head->next->next->data) ||
            (head->data == (head->next)->next->data && (head->next)->next->data == (head->next)->next->next->data)) {
            return 1;
        }
        head = head->next;
    }
    if ((head->data == (head->next)->next->data && head->next->data == (head->next)->next->next->data) ||
        ((head->next)->data == (head->next)->next->data && head->data == (head->next)->next->next->data)) {
        return 1;
    }
    return 0;
}
Node* makeMove(Node* head, int choice, char mark) {
    Node* current = head;
    for (int i = 1; i < choice && current; ++i) {
        current = current->next;
    }
    if (current && (current->data != 'X' && current->data != 'O')) {
        current->data = mark;
    }
    return head;
}
void freeMemory(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* board = initializeBoard();
    int player = 1, choice;
    char mark;
    do {
        displayBoard(board);
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number:  ";
        while (!(cin >> choice) || choice < 1 || choice > 9) {
            cout << "Invalid input. Please enter a valid number (1-9): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        mark = (player == 1) ? 'X' : 'O';
        board = makeMove(board, choice, mark);
        player++;
    } while (!checkwin(board) && choice >= 1 && choice <= 9);

    displayBoard(board);
    if (checkwin(board))
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    freeMemory(board);
    cin.ignore();
    cin.get();
    return 0;
}
