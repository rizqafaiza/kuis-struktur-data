#include<iostream>
#include<vector>
#include<string>

const int TABLE_SIZE = 20;

class HashTable{
    private:
    std::vector<std::pair<int, std::string>> table;
    std::vector<int> status;

    int hash1(int key){
        return key % TABLE_SIZE;
    }

    int hash2(int key){
        return 19-(key % 19);
    }

    public:
    HashTable(){
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(int key, std::string value){
        int index=hash1(key);
        int step = hash2(key);
        int initialIndex=index;

        int deleteIndex=-1;

        while(true){
            if(status[index]==1 && table[index].first==key){
                table[index].second = value;
                return;
            }

            if(status[index]==2 && deleteIndex==-1){
                deleteIndex=index;
            }

            if(status[index]==0){
                if(deleteIndex!=-1){
                    index=deleteIndex;
                }

                table[index]= make_pair(key, value);
                status[index] = 1;
                return;
            }

            index=(index + step)%TABLE_SIZE;

            if(index==initialIndex){
                break;
            }
        }      
        
        if (deleteIndex != -1) {
                table[deleteIndex] = make_pair(key, value);
                status[deleteIndex] = 1;
            } else {
                std::cout << "Tabel penuh" << std::endl;
            }
    }

    void search(int key){
        int index= hash1(key);
        int step=hash2(key);
        int initialIndex= index;

        while(status[index]!=0){
            if(status[index]==1 && table[index].first==key){
                std::cout << key << "\t" << table[index].second << std::endl;
                return;
            }

            index=(index + step) % TABLE_SIZE;

            if(index == initialIndex){
                break;
            }
        }

        std::cout << "data tidak ditemukan" << std::endl;
    }

    void remove(int key){
        int index= hash1(key);
        int step=hash2(key);
        int initialIndex= index;

        while(status[index]!=0){
            if(status[index]==1 && table[index].first==key){
                status[index]=2;
                std::cout << "data berhasil dihapus" <<std::endl;
                return;
            }

            index=(index+step) % TABLE_SIZE;

            if(index == initialIndex){
                break;
            }
        }

        std::cout << "data tidak ditemukan" << std::endl;
    }

    void display(){
        for (int i=0; i<TABLE_SIZE; i++){
            std::cout << i << ": ";

            if(status[i]==1){
                std::cout << table[i].first << "\t" << table[i].second << std::endl;
            } else if(status[i]==2){
                std::cout << "deleted" << std::endl;
            } else {
                std::cout << "empty" << std::endl;
            }
            std::cout<<std::endl;
        }
    }
};

int main(){
    HashTable ht;
    bool pilih;
    int nim, i = 0;
    std::string nama;

    while(!pilih && i<TABLE_SIZE){
        i++;
        std::cout << "Masukkan nim: "; std::cin >> nim;
        std::cout << "Masukkan nama: "; std::cin >> nama;
        
        ht.insert(nim, nama);

        std::cout << "berhenti isi? (y=1/n=0): ";
        std::cin >> pilih;
    }

    std::cout << "Masukkan nim yang ingin dicari "; std::cin >> nim;
    ht.search(nim);

    std::cout << "Masukkan nim yang ingin dihapus "; std::cin >> nim;
    ht.remove(nim);

    ht.display();
}