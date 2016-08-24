/*
 * Specifications design pattern
 * -----------------------------
 *
 * - Demonstrates the Open Closed Principle
 * - Frequently used in Domain driven design
 * - Frequently used while accessing data with certain criteria
 *
 * In this example, we have a vector of products with various attributes
 * and we want to filter it out based on combinations of criteria.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Color {Red, Green, Yellow, Blue};
enum Size {Small, Medium, Large};

class Product
{
    private:
        string _name;
        Color _color;
        Size _size;
    public:
        Product(const string& name, Color color, Size size)
            : _name(name), _color(color), _size(size) 
        {}

        const string& getName() const {
            return _name;
        }

        Color getColor() const {
            return _color;
        }

        Size getSize() const {
            return _size;
        }
};

template <typename T>
class ISpecification
{
    public:
        virtual bool is_satisfied(const T& item) = 0;
};

template <typename T>
class IFilter
{
    public:
        virtual vector<T> filter(vector<T> items, ISpecification<T>& spec) = 0;
};

class Filter: public IFilter<Product>
{
    typedef vector<Product> Items;
    public:
        virtual Items filter(Items items, ISpecification<Product>& spec) {
            Items result;
            for(auto i: items) {
                if(spec.is_satisfied(i))
                        result.push_back(i);
            }
            return result;
        }
};

class ColorSpec: public ISpecification<Product>
{
    Color _color;
    public:
        ColorSpec(Color color): _color(color) {}

        virtual bool is_satisfied(const Product& p) {
           if(_color == p.getColor())
               return true;

           return false;
        }
};

int main()
{
    Product apple("Apple", Red, Large);
    Product banana("Banana", Yellow, Medium);
    Product cherry("Cherry", Red, Large);

    vector<Product> fruits {apple, banana, cherry};

    ColorSpec c(Red);
    Filter f;
    vector<Product> red = f.filter(fruits, c);
    for(auto i: red)
        cout << i.getName() << endl;
   
}
