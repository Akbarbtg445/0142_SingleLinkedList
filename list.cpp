#include <iostream>
#include <string>
using namespace std;

class node 
{
    public:
    int noMhs;
    node*next;
};

class list
{
    node*START;
    public:
    list()
    {
        START = NULL;
    }
    void  addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Mahasiswa: ";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs = nim;

        if(START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL ) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi no Mhs tidak diijinkan\n";
                return;
            }

            node *previous = START;
            node *current = START;

            while((current !=NULL) && (nim >= current->noMhs))
        }
    }
};
