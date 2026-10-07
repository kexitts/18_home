#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Book
{
    string name;
    string author;
    string publisher;
    string genre;
    int year;
    double price;
};


void Show(Book* books, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nКнига №" << i + 1 << endl;
        cout << "Назва: " << books[i].name << endl;
        cout << "Автор: " << books[i].author << endl;
        cout << "Видавництво: " << books[i].publisher << endl;
        cout << "Жанр: " << books[i].genre << endl;
        cout << "Рік видання: " << books[i].year << endl;
        cout << "Ціна: " << books[i].price << " грн" << endl;
    }
}


void ChangeData(Book* books, int size)
{
    int number;

    cout << "Введіть номер книги: ";
    cin >> number;
    cin.ignore();

    if (number < 1 || number > size)
    {
        cout << "Невірний номер!" << endl;
        return;
    }

    number--;

    cout << "Нова назва: ";
    getline(cin, books[number].name);

    cout << "Новий автор: ";
    getline(cin, books[number].author);

    cout << "Нове видавництво: ";
    getline(cin, books[number].publisher);

    cout << "Новий жанр: ";
    getline(cin, books[number].genre);

    cout << "Новий рік видання: ";
    cin >> books[number].year;

    cout << "Нова ціна: ";
    cin >> books[number].price;

    cout << "Дані книги змінено!" << endl;
}


void SearchAuthor(Book* books, int size)
{
    string author;

    cin.ignore();

    cout << "Введіть автора: ";
    getline(cin, author);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].author == author)
        {
            cout << "\n" << books[i].name
                << " | " << books[i].author
                << " | " << books[i].publisher
                << " | " << books[i].genre
                << " | " << books[i].year
                << " | " << books[i].price << " грн";

            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг цього автора не знайдено!" << endl;
    }
}


void SearchName(Book* books, int size)
{
    string name;

    cin.ignore();

    cout << "Введіть назву книги: ";
    getline(cin, name);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].name == name)
        {
            cout << "\nАвтор: " << books[i].author;
            cout << "\nВидавництво: " << books[i].publisher;
            cout << "\nЖанр: " << books[i].genre;
            cout << "\nРік: " << books[i].year;
            cout << "\nЦіна: " << books[i].price << " грн\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "Книгу не знайдено!" << endl;
    }
}


void SearchPublisher(Book* books, int size)
{
    string publisher;

    cin.ignore();

    cout << "Введіть видавництво: ";
    getline(cin, publisher);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].publisher == publisher)
        {
            cout << "\n" << books[i].name
                << " | " << books[i].author
                << " | " << books[i].genre
                << " | " << books[i].year
                << " | " << books[i].price << " грн";

            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг цього видавництва не знайдено!" << endl;
    }
}


void SearchGenre(Book* books, int size)
{
    string genre;

    cin.ignore();

    cout << "Введіть жанр: ";
    getline(cin, genre);

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (books[i].genre == genre)
        {
            cout << "\n" << books[i].name
                << " | " << books[i].author
                << " | " << books[i].publisher
                << " | " << books[i].year
                << " | " << books[i].price << " грн";

            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг цього жанру не знайдено!" << endl;
    }
}


void ChangePrice(Book* books, int size)
{
    int number;
    double price;

    cout << "Введіть номер книги: ";
    cin >> number;

    if (number < 1 || number > size)
    {
        cout << "Невірний номер!" << endl;
        return;
    }

    cout << "Введіть нову ціну: ";
    cin >> price;

    books[number - 1].price = price;

    cout << "Ціну змінено!" << endl;
}



void SaveToFile(Book* books, int size)
{
    ofstream file("books.txt");

    if (!file)
    {
        cout << "Не вдалося відкрити файл!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file << books[i].name << endl;
        file << books[i].author << endl;
        file << books[i].publisher << endl;
        file << books[i].genre << endl;
        file << books[i].year << endl;
        file << books[i].price << endl;
    }

    file.close();

    cout << "Колекцію книг успішно записано у файл books.txt!" << endl;
}



void LoadFromFile(Book* books, int size)
{
    ifstream file("books.txt");

    if (!file)
    {
        cout << "Файл books.txt не знайдено!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        getline(file, books[i].name);
        getline(file, books[i].author);
        getline(file, books[i].publisher);
        getline(file, books[i].genre);

        file >> books[i].year;
        file >> books[i].price;

        file.ignore();
    }

    file.close();

    cout << "Колекцію книг успішно зчитано з файлу!" << endl;
}


int main()
{
    const int size = 10;

    Book* books = new Book[size];

    books[0] = { "Кобзар", "Тарас Шевченко", "Школа", "Поезія", 1840, 250 };
    books[1] = { "Захар Беркут", "Іван Франко", "Фоліо", "Історичний", 1883, 300 };
    books[2] = { "Тигролови", "Іван Багряний", "А-БА-БА-ГА-ЛА-МА-ГА", "Роман", 1944, 350 };
    books[3] = { "Місто", "Валер'ян Підмогильний", "Фоліо", "Роман", 1928, 280 };
    books[4] = { "Лісова пісня", "Леся Українка", "Школа", "Драма", 1911, 200 };
    books[5] = { "Кайдашева сім'я", "Іван Нечуй-Левицький", "Фоліо", "Роман", 1879, 220 };
    books[6] = { "Чорна рада", "Пантелеймон Куліш", "Клуб Сімейного Дозвілля", "Історичний", 1857, 270 };
    books[7] = { "Енеїда", "Іван Котляревський", "Школа", "Поема", 1798, 230 };
    books[8] = { "Intermezzo", "Михайло Коцюбинський", "Фоліо", "Новела", 1908, 180 };
    books[9] = { "Маруся Чурай", "Ліна Костенко", "А-БА-БА-ГА-ЛА-МА-ГА", "Роман у віршах", 1979, 320 };


    int choice;

    do
    {
        cout << "\n===== БІБЛІОТЕКА =====" << endl;
        cout << "1. Показати всі книги" << endl;
        cout << "2. Редагувати книгу" << endl;
        cout << "3. Пошук за автором" << endl;
        cout << "4. Пошук за назвою" << endl;
        cout << "5. Пошук за видавництвом" << endl;
        cout << "6. Пошук за жанром" << endl;
        cout << "7. Змінити ціну книги" << endl;
        cout << "8. Записати книги у файл" << endl;
        cout << "9. Зчитати книги з файлу" << endl;
        cout << "0. Вихід" << endl;

        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Show(books, size);
            break;

        case 2:
            ChangeData(books, size);
            break;

        case 3:
            SearchAuthor(books, size);
            break;

        case 4:
            SearchName(books, size);
            break;

        case 5:
            SearchPublisher(books, size);
            break;

        case 6:
            SearchGenre(books, size);
            break;

        case 7:
            ChangePrice(books, size);
            break;

        case 8:
            SaveToFile(books, size);
            break;

        case 9:
            LoadFromFile(books, size);
            break;

        case 0:
            cout << "Вихід..." << endl;
            break;

        default:
            cout << "Невірний вибір!" << endl;
        }

    } while (choice != 0);


    delete[] books;

    return 0;
}