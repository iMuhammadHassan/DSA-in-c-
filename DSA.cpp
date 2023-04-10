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
void modifyarray(int arr[]);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Traverse(int arr[])
{
	if(totalElement==0)
	{
		cout<<"\t Array is empty"<<endl<<endl;
	}
	for(int i=0; i<totalElement; i++)
	 {
	 	if(i==0)
	 	 cout<<"\t "<<arr[i]<<" ";
	 	else
         cout<<arr[i] << " ";
     }
     cout<<endl<<endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void modifyarray(int arr[])
{
	int var;
	cout<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"\t Enter the size to increment in this array : ";
	cin>>var;
	cout<<"********************************************************************"<<endl;
	 size+=var;
	 cout<<endl;
	 cout<<"\t Size modifiied successfully"<<endl<<endl;
	 for(int i=size-var;i<size;i++)
	 {
	 	arr[i]=0;
	 }
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
			    return;
	     	  }
	        else
	     	  {
	     		cout<<endl;
	     		cout<<"\t invalid key is entered";
	     		cout<<"*************************************************************";
	     		return;
	     		
			 }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void insertElement(int arr[])
{
	 while(true)
	 {
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
		    found=false;
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
			if(!found)
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
//						arr[ElementIndex] = 0;
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
			cout<<ElementValue<<" found at index "<<i<<endl;
			cout<<"*************************************************************";
			cout<<"\t Are you want to continue searching?(Y/N) : ";
			cin>>option;
			cout<<"\n*************************************************************";
			option = toupper(option);
			if(option=='N')
			{
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
			 
			else
			{
				break;
				single_search(arr);
				cout<<endl<<endl;	
			}
			 
		 	
		 }
	}
}
 
 
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void multi_Search(int arr[])
{
	count=0;
	cout<<"\t Enter Value to search : ";
	cin>>ElementValue;
	for(int i=0;i<totalElement;i++)
	{
		if(arr[i]==ElementValue)
		{
			found=true;
			count++;
		}
	}
	if(!found)
	{
		cout<<endl;
		cout<<"\t Item is not found"<<endl;		
	}
	else
	{
		cout<<"\t "<<ElementValue<<" found "<<count<<" times in this array"<<endl<<endl;
	}
}
void bubble_sort(int arr[])
{
	for(int i=0;i<totalElement;i++)
	{
		int j = i+1;
		for(j;j<totalElement;j++)
		{
			if(arr[i] > arr[j])
			{
				int temp;
				temp   = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void insertion_sort(int arr[])
{
	for(int i=1;i<5;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j] > arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void selection_sort(int arr[])
{
	for(int i=0;i<5;i++)
	{
		int min_index=i;
		for(int j=i+1;j<5;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		
		int temp = arr[min_index];
		arr[min_index]=arr[i];
		arr[i]   = temp;
			
	}
	
	for(int k=0;k<5;k++)
	{
		cout<<arr[k]<<endl;
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
	cout<<"\t 6 for Modify Array size"<<endl;
	cout<<"\t 7 for Exit"<<endl;
	cout<<"\t 8 for multi_Search"<<endl;
	cout<<"\t 9 for bubble_sort"<<endl;
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
		case 4:
		    single_search(arr);
			break;
		case 6:
			modifyarray(arr);
				
		case 7:
				exit(0);
		case 8:
			multi_Search(arr);
			break;
		case 9:
			bubble_sort(arr);
			break;
		default:
		 cout<<"\t invalid key in entered";	
	}
	
}

}
	
int main()
{
   cout<<"***************************** Welcome To The Back Bencher Project **************************************"<<endl<<endl;
//   cout<<"\t Enter the size of array : ";
//   cin>>size;
//   int myarray[size]={0};
//   menu(myarray); 
//int amyarr[5]={2,500,100,10,1};
//insertion_sort(amyarr);  
//selection_sort(amyarr);
   return 0;
}
