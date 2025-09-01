#include <string>
#include <ostream>
#include <initializer_list>
#include <cassert>

namespace latc {

  template <typename TYPE, int DIMENSION>
  class Vector {
    public:
      // CONSTRUCTORS ***************************************************
      // Default Constructor
      Vector() : 
        _array()
      {

      }

      // Initializer List Constructor
      Vector(std::initializer_list<TYPE> array) : 
        _array()
      {
        auto iter = array.begin();
        for (int i = 0; i < DIMENSION; ++iter, ++i) {
          _array[i] = *iter;
        }
      }

      // Conversion Constructor
      Vector(const TYPE array[]) : 
        _array()
      {
        for (int i = 0; i < DIMENSION; ++i) {
          _array[i] = array[i];
        }
      }

      // Copy Constructor
      Vector(const Vector& rhs) : 
        _array()
      {
        for (int i = 0; i < DIMENSION; ++i) {
          _array[i] = rhs._array[i];
        }
      }
      
      // Destructor ******************************************************
      virtual ~Vector() {
        for (int i = 0; i < DIMENSION; ++i) {
          _array[i] = 0;
        }
      }

      // Assignment ******************************************************
      Vector& operator=(const Vector& rhs) {
        if (&rhs == this) return *this;
        for (int i = 0; i < DIMENSION; ++i) {
          _array[i] = rhs._array[i];
        }
        return *this;
      }

      // Accessors and Mutators ******************************************
      void set(unsigned int i, const TYPE& val) {
        assert(i < DIMENSION);
        _array[i] = val;
      }

      const TYPE& get(unsigned int i) const {
        assert(i < DIMENSION);
        return _array[i];
      }

      TYPE& operator[](unsigned int i) {
        assert(i < DIMENSION);
        return _array[i];
      }

      // SERIALIZATION ***************************************************
      std::string to_string() const {
        std::string to_return = "[ ";
        for (TYPE elem: _array) {
          to_return += std::to_string(elem) + ", ";
        }
        to_return.pop_back();
        to_return.pop_back();
        to_return += " ]";
        return to_return;
      }

      // ostream operator
      template <typename T, int D>
      friend std::ostream& operator<<(std::ostream& os, const Vector<T,D>& vec);

    private:

      TYPE _array[DIMENSION];
  }; // End class Vector<TYPE, DIMENSION>;

  template <typename TYPE, int DIMENSION>
  std::ostream& operator<<(std::ostream& os, const Vector<TYPE, DIMENSION>& vec) {
    os << "[ ";
    for (TYPE elem: vec._array) {
      os << elem << ", ";
    }
    os << "\b\b ]";
    return os;
  }
  

} // end namespace latc;


