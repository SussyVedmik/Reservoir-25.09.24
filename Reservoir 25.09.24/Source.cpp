#include "Reservoir.h"
#include <string.h>
#include <iostream>
using namespace std;

class ReservoirManager {
private:
    Reservoir* reservoirs; 
    size_t size;           
    size_t capacity;       

    void resize() {
        capacity *= 2;
        Reservoir* newReservoirs = new Reservoir[capacity];
        for (size_t i = 0; i < size; ++i) {
            newReservoirs[i] = reservoirs[i];
        }
        delete[] reservoirs;
        reservoirs = newReservoirs;
    }

public:

    ReservoirManager() : size(0), capacity(4) {
        reservoirs = new Reservoir[capacity];
    }

    ~ReservoirManager() {
        delete[] reservoirs;
    }

    void addReservoir(const Reservoir& reservoir) {
        if (size == capacity) {
            resize();
        }
        reservoirs[size++] = reservoir;
    }

    void removeReservoir(size_t index) {
        setlocale(LC_ALL, "Russian");
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                reservoirs[i] = reservoirs[i + 1];
            }
            --size;
        }
    }

    void showAllReservoirs() const {
        setlocale(LC_ALL, "Russian");
        if (size == 0) {
            cout << "��� �������� ��� �����������.\n";
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                cout << "������ #" << (i + 1) << ":\n";
                reservoirs[i].Display();
                cout << "--------------------\n";
            }
        }
    }

    const Reservoir& getReservoir(size_t index) const {
        setlocale(LC_ALL, "Russian");
        if (index < size) {
            return reservoirs[index];
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    ReservoirManager manager;

    Reservoir reservoir1("����", "����", 100, 200, 30);
    Reservoir reservoir2("�����", "�����", 50, 80, 10);
    Reservoir reservoir3("����", "����", 70, 200, 70);
    Reservoir reservoir4("�����", "������������� �����", 100, 60, 10);

    manager.addReservoir(reservoir1);
    manager.addReservoir(reservoir2);
    manager.addReservoir(reservoir3);
    manager.addReservoir(reservoir4);

    manager.showAllReservoirs();

    if (reservoir1.TypeComparison(reservoir2)) {
        cout << "������� ������ ����.\n";
    }
    else {
        cout << "������� ������ �����.\n";
    }

    if (reservoir1.SameTypeAreaComparison(reservoir2)) {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }
    else {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }

    if (reservoir1.TypeComparison(reservoir3)) {
        cout << "������� ������ ����.\n";
    }
    else {
        cout << "������� ������ �����.\n";
    }

    if (reservoir1.SameTypeAreaComparison(reservoir3)) {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }
    else {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }

    if (reservoir2.TypeComparison(reservoir4)) {
        cout << "������� ������ ����.\n";
    }
    else {
        cout << "������� ������ �����.\n";
    }

    if (reservoir2.SameTypeAreaComparison(reservoir4)) {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }
    else {
        cout << "������ ������ ����� ������� ������� ������ �����������.\n";
    }

    return 0;
}