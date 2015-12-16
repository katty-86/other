#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void write_to_file(string f, vector<string> &v);
void read_from_file(string f, vector<string> &v);
string parse_string(string &s);

int main(){
   vector<string> vec, result;
   string filename="data.txt";
   read_from_file(filename, vec);
   for(auto it=vec.begin(); it!=vec.end(); ++it){
      string conv_date= parse_string(*it);
      result.push_back(conv_date);
      cout<<*it<<" -> "<< conv_date<<"\n";
   }
   cout<<endl;
   write_to_file("result.txt", result);
}


void write_to_file(string f, vector<string> &v){
   ofstream myfile;
   myfile.open(f);
   for(auto it=v.begin(); it!=v.end(); ++it){
      myfile <<*it<<'\n';
   }
   myfile.close();

}
void read_from_file(string f, vector<string> &v){
   string line;
   ifstream myfile (f);
   if(myfile.is_open()){
       while(getline(myfile,line)){
          v.push_back(line);
       }
       myfile.close();
   }
   else{
      cout<<"Unable to open file"<<endl;
   }

}

string parse_string(string &t){
    string ret_string, year, day, mounth;
    int pos_del1=t.find_first_not_of("0123456789");	
    int pos_del2=t.find_last_not_of("0123456789");
    if(pos_del1<3){
        mounth=t.substr(0,pos_del1);
        day=t.substr(pos_del1+1, pos_del2-pos_del1-1);
        year=t.substr(pos_del2+1, t.size()-pos_del2-1);
    }
    else{
       year=t.substr(0,pos_del1);
       mounth=t.substr(pos_del1+1, pos_del2-pos_del1-1);
       day=t.substr(pos_del2+1, t.size()-pos_del2-1);
   }
   if(year.size()<4){
      ret_string.append("20");
   }
   ret_string.append(year);
   ret_string.append("-");
   if(mounth.size()<2){
     ret_string.append("0");
   }
   ret_string.append(mounth);
   ret_string.append("-");
   if(day.size()<2){
      ret_string.append("0");
   }
   ret_string.append(day);
   
   return ret_string;
}
