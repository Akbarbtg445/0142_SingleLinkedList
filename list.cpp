#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
    int noMhs;
    Node*next;
};

class LinkedList
{
    Node*START;
    public:
    LinkedList()
    {
        START = NULL;
    }
    void  addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if(START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL ) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi no Mhs tidak diijinkan\n";
                return;
            }

            Node *previous = START;
            Node *current = START;

            while((current !=NULL) && (nim >= current->noMhs))
            {
                if (nim == current->noMhs)
                {
                    cout << "\nDuplikasi noMhs tidak dijinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }
            nodeBaru->next = current;
            previous->next = nodeBaru;
            
        }
    }
    bool listEmpty()
    {
        return (START ==NULL);
    }
    bool Search(int nim, Node **previous,Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL)&& (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }
    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search (nim, &previous, &current))
        return false;

        if (current == START)
        START = START->next;
        else
        previous->next = current->next;

        delete current;
        return true;
    }
    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode !=NULL)
            {
                cout << currentNode->noMhs <<endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    LinkedList mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << "MENU" << endl;
        cout << endl << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menammpilkan semua data di dalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukan pilihan (1-5) :" << endl;
        cin >> ch;
        switch(ch)
        {
                case '1':
                {
                    mhs.addNode();
                    break;
                }
                case '2':
                {
                    if (mhs.listEmpty())
                    {
                        cout << endl << "List Kosong" << endl;
                        break;
                    }
                    cout << endl << "\nmasukan no mahasiswa yang akan di hapus :";
                    cin >> nim;
                    if (mhs.delNode(nim) == false)
                    cout << endl << "Data tidak di temukan" << endl;
                    else 
                    
                        cout << endl << "Data dengan nomor mahasiswa " << nim << "berhasil di hapus" << endl;

                    
                 }
                    break ;
                case '3':
                {
                    mhs.traverse();
                }
                break;
                case '4':
                {
                if (mhs.listEmpty() == true)
                    {
                    cout << "\nList Kosong";
                    break;
                    }
                    Node *previous, *current;
                    cout << endl << "Masukan no mahasiswa yang di cari :";
                    cin >> nim;
                    if (mhs.Search(nim, &previous, &current) == false)
                    cout << endl << "Data tidak di temukan" << endl;
                    else
                    {
                        cout << endl << "\nNo Mahasiswa :" << current->noMhs << endl;
                        cout <<"\n";
                    }
                    break;
                    case '5':
                    {
                    }
                    break;
                    default:
                    {
                        cout << "Pilihan Salah !." << endl ;
                    }
                    break;
                }  
        }while (ch != '5');
    }
}