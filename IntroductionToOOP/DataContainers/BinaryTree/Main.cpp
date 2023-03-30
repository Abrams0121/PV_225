#include <iostream>
using namespace std;

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
        if (Root == nullptr)
        {
            this->Root = new ELement(Data);
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

    void print(ELement const* Root)
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
    setlocale(LC_ALL, "");
    int n;
    cout << "¬ведите размер дерева: ", cin >> n;
    Tree tree;
    for (int i = 0; i < n; i++)
    {
        tree.insert(rand() % 100, tree.getRoot());
    }
    cout << tree.getRoot();
    cout << "\n\n";
    tree.print(tree.getRoot());
    cout << "\n\n";
    /*tree.dump2(tree.getRoot());
    cout << "\n\n";*/
    system("Pause");
}