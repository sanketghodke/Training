#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class details{
        public:
        string lastName[15], firstName[15],middleName[10],nickName[5],houseNo[20],streetAddress[15],City[15],State[15],Zip[6];
};

void print_vector(vector<string> input)
{
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<endl;
        }
}
vector<string> return_seperated_vector(vector<string> input){
    
    string temp_str;
    vector<string> temp_vec;
    for(int i=0;i<input.size();i++){
            temp_str=input[i].substr(0,15);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(15,15);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(30,15);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(45,10);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(55,5);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(60,20);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(80,15);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(95,15);    
            temp_vec.push_back(string(temp_str));

            temp_str=input[i].substr(110,6);    
            temp_vec.push_back(string(temp_str));

    }
    return temp_vec;
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


string trim_utility(string input1, string input2){
    string output,temp_str;
    int b_spaces=input1.size();
    input1=removeSpaces(input1);
    b_spaces=b_spaces-input1.size();
    for(int i=0;i<b_spaces;i++){
        temp_str=temp_str+" ";
    }
    output=input1+" "+input2+temp_str;
    return output;    
}

string trim_utility_for_comma(string input1, string input2){
    string output,temp_str;
    int b_spaces=input1.size();
    input1=removeSpaces(input1);
    b_spaces=b_spaces-input1.size();
    for(int i=0;i<b_spaces-1;i++){
        temp_str=temp_str+" ";
    }
    input2=removeSpaces(input2);

    output=input1+" "+input2+","+temp_str;
    return output;    
}


void output_format1(vector<string> input){
    
    for(int i=0;i<input.size();i=i+9){
        cout<<trim_utility_for_comma(string(input[i+1]),string(input[i]))<<endl;
        cout<<trim_utility_for_comma(string(input[i+4]),string(input[i+5]))<<endl;
        cout<<removeSpaces(input[i+6])<<","<<" "<<trim_utility(string(input[i+7]),string(input[i+8]))<<endl;
    }
}

void output_format3(vector<string> input){
    
    for(int i=0;i<input.size();i=i+9){
        cout<<"\""<<removeSpaces(input[i+1])<<" "<<removeSpaces(input[i])<<"\""<<","<<"\""<<removeSpaces(input[i+4])<<" "<<removeSpaces(input[i+5])<<"\""<<","<<"\""<<removeSpaces(input[i+6])<<", "<<removeSpaces(input[i+7])<<" "<<removeSpaces(input[i+8])<<"\""<<endl;
    }
}

void output_format2(vector<string> input){
    
    for(int i=0;i<input.size();i=i+9){
        cout<<trim_utility(string(input[i+1]),string(input[i]))<< trim_utility(string(input[i+4]),string(input[i+5]))<<removeSpaces(input[i+6])<<", "<<trim_utility(string(input[i+7]),string(input[i+8]))<<endl;
    }
}


int main(){
    ofstream fout;
    string line;
    ifstream myfile("sample_input.in");
    vector<string> input;
    vector<string> filtered_input;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
        input.push_back(string(line));

        }
        myfile.close();
    }

    else {
        cout << "Unable to open file"; 
    }
    //print_vector(input);
    filtered_input= return_seperated_vector(input);
    for(int i=0;i<filtered_input.size();i++){
        //cout<<filtered_input[i]<<endl;
    }

    //OUTPUT FORMAT 1
    output_format1(filtered_input);
    output_format2(filtered_input);
    output_format3(filtered_input);
    return 1;
}