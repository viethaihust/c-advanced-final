#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ostream>
using namespace std;
void print(ostream& os);
void remove(vector<string> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}
map<string, vector<string>> mymap;
int choice;
int songuoi;
int main()
{
    cout << "1.Doc vao danh sach tu file.\n";
    cout << "2.In danh sach tiep xuc gan.\n";
    cout << "3.Kiem tra 2 nguoi co tiep xuc gan.\n";
    cout << "4.Nhap vao mot nguoi va in danh sach tiep xuc gan cua nguoi do.\n";
    cout << "5.In nhung nguoi tiep xuc gan voi nhieu nguoi nhat.\n";
    cout << "6.In danh sach cac F1 va F2 cua nguoi nhap vao.\n";
    cout << "7.Bo sung them 1 nguoi.\n";
    cout << "8.Bo sung them thong tin tiep xuc gan giua hai nguoi.\n";
    cout << "9.In danh sach tiep xuc gan ra file.\n";
    cout << "10.Thoat chuong trinh.\n";
    do {
        cout << "Nhap lua chon:";
        cin >> choice;
        if (choice == 1)
        {
        ifstream file{"tiepXucGan.txt"};
        string line1;
        getline(file, line1);
        istringstream ss(line1);
        ss >> songuoi;
        string line;

        while(getline(file, line))
        {
                istringstream iss(line);
                string key;
                getline(iss, key, ' ');
                string value;
                vector<string> values;

                while(iss)
                {
                        if (!getline( iss, value, ' ' )) break;
                        values.push_back(value);
                }

                mymap.insert({key, values});
        }
        cout << "Doc xong du lieu.\n";
        }
        else if (choice == 2)
        {
            cout << songuoi <<endl;
            for(auto const &[key, values]: mymap)
            {
                cout << key << " ";
                for(auto const value: values)
                {
                    cout << value << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Nhap ten hai nguoi:\n";
            string ten1;
            string ten2;
            cin >> ten1;
            cin >> ten2;
            int check = 0;

            for(auto const &[key, values]: mymap)
            {
                if (key==ten1)
                for(auto const value: values)
                {
                        if (ten2==value){
                            check = 1;
                        }

                }
            }
            if (check == 1){
                cout << "Hai nguoi co tiep xuc gan.\n";
            }
            else {
                cout << "Hai nguoi khong tiep xuc gan.\n";
            }
            }
        else if (choice == 4){
            cout << "Nhap mot nguoi:\n";
            string ten1;
            cin >> ten1;
            cout << "Danh sach nhung nguoi tiep xuc gan la: ";
            for(auto const &[key, values]: mymap)
            {
                if (key==ten1)
                for(auto const value: values)
                {
                        cout << value << " ";
                        }

                }
                cout << endl;
            }
        else if (choice == 5){
            int max = 0;
            cout << "Danh sach nhung nguoi tiep xuc gan voi nhieu nguoi nhat la: ";
            for(auto const &[key, values]: mymap)
            {

                for(auto const value: values)
                {
                        if((values.size()-1) > max){
                        max = (values.size()-1);
                        }
                }
            }

            for(auto const &[key, values]: mymap)
            {

                for(auto const value: values)
                {
                        if((values.size()-1) == max){
                            cout << key << " ";
                            break;
                        }

                }

            }
            cout << endl;
        }
        else if (choice == 6){
            cout << "Nhap mot nguoi:\n";
            string ten1;
            cin >> ten1;
            cout << "Danh sach cac F1 cua nguoi do la: ";
            vector<string> F1;
            vector<string> F2;
            for(auto const &[key, values]: mymap)
            {
                if (key==ten1)
                for(auto const value: values)
                {
                        F1.push_back(value);
                }
            }

            for(auto const &[key, values]: mymap)
            {
                if (key==ten1)
                for(auto const value: values)
                {

                        for(auto const &[key, values]: mymap)
                        {
                        if (key==value)
                        for(auto const value: values)
                        {
                            for (int i=0; i<F1.size(); i++){
                            if (value != ten1 && !(find(F1.begin(), F1.end(), value) != F1.end()) ){
                                F2.push_back(value);
                            }
                            }
                        }
                        }

                }
            }


            for (int i=0; i<F1.size(); i++){
                cout << F1[i] << " ";
            }
            cout << endl;
            cout << "Danh sach cac F2 cua nguoi do la: ";
            remove(F2);
            for (int i=0; i<F2.size(); i++){
                cout << F2[i] << " ";
            }

            cout << endl;
    }

    else if (choice == 7){
            cout << "Them nguoi ten la:";
            string tenthem;
            cin >> tenthem;
            songuoi = songuoi + 1;
            string tiepxucgan;
            vector<string> values1;
            cout << "Nhap so nguoi tiep xuc gan:";
            int songuoitiepxuc;
            cin >> songuoitiepxuc;
            int count = 0;
            cout << "Nhap ten cac nguoi tiep xuc gan:\n";
            while (songuoitiepxuc != count){
                cin >> tiepxucgan;
                values1.push_back(tiepxucgan);
                count++;
            }
            mymap.insert({tenthem, values1});

    for(auto const &[key, values]: mymap)
            {
                if(find(values1.begin(), values1.end(), key) != values1.end()){
                for(auto const value: values)
                {
                        if(!(find(values.begin(), values.end(), tenthem) != values.end())){
                        mymap[key].push_back(tenthem);
                        }
                }
                }
            }

    for(auto const &[key, values]: mymap)
            {
                cout << key << " ";
                for(auto const value: values)
                {
                        cout << value << " ";
                }
                cout << endl;
            }
            cout << endl;
    }

    else if (choice == 8){
        cout << "Nhap hai nguoi can bo sung them thong tin:\n";
        string nguoithunhat;
        string nguoithuhai;
        cin >> nguoithunhat;
        cin >> nguoithuhai;
        cout << "Nhap ten nguoi can bo sung:\n";
        string tencanbosung;
        cin >> tencanbosung;
        for(auto const &[key, values]: mymap)
        {
            if (nguoithunhat == key)
            for(auto const value: values)
                {
                if(!(find(values.begin(), values.end(), tencanbosung) != values.end())){
                mymap[key].push_back(tencanbosung);
                }
                }
        }

        for(auto const &[key, values]: mymap)
        {
            if (nguoithuhai == key)
            for(auto const value: values)
                {
                if(!(find(values.begin(), values.end(), tencanbosung) != values.end())){
                mymap[key].push_back(tencanbosung);
                }
                }
        }

        mymap[tencanbosung].push_back(nguoithunhat);
        mymap[tencanbosung].push_back(nguoithuhai);
        songuoi = songuoi + 1;

        for(auto const &[key, values]: mymap)
        {
            cout << key << " ";
            for(auto const value: values)
                {
                cout << value << " ";
                }
            cout << endl;
        }
    }
    else if(choice == 9){
        ofstream outfile;
        outfile.open("tiepXucGan2.txt");
        print(outfile);
        cout << "Da in ra file text.\n";
    }

        } while (choice != 10);
    return 0;
}
void print(ostream& os)
{
    os << songuoi <<endl;
    for(auto const &[key, values]: mymap)
        {
            os << key << " ";
            for(auto const value: values)
                {
                os << value << " ";
                }
            os << endl;
        }
}
