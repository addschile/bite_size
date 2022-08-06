template<typename Derived>
struct Base {};

struct MyDerived : Base<MyDerived> {};

int main() {
    auto x = MyDerived();
}
