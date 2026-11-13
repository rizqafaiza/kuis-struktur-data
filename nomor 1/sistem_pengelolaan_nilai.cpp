#include<iostream>

struct Node{
    int data;
    Node* next;
    
    Node(int isi){
        data=isi;
        next=nullptr;
    }
};

Node* head;
Node* tail;
Node* current = head;

void isi_data_mahasiswa(int data){
    if(head==nullptr){
        Node* baru= new Node(data);
        head=baru;
        tail=baru;
    }  else {
        Node* baru= new Node(data);
        tail->next = baru;
        tail = baru;
    }
}

int* insertion_Sort(int data[], int n){
    int* hasil = new int[n];

    for(int i= 0;i<n;i++ ){
        hasil[i] = data[i];
    }

    for(int i=1; i<n; i++){
        int key = hasil[i];
        int j= i-1;

        while (j >= 0 && hasil[j] > key){
            hasil [j+1] = hasil[j];
            j--;
        }

        hasil[j+1] = key;
    }

    return hasil;
}

void tampilkan_insertion(int data[], int n){
    for (int i=0; i<n; i++){
        std::cout << data[i] <<" "<< std::endl;
    }
}

int linearSearch (int target){
    current=head;
    while(current!=nullptr){
        if(current->data == target){
            std::cout << "data ditemukan\n";

            return 0;
        }

        current=current->next;
    }

    std::cout << "nim tidak ditemukan\n";
    return -1;
}

int binarySearch(int data[], int n, int target) {
    data=insertion_Sort(data,n);
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            std::cout << "data ditemukan\n";
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << "data tidak ditemukan\n";
    return -1;
}

int main(){
    int jumlah, nim, angka;

    std::cout << "Masukkan Jumlah Mahasiswa: ";
    std::cin >> jumlah;

    int* nilai = new int[jumlah];

    std::cout<< "Masukkan NIM: "<< std::endl;
    for(int i=0; i<jumlah; i++){
        std::cout << "Mahasiswa ke-"<< i+1 <<": ";
        std::cin >>nim;

        isi_data_mahasiswa(nim);
        std::cout<< std::endl;
    }
    

    std::cout << "Masukkan nilai: "<< std::endl;
    for(int i=0; i<jumlah; i++){
        std::cout<<"Mahasiswa ke "<<i<<": ";
        std::cin >> nilai[i];
        std::cout<<std::endl;
    }

    std::cout << "\tDaftar NIM: \n";
    current=head;
    while(current!=nullptr){
        std::cout << current->data << " ";
        current=current->next;
    }
    std::cout<<"\n";

    std::cout << "\tHasil Sorting\n";
    tampilkan_insertion(insertion_Sort(nilai,jumlah),jumlah);

    std::cout << "\tCari NIM:\n";
    std::cin >> nim;
    linearSearch(nim);

    std::cout<< "\tCari nilai:\n";
    std::cin>>angka;
    binarySearch(nilai,jumlah,angka);
}