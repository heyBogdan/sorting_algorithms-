#include <iostream>

using namespace std;

//Сортировка выбором
void selection_sort(int *a, int n){
    for(int i = 0; i < n - 1 ; ++i){
        int min_index = i;
        for (int j = i + 1; j < n; ++j){
            if (a[j] < a[min_index]) min_index = j;
        }
        swap(a[i], a[min_index]);
    }
}

//Сортировка вставками
void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; ++i){
        int tmp = a[i];
        int j;
        for (j = i; j>0 && tmp < a[j-1]; --j){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

//Быстрая сортировка
void quick_sort(int *a, int n){
    int i = 0;
    int j = n - 1;
    bool side = 0;
    while(i != j){
        if (a[i] > a[j]){
            swap(a[i], a[j]);
            side = !side;
        }
        if(side){
            i++;
        }
        else{
            j--;
        }
    }
    if (i > 1) quick_sort(a, i);
    if (i+1 < n) quick_sort(a+(i+1), n - (i + 1));
}


void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void create_arr(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << "Insert " << i << " element" << endl;
        cin >> a[i];
    }
}

void print_arr(int *a, int n){
    cout << "Array a" << endl;
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}

int main()
{
    int n;
    cout << "Insert array size" << endl;
    cin >> n;
    int a[n];

    create_arr(a, n);

    // Место для вставки функции сортировки

    print_arr(a,n);

    return 0;
}
