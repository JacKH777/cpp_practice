#include <iostream>

using namespace std;

class list{
    public:
        int num;
        char name;
        int score;
        list * next;
};

typedef class list node;

/*亦可使用
typedef class list{
    int num;
    char name;
    int score;
    list * next;
}node;
*/

typedef node * link; //定義一個新的型別名稱 link，表示指向 node 類型的指標

int main(){
    link node_head, node_current, node_last; //first node, current node, last node
    node_head = new node; //給第一個node地址

    //檢查是否成功配置記憶體
    if(!node_head){
        cout << "記憶體配置失敗";
        exit(1); //程式出現問題，強制退出
    }

    //第一組
    cout << "Num = ";
    cin >> node_head -> num;
    cout << "Name = ";
    cin >> node_head -> name;
    cout << "Score = ";
    cin >> node_head -> score;
    node_head -> next = NULL;

    node_last = node_head; //最後一個node

    //下一組
    cout << "Next num(press q to finish) = ";
    node_current = new node;

    //檢查是否成功配置記憶體
    if(!node_current){
        cout << "記憶體配置失敗";
        exit(1); //程式出現問題，強制退出
    }

    //當輸入成功，建立新的node，輸入q則結束
    while(cin >> node_current -> num){
        cout << "Name = ";
        cin >> node_current -> name;
        cout << "Score = ";
        cin >> node_current -> score;
        node_current -> next = NULL;

        node_last -> next = node_current; //node_last 所指的 next 指到 node_current
        //node_last = node_new;
        node_last = node_last -> next; //node_last 指到最後一個值

        cout << "Next num(press q to finish) = ";
        node_current = new node;

        if(!node_current){
            cout << "記憶體配置失敗";
            exit(1); //程式出現問題，強制退出
        }   
    }

    node_current = node_head; //node_current 指到最前面

    //遍歷
    cout << "all students grade :" << endl;
    while(node_current != NULL){
        cout << "Num : " << node_current -> num << " Name : " << node_current -> name << " Score : " << node_current -> score << endl;
        node_head = node_current;
        node_current = node_current -> next;
        delete node_head;
    }
    
    system("pause");
    return 0;
}