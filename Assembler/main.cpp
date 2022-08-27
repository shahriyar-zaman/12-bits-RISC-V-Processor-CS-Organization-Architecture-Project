#include <bits/stdc++.h>

using namespace std;

// Function to convert binary to decimal
string binaryToHexadecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;
    bool check = true;
    for(int i = 0; i < 4; ++i) {
        if(n[i] == '1') {
            check = false;
            break;
        }
    }
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    stringstream ss;
    ss << hex << dec_value;
    string result = ss.str();
    if(check){
        string tmp = "0" + result;
        return tmp;
    }
    return result;
}

// Function that convert Decimal to binary
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string s;
    for (int i = 2; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s.push_back('1');
        else
            s.push_back('0');
    }

    return s;
}

//It will use for jump because as i took jumps value as atmost 9 bits number
string SpecialdecToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string s;
    for (int i = 8; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s.push_back('1');
        else
            s.push_back('0');
    }

    return s;
}

//It will operate jump operation
// example j 7
string jump(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);
//    for(auto& x : tmp) {
//        cout << x << endl;
//    }

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 'j') {
            tmpstr2 += "111";
        }else {
//            tmpstr2 += "000000";
            int x = stoi(tmp[i]);
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();

            tmpstr2 += SpecialdecToBinary(x);
        }
    }
    return binaryToHexadecimal(tmpstr2);
}

//it will do I-type operation
//for example andi $R1, $R2, 4;
string andi(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 'a') {
            tmpstr2 += "110";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            string t(1, tmp[i][2]);
//            tmpstr2 += decToBinary(t);
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }else {
            int x = tmp[i][0] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }
    }

    return binaryToHexadecimal(tmpstr2);
}

//It will do the store operation.
//Example: SW $R3, 2($R1)
string sw(string s) {
    vector <string> tmp;
    cin.ignore();
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    string track1, track2, track3;
    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 's') {
            tmpstr2 += "011";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            track1 = decToBinary(x);
        }else {
            int x = tmp[i][0] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            track2 = decToBinary(x);
            x = tmp[i][4] - '0';
//            stringstream xx;
//            xx << hex << x;
//            string re = xx.str();
            track3 = decToBinary(x);

        }
    }
    tmpstr2 += track3;
    tmpstr2 += track1;
    tmpstr2 += track2;
    return binaryToHexadecimal(tmpstr2);
}

//It will do load opeartion
//For example: LW $R3, 1($R2)

string lw(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    string track1, track2, track3;
    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 'l') {
            tmpstr2 += "010";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            track1 = decToBinary(x);
        }else {
            int x = tmp[i][0] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            track2 = decToBinary(x);
            x = tmp[i][4] - '0';
//            stringstream xx;
//            xx << hex << x;
//            string re = xx.str();
            track3 = decToBinary(x);

        }
    }
    tmpstr2 += track3;
    tmpstr2 += track1;
    tmpstr2 += track2;

    return binaryToHexadecimal(tmpstr2);
}

//It will do I-type instruction.
//For example: subi $R1, $R2, 3
string subi(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 's') {
            tmpstr2 += "101";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }else {
            int x = tmp[i][0] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }
    }

    return binaryToHexadecimal(tmpstr2);
}

//It will do R-Type instruction.
//For example: sub $R1, $R2, $R3
string sub(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 's') {
            tmpstr2 += "001";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }
    }

    return binaryToHexadecimal(tmpstr2);
}

//It will perform add operation.
// For example: add $R1, $R2, $R3
string add(string s) {
    vector <string> tmp;
    string tmpstr1, tmpstr2;
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 'a') {
            tmpstr2 += "000";
        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }
    }
    return binaryToHexadecimal(tmpstr2);
}

//It will peform I-type instruction.
//For example: addi $R1, $R2, 2
string addi(string s) {
    vector <string> tmp;
    string tmpstr1="", tmpstr2="";
    for(int i = 0; i < s.size(); ++i) {
       if(s[i] == ' ') {
            tmp.push_back(tmpstr1);
            tmpstr1.clear();
            continue;
       }
        else {
            tmpstr1.push_back(s[i]);
       }
    }
    tmp.push_back(tmpstr1);

    for(int i = 0; i < tmp.size(); ++i) {
        if(tolower(tmp[i][0]) == 'a') {
            //tmpstr2 += "0";
            tmpstr2 += "100";

        }else if(tmp[i][0] == '$') {
            int x = tmp[i][2] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }else {
            int x = tmp[i][0] - '0';
//            stringstream ss;
//            ss << hex << x;
//            string result = ss.str();
            tmpstr2 += decToBinary(x);
        }
    }

    return binaryToHexadecimal(tmpstr2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    // associates standard output with output.txt
    // (this will create a new file called output.txt if none exists)
    freopen("output.txt", "w", stdout);
    string x;
    // reads the input.txt file and stores in string x
    //Storing all the Assembly code on the dynamic container vector.
    vector <string> s;
    while(getline(cin, x)) {
        s.push_back(x);
    }
    //overall checking all instructions. And calling the functions respectively.
    for(int i = 0; i < s.size(); ++i) {

        char ch = tolower(s[i][0]);
        string str;
        if(ch == 'a') {
            if(tolower(s[i][1]) == 'd') {

                if(tolower(s[i][3]) == 'i') {
                    //addi
                    str = addi(s[i]);
                }else {
                    //add
                    str = add(s[i]);
                }
            }else {
                //andi
                str = andi(s[i]);
            }

        }else if(ch == 's') {

            if(tolower(s[i][1]) == 'u') {

                if(tolower(s[i][3]) == 'i') {
                    //subi
                    str = subi(s[i]);
                }else {
                    //sub
                    str = sub(s[i]);
                }

            }else {
                //sw
                str = sw(s[i]);
            }
        }else if(ch == 'l') {
            //lw
            str = lw(s[i]);

        }else if(ch == 'j') {
            //jump
            str = jump(s[i]);
        }
        //writing the value on file.
        cout << str << endl;
        str.clear();
    }
}
