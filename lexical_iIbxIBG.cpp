#include<bits/stdc++.h>
using namespace std;


vector<char>v = {'+','-','*','/','!','%','^','&','=','~','|','.','<','>','/','?'};
vector<char>sep = {'\t','\n',';','(',')','{','}','[',']','\\','<', '>'};
vector<string> keys ={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while","printf","scanf","main"};

int operators(char x){
	set<char>op(v.begin(),v.end());
	auto it = op.find(x);
	if(it!=op.end()){
	        return 1;
	}
	return 0;
}

int separators(char x){
	set<char>op(sep.begin(),sep.end());
	auto it = op.find(x);
	if(it!=op.end()){
	        return 1;
	}
	return 0;
}

int keywords(string x){
        set<string>k(keys.begin(),keys.end());
        auto it = k.find(x);
        if(it!=k.end()){
                return 1;
        }
        return 0;
}


int main(){
	string file;
	cout<<"ENTER THE FILE NAME\n";
	cin>>file;
	ifstream infile(file);
	char ch;
	string str;
	string curr="";
	while( (ch=infile.get())){
		if(ch==EOF){
			cout<<"BREAK OVER";
			break;
		}
		if(ch == '#'){
			cout<<ch;
			while((ch=infile.get())!='\n'){
				cout<<ch;
			}
			cout<<" : is a preprocessor directive\n";
			continue;
		}
		if(separators(ch)){
	        cout<<ch<<":"<<"is a separator"<<endl;
	        continue;
	    }
	    if(operators(ch)){
	        cout<<ch<<":"<<"is a operator"<<endl;
	        continue;
	    }
	    curr+=ch;
	    char t;
	    while((t=infile.get() )){
	        if(t==' '){
	                break;
	        }
	        curr+=t;
	    }
	    if(keywords(curr)){
	        cout<<curr<<": is a keyword"<<endl;
	    }
	    else{
			cout<<curr<<": is an identifier"<<endl;
			
		}
		curr="";
	}
	return 0;
}
