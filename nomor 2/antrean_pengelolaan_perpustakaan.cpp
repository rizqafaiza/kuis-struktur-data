#include<iostream>

struct antre{
    std::string data;
    antre* next;

    antre(std::string nama){
        data = nama;
        next = nullptr;
    }
};

antre* front;
antre* rear;
antre* current;

void queue(std::string nama){
    antre* baru= new antre(nama);
    if(front==nullptr){
        front=baru;
        rear=baru;
    } else {
        rear->next=baru;
        rear=baru;
    }
}

void display_queue(){
    current=front;
    int i=1;
    while(current!=nullptr){
        std::cout << "Antrean ke " << i << ": "<< current->data ;

        i++;
        current=current->next;
        std::cout<<std::endl;
    }
}

struct pengembalian{
    int id_buku;
    pengembalian* next;

    pengembalian(int id){
        id_buku=id;
        next=nullptr;
    }
};

pengembalian* top;
pengembalian* sekarang;

void stack(int id){
    pengembalian* baru=new pengembalian(id);

    if(top==nullptr){
        top=baru;
    } else {
        baru->next=top;
        top=baru;
    }
}

void display_stack(){
    sekarang = top;

    if (sekarang == nullptr) {
        std::cout << "Stack kosong!\n";
        return;
    }

    while (sekarang != nullptr) {
        std::cout << "ID Buku: "
                  << sekarang->id_buku << std::endl;

        sekarang = sekarang->next;
    }

}

struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int id_buku){
        id=id_buku;
        left=nullptr;
        right=nullptr;
    }
};

Node* root = nullptr;

void insert(Node*& root, int id_buku) {
    if (root == nullptr) {
        root = new Node(id_buku);
        return;
    }

    if (id_buku < root->id) {
        insert(root->left, id_buku);
    }
    else if (id_buku > root->id) {
        insert(root->right, id_buku);
    }
}

void preOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->id << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->id << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->id << " ";
    }
}

void bst(Node* root){
    std::cout << "preorder: \n";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "inorder: \n";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "postorder: \n";
    postOrder(root);
    std::cout << std::endl;
}

int main(){
    int jumlah;
    std::string nama;
    int id;

    insert(root, 45);
    insert(root, 25);
    insert(root, 65);
    insert(root, 15);
    insert(root, 35);
    insert(root, 55);
    insert(root, 75);

    std::cout << "Jumlah peminjam: ";
    std::cin >> jumlah;

    std::cout << "Masukkan Nama untuk Antre: \n";
    for (int i = 0; i < jumlah; i++) {
        std::cout << "Masukkan nama peminjam ke-" << i + 1 << ": ";
        std::cin >> nama;

        queue(nama);
    }

    std::cout << "\nJumlah buku dikembalikan: ";
    std::cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        std::cout << "Masukkan ID buku ke-" << i + 1 << ": ";
        std::cin >> id;

        stack(id);
    }

    std::cout << std::endl;
    display_queue();
    std::cout << std::endl;
    display_stack();
    std::cout << std::endl;
    bst(root);
}