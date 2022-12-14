#include <iostream>
#include <stdexcept>
 
class VectorOfLong {
 public:
  VectorOfLong() : size(1), data(new long int[size]()) {}
  VectorOfLong(size_t size) : size(size), data(new long int[size]) {
    for (size_t i = 0; i < size; ++i) {
      data[i] = i;
    }
  }
  VectorOfLong(int size, long int initializer) : size(size),
    data(new long int[size]) {
    setAllTo(initializer);
  }
  VectorOfLong(const VectorOfLong &other) {
    copyFrom(other);
  }
  VectorOfLong &operator=(const VectorOfLong &other) {
    return copyFrom(other);
  }
  virtual ~VectorOfLong() {
    delete [] data;
  }
  long int &get(size_t position) {
    if (position >= size) {
      throw std::out_of_range("index went out of range");
    }
    return data[position];
  }
  const long int &get(size_t position) const {
    if (position >= size) {
      throw std::out_of_range("index went out of range");
    }
    return data[position];
  }
  void set(size_t position) {
    if (position >= size) {
      throw std::out_of_range("index went out of range");
    }
    data[position] = 0;
  }
  void set(size_t position, long int value) {
    if (position >= size) {
      throw std::out_of_range("index went out of range");
    }
    data[position] = value;
  }
  size_t getSize() const { return size; }
  void setAllTo(long int value) {
    for (size_t i = 0; i < size; ++i) {
      data[i] = value;
    }
  }
  VectorOfLong &copyFrom(const VectorOfLong &other) {
    if (this != &other) {
      size = other.size;
      delete [] data;
      data = new long int[size];
      for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }
  static size_t getMaximumSize() { return static_cast<size_t>(-1); }
 private:
  size_t size;
  long int *data;
};
 
std::ostream &operator<<(std::ostream &stream, const VectorOfLong &v) {
  stream << "[";
  for (size_t i = 0; i < v.getSize(); ++i) {
    stream << v.get(i);
    if (i < v.getSize() - 1) stream << ", ";
  }
  return stream << "]";
}
 
int main(int argc, char *argv[]) {
  VectorOfLong v(10);
  v.set(9);
  v.set(3, 4);
  std::cout << v << std::endl;
  return 0;
}