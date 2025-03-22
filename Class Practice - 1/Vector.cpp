#include <iostream>
using namespace std;
class Vector
{
private:
    int n;
    double *elements;

public:
    Vector(int n, double arr[])
    {
        elements = new double[n];
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            elements[i] = arr[i];
        }
    }

    ~Vector()
    {
        delete (elements);
    }

    void add(Vector &v)
    {
        for (int i = 0; i < n; i++)
        {
            elements[i] += v.elements[i];
        }
    }

    void add(double value)
    {
        for (int i = 0; i < n; i++)
        {
            elements[i] += value;
        }
    }

    void subtract(Vector &v)
    {
        for (int i = 0; i < n; i++)
        {
            elements[i] -= v.elements[i];
        }
    }

    void subtract(double value)
    {
        for (int i = 0; i < n; i++)
        {
            elements[i] -= value;
        }
    }

    double product(Vector &v)
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += elements[i] * v.elements[i];
        }
        return sum;
    }

    void product(double value)
    {
        for (int i = 0; i < n; i++)
        {
            elements[i] *= value;
        }
    }

    void set_value(int index, double value)
    {
        elements[index] = value;
    }

    double get_value(int index)
    {
        return elements[index];
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    double arr1[] = {1.2, 2.3, 3.4, 4.5};
    Vector v1(4, arr1); // 4-dimensional vector initialized with arr1
    cout << "Vector v1: ";
    v1.display(); // Output: [1.2, 2.3, 3.4, 4.5]
    double arr2[] = {5.0, 6.0, 7.0, 8.0};
    Vector v2(4, arr2); // Another 4-dimensional vector initialized with arr2
    cout << "Vector v2: ";
    v2.display(); // Output: [5.0, 6.0, 7.0, 8.0]
    v1.add(v2);
    cout << "After adding v2 to v1: ";
    v1.display(); // Output: [6.2, 8.3, 10.4, 12.5]
    v1.add(2.0);
    cout << "After adding scalar 2.0 to v1: ";
    v1.display(); // Output: [8.2, 10.3, 12.4, 14.5]
    v1.subtract(v2);
    cout << "After subtracting v2 from v1: ";
    v1.display(); // Output: [3.2, 4.3, 5.4, 6.5]
    v1.subtract(1.5);
    cout << "After subtracting scalar 1.5 from v1: ";
    v1.display(); // Output: [1.7, 2.8, 3.9, 5.0]
    double dotProduct = v1.product(v2);
    cout << "Dot product of v1 and v2: " << dotProduct << endl; // Output: 92.6
    v1.product(3.0);
    cout << "After multiplying v1 with scalar 3.0: ";
    v1.display(); // Output: [5.1, 8.4, 11.7, 15.0]
    return 0;
}