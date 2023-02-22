#include <iostream>

int main()
{
    bool flag=false;
    int num;
    int buf;
    std::cin >> num;
    int* arr = new int[num+1];
    
    for (int i = 0; i < num; i++) {
        std::cin >> buf;
        arr[i] = buf;
    }
    arr[num] = -1;


    std::cout << "Source:" << std::endl;
    for (int i = 0; i <num;i++) {
        if (!flag) {
            flag = true;
            std::cout << '(';
        }
        else {
            std::cout << ' ';
        }
        std::cout << arr[i];
    }
    flag = false;
    std::cout << ")\nSelect Sort:\n";


    int* p,*min;
    
    for (int i = 0; i < num; i++) {
        p=arr+i;
        min = p;
        for (; *p!=-1; p++) {
            if (*p < *min) {
                min = p;
            }
        }
        buf = *(arr+i);
        arr[i] = *min;
        *min = buf;
        if(i!=num-1){
            for (int j = 0; j < num; j++) {
                if (!flag) {
                    flag = true;
                    std::cout << '(';
                }
                else {
                    std::cout << ' ';
                }
                std::cout << arr[j];
                if (j == i) {
                    std::cout << ")";
                }
            }        
            std::cout << std::endl;
            flag = false;
        }

    }

    for (int i = 0; i < num; i++) {
        if (!flag) {
            flag = true;
            std::cout << "Result:\n(";
        }
        else {
            std::cout << ',';
        }
        std::cout << arr[i];
    }
    std::cout << ')';
    flag = false;

    delete[] arr;
    return 0;
}
