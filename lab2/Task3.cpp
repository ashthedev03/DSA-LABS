#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
public:
	virtual void display() = 0;
};

class Book : public LibraryItem
{
private:
	string title;
	string author;
	int pages;

public:
	Book(string t, string a, int p)
	{
		title = t;
		author = a;
		pages = p;
	}

	string getTitle()
	{
		return title;
	}

	int getPages()
	{
		return pages;
	}

	void display() override
	{
		cout << "Book: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Pages: " << pages << endl;
	}
};

class Newspaper : public LibraryItem
{
private:
	string name;
	string date;
	string edition;

public:
	Newspaper(string n, string d, string e)
	{
		name = n;
		date = d;
		edition = e;
	}

	string getName()
	{
		return name;
	}

	string getEdition()
	{
		return edition;
	}

	void display() override
	{
		cout << "Newspaper: " << name << endl;
		cout << "Date: " << date << endl;
		cout << "Edition: " << edition << endl;
	}
};

template <class T>
int linearSearch(T arr[], int size, string key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getTitle() == key || arr[i].getName() == key)
		{
			return i;
		}
	}

	return -1;
}

template <class T>
int binarySearch(T arr[], int size, string key)
{
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid].getTitle() == key || arr[mid].getName() == key)
		{
			return mid;
		}
		else if (arr[mid].getTitle() < key || arr[mid].getName() < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

class Library
{
private:
	Book books[100];
	Newspaper newspapers[100];
	int bookCount;
	int newspaperCount;

public:
	Library() : bookCount(0), newspaperCount(0) {}

	void addBook(Book book)
	{
		books[bookCount++] = book;
	}

	void addNewspaper(Newspaper newspaper)
	{
		newspapers[newspaperCount++] = newspaper;
	}

	void displayCollection()
	{
		cout << "\nBooks:\n";

		for (int i = 0; i < bookCount; i++)
		{
			books[i].display();
			cout << endl;
		}

		cout << "Newspapers:\n";

		for (int i = 0; i < newspaperCount; i++)
		{
			newspapers[i].display();
			cout << endl;
		}
	}

	void sortBooksByPages()
	{
		for (int i = 0; i < bookCount - 1; i++)
		{
			for (int j = 0; j < bookCount - i - 1; j++)
			{
				if (books[j].getPages() > books[j + 1].getPages())
				{
					Book temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
				}
			}
		}
	}

	void sortNewspapersByEdition()
	{
		for (int i = 0; i < newspaperCount - 1; i++)
		{
			for (int j = 0; j < newspaperCount - i - 1; j++)
			{
				if (newspapers[j].getEdition() >
					newspapers[j + 1].getEdition())
				{
					Newspaper temp = newspapers[j];
					newspapers[j] = newspapers[j + 1];
					newspapers[j + 1] = temp;
				}
			}
		}
	}

	Book* searchBookByTitle(string title)
	{
		int index = linearSearch(books, bookCount, title);

		if (index != -1)
		{
			return &books[index];
		}

		return nullptr;
	}

	Newspaper* searchNewspaperByName(string name)
	{
		int index = linearSearch(newspapers, newspaperCount, name);

		if (index != -1)
		{
			return &newspapers[index];
		}

		return nullptr;
	}
};

int main()
{
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	Library library;

	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	cout << "Before Sorting:\n";
	library.displayCollection();

	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	Book* foundBook =
		library.searchBookByTitle("The Catcher in the Rye");

	if (foundBook)
	{
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else
	{
		cout << "\nBook not found.\n";
	}

	Newspaper* foundNewspaper =
		library.searchNewspaperByName("The Times");

	if (foundNewspaper)
	{
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else
	{
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}
