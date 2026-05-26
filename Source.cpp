#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> mergeTrashh(vector<vector<int>> trashh) {
    vector<int> mergedMassive;
    int n = trashh.size();
    for (int i = 0; i < n; i++) {
        mergedMassive.insert(mergedMassive.end(), trashh[i].begin(), trashh[i].end());
    }
    return mergedMassive;
}

void sortByBits(vector<int>& massive, int bit) {
    vector<vector<int>> trashh(10);
    int n = massive.size();
    for (int i = 0; i < n; i++) {
        int index_trashh = (massive[i] / bit) % 10;
        trashh[index_trashh].push_back(massive[i]);
    }
    massive = mergeTrashh(trashh);
}

void radixSort(vector<int>& massive) {
    if (massive.empty()) return;
    int max_number = *std::max_element(massive.begin(), massive.end());
    int bit = 1;
    while (max_number / bit > 0) {
        sortByBits(massive, bit);
        bit = bit * 10;
    }
}

void insertionSort(vector<int>& mas) {
    int n = mas.size();
    for (int i = 1; i < n; i++) {
        int current = mas[i];
        int j = i - 1;
        while (j >= 0 && mas[j] > current) {
            mas[j + 1] = mas[j];
            j = j - 1;
        }
        mas[j + 1] = current;
    }
}

int partition(vector<int>& mass, int low, int high) {
    int pivot = mass[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (mass[j] < pivot) {
            i++;
            swap(mass[i], mass[j]);
        }
    }
    swap(mass[i + 1], mass[high]);
    return (i + 1);
}

void quickSort(vector<int>& mass, int low, int high) {
    if (low < high) {
        int pi = partition(mass, low, high);
        quickSort(mass, low, pi - 1);
        quickSort(mass, pi + 1, high);
    }
} // Ñêîáêà, êîòîðàÿ ïîòåðÿëàñü

// Âñïîìîãàòåëüíàÿ ôóíêöèÿ äëÿ âûâîäà ÷èñåë íà ýêðàí
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// --- ÔÓÍÊÖÈß MAIN ---

int main() {
    // Íåîòñîðòèðîâàííûé ìàññèâ äëÿ òåñòà
    vector<int> original = { 42, 7, 105, 1, 88, 12, 0, 55 };

    cout << "Èñõîäíûé ìàññèâ:       ";
    printVector(original);
    cout << "---------------------------------------" << endl;

    // Ïðîâåðÿåì Ïîðàçðÿäíóþ ñîðòèðîâêó
    vector<int> a1 = original;
    radixSort(a1);
    cout << "Ïîðàçðÿäíàÿ ñîðòèðîâêà: ";
    printVector(a1);

    // Ïðîâåðÿåì ñîðòèðîâêó Âñòàâêàìè
    vector<int> a2 = original;
    insertionSort(a2);
    cout << "Ñîðòèðîâêà âñòàâêàìè:   ";
    printVector(a2);

    // Ïðîâåðÿåì Áûñòðóþ ñîðòèðîâêó
    vector<int> a3 = original;
    if (!a3.empty()) {
        quickSort(a3, 0, a3.size() - 1);
    }
    cout << "Áûñòðàÿ ñîðòèðîâêà:     ";
    printVector(a3);

    cout << "---------------------------------------" << endl;
    return 0;
}
