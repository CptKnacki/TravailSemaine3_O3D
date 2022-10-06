 #include <iostream>

template<typename T>
class Liste
{
    private:
        int count = 0;
        T* tab = nullptr;
    public:

        // Constructor of Liste //
        Liste(int _count)
        {
            tab = new T[_count];
            count = _count;
        }
        Liste(T _item, int _count)
        {
            count = _count;
            tab = new T[_count];
            for (int i = 0; i < _count; i++)
            {
                tab[i] = _item;
            }
        }
        Liste(std::initializer_list<T> _tab)
        {
            tab = new T[_tab.size()];
            count = _tab.size();
            int index = 0;
            for (T _item : _tab)
            {
                tab[index++] = _item;
            }
        }

        // Get Method //
        T GetAt(int _index)
        {
            return tab[_index];

        }
        T GetLast()
        {
            return tab[count-1];
        }
        T GetFirst()
        {
            return tab[0];
        }

        // Method used to resize the array //
        void Resize(int _count)
        {
            T* _tempTab = tab;
      
            tab = new T[_count];
            for (int i = 0; i < count; i++)
            {
                tab[i] = _tempTab[i];
            }
            count = _count;
        }

        // Method used to display the data in the array //
        void Display()
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << tab[i] << " ";
            }

        }

        // Operator Method //
        T& operator[](int _index)
        {
            return tab[_index];
        }
};

int main()
{
    Liste<int> list1(4, 5);
    list1.Display();

    std::cout << std::endl << list1.GetAt(2) << std::endl;
    list1[2] = 100;
    std::cout << list1.GetAt(2) << std::endl;

    Liste<float> list2 = { 0.56f, 8.89f, 12.01f, 5.32f};
    list2.Display();

    std::cout << std::endl << list2.GetLast() << std::endl;
    std::cout << list2.GetFirst() << std::endl;
}