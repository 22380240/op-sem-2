#include <iostream>

using namespace std;

template <class T>
class TVector {
  protected: 
    T* pVector;
    int size;
    int startIndex;

  public:
    TVector(int s, int si) {
      size = s;
      startIndex = si;
      pVector = new T[size];
      for (int i = 0; i < size; i++) 
        pVector[i] = 0;
    }
    TVector(const TVector& v) {
      size = v.size;
      startIndex = v.startIndex;
      pVector = new T[size];
      for (int i = 0; i < size; i++)
        pVector[i] = v.pVector[i];
    }
    ~TVector() {
      delete[]pVector;
      pVector = nullptr;
    }
    T& operator[](int pos) {
      return pVector[pos - startIndex];
    }
    TVector<T> operator + (const TVector<T> & v) {
      TVector temp(size, startIndex);
      for (int i = 0; i <size; i++) 
        temp.pVector[i] = pVector[i] + v.pVector[i];

      return temp;
    }
    TVector<T> operator - (const TVector<T> & v) {
      TVector temp(size, startIndex);
      for (int i = 0; i <size; i++) 
        temp.pVector[i] = pVector[i] - v.pVector[i];

      return temp;
    }
      

    friend istream& operator>>(istream& in, TVector& v) {
      for (int i = 0; i < v.size; i++)
        in >> v.pVector[i];

      return in;
    }

    friend ostream& operator<<(ostream& out, const TVector& v) {
      for (int i = 0; i < v.size; i++)
        out << v.vector[i] << ' ';

      return out;
    }

    bool operator == (const TVector& v) {
      bool flag = 0;
      if ((size == v.size) & (startIndex == v.startIndex)) {
        int n = 0;

        for(int i = 0; i < size; i++) 
          if ((pVector[i] ==  v.pVector[i]))
            n++;

        if (n == size) 
          flag = 1;
        
      }

      return flag;
    }

    TVector<T> operator = (const TVector& v) {
      if (this != &v) {
        if (size != v.size) {
          delete pVector;
          pVector = new T[v.size];
        }
      }

      size = v.size;
      startIndex = v.startIndex;

      for (int i = 0; i < size; ++i) {
        pVector[i] = v.pVector[i];
      }
      
      return this;
    }
};

template<class T>
class Matrix: public TVector<TVector<T>> {
  public:
    Matrix(int s = 10);
    Matrix(const Matrix& mt);
    Matrix(const TVector<TVector<T>>& mt);

    Matrix<T> operator + (const Matrix<T> & mt) {
      return TVector<T>::operator+(mt);
    }
    Matrix<T> operator = (const Matrix<T> & mt) {
      if (this != &mt) {
        if (this->size != mt.size) {
          delete[] this-> pVector;
          this->pVector = new TVector<T>[mt.size];
        }
      }

      this->size = mt.size;
      this->startIndex = mt.startIndex;

      for (int i = 0; i < this->size; i++) {
        this->pVector[i] = mt.pVector[i];
      }

      return this;
    }
    Matrix<T> operator * (const Matrix<T> & v) {
      Matrix temp(this->getSize());
      int i, j, k;
      for (i = 0; i < temp.size; ++i) {
        for (k = i; k < j + 1; ++k) {
          temp[i][k] += this->pVector[i][k] * this->pVector[k][i];
        }

        return temp;
      }
    }
};
