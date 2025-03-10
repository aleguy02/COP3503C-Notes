class MyClass {
    public:
    int value;
    void setValue(int newValue) const {
        value = newValue;
    }
};

void Foo(const MyClass& obj) {
    obj.value = 20;
    obj.setValue(5000);
}