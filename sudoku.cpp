#include "sudoku.h"
Sudoku::Sudoku() {
    for(int i=0; i<sudokuSize; ++i)
        map[i] = 0;
    ansNum=0;
    n=0;
    row_index=0;
    col_index=0;
    cell_index=0;
}

Sudoku::Sudoku(const int init_map[]) {
    for(int i=0; i<sudokuSize; ++i)
        map[i] = init_map[i];
}

int Sudoku::getFirst() {
    int f=0;
    while(map[f]!=0) ++f;
    return f;
}

void Sudoku::setMap(const int set_map[]) {
    for(int i=0; i<sudokuSize; ++i) {
        map[i] = set_map[i];
        if(map[i]!=0)
            boolmap[i]=1;
        else
            boolmap[i]=0;
    }
}

int Sudoku::noneZero() {
    for(int i=0; i<sudokuSize; ++i)
        if(map[i]!=0)
            ++n;
    return n;
}

void Sudoku::printAns() {
    if(ansNum==1) {
        cout<<ansNum<<endl;
        for(int i=0; i<sudokuSize; ++i) {
            cout<<firstAns[i];
            if(i%9==8) cout<<endl;
            else cout<<" ";
        }
    } else {
        if(ansNum>1) ansNum=2;
        cout<<ansNum<<endl;
    }
}

void Sudoku::print(bool on) {
    if(on) {
        for(int i=0; i<sudokuSize; ++i) {
            cout<<map[i];
            if(i%9==8) cout<<endl;
            else cout<<" ";
        }
    }
}

void Sudoku::setKey() {
    for(int i=0; i<sudokuSize; ++i) {
        row[i]=9*(i/9);
        col[i]=i%9;
        cell[i]=27*(i/27)+3*((i%9)/3);
    }
}

int Sudoku::getElement(int index) {
    return map[index];
}

void Sudoku::changeNum(int a,int b) {
    for(int i=0; i<sudokuSize; ++i) {
        if(map[i]==a)
            map[i]=b;
        else if(map[i]==b)
            map[i]=a;
    }
}

void Sudoku::changeRow(int a,int b) {
    if(a<0||a>2||b<0||b>2) {
    } else {
        int temp[sudokuSize];
        for(int i=0; i<sudokuSize; ++i)
            temp[i]=map[i];
        for(int i=0; i<27; ++i) {
            map[27*a+i]=temp[27*b+i];
            map[27*b+i]=temp[27*a+i];
        }
    }
}

void Sudoku::changeCol(int a,int b) {
    if(a<0||a>2||b<0||b>2) {
    } else {
        int temp[sudokuSize];
        for(int i=0; i<sudokuSize; ++i)
            temp[i]=map[i];
        for(int i=0; i<3; ++i)
            for(int j=0; j<9; ++j) {
                map[9*j+3*a+i]=temp[9*j+3*b+i];
                map[9*j+3*b+i]=temp[9*j+3*a+i];
            }
    }
}

void Sudoku::rotate(int times) {
    while(times>0) {
        --times;
        int temp[sudokuSize];
        for(int i=0; i<sudokuSize; ++i)
            temp[i]=map[i];
        for(int i=0; i<sudokuSize; ++i) {
            map[(8-i/9)+9*(i%9)]=temp[i];
        }
    }
}

void Sudoku::mirror(int key) {
    if(key<0||key>1) {
    } else {
        int temp[sudokuSize];
        for(int i=0; i<sudokuSize; ++i)
            temp[i]=map[i];
        if(key==0) {
            for(int i=0; i<sudokuSize; ++i)
                map[i]=temp[9*(8-i/9)+i%9];
        } else {
            for(int i=0; i<sudokuSize; ++i)
                map[i]=temp[9*(i/9)+8-i%9];
        }
    }
}

void Sudoku::generate() {
    srand(time(NULL));
    int transNum=rand()%5+10;
    int mode,x,y;
    while(transNum>0) {
        mode=1+rand()%5;
        switch(mode) {
        case 1:
            x=rand()%9+1;
            while((y=rand()%9+1)==x);
            changeNum(x,y);
            break;
        case 2:
            x=rand()%3;
            while((y=rand()%3)==x);
            changeRow(x,y);
            break;
        case 3:
            x=rand()%3;
            while((y=rand()%3)==x);
            changeCol(x,y);
            break;
        case 4:
            x=rand()%10+1;
            rotate(x);
            break;
        case 5:
            x=rand()%2;
            mirror(x);
            break;
        }
        --transNum;
    }
    print(true);
}
void Sudoku::transform() {
    int mode,x,y;
    while(cin>>mode) {
        switch(mode) {
        case 0:
            print(true);
            break;
        case 1:
            cin>>x>>y;
            changeNum(x,y);
            break;
        case 2:
            cin>>x>>y;
            changeRow(x,y);
            break;
        case 3:
            cin>>x>>y;
            changeCol(x,y);
            break;
        case 4:
            cin>>x;
            rotate(x);
            break;
        case 5:
            cin>>x;
            mirror(x);
            break;
        default:
            break;
        }
        if(mode==0) break;
    }
}

void Sudoku::solve(int temp,int total) {
    if(map[temp]!=0&&temp<80) {
        solve(temp+1,total);
    } else {
        bool illegal_index[10]= {0};
        LegalNum(temp,illegal_index);//找到當前index不可填入的值並存在陣列
        for(int num=1; num<10; ++num) {
            if(illegal_index[num]==0) {
                map[temp]=num;
                if(total==80) {
                    ++ansNum;
                    if(ansNum>1) return;
                    else if(ansNum==1)
                        for(int i=0; i<sudokuSize; ++i)
                            firstAns[i]=map[i];
                    map[temp]=0;
                    return;
                }
                solve(temp+1,total+1);
                if(ansNum>1) return;
            }
        }
        map[temp]=0;
    }
}


void Sudoku::LegalNum(int index,bool check[]) {
    row_index=row[index];
    col_index=col[index];
    cell_index=cell[index];
    check[map[row_index]]=1;
    check[map[row_index+1]]=1;
    check[map[row_index+2]]=1;
    check[map[row_index+3]]=1;
    check[map[row_index+4]]=1;
    check[map[row_index+5]]=1;
    check[map[row_index+6]]=1;
    check[map[row_index+7]]=1;
    check[map[row_index+8]]=1;
    check[map[col_index]]=1;
    check[map[col_index+9]]=1;
    check[map[col_index+18]]=1;
    check[map[col_index+27]]=1;
    check[map[col_index+36]]=1;
    check[map[col_index+45]]=1;
    check[map[col_index+54]]=1;
    check[map[col_index+63]]=1;
    check[map[col_index+72]]=1;
    check[map[cell_index]]=1;
    check[map[cell_index+1]]=1;
    check[map[cell_index+2]]=1;
    check[map[cell_index+9]]=1;
    check[map[cell_index+10]]=1;
    check[map[cell_index+11]]=1;
    check[map[cell_index+18]]=1;
    check[map[cell_index+19]]=1;
    check[map[cell_index+20]]=1;
}

void Sudoku::sortIndex() {
    int empty=sudokuSize-n,test,row_index,col_index,cell_key,cell_index,temp_num,max_num,next_index;
    zeroIndex=new int[empty*9];
    for(int set=0; set<sudokuSize-n; ++set) {
        max_num=-1;
        for(int index=0; index<sudokuSize; ++index) {
            if(boolmap[index]==0) {
                temp_num=0;
                row_index=row[index];
                for(int i=0; i<9; ++i) {
                    test=boolmap[row_index+i];
                    if(test==1)
                        ++temp_num;
                }
                col_index=col[index];
                for(int i=0; i<81; i+=9) {
                    test=boolmap[col_index+i];
                    if(test==1)
                        ++temp_num;//check col
                }
                cell_index = cell[index];
                for(int i=0; i<27; i+=9) {
                    for(int j=0; j<3 ; ++j) {
                        test=boolmap[cell_index+i+j];
                        if(test==1)
                            ++temp_num;//check cell
                    }
                }
                if(temp_num>max_num) {
                    max_num=temp_num;
                    next_index=index;
                }
            }
        }
        boolmap[next_index]=1;
        zeroIndex[set]=next_index;
    }
}
