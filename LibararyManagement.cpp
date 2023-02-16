#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<fstream>
const int MAX_CATEGORY_NUMBER = 100 ;
const int MAX_CATEGORY_NAME   = 100 ; 
using namespace std ;
struct Category
{
	char  Id[100]   ;
	char Name[100]  ;
};
struct Book
{
    char Id[100]    ;
	char Name[100]  ;
	int Edition     ;    	
};
struct Date
{
    int Day        ;
	int Month      ;
	int Year       ; 	
};
struct BookCopy
{
	char Id[100]      ;
	Date PurchaseDate ;
};
struct student
{
	char RegisterationNo[100] ;
	char Name[100]            ;
	int Session               ;
	Date AdmmissionDate       ;  	
}; 
bool AddCategory ()   ;
bool editCategory()   ;
bool deleteCategory() ;
void printCategory()  ;
bool isExistCategory();
bool printCategories();
bool saveCategories() ;
bool LoadCategories() ;
bool isExistBook()    ;
bool AddBook()        ;
bool deleteBook()     ;
bool printBook()      ;
bool saveBooks()      ;
bool LoadBooks()      ;
bool editBook()       ;
bool isExistBookCopy();
bool addBookCopy();
bool editBookCopy();
bool deleteBookCopy();
void printBookCopies();
bool saveBookCopies() ;
bool LoadBookCopies() ;
bool isExist()      ;
bool addStudent()   ;
bool editStudent()  ;
bool deleteStudent();
void printStudent() ;
bool saveStudent()  ;
bool LoadStudents()  ;
bool isValidCategoryNumber() ;
bool isValidBookId()      ;
bool isValidBookName()    ; 
bool isValidCopyId()      ;
bool isValidCategoryNo()  ;
bool isValidCategoryName();
bool isValidCategoryName();
bool isValidBookName()    ;
bool isValidCopyId()      ;
bool isValidBookId()      ;
bool isValidDate()        ;
bool isValidRegNo()       ;
bool isValidStudentName() ; 
bool isValidDate(Date date)
{
	bool s = true ;
	if(date.Day > 31)
	return false ;
	if(date.Month > 12)
	return false ;
	if(date.Day > 28 && date.Month == 2 )
     return false ;
    if( date.Day != 31 && date.Month %2 != 2 && date.Month < 8 )
	return false ; 
	else 
	return true ;  
}
bool isValidRegNo(char RegNo[])
{
	bool f = false ;
	if(RegNo[3] == '-' && RegNo[5] == '-')
		f = true ;
	else
		f = false ; 	
	for(int i = 0 ; i <= 2 ; i++)
	{
		f = false ;
		if(isdigit(RegNo[i]))
			f = true ;
		else 
			return f ;		
	}
	for(int i = 4 ; i <= 5 ; i++)
	{
		f = false ;
		if(isalpha(RegNo[i]))
			f = true ;
		else 
			return f ;		
	}
	for(int i = 7 ; i <= 10 ; i++)
	{
		f = false ;
		if(isdigit(RegNo[i]))
			f = true ;
		else 
			return f ;		
	}
	return f ;	
}
bool isValidStudentName(char Name[])
{
	bool k = false ;
	for(int i = 0 ; i < strlen(Name) ; i++)
	{
		k = false ;
		if(isdigit(Name[i]))
			k = true ;
		else 
			break ;
	}
	return k ;
} 
bool isValidBookId(char bookCopy[])
{
    int l = strlen(bookCopy) ; 
    if( l != 12)
    return false ;
	bool s = false ;
	int i = 0 ; 
    {
    	for(  i = 0; i <= 11 ; i++)
    	{
    		s = false ;
    		if( i > 2 && i <= 6  )
    		{
    			if(bookCopy[i] == '-' )
    			{
    			s = true ;
    		    }
    	    if( i == 4 || i ==5  )
    	      {
    	    	 if((bookCopy[i] >= 65 && bookCopy[i] <= 90) || (bookCopy[i] >= 97 && bookCopy[i] <= 122))
    	    	 { 
					 s = true;
				 } 
			  }
		   }
    		else
    		{
    			for ( int j = 48 ; j <= 57 ; j++)
    			{
    				if(bookCopy[i] == j) 
    				{
    				 s = true ;
    				 break    ;
					}
				}
			}
			if( s == false)
		    break ;
		}
	}
	return s ;
}
bool isValidCopyId(char bookCopy[])
{
	int l = strlen(bookCopy) ;
	bool s = false ;
	int i = 0 ; 
    {
    	for(  i = 0; i <= 11 ; i++)
    	{
    		s = false ;
    		if( i > 2 && i <= 6  )
    		{
    			if(bookCopy[i] == '-' )
    			{
    			s = true ;
    		    }
    	    if( i == 4 || i ==5  )
    	      {
    	    	 if((bookCopy[i] >= 65 && bookCopy[i] <= 90) || (bookCopy[i] >= 97 && bookCopy[i] <= 122))
    	    	 { 
					 s = true;
				 } 
			  }
		   }
    		else
    		{
    			for ( int j = 48 ; j <= 57 ; j++)
    			{
    				if(bookCopy[i] == j) 
    				{
    				 s = true ;
    				 break    ;
					}
				}
			}
			if( s == false)
		    break ;
		}
	}
	int count = 0 ;
	        for(int i = 13 ; i <= 15 ; i++ )
			{
				count = 0  ;
				if(bookCopy[i] >= 48 && bookCopy[i] <= 57)
				count = 1   ;
				else
				break       ;				
			}
	if( l > 16)
	return false ;
	if(count == 1 && s == true && bookCopy[12] == '#')	
    return 1 ;
    else
    return 0 ;
}  
bool isValidBookName(char BookName[] )
{   
	int g = strlen(BookName) ;
	bool s = false           ;
		    for(int i = 0 ; i < g  ; i++)
		    {
		        s = false ;
    				if ( isalpha(BookName[i])   || (BookName[i] == ',' && BookName[i+1] != ',') || (BookName[i] == ';'&& BookName[i+1] != ';' ) || (BookName[i] == ' ' && BookName[i+1] != ' ') )
						s = true  ;
					else 
					{
						s = false ;
						break ; 
			    
	 				}   
			}
   return s ;
}
bool isValidCategoryName(char CNa[] ) 
{
	int j ;
	int s = strlen(CNa) ;
	bool k = false ;
	for(int i = 0 ; i < s  ; i++ )
	{
		k = false ;
		if(isalpha(CNa[i]) || CNa[s-1] == '\n')
		k = true  ;
		else 
		break     ;
	}
	
    return k ;   
}
bool isValidCategoryNumber(char bookCopy[])
{
    int l = strlen(bookCopy) ;
    if( l != 3 )
    return false ;
	bool s = false ;
	int i = 0 ; 
    {
    	for(  i = 0; i < 3 ; i++)
    	{
    		s = false ;
    		if(isdigit(bookCopy[i]))
    		s = true ;
			if( s == false)
		    break ;
		}
	}
	return s ;
}
bool AddCategory(Category arr[] , int ArraySize  , Category newCategory ) 
{
	char k[100] = {'\0'} ; 
	for(int i = 0 ; i <= 100 ; i++)
	{
		if(!strcmp(arr[i].Id , k ))
			{
				strcpy( arr[i].Id  , newCategory.Id  );
				strcpy(arr[i].Name , newCategory.Name)  ;
			    break ;
			}
			
	}
	
	return true ;
}
bool deleteCategory(Category category[] , int ArraySize , char CatId[]) 
{
	char a[100] = {0} ;
	for(int i = 0 ; i <= 100 ; i++)
	{
		if(!strcmp(category[i].Id , CatId))
		{
			strcpy(category[i].Id,a)     ;
			strcpy(category[i].Name , a) ;
			break ;
		}
	}
	return true ;
}

bool editCategory(Category category[] , int ArraySize , char CatId[] , Category newData)
{
	for(int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(category[i].Id , CatId))
			{
				strcpy(category[i].Id , newData.Id) ;
				strcpy(category[i].Name , newData.Name)   ; 
				break ;
			}
	}
	return true ;
}

void printCategory(Category category[] , int arraySize)
{
	char a[100] = {0} ;
	cout << "CatN" ;
	cout << setfill(' ')  << setw(35) << "" ;
	cout << "CatNu" << endl  ;  
	for( int i = 0 ; i <= 100 ; i++  )
	{
			if(strcmp(category[i].Id , a ))
			{
				cout << category[i].Name  ; 
				cout << setfill(' ') << setw(30) <<""  ;
				cout << category[i].Id << endl ;
			}
	}
	return ; 
}
bool isExist( Category arr[] ,int ArraySize  , char CatId[])
{
	bool k = true ; 
	for(int i = 0 ; i <= 100 ; i++)
{
	if(!strcmp(arr[i].Id , CatId)) 
	{
		cout << "Exist" << endl ;
		k = false       ;
		break ;
	}
}
    if( k == true)
    {
    	cout << "doesn't exixt" << endl ;
	}
	return 1 ;	
}
bool saveCategories(Category category[] , int arraySize)
{
	char s = ',' ;
	char a[100] = {0} ;
	ofstream f1 ;
	f1.open("Categories.csv") ;
	char comma = ',' ;    
	for(int i = 0 ; i <= 100 ; i++)
	{
		   if(strcmp(category[i].Name , a))
		   {
			f1 << category[i].Id ;
			f1 <<',';
	        f1 << category[i].Name   ; 
		    f1 << endl ;
		   }
		    
	}
	return true ;
}
bool LoadCategories( Category category[] , int ArraySize )
{
	char a[10]  = {0};
	ifstream f2 ;
	f2.open("Categories.csv")   ;
	for(int i = 0 ; i < 50 ; i++)
	{
		if(f2.eof())
		break ;
		f2.getline(category[i].Id , 4 ,',') ;       
		f2.getline(category[i].Name , '\n') ;  
	}
	return true ;
}
bool isBookExist(Book book[] , int ArraySize , char BookId[])
{
	for(int i = 0 ; i <= 100 ; i++)
	{
		if(!strcmp(book[i].Id , BookId))
		{
			cout << "Exist : " << endl         ;
			break  ;
		}
		else
		    cout << "Doesn't Exist : " << endl ;
	}
	return 0 ;
}
bool AddBook(Book book[] , int ArraySize , Book newBook)
{
	char a[100] = {0} ;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(book[i].Id , a  ))
		{
			strcpy(book[i].Name , newBook.Name) ;
			strcpy(book[i].Id , newBook.Id)     ;
		    book[i].Edition = newBook.Edition        ;
			break ;
		}
	}
	return 1 ;
}
bool deleteBook( Book book[] , int ArraySize , char BookId[])
{
	char a[100] = {0} ; 
	for(int i =0 ; i < 100 ; i++ )
	{
		if(!strcmp(book[i].Id , BookId))
		{
			strcpy(book[i].Id , a)   ;
			strcpy(book[i].Name , a) ;
			book[i].Edition = 0 ;
			break ;
		}
	}
	return 0 ;
}
bool editBook( Book book[] , int ArraySize , char prevId[] , Book newData)
{
	for(int i = 0 ; i < 100 ; i++ )
	{
		if(!strcmp(book[i].Id , prevId ))
		{
			strcpy(book[i].Name , newData.Name );
			strcpy(book[i].Id , newData.Id)     ;
			book[i].Edition = newData.Edition   ;
		}
    }
    return 1 ;
}
bool printBook( Book book[] , int ArraySize  )
{
	bool k = true  ;
	char s[100] = {0} ;
	cout << "BookN" << "             " << "BookI" << "            " << "BookEdition" << endl ;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(strcmp(book[i].Name , s))
		{
			cout << book[i].Name    ;
			cout << "           "   ;
			cout << book[i].Id      ;
			cout << "           "   ;
			cout << book[i].Edition << endl  ; 	
		}
	}
	return 0 ;
}
bool saveBook(Book book[] , int ArraySize )
{
	char s[100] = {'\0'} ;
	ofstream f1 ;
	f1.open("Books.csv") ; 
	for(int i = 0 ; i <= 100 ; i++)
	{
		    if(strcmp(book[i].Name , s))   
		    {
		    	f1 << book[i].Name << ",";
				f1 << book[i].Id ;
				f1 << ",";
				f1 << book[i].Edition ;
		    	f1 << endl ;
			}
	}
	return 0 ;
}
bool LoadBooks(Book book[] , int ArraySize )
{
	char a[20] = {0} ;
	char discard ;
	ifstream f2 ;
	f2.open("Books.csv")  ;
	for( int j = 0 ; j < 100 ; j++)
	{
		if(f2.eof() )
			break ;
		else
			{
		    	f2.getline(book[j].Name , 59 ,',') ; 
				f2.getline(book[j].Id , 12 ,',')    ; 
				f2 >> book[j].Edition            ;
				f2.get(discard) ;
			}
	}
	return 0 ;
}
bool isExistBookCopy(BookCopy arr[], int arraySize, char copyId[])
{
	for(int i = 0 ; i < 50 ; i++)
	{
		if(!strcmp(arr[i].Id , copyId ))
		{
			cout << "Valid " << endl ;
			break ;
		}
		else
		cout << "Invalid" << endl   ;
	}
	return 1 ;
}
 bool addBookCopy(BookCopy arr[], int arraySize, BookCopy newBookCopy)
{
	char a[100] = {0} ;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(arr[i].Id , a))
		{
			strcpy(arr[i].Id , newBookCopy.Id) ;
			arr[i].PurchaseDate.Day   = newBookCopy.PurchaseDate.Day ;
			arr[i].PurchaseDate.Month = newBookCopy.PurchaseDate.Month ;
			arr[i].PurchaseDate.Year  = newBookCopy.PurchaseDate.Year ;
	        break ;
		}
	}
	return 0 ;
}
 bool editBookCopy(BookCopy arr[], int arraySize, char bookCopyId[], BookCopy newData)
{
	for( int i = 0 ; i < 100 ; i++ )
	{
		if(!strcmp(arr[i].Id , bookCopyId))
		{
			strcpy(arr[i].Id , newData.Id) ;
			arr[i].PurchaseDate.Day = newData.PurchaseDate.Day ;
			arr[i].PurchaseDate.Month = newData.PurchaseDate.Month ;
			arr[i].PurchaseDate.Year = newData.PurchaseDate.Year ;
		}
	}
	return 0 ;
}
 bool deleteBookCopy(BookCopy arr[], int arraySize, char bookCopyId[])
{
	char a[100] = {0} ;
	for( int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(arr[i].Id , bookCopyId)) 
		{
			strcpy(arr[i].Id , a ) ;
			for(int i = 0 ; i < 100 ; i++)
			{
				arr[i].PurchaseDate.Day = 0 ;
			    arr[i].PurchaseDate.Month = 0 ;
			    arr[i].PurchaseDate.Year = 0 ;
			    break ;
			}
		}
	}
	return 0 ;
}
void printBookCopies(BookCopy arr[], int arraySize, char bookId[])
{
	bool f = false ;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(arr[i].Id , bookId))
		{
			cout << bookId << endl ;
			cout << "ID : "  << arr[i].Id << endl ;
			cout << "Date : "<< arr[i].PurchaseDate.Day << "/"<< arr[i].PurchaseDate.Month << "/" << arr[i].PurchaseDate.Year << endl; 
			f = true ;
			break ;
		}
		
	}
	if ( f == false )
	{
		cout << "not present " << endl ; 
	}
}
bool saveBookCopies(BookCopy arr[], int arraySize)
{
	char a[100] = {0} ;
	ofstream f1  ;
	f1.open("BookCopies.csv") ;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(strcmp(arr[i].Id , a))
		{
			f1 << arr[i].Id ;
			f1 << ","       ;
			f1 << arr[i].PurchaseDate.Day << '-'; 
			f1 << arr[i].PurchaseDate.Month << '-'; 
			f1 << arr[i].PurchaseDate.Year  << endl ;  
		}
	}
	return 0 ;
}
bool LoadBookCopies(BookCopy arr[], int arraySize)
{
	char discard ;
	char a[100] = {0} ;
	ifstream f2  ;
	f2.open("BookCopies.csv") ;
	for(int i = 0 ; i < 50 ; i++)
	{
		if( f2.eof() )
		{
			break ;
		}
			f2.getline(arr[i].Id , 18 ,',') ;
			f2 >> arr[i].PurchaseDate.Day;
			f2.get(discard) ;
			f2 >> arr[i].PurchaseDate.Month; 
            f2.get(discard) ;
			f2 >> arr[i].PurchaseDate.Year;
			f2.get(discard) ; 
	}
	return 0 ;
	
}
bool isExist(student arr[], int arraySize, char regNo[])
{
	bool s = true ;
	for( int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(arr[i].RegisterationNo , regNo))
		{
			s = false ;
			cout << "Valid" << endl ;
			break ;
		}
	}
	if(s == true )
	cout << "Not Valid" << endl ;
	return 0 ;
}
bool addStudent(student arr[], int arraySize, student newStudent)
{
	char f[100] = {0} ;
	for ( int i = 0 ; i < 100 ; i++ )
	{
		if(!strcmp(arr[i].RegisterationNo , f))
		{
			strcpy(arr[i].RegisterationNo , newStudent.RegisterationNo);
			strcpy(arr[i].Name  , newStudent.Name) ;
			arr[i].Session = newStudent.Session    ;
			arr[i].AdmmissionDate.Day      = newStudent.AdmmissionDate.Day   ;
			arr[i].AdmmissionDate.Month    = newStudent.AdmmissionDate.Month ;
			arr[i].AdmmissionDate.Year     = newStudent.AdmmissionDate.Year  ; 
			break ;
		}
	}
	return 0 ;
}
bool editStudent( student Student[] , int arraysize , char reg[] , student newData)
{
	for( int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(Student[i].RegisterationNo , reg ))
		{
			strcpy(Student[i].RegisterationNo , newData.RegisterationNo) ;
			strcpy(Student[i].Name , newData.Name)  ;
			Student[i].Session = newData.Session ;
			Student[i].AdmmissionDate.Day = newData.AdmmissionDate.Day    ; 
			Student[i].AdmmissionDate.Month = newData.AdmmissionDate.Month    ;
			Student[i].AdmmissionDate.Year = newData.AdmmissionDate.Year    ;
		    break ;
		}		
	}		
	return 1 ; 
}
bool deleteStudent (student Student[], int arraySize, char regNo[])
{
	char a[100] ;
	for( int i = 0 ; i < 100 ; i++)
	{
		if(!strcmp(Student[i].RegisterationNo , regNo ))
		{
			strcpy(Student[i].RegisterationNo , a) ;
			strcpy(Student[i].Name , a)  ;
			Student[i].Session = 0 ;
			Student[i].AdmmissionDate.Day = 0    ; 
			Student[i].AdmmissionDate.Month = 0    ;
			Student[i].AdmmissionDate.Year = 0    ;
			break ;
		}		
	}		
	return 1 ;	
}
void printStudent(student Student[], int arraySize)
{
	char arr[100] = {'\0'};
	for(int i = 0 ; i < 100 ; i++)
	{
		if(strcmp(Student[i].RegisterationNo , arr))
		{
			cout << Student[i].RegisterationNo << "," << Student[i].Name << "," <<Student[i].Session  ;
		    cout << "," << Student[i].AdmmissionDate.Year << "-" << Student[i].AdmmissionDate.Day ;
		    cout << "-" << Student[i].AdmmissionDate.Day << endl ;
		}
	}
}
bool saveStudents(student Student[], int arraySize)
{
	ofstream f1 ;
	f1.open("Student.csv") ;
	char arr[100] = {'\0'};
	for(int i = 0 ; i < 100 ; i++)
	{
		if(strcmp(Student[i].RegisterationNo , arr))
		{
			f1 << Student[i].RegisterationNo << "," << Student[i].Name << "," <<Student[i].Session  ;
		    f1 << "," << Student[i].AdmmissionDate.Year << "-" << Student[i].AdmmissionDate.Day ;
		    f1 << "-" << Student[i].AdmmissionDate.Day << endl ;
		}
	}
}
bool LoadStudents(student Student[], int arraySize)
{
	char discard ;
	ifstream f2  ;
	f2.open("Student.csv") ;
	for(int i = 0 ; i < 100 ; i++)
	{
		while(f2.eof())
		{
			break ;
		}
		    f2.getline(Student[i].RegisterationNo , 12 , ','  ) ;
		    f2 >> Student[i].AdmmissionDate.Year ; 
			f2.get(discard)  ;
			f2 >> Student[i].AdmmissionDate.Day ; 
			f2.get(discard)  ;
		    f2 >> Student[i].AdmmissionDate.Day  ;
			f2.get(discard)  ;
	}
	return 0 ;
}
int main()
{  
        char CN[20] ;
         
		
        student Student[100] ; 
	    student newStudent   ;
	    int ArraySize ; char RegNo[100] ;
	    char prevRegNo[100]  ; 
        char regNo[100] ;
	                      
		Category category[100]    = {'\0'} ;  
		Category newCategory ;
		Book book[100]            = {'\0'} ;
		Book newBook         ;  
		char prevId[100]     ;
		char CatId[100]      ;
		char BookId[100]     ;
		char prevBId[100]    ;
		char discard         ;
		char r , f           ;
		BookCopy bookcopy[100]   ;
	    BookCopy newBookCopy;
	    Date PurchaseDate ;
	    char BCId[100] ;
		cout << "Enter the Category the option : " << endl ;   
		cin.get(r) ;
		cin.get(f) ;
		cin.get(discard) ; 
		while( r != '0' && f != 'E' ) 
		{  
				if( r == '1' && f == 'C' )
				{
					cout << "Enter the category No. to check that it is Valid : " << endl ;
					for(int i = 0 ; i <= 4 ; i++)
					{
						cin.get(CN[i]) ;
				     	if(cin.peek() == '\n')
				     	break ;
					}
					cin.get(discard) ;
					bool f = isValidCategoryNumber( CN) ;
		    	    cout << f ;
		    	    char CNa[50] ;
		    	    cout << "Enter the category Name to check that it is Valid : " << endl ;
		    	    for( int i = 0 ; i < 15 ; i++ )
		    	    {
						cin.get(CNa[i]) ;
						if(cin.peek() == '\n')
						break ;
					}
					bool k = isValidCategoryName(CNa) ;
					cout << k << endl ;
				}
				if( r == '1' && f == 'O')
		    	{
		  			cout << "Enter the category to check whether it exits :"  ;
		  			cin.getline(CatId , 50 , '\n') ;
					bool f = isExist(category , ArraySize , CatId ) ;
		    	}
		        if( r == '1' && f == 'A')
		  		{
		        cout << "Enter the Category Name : "  << endl ;
		        cin.get(newCategory.Name , 50 , '\n' ) ;
				cout << "Enter the Category Id :  " << endl   ;
				cin.get(discard) ;
				cin.get(newCategory.Id , 50 , '\n') ;
				bool s = AddCategory(category ,  ArraySize , newCategory );
            	}
    			if( r == '1'   && f == 'U')
    			{
				cout << "Enter Previous Category Id" ;
				cin.getline(prevId , 50 ,'\n')         ;
				cout << "Enter the Category Name : " << endl   ;
				cin.getline(newCategory.Name , 50 , '\n')  ;
				cout << "Enter the Category Number : " << endl ;
				cin.getline(newCategory.Id , 50 , '\n') ;
				bool f = editCategory(category , ArraySize , prevId , newCategory ) ;
	    		}
	    	    if(r == '1' && f == 'D')
	    		{
	    		cout << "Enter the category Id to delete " << endl ;
	    		cin.getline( CatId , 50  ,'\n' ) ;
	    		bool l = deleteCategory(category , ArraySize , CatId) ;
				}
	    	    if( r == '1' && f == 'P' )
		        	printCategory(category , ArraySize) ;
		        if( r == '1' && f == 'S')
			    	saveCategories( category , ArraySize ) ; 	
			    if( r == '1' && f == 'L')
					LoadCategories(category , ArraySize)   ;
				if( r == '2' && f == 'C')
				{
					char CNa[50] ;
					cout << "Enter the Book Name to check it is Valid :  " << endl ;
					cin.getline(CNa , 50 , '\n') ;
					bool f = isValidBookName( CNa) ;
		    	    cout << f << endl ;
		    	    cout << "Enter the Book Id to check Wherthe it is Valid : " << endl ;
					cin.getline(CNa , 50 , '\n')  ;
					bool k = isValidBookId(CNa) ;
					cout << k << endl ;
				}
				if( r == '2' && f == 'O')
		    	{	
		  			cout << "Enter the BookId to check whether it exits :"  ;
		  			cin.getline(BookId , 50 ,'\n') ;
					bool f = isBookExist(book , ArraySize , BookId ) ;
		    	}
		    	if( r == '2' && f == 'A')
		    	{
		    		cout << "Enter the Book Name : "  << endl ;
		        	cin.getline(newBook.Name , 50 , '\n' ) ;
					cout << "Enter the Category Id :  " << endl   ;
					cin.getline(newBook.Id , 50 , '\n')    ;
					cout << "Enter the edition : " << endl ;
					cin  >> newBook.Edition ; 
					bool s = AddBook( book ,  ArraySize , newBook  );
				}
				if(r == '2' && f == 'D')
	    		{
	    			cout << "Enter the Book Id to delete " << endl ;
	    			cin.getline( BookId , '\n' ) ;
	    			bool l = deleteBook(book , ArraySize , BookId  ) ;
				}
				if( r == '2' && f == 'U' )
				{
					cout << " Enter the previous Id:" << endl      ;
					cin.getline( prevBId , 20 ,'\n')      ;
					cout << "Enter the new book Name :" << endl      ;
					cin.getline( newBook.Name , 20 , '\n') ;
					cout << "Enter the new Book Id : \n" << endl ;
					cin.getline( newBook.Id, 20 , '\n')   ;
				    cout << "enter the EditionS : " << endl       ;
				    cin >> newBook.Edition ;
					bool k = editBook(book , ArraySize , prevBId , newBook) ;  	
				}
				if( r == '2' && f == 'P')
				{
					bool k =printBook(book , ArraySize) ;
				}
		        if( r == '2' && f == 'S')
				{
					bool s = saveBook(book , ArraySize);
				}
     			if( r == '2' && f == 'L')
				{
					bool k = LoadBooks(book , ArraySize);
				}
					if( r == '3' && f == 'O')
				{ 
					cout << " Enter the Category Number : " << endl ;
					cin.getline(BCId , 20 ,'\n' ) ;
					bool s = isExistBookCopy( bookcopy , ArraySize , BCId ) ;
				}
				if( r == '3' && f == 'A')
				{
					cout << "Enter the Book Copy Number" << endl       ; 
		    		cin.getline(newBookCopy.Id ,17 , '\n')             ;
		    	    cout << "Enter the date of parchase :" << endl      ;
					cin >> newBookCopy.PurchaseDate.Day   ;
					cout << "Enter the month of parchase :" << endl      ;
					cin >> newBookCopy.PurchaseDate.Month ;
					cout << "Enter the year of parchase :" << endl      ;
					cin >> newBookCopy.PurchaseDate.Year  ;
					bool f = addBookCopy( bookcopy , ArraySize , newBookCopy) ;	
				}
		
				if( r == '3' && f == 'U')
				{
					cout << "Enter the prev Id : " ;
					cin.getline( BCId , '\n')      ;
					cout << "Enter the new Book Copy Number" << endl   ;
					cin.getline(newBookCopy.Id , 20  , '\n')             ;
					cout << "Enter new date  : " << endl  ;
					cin  >> newBookCopy.PurchaseDate.Day  ;
					cout << "Enter new month : " << endl  ;
					cin >> newBookCopy.PurchaseDate.Month ;
					cout << "Enter new year  :  " << endl ;
					cin >> newBookCopy.PurchaseDate.Year  ;
					bool f = editBookCopy( bookcopy , ArraySize , BCId, newBookCopy) ;	
				}
				if( r == '3' && f == 'D')
				{
					cout << "enter the book you want to delete :" << endl ;
					cin.getline( BCId , 20 , '\n' ) ;
					bool s = deleteBookCopy(bookcopy , ArraySize , BCId) ;
				}
				if( r == '3' && f == 'P')
				{
					cout << "enter the book you want to print :" << endl ;
					cin.getline( BCId , 20 ,'\n' ) ;
		 	 		printBookCopies(bookcopy , ArraySize  , BCId)	;
				}
				if( r == '3' && f == 'S')
					bool f = saveBookCopies(bookcopy , ArraySize )	;  
				if( r == '3' && f == 'L')
					bool f = LoadBookCopies(bookcopy , ArraySize  )	; 	  
	    		
	    		if( r == '4' && f == 'O')
				{	
				cout << "Enter the registeration number: " << endl ;
				cin.getline(regNo , 20 , '\n')        ;
				bool s = isExist( Student , ArraySize , regNo ); 
	    		}
	    		if( r == '4' && f == 'A')
	    		{
	    		cout <<  "Enter the student name you want to add : "  << endl ;
	    		cin.getline(newStudent.Name , 20 , '\n') ;
	    		cout << "Enter the student Refn no. you want to add :   " << endl   ;
	    		cin.getline(newStudent.RegisterationNo, 20 ,  '\n') ;
	    		cout << "Enter the session you want to add : " << endl   ;
	        	cin  >> newStudent.Session ;
				cout <<	"Enter the Admmission day : " << endl   ;
				cin  >> newStudent.AdmmissionDate.Day           ;
				cout <<	"Enter the Admmission month : " << endl ;
				cin  >> newStudent.AdmmissionDate.Month         ;
				cout <<	"Enter the Admmission Year : " << endl  ;
				cin  >> newStudent.AdmmissionDate.Year          ;
				bool k = addStudent( Student , ArraySize , newStudent ) ;
			} 
		if( r == '4' && f == 'U')
			{
				cout << "Enter the prev Reg no. " << endl ;
				cin.getline(prevRegNo , 20 , '\n')        ;
				cout << " Enter the new reg No ." << endl  ;
				cin.getline(newStudent.RegisterationNo, 20 , '\n')  ;
				cout << " Enter the new Session " << endl  ;
				cin  >> newStudent.Session  ;
				cout << " Enter the year " << endl         ;
				cin  >> newStudent.AdmmissionDate.Year     ;
				cout << " Enter the Day " << endl          ;
				cin  >> newStudent.AdmmissionDate.Day      ;
				cout << " Enter the Month " << endl        ;
				cin  >> newStudent.AdmmissionDate.Month    ;
				bool f = editStudent( Student , ArraySize , prevRegNo , newStudent) ;
			}
			if( r == '4' && f == 'D') 
			{
				cout << "Enter reg no. you want to delete : " << endl ;
				cin.getline(RegNo , 20 , '\n') ;
				bool f = deleteStudent(Student , ArraySize , RegNo) ;
			} 
			if( r == '4' && f == 'P')
				printStudent( Student , ArraySize ) ;
		
			if( r == '4' && f == 'S')
				saveStudents(Student , ArraySize)    ;
			if( r == '4' && f == 'L')
				LoadStudents(Student , ArraySize)    ;
		
			cout << "enter the Option :" << endl ;
	    	cin >>r ;
	    	cin >> f ;
	    	cin.get(discard) ;
			}
        
	return 0 ;
	
}
