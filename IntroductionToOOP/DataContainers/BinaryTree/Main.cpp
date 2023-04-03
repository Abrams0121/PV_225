#include <iostream>
using namespace std;

#define Delimeter "-----------------------------------------------------------------------------"

class Tree
{
    class ELement
    {
        int Data;
        ELement* pLeft;
        ELement* pRight;
    public:
        ELement(int Data, ELement* pLeft = nullptr, ELement* pRight = nullptr)
            :Data(Data),pLeft(pLeft),pRight(pRight)
        {
            cout << "EConstructor\t" << this << endl;
        }
        ~ELement()
        {
            cout << "EDestructor\t" << this << endl;
        }

        friend class Tree;

    }*Root;

public:
    const ELement* getRoot()const
    {
        return Root;
    }

    ELement* getRoot()
    {
        return Root;
    }

    Tree() :Root(nullptr)
    {
        cout << "TConstructro\t" << this << endl;
    }

    ~Tree()
    {
        
        cout << "TDestructor\t" << this << endl;
    }


    void insert(int Data,ELement* Root)
    {
        if (!this->Root)this->Root = new ELement(Data);
        if (Root == nullptr)
        {
            return;
        } 
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)Root->pLeft = new ELement(Data);
            else insert(Data, Root->pLeft);
        }
        else
        {
            if (Root->pRight == nullptr)Root->pRight = new ELement(Data);
            else insert(Data, Root->pRight);
        }
    }

    void pop_back(ELement* Root)
    {

    }

    void erase(int Data,ELement* Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        if (Root->Data == Data)
        {
            if (isLeaf(Root))
            {
                delete Root;
                Root = nullptr;
            }
            
            
        }
        else if (Data < Root->Data)
        {
            erase(Data, Root->pLeft);
        }
        else if (Data > Root->Data)
        {
            erase(Data, Root->pRight);
        }
        else return;
    }

    int max_value(ELement const* Root)
    {
        if (Root != nullptr)
        {

            if (Root->pRight != nullptr)
            {
                max_value(Root->pRight);
            }
            else return Root->Data;
        }
    }

    int min_value(ELement const* Root)
    {
        if (Root != nullptr)
        {
          
            if (Root->pLeft != nullptr)
            {
                min_value(Root->pLeft);
            }
            else return Root->Data;

        }
    }

    int Count(ELement const* Root,int count = 1)
    {
        if (Root != nullptr)
        {
            if (Root->pRight != nullptr)
            {
                count = Count(Root->pRight, ++count);
            }


            if (Root->pLeft != nullptr)
            {
                count = Count(Root->pLeft, ++count);
            }

        }
        else return 0;
        return count;
    }

    int Summ(ELement const* Root, int summ = 0)
    {

        if (Root != nullptr)
        {
            summ += Root->Data;
            if (Root->pRight != nullptr)
            {
                summ = Summ(Root->pRight, summ);
            }


            if (Root->pLeft != nullptr)
            {
               summ = Summ(Root->pLeft, summ);
            }

        }
        else return 0;
        return summ;
    }

    int Avg(ELement const* Root, int avg = 0)
    {
        return Summ(Root) / Count(Root);
    }


    int Depth(ELement const* Root, int depth = 1)
    {
        if (Root != nullptr)
        {
            if (Root->pLeft != nullptr)
            {
                depth = Depth(Root->pLeft, ++depth);
            } else if (Root->pRight != nullptr)
            {
                
                depth = Depth(Root->pRight, ++depth);
            }
            else return depth;
        }
        else return 0;
        return depth;
    }


    /*void print(ELement const* Root)
    {
        if (Root != nullptr)
        {

            cout << Root->Data<<endl;
            

            if (Root->pRight != nullptr)
            {
                print(Root->pRight);
                
            }
            
            if (Root->pLeft != nullptr) 
            {
                print(Root->pLeft);
                
            }
        }
    }*/

    void print(ELement const* Root,int depth = 0)
    {
        const int TAB_SIZE = 6;
        const std::string tabOffset(depth * TAB_SIZE, ' ');

        if (Root->pLeft) {
            print(Root->pLeft,depth + 1);
        }
        else if (!this->isLeaf(Root)) {
            std::cout << tabOffset << std::string(TAB_SIZE, ' ') << "NULL" << std::endl;
        }

        std::cout << tabOffset << Root->Data;

        if (this->isLeaf(Root)) {
            std::cout << " Leaf";
        }

        std::cout << std::endl;

        if (Root->pRight) {
            print(Root->pRight,depth + 1);
        }
        else if (!this->isLeaf(Root)) {
            std::cout << tabOffset << std::string(TAB_SIZE, ' ') << "NULL" << std::endl;
        }
    }

    bool isLeaf(ELement const* Root)const
    {
        return !Root->pLeft && !Root->pRight;
    }
    /*void dump2(ELement const* Root, std::string const& rpref = "", std::string const& cpref = "", std::string const& lpref = "")
    {
        if (!Root) return;
        if (Root->pRight)
            dump2(Root->pRight, rpref + "  ", rpref + "/", rpref + "|");
        std::cout << cpref << Root->Data << std::endl;
        if (Root->pLeft)
            dump2(Root->pLeft, lpref + "|", lpref + "\\", lpref + "  ");
    }*/
};



void main()
{
    
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int n,D;
    cout << "Введите размер дерева: ", cin >> n;
    Tree tree;
    for (int i = 0; i < n; i++)
    {
        tree.insert(rand() % 100, tree.getRoot());
    }
    cout << "\t\t\tБЛОК КОНСТРУКТОРОВ\n";
    cout << Delimeter;
    cout << "\n\n";
    tree.print(tree.getRoot());
    cout << "\n\n ВВедите число: ";
    cin >> D;
    tree.erase(D, tree.getRoot());
    cout << "\n\n";
    tree.print(tree.getRoot());
    cout << "\n\n";
    cout << "Минимальное: " << tree.min_value(tree.getRoot());
    cout << "\n\n";
    cout << "Максимальное: " << tree.max_value(tree.getRoot());
    cout << "\n\n";
    cout << "Колличество: " << tree.Count(tree.getRoot());
    cout << "\n\n";
    cout << "Сумма: " << tree.Summ(tree.getRoot());
    cout << "\n\n";
    cout << "Среднее: " << tree.Avg(tree.getRoot());
    cout << "\n\n";
    cout << "Глубина: " << tree.Depth(tree.getRoot());
    cout << "\n\n";
    system("Pause");
}