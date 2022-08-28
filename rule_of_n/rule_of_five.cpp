#include <iostream>

template<typename Numeric>
class Matrix {
    private:
        size_t row_dim, col_dim;
        Numeric* m_data = nullptr;
    public:
        Matrix(){};

        /* non default constructor needs managing of heap allocated data */
        Matrix(const size_t nrows, const size_t ncols) : row_dim{nrows}, col_dim{ncols}
        {
            allocate();
        }

        /* copy constructor */
        Matrix(const Matrix& other) : Matrix(other.rows(), other.cols())
        {
            std::copy(other.data(), other.data() + other.size(), m_data);
        }

        /* non default destrcutor needs managing of heap allocated data */
        ~Matrix(){
            deallocate();
        }

        Matrix& operator=(const Matrix& other)
        {
            if (this == &other){
                return *this;
            }
            this->deallocate();
            this->set_rows(other.rows());
            this->set_cols(other.cols());
            this->allocate();
            std::copy(other.data(), other.data() + other.size(), m_data);
            return *this;
        }

        void allocate(){
            if (!m_data)
                m_data = new Numeric[row_dim*col_dim];
                return;
            this->deallocate();
            this->allocate();
        }

        void deallocate(){
            if (!m_data)
                return;
            delete [] m_data;
        }

        void set_rows(const size_t nrows){row_dim = nrows;}
        void set_cols(const size_t ncols){col_dim = ncols;}
        size_t rows() const {return row_dim;}
        size_t cols() const {return col_dim;}
        size_t size() const {return row_dim*col_dim;}
        const Numeric* data() const {return m_data;}

        void ones()
        {
            if (!m_data) {
                allocate();
            }
            for (size_t i=0; i<(row_dim*col_dim); i++){
                m_data[i] = static_cast<Numeric>(1);
            }
        }

        void print()
        {
            if (!m_data) {
                return;
            }
            for (size_t i=0; i<row_dim; i++){
                size_t bind = i*col_dim;
                for (size_t j=0; j<col_dim; j++){
                    std::cout << m_data[bind + j] << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main() {

    std::cout << "og mat\n";
    auto mat = Matrix<double>(3,3);
    mat.ones();
    mat.print();

    std::cout << "new mat\n";
    auto new_mat = Matrix<double>(mat);
    new_mat.print();

    std::cout << "new new mat\n";
    Matrix<double> new_new_mat;
    new_new_mat.print();
    new_new_mat = mat;
    new_new_mat.print();
}
