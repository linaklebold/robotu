#include<iostream>
using namespace std;
int main(){
	setlocale(LC_ALL, "ukr");
	int n, m;
	
	cout<<"����i�� ������ �i���i��: ";
	cin>>n;
	
	cout<<"���� ����� ���i����? ";
	cin>>m;
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<i; j++){
			if(i == m) cout<<"@";
			else cout<<"#";
		}
		cout<<endl;
	}
	
	return 0;
}
