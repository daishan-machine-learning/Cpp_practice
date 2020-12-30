#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*练习8.1*/
istream& read_print(istream& ird){
    //保存流原来的状态
    auto state = ird.rdstate();
    if(!ird.fail()){
        string content;
        while(getline(ird,content)){
            cout<<content<<endl;
        }

    }
    ird.clear(state); //重新设置各个条件位
    return ird;
}
int main1(){
    // int val;
    // cin>>val;
    // if(cin.fail()){
    //     cout<<cin.rdstate()<<endl;
    //     cout<<"IO操作失败"<<endl;
    // }else if(cin.good()){
    //     cout<<"IO操作正常"<<endl;
    //     cout<<"cin.good():"<<cin.good()<<endl;
    //     cout<<"cin.eof():"<<cin.eof()<<endl;
    // }
    //测试练习8.1
    ifstream isd("D:\\Cpp_practice\\.vscode\\tasks.json");
    auto good =read_print(isd).good();
    if(good){
        cout<<"流没有改变,仍然可以使用"<<endl;
    }else{
        cout<<"流改变了，不能继续使用"<<endl;
    }
    string str;
    //ctl+Z 然后回车
    while(cin>>str){

    }
    system("pause");
    return 0;
}
int main(){
    //测试文件模式
    ofstream os;   //隐含模式为输出和截断
    string filename = "D:\\Cpp_practice\\test.txt"; 
    os.open(filename,ofstream::out|ofstream::app);
    if(!os.fail()){
        os<<"change";
        os.close();
    }
   

}