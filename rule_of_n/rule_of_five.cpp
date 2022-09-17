#include <iostream>
#include <utility>

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
            std::cout << "sized constructor\n";
            allocate();
        }

        /* non default constructor needs managing of heap allocated data */
        Matrix(const size_t nrows, const size_t ncols, Numeric value) : row_dim{nrows}, col_dim{ncols}
        {
            std::cout << "sized init value constructor\n";
            allocate();
            for (size_t i=0; i<(row_dim*col_dim); i++){
                m_data[i] = value;
            }
        }

        /* copy constructor */
        Matrix(const Matrix& other) : Matrix(other.rows(), other.cols())
        {
            std::cout << "copy constructor\n";
            std::copy(other.data(), other.data() + other.size(), m_data);
        }

        /* move constructor */
        Matrix(Matrix&& other) : row_dim{other.rows()}, col_dim{other.cols()}
        {
            std::cout << "move constructor\n";
            m_data = std::exchange(other.data(), nullptr);
        }

        /* non default destrcutor needs managing of heap allocated data */
        ~Matrix(){
            std::cout << "dealloc\n";
            deallocate();
        }

        /* copy assignment */
        Matrix& operator=(const Matrix& other)
        {
            std::cout << "copy assignment\n";
            if (this == &other){
                return *this;
            }
            if (m_data)
                this->deallocate();
            set_rows(other.rows());
            set_cols(other.cols());
            this->allocate();
            std::copy(other.data(), other.data() + other.size(), m_data);
            return *this;
        }

        /* move assignment */
        Matrix& operator=(Matrix&& other)
        {
            std::cout << "move assignment\n";
            if (this == &other){
                return *this;
            }
            set_rows(other.rows());
            set_cols(other.cols());
            m_data = std::exchange(other.data(), nullptr);
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
        Numeric*& data() {return m_data;}
        Numeric* data() const {return m_data;}
        void nullify() {m_data = nullptr; return;}

        void zero()
        {
            if (!m_data) {
                allocate();
            }
            for (size_t i=0; i<(row_dim*col_dim); i++){
                m_data[i] = static_cast<Numeric>(0);
            }
        }

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

template<typename Numeric>
Matrix<Numeric> zeros(const size_t row_dim, const size_t col_dim)
{
    auto out_mat = Matrix<Numeric>(row_dim, col_dim);
    out_mat.zero();
    return std::move(out_mat);
}

template<typename Numeric>
Matrix<Numeric> ones(const size_t row_dim, const size_t col_dim)
{
    Matrix<Numeric> out_mat{row_dim, col_dim};
    out_mat.ones();
    return std::move(out_mat);
}

int main() {

    std::cout << "move constructed via helper function mat\n";
    auto mat = ones<double>(3, 3);
    std::cout << "mat\n";
    mat.print();

    std::cout << "\nvalue initialized new mat\n";
    auto new_mat = Matrix<double>{3, 3, 14};
    std::cout << "new_mat\n";
    new_mat.print();


    std::cout << "\nmove assigned mat -> new_mat\n";
    new_mat = std::move(mat);
    std::cout << "new_mat\n";
    new_mat.print();
    std::cout << "mat\n";
    mat.print();

    std::cout << "\ncopy assigned new_mat -> mat\n";
    mat = new_mat;
    std::cout << "new_mat\n";
    new_mat.print();
    std::cout << "mat\n";
    mat.print();

}
