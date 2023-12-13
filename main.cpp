#include <iostream>
using namespace std;

const int MAX_TODOS = 100;
bool isDone[MAX_TODOS];
string todos[MAX_TODOS];
int todosCount = 0;

void handleMarkTodoAsNotDone()
{
    cout << "Enter the todo's index: ";
    int index;
    cin >> index;

    if (index < 1 || index > todosCount)
    {
        cout << "The index is invalid." << endl;
    }
    else if (!isDone[index - 1])
    {
        cout << "The todo has been marked as done" << endl;
    }
    else
    {
        isDone[index - 1] = false;
        cout << "The todo is marked as not done successfully." << endl;
    }
}

void handleMarkTodoAsDone()
{
    cout << "Enter the todo's index: ";
    int index;
    cin >> index;

    if (index < 1 || index > todosCount)
    {
        cout << "The index is invalid." << endl;
    }
    else if (isDone[index - 1])
    {
        cout << "The todo has been marked as done" << endl;
    }
    else
    {
        isDone[index - 1] = true;
        cout << "The todo is marked as done successfully." << endl;
    }
}

void handleDeleteTodo()
{
    cout << "Enter the todo's index: ";
    int index;
    cin >> index;
    if (index < 1 || index > todosCount)
    {
        cout << "The index is invalid." << endl;
    }
    else
    {
        for (int i = index; i < todosCount; i++)
        {
            /* delete a todo from the isDone array. */
            todos[i - 1] = todos[i];
            isDone[i - 1] = isDone[i];
        }

        todosCount -= 1;
        cout << "The todo is deleted successfully;" << endl;
    }
}

void displayTodos()
{
    cout << "Todos: " << endl;
    for (int i = 0; i < todosCount; i++)
    {
        cout << i + 1 << ".";
        if (isDone[i])
        {
            cout << " [x] ";
        }
        else
        {
            cout << " [ ] ";
        }
        cout << todos[i] << endl;
    }
}

enum MenuChoice
{
    AddNewTodo = 1,
    DeleteTodo = 2,
    MarkTodoAsDone = 3,
    MarkTodoAsNotDone = 4,
    Exit = 5,
};

void printMenu()
{
    cout << "Menu:" << endl;
    cout << AddNewTodo << ". Add a new todo" << endl;
    cout << DeleteTodo << ". Delete a todo" << endl;
    cout << MarkTodoAsDone << ". Mark a todo as done" << endl;
    cout << MarkTodoAsNotDone << ". Mark a todo as not done" << endl;
    cout << Exit << ". Exit" << endl;
}

MenuChoice getChoice()
{
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    return static_cast<MenuChoice>(choice);
}

void handleAddNewTodo()
{
    cout << "Enter the todo's title: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout << "title: " << title << endl;
    if (title.empty())
    {
        cout << "The title cannot be empty." << endl;
    }
    todos[todosCount] = title;
    isDone[todosCount] = false;
    todosCount++;

    cout << "The todo is added successfully." << endl;
}

void handleExit()
{
    cout << "Bye!" << endl;
}

void handleInvalidChoice()
{
    cout << "Invalid code" << endl;
}

void handleChoice(MenuChoice choice)
{
    switch (choice)
    {
    case AddNewTodo:
        handleAddNewTodo();
        break;
    case DeleteTodo:
        handleDeleteTodo();
        break;
    case MarkTodoAsDone:
        handleMarkTodoAsDone();
        break;
    case MarkTodoAsNotDone:
        handleMarkTodoAsNotDone();
        break;
    case Exit:
        handleExit();
        break;

    default:
        handleInvalidChoice();
        break;
    }
}

int main()
{
    while (true)
    {
        displayTodos();
        printMenu();
        MenuChoice choice = getChoice();
        handleChoice(choice);
        if (choice == Exit)
            break;
    }
    return 0;
}