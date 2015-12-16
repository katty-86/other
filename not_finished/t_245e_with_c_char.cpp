#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void write_to_file(string f, vector<string> &v);
void read_from_file(string f, vector<string> &v);
void parse_string(char *t);

int main(){
   vector<string> vec;
   string filename="data.txt";
   read_from_file(filename, vec);
   for(auto it=vec.begin(); it!=vec.end(); ++it){
      cout<<*it;
      char *tmp= new char[it->size()+1];
      copy(it->begin(), it->end(),tmp);
      tmp[it->size()]='\0';
      parse_string(tmp);


     delete []tmp;
   }
}


void write_to_file(string f, vector<string> &v){
   ofstream myfile;
   myfile.open(f);
   myfile <<"write this to file\n";
   myfile.close();

}
void read_from_file(string f, vector<string> &v){
   string line;
   ifstream myfile (f);
   if(myfile.is_open()){
       while(getline(myfile,line)){
          cout<<line<<'\n';
          v.push_back(line);
       }
       myfile.close();
   }
   else{
      cout<<"Unable to open file"<<endl;
   }

}

void parse_string(char *t){
    int length=sizeof(t)/sizeof(char);
    int licznik;
    int position=0;
    cout<<length<<endl;
    char *tmpdate= new char[length];
    if(t[3]=='-') &&(t[5]=='-'){
       cou<<"correct"<<endl;
    }
    else{
        for(int i=0; i<length;i++){
           cout<<t[i]<<endl;
	   if(isdigit(t[i])){
           
           }

    }
	

}
