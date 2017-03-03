#include <iostream>
using namespace std;

class MyException {
	public:
	int what() {return 123;}
	};

class Array
{
	int * p;
	int size;
	
public:
	Array(int n){ 
		size = n; 
		p = new int [size];
		for (int i = 0; i < size; i++)
        {
            p[i] = 0;
        }
	}
	~Array(){ delete [] p; }
		
	Array& operator= (Array &obj){
		delete [] p;
		size = obj.size;
        p = new int [size];
		for (int i = 0; i < size; i++)
        {
            p[i] = obj.p[i];
        }
        return *this;
		}
		
	int& operator[](int index) { 
		if ((index >= 0) && (index < size))
		return p[index];
		else
		{
			throw MyException();
		}
		}

	void showArr()
    {
        for(int i = 0; i < size; i++){
            cout << p[i] << endl;
        }
    
    }
    friend bool operator ==( Array &ar1, Array &ar2 );
 };
	
	
	bool operator ==( Array &ar1, Array &ar2 ){
    if (ar1.size != ar2.size) 
    {
        cout << "Different size" << endl;
        return 0;
    }
    else 
    {      
        for (int i = 0; i < ar1.size; i++) {
            if(ar1.p[i] != ar2.p[i]) {
                cout << "Array values are not equal";
                return 0;
            }              
        }  
    }
return 1;
}


	
int main()
{
	Array arr1(5);
	Array arr2(4);
try {
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	arr1[4] = 6;
	
	arr2[0] = 5;
	arr2[1] = 6;
	arr2[2] = 7;
	arr2[3] = 8;
	
	
	arr1 = arr2;
	
		
	if (arr1 == arr2){ 
        cout << "Equal mas" << endl;
    }
    else {
        arr1 = arr2;
    }
    cout << "After copy: " << endl;
    arr1.showArr();
    
} catch (MyException e) {cout << "Wrong index" << e.what() << endl;}
	
}


