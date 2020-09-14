typedef int ElementType;

struct List {
  int len;
  ElementType *data;

 public:
  List(ElementType *data, int len) : data(data), len(len) {}
};