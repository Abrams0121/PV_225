#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define DEBUG

#define Delimeter "-----------------------------------------------------------------------------"

class Tree
{
    class Element
    {
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
            :Data(Data),pLeft(pLeft),pRight(pRight)
        {
            cout << "EConstructor\t" << this << endl;
        }
        ~Element()
        {
           cout << "EDestructor\t" << this << endl;
        }

        friend class Tree;

    }*Root;

public:
    const Element* getRoot()const
    {
        return Root;
    }

    Element* getRoot()
    {
        return Root;
    }

    Tree() :Root(nullptr)
    {
        cout << "TConstructro\t" << this << endl;
    }

    Tree(const std::initializer_list<int>& il) :Tree()
    {
        for (int i : il)insert(i);
    }

    Tree(const Tree& Other) :Tree()
    {
        Copy(Other.Root);
    }
    ~Tree()
    {
        Clear();
        cout << "TDestructor\t" << this << endl;
    }
    


    void insert(int Data)
    {
        insert(Data, Root);
    }
    void Erase(int Data)
    {
        Erase(Data, Root);
    }
    int MinValue()const
    {
        return MinValue(Root);
    }
    int MaxValue()const
    {
       return MaxValue(Root);
    }
    int Sum()const
    {
       return Sum(Root);
    }
    int Count()const
    {
       return  Count(Root);
    }
    int Avg()const
    {
        return (double)Sum(Root) / Count(Root);
    }
    int Depth()const
    {
        return Depth(Root);
    }
    void Print()const
    {
        Print(Root);
        cout << endl;
    }

    void Clear()
    {
        Clear(Root);
    }
private:

    void insert(int Data,Element* Root)
    {
        if (!this->Root)this->Root = new Element(Data);
        if (Root == nullptr)
        {
            return;
        } 
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
            else insert(Data, Root->pLeft);
        }
        else
        {
            if (Root->pRight == nullptr)Root->pRight = new Element(Data);
            else insert(Data, Root->pRight);
        }
    }
    /*void erase(int Data,Element* Root)
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
    }*/

    int MaxValue(Element const* Root)const
    {
        if (Root != nullptr)
        {

            if (Root->pRight != nullptr)
            {
                MaxValue(Root->pRight);
            }
            else return Root->Data;
        }
    }

    int MinValue(Element const* Root)const
    {
        if (Root != nullptr)
        {
          
            if (Root->pLeft != nullptr)
            {
                MinValue(Root->pLeft);
            }
            else return Root->Data;

        }
    }

    int Count(Element const* Root,int count = 1)const
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

    int Sum(Element const* Root, int summ = 0)const
    {

        if (Root != nullptr)
        {
            summ += Root->Data;
            if (Root->pRight != nullptr)
            {
                summ = Sum(Root->pRight, summ);
            }


            if (Root->pLeft != nullptr)
            {
               summ = Sum(Root->pLeft, summ);
            }

        }
        else return 0;
        return summ;
    }

   


    /*int Depth(ELement const* Root, int depth = 1)const
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
    }*/


    int Depth(Element* Root)const
    {

        if (Root == nullptr)return 0;

        int l_depth = Depth(Root->pLeft) + 1;
        int r_depth = Depth(Root->pRight) + 1;
        return l_depth > r_depth ? l_depth : r_depth;
        /*if (Depth(Root->pLeft) + 1 > Depth(Root->pRight) + 1)return Depth(Root->pLeft) + 1;
        else return Depth(Root->pRight) + 1;*/
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

    void Clear(Element* Root)
    {
        if (Root == nullptr)return;
        Clear(Root->pLeft);
        Clear(Root->pRight);
        delete Root;
    }

    void Erase(int Data, Element* Root)
    {
        if (!Root) return;
        Erase(Data, Root->pLeft);
        Erase(Data, Root->pRight);
        if (Data == Root->Data)
        {
            if (isLeaf(Root))
            {
                delete Root;
                Root = nullptr;
            }
            else
            {
                if (Count(Root->pLeft)>Count(Root->pRight))
                {
                    Root->Data = MaxValue(Root->pLeft);
                    Erase(MaxValue(Root->pLeft), Root->pRight);
                }
                else
                {
                    Root->Data = MinValue(Root->pLeft);
                    Erase(MinValue(Root->pLeft), Root->pRight);
                }
            }

        }
    }

    void Copy(Element* Root)
    {
        if (!Root)return;
        insert(Root->Data, this->Root);
        Copy(Root->pLeft);
        Copy(Root->pRight);
    }
    void Print(Element const* Root,int depth = 0)const
    {
        const int TAB_SIZE = 6;
        const std::string tabOffset(depth * TAB_SIZE, ' ');

        if (Root->pLeft) {
            Print(Root->pLeft,depth + 1);
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
            Print(Root->pRight,depth + 1);
        }
        else if (!this->isLeaf(Root)) {
            std::cout << tabOffset << std::string(TAB_SIZE, ' ') << "NULL" << std::endl;
        }
    }

    bool isLeaf(Element const* Root)const
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

//#define Check1
#define DepthCheck

void main()
{
    




    srand(time(NULL));
    setlocale(LC_ALL, "");

#ifdef Check1
    int n,D;
    cout << "Введите размер дерева: ", cin >> n;
    Tree tree;
    for (int i = 0; i < n; i++)
    {
        tree.insert(rand() % 100);
    }
    cout << "\t\t\tБЛОК КОНСТРУКТОРОВ\n";
    cout << Delimeter;
    cout << "\n\n";
    /*tree.Print();
    cout << "\n\n ВВедите число: ";
    cin >> D;
    tree.erase(D);
    cout << "\n\n";
    tree.Print();*/
    cout << "\n\n";
    cout << "Минимальное: " << tree.MinValue();
    cout << "\n\n";
    cout << "Максимальное: " << tree.MaxValue();
    cout << "\n\n";
    cout << "Колличество: " << tree.Count();
    cout << "\n\n";
    cout << "Сумма: " << tree.Sum();
    cout << "\n\n";
    cout << "Среднее: " << tree.Avg();
    cout << "\n\n";
    cout << "Глубина: " << tree.Depth();
    cout << "\n\n";
    system("Pause");
#endif // Check1

#ifdef DepthCheck
    Tree tree = { 50,25,75,16,32,64,80,48,49 };
    tree.Print();

    Tree tree2 = tree;
    tree2.Print();
    cout << "Глубина: " << tree.Depth() << endl;
#endif // DEBUG

    
}