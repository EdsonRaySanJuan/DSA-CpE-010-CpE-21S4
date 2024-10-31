 #include<iostream>
 #include<cstdlib>
 #include<ctime>
 
 using namespace std;
 
 int main(){
 	const int SIZE=100;
	int arr[SIZE];
	//Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	//Fill thearraywithrandomvalues
	for(int i=0; i<SIZE;++i){
		arr[i]=rand()%1000; //Generate random numbers between 0 and 999
	}
	//Print the unsorted array
	cout<<"Unsortedarray:";
	for(int i=0; i<SIZE;++i){
		cout<<arr[i]<<"";
	}
	cout<<endl;
	return 0;
}
