#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int size = 0;
int count = 0;
bool found = false;
int ElementIndex;
int ElementValue;
int totalElement = 0;
int choice;
char option;
void Traverse(int arr[]);
void insertElement(int arr[]);
void menu(int arr[]);
void deleteItem(int arr[]);
void single_search(int arr[]);
void countTotalElement(int arr[]);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Traverse(int arr[])
{
	for(int i=0; i<size; i++)
	 {
	 	if(i==0)
	 	 cout<<"\t "<<arr[i]<<" ";
	 	else
         cout<<arr[i] << " ";
     }
     cout<<endl<<endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void countTotalElement(int arr[])
{
	 for(int i = 0; i < size; i++)
		{
		    if(arr[i] != 0)
		        totalElement++; 
		    else
		        continue; 
		}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void insertElement(int arr[])
{
	 while(true)
	 {
	 	countTotalElement(arr);
		if(size==totalElement)
		{
		  cout<<"\t Array is full...Thank you";
		  cout<<endl;
		  cout<<"*************************************************************";
		  cout<<endl;
		  cout<<"\t Are You want to perform other operation ?(Y/N) : ";
		  cin>>option;
		  cout<<"*************************************************************";
		  option =toupper(option);
			  if(option=='N')
			    exit(0);
			  else if(option=='Y')
	          {
			    menu(arr);
			    break;
	     	  }
	        else
	     	  {
	     		cout<<endl;
	     		cout<<"\t invalid key is entered";
	     		cout<<"*************************************************************";
	     		continue;
	     		
			 }
	    }
	    
	    
		cout<<"\t Enter the index of Element : ";
  		cin>>ElementIndex;
  		
		if(ElementIndex < 0 || ElementIndex > size-1)
        {
            cout << "\t Invalid index. Please try again." ;
            cout<<"*********************************************************";
			cout<<endl<<endl;  
            continue;
        }
		
			
		cout<<"\t Enter the value of Element : ";
		cin>>ElementValue;
		
	    for(int i=size-1;i>ElementIndex;i--)
		{
				arr[i+1]=arr[i];
		}
		arr[ElementIndex] = ElementValue;
		totalElement++;
		cout << "\t Are you want to insert another? (Y/N): ";
	    cin >> option;
	    cout<<endl;
	
	    option = toupper(option);
	
	    if(option == 'N')
	    {
	    	cout<<"*************************************************************";
	    	cout<<endl;
	        cout << "\t Ok, Are you want to perform another operation ?(Y/N) : ";
	        cin>>option;
	        cout<<"*************************************************************";
		        option=toupper(option);
		        if(option=='Y')
		        {
		          menu(arr);
		          break;
		        }
		        else
		          exit(0);
	    }
	    else if(option == 'Y')
	    {
	        continue;
	    }
	    else
	    {
	        cout << "\t Entered invalid key" << endl;
	        exit(0);
		}
		cout<<endl<<endl;				
	}
	
 }
 
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void deleteItem(int arr[])
{
	while(true)
	{
			cout<<"\t Enter element value to delete : ";
			cin>>ElementValue;
			for(int i=0;i<size;i++)
			{
				if(arr[i]==ElementValue)
				{
					ElementIndex=i;
					found = true;
				}
			}
			if(found==false)
			{
				cout<<"\t Element not found..";	
				cout<<endl<<endl;
				cout<<"*************************************************************"<<endl;
			    cout << "\t Are you want to try another  value?(Y/N) : ";
			    cin>>option;
			    cout<<"*************************************************************";
			    cout<<endl<<endl;
			    option=toupper(option);
				    if(option=='Y')
				    {
				        continue;
				    }
				    else
				        {
								cout<<endl;
						        cout << "\t Ok, Are you want to perform another operation ?(Y/N) : ";
						        cin>>option;
						        cout<<"*************************************************************";
							        option=toupper(option);
							        if(option=='Y')
							        {
							          menu(arr);
							          break;
							        }
							        else
							          exit(0);	
						}
			}
			else{
					if(size==0)
					{
							cout<<"Array is empty...sorry";
							cout<<endl;
							cout<<"*************************************************************";
						    cout<<endl;
						    cout << "\t Are you want to perform another operation?(Y/N) : ";
						    cin>>option;
						    cout<<"*************************************************************";
						    option=toupper(option);
						    if(option=='Y')
						        {
						          menu(arr);
						          break;
						        }
						        else
						          exit(0);
					}	
					else
					{
						for(int i=ElementIndex;i>0;i--)
						{
							arr[i]=arr[i+1];		
						}
						totalElement--;
						cout<<"\t Element deleted successfully."<<endl<<endl;
						cout<<"*************************************************************"<<endl;
						cout << "\t Are you want to delete another value ?(Y/N) : ";
						cin>>option;
						cout<<"*************************************************************";
						cout<<endl<<endl;
					    option=toupper(option);
					    if(option=='Y')
						{
						  found=false;
						  continue;
						}
						else
						
						   cout<<endl;
						   cout<<"*************************************************************"<<endl;
							cout << "\t Are you want to perform another operation ?(Y/N) : ";
							cin>>option;
							cout<<"*************************************************************";
							cout<<endl<<endl;
						    option=toupper(option);
						    if(option=='Y')
						    {
						    	menu(arr);
						    	break;
							}
							else
							{
								exit(0);
								
							}
						   
					}		
			}
		
		}
	}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void single_search(int arr[])
{
	cout<<"\t Enter element to search : ";
	cin>>ElementValue;
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==ElementValue)
		{
			cout<<ElementValue<<" found at index "<<i;
			cout<<"*************************************************************";
			cout<<"\t Are you want to continue searching?(Y/N)";
			cin>>option;
			cout<<"*************************************************************";
			option = toupper(option);
			if(option=='N')
			 exit(0);
			else
			{
				continue;
				cout<<endl<<endl;	
			}
			 
		 	
		 }
	}
}
 
 
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void menu(int arr[])
{
	cout<<"*******************************************";
	cout<<endl;
	while(true){
	cout<<"\t 1 for Traverse"<<endl;
	cout<<"\t 2 for Insertion"<<endl;
	cout<<"\t 3 for Deletion"<<endl;
	cout<<"\t 4 for Searching"<<endl;
	cout<<"\t 5 for Sorting"<<endl;
	cout<<"\t 6 for Exit"<<endl<<endl;
	cout<<"\t Enter Your operation code : ";
	cin>>choice;
	cout<<endl;
	switch(choice)
	{
		case 1:
			Traverse(arr);
			cout<<"*************************************************************";
			cout<<endl;
			cout<<"\t Are you want to continue?(Y/N) : ";
			cin>>option;
			cout<<"*************************************************************";
			option = toupper(option);
			if(option=='N')
			 exit(0);
			else
			{
			 cout<<endl;
			 continue;
		    }
		case 2:
		    insertElement(arr);
			break;
		case 3:
		    deleteItem(arr);
			break;
		case 6:
				exit(0);
		default:
		 cout<<"\t invalid key in entered";	
	}
	
}

}
	
int main()
{
   cout<<"***************************** Welcome To The Back Bencher Project **************************************"<<endl<<endl;
   cout<<"\t Enter the size of array : ";
   cin>>size;
   int myarray[size]={0};
   menu(myarray);   
   return 0;
}
