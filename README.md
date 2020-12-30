[toc]
# C++ Primer 练习项目
## 第Ⅰ部分 C++基础
### const限定符
### 字符串、向量和数组
### 函数
### 类
## 第Ⅱ部分 C++标准库
### 第8章 IO库
#### 8.1 IO类
**c++定义了一族类型来处理IO，支持从设备读取和写入的IO操作，设备可以是文件，控制台，内存(string)**
+ iostream定义了用于读写流的基本类型
+ fstream定义了读写命名文件的类型
+ 是sstream定义了读写内存string对象的类型
```
IO类中的继承关系是:
    1. ifstream 和 istringstream都继承自istream
    2. ofstream 和 ostringstream都继承自ostream
```

+ IO对象不能拷贝或者赋值
    + 不能将形参或返回类型设置为流类型
    + IO操作的函数通常以引用方式传递和返回
    + 读写IO对象会改变其状态，因此传递和返回的引用不能是const
+ IO操作的条件状态
    |function|meaning|
    |--|--|
    |s.eof()|流s到达了文件结束|
    |s.fail()|流s的IO操作失败|
    |s.bad()|流s已经崩溃|
    |s.good()|流s正常|
    |s.clear()|流s中所有条件状态位复位，将流的状态设置为有效|
    |s.clear(flags)|将流s中对应的flags条件状态复位|
    |s.setstate(flags)|将流s中对应的条件状态置位|
    |s.rdstate()|返回流s的当前条件状态，返回类型为strm::iostate|
    + 一个流一旦发生错误，其后续的IO操作都会失败。
    + 只有一个流无错的时候，我们才可以读写数据
    + 使用一个流之前应该检查它是否处于良好状态
    ```c++
    //确定一个流状态最简单的方法时将它当作一个条件来使用
    while(cin>>word)
        //ok:读操作成功
    ```
    IO库定义了4个iostate类型的constexpr值，表示特定的位模式。
    + badbit:系统级错误，一旦置位，流就无法再使用
    + failbit:可以被修正(如期望读取数值却读到字符)
    + eofbit :文件到达末尾(如果达到文件结束位置，eofbit和failbit都会置位)
    + goodbit:为0，表示流未发生错误

    **Notes：badbit、failbit、eofbit任一被置位，则检测流状态的条件会失败。我们有good,bad,fail,eof,四个函数来返回对应的条件位状态,由于good返回true iff 没有任何错误，badbit被置位时，fail也会返回true，所以good和fail表示了流的总体状态**

    ```c++
    //复位failbit和badbit，保持其他标志位不变
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit)
    ```

    
    **管理输出缓冲：**
    每个输出流都管理一个缓冲区，由于设备的写操作可能很耗时，允许操作系统将多个输出组合成单一写操作会带来很大的效率。
    导致缓冲区刷新的理由:
    + 程序正常结束
    + 缓冲区满了
    + 使用操纵符如endl/flush/ends来显式刷新缓冲区
    + 每个输出之后，我们可以用操纵符unitbuf设置流的内部状态，来清空缓冲区。默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新
    + 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联的流的缓冲区就会刷新。例如默认情况下，cin和cerr都被关联到cout。因此读cin或写cerr都会导致cout缓冲区刷新。可以使用tie()函数对一个流进行关联或者解关联。

    ```c++
    cout<< "hi"<<endl; //输出hi和一个换行，然后刷新缓冲区
    cout<< "hi"<<flush; //输出hi，然后刷新缓冲区
    cout<< "hi"<<ends; //输出hi和一个空字符，然后刷新缓冲区

    cout<< unitbuf;  //所有输出操作后都会立即刷新缓冲区
    cout<< nounitbuf; //回到正常的缓冲方式
    ```

**Notes:如果程序崩溃，缓冲区不会被刷新。**

#### 8.2 文件的输入输出
读取文件的类包含在三个头文件中，ifstream,ofstream,fstream
文件流继承了基本流的操作，比如<<,>>和getline从一个ifstream读取数据。下表中是文件流特有的操作:
|function|meaning|
|--|--|
|fstream fstrm|创建一个未绑定的文件流|
|fstream fstrm(s)|创建一个打开s文件的fstream,默认文件模式依赖fstream的类型|
|fstream fstrm(s,mode)|与前一个构造函数类似，但按指定mode打开文件|
|fstrm.open(s)|打开s文件，并与fstrm绑定|
|fstrm.close()|关闭与fstrm绑定的文件|
|fstrm.is_open()|返回bool值，判断与fstrm关联的文件是否成功打开且尚未关闭|


    
### 顺序容器
### 泛型算法
### 关联容器
### 动态内存
## 第Ⅲ部分 类设计者的工具
### 拷贝控制
### 操作重载与类型转换
### 面向对象设计
### 模板与泛型函数
### 



