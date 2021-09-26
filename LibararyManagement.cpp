#include <iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;
struct Category
{
	string category_name;
	string category_number;
};

bool checkCategory(Category category)
{
	if (category.category_number.length() != 3) return false;
	for (int i = 0; i < category.category_number.length(); i++)
	{
		if (!isdigit(category.category_number[i]))return false;

	}
	if (category.category_name.length() > 60) return false;
	for (int i = 0; i < category.category_name.length(); i++)
	{
		if (!isalpha(category.category_name[i])) return false;
	}
	return true;
}

Category& inputCategory(Category& category)
{
	cout << "Enter the category: 098 Science ";
	getline(cin, category.category_number, ' ');
	getline(cin, category.category_name, '\n');;
	return category;
}

bool addCategory(vector<Category>& category)
{
	Category category_var;
	category_var = inputCategory(category_var);

	if (!checkCategory(category_var)) return false;

	if (category.at(0).category_number == "\0") 
	{
		category.at(0).category_name = category_var.category_name;
		category.at(0).category_number = category_var.category_number;
		cout << "Category added successfully" << endl;
		return true;
	}

	else  
	{
		for (int i = 0; i < category.size(); i++)
		{
			if (category.at(i).category_number == category_var.category_number)
			{
				cout << "Category already present" << endl;
				return false;
			}
		}
		for (int i = 0; i < category.size(); i++)
		{
			if (category.at(i).category_number == "\0")
			{
				category.at(i).category_name.assign(category_var.category_name);
				category.at(i).category_number.assign(category_var.category_number);
				cout << "Category added successfully" << endl;
				return true;
			}
		}
		category.push_back(category_var);
		cout << "Category added successfully"<<endl;
		return true;
	}
	cout << "Category not added" << endl;
	return false;
}

//bool deleteCategory(vector<Category>& category)
//{

//}

void printCategory(vector<Category> category)
{
	cout << "Category Number " << " " << "Category  Name" << endl;
	for (int i = 0; i < category.size(); i++)
	{
		cout << category.at(i).category_number << "                 " << category.at(i).category_name << endl;
	}
}

int main()
{
	Category categoryDumy;
	categoryDumy.category_name = "\0";
	categoryDumy.category_number = "\0";
	vector<Category> category{categoryDumy};
	cout << addCategory(category) << endl;
	cout << addCategory(category) << endl;
	printCategory(category);
    cout << "Hello World!\n";
	return 0; 
}

