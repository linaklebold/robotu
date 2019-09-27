#include<iostream>
using namespace std;
int main(){
	int n=5;
	
	for(int i=0; i <= 5; i++){
		for(int c = i; c < 5; c++){
			cout<<" ";
			}
				for(int j = 0; j < i; j++){
					cout<<"#";
				
		}
		cout<<endl;
	}
	
	return 0;
}
